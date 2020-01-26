//Reversing a linked list using recursion

#include<iostream>
#include<conio.h>
#include<stdio.h>
struct node{
	int data;
	struct node* next;
};
node* head;
void insert(int data,int n){
	node* temp= new node;
	temp->data=data;
	temp->next=NULL;
	if(n==1){
		temp->next=head;
		head=temp;
		return;
	}
	node* temp1=head;
	for(int i=0;i<n-2;i++){
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
void print(){
	node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverse(node* temp){
	if (temp->next==NULL){		// To traverse the list till the very end
		head=temp;
		return;					
	}
	reverse(temp->next);
	node* ptr=temp->next;		
	ptr->next=temp;      		
	temp->next=NULL;      
}
int main(){
	head=NULL;
	insert(4,1);
	insert(5,2);
	insert(1,2);
	insert(9,1);
	printf("Before Reversal the list is : ");
	print();
	printf("After Reversal the list is : ");
	reverse(head);
	print();
}
