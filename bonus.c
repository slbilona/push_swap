#include "header.h"
#include "header_bonus.h"

int main(int ac, char **av)
{
	char *str;
	long int *nombres;
	t_list *pile_a;
	t_list *premier_a;
	t_list *premier_b;

	if (ac >= 2)
	{
		nombres = ft_verif(ac, av);
		
		if (nombres)
		{
			pile_a = ft_pile_a(nombres, ac);
			premier_a = pile_a;
			premier_b = NULL;
			str = get_next_line(0);
		}
		else
		{
			printf("Error");
			free(nombres);
		}
	}
	printf("\n");
}
/*
void ft_attribution(char *str)
{
	if(ft_memcmp(str, 'ra', ft_strlen(str)))
		ft_ra_rb()
}*/