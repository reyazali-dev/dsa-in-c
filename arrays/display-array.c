//Purpose: Reading Size of Array and Elements from User, Then Displaying Elements of an Array.
//Author: Reyaz Ali
//Date: Sun 13 Sep
//Time: 6:40
#include<stdio.h>   //This line includes the information about C Standard Library
int main(void) { // Defining Main, it calls other functions to perform their jobs wheather you wrote it or it is a library function.
    //The Execution of Program Begins Here
    int n,i; //Declaring Varibles
    printf("\nEnter the Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nNow Enter Elements: ");
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);  //Storing N-Elements in an array.
    }
    printf("\nThe Elements are: ");
    for (i=0;i<n;i++) {
        printf("%d\t",arr[i]); //Displaying N-Elements of an Array
    }

    return 0;
}