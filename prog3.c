#include<stdio.h>
int main()

{
	int i,j,m,n;
	int a[100][100],b[500][3];
	int c=0;

	printf("enter the no.of columns in the 2D array:\n");
	scanf("%d",&m);
	printf("enter the no.of rows in the  2D array:\n");
	scanf("%d",&n);
	printf("enter the elements of the sparse array;\n");
	for(i=0;i<n;i++)
	{
	   for(j=0;j<m;j++)
	      {
		scanf("%d",&a[i][j]);
	
	      }
	    printf("\n");    
	}
 
	for(i=0;i<n;i++)
	{
	   for(j=0;j<m;j++)
	     {
                 if(a[i][j]!=0)
		   {
			b[c][0]=a[i][j];
		   	b[c][1]=i;
		   	b[c][2]=j;
			c++;
		   }
		
		   
	      }
	}
	printf("The matrix representation is :\n");

	for(i=0;i<c;i++)
	{
	  
	     
		printf("%d  %d  %d\n",b[i][0],b[i][1],b[i][2]);
	        
	     
	}
}
b[i][0]=b[i][0]^b[
printf("the transposed matrix is  
