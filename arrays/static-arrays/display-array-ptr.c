//Purpose: To display array and its reverse using pointers.
//Author: Reyaz Ali

#include<stdio.h>
int main(void) {
    start:
    int n,i;
    int *p; //Pointer to an integer.
    printf("\nEnter the Size of Array: ");
    scanf("%d",&n);
    if (n>0) {
        int arr[n];
        p=arr; // p stores base address of the array
        printf("\nNow Enter Elements: ");
        for (i=0;i<n;i++) {
            scanf("%d",&p[i]);
        }
        printf("\nThe Array is: ");
        for (i=0;i<n;i++) {
            printf("%d\t",p[i]);     //Displaying elements from 0-n-1 using pointers
        }
        printf("\nThe Reversed Array is: ");
        for (i=n-1;i>=0;i--) {
            printf("%d\t",p[i]);    //Displaying elements from n-1-0 using pointers
        }
    }
    else {
        printf("\nEnter a Valid Size.");
        goto start;                     //Unconditional jump to start
    }


    return 0;
}
