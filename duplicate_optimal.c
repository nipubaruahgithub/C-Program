#include<stdio.h>
main()
{
  int i,n;
  printf("Enter the value of n:\n");
  scanf("%d",&n);
  int a[n],b[n];
  printf("Enter 1st array:\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
   b[i]=0;
  }
  for(i=0;i<n;i++)
  {
   b[a[i]]+=1;
  }
  printf("The repeating elements are;\n");
  for(i=0;i<n;i++)
  {
   if(b[i]>1)
    printf("%d\n",i);

  }
}
