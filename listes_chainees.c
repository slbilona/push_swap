#include "header.h"

t_list	*ft_pile_a(long int *nombres, int ac)
{
	t_list	*list;
	//t_list	*test;
	int		i;

	i = 0;
	list = ft_lstnew(nombres[i]);
	i++;
	while (i < (ac - 1))
	{
		ft_lstadd_front(&list, ft_lstnew(nombres[i]));
		i++;
	}
	// test = list;
	// while (test)
	// {
	// 	printf("%d, ", test->nombre);
	// 	test = test->next;
	// }
	free(nombres);
	//printf("NULL\n");
	return (list);
}

/*t_list	*ft_pile_b()
{
	t_list list;

	list = ft_lstnew(0);
	return (list);
}*/

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nombre = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*actuel;

	if (!*lst)
		*lst = new;
	else
	{
		actuel = *lst;
		*lst = new;
		new->next = actuel;
	}
}

int ft_lstsize(t_list *lst)
{
	t_list *actuel;
	int i;

	actuel = lst;
	i = 0;
	if(!actuel)
		return (1);
	while(actuel)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *actuel;
	t_list *temp;

	actuel = lst;
	if(!lst)
		return (NULL);
	while(actuel)
	{
		temp = actuel;
		actuel = actuel->next;
	}
	return (temp);
}