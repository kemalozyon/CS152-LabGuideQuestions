#include <stdio.h>
#include <string.h>


typedef struct{
    char doctorName[20];
    char patientName[20]; 
    char operation[25];
    int time; 
    char status[15];
}info_t;

int main(void){
    FILE *file = fopen("LG14_files/surgery.bin", "rb");
    FILE *out = fopen("output.bin","wb");
    if(file == NULL || out == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    fseek(file, sizeof(info_t), SEEK_END);
    int size = ftell(file) / sizeof(info_t);
    rewind(file);
    info_t info;
    for(int i = 0; i < size; i++){
        fread(&info, sizeof(info_t), 1, file);
        if(strcmp(info.status, "Finished") == 0){
            fwrite(&info, sizeof(info), 1, out);
        }
    }
    fclose(out);
    FILE *out2 = fopen("output.bin","rb");
    while (fread(&info, sizeof(info), 1, out2) == 1)
    {
        printf("%-30s\t%-20s\t%-20s\t%-5d\t%-10s\n",
            info.doctorName, 
            info.patientName, 
            info.operation, 
            info.time,
            info.status);
    }
}