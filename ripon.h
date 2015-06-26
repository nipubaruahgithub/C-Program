/********************************************************************************************************************************************
This is our library. Ihave not tested all other condition. Please test the boundary cases. The function may fails depend on the user input.
Use this functions from main function.

***********************************************************************************************************************************************/


/* Defining structure a single linked list
The info variable of the structure is value of a node in linked list
next is a pointer to hold address of same kind of structure or it is a pointer to point next node.
*/
struct linked_list
{
	int info;
	struct linked_list *next;
};
typedef struct linked_list node;



//Insert an element at front in a linked list
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



//Insert an element in a linked list
node *insert_at_last(node *head,int n)	
{
	node *start=head,*temp;
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		if(head==NULL)  //// if the list is empty
		{
			printf("Memory is not available");
			return;
		}
		head->info=n;
		head->next=NULL;
	}
	else
	{
		while(start->next!=NULL)
			start=start->next;
		temp=(node *)malloc(sizeof(node));
		if(temp==NULL)				/// if the memory is unabailable
		{
			printf("Memory is not available");
			return;
		}
		temp->info=n;				///insert at last....
		temp->next=NULL;
		start->next=temp;
	}
	return head;
}




// Display single linked list only. The list must
// be null terminated.
void display(node * head)
{
	if(head)    //stops when head==NULL
	{
		//display(head->next);
		printf("%d->",head->info);
		display(head->next);    //Recursive call for next node.
	}
}





//find out middle element in a single traverse
void find_middle(node *head)
{
	node *ptr=head,*p=head;
	int flag=0;
	if(head==NULL)   ///List may empty
	{
		printf("Emtpy List\n");
		return;
	}
	while(1)
	{
		if(p->next==NULL)         //List may contains odd numbers of elements
			break;
		if(p->next->next==NULL)  //List may contains even numbers of elements
		{
			flag=1;          //flag is set to zero, if the list contains even numbers of elements
			break;
		}
		ptr=ptr->next;
		p=p->next->next;
	}
	if(flag)			//if the list contains even numbers of elements, two elements should be printed.
		printf("\nThe middle elements is: %d     %d\n",ptr->info,ptr->next->info);
	else
		printf("\nThe middle elements is: %d\n",ptr->info);
}





// Repeated element in a linked list to be printed with O(n) time complexity.
// O(n) extra spaces is used.
// Assuming the list contains only <100
void repeated_in_SLL(node *head)
{
	int a[100],i;
	node *temp=head;
	for(i=0;i<100;i++)
		a[i]=0;
	while(temp)
	{
		a[temp->info]+=1;
		temp=temp->next;
		
	}
	for(i=0;i<100;i++)
		if(a[i]>1)
			printf("%d   ",i);
}





//Insertion sort
// Sort while streaming
node *insertion_sort(node *head, int n)
{
	node *temp,*start=head,*p;
	temp=(node *)malloc(sizeof(node));
	temp->info=n;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
		return head;
	}
	if(head->next==NULL)
	{
		if(head->info>=temp->info)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			head->next=temp;
			temp->next=NULL;
		}
		return head;
	}
	p=head;	
	while(p->info<n&&p->next)
	{
		start=p;
		p=p->next;
		
	}
	
	if(p->info<n&&p->next==NULL)
	{
		p->next=temp;
		temp->next=NULL;
		return head;
	}
	if(p==head)
	{
		temp->next=head;
		head=temp;
		return head;
	}
	start->next=temp;
	temp->next=p;
	return head;
}





//Merging two sorted output. Produce sorted output.
// Method: It takes O(1) xtra space.

node *merge(node *head1,node *head2)
{
	node *p1=head1,*p2=head2,*s,*prev;
	
	if(head1==NULL && head2==NULL)
		return NULL;
	else
	if(head1==NULL)
		return head2;
	else
	if(head2==NULL)
		return head1;
	else
	{
		if(p1->info>p2->info)
		{
			s=p2;
			prev=p2;
			p2=p2->next;
		}
		else
		{
			s=p1;
			prev=p1;
			p1=p1->next;
		}
		while(p1&&p2)
		{
			
			if(p1->info>p2->info)
			{
				prev->next=p2;
				prev=prev->next;
				p2=p2->next;
				
			}
			else
			{
				prev->next=p1;
				prev=prev->next;
				p1=p1->next;
			}
			
		}
		if(p1)
			prev->next=p1;
		else
			prev->next=p2;
	}
	
	return s;
}




// creating Y shape of two linked list
// n is a input from user where the intersection is made in head1.
//
node *create_Y_shape(node *head1, node *head2,int n)
{
	int i=0;
	node *p1=head1,*p2=head2;
	while(p2->next!=NULL)
		p2=p2->next;
	while(++i!=n)
		p1=p1->next;
	p2->next=p1;
	return head2;
}




//Detecting Y shape
//Find the lenght of both list
//i=-1 because the both list can be same lenght

void detect_Y_shape(node *head1, node *head2)
{
	int m=0,n=0,i=-1;
	node *p1=head1,*p2=head2;
	while(p1!=NULL)
	{
		p1=p1->next;
		m++;
	}
	while(p2!=NULL)
	{
		p2=p2->next;
		n++;
	}
	p1=head1;
	p2=head2;
	if(m>n)
	{
		while(++i!=(m-n))
			p1=p1->next;
	
	}
	else
	{	
		while(++i!=(n-m))
			p2=p2->next;
	}
	while((p1!=p2)&&p1&&p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==p2&&p1)
		printf("%d is intersecting point\n",p1->info);
	else
		printf("No intersecting point\n");
}




// Destroy a linked list without using extra variable.
// Delete all nodes of linked list.
node *destroy(node *head)
{
	if(head)
	{
		head=destroy(head->next);
		free(head);
	}
	return head;
}
