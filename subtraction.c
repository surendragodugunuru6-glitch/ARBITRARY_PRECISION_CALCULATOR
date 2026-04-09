#include <stdio.h>
#include <string.h>
#include "apc.h"
#include <stdlib.h>



int subtraction(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    
        Dlist *temp1=*tail1;
        Dlist *temp2=*tail2;
        int Diff=0;
        int val1,val2;
        while(temp1!=NULL||temp2!=NULL)
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
		if(val1<val2)
		{
		  val1=val1+10;
                  Diff=val1-val2;
                  temp1->prev->data=temp1->prev->data-1;
		}
		else
		{
			Diff=val1-val2;
		}
                Dlist *new=malloc(sizeof(Dlist));
                if(new==NULL)
                {
                        return FAILURE;
                }
                else
                {
                        new->data=Diff;
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
            while (temp)
            {
                    printf("%d", temp -> data);
                    temp= temp -> next;
            }

            printf("\n");
    }
}

int compare_char_by_char(char *op1,char *op2)
{
	for(int i=0;op1[i]!='\0';i++)
{
	if(op1[i]<op2[i])
	{
	  return 0;
	}
}
      return 1;
}

