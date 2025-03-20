#include <stdio.h>

int main(void)
{
    double array[4][3] = {
        {42.90, 60.71, 57.30},
        {93.21, 82.97, 21.14},
        {25.91, 92.2, 30.17},
        {52.87, 75.84, 44.56}};

    // In order to reach the value of an element it needs to be used two derreference operator
    printf("%p\n", array);
    printf("%p\n", (array + 1));
    printf("%p\n", *(array + 1));
    printf("%p\n", (*(array) + 1));
    printf("%f\n", *(*(array) + 1));
    printf("%f\n", *(*(array + 1)));
    printf("%f\n", *(*(array) + 1) + 2);
    printf("%p\n", (*(array + 1) + 2));
    printf("%f\n", *(*(array + 1) + 2));
}