#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
int addition_for_division(Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
        Dlist *temp1=*tail2;
        Dlist *temp2=*tailR;
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
		if(temp2==NULL)
		{
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
		}
		else
		{
			temp2->data=sum;
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

}
