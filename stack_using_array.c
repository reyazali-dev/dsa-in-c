//Stack Implementation Using Arrays.
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5
int top = -1;
int i,count;
void push(int *stack, int x) {

    if (top==MAX_SIZE-1) {
        printf("\nStack Overflow!");
        return;
    }
    top++;
    stack[top]=x;
    printf("\nPushed Item: %d",stack[top]);
}

void display(int *stack) {
    if (top==-1) {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nThe Stack is: ");
    for (i=top;i>=0;i--) {
        printf("%d\t",stack[i]);
    }

}

void pop(int *stack) {
    if (top==-1) {
        printf("\nStack Underflow!");
        return;
}
    printf("\nPopped Item: %d",stack[top]);
    top--;
    
}

void peak(int *stack) {
    if (top==-1) {
        printf("\nThe Stack is Empty!");
        return;
    }
    printf("\nThe Peak is %d",stack[top]);
}

void is_empty(int *stack) {
    if (top==-1) {
        printf("\nThe Stack is Empty!");
        return;
    }
    else
        printf("\nThe Stack is Not Empty.");
}

void is_full(int *stack) {
    if (top==MAX_SIZE-1) {
        printf("\nThe Stack is Full or Stack Over Flow.");
    }
    else
        printf("\nThe Stack is Not Full.");
}
int main(void) {
    int x,y;
    int stack[MAX_SIZE];
	printf("\nStack Using Arrays");
    while(1){
    	printf("\nPress 1 to Push an element into the Stack. ");
    	printf("\nPress 2 to Pop an element.");
    	printf("\nPress 3 to Display a Stack.");
    	printf("\nPress 4 to Check Wheather a Stack is Full or Not.");
    	printf("\nPress 5 to Check Wheather a Stack is Empty or Not.");
    	printf("\nPress 6 to See Peak Value in a Stack.\n");
    	scanf("%d",&x);
    	switch(x){
    		case 1:
    			printf("\nEnter the Element You Want to Push: ");
    			scanf("%d",&y);
    			push(stack,y);
    			break;
    		case 2:
    			pop(stack);
    			break;
    		case 3: 
    		    display(stack);
    		    break;
    		case 4:
			    is_full(stack);
				break;
			case 5:
			    is_empty(stack);
				break;
			case 6:
			    peak(stack);
				break;
			default:
			printf("\nInvalid Option!");
			 
		}
	}

    return 0;
}
