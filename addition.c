/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdlib.h>
#include <stddef.h>
#include<stdio.h>

int addition(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	int sum=0,carry=0;
	int val1,val2;
	while(temp1!=NULL||temp2!=NULL||carry!=0)
	{
		if(temp1!=NULL)
		{
			val1=temp1->data;
	        }
		else
		{
			val1=0;
		}
		if(temp2!=NULL)
		{
			val2=temp2->data;
		}
		else
		{
			val2=0;
		}
		sum=val1+val2+carry;
		carry=sum/10;
		sum=sum%10;
		Dlist *new=malloc(sizeof(Dlist));
		if(new==NULL)
		{
			return FAILURE;
		}
		else
		{
			new->data=sum;
			new->next=NULL;
			new->prev=NULL;
			if(*headR==NULL)
			{
				*headR=new;
				*tailR=new;
			}
			else
			{
				 new->next=*headR;
				 (*headR)->prev=new;
				 *headR=new;
			}
		}
		if(temp1!=NULL&&temp2==NULL)
		{
			temp1=temp1->prev;
		}
		else if(temp1==NULL&&temp2!=NULL)
		{
			temp2=temp2->prev;
		}
		else if(temp1!=NULL&&temp2!=NULL)
		{
			temp1=temp1->prev;
			temp2=temp2->prev;
		}
	}


          if (*headR == NULL)
          {
                printf("INFO : List is empty\n");
          }
         else
          {
	    Dlist *temp=*headR;
            while (temp!=NULL)
            {
                    printf("%d", temp -> data);
                    temp= temp -> next;
            }

            printf("\n");
	  }

}
