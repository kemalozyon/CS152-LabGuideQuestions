#include <stdio.h>
#define MAX 300 //Array will get Maximum 300 

int fillArray(int arr[]);
int isPrime(int number);
int isPerfect(int number);

int main(void){
    int arr[MAX], countPerfect = 0, countPrime = 0;
    int size = fillArray(arr);
    for(int i = 0; i < size; i++){
        if(isPerfect(arr[i])){
            countPerfect++;
        }
        if(isPrime(arr[i])){
            countPrime++;
        }
    }
    printf("\n\nThere are %d prime number\nThere are %d perfect number\n",countPrime,countPerfect);

}

int fillArray(int arr[]){ // It will return the actual size of array
    int number, index = 0;
    do{
        printf("Enter a positive number: ");
        scanf("%d", &number);
        if(number > 0){
            arr[index] = number;
            index++;
        }
    }while(number > 0);
    return index;
}

int isPrime(int number){ // It won't be the efficinet method to check wheter a number is prime or not.
    if (number == 1)
        return 0;
        
    for(int i = 2; i < number; i++){
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isPerfect(int number){
    int sum = 0;
    for(int i = 1; i < number; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    if(sum == number){
        return 1;
    }
    return 0;
}