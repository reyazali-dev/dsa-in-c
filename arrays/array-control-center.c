/**
 *@STATUS: INCOMPLETE
* @file c-array-control-center
 * @brief Console-based Centralized Array Control Center.
 *
 * @details A modular, menu-driven CLI architecture designed to manage, manipulate,
 *          and optimize 1D Variable Length Arrays (VLA), 2D multidimensional
 *          matrices, and heap-allocated Dynamic Arrays via memory reconfiguration
 *          mechanisms (malloc/realloc).
 *
 * @author Reyaz Ali (ریاض علی بٹ)
 * @location Baramulla, Jammu & Kashmir
 * @version 1.0.0
 * @date September 20, 2026
 *
*/

#include<stdio.h>  //These lines include header files that contains function declarations.
#include<stdlib.h>
#define MAX 100000000
#define ROW 10000
#define COL 10000

//Global Variables
int arr[MAX]; //Variable Length Array
int array[ROW][COL]; //2D Variable Length Array
int global_size; //This enables communication between functions.
int *p;
int row,col;
int i,j; //Loop Counter
void create_array(int arr[]) {
    printf("\nEnter the Size of Array: ");
    scanf("%d",&global_size);
    if (global_size>MAX||global_size<=0) {
        printf("\nInvalid Size");
        return;
    }
    else {
        printf("\nNow Enter %d Elements: \n",global_size);
        for (i=0;i<global_size;i++)
            scanf("%d",&p[i]);
    }
    printf("======================================");
    printf("\nWhat you want to do with this Array:\n");
    printf("======================================\n");
    printf("\nPress 1 to Display its Elements: ");
    printf("\nPress 2 to Reverse this Array: ");
    printf("\nPress 3 to Find Largest and Second Largest Element: ");
    printf("\nPress 4 to Search an Element in this Array: ");
    printf("\nPress 5 to Insert an Element: ");
    printf("\nPress 6 to Delete an Element: ");
    printf("\nPress 7 to Find Frequency of an Element: ");
    printf("\nPress 8 to Find the Sum of Elements: ");
    printf("\nPress 9 to Find the Average of Elements: ");
    printf("\nPress 10 to Go Back to Main Menu: ");
}

void display_array(int *p) {
    for (i=0;i<global_size;i++)
        printf("%d\t",p[i]);
}

void reverse_array(int *p) {
    int low=0,high=global_size-1,temp;
    while (low<high) {
        temp = p[low];
        p[low]=p[high];
        p[high]=temp;
        low++;
        high--;
    }

    printf("The Reverse is: ");
    display_array(arr);
}

void largest_secondlargest(int arr[]) {
    int largest = arr[0];
    int second_largest;
    for (i=0;i<global_size;i++) {
        if (arr[i]>largest) {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i]>second_largest&&arr[i]<largest)
            second_largest = arr[i];
        else if (arr[i]==largest)
            largest = arr[i];
            second_largest = largest;
    }
    printf("\nThe Largest Element is: %d",largest);
    printf("\nThe Second Largest Element is: %d",second_largest);

}

void search_array(int arr[]) {
    int key,found=-1;
    printf("\nEnter the Element You Want to Search: ");
    scanf("%d",&key);
    for (i=0;i<global_size;i++) {
        if (key==p[i]) {
            found = i+1;
            break;
        }
    }
        if (found!=-1)
            printf("\nElement %d Found at Postion %d",key,found);
        else
            printf("\nElement %d Not Found!",key);
}

void insert_array(int ar[]) {
    main_menu:
    int index;
    int element;
    printf("\nEnter the Index Where You Want to Insert an Element: ");
    scanf("%d",&index);
    if (index<0) {
        printf("\nEnter a Valid Index");
        goto main_menu;
    }
    printf("\nEnter the Element You Want to Insert: ");
    scanf("%d",&element);
    for (i=global_size;i>index;i--) {
        p[i]=p[i-1];
    }
    p[index]=element;
    printf("\nThe Current Array is: ");
    global_size++;
    display_array(p);
}

void delete_array(int arr[]) {
    int index;
    printf("\nEnter the Index Where You want to delete an element: ");
    scanf("%d",&index);
    if (index<0) {
        printf("\nInvalid Index!");
        return;
    }
    for (i=index;i<global_size;i++) { //If we write global_size-1 the last element will not be overwritten
        p[i] = p[i+1];
    }
    global_size--;
    printf("\nThe Current Array is: ");
    display_array(arr);
}
void frequency(int *p) {
    int frequency = 0,element;
    printf("\nEnter the Element Whose Frequency You Want to Find: ");
    scanf("%d",&element);
    for (i=0;i<global_size;i++) {
        if (p[i]==element)
            frequency++;
    }
    printf("\nThe Frequency of %d is: %d",element,frequency);
}
void sum_array(int *p) {
    int sum = 0;
    for (i=0;i<global_size;i++) {
        sum = sum+p[i];
    }
    printf("\nThe Sum of Elements is: %d",sum);
}

void average_array(int *p) {
    int sum = 0;
    int count = 0;
    double average;
    for (i=0;i<global_size;i++) {
        count++;
        sum = sum+p[i];
    }
    average = sum/count;
    printf("\nThe Average of Elements is: %.3f",average);
}
//Creating 2D Array Function
void create_2d_array(int array[ROW][COL]) {
    printf("\nEnter the No. Of Rows: ");
    scanf("%d",&row);
    if (row<=0)
        return;
    printf("\nEnter the No. Of Columns: ");
    scanf("%d",&col);
    if (col<=0)
        return;
    global_size = row*col;
    printf("\nNow Enter %d Elements:\n",row*col);
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            scanf("%d",&array[i][j]);
        }
    }
    printf("======================================");
    printf("\nWhat you want to do with this 2-D Array:\n");
    printf("======================================\n");
    printf("\nPress 1 to Display its Elements: ");
    printf("\nPress 2 to Search an Element: ");
    printf("\nPress 3 to Find Sum of Elements: ");
    printf("\nPress 4 to Find the Average of Elements: ");
    printf("\nPress 5 to Find the Frequency of an Element: \n");
    printf("\nPress 10 to Go Back to Main-Menu: ");

}

//Displaying 2D Array Function
void display_2d_array(int *p) {
    printf("\nThe 2D Array is: \n");
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
}

//Searching An Element in 2D Array Function
void search_2d_array(int *p) {
    int s;
    int found = -1;
    printf("\nEnter the Element You Want To Search: ");
    scanf("%d",&s);
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            if (s==array[i][j])
                found = i;
        }
    }
    if (found!=-1) {
        printf("Found Element %d at Row: %d , Column: %d",s,i,j);
    }
    else
        printf("\nElement %d Not Found!",s);
}
//Defining a function that finds sum of elements
void sum_2d_array(int *p) {
    int sum=0;
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            sum = sum+array[i][j];
        }

    }
    printf("\nThe Sum of Elements is: %d",sum);
}

//Defining a function that finds average of elements.
void average_2d_array(int *p) {
    int sum=0;
    int count=row*col;
    float average;
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            sum = sum + array[i][j];
        }

    }
    average = sum/count;
    printf("\nThe Average is: %.3f",average);
}
//Defining a function that finds frequency of an element.
void frequency_2d_array(int *p) {
    int element;
    int frequency = 0;
    printf("\nEnter the Element Whose Frequency you want to find: ");
    scanf("%d",&element);
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            if (element==array[i][j])
                frequency++;
        }
    }
    printf("\nThe Frequency of %d is %d",element,frequency);
}

//Defining a Dynamic Array Function
void create_dynamic_array(void) {
    printf("\nEnter the No. of Elements: \n");
    scanf("%d",&global_size);
    if (global_size<=0 || global_size>MAX) {
        printf("\nInvalid Size!");
        return;
    }
    p = (int *)malloc(global_size*sizeof(int));
    if (p==NULL)
        printf("\nNo Memory Allocated!");
    else{
        printf("\nMemory Allocated Sucessfully for Dynamic Array!\n");
        printf("\nNow Enter %d Elements: \n",global_size);
        for (i=0;i<global_size;i++)
            scanf("%d",&p[i]);
    }
    printf("======================================");
    printf("\nWhat you want to do with Dynamic Array:\n");
    printf("======================================\n");
    printf("\nPress 0 to Re-Allocate Memory: ");
    printf("\nPress 1 to Display its Elements: ");
    printf("\nPress 2 to Reverse this Array: ");
    printf("\nPress 3 to Find Largest and Second Largest Element: ");
    printf("\nPress 4 to Search an Element in this Array: ");
    printf("\nPress 5 to Insert an Element: ");
    printf("\nPress 6 to Delete an Element: ");
    printf("\nPress 7 to Find Frequency of an Element: ");
    printf("\nPress 8 to Find the Sum of Elements: ");
    printf("\nPress 9 to Find the Average of Elements: ");
    printf("\nPress 10 to Go Back to Main Menu: \n");
    //free(p);               If we release memory then the previous elements will be lost.
    }

void realloc_array(int *p) {
    int new_size;
    char r;
    int *x;
    printf("\nEnter the New Size of Array: ");
    scanf("%d",&new_size);
    if (new_size<=0 && new_size>MAX) {
        printf("\nInvalid New Size!");
        return;
    }
    x = realloc(p,new_size*sizeof(int));    //Re-Allocating Memory.
    if (x==NULL)
        printf("\nNo Enough Memory for Reallocation!");
    else {
        p = x;
        printf("\nMemory Re-Allocated Sucessfully!");
        printf("\nNow Enter New Elements: \n");
        for (i=global_size;i<new_size;i++) {
            scanf("%d",&p[i]);
        }
        //After Storing New Elements Lets Update Global Variable
        global_size = new_size;
        printf("\nThe New Array is: ");
        display_array(p);
    }
    printf("\nDo You Want to Erase All Data from Heap: (Y/N): ");
    scanf("%s",&r);
    if (r=='Y') {
        free(p);
        printf("\nData Erased Sucessfully!");
    }
    else if (r=='N')
        printf("\nData is Saved in Heap!");
    else
        return;
}

//Defining a function that creates a 2D Dynamic Array
void create_2d_dynamic_array(void) {
    printf("\nEnter the No. of Rows: ");
    scanf("%d",&row);
    if (row<=0)
        return;
    printf("\nEnter the No. of Columns: ");
    scanf("%d",&col);
    if (col<=0)
        return;
    global_size = row*col;
    int *ptr[global_size];
    if (global_size<=0||global_size>MAX)
        return;
    for (i=0;i<col;i++) {
        ptr[i] = (int *)malloc(row*sizeof(int));
    }
    if (ptr==NULL)
        printf("\nNo Memory Allocated!");
    else
        printf("\nMemory Allocated Successfully for 2D Array!");
    p = ptr;
    printf("\nNow Enter %d Elements: \n",row*col);
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            scanf("%d",&ptr[i]);
        }
    }
    p = ptr[0];
    printf("======================================");
    printf("\nWhat you want to do with this 2-D Array:\n");
    printf("======================================\n");
    printf("\nPress 1 to Display its Elements: ");
    printf("\nPress 2 to Search an Element: ");
    printf("\nPress 3 to Find Sum of Elements: ");
    printf("\nPress 4 to Find the Average of Elements: ");
    printf("\nPress 5 to Find the Frequency of an Element: ");
    printf("\nPress 10 to Go Back to Main-Menu: \n");

}
int main(void) {
    int a,b;
    main_menu:
    printf("===========");
    printf("\nMAIN MENU:\n");
    printf("===========\n");
    printf("\nPress 1 to Create a One-Dimensional Variable Length Array(VLA):");
    printf("\nPress 2 to Create a Two-Dimension Variable Length Array(VLA):");
    printf("\nPress 3 to Create a One-Dimensional Dynamic Array:");
    printf("\nPress 4 to Create a Two-Dimensional Dynamic Array:\n");
    scanf("%d",&a);
    if (a==1){
        p = arr;
        create_array(arr);
        scanf("%d",&b);
        switch (b) {
            case 1:
                display_array(p);break;
            case 2:
                reverse_array(p);break;
            case 3:
                largest_secondlargest(p);break;
            case 4:
                search_array(p);break;
            case 5:
                insert_array(p);break;
            case 6:
                delete_array(p);break;
            case 7:
                frequency(p);break;
            case 8:
                sum_array(p);break;
            case 9:
                average_array(p);break;
            case 10:
                goto main_menu;break;
            default:
                exit(1);
        }

    }

    else if (a==2) {
        p = &array[0][0];
        create_2d_array(array);

        scanf("%d",&b);
        switch (b) {
           case 1:
                display_2d_array(p);break;
            case 2:
                search_2d_array(p);break;
            case 3:
                sum_2d_array(p);break;
            case 4:
                average_2d_array(p);break;
            case 5:
                frequency_2d_array(p);break;
            case 10:
                goto main_menu;

            default:
                exit(1);

       }



    }


    else if (a==3) {
        create_dynamic_array();
        scanf("%d",&b);
        switch (b) {
            case 0:
                realloc_array(p);break;
            case 1:
                display_array(p);break;
            case 2:
                reverse_array(p);break;
            case 3:
                largest_secondlargest(p);break;
            case 4:
                search_array(p);break;
            case 5:
                insert_array(p);break;
            case 6:
                delete_array(p);break;
            case 7:
                frequency(p);break;
            case 8:
                sum_array(p);break;
            case 9:
                average_array(p);break;
            case 10:
                goto main_menu;break;
            default:
                exit(1);
        }
    }
    else if (a==4)
        create_2d_dynamic_array();
        scanf("%d",&b);
        switch (b) {
            case 1:
                display_2d_array(p);break;
            case 2:
                search_2d_array(p);break;
            case 3:
                sum_2d_array(p);break;
            case 4:
                average_2d_array(p);break;
            case 5:
                frequency_2d_array(p);break;
            case 10:
                goto main_menu;

            default:
                exit(1);

        }




    return 0;
}