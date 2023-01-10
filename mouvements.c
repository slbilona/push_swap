#include "header.h"

t_list *ft_sa_sb(t_list *pile)
{
    t_list *chaine1;
    t_list *chaine2;

    chaine1 = pile;
    chaine2 = chaine1->next;
    chaine1->next = chaine2->next;
    chaine2->next = pile;
    pile = chaine2;
    printf("sa\n");
    return (chaine2);
}