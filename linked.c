#include <stdio.h>
#include <stdlib.h>

struct node
{
	int	data;
	struct node *next;
};

void	add_to_node(struct node *head, int data)
{
	struct node *temp;

	temp = NULL;
	temp = malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;

	while (head->next)
		head = head->next;
	head->next = temp;
}

void	add_to_point_of_node(struct node *head, int pos, int data)
{
	struct node *ptr2;

	ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->next = NULL;

	pos--;
	while (pos != 1)
	{
		head = head->next;
		pos--;
	}
	if (head->next != NULL)
		ptr2->next = head->next;
	head->next = ptr2;
}

struct node *delete_head_node(struct node *head)
{
	if (head == NULL)
		printf("already empty\n");
	else
	{
		struct node *temp;
		temp = head;
		head = head->next;
		free(temp);
	}
	return (head);
}

void	delete_last_node(struct node *head)
{
	if (head == NULL)
		return ;
	else if (head->next == NULL)
	{
	free(head);
	head = NULL;
}
	else
{
		while (head->next->next)
			head = head->next;
		free(head->next->next);
		head->next = NULL;
	}
}

struct node *add_to_end_of_node(struct node *ptr, int data)
{
	struct node *temp;

	temp = NULL;
	temp = malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;
	ptr->next = temp;
	return (temp);
}

struct node *add_to_head(struct node *old_head, int data)
{
	struct node *new_head;

	new_head = NULL;
	new_head = malloc(sizeof(struct node));

	new_head->data = data;
	new_head->next = old_head;
	return (new_head);
}

void	print_nodes(struct node *head)
{
	struct node *ptr;
	int	count;

	ptr = NULL;
	ptr = malloc(sizeof(struct node));
	ptr = head;
	while (ptr)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

