#include "header.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#define PRIME 33

static size_t	hash(char *str, int len)
{
	size_t	hash;
	unsigned char	*u_str;

	u_str = (unsigned char*)str;
	hash = 0;
	while (len--)
		hash = hash * PRIME + (*u_str++);
	return (hash);
}


static size_t	rehash(size_t old, int len, unsigned char rm, unsigned char add)
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
	int		bible_hash = hash(bible, jesus_len);
	int		jesus_hash = hash(jesus, jesus_len);
	int		count = 0;

	for (int i = 0; i < bible_len - jesus_len + 1; i++)
	{
		if (bible_hash == jesus_hash)
			count++;
		bible_hash = rehash(bible_hash, jesus_len, bible[i], bible[i + jesus_len]);
	}
	return (count);
}
