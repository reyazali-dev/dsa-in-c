/*
 * @Author: Reyaz Ali
 * Queue Implementation using Arrays.
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int Queue[MAX];
int rear=-1;
int front=-1;

void EnQueue(int x) {
    if (rear==MAX-1) {
        printf("\nCan't Insert At Rear!");
        return;
    }

    else if (front==-1) {
        front=rear=0;
        Queue[rear]=x;
    	printf("\nQueued Item: %d",Queue[rear]);
    }

else {
        rear++;

    Queue[rear]=x;
	printf("\nQueued Item: %d",Queue[rear]);
    }


}

void DeQueue(void) {
    if (front==-1) {
        printf("\nQueue Underflow!");
        return;
    }

    else if (front==rear) {
        printf("\nDeQueued Item: %d",Queue[front]);
        front=rear=-1;
    }
    else {
        printf("\nDeQueued Item: %d", Queue[front]);
        front++;
    }

}

void Display(void) {
	if (front==-1) {
		printf("\nQueue is Empty!");
		return;
	}
	int i;
	printf("\nQueue: ");
	for(i=front;i<=rear;i++) {
		printf("%d\t",Queue[i]);
	}
}
int main(void) {
    int x,y;
	while(1){
		printf("\nPress 1 for En-Queue.");
		printf("\nPress 2 for De-Queue.");
		printf("\nPress 3 to Display Queue.");
		printf("\nPress 4 to Exit.\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("\nEnter the Element You Want to EnQueue: ");
				scanf("%d",&y);
				EnQueue(y);
				break;
			case 2:
				DeQueue();
				break;
			case 3: 
			  Display();
				break;
			case 4:
				exit(1);
			  
			default:
				printf("\nInvalid Choice.");
		}
    }
return 0;
}
