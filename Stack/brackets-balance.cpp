#include<iostream> 
#include<string.h>
#include<stack>
using namespace std;

bool CheckBalanceParenthesis(char expr[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		if(expr[i]=='['||expr[i]=='{'||expr[i]=='('){
			S.push(expr[i]);
		}
		else if(expr[i]==']'||expr[i]=='}'||expr[i]==')'){
			if(S.empty()){
				return false;
			}
			char top=S.top();
			if(expr[i]==')' && top=='(')
				S.pop();
			else if(expr[i]==']' && top=='[')
				S.pop();
			else if(expr[i]=='}' && top=='{')
				S.pop();
			else
				return false;
		}
	}
	return S.empty()? true:false;
}

int main(){
	char a[100];
	printf("Enter some expression : ");
	gets(a);
	int x=CheckBalanceParenthesis(a,strlen(a));
	if(x==1)
		printf("Balanced");
	else
		printf("Not Balanced");
}