0x17. C - Doubly linked lists

Resources
What is a Doubly Linked List\n

Learning Objectives
What is a doubly linked list\n
How to use doubly linked lists\n
Understand and know how to implement the various operations (deletion, insertion, etc) with doubly linked lists\n
Start to look for the right source of information without too much help\n

use this data structure
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * 
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
