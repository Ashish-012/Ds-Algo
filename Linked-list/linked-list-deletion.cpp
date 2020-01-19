#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
node* head;
void insert(int data){  // Always inserting at the end 
	node* temp= new node();
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
void Delete(int n){
	node* temp=head;
	if(n==1){
		head=temp->next;
		delete temp;
		return;
	}
	for(int i=0;i<n-2;i++){
		temp=temp->next;
	}
	node* temp1=temp->next;
	temp->next=temp1->next;
	delete temp1;
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
	print();
	int n;
	printf("Enter a position: ");
	scanf("%d",&n);
	Delete(n);
	print();
	return 0;
	getch();
}