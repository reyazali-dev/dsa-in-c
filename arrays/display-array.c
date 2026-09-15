//Purpose: To display array and its reverse
//Author: Reyaz Ali

#include<stdio.h>   //This line includes the information about C Standard Library
int main(void) {     // Defining Main, it calls other functions to perform their jobs wheather you wrote it or it is a library function.
    //The Execution of Program Begins Here
    start:
    int n,i; //Declaring Varibles
    printf("\nEnter the Size of Array: ");
    scanf("%d",&n);
    if (n<=0) {
        printf("\nPlease Enter a Valid Size");
        goto start;
    }
    int arr[n];
    printf("\nNow Enter Elements: ");
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);  //Storing N-Elements in an array.
    }
    printf("\nThe Array is: ");
    for (i=0;i<n;i++) {
        printf("%d\t",arr[i]); //Displaying N-Elements from 0-n-1
    }

    printf("\nThe Reversed Array is: "); //Displaying Elements from n-1 to 0
    for (i=n-1;i>=0;i--) {
        printf("%d\t",arr[i]);
    }

    return 0;
}
