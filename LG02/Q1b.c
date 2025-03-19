#include <stdio.h>

int main(void){
    int mat[8] = { 6, 59, 81, 61, 1, 22, 41};
    printf("%p\n",mat);
    printf("%p\n", mat + 2);
    printf("%d\n",*(mat + 2));
    printf("%d\n", *mat + 4);
    printf("%p\n", mat + 5);
    printf("%d\n", *(mat + 7));
}