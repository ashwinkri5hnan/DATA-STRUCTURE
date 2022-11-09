#include<stdio.h>
int main(){
int n,i,a[50];
printf("enter the number of elements to the array");
scanf("%d",&n);
printf("enter the elements to the array");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
printf("%d",a[i]);
}

return 0;
}
