#include "header.h"

/*
ft_sa_sb
ft_pa_pb
ft_ra_rb
ft_rra_rrb
ft_almostlast
ft_rrr
*/

void	ft_sa_sb(t_list **pile, char c)
{
	t_list	*chaine1;
	t_list	*chaine2;

	if (ft_lstsize(*pile) >= 2)
	{
		chaine1 = *pile;
		chaine2 = chaine1->next;
		chaine1->next = chaine2->next;
		chaine2->next = *pile;
		*pile = chaine2;
		printf("s%c\n", c);
	}
}

void	ft_pa_pb(t_list **pile1, t_list **pile2, char c)
{
	t_list	*chaine1;
	t_list	*chaine2;

	if (*pile1)
	{
		chaine1 = *pile1;
		chaine2 = *pile2;
		*pile2 = chaine1;
		*pile1 = chaine1->next;
		chaine1->next = chaine2;
	}
	printf("p%c\n", c);
}

void	ft_ra_rb(t_list **pile, char c)
{
	t_list	*chaine1;
	t_list	*chaine2;
	t_list	*derniere;

	if (ft_lstsize(*pile) >= 2)
	{
		chaine1 = *pile;
		derniere = ft_lstlast(*pile);
		derniere->next = chaine1;
		chaine2 = chaine1->next;
		chaine1->next = NULL;
		*pile = chaine2;
		printf("r%c\n", c);
	}
}

void	ft_rra_rrb(t_list **pile, char c)
{
	t_list	*chaine1;
	t_list	*av_dernier;
	t_list	*dernier;

	if (*pile)
	{
		if (ft_lstsize(*pile) >= 3)
		{
			dernier = ft_lstlast(*pile);
			chaine1 = *pile;
			av_dernier = ft_almostlast(*pile);
			av_dernier->next = NULL;
			dernier->next = chaine1;
			*pile = dernier;
			printf("rr%c\n", c);
		}
		else if (ft_lstsize(*pile) == 2)
			ft_sa_sb(pile, c);
	}
}

t_list	*ft_almostlast(t_list *lst)
{
	t_list	*actuel;
	t_list	*temp;
	t_list	*pretemp;

	actuel = lst;
	temp = NULL;
	if (!lst)
		return (NULL);
	while (actuel)
	{
		pretemp = temp;
		temp = actuel;
		actuel = actuel->next;
	}
	return (pretemp);
}

void ft_rrr(t_list **pile_a, t_list **pile_b)
{
	t_list	*chaine1;
	t_list	*av_dernier;
	t_list	*dernier;

	if (*pile_a && *pile_b)
	{
		dernier = ft_lstlast(*pile_a);
		chaine1 = *pile_a;
		av_dernier = ft_almostlast(*pile_a);
		av_dernier->next = NULL;
		dernier->next = chaine1;
		*pile_a = dernier;
		if (ft_lstsize(*pile_b) >= 3)
		{
			dernier = ft_lstlast(*pile_b);
			chaine1 = *pile_b;
			av_dernier = ft_almostlast(*pile_b);
			av_dernier->next = NULL;
			dernier->next = chaine1;
			*pile_b = dernier;
		}
		else if (ft_lstsize(*pile_b) == 2)
			ft_sa_sb(pile_b, 'b');
		printf("rrr\n");
	}
}