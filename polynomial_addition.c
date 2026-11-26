#include<stdio.h>
#include<stdlib.h>

struct poly{
	int coff;
	int exp;
	struct poly *next;
};

struct poly *p1=NULL,*p2=NULL,*result;

struct poly *insert(struct poly *p, int c, int e){
	struct poly *temp,*ptr=p;
	temp=(struct poly *)malloc(sizeof(struct poly));
	temp->coff=c;
	temp->exp=e;
	temp->next=NULL;
	if(p==NULL){
		return temp;
	}
		while(ptr->next!=NULL)
			ptr = ptr->next;
			ptr->next=temp;
	return p;
}

void display(struct poly *p){
	struct poly *ptr = p;
	if(ptr==NULL){
		printf("\nEmpty Linked List!");
		return;
	}
	else{
		while(ptr!=NULL){
			printf("%dx^%d",ptr->coff,ptr->exp);
			if(ptr->next!=NULL){
				printf("+");
			}
			ptr = ptr->next;
		}
	}
	
}

void add(struct poly *p1, struct poly *p2){
	while(p1!=NULL && p2!=NULL){
		if(p1->exp==p2->exp){
			int co = p1->coff+p2->coff;
			result = insert(result,co,p1->exp);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->exp>p2->exp){
			result = insert(result,p1->coff,p1->exp);
			p1=p1->next;
		}
		else{
		    result = insert(result,p2->coff,p2->exp);
			p2 = p2->next;
		}
	}
	while(p1!=NULL){
		insert(result,p1->coff,p1->exp);
		p1 = p1->next;
	}
	
	while(p2!=NULL){
		insert(result,p2->coff,p2->exp);
		p2 = p2->next;
	
	}
}

int main(void){
int choice;
int c,e;
while(1){
	printf("\nPress 1 to Insert in P1.");
	printf("\nPress 2 to Insert in P2");
	printf("\nPress 3 to Add Them.");
	printf("\nPress 4 to Display Result Polynomial.");
	printf("\nPress 5 to Exit.\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter Cofficient and Exponent: ");
			scanf("%d%d",&c,&e);
		  p1 = 	insert(p1,c,e);
			break;
			
		case 2: 
		printf("Enter Cofficient and Exponent: ");
			scanf("%d%d",&c,&e);
		p2 = insert(p2,c,e);
			break;
		case 3:
			add(p1,p2);
			break;
		case 4:
			display(result);
			break;
		case 5:
			exit(1);
		default:
			printf("\nInvalid Choice!");
	}
}	

	
	return 0;
}
