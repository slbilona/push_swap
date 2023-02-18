#include "../header.h"
#include "header_bonus.h"

int	main(int ac, char **av)
{
	long int	*nombres;
	t_list		*pile_a;
	t_list		*premier_a;
	t_list		*premier_b;
	int			nb_de_nb;

	if (ac >= 2)
	{
		nb_de_nb = ft_nombre_de_nombres(av);
		nombres = ft_verif(nb_de_nb, av);
		if (!nombres)
			printf("Error\n");
		pile_a = ft_pile_a(nombres, nb_de_nb);
		premier_a = pile_a;
		premier_b = NULL;
		free(nombres);
		ft_principale_bn(&premier_a, &premier_b);
		ft_vide_liste(&premier_a);
		ft_vide_liste(&premier_b);
	}
}