#include <stdio.h>

typedef struct 
{
    int id, 
        age;
}stu_t;

int main(void){
    stu_t student;
    student.age = 20;
    student.id = 22302474;
    FILE *file = fopen("student.bin", "wb");
    if(file == NULL){
        printf("File cannot be created");
        return 1;
    }
    fwrite(&student, sizeof(stu_t), 1, file);
}

void copyBinFile(FILE *file, FILE *file2){
    while(!feof(file)){
        
    }
}