#include "header.h"

void insertionSort(struct s_player **players)
{
	struct s_player	*player;
	int	i, j;

	for (i = 1; players[i]; i++)
	{
		j = i;
		while (j > 0 && players[j]->score < players[j - 1]->score)
		{
			player = players[j];
			players[j] = players[j - 1];
			players[j - 1] = player;
			j--;
		}
	}
}
