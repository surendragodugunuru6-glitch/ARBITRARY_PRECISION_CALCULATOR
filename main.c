#include "apc.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	Dlist *head1=NULL,*head2=NULL,*headR=NULL,*tail1=NULL,*tail2=NULL,*tailR=NULL,*new=NULL;
        if(argc==4)
	{
		if(argv[2][0]=='+')
		{
                list_operands_to_DLL(argv[1],&head1,&tail1);
                list_operands_to_DLL(argv[3],&head2,&tail2); 
                addition(&head1,&head2,&tail1,&tail2,&headR,&tailR);
		}
		else if(argv[2][0]=='-')
		{
			if(strlen(argv[1])<strlen(argv[3]))
			{
				char *temp;
				temp=argv[1];
				argv[1]=argv[3];
				argv[3]=temp;
				list_operands_to_DLL(argv[1],&head1,&tail1);
                                list_operands_to_DLL(argv[3],&head2,&tail2);
                                subtraction(&head1,&head2,&tail1,&tail2,&headR,&tailR);
			}
			else if(strlen(argv[1])>strlen(argv[3]))
		        {
			   list_operands_to_DLL(argv[1],&head1,&tail1);
                           list_operands_to_DLL(argv[3],&head2,&tail2);
                           subtraction(&head1,&head2,&tail1,&tail2,&headR,&tailR);
			}
			else
			{
				if(strlen(argv[1])==strlen(argv[3]))
				{
				  if( strcmp(argv[1],argv[3]) == 0)
				  {
				       printf("0\n");
				  }
				   else
				   {
				     if(compare_char_by_char(argv[1],argv[3])==1)
				     {
					printf("%s %s\n",argv[1],argv[3]);
                                        list_operands_to_DLL(argv[1],&head1,&tail1);
                                        list_operands_to_DLL(argv[3],&head2,&tail2);
                                        subtraction(&head1,&head2,&tail1,&tail2,&headR,&tailR);
				     }
				     else
				     {
                                      char *temp;
                                      temp=argv[1];
                                      argv[1]=argv[3];
                                      argv[3]=temp;
                                      list_operands_to_DLL(argv[1],&head1,&tail1);
                                      list_operands_to_DLL(argv[3],&head2,&tail2);
                                      subtraction(&head1,&head2,&tail1,&tail2,&headR,&tailR);

				     }
				   }
				}
		       }
		}
		else if(argv[2][0]=='/')
		{
			if(strlen(argv[1])>strlen(argv[3]))
		        {
                           list_operands_to_DLL(argv[1],&head1,&tail1);
                           list_operands_to_DLL(argv[3],&head2,&tail2);
                           division(&head1,&head2,&tail1,&tail2,&headR,&tailR);
			 
			}
			else if(strlen(argv[1]) < strlen(argv[3]))
			{
				printf("0\n");
			}
			else if(argv[3][0]=='0')
                        {
                                printf("Invalid operand2\n");
                        }
                        else if(argv[2][0]=='0')
                        {
                                printf("0\n");
                        }
			else if(strlen(argv[1])==strlen(argv[3]))
			{
			        if(strcmp(argv[1],argv[3])==0)
			        {
                                   printf("1\n");
			        }
			        else
			        {
				    if(compare_char_by_char(argv[1],argv[3])==1)
				    {
			             list_operands_to_DLL(argv[1],&head1,&tail1);
                                     list_operands_to_DLL(argv[3],&head2,&tail2);
                                     division(&head1,&head2,&tail1,&tail2,&headR,&tailR);
				    }
				    else
				    {
					printf("0\n");
				    }
			       }
			}
		}
		else if(argv[2][0]=='X')
		{
			 if( argv[1][0]=='0'||argv[3][0]=='0')
                        {
                                printf("0\n");
                        }
			else if(strlen(argv[1])>strlen(argv[3]))
			{
				list_operands_to_DLL(argv[1],&head1,&tail1);
                                list_operands_to_DLL(argv[3],&head2,&tail2);
				multiplication(&head1,&head2,&tail1,&tail2,&headR,&tailR);
			}
			else if(strlen(argv[1])<strlen(argv[3]))
			{
				      char *temp;
                                      temp=argv[1];
                                      argv[1]=argv[3];
                                      argv[3]=temp;
                                      list_operands_to_DLL(argv[1],&head1,&tail1);
                                      list_operands_to_DLL(argv[3],&head2,&tail2);
				      multiplication(&head1,&head2,&tail1,&tail2,&headR,&tailR);
                        }
			else if(strlen(argv[1])==strlen(argv[3]))
			{

                                list_operands_to_DLL(argv[1],&head1,&tail1);
                                list_operands_to_DLL(argv[3],&head2,&tail2);
                                multiplication(&head1,&head2,&tail1,&tail2,&headR,&tailR);
			}
		}
	}

	return 0;
}

