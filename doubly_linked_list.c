#include<stdio.h>
#include<stdlib.h>
int i;
struct bca {
    int data;
    struct bca *prev;
    struct bca *next;
};

struct bca *HEAD=NULL;

void create_dbll(int x) {
    struct bca *ptr,*temp;
    temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if (HEAD==NULL) {
        HEAD=temp;
        return;
    }
    else {
        ptr = HEAD;
        while (ptr->next!=NULL) {
            ptr = ptr->next;


        }
        ptr->next=temp;
        temp->prev=ptr;
    }
}


void display() {
    struct bca *ptr;
    ptr = HEAD;
    while (ptr!=NULL) {
        printf("%d----->",ptr->data);
        ptr = ptr->next;

    }
}

void insert_at_begin(int x) {
    struct bca *temp;
    temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    temp->prev=NULL;
    if(HEAD==NULL){
    	HEAD=temp;
    	return;
	}
    HEAD->prev=temp;
    temp->next=HEAD;
    HEAD=temp;

}


void insert_at_end(int x) {
    struct bca *ptr,*temp;
    temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    
    if(HEAD==NULL){
    	HEAD=temp;
    	return;
	}
	ptr = HEAD;
    while(ptr->next!=NULL){
    	ptr = ptr->next;
	}
	ptr->next=temp;
	temp->prev=ptr;
    

}

void insert_at_pos(int x, int pos){
	if(pos==0)
	return;
	struct bca *ptr, *temp;
	ptr = HEAD;
	for(i=0;i<pos-1;i++){
		ptr = ptr->next;
	}
	temp = (struct bca *)malloc(sizeof(struct bca));
	temp->data=x;
	temp->next=ptr->next;
	ptr->next=temp;
	temp->prev=ptr;
	temp->next->prev=temp;
	
}

void delete_at_begin(void){
	struct bca *ptr;
	ptr = HEAD;
	if(ptr==NULL){
		printf("\nDoubly Linked List Does Not Exit!");
		return;
	}
	HEAD=HEAD->next;
	HEAD->prev=NULL;
	free(ptr);
}

void delete_at_end(void){
	struct bca *ptr,*temp;
	ptr = HEAD;
	if(ptr==NULL){
		printf("\nDoubly Linked List Does Not Exit!");
		return;
	}
	while(ptr->next->next!=NULL){
		ptr = ptr->next;
	}
	temp=ptr->next;
	ptr->next=NULL;
	free(temp);
	
	
}

void delete_at_pos(int pos){
	if(pos==0 || pos==1)
	return;
	struct bca *ptr,*temp;
	ptr = HEAD;
	if(ptr==NULL){
		printf("\nDoubly Linked List Does Not Exit!");
		return;
	}
	for(i=0;i<pos-1;i++){
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next=temp->next;
	ptr->next->prev=ptr;
}

void count_nodes(void){
	int count;
	struct bca *ptr;
	ptr = HEAD;
	while(ptr!=NULL){
		count++;
		ptr = ptr->next;
	}
	printf("\nThe Count is: %d",count);
}

void search(int key){
	int found=-1;
	int count=0;
	struct bca *ptr;
	ptr = HEAD;
	if(ptr==NULL)
	return;
	while(ptr!=NULL){
		count++;
		if(key==ptr->data){
		found=1;
		break;
	}
		ptr = ptr->next;
	}
	
	if(found==1){
		printf("\nFound Data %d at node %d",key,count);
		return;
	}
	else
	printf("\nData Not Found!");
}

void display_reverse(void){
	struct bca *END = HEAD;
	while(END->next!=NULL){
		END = END->next;
	}
	struct bca *ptr;
	ptr = END;
	while(ptr!=NULL){
		printf("%d--->",ptr->data);
		ptr = ptr->prev;
	}
}


int main(void) {
	int x,y,z,pos;
while(1){

	printf("\nPress 1 to Create a Doubly Linked List.");
	printf("\nPress 2 to Display Nodes of a Doubly Linked List");
	printf("\nPress 3 to Insert Node at the Begining.");
	printf("\nPress 4 to Insert Node at the End.");
	printf("\nPress 5 to Insert Node at Position.");
	printf("\nPress 6 to Delete Node at the Begining.");
	printf("\nPress 7 to Delete Node at the End.");
	printf("\nPress 8 to Delete Node at Position.");
	printf("\nPress 9 to Count Number of Nodes.");
	printf("\nPress 10 to Search Data in a Linked List.");
	printf("\nPress 11 to Display its Reverse.");
	printf("\nPress 0 to Exit the Program.\n");
	
	scanf("%d",&x);
    switch(x){
    	case 1:
    		printf("\nEnter the Data You Want to Insert: ");
    		scanf("%d",&y);
    		create_dbll(y);
    		break;
    		
        case 2:
        	display();
        	break;
        	
        case 3:
        	printf("\nEnter the Data You Want to Insert at Begin: ");
    		scanf("%d",&y);
    		insert_at_begin(y);
    		break;
    		
    	case 4:
    		printf("\nEnter the Data You Want to Insert at End: ");
    		scanf("%d",&y);
    		insert_at_end(y);
    		break;
    		
    	case 5:
    		printf("\nEnter the Data You Want to Insert at Position: ");
    		scanf("%d",&y);
    		printf("\nEnter Position Where You Want to Insert %d",y);
    		scanf("%d",&pos);
    		insert_at_pos(y,pos);
    		break;
    		
    	case 6:
    		delete_at_begin();
    		break;
    	
    	case 7:
    		delete_at_end();
    		break;
    		
    	case 8:
    		printf("\nEnter the Postition Where You Want to Delete a Node: ");
    		scanf("%d",&pos);
    		delete_at_pos(pos);
    		break;
    		
    	case 9:
    		count_nodes();
    		break;
    		
    	case 10:
    		printf("\nEnter the Element You Want to Search: ");
    		scanf("%d",&y);
    		search(y);
    		
    	case 11:
    		display_reverse();
    		
    	case 0:
    		exit(1);
        	
        default:
		printf("\nInvalid Option!");	
	}
	
	
	 
}
	


    return 0;
}
