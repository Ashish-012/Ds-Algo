// Printing the linked list using recursion 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

node* head;

void print(node* temp){
	if(temp==NULL) return;
	
	printf("%d ",temp->data);
	print(temp->next);
}

void printrev(node* temp){
	if(temp==NULL) return;
	printrev(temp->next);
	printf("%d ",temp->data);

}

void insert(int data,int n){
	node* temp= new node;
	node* temp1= head;
	temp-> data= data;
	temp-> next= NULL;
	if(n==1){
		temp->next=head;
		head=temp;
		return;
	}
	for(int i=0;i<n-2;i++){
		temp1=temp1->next;

	}
	temp->next=temp1->next;
	temp1->next=temp;

}

int main(){
	head=NULL;
	insert(2,1);
	insert(3,2);
	insert(4,1);
	insert(5,2);
	printf("Linked list after insertion is : ");
	print(head);
	printf("Linked list reversed : ");
	printrev();
}