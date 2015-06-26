#include<stdio.h>
#include<malloc.h>
struct linked_list
{
	int info;
	struct linked_list *next;
};
typedef struct linked_list node;
node *create(node *head, int n)
{
	node *temp,*start=head;
	temp=(node *)malloc(sizeof(node));
	temp->info=n;
if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		while(start->next!=NULL)
			start=start->next;			
		temp->next=NULL;
		start->next=temp;
	
	}
	return head;
}

void display(node * head)
{
	if(head)
	{
		printf("%d->",head->info);
		display(head->next);
	}
}
void odd_even(node *head)
{
	node *p1=head,*p2=head->next;
	node *prev=NULL,*curr=p2,*Next,*p=head;

	int count=0;
	while(p1->next!=NULL)
	{
		p1->next=p1->next->next;
		p1=p1->next;
		
			
			if(curr)
		{
			Next=curr->next->next;
			curr->next=prev;
			prev=curr;
			curr=Next;
			
		}
		else break;
	}
	p1->next=prev;
	
	display(head);
}
int main()
{
	node *head=NULL;
	int n;

	while(1)
	{
		printf("Enter the elements(type -9999 to end):");
		scanf("%d",&n);
		if(n!=-9999)
			head=create(head,n);
		else
			break;
	}
	display(head);
	printf("\nThe modified list is:");
	odd_even(head);
	return 0;
}	
	

