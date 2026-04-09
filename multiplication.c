/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int multiplication(Dlist **head1,Dlist **head2,Dlist **tail1, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	u_intll nodes;
        nodes=len(head2);
	int mul_val,val,carry=0;
        Dlist *arr_h[nodes];
        Dlist *arr_t[nodes];
        Dlist *temp1=*tail1;
        Dlist *temp2=*tail2;
	int i=0;
	int j=i; 
        while(temp2!=NULL)
	{
	  arr_h[i]=NULL;
          arr_t[i]=NULL;
	  carry=0;
          while(temp1!=NULL||carry!=0)
	  {
            if(j==0&&temp1!=NULL)
	    {
            mul_val=temp1->data*temp2->data+carry;
	    carry=0;
	    }
	    else if(j>0)
	    {
	    mul_val=0;
	    }
	    else
	    {
	     mul_val=carry;
	    }
	     
            if(mul_val>9)
	    {
		    val=mul_val%10;
		    carry=mul_val/10;
		    Dlist *new=malloc(sizeof(Dlist));
		    if(new==NULL)
		    {
			    printf("Failed to allocate memory\n");
		    }
		    else
		    {
			    new->data=val;
			    new->next=NULL;
			    new->prev=NULL;
			    if(arr_h[i]==NULL)
			    {
			    arr_h[i]=new;
			    arr_t[i]=new;
			    }
			    else
			    {
			      new->next=arr_h[i];
			      (arr_h[i])->prev=new;
			      arr_h[i]=new;
			    }
		    }
	    }
	    else
	    {
		    Dlist *new=malloc(sizeof(Dlist));
		    if(new==NULL)
                    {
                            printf("Failed to allocate memory\n");
                    }
                    else
                    {
                            new->data=mul_val;
                            new->next=NULL;
                            new->prev=NULL;
                            if(arr_h[i]==NULL)
                            {
                            arr_h[i]=new;
                            arr_t[i]=new;
                            }
                            else
                            {
                              new->next=arr_h[i];
                              (arr_h[i])->prev=new;
                              arr_h[i]=new;
	                    }
		    }
	    }
	    if(temp1!=NULL)
	    {
	    if(j==0)
	    {
	     temp1=temp1->prev;
	    }
	    else
	    {
		    j--;
	    }
	    }
	  }
	     addition_for_division(&arr_h[i],&arr_t[i],headR,tailR);
	     
	      i++;
	      j=i;
	      temp1=*tail1;
	      temp2=temp2->prev;
	}	
	Dlist *temp_head=*headR;
       while(temp_head!=NULL)
       {
         printf("%d",temp_head->data);
	 temp_head=temp_head->next;
       }

}
u_intll len(Dlist **head2)
{
	u_intll len=0;
	Dlist *temp=*head2;
	while(temp!=NULL)
	{
          len++;
	  temp=temp->next;
	}
	return len;
}


