#include "binary_trees.h"

/**
 * push - pushs a node in the front of a queue
 * @head: pointer to head of the queue
 * @tail: pointer to tail of the queue
 * @node: pointer to binary tree node
 *
 * Return: void
 */
void push(queue_t **head, queue_t **tail, const binary_tree_t *node)
{
	queue_t *new_node;

	new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return;
	new_node->node = node;
	if (*head == NULL)
	{
		(*head) = new_node;
		(*tail) = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = (*head);
		new_node->prev = NULL;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

/**
 * pop - pops a node from tail of the queue
 * @tail: pointer to tail of the queue
 *
 * Return: void
 */
void pop(queue_t **tail)
{
	queue_t *tmp;

	tmp = (*tail);
	(*tail) = (*tail)->prev;
	free(tmp);
}

/**
 * binary_tree_levelorder - Level-order traversal
 * @tree: pointer to root node
 * @func: pointer to function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head = NULL, *tail = NULL;
	const binary_tree_t *current;

	if (!tree)
		return;
	push(&head, &tail, tree);
	while (tail)
	{
		current = tail->node;
		if (current->left)
			push(&head, &tail, current->left);
		if (current->right)
			push(&head, &tail, current->right);
		func(tail->node->n);
		pop(&tail);
	}
}
