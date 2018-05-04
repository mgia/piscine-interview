/*
COUNT_APLHA
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------
Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.
The format is in the examples.
If the number of arguments is not 1, display only a newline.
Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$
*/

#include <stdio.h>
#define SMALL(x) (x >= 'a' && x <= 'z')
#define BIG(x) (x >= 'A' && x <= 'Z')

void ft_count(char *str)
{
	int tab[26] = {0};
	int i = -1;
	while (str[++i])
	{
		if (BIG(str[i]))
			str[i] = str[i] - 'A' + 'a';
		if (SMALL(str[i]))
			tab[str[i] - 'a']++;
	}
	i = -1;
	int first = 1;
	while (str[++i])
	{
		if (tab[str[i] - 'a'] > 0)
		{
			if (first)
			{
				first = 0;
				printf("%d%c", tab[str[i] - 'a'], str[i]);
			}
			else
				printf(" %d%c", tab[str[i] - 'a'], str[i]);
			tab[str[i] - 'a'] = 0;
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_count(av[1]);
	printf("\n");	
	return 0;
}
