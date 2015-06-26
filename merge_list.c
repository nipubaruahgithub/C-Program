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
		//display(head->next);
		printf("%d->",head->info);
		display(head->next);
	}
}
//find out middle element in a single traverse
void find(node *head)
{
	node *ptr=head,*p=head;
	int flag=0;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
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
	printf("\nThe middle elements are:%d %d\n",ptr->info,ptr->next->info);
	else
	printf("\n The middle element is %d\n",ptr->info);
}
node *merge(node *head1,node *head2)
{
	node *p=head1,*temp;
	while(p->next!=NULL&&p!=NULL)
	{
		p=p->next;
	}
	p->next=head2;
	node *p1=head1,*p2=head1->next;
	/*while(p2->next!=NULL)
	{*/
		if(p1->info>p2->info)
		{
			temp=p2->next;
			
			p2->next=p1;
			p1->next=temp;
		}
		//p2=p2->next;
		//break;
	//}
	return head1;

}

node *reverse(node *head)
{
	node *prev=NULL,*curr=head,*Next;
	while(curr)
	{
		Next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=Next;
	}
}
int main()
{
	node *head1=NULL,*head2=NULL,*temp=NULL,*temp1,*temp2;
	int n;
	while(1)
	{
		printf("Enter the elements of 1st list(type -9999 to end):");
		scanf("%d",&n);
		if(n!=-9999)
			head1=create(head1,n);
		else
			break;
	}
	while(1)
	{
		printf("Enter the elements of 2nd list(type -9999 to end):");
		scanf("%d",&n);
		if(n!=-9999)
			head2=create(head2,n);
		else
			break;
	}
	printf("\nThe 1st list is:\n");
	display(head1);
	printf("\nThe 2nd list is:\n");
	display(head2);
	temp=merge(head1,head2);
	//temp1=sort_ll(temp);
	printf("The merged list is:\n");
	display(temp);
	//find(head);
	return 0;
}	
	

