#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int Queue[MAX]={0};
int Pri[MAX]={0};
int front=-1,rear=-1;

void EnQueue(int x, int p){
	if(rear==MAX-1){
		printf("\nCan't Insert At Rear.");
		return;
	}
    else if(rear==-1){
    	rear=front=0;
    	Queue[rear]=x;
    	Pri[rear]=p;
    	printf("\nQueued Item: %d with Priority: %d",Queue[rear],Pri[rear]);
    	return;
	}
	rear++;
	Queue[rear]=x;
	Pri[rear]=p;
	printf("\nQueued Item: %d with Priority: %d",Queue[rear],Pri[rear]);
}


void DeQueue(void){
	if(front==-1){
		printf("\nQueue Underflow.");
		return;
	}
int i,max=front;
for(i=0;i<=rear;i++){
	if(Pri[i]>Pri[max])
	 max=i;
}
printf("\nDeQueued Item: %d with Priority: %d",Queue[max],Pri[max]);
for(i=max;i<rear;i++){
	Queue[i]=Queue[i+1];
	Pri[i]=Pri[i+1];
}
rear--;
if(rear<front){
	rear=front=-1;
}

}

void display(void) {
	if (front==-1) {
		printf("\nPriority Queue is Empty!");
		return;
	}

	int i;
	printf("\nData   Priority");
	for (i=front;i<=rear;i++) {
		printf("\n%d\t\t%d",Queue[i],Pri[i]);
	}
}

int main(void){
	int choice;
	printf("\nPriority Queue Using Arrays.");
	while(1){
	printf("\nPress 1 to EnQueue.");
	printf("\nPress 2 to Dequeue.");
	printf("\nPress 3 to Display.");
	printf("\nPress 4 to Exit.\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the Data You Want to Insert: ");
			int a,b;
			scanf("%d",&a);
			printf("\nEnter its Priority: ");
			scanf("%d",&b);
			EnQueue(a,b);
			break;
			
		case 2:
			DeQueue();
		    break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
			printf("\nInvalid Choice");
	}
	}
	return 0;
}

