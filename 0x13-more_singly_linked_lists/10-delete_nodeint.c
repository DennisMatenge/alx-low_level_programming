#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node in a linked list at a certain index
* @head: pointer to the first element in the list
* @index: index of the node to delete
*
* Return: 1 (Success), or -1 (Fail)
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *prev, *temp;
unsigned int i;

if (!head || !*head)
return (-1);

if (index == 0)
{
temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

prev = NULL;
temp = *head;
for (i = 0; i < index && temp; i++)
{
prev = temp;
temp = temp->next;
}

if (!temp)
return (-1);

prev->next = temp->next;
free(temp);

return (1);
}

