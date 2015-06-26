#include<stdio.h>
main()
{
	int n,count=1,i;
	float pre_avg=0,new_avg;
	printf("Enter numbers:\n");
	for(;;)
	{
			scanf("%d",&n);
			new_avg=(pre_avg*(count-1)+n)/count;
			printf("New-avg: %f\n",new_avg);
			count++;
			pre_avg=new_avg;
	}
}

