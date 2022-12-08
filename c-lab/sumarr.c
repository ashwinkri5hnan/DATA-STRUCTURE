#include<stdio.h>
int main()
{
int i,n,sum=0,a[100];
printf("Enter the size of the array");
scanf("%d",&n);
printf("Enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("The array is");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
printf("The sum is");
for(i=0;i<n;i++){
sum+=a[i];
}
printf("%d",sum);
return 0;
}
