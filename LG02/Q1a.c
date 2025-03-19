#include <stdio.h>

int main(void){
    int x = 34, y;  
    int *ptrA = &x;  
    int *ptrB;  
    *ptrA = x + 2;  
    y = *ptrA + 5; 
    ptrB = ptrA; 
    *ptrA = x + y;  

    printf("%p\n",&x);
    printf("%p\n",&y);
    printf("%p\n",ptrA);
    printf("%d\n",*ptrA);
    printf("%d\n",x);
    printf("%p\n",ptrB);
    printf("%d\n",*ptrB);
    printf("%p\n",(ptrA + 3));
    printf("%d\n", (*ptrA + 3));
}