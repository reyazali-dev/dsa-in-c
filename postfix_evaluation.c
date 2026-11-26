#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int x){
	if(top==MAX-1){
		printf("\nStack Overflow.");
		return;
	}
	top++;
	stack[top]=x;
}
int pop(void){
	if(top==-1){
		printf("\nStack Underflow.");
		return;
	}
	return stack[top--];
}
int main(void){
	
	//5+3/2*4
	//5+1*4
	//5+4
	//9
//5+[32/]*4
//5+[32/4*]
//532/4*+
	char postfix[MAX];
	int i,a,b;
	printf("\nEnter Any Postfix String: ");
	scanf("%s",postfix);
	for(i=0;i<strlen(postfix);i++){
		char ch = postfix[i];
		if(isdigit(ch)){
			push(ch-'0');
			
		}
		else {
			b = pop();
			a = pop();
			switch(ch){
			case '+':
				push(a+b);
				break;
			case '-':
				push(a-b);
				break;
			case '*':
				push(a*b);
				break;
			case '/':
				if(b==0){
					printf("\nNot Defined!");
					return 1;
				}
				else{
					push(a/b);
				}
				break;
			default:
				printf("\nInvalid Operator!");	
			}
		}
	}
	printf("\nResult is: %d",pop());
return 0;
}
