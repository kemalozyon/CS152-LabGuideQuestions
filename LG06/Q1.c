#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SINGLE 1000
#define TWIN 2500
#define DOUBLE 3500

typedef struct 
{   
    int roomNumber;
    char roomInfo;
}room_info;

typedef struct 
{
    char name[50];
    int birthYear;
    int day;
    room_info room;
    double payment;
}Customer_info;

void readFromFile(FILE *file, Customer_info *customer, int random);
void displayAll(Customer_info *customer, int size);
double calculateTotalEarnings(Customer_info *customer, int random);
int searchForMaxPay(Customer_info *customer, int random);
int main(void){
    srand(time(NULL));
    FILE *file = fopen("LG06_files/customers.txt", "r");
    if(file == NULL){
        printf("File cannot opened!\n");
        return 1;
    }
    int random = rand() % 16 + 5, maxIndex;
    Customer_info *customer = (Customer_info *)malloc(random * sizeof(Customer_info));
    readFromFile(file, customer, random);
    displayAll(customer, random);
    printf("Total Earnings of the hotel : %.2f\n", calculateTotalEarnings(customer, random));
    maxIndex = searchForMaxPay(customer, random);
    printf("The Customer having maximum payment for accommodation: %s with the price %.2f TL\n", (customer + maxIndex)->name,(customer + maxIndex)->payment);
    fclose(file);
}
void readFromFile(FILE *file, Customer_info *customer, int random){
    int i;
    printf("%d customer info will be read!\n",random);
    for(int i = 0; i < random; i++){
        fscanf(file,"%s %d %d %d %c", (customer + i)->name, &(customer + i)->birthYear, &(customer + i)->day, &(customer + i)->room.roomNumber, &(customer + i)->room.roomInfo);
        switch ((customer + i)->room.roomInfo)
        {
        case 'S':
            (customer + i)->payment = (customer + i)->day * SINGLE;
            break;
        case 'T':
            (customer + i)->payment = (customer + i)->day * TWIN;
            break;
        case 'D':
            (customer + i)->payment = (customer + i)->day * DOUBLE;
            break;
        default:
            break;
        }
    }
}
void displayAll(Customer_info *customer, int size){
    for(int i = 0; i < size; i++){
        printf("%d. Name: %-20s\tBirth Year: %d\tDay: %d\tRoom Number: %d\tRoom Info: %c\tPayment: %.2f\n", 
            i+1, (customer + i)->name, (customer + i)->birthYear, (customer + i)->day, 
            (customer + i)->room.roomNumber, (customer + i)->room.roomInfo, (customer + i)->payment);
    }
}

double calculateTotalEarnings(Customer_info *customer, int random){
    double sum = 0;
    for(int i = 0; i < random; i++){
        sum += (customer + i)->payment;
    }
    return sum;
}

int searchForMaxPay(Customer_info *customer, int random){
    int max = customer->payment;
    int index = 0;
    for(int i = 1; i < random; i++){
        if((customer + i)->payment > max){
            max = (customer + i)->payment;
            index = i;
        }
    }
    return index;
}