#include<stdio.h>
#include<stdlib.h>
struct student{
	int data;
	struct student *next;
};

struct student *HEAD;

void create_cll(int x){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	if(temp==NULL){
		printf("\nMemory Not Allocated!");
		return;
	}
	temp->data=x;
	
	if(HEAD==NULL){
		HEAD=temp;
		temp->next=HEAD;
		return;
	}
	
	else{
		temp->next=HEAD;
		struct student *ptr = HEAD;
		while(ptr->next!=HEAD){
			ptr = ptr->next;
		}
		ptr->next=temp;
	}
}


void display_cll(void){
	if(HEAD==NULL){
		printf("\nCicular Linked List Doesn't Exist.");
		return;
	}
	struct student *ptr=HEAD;
	do{
		printf("%d--->",ptr->data);
		ptr = ptr->next;
	}
	
	while(ptr!=HEAD);
}

void insert_at_begin(int x){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	if(temp==NULL){
		printf("\nMemory Not Allocated!");
		return;
	}
	temp->data=x;
	temp->next=HEAD;
	if(HEAD==NULL){
		HEAD=temp;
		return;
	}
	struct student *ptr=HEAD;
	while(ptr->next!=HEAD){
		ptr = ptr->next;
	}
	HEAD=temp;
	ptr->next=HEAD;
	
}
void insert_at_end(int x){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->data=x;
	if(HEAD==NULL){
		HEAD=temp;
		temp->next=temp;
		return;
	}
	temp->next=HEAD;
	struct student *ptr = HEAD;
	while(ptr->next!=HEAD){
		ptr = ptr->next;
	}
	ptr->next=temp;

}

void insert_at_pos(int x, int pos){
	if(HEAD==NULL || pos<0){
		
		printf("\nInvalid Position or Circular Linked List Doesn't Exist!");
		return;	
		}
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->data=x;
	struct student *ptr=HEAD;
	if(pos==0){
	   while(ptr->next!=HEAD)
	   ptr = ptr->next;
	   temp->next=HEAD;
	   HEAD=temp;
	   ptr->next=HEAD;
	   return;
	}
    int i;
	for(i=0;i<pos-1;i++){
	ptr = ptr->next;
	if(ptr==HEAD)
		break;
}

if(ptr->next==HEAD){
	ptr->next=temp;
	temp->next=HEAD;
	return;
}
if(ptr==HEAD){
	printf("\nPosition is too Large.");
	return;
}
	temp->next=ptr->next;
	ptr->next=temp;
	     
	}
	
void delete_at_begin(void){
	if(HEAD==NULL){
		printf("\nCircular Linked List Does Not Exist!");
		return;
	}
	//ptr is used for both traverse and de-allocation.
	struct student *ptr=HEAD;
	while(ptr->next!=HEAD)
	ptr = ptr->next;
	ptr->next=HEAD->next;
	ptr = HEAD;
	HEAD=HEAD->next;
	free(ptr);
}

delete_at_end(void){
	if(HEAD==NULL){
		printf("\nCircular Linked List Does Not Exist!");
	    return;
	}
	struct student *temp,*ptr=HEAD;
	while(ptr->next->next!=HEAD)
		ptr = ptr->next;
	temp = ptr->next;
	ptr->next=HEAD;
	free(temp);
	
}

void delete_at_pos(int pos){
	if(HEAD==NULL || pos<0){
		printf("\nInvalid Position or Cirular Linked List Doesn't Exist!'");
		return;
	}
	struct student *ptr=HEAD,*temp;
	if(pos==0){
		while(ptr->next!=HEAD)
		ptr = ptr->next;
		temp=HEAD;
		HEAD=HEAD->next;
		ptr->next=HEAD;
		free(temp);
		return;
	}
	int i;
	for(i=0;i<pos-1;i++){
		ptr = ptr->next;
		if(ptr->next==HEAD)
		break;
	}
	if(ptr->next==HEAD){
		printf("\nPosition is too Large.");
		return;
	}
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
}

int main(void){
	int choice;
	int x;
	while(1){
		printf("\nPress 1 to Create a Circular Linked List.");
		printf("\nPress 2 to Display a Circular Linked List.");
		printf("\nPress 3 to Insert a Node at the Begining of a Circular Linked List.");
		printf("\nPress 4 to Insert a Node at the End of a Circular Linked List.");
		printf("\nPress 5 to Insert a Node at a Position in a circular Linked List.");
		printf("\nPress 6 to Delete Node at the Begining of a circular linked list.");
		printf("\nPress 7 to Delete Node at the End of a circular linked list");
		printf("\nPress 8 to Delete Node at the Position in a circular Linked List.");
		scanf("%d",&choice);
		switch(choice){
		  case 1:
		  	printf("\nEnter the Data You Want to Insert: ");
		  	int x;
		  	scanf("%d",&x);
		  	create_cll(x);
		  	break;
		  case 2:
		  	display_cll();
		  	break;
		  case 3:
		  	printf("\nEnter the Data to Insert at the Begining: ");
		  	scanf("%d",&x);
		  	insert_at_begin(x);
		  	break;
		  case 4:
		  	printf("\nEnter the Data to Insert at the End: ");
		  	scanf("%d",&x);
		  	insert_at_end(x);
		  	break;
		  case 5:
		  	printf("\nEnter the Data You Want to Insert at Position: ");
		  	int b;
		  	scanf("%d",&x);
		  	printf("\nEnter the Position Where You Want to Insert: ");
		  	scanf("%d",&b);
		  	insert_at_pos(x,b);
		  	break;
		  case 6:
		  	delete_at_begin();
		  	break;
		  case 7:
		  	delete_at_end();
		  	break;
		  case 8:
		  	printf("\nEnter the Position Where You Want to Delete: ");
		  	int pos;
		  	scanf("%d",&pos);
		  	delete_at_pos(pos);
		  	break;
		  default:
		  	printf("\nInvalid Choice.\n");
		  }
	}
	return 0;
}
