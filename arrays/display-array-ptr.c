//Purpose: To display elements of an array using pointers.
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
        printf("\nThe Elements are: ");
        for (i=0;i<n;i++) {
            printf("%d\t",p[i]);
        }
    }
    else {
        printf("\nEnter a Valid Size.");
        goto start;
    }


    return 0;
}
