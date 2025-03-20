#include <stdio.h>
#include <math.h>

int main(void){
    FILE *file = fopen("./outputs/result.txt", "w");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }

    int arr[3][3];
    
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            *(*(arr + r) + c) = pow(2, (3 * r) + (c + 1));
        }
    }

    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            fprintf(file, "*(*(arr + %d) + %d)\t%d\t%p\n",r,c,*(*(arr + r) + c), *(arr + r) + c);
        }
    }
    fclose(file);
}