#include "libft.h"


void free_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
}

int main()
{
	char **split;

	split = ft_split("bonjour tout le monde", ' ');
	free_split(&split);
	return 0;
}
