#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
**	Dynamic string functions
*/

struct s_string		*stringInit(void) {
	struct s_string	*s;

	s = malloc(sizeof(struct s_string));
	s->capacity = 100;
	s->content = malloc(sizeof(char) * s->capacity);
	s->length = 0;
	return (s);
}

int					stringAppend(struct s_string *s, char *add) {
	int		len;
	int		capacity;

	len = strlen(add);
	capacity = s->capacity;
	while (capacity < len + s->length + 1)
		capacity *= 2;
	if (capacity > s->capacity) {
		s->capacity = capacity;
		s->content = realloc(s->content, s->capacity);
		if (!s->content)
			return (0);
		bzero(s->content + s->length, s->capacity - s->length);
	}
	strcpy(s->content + s->length, add);
	s->length += len;
	return (1);
}

/*
**	Utils
*/

unsigned	ft_count_words(char const *s, char c)
{
	unsigned	i;
	unsigned	found_word;

	i = 0;
	while (*s)
	{
		found_word = 0;
		while (*s && *s == c)
			s++;
		s--;
		while (*++s && *s != c)
			found_word = 1;
		i += found_word;
	}
	return (i);
}

char		**getWordsArray(char *header) {
	int		i;
	int		words;
	char	**res;
	char	*word;

	words = ft_count_words(header, ',');
	res = malloc(sizeof(char *) * (words + 1));
	word = strtok(header, ",");
	i = 0;
	while (word) {
		res[i++] = strdup(word);
		word = strtok(NULL, ",");
	}
	res[i] = NULL;
	return (res);
}

/*
**	Mandatory function
*/

char 		*decompress(char *cBook) {
	int			i, j;
	char		*tmp;
	char		**dict;
	char		*header;
	struct s_string	*s;

	i = 1;
	while (cBook[i] != '>') i++;
	header = strndup(cBook + 1, i - 1);
	header[i - 1] = '\0';
	dict = getWordsArray(header);
	s = stringInit();
	while (cBook[++i]) {
		j = 0;
		while (cBook[i + j] != '@' && cBook[i + j]) j++;
		tmp = strndup(cBook + i, j + 1);
		tmp[j] = '\0';
		i += j + 1;
		stringAppend(s, tmp);
		free(tmp);
		if (cBook[i - 1] == '@')
			stringAppend(s, dict[(unsigned char)cBook[i] - 1]);
	}
	stringAppend(s, "\0");
	free(header);
	i = -1;
	while (dict[++i])
		free(dict[i]);
	free(dict);
	tmp = s->content;
	free(s);
	printf("%s", tmp);
	return (tmp);
 }
