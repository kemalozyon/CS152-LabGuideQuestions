//Libraries
#include <stdio.h>
#include <stdlib.h>

//Structures:
typedef struct 
{
    char exercise;
    int hour;
    int calori;
}Workout;
typedef struct 
{
    int id;
    char name[30];
    Workout workout;
}Member;

//Functions:
int menu();
void displayAll(Member *member, int size);
int searchById(Member *member, int size);
int searchById(Member *member, int size);


int main(void){
    int choice = menu();
    FILE *file = fopen("LG06_files/fitness.txt", "r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int numOfPeople;
    fscanf(file, "%d",&numOfPeople);
    Member *members = (Member *)malloc(numOfPeople * sizeof(Member));
    if(members == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }
    for(int i = 0; i < numOfPeople; i++)
    {
        fscanf(file, "%d %s %c %d %d", &(members + i)->id, (members + i)->name, &(members + i)->workout.exercise, &(members + i)->workout.hour, &(members + i)->workout.calori);
    }
    
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
            displayAll(members, numOfPeople);
            choice = menu();
            break;
        case 2:
            choice = menu();
            break;
        case 3:

            choice = menu();
            break;
        case 4:

            choice = menu();
            break;
        case 5:

            choice = menu();
            break;
        case 6:

            choice = menu();
            break;
        case 7:

            choice = menu();
            break;
        default:
            break;
        }
    }
    
}

int menu(){
    int choice;
    printf("FITNESS CENTER MENU -------------------\n");
    printf("1. Display All Members\n");
    printf("2. Search a Member by ID\n");
    printf("3. Display the high-calorie burners\n");
    printf("4. Find the most active member\n");
    printf("5. Find the most popular exercise type\n");
    printf("6. Display Average Weekly Workout Time\n");
    printf("7. Find Members Who Need Extra Workout Time\n");
    printf("8. EXIT\n");
    do{
        printf("Enter a number: ");
        scanf("%d",&choice);
        if (choice <= 0 || choice > 8){
            printf("Enter a validate number\n");
        }
    }while(choice <= 0 || choice > 8);
    return choice;
}

void displayAll(Member *member, int size){
    printf("ID\tName\t\tExercise Type\tWeekly Workout Time\tCalories Burned\n");
    printf("-----------------------------------------------------------------\n");
    
    for(int i = 0; i < size; i++) {
        printf("%d\t%-12s\t%c\t\t%d\t\t\t%d\n", 
               member[i].id, 
               member[i].name, 
               member[i].workout.exercise, 
               member[i].workout.hour, 
               member[i].workout.calori);
    }
}
