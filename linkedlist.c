#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int i; //Loop Counter.
struct bca {
    int data;
    struct bca *next;
};
struct bca *HEAD=NULL;

void create_ll(int x) {
    struct bca *temp;
    temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    temp->next=NULL;
    if (HEAD==NULL) {
        HEAD=temp;
        return;
    }
    else {
        struct bca *ptr = HEAD;
        while (ptr->next!=NULL) {
            ptr = ptr->next;
        }
        ptr->next=temp;
    }
}
void display(void) {
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
    temp->next=HEAD;
    HEAD = temp;
}
void insert_at_end(int x) {
    struct bca *ptr=HEAD,*temp;
    temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    temp->next=NULL;
    if (ptr==NULL) {
        HEAD=temp;
        return;
    }
    while (ptr->next!=NULL) {
        ptr = ptr->next;
    }
    ptr->next=temp;

}
void insert_at_pos(int x,int y) {
	if(y<0){
		printf("\nInvalid Position.");
		return;
	}
	
    struct bca *temp = (struct bca *)malloc(sizeof(struct bca));
    temp->data=x;
    if(y==0){
		temp->next=HEAD;
		HEAD=temp;
		return;
	}
	struct bca *ptr=HEAD;
	for (i=0;i<y-1;i++) {
        ptr = ptr->next;
        if(ptr==NULL)
        break;
    }
    if(ptr==NULL){
		printf("\nPosition is too Large.");
		return;
	}
    if(ptr->next=NULL){
    	ptr->next=temp;
    	return;
}
    temp->next=ptr->next;
    ptr->next=temp;
}

void delete_at_begin(void) {
    if (HEAD==NULL) {
        printf("\nSingly Linked List Does Not Exit.");
        return;
    }
    struct bca *ptr=HEAD;
    HEAD = HEAD->next;
    free(ptr);

}
void delete_at_pos(int pos) {
	if(HEAD==NULL || pos<0){
		printf("\nInvalid Position/Empty Linked List.!");
		return;
	}
    struct bca *ptr=HEAD;
    if(pos==0){
    	HEAD=HEAD->next;
    	free(ptr);
    	return;
	}
	struct bca *temp;
    for (i=0;i<pos-1;i++) {
        ptr = ptr->next;
        if(ptr->next==NULL)
        break;
    }
    if(ptr->next==NULL){
    	printf("\nPosition is too Large!");
    	   return;
	}
 
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
}
void delete_at_end(void) {
    struct bca *ptr=HEAD,*temp;
    while (ptr->next->next!=NULL) {
        ptr=ptr->next;
    }
    temp = ptr->next;
    ptr->next=NULL;
    free(temp);
}

void reverse(void) {
   struct bca *curr,*next,*prev;
    prev = NULL;
    curr = HEAD;
    while (curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    HEAD=prev;
}

void search(int x) {
    int found=0;
    int count=0;
    struct bca *ptr;
    ptr = HEAD;
    while (ptr!=NULL) {
        count++;
        if (ptr->data==x) {
            found = 1;
            break;
        }
        ptr=ptr->next;
    }
    if (found!=0) {
        printf("\nFound Element %d at %d",x,count);
    }
    else
        printf("\nElement Not Found!");
}

void insert_multiple_nodes_at_begin(int n,int *ptr) {
    struct bca *temp[n];

    for (i=0;i<n;i++) {
        temp[i]=(struct bca *)malloc(sizeof(struct bca));
    }
    //Linking Nodes Together
    for (i=0;i<n;i++) {
        temp[i]->next=temp[i+1];
    }
    temp[n-1]->next=NULL;
   //Filling Data in each Node
   for (i=0;i<n;i++) {
      temp[i]->data=ptr[i];
   }
    if (HEAD==NULL) {
        HEAD=temp[0];
        return;
    }

    temp[n-1]->next=HEAD;
    HEAD=temp[0];

}

void insert_multiple_nodes_at_end(int n,int *p) {
    struct bca *ptr,*temp[n];
    ptr = HEAD;
    for (i=0;i<n;i++) {
       temp[i]=(struct bca *)malloc(sizeof(struct bca));

    }
    //Linking Nodes
    for (i=0;i<n;i++) {
        temp[i]->next=temp[i+1];
    }
    temp[n-1]->next=NULL;

    //Storing Data.
    for (i=0;i<n;i++) {
        temp[i]->data=p[i];
    }

    if (HEAD==NULL) {
        HEAD=temp[0];
        return;
    }

    while (ptr->next!=NULL) {
        ptr = ptr->next;
    }
    ptr->next=temp[0];

}


void insert_multiple_nodes_at_pos(int pos,int n,int *p) {
    struct bca *temp[n],*ptr;
    ptr = HEAD;
    for (i=0;i<n;i++) {
        temp[i]=(struct bca *)malloc(sizeof(struct bca));
    }
    if (temp[0]&&temp[n-1]==NULL) {
        printf("\nMemory Not Allocated!");
    }
    else {
        //Linking Nodes Together
        for (i=0;i<n;i++) {
            temp[i]->next=temp[i+1];
        }
        for (i=0;i<n;i++) {
            temp[i]->data=p[i];
        }
        for (i=0;i<pos-1;i++) {
            ptr = ptr->next;
        }
        temp[n-1]->next=ptr->next;
        ptr->next = temp[0];
    }
}

int main(void) {
    int choice,x,pos,y;
    int arr[MAX];
    while (1) {
        printf("\nEnter Your Choice: \n");
        printf("\nPress 1 to Create a Singly Linked List.");
        printf("\nPress 2 to Display a Singly Linked List");
        printf("\nPress 3 to Insert a Node at the Begining.");
        printf("\nPress 4 to Insert a Node at End.");
        printf("\nPress 5 to Insert a Node at Position.");
        printf("\nPress 6 to Delete a Node at the Begining.");
        printf("\nPress 7 to Delete a Node at the End.");
        printf("\nPress 8 to Delete a Node at Position.");
        printf("\nPress 9 to Search Data in a Singly Linked List.");
        printf("\nPress 10 to Reverse a Singly Linked List.");
        printf("\nPress 11 to Insert Multiple Nodes at the Begining.");
        printf("\nPress 12 to Insert Multiple Nodes at the End.");
        printf("\nPress 13 to Insert Multiple Nodes at Position.");
        printf("\nPress 14 to Exit the Program.\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("\nEnter the Data You Want to Insert: ");
                scanf("%d",&x);
                create_ll(x);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nEnter the Data You Want to Insert at the Begining:");
                scanf("%d",&x);
                insert_at_begin(x);
                break;

            case 4:
                printf("\nEnter the Data You Want to Insert at the End: ");
                scanf("%d",&x);
                insert_at_end(x);
                break;

            case 5:
                printf("\nEnter the Data You Want to Insert at Position: ");
                scanf("%d",&x);
                printf("\nEnter the Position Where You Want to Insert: ");
                scanf("%d",&pos);
                insert_at_pos(x,pos);
                break;

            case 6:
                delete_at_begin();
                break;

            case 7:
                delete_at_end();
                break;

            case 8:
                printf("\nEnter the Position Where You Want to Delete: ");
                scanf("%d",&pos);
                delete_at_pos(pos);
                break;

            case 9:
                printf("\nEnter Data You Want to Search in a Singly Linked List: ");
                scanf("%d",&x);
                search(x);
                break;

            case 10:
                reverse();
                break;

            case 11:
                printf("\nEnter the No. of Nodes You Want to Insert at the Begining: ");
                scanf("%d",&x);
                printf("\nEnter %d Data Parts: ",x);
                for (i=0;i<x;i++) {
                    scanf("%d",&arr[i]);
                }
                insert_multiple_nodes_at_begin(x,arr);
                break;

            case 12:
                printf("\nEnter the No. of Nodes You Want to Insert at End: ");
                scanf("%d",&x);
                printf("\nEnter %d Data Parts: ",x);
                for (i=0;i<x;i++) {
                    scanf("%d",&arr[i]);
                }
                insert_multiple_nodes_at_end(x,arr);
                break;

            case 13:
                printf("\nEnter the No. of Nodes You Want to Insert at Position: ");
                scanf("%d",&x);
                printf("\nEnter the Position Where You Want to Insert Multiple Nodes: ");
                scanf("%d",&pos);
                printf("\nEnter %d Data Parts: ",x);
                for (i=0;i<x;i++) {
                    scanf("%d",&arr[i]);
                }
                insert_multiple_nodes_at_pos(pos,x,arr);
                break;

            case 14:
                exit(1);


            default:
                printf("\nInvalid Choice!");





        }
    }


    return 0;
}
