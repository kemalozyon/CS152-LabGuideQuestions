#include <stdio.h>

void swap(int *x, int *y){ //Call by reference. It takes two argument as address. 
    int temp = *x; // We assign the value of where the address x points to.
    *x = *y; // we assign the value of y to the location of x.
    // * -> it stands for dereferencing it used to reach the value of an address.
    *y = temp;
}

int main(void){
    int a, b;
    do{
        printf("Enter first value: ");
        scanf("%d",&a);
        if(a < 0){
            printf("First number must be poistive\n");
        }
    }while(a < 0);
    do {
        printf("Enter second value");
        scanf("%d",&b);
        if(b < 0){
            printf("The second number must be positive\n");
        }
    }while (b < 0);

    printf("Before swap: %d %d\n",a,b);
    swap(&a,&b);
    printf("After swap: %d %d\n",a,b);

    return 0;    

}