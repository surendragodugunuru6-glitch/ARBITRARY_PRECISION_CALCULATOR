#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#define MAX 100000000000

typedef unsigned long long int u_intll;
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;
int addition(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR);
int subtraction(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR);
int multiplication(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR);
int division(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR);
void list_operands_to_DLL(char *str,Dlist **head,Dlist **tail);
void insert_at_last(Dlist **head,Dlist **tail,Dlist **new);
int compare_node_by_node(Dlist **headR,Dlist **head1);
int addition_for_division(Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
void copy_list(Dlist **head2,Dlist **tail2,Dlist **copy_head2,Dlist **copy_tail2);
void count(Dlist **count_head,Dlist **count_tail);
u_intll len(Dlist **head2);
#endif

