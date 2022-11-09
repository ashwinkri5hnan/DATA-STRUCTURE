#include<stdio.h>
int main(){
int a[50],n,i,j,temp;
printf("enter the number of array");
scanf("%d",&n);
printf("enter the elements to the array");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
printf("%d",a[i]);
}
for(i=0;i<n-1;i++){
	for(j=0;j<n-1;j++){
	if(a[j]>a[j+1]){
        temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp; 
}
}
}
printf("the array is");
for(i=0;i<n;i++){
	printf("%d",a[i]);
}

return 0;
}
