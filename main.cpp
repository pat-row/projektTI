#include <iostream>
#include "array.h"

void menu(void){
    printf("\n1. Enter the values into array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the maximum value\n");
    printf("4. Determine the minimum value\n");
    printf("5. Determine the average\n");
    printf("6. Save array to file\n");
    printf("7. Get array from file\n");
    printf("0. EXIT\n");
    printf(" Select an option\n");
}

int main() {

    int array[SIZE];
    int *temps;
    int i;
    temps = (int *) malloc( 10 * sizeof( int ) );
    int * randomNums;

    randomNums = (int *) malloc(SIZE * sizeof(int));

    for (i = 0; i < SIZE; i++)
    {
        randomNums[i] = (rand() % 500) + 1;
    }


    int option = 0;

    do {
        menu();
        scanf("%d",&option);

        switch(option){
            case 0:
                break;
            case 1:
                enterDataIntoArray(array);
                break;
            case 2:
                displayArray(array);
                break;
            case 3:
                printf("Maximum value = %d\n",findMaximumValue(array));
                break;
            case 4:
                printf("Minimum value = %d\n",findMinimumValue(array));
                break;
            case 5:
                printf("Average value = %f\n",calculateAverage(array));
                break;
            case 6:
                saveArrayToFile(array);
                break;
            case 7:
                getArrayFromFile(array);
                break;
            default:
                printf("Choose the right option\n");
        }

    }while(option!=0);

    return 0;
}
