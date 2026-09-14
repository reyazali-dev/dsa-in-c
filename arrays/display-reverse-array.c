//Purpose: To display elements of an array in reverse order
//Author: Reyaz Ali

#include<stdio.h> //Includes information about c standard library (header files that contain function declarations and their definitions are linked by the linker after compilation)
int i=0; //Initializing i to Zero
int main(void) {    //It calls other functions to perform their jobs.
    start:
    int n;   //Variable Declaration
    printf("\nEnter the Size of Array: "); //Writing the Argument String to the Standard Output Stream or Console or Screen.
    scanf("%d",&n); //Reading Size from User through standard input stream then storing it in variable n.
    if (n>0) {
        int arr[n]; // It tells the compiler to allocate memory from data-section of sizeof(int)*n bytes.
        printf("\nNow Enter Elements: ");
        while (i<n) {    //This loop executes as long as the condition is true.
            scanf("%d",&arr[i]);  //i = 0, the condition is true then it read element, then increments i and condition is checked again.
            i++;
        }
        //Now i contains size of array
        printf("\nThe Elements are: ");
        while (i>0) {  //Here i = size of array, the condtion is true, it will print the last element arr[n-1], the decrements i and condition is checked again.
            printf("%d\t",arr[i-1]);
            i--;

        }
    }
    else {
        printf("\nEnter a Valid Size");
        goto start;
    }
    return 0;
}
