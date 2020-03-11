#include<bits/stdc++.h>
#define MAX 10
using namespace std;
//make a global array and set front and rear to -1
int x[MAX];
int front=-1,rear=-1;

void print(){
	int length = (rear-front+ MAX)%MAX;
	for(int i=0;i<length;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
// to check if the list(array) is full
bool isFull(){
	if((rear+1)%MAX==front)
		return true;
	return false;
}
//to check if the list(array) is empty
bool isEmpty(){
	if(front==rear==-1)
		return true;
	return false;
}
//adding elements in the list
void enqueue(int n){
	if(isFull())
		return;
	else if(isEmpty()){
			front=rear=0;
		}
	else{
		rear=(rear+1)%MAX;
	}	
	x[rear]=n;
}
//removing elements from the list
void dequeue(){
	if(isEmpty())
		return;
	else if(front==rear)
		front=rear=-1;
	else{
		front=(front+1)%MAX;
	}
}
int main(){
	front=rear=-1;
	enqueue(5); print();
	enqueue(8); print();
	enqueue(23); print();
	dequeue(); print();
	enqueue(6); print();
	enqueue(53); print();
	enqueue(1); print();
	dequeue(); print();
	dequeue(); print();

	return 0;
}