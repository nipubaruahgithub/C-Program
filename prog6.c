#include<stdio.h>
#include<malloc.h>
#include"ripon.h"

 void swap_couple(node *head)
        {   int a;

         node *p1=head,*p2=head->next;
         while(1)
         {
		if(p1!=NULL && p2!=NULL)
		{
                  p1->info=p1->info^p2->info;
                  p2->info=p1->info^p2->info;
                  p1->info=p1->info^p2->info;
                


                  p1=p1->next->next;
                  p2=p2->next->next;
                }
		else
		break;
         }
        }

void main()
{

	node *head=NULL;
	int n;
	while(1)
	{
	   printf("Enter the elements(Type -9999 to end):");
	   scanf("%d",&n);

	   if(n!=-9999)
		{
		   head=insert_at_last(head,n);
		}
	   else
	   break;
	}
	printf("The input...");

	display(head);
	swap_couple(head);
        node *new_head;
        new_head=head->next;

        printf("The output...");
        display(new_head);

}	
	

     		
