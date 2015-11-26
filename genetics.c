/*
Name: Elvin Abraham Garcia
Class: COP3502C
Section: 002
Summary: This program is used to convert a genetic sequence (consisting of A,C,G, and/or T), into
        a base-10 number, and vice versa. The first input specifies how many N sequences there are to
        convert. The following N lines will be filled with the aforementioned genetic sequences or
        base-10 numbers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void determineScenario(int numCases); //Reads in each test case (of up to LENGTH characters), and determines which of the two functions below are used.
void NUMtoDNA(int nums); //Convert number into DNA code value
void DNAtoNUM(char* letters); //"Encrypt" DNA code value into numbers
int findArrayLength(char* array); // Finds the Length of the array. NUMtoDNA: to specify length of temporary array to swap ints for correct decryption order. DNAtoNUM: setting highest power.
void printSequence(int printWhich, int sum, char* output, int arrayLength);

#define LENGTH 15

int sequenceNUM = 1;

int main(){

    int cases;

    scanf("%d",&cases);
    determineScenario(cases);

    //system("pause");
    return 0;
};

void determineScenario(int numCases){

    int i;
    int atoiVAL;
    char input[LENGTH];


    for(i=0;i<numCases;i++){
       // printf("LOOP: %d\n",i);
        memset(&input, 0, sizeof(input));
        scanf("%s",input);
        atoiVAL = atoi(input);
        if(atoiVAL !=0){
            NUMtoDNA(atoiVAL);
        }
        else if(atoiVAL == 0){
            DNAtoNUM(input);
        }
    }

}

void NUMtoDNA(int nums){

    int division = nums;
    int remainder;
    int arrayLength;
    char sequence[LENGTH];
    int i = 0;
    int k = 0;
    int j;

    //printf("Sequence before memset: %s\n", sequence);
    memset(&sequence, 0, sizeof(sequence));
    //printf("Sequence after memset: %s\n", sequence);

    //printf("NUM to DNA (nums value): %d\n", nums);
    while(division > 0){
        remainder = division%4;
        division = division/4;
        sequence[i] = remainder + '0';
        //printf("Division: %d\tRemainder: %d\t Sequence at i: %c\t Sequence: %s\n", division, remainder, sequence[i], sequence);
        i++;
    }

    arrayLength = findArrayLength(sequence);
    char sequenceCoded[arrayLength];
    //printf("Sequence Length: %d\n", arrayLength);

    for(j=arrayLength-1;j>=0;j--){
        //printf("K: %d\n", k);
        if(sequence[j] == '0') {
            sequenceCoded[k] = 'A';
            //printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '1') {
            sequenceCoded[k] = 'C';
            //printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '2') {
            sequenceCoded[k] = 'G';
            //printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '3') {
            sequenceCoded[k] = 'T';
            //printf("HIT\n");
            k++;
        }
    }

    //printf("Coded Sequence: %s (FINAL DIGIT MOST LIKELY TRASH)\n", sequenceCoded); //ignore any ending characters that aren't 'C','A','G', or 'T', remaining trash characters that don't get printed.

    printSequence(0, 0, sequenceCoded, arrayLength);

}

void DNAtoNUM(char* letters){

    int i;
    int sum = 0;
    int arrayLength = findArrayLength(letters);
    int exponent = arrayLength -1;

    //printf("DNA to NUM (letters value): %s\n", letters);
    //printf("Array Length: %d\n", arrayLength);

    for(i=0;i<arrayLength;i++){
        if(letters[0] == 'A'){
            printf("LEADING A ENTERED, OUTSIDE OF PROGRAM SPECIFICATIONS, SKIPPING THIS STRING\n");
            return;
        }
        else if(letters[i] == 'A'){
            //printf("HIT A\n");
            sum = sum + (0 * pow(4, exponent));
            exponent--;
        }
        else if(letters[i] == 'C'){
            //printf("HIT C\n");
            sum = sum + (1 * pow(4, exponent));
            exponent--;
        }
        else if(letters[i] == 'G'){
            //printf("HIT G\n");
            sum = sum + (2 * pow(4, exponent));
            exponent--;
        }
        else if(letters[i] == 'T'){
            //printf("HIT T\n");
            sum = sum + (3 * pow(4, exponent));
            exponent--;
        }
    }

    //printf("'Encrypted' Sequence: %d\n", sum);
    printSequence(1, sum," ", arrayLength);

}

int findArrayLength(char* array){

    int count = 0;
    while(array[count]){
        count++;
    }
    return count;

}

void printSequence(int printWhich, int sum, char* output, int arrayLength){

    int i;

    if(printWhich == 0) {
        printf("Sequence #%d: ", sequenceNUM);
        sequenceNUM++;
        for (i = 0; i < arrayLength; i++) {
            printf("%c", output[i]);
        }
        printf("\n");
    }
    else if(printWhich == 1){
        printf("Sequence #%d: %d\n", sequenceNUM, sum);
        sequenceNUM++;
    }

}