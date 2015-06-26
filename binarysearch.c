#include<stdio.h>
main()
{

	int low,high,mid;//variables for binary search//
	int a[100],key,i,size;//size of the array and index//
	int flag=0;

	printf("enter the size of the array\n");//asking the size//
	scanf("%d",&size);

	printf("enter the elements of the array...\n");//entering the elements//
	for(i=0;i<size;i++)//storing the elements//
	{
	  scanf("%d",&a[i]);
	}
	printf("enter the element to search..\n");//entering the key//
	scanf("%d",&key);
	
	low=0;
	high=size-1;

	do//start of the do while loop//
	{
	  mid=(low+high)/2;//the formula//
	  if(a[mid]==key)
	  {
            flag=1;//the key is found//
	    break;
	  }
	  else if(a[low]>a[mid]||a[mid]>a[high]||a[low]>a[high])
	  {
	    flag=2;
	  }
          else
	  {
	      if(a[mid]>key)
	        {
		  high=mid-1;
		}
	      else
		{
		  low=mid+1;
		}
	  }
	}while(low<=high);//end of the loop//

	{
	   if(flag==0)//start of else if ladder//
	     printf("Not found\n");
	   else if(flag==1)
	     printf("Found\n");
	   else if(flag==2)
	     printf("Not ordered\n");
	   else//end of the else if ladder//
	     printf("Error\n");
 	}
	
	
}
