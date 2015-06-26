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
	node *ptr=head,*p=head;
	while(1)
	{
		if(p==NULL||p->next==NULL||p->next->next==NULL)
			break;
		ptr=ptr->next;
		p=p->next->next;
	}
	printf("\nThe middle elements is: %d\n",ptr->info);
}
node *destroy(node *head)
{
	if(head)
	{
		head=destroy(head->next);
		free(head);
	}
	return head;
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
	destroy(head);
	return 0;
}

