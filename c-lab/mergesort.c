#include<stdio.h>

int main()
{
int n,i,j,k;
printf("Enter the size of the first array");
scanf("%d",&n);
int arr1[n];
printf("Enter the elements to the first array");
for(i=0;i<n;i++)
{
scanf("%d",&arr1[i]);
}
printf("Enter the size of the second array");
scanf("%d",&k);
int arr2[k];
printf("Enter the elements to the second array");
for(j=0;j<k;j++)
{
scanf("%d",&arr2[j]);
}
int in;
i=j=0;
int arr3[n+k];
for(in==0;in<n+k;in++)
{
if(i<n&&j<k)
{
if(arr1[i]<arr2[j]){
arr3[in]=arr1[i];
i++;
}
else
{
arr3[in]=arr2[j];
j++;
}
}
else if(i<n)
{
arr3[in]=arr1[i];
i++;
}
else
{
arr3[in]=arr2[j];
j++;
}
}

printf("The merged array is");
for(in=0;in<n+k;in++)
{
printf("\n%d",arr3[in]);
}

return 0;
}

