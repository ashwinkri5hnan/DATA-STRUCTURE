#include<stdio.h>
int main(){
int a[50],n,i,search;
printf("enter the number of elemenets you want to print");
scanf("%d",&n);
printf("enter the elements to the array");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
printf("%d",a[i]);
}
printf("enter the element you want to search");
scanf("%d",&search);
for(i=0;i<n;i++){
if(search==a[i]){
printf("the index of searched element,%d is %d",a[i],i);
}
}

return 0;
}
