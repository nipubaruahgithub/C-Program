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
	node *temp;
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->info=n;
		head->next=NULL;
	}
	else
	{
		temp=(node *)malloc(sizeof(node));
		temp->info=n;
		temp->next=head;
		head=temp;
	}
	return head;
}
void display(node * head)
{
	if(head)
	{
		display(head->next);
		printf("%d->",head->info);
		//display(head->next);
	}
}
//find out middle element in a single traverse
void find(node *head)
{
	int flag=0;
	node *ptr=head,*p=head;
	while(1)
	{
		if(p->next==NULL)
			break;
		if(p->next->next==NULL)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;
		p=p->next->next;
	}
	if(flag)
		printf("\nThe middle elements is: %d	%d\n",ptr->info,ptr->next->info);
	else
		printf("\nThe middle element is: %d\n",ptr->info);
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
	find(head);
	return 0;
}	
	
