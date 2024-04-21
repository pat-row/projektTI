#include <iostream>
#include "array.h"

void enterDataIntoArray(int *array){
    for (int i = 0; i < SIZE; i++) {
        printf("*(array +%d) = ", i);
        scanf("%d", &*(array +i));
    }
}

void displayArray(int *array){

    for(int i=0; i<SIZE; i++){
        printf("*(array +%d) = %d\n", i, *(array
                                           +i));
    }
}

int findMaximumValue(int *array){
    int max = *array;
    for(int i=0; i<SIZE; i++){
        if(*(array +i) > max){
            max = *(array +i);
        }
    }
    return max;
}

int findMinimumValue(int *array){
    int min = *array;
    for(int i=0; i<SIZE; i++){
        if(*(array +i) < min){
            min = *(array +i);
        }
    }
    return min;
}

float calculateAverage(int *array){
    int sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += *(array +i);
    }
    float average = (float) sum / SIZE;
    return average;
}

void saveArrayToFile(int *array){
    FILE *fptr = NULL;
    fptr = fopen("plik.txt", "a");
    if(fptr == NULL){
        printf("blad otwierania pliku\n");
        exit(1);
    }

    for(int i=0; i<SIZE; ++i){
        fprintf(fptr,"array[%d] = %d\n",i, array[i]);
    }

    fclose(fptr);

}

void getArrayFromFile(int *array){
    FILE * fptr = NULL;
    char fileLine[100];
    fptr = fopen("plik.txt", "r");
    if (fptr != NULL)
    {
        while (!feof(fptr))
        {
            fgets(fileLine, 100, fptr);
            if (!feof(fptr))
            {
                puts(fileLine);
            }
        }
    }
    else
    {
        printf("\nBlad otwierania pliku\n");
    }

    fclose(fptr);

}