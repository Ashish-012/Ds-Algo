#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	node* next;
};
node* head;
void push(int x){
	node* temp= new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return;
	}
	temp->next=head;
	head=temp;
}
void pop(){
	node * temp=head;
	if(temp==NULL) return;
	head=temp->next;
	delete temp;
}
void print(){
	node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	head=NULL;
	push(5);print();
	push(3);print();
	push(6);print();
	pop();print();
	push(1);print();
	pop();print();
}