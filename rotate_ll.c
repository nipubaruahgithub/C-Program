#include<stdio.h>
#include<malloc.h>
#include"ripon.h"
void rotate(node *head,int k);
node *reverse(node *head);
main()
{
	node *head=NULL;
	int n,k;
	while(1)
	{
		printf("Enter any number: ");
		scanf("%d",&n);
		if(n!=-99)
		{
			head=insert_at_last(head,n);
		}
		else break;
	}
	display(head);
	printf("\nEnter the value of k:");
	scanf("%d",&k);
	rotate(head,k);
}
void rotate(node *head,int k)
{
	node *temp,*p=head,*ptr=head,*p1=head;
	int count=1,l;
	while(p1->next!=NULL)
	{
		count++;
		p1=p1->next;
	}
	k=k%count;
	l=count-k;
	count=1;	
	while(count!=l)
	{
		p=p->next;
		count++;
	}
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		//count++;
	}
	ptr->next=head;
	head=p->next;
	p->next=NULL;
	printf("\nThe rotated list is:\n");
	display(head);
}
