#include<bits/stdc++.h>
using namespace std;

int prec(char c){
	if(c=='^')
		return 3;
	else if(c=='/'||c=='*')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else 
		return -1;
}

void infixToPostfix(string expr){
	stack <char> s;
	string postfix;
	for(int i=0;i<expr.length();i++){
		// in case of operand append it 
		if(expr[i]>='a' && expr[i]<='z') 
			postfix = postfix + expr[i];
		// in case of opening parenthesis just append it
		else if(expr[i]=='(')
			s.push(expr[i]);
		// in case of closing parenthesis append and pop the items from the stack till a opening parenthesis is encountered
		else if(expr[i]==')'){
			while(s.top()!='(' && !s.empty()){
				postfix += s.top();
				s.pop();
			}
			// pop the opening parenthesis
			if (s.top()=='(')
				s.pop();
		}
		// in case of operator check the precedence and do accordingly
		else{
			while(!s.empty() && prec(expr[i])<=prec(s.top())){
				postfix += s.top();
				s.pop();
			}
			s.push(expr[i]);
		}
	}	
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	cout<<"The postfix expression is "<<postfix<<endl;
}
int main(){
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}