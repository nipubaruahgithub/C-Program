#include<stdio.h>
#include<stdlib.h>
struct DLL
{
	int info;
	struct DLL *next;
	struct DLL *prev;
};
typedef struct DLL dll;
void display_ls(dll *head);
dll *create(dll *head,int n)
{
	dll *temp,*p=head;
	temp=(dll *)malloc(sizeof(dll));
	temp->info=n;
	if(head==NULL)
	{
		head=temp;
		head->prev=NULL;
		head->next=NULL;
		return head;
	}
	if(head->next==NULL)
	{
		head->next=temp;
		temp->prev=head;
		temp->next=NULL;
		return head;
	}
	
	while(p->next!=NULL)
	{
			p=p->next;
	}
	p->next=temp;
	temp->prev=p;
	temp->next=NULL;
	return head;
}
dll *create_first(dll *head,int n)
{
	dll *temp,*p=head;
	temp=(dll *)malloc(sizeof(dll));
	temp->info=n;
	if(head==NULL)
	{
		head=temp;
		head->prev=NULL;
		head->next=NULL;
		return head;
	}
	if(head->prev==NULL)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		return head;
	}
	while(p->prev!=NULL)
	{
		p=p->prev;
	}
	p->prev=temp;
	temp->prev=NULL;
	temp->next=p;
	return head;
	
}
dll *insert_first(dll *head,int n)
{
	dll *temp,*p=head;
	temp=(dll *)malloc(sizeof(dll));
	temp->info=n;
	if(head==NULL)
	{
		head=temp;
		head->prev=NULL;
		head->next=NULL;
		return head;
	}
	else
	{
		temp->next=head;
		head=temp;
		return head;
	}
}
dll *insert_any(dll *head,int n,int pos)
{
	dll *temp,*p=head,*p1;
	temp=(dll *)malloc(sizeof(dll));
	temp->info=n;
	int count=0;
	if(head==NULL)
	{
		head=temp;
		head->prev=NULL;
		head->next=NULL;
		return head;
	}
	if(head->prev==NULL)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		return head;
	}
	while(p->next!=NULL && p->info!=pos)
	{
		p=p->next;
	}
	p->next=p1;
	p->next=temp;
	temp->next=p1;
	temp->prev=p;
	return head;
}
void display(dll *head)
{
	if(head)
	{
		printf(" %d ",head->info);
		display(head->next);
	}
}
main()
{
	int n,pos;
	dll *head=NULL;
	while(1)
	{
		printf("Enter any number: ");
		scanf("%d",&n);
		printf("Enter position: ");
		scanf("%d",&pos);
		if(n!=-99)
		{
			head=insert_any(head,n,pos);
		}
		else break;
	}
	display(head);
}

