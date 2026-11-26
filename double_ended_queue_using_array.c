#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int Queue[MAX];
int front=-1,rear=-1;

void EnQueue_at_rear(int x){
	if(rear==MAX-1){
		printf("\nCan't Insert at Rear.");
		return;
	}
	else if(rear==-1){
		rear=front=0;
		Queue[rear]=x;
		printf("\nQueued Item at Rear-End: %d",Queue[rear]);
		return;
	}
	
    rear++;
    Queue[rear]=x;
    printf("\nQueued Item at Rear-End: %d",Queue[rear]);
}


void DeQueue_at_front(void){
	if(front==-1){
		printf("\nQueue Underflow.");
		return;
	}
	
	else if(front==rear){
		printf("\nDeQueued Item at Front-End: %d",Queue[front]);
		front=rear=-1;
		return;
	}
	printf("\nDeQueued Item at Front-End: %d",Queue[front]);
	front++;
	
}

EnQueue_at_front(int x){
	if(front==-1){
		front=rear=0;
		Queue[front]=x;
		printf("\nEnQueued Item at Front-End: %d",Queue[front]);
		return;
	}
	else if(front==0){
		printf("\nCan't Insert at Front.");
		return;
	}
	front--;
	Queue[front]=x;
	printf("\nEnQueued Item at Front-End: %d",Queue[front]);
    
    
}

void DeQueue_at_rear(void){
	if(rear==-1){
		printf("\nQueue Underflow.");
		return;
	}
	else if(rear==front){
		printf("\nDeQueued Item at Rear-End: %d",Queue[rear]);
		rear=front=-1;
		return;
	}
	printf("\nDeQueue Item at Rear-End: %d",Queue[rear]);
	rear--;
}


void display(void){
	if(front==-1){
		printf("\nDouble-Ended Queue is Empty!");
		return;
	}
	int i;
	printf("\nDEQUEUE: ");
	for(i=front;i<=rear;i++){
		printf("%d\t",Queue[i]);
	}
}
int main(void){
	int choice;
	printf("\nDouble-Ended Queue");
	while(1){
		printf("\nPress 1 to EnQueue at Rear.");
		printf("\nPress 2 to EnQueue at Front.");
		printf("\nPRess 3 to DeQueue at Front.");
		printf("\nPress 4 to DeQueue at Rear.");
		printf("\nPress 5 to Display Double-Ended Queue.");
		printf("\nPress 6 to Exit the Program.\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter the Data You Want to EnQueue: ");
				int a;
				scanf("%d",&a);
				EnQueue_at_rear(a);
				break;
			case 2:
				printf("\nEnter the Data You Want to EnQueue: ");
				int b;
				scanf("%d",&b);
				EnQueue_at_front(b);
				break;
				
			case 3:
				DeQueue_at_front();
				break;
			case 4:
				DeQueue_at_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
			default:
				printf("\nInvalid Choice.");
				
		}
	}
	
	
	
	return 0;
}
