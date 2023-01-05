#include "header.h"

int *verif(int ac, char **av)
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
				return (NULL);
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
	i = 0;
	j = 1;
	while(j++ < ac)
		printf("%d, ", nombres[i++]);
	if(!verif_2(nombres, ac))
		return (NULL);
	return (nombres);
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

int ft_ordre(int ac, int *nombres)
{
	int i;

	i = 0;
	while(i < (ac - 2))
	{
		if(nombres[i] > nombres[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int ft_push_swap(int ac, char **av)
{
	int *nombres;
	if (1 < ac)
	{
		nombres = verif(ac, av);
		if(!nombres)
		{
			printf("🙁 dsl ma belle 🙁\n");
			return (0);
		}
		if(!verif_2(nombres, ac))
		{
			printf("🙁 dsl ma belle 🙁\n");
			return (0);
		}
		if(!ft_ordre(ac, nombres))
		{
			printf("🙁 pas dans l'ordre ma jolie 🙁\n");
			return (0);
		}
	}
	printf("🧡 you go girl 🧡\n");
	return 1;
}

int main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}