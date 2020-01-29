#include<stdio.h>
#define MAX 101
int a[MAX];
int top=-1;
void push(int x){
	if(top==MAX-1){
		printf("Overflow! \n");
		return;
	}
	top++;
	a[top]=x;
}
void pop(){
	if(top==-1){
		printf("No element to pop \n");
		return;
	}
	top--;
}
int Top(){
	return a[top];
}
int isempty(){
	if(top==-1) return 1;
	return 0;
}
void print(){
	printf("Stack : ");
	for(int i=0;i<=top;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	push(2);print();
	push(5);print();
	push(10);print();
	pop();print();
	push(12);print();

}
