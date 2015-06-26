#include<stdio.h>
#include<malloc.h>
struct linked_list
{
	int info;
	struct linked_list *next;
};
typedef struct linked_list node;
node *insert_at_first(node *head, int n)
{
	node *temp;
	if(head==NULL) // if the list is empty
	{
		head=(node *)malloc(sizeof(node));
		if(head==NULL)  /// if the memory is unabailable
		{
			printf("Memory is not available");
			return;
		}
		head->info=n;     // insertion at empty list
		head->next=NULL;
	}
	else
	{
		temp=(node *)malloc(sizeof(node));
		if(temp==NULL) /// if the memory is unabailable
		{
			printf("Memory is not available");
			return;
		}
		temp->info=n;   // insertion at non-empty list. Insert at front of the list
		temp->next=head;
		head=temp;
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
void delete(node *head)
{
	node *temp=head,*p=head->next;
	temp->next=NULL;
	free(temp);
	printf("\nThe modified list is:\n");
	display(p);
}
int main()
{
	node *head=NULL;
	int n;
	while(1)
	{
		printf("Enter the elements(type -99 to end):");
		scanf("%d",&n);
		if(n!=-99)
			head=insert_at_first(head,n);
		else
			break;
	}
	display(head);
	delete(head);
	return 0;
}	
