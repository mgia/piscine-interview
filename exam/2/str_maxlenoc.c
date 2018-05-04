/*
STR_MAXLENOC
Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.
If there are no parameters, the program displays \n.
Examples:
$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	if (!str)
		return 0;
	int		i = -1;
	while (str[++i]);
	return (i);
}

int		ft_strnstr(char *str, char *sub, int len)
{
	int		i = 0, j;

	while (str[i])
	{
		j = 0;
		while (str[i + j] == sub[j] && j < len)
			j++;
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	char	*res = calloc(n + 1, sizeof(char));
	int		i = 0;
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

void	str_maxlenoc(int ac, char **av)
{
	char	*res = NULL, *tmp = NULL;
	int		i = 0, len = 1, found, j;

	while (av[0][i])
	{
		found = 1;
		j = -1;
		while (++j < ac && av[j])
			found = ft_strnstr(av[j], &av[0][i], len) ? found : 0;
		if (found)
		{
			tmp = ft_strndup(&av[0][i], len);
			if (ft_strlen(res) < ft_strlen(tmp))
			{
				free(res);
				res = tmp;
			}
			len++;
			if (!av[0][i + len - 1])
				break ;
		}
		else
			i++;
	}
	if (res)
	{
		write(1, res, ft_strlen(res));
		free(res);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		write(1, av[1], ft_strlen(av[1]));
	else if (ac > 2)
		str_maxlenoc(ac - 1, av + 1);
	write(1, "\n", 1);
	return 0;
}
