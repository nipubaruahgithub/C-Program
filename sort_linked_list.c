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
p=head->next;
while(p->info<n)

int main()
{
        node *head=NULL;
        int n;
        while(1)
        {
                printf("Enter the elements(type -9999 to end):");
                scanf("%d",&n);
                i                                                                                                                                                                         f(n!=-9999)
                        head=create(head,n);
                else
                        break;
        }

