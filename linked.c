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

int	count_nodes(struct node *head)
{
	struct node *ptr;
	int	count;

	count = 0;
	ptr = NULL;
	ptr = malloc(sizeof(struct node));
	ptr = head;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

int	main()
{
	struct node *head = NULL;
	head = malloc(sizeof(struct node));
	head->data = 45;
	head->next = NULL;

	struct node *ptr = NULL;
	ptr = malloc(sizeof(struct node));
	ptr = head;

	ptr = add_to_end_of_node(ptr, 102);
	head = add_to_head(head, 0);
	head = add_to_head(head, 30);

	print_nodes(head);
}
