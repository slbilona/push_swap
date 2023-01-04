#include "header.h"

int verif(int ac, char **av)
{
	int *nombres;
	int i;
	int j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while(av[j][i])
			if(ft_isalpha(av[j][i++]))
				return (0);
		j++;
	}
	i = 0;
	j = 1;
	nombres = malloc(sizeof(int) * (ac - 1));
	if (nombres)
		while(j < ac)
		{
			nombres[i] = ft_atoi(av[j]);
			i++;
			j++;
		}
	/*i = 0;
	j = 1;
	while(j++ < ac)
		printf("%d, ", nombres[i++]);*/
	if(!verif_2(nombres, ac))
		return 0;
	free(nombres);
	return (1);
}

int verif_2(int *nombres, int ac)
{
	int j;
	int fac;

	j = 0;
	fac = ac - 2;
	while (j < (ac - 1))
	{
		while(fac > 0)
		{
			//printf("|nombres[j] %d|\n|nombres[i + j] %d|\n", nombres[j], nombres[(fac) + j]);
			if(nombres[j] == nombres[(fac) + j])
			{
				free(nombres);
				return (0);
			}
			fac--;
		}
		j++;
	}
	return 1;
}

void ft_push_swap(int ac, char **av)
{
	if (1 < ac)
	{
		if(verif(ac, av))
			printf("🧡 you go girl 🧡\n");
		else
			printf("🙁 dsl ma belle 🙁\n");
	}
}

int main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}