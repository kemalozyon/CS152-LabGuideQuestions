#include <stdio.h>

int readFromFile(FILE *file, int id[], int scores[][4]);
void findTeamAvg(int scores[][4], int size, double avgArr[]);
void findGameAvg(int scores[][4], int size, double avgArr[]);
void display(int id[],double gameAvg[], double teamAvg[], int size);
#define MAX 40
int main(void){
    FILE *file = fopen("./LG01_files/dart.txt", "r");
    int id[MAX], scores[MAX][4]; 
    double avgTeamArr[MAX], avgGameArr[4];

    if(file == NULL){
        printf("File cannot be opened!");
        return 1;
    }
    int size = readFromFile(file, id, scores);
    findTeamAvg(scores, size, avgTeamArr);
    findGameAvg(scores, size, avgGameArr);
    display(id,avgGameArr,avgTeamArr, size);
}

int readFromFile(FILE *file, int id[], int scores[][4]){
    int i = 0;
    while(fscanf(file, "%d %d %d %d %d", &id[i], &scores[i][0], &scores[i][1], &scores[i][2], &scores[i][3]) != EOF){
        i++;
    }
    return i;
}

void findTeamAvg(int scores[][4], int size, double avgArr[]){
    double sum = 0;
    for (int r = 0; r < size; r++){
        for (int c = 0; c < 4; c++){
            sum += scores[r][c];
        }
        avgArr[r] = sum / 4.0;
        sum = 0;
    }
}

void findGameAvg(int scores[][4], int size, double avgArr[]){
    double sum = 0;
    for (int c = 0; c < 4; c++){
        for (int r = 0; r < size; r++){
            sum += scores[r][c];
        }
        avgArr[c] = sum / size;
        sum = 0;
    }
}

void display(int id[], double gameAvg[], double TeamAvg[], int size){
    printf("TeamNumber.     Avarage\n");
    for (int i = 0; i < size; i++){
        printf("%d \t %.2f\n", id[i], TeamAvg[i]);
    }
    for (int i = 0; i < 4; i++){
        printf("%d\t%.2f\n", i+1, gameAvg[i]);
    }
}