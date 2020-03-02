#include<bits/stdc++.h>

using namespace std;

float isOperator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		return 1;
	return -1;
}

float evaluate(string expr){
	stack <float> s;
	int a,b;
	for(int i=expr.size()-1;i>=0;i--){
		if(isOperator(expr[i]) !=-1){
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			switch(expr[i]){
				case '+':
				s.push(a+b);
				break;
				case '-':
				s.push(a-b);
				break;
				case '*':
				s.push(a*b);
				break;
				case '/':
				s.push(a/b);
				break;
				case '^':
				s.push(pow(a,b));
				break;
			}
		}
		else{
			s.push(expr[i]-'0');
		}
		
	}
	return s.top();
}

int main(){
	string expr = "+9*26"; 
	cout<<evaluate(expr);
	return 0;
}