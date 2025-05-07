#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char doctorName[20];
    char patientName[20]; 
    char operation[25];
    int time; 
    char status[15];
}info_t;

int main(void){
    FILE *file = fopen("LG14_files/surgery.bin", "rb");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    fseek(file, sizeof(info_t), SEEK_END);
    int size = ftell(file) / sizeof(info_t);
    rewind(file);
    printf("There are %d surgery in the file\n",size);
    srand(time(NULL));
    int numOfDisp = rand() % (size) + 1;
    printf("%d surgery will be displayed\n", numOfDisp);
    printf("%-30s\t%-20s\t%-20s\t%-5s\t%-10s\n","DOCTOR","PATIENT","OPERATION","TIME", "STATUS");
    info_t info;
    for(int i = 0; i < numOfDisp; i++){
        fread(&info, sizeof(info), 1, file);
        printf("%-30s\t%-20s\t%-20s\t%-5d\t%-10s\n",info.doctorName, info.patientName, info.operation, info.time,info.status);
    }
}