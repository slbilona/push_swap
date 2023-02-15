#include "header.h"
#include "header_bonus.h"

void afficher_pile(t_list **pile_a, t_list **pile_b)
{
	t_list *p_a;
	t_list *p_b;

	p_a = *pile_a;
	p_b = *pile_b;
	while(p_a || p_b)
	{
		if (p_a && p_b)
		{
			printf("%d   %d\n", p_a->nombre, p_b->nombre);
			p_a = p_a->next;
			p_b = p_b->next;
		}
		else if (p_a)
		{
			printf("%d\n", p_a->nombre);
			p_a = p_a->next;
		}
		else if (p_b)
		{
			printf("    %d\n", p_b->nombre);
			p_b = p_b->next;
		}
	}
	printf("-   -\na   b\n");
}

void ft_free_et_exit(char *str, t_list **pile_a, t_list **pile_b)
{
	printf("Error\n");
	free(str);
	ft_vide_liste(pile_a);
	ft_vide_liste(pile_b);
	exit(EXIT_FAILURE);
}

void ft_attribution(char *str, t_list **pile_a, t_list **pile_b)
{
	if (ft_memcmp(str, "ra\n", ft_strlen(str)) == 0)
		ft_ra_rb_bn(pile_a);
	else if (ft_memcmp(str, "sa\n", ft_strlen(str)) == 0)
		ft_sa_sb_bn(pile_a);
	else if (ft_memcmp(str, "pa\n", ft_strlen(str)) == 0)
		ft_pa_pb_bn(pile_a, pile_b);
	else if (ft_memcmp(str, "^D\n", ft_strlen(str)) == 0)
	{
		printf("jsp\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_free_et_exit(str, pile_a, pile_b);
}

void ft_principale_bn(t_list **pile_a, t_list **pile_b)
{
	char *str;

	str = get_next_line(0);
	ft_attribution(str, pile_a, pile_b);
	free(str);
	//ft_principale_bn(pile_a, pile_b);
}

int main(int ac, char **av)
{
	long int *nombres;
	t_list *pile_a;
	t_list *premier_a;
	t_list *premier_b;
	int nb_de_nb;

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
		afficher_pile(&premier_a, &premier_b);
		ft_principale_bn(&premier_a, &premier_b);
		afficher_pile(&premier_a, &premier_b);
		ft_vide_liste(&premier_a);
		ft_vide_liste(&premier_b);
		free(nombres);
	}
	
}

