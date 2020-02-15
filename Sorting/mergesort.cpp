#include<stdlib.h>
#include<stdio.h>
void merge(int a[],int l,int m, int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	// Creating two new temporary arrays
	int L[n1],R[n2];
	// Copying the data into temporary arrays
	for(i=0;i<n1;i++){
		L[i]=a[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=a[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else {
			a[k]=R[j];
			j++;
		}
		k++;
	}
	// Copy the remaining left or right subarray elemets if there are any
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}	
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}
void mergeSort(int a[],int l,int r){
	if(l<r){
		int m=(l+r)/2;

		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int arr[] = {12, 11, 13, 5, 6, 7}; 
    int size = sizeof(arr)/sizeof(arr[0]);
	printf("Befor sorting the array is: ");
	print(arr,size);
	mergeSort(arr,0,size-1);
	printf("After sorting the array is : ");
	print(arr,size);
	return 0;
}