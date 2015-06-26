#include<stdio.h>
main()
{
	int a,count=0,i;//the new data is denoted by a,count is zero because it is a counter for the numbers,i is used in if statement// 
	:wq
float current_avg,previous_avg=0 ;//previous avg is zero because to calculate current average as per the counter//

	while(1)//start of while loop//
	{
	
	  printf ("enter the new data\n");//for the new data//
	  scanf("%d",&a);
	
	  current_avg= (previous_avg*count+a)/(count+1);//the formula for calculation//
	  previous_avg=current_avg;
	  
	
	printf("the current average is %f",current_avg);//for the current average//
	
	count++;

	printf("enter 1 for continue or 0 for exit:");//decides to finish or exist//
	scanf("%d",&i);
	if(i==0)
		break;//the loop will break//

    	}           
}




	
	

	


	 
