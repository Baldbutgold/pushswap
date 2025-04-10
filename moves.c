#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->n;
	}
	return (count);
}

/*int	main()*/
/*	struct node *head = NULL;*/
/*	head = malloc(sizeof(struct node));*/
/*	head->data = 0;*/
/*	head->next = NULL;*/
/*	struct node *ptr = NULL;*/
/*	ptr = malloc(sizeof(struct node));*/
/*	ptr = head;*/
/*	ptr = add_to_end_of_node(ptr, 10);*/
/*	ptr = add_to_end_of_node(ptr, 20);*/
/*	add_to_node(head, 30);*/
/*	add_to_point_of_node(head, 5, 40);*/
/*	add_to_point_of_node(head, 6, 50);*/
/*	delete_last_node(head);*/
/*	print_nodes(head);*/
/*}*/