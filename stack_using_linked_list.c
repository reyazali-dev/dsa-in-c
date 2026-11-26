/*
 *@Author: Reyaz Ali
 *Purpose: Implementation of Stack Using Linked List
 */

#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

struct stack *TOP=NULL;

void push(int x) {
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp==NULL) {
        printf("\nNo Enough Memory!");
        return;
    }
    temp->data=x;
    temp->next=NULL;

    if (TOP==NULL) {
        TOP=temp;
        printf("\nPushed Item: %d",TOP->data);
        return;
    }
        temp->next=TOP;
        TOP = temp;
    printf("\nPushed Item: %d",TOP->data);
}

void display(void) {
	if(TOP==NULL){
		printf("\nStack Is Empty!");
		return;
	}
    struct stack *ptr=TOP;
    while (ptr!=NULL) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}


void pop() {
	if(TOP==NULL){
		printf("\nStack Underflow!");
		return;
	}
    struct stack *ptr=TOP;
    TOP = TOP->next;
    printf("\nPopped Item: %d",ptr->data);
    free(ptr);
}


void peek() {
    if (TOP==NULL) {
        printf("\nStack Does Not Exist!");
        return;
    }
    else {
        printf("\nThe Peak is: %d\n",TOP->data);
    }
}

void is_empty() {
    if (TOP==NULL) {
        printf("\nThe Stack is Empty!");
    }
    else {
        printf("\nThe Stack is Not Empty!");
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\nPress 1 to Push an Element in a Stack.");
        printf("\nPress 2 to Pop an Element in a Stack.");
        printf("\nPress 3 to Check Peak Value in a Stack.");
        printf("\nPress 4 to Display a Stack.");
        printf("\nPress 5 to Exit.\n");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                int e;
                printf("\nEnter the Element You Want to Push: ");
                scanf("%d",&e);
                push(e);
                break;

            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice!");

        }
    }
    return 0;
}
