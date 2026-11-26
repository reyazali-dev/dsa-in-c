#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int Queue[MAX];
int front=-1,rear=-1;

void EnQueue(int x){
	if(front==(rear+1)%MAX){
		printf("\nCircular Queue is Full.");
		return;
	}
	if(rear==-1){
		rear=front=0;
		Queue[rear]=x;
		printf("\nEnQueued Item: %d",Queue[rear]);
		return;
	}
		rear = (rear+1)%MAX;
		Queue[rear]=x;
		printf("\nEnQueued Item: %d",Queue[rear]);
	
}

void DeQueue(void){
	if(front==-1){
		printf("\nCircular Queue Is Empty.");
		return;
	}
	else if(front==rear){
	printf("\nDeQueued Item is: %d",Queue[front]);
	front=rear=-1;
	return;
    }
    front=(front+1)%MAX;
    printf("\nDeQueued Item is: %d",Queue[front]);
}

void display(void){
	if(front==-1){
		printf("\nQueue Empty!");
		return;
	}
	int i=front;
	printf("\nQueue is: ");
	while(1){
		printf("%d\t",Queue[i]);
		if(i==rear)
		break;
		i = (i+1)%MAX;
	}
}

int main(void){
printf("\nCircular Queue using Arrays\n");
while(1){
	printf("\nPress 1 to EnQueue.");
	printf("\nPress 2 to DeQueue.");
	printf("\nPress 3 to Display Queue.");
	printf("\nPress 4 to Exit\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the Element You Want to EnQueue: ");
			int x;
			scanf("%d",&x);
			EnQueue(x);
			break;
		case 2:
			DeQueue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nInvalid Choice.");
	}
}
	return 0;
}
