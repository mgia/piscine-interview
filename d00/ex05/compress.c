#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PRIME 33

size_t			hash(char *str)
{
	size_t	hash;
	unsigned char	*u_str;
	int		len;

	len = strlen(str);
	u_str = (unsigned char*)str;
	hash = 0;
	while (len--)
		hash = hash * PRIME + (*u_str++);
	return (hash);
}

size_t			rehash(size_t old, int len, unsigned char rm, unsigned char add)
{
	size_t	new;
	new = old - pow(PRIME, len - 1) * rm;
	new = new * PRIME + add;
	return (new);
}

int				howManyJesus(char *bible, char *jesus)
{
	int		bible_len = strlen(bible);
	int		jesus_len = strlen(jesus);
	int		bible_hash = hash(bible);
	int		jesus_hash = hash(jesus);
	int		count = 0;

	for (int i = 0; i < bible_len - jesus_len + 1; i++)
	{
		if (bible_hash == jesus_hash)
			count++;
		bible_hash = rehash(bible_hash, jesus_len, bible[i], bible[i + jesus_len]);
	}
	return (count);
}

int				count_new_memory(char *book, char **list, int len)
{
	int bytes = strlen(book);
	int word_count;

	for (int i = 0; i < len; i++)
	{
		word_count = howManyJesus(book, list[i]);
		bytes -= word_count * strlen(list[i]);
		bytes += word_count * 2;
	}
	return bytes;
}

struct s_dict	 *dictInit(int capacity)
{
	struct s_dict	*dict;

	if (!(dict = (struct s_dict *)malloc(sizeof(struct s_dict))))
		return (NULL);
	dict->items = (struct s_item**)calloc(capacity, sizeof(struct s_item*));
	if (!(dict->items))
		return (NULL);
	dict->capacity = capacity;
	return (dict);
}

int				dictInsert(struct s_dict *dict, char *key, int value)
{
	struct s_item	*tmp;
	size_t			i;

	i = hash(key) % dict->capacity;
	if (!dict->items[i])
	{
		if (!(dict->items[i] = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		tmp = dict->items[i];
	}
	else
	{
		tmp = dict->items[i];
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		tmp = tmp->next;
	}
	if (!(tmp->key = strdup(key)))
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	return (1);
}

int				dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*tmp;
	size_t			i;

	i = hash(key) % dict->capacity;
	tmp = dict->items[i];
	while (tmp)
	{
		if (!strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (-1);
}

char			**dictGetHeader(struct s_dict *dict, int *header_len, int *header_count)
{
	char			**list;
	struct s_item	*tmp;
	int				count = 0;
	int				len = 0;

	for (int i = 0; i < dict->capacity; i++)
	{
		tmp = dict->items[i];
		while (tmp)
		{
			count++;
			len += (strlen(tmp->key) + 1);
			tmp = tmp->next;
		}
	}
	list = (char**)malloc(sizeof(char*) * count);
	for (int i = 0; i < dict->capacity; i++)
	{
		tmp = dict->items[i];
		while (tmp)
		{
			list[tmp->value] = strdup(tmp->key);
			tmp = tmp->next;
		}
	}
	*header_len = len + 1;
	*header_count = count;
	return (list);
}

char			*headerString(char **list, int len, int count)
{
	char	*header;
	int		word_len;
	int		j;

	header = (char*)calloc(1, len + 1);
	header[0] = '<';
	j = 1;
	for (int i = 0; i < count; i++)
	{
		word_len = strlen(list[i]);
		strncpy(&header[j], list[i], word_len);
		j += word_len;
		header[j++] = ',';
		free(list[i]);
	}
	header[--j] = '>';
	return (header);
}

char			*compress(char *book, struct s_dict *dict)
{
	char	**list;
	char	*header, *new, *word;
	int		header_len, header_count;
	int		i, j, k;
	int		index;

	list = dictGetHeader(dict, &header_len, &header_count);
	header = headerString(list, header_len, header_count);
	new = (char*)calloc(1, strlen(book) + header_len + 1);
	strncpy(new, header, header_len);
	i = header_len;
	j = 3;
	while (book[j])
	{
		while (!isalnum(book[j]) && book[j])
			new[i++] = book[j++];
		k = j;
		while (isalnum(book[j]) && book[j])
			j++;
		if (k < j)
		{
			word = strndup(&book[k], j - k);
			if ((index = dictSearch(dict, word)) != -1)
			{
				new[i++] = '@';
				new[i++] = index + 1;
			}
			else
				while (k < j)
					new[i++] = book[k++];
			free(word);
		}
	}
	free(list);
	free(header);

	// Testing function
	// printf("original bytes: %lu\n", strlen(book));
	// printf("new bytes: %lu\n", strlen(new) - header_len);
	// printf("%s\n", new);
	return (new);
}
