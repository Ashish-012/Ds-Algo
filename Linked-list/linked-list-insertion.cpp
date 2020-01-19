#include<iostream>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
node* head;
void print(){
	node* temp=head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void insert(int data,int n){
	node* temp1=new node();
	temp1->data=data;
	temp1->next=NULL;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	node* temp= head;
	for(int i=0;i<n-2;i++){
		temp=temp->next;
	}
	temp1->next=temp->next;
	temp->next=temp1;


}	
int main(){
	head=NULL;
	insert(2,1);
	insert(3,2);
	insert(4,1);
	insert(5,2);
	print();
}