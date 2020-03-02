#include<bits/stdc++.h>
using namespace std;

// function to check if the character is operator or not
int isOperator(char ch){
	if(ch=='*'||ch=='/'||ch=='+'||ch=='-'||ch=='^'){
		return 1;
	}
	return -1;
}
//function to check if the character is operand or not
int isOperand(char ch){
	if(ch>='0'&& ch<='9')
		return 1;
	return -1;
}
// function to evaluate the expression
float evaluate(int a,int b,char op){
	if(op=='*')
		return b*a;
	else if(op=='+')
		return b+a;
	else if(op=='-')
		return b-a;
	else if(op=='/')
		return b/a;
	else if(op=='^')
		return pow(b,a);
   else
      return INT_MIN;
}

int postfixeval(string expr){
	int a,b;
	stack <float> s;
	for(int i=0;i<=expr.size()-1;i++){
		if(isOperator(expr[i]) !=-1){
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			s.push(evaluate(a,b,expr[i]));
		}
		else if(isOperand(expr[i])!=-1){
			s.push(expr[i]-'0');  // changing string to integer
		}
	}
	return s.top();
}
int main(){
	int x;
	string expr="53+62/*35*+";
	x=postfixeval(expr);
	printf("%d",x);
   return 0;
}