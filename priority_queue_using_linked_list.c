#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int data;
	int pri;
	struct Queue *next;
};

struct Queue *front=NULL,*rear=NULL;

void EnQueue(int x, int p){
	struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
	temp->data=x;
	temp->pri=p;
	temp->next=NULL;
	if(front==NULL){
		front=rear=temp;
		printf("\nPushed Item: %d with Priority: %d",rear->data,rear->pri);
		return;
	}
	rear->next=temp;
	rear=temp;
	printf("\nPushed Item: %d with Priority: %d",rear->data,rear->pri);
}

void DeQueue(void){
	if(front==NULL){
		printf("\nQueue Underflow.");
		return;
	}
	struct Queue *ptr=front,*temp = front;
	if(front==rear){
		front=rear=NULL;
		printf("\nDeQueued Item: %d with Priority: %d",ptr->data,ptr->pri);
		free(temp);
		return;
	}
	while(ptr!=NULL){
		if(temp->pri<ptr->pri){
			temp=ptr;
		}
		ptr = ptr->next;
	}
	if(temp==front){
		front=front->next;
		printf("\nDeQueued Item: %d with Priority: %d",temp->data,temp->pri);
		free(temp);
		return;
	}
	
	
	else if(temp==rear){
		ptr = front;
		while(ptr->next!=temp)
		ptr = ptr->next;
		ptr->next=NULL;
		rear=ptr;
		printf("\nDeQueued Item: %d with Priority: %d",temp->data,temp->pri);
		free(temp);
		return;
	}
	ptr = front;
	while(ptr->next!=temp)
	ptr = ptr->next;
	ptr->next=temp->next;
	printf("\nDeQueued Item: %d with Priority: %d",temp->data,temp->pri);
	free(temp);
}
void Display(void){
	if(front==NULL){
		printf("\nPriority Queue is Empty.");
		return;
	}
	struct Queue *ptr = front;
	printf("\nData   Priority");
	while(ptr!=NULL){
		printf("%d\t\t%d",ptr->data,ptr->pri);
		ptr = ptr->next;
	}
}	

int main(void){
	printf("\nPriority Queue Using Linked List.\n");
		while(1){
			printf("\nPress 1 to EnQueue.");
			printf("\nPress 2 to DeQueue.");
			printf("\nPress 3 to Display Priority Queue.");
			printf("\nPress 4 to Exit the Program.\n");
			int choice;
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("\nEnter the Data You Want to EnQueue: ");
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
					Display();
					break;
				case 4:
					exit(1);
			        break;
			    default:
			    	printf("\nInvalid Choice!");
			}
		}
		return 0;
	}

