/*
 * delete_node:
 * Deletes a node from a doubly linked list and frees its memory.
 *
 * Parameters:
 *   node - pointer to the node to delete; may be NULL (no-op).
 *
 * Returns:
 *   Pointer to the next node if it exists,
 *   else pointer to the previous node if it exists,
 *   else NULL if the node was the only one in the list.
 */

#include <stddef.h>

typedef struct s_node
{
	struct s_node	*prev_node;
	int				value;
	struct s_node	*next_node;
}	t_node;

t_node	*delete_node(t_node *node)
{
	t_node	*prev_node;
	t_node	*next_node;
	
	if (!node)
		return (NULL);
	prev_node = node->prev_node;
	next_node = node->next_node;
	free(node);
	if (prev_node)
		prev_node->next_node = next_node;
	if (next_node)
		next_node->prev_node = prev_node;
	if (next_node)
		return (next_node);
	if (prev_node)
		return (prev_node);
	return (NULL);
}