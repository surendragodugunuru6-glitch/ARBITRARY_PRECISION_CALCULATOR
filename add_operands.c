#include <stdio.h>
#include <string.h>
#include "apc.h"
#include <stdlib.h>

void list_operands_to_DLL(char *str,Dlist **head,Dlist **tail)
{
     for(int i=0;str[i]!='\0';i++)
     {
       Dlist *new=malloc(sizeof(Dlist));
       if(new==NULL)
       {
	       printf("Memory allocation failed\n");
       }
       else
       {
	       new->data=str[i]-48;
	       new->next=NULL;
	       new->prev=NULL;
	       insert_at_last(head,tail,&new);
       }
     }
}


void insert_at_last(Dlist **head,Dlist **tail,Dlist **new)
{
	if(*tail==NULL&&*head==NULL)
	{
		*tail=*new;
		*head=*new;
	}
	else
	{
		(*new)->prev=*tail;
		(*tail)->next=*new;
		*tail=*new;
	}
}
     

