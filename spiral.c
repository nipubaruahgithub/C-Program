#include<stdio.h>
main()
{
	int i,j,k,t,c=0;
	int mat[4][4];
	printf("Enter the matrix elements:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(k=0;k<16;k++)
	{
		for(i=0;i<4;i++)
		{
			
			for(j=0;j<4;j++)
			{
				if(c==i+j)
				{
					printf(" %d ",mat[i][j]);
				}
			c++;			
			}		
		}
	}
}
