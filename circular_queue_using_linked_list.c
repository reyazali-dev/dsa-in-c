#include<stdio.h>
#include<stdlib.h>

struct queue{
	int data;
	struct queue *next;
};

struct queue *front=NULL,*rear=NULL;

void EnQueue(int x){
	struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
	temp->data=x;
	if(front==NULL){
		front=rear=temp;
		printf("\nEnQueued Item: %d",temp->data);
		temp->next=temp;
		return;
	}
    rear->next=temp;
    rear=temp;
    printf("\nEnQueued Item: %d",rear->data);
    rear->next=front;
}

void DeQueue(void){
	if(front==NULL){
		printf("\nCircular Queue Underflow.");
		return;
	}
	struct queue *temp=front;
	if (front==rear) {
		front=rear=NULL;
		printf("\nDeQueued Item: %d",temp->data);
		free(temp);
		return;
	}
	temp = front;
	front = front->next;
	rear->next=front;
	printf("\nDeQueued Item: %d",temp->data);
	free(temp);
}
void display(void) {
	if (front==NULL) {
		printf("\nCircular Queue is Empty.");
		return;
	}
	struct queue *ptr=front;
	printf("\nCircular Queue: ");
	do {
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	while (ptr!=front);
}
int main(void){
int choice;
printf("\nCircular Queue Using Linked List.");
while(1){
	printf("\nPress 1 to EnQueue.");
	printf("\nPress 2 to DeQUeue.");
	printf("\nPress 3 to Display Circular Queue.");
	printf("\nPress 4 to Exit the Program.\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the Data You Want to EnQueue.");
			int a;
			scanf("%d",&a);
			EnQueue(a);
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
			printf("\nInvalid Choice.");
	}
}
	
	return 0;
}
