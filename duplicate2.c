#include<stdio.h>
main()
{
  int i,n;
  printf("Enter the value of n:\n");
  scanf("%d",&n);
  int a[n];
  printf("Enter 1st array:\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
   a[a[i]]+=10;
  }
  printf("The repeating elements are;\n");
  for(i=0;i<n;i++)
  {
   if(a[i]>10)
    printf("%d\n",i);

  }
}
