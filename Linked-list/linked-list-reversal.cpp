// This is the iterative method to reverse a linked list

#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
node* head;
void insert(int data){  // Always inserting at the end 
	node* temp= new node;
	temp->data=data;
	temp->next=NULL;
	node* temp1=head;
	if ( head==NULL){
		head=temp;
		return;
	}
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
}
node* reverse(){
	node* current,*prev,*next;
	current=head;
	prev=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}

void print(){
	node*temp= head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}	
	printf("\n");
}
int main(){
	head=NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(5);
	printf("Before reversing the list is : ");
	print();
	head=reverse();
	printf("After reversing the list is : ");
	print();
	return 0;
}