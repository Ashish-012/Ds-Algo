#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string.h>
using namespace::std;

struct node{
	int data;
	node*next;
};

node* head;
void insert(int data,int n){
	node* temp = new node;
	temp->data=data;
	temp->next=NULL;
	if(n==1){
		temp->next=head;
		head=temp;
		return;
	}
	node *temp1=head;
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

void reverse(){
	stack <node*> S;
	if(head==NULL) return;
	node* temp=head;
	while(temp!=NULL){
		S.push(temp);
		temp=temp->next;
	}
	temp=S.top();
	head=temp;
	S.pop();
	while(!S.empty()){
		temp->next=S.top();
		S.pop();
		temp=temp->next;
	}
	temp->next=NULL;
}

int main(){
	head=NULL;
	insert(10,1);	print(); //some sample inputs
	insert(4,2);	print();
	insert(5,1);	print();
	insert(9,2);	print();
	printf("List after reversal is : ");
	reverse();		print();
	return 0;
}