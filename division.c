/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int division(Dlist **head1, Dlist **head2,Dlist **tail1, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
    Dlist *copy_head2=NULL;
    Dlist *copy_tail2=NULL;
    Dlist *count_head=NULL;
    Dlist *count_tail=NULL;
    copy_list(head2,tail2,&copy_head2,&copy_tail2);
    headR=&copy_head2;
    tailR=&copy_tail2;
   while(compare_node_by_node(headR,head1)==1)
   {
	 
	   count(&count_head,&count_tail);
	   addition_for_division(head2,tail2,headR,tailR);
   }
   Dlist *temp=count_head;
       while(temp!=NULL)
     {
	   printf("%d",temp->data);
           temp=temp->next;
   }
}

int compare_node_by_node(Dlist **headR,Dlist **head1)
{
      u_intll len_headR=0,len_head1=0;
      Dlist *temp1=*headR;
      Dlist *temp2=*head1;
      while(temp1!=NULL)
      {
	     len_headR++;
	     temp1=temp1->next;
      }
      while(temp2!=NULL)
      {
	     len_head1++;
	     temp2=temp2->next;
      }
     if(len_head1>len_headR)
     {
	    return 1;
     } 
     else if(len_head1<len_headR)
     {
	     return 0;
     }
     else 
     {
             temp1=*headR;
             temp2=*head1;	     
	     
	     while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data > temp2->data)
	{
            return 0;
	}

        else if(temp1->data < temp2->data)
	{
            return 1;
	}

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
     }


}

void copy_list(Dlist **head2,Dlist **tail2,Dlist **copy_head2,Dlist **copy_tail2)
{
	Dlist *temp1=*head2;
	while(temp1!=NULL)
	{
		Dlist *new=malloc(sizeof(Dlist));
		if(new==NULL)
	        {
			printf("Memory allocated failure\n");
		}
		else
		{
			if(*copy_tail2==NULL)
			{
				 new->data=temp1->data;
                                 new->next=NULL;
                                 new->prev=NULL;
				*copy_head2=new;
				*copy_tail2=new;
			}
			else
			{
				 new->data=temp1->data;
                                 new->next=NULL;
                                 new->prev=NULL;
				(*copy_tail2)->next=new;
				new->prev=*copy_tail2;
				*copy_tail2=new;
			}
                         temp1=temp1->next;

		}
	}

}

void count(Dlist **count_head, Dlist **count_tail)
{
    Dlist *temp = *count_tail;
    int carry = 1;
    int sum;

    if(temp == NULL)
    {
        Dlist *new = malloc(sizeof(Dlist));
        if(new == NULL)
        {
            printf("Failed to allocate memory\n");
            return;
        }

        new->data = 2;
        new->next = NULL;
        new->prev = NULL;

        *count_head = new;
        *count_tail = new;
        return;
    }

    while(temp != NULL && carry != 0)
    {
        sum = temp->data + carry;

        temp->data = sum % 10;
        carry = sum / 10;

        temp = temp->prev;
    }

    if(carry != 0)
    {
        Dlist *new = malloc(sizeof(Dlist));
        if(new == NULL)
        {
            printf("Failed to allocate memory\n");
            return;
        }

        new->data = carry;
        new->prev = NULL;
        new->next = *count_head;

        (*count_head)->prev = new;
        *count_head = new;
    }

}


