#include<stdio.h>
#include<stdlib.h>
struct ll
{
	int info;
	struct ll *next;
};
typedef struct ll stack;
stack *push(stack *top,int n)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->info=n;
	if(top==NULL)
	{
		top=temp;
		temp->next=NULL;
		return top;
	}
	temp->next=top;
	//top->next=NULL;
	top=temp;
	return top;
}
void display(stack *top)
{
	if(top)
	{
		printf(" %d ",top->info);
		display(top->next);
	}
}
stack *pop(stack *top)
{
	stack *temp=top;
	if(top==NULL)
		printf("Empty");
	else
	if(top->next==NULL)
	{
		free(top);
		top=NULL;
	}
	else
	{
		free(temp);
		top=top->next;
		display(top);
	}
	return top;
}
main()
{

	int n,k;
	stack *top=NULL;
	while(1)
	{
		printf("\n\t1.Add\n\t2.Delete\n\t3.Break\n\t");
		scanf("%d",&k);
		switch(k)
		{
			case 1:	printf("Enter any no.: ");
					scanf("%d",&n);
					top=push(top,n);
					display(top);
					break;
			case 2: top=pop(top);
					break;
			case 3: printf("Break!!!");
					exit(0);
					break;					
			default: printf("Incorrect option!");
					 break;
		}
		//if(n=-99) break;
	}
}
