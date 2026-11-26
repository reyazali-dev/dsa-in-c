//Queue Implementation using Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

void EnQueue(int x) {
    struct Queue *temp;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
	if (temp==NULL) {
		printf("\nNo Enough Memory!");
		return;
	}
    temp->data=x;
    temp->next=NULL;
  if (rear==NULL) {
	  rear=front=temp;
  	  printf("\nQueued Item: %d",rear->data);
  	  return;
  }
        rear->next=temp;
        rear=temp;
    	printf("\nQueued Item: %d",rear->data);
}

void DeQueue(void) {
    struct Queue *ptr=front;
    if (front==NULL) {
        printf("\nQueue Underflow!");
        return;
    }
    else if (front==rear) {
        printf("\nDeQueued Item: %d",ptr->data);
        front=rear=NULL;
        free(ptr);
    }
   else {
       front=front->next;
       printf("\nDeQueued Item: %d",ptr->data);
       free(ptr);
   }
}

void display(void) {
	if (front==NULL) {
		printf("\nQueue is Empty!");
		return;
	}
	struct Queue *ptr = front;
	while (ptr!=NULL) {
		printf("%d\t",ptr->data);
		ptr = ptr->next;
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



