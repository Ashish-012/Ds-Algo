#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
void Reverse(char c[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		S.push(c[i]);
	}	// Pushing all the elements of array into stack
	for(int i=0;i<n;i++){
		c[i]=S.top();
		S.pop();
	}

}
int main(){
	char c[100];
	printf("Enter the string you want to get reversed : ");
	gets(c);	
	Reverse(c,strlen(c));
	printf("After reversal list is %s",c);
}