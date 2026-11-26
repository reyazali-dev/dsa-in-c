#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(char x) {
    if (top==MAX-1) {
        printf("\nStack Overflow!");
        return;
    }
    stack[++top]=x;
}

char pop(void) {
    if (top==-1) {
        printf("\nStack Underflow!");
        return '\0';
    }

    return stack[top--];
}


int precedence(char ch) {
    if (ch=='^')
        return 3;

    else if (ch=='*'|| ch=='/')
        return 2;
    else if (ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}

int main(void) {
    char infix[MAX],postfix[MAX];
    int i=0,j=0;
    char ch;
    printf("\n==Infix to Postfix Expression Using Stack==");
    while (1) {
        printf("\nEnter an Infix Expression: ");
        scanf("%s",infix);
        for (i=0;i<strlen(infix);i++) {
            ch = infix[i];
            if (isalnum(ch))
                postfix[j++]=ch;
            else if (ch=='(')
                push(ch);
            else if (ch==')') {

                while (top!=-1&&stack[top]!='('&&stack[top]) {
                    postfix[j++]=pop();
                }
                pop();
            }

            else {
                while (top!=-1 && stack[top]!='(' && precedence(stack[top])>=precedence(ch)) {
                    postfix[j++]=pop();
                }
                push(ch);
            }
        }

        while (top!=-1) {
            postfix[j++]=pop();
        }
        postfix[j]='\0';

        printf("\nPostfix Expression: %s\n",postfix);
    }
    return 0;
}