#include "header.h"

t_list *ft_sa_sb(t_list *pile)
{
    t_list *chaine1;
    t_list *chaine2;
    
    if(ft_lstsize(pile) < 2)
        return (NULL);
    chaine1 = pile;
    chaine2 = chaine1->next;
    chaine1->next = chaine2->next;
    chaine2->next = pile;
    pile = chaine2;
    printf("sa\n");
    return (chaine2);
}

t_list  *ft_pa_pb(t_list *pile1, t_list *pile2)
{
    if(!pile1)
        return (NULL);
    ft_lstadd_front(&pile2, pile1);
}

t_list *ft_ra_rb(t_list *pile)
{
    t_list *chaine1;
    t_list *chaine2;
    t_list *derniere;

    chaine1 = pile;
    derniere = ft_lstlast(pile);
    derniere->next = chaine1;
    chaine2 = chaine1->next;
    chaine1->next = NULL;
    printf("ra\n");
    return (chaine2);
}

t_list *ft_rra_rrb(t_list *pile)
{
    t_list *chaine1;
    t_list *av_dernier;
    t_list *dernier;

    if(ft_lstsize(pile) < 3)
    {
        return (NULL);
    }
    dernier = ft_lstlast(pile);
    chaine1 = pile;
    av_dernier = ft_almostlast(pile);
    av_dernier->next = NULL;
    dernier->next = chaine1;
    printf("rra\n");
    return (dernier);
}

t_list *ft_almostlast(t_list *lst)
{
	t_list *actuel;
	t_list *temp;
    t_list *pretemp;

	actuel = lst;
    temp = NULL;
	if(!lst)
		return (NULL);
	while(actuel)
	{
        pretemp = temp;
		temp = actuel;
		actuel = actuel->next;
	}
	return (pretemp);
}