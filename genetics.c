#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void determineScenario(int numCases); //Reads in each test case (of up to LENGTH characters), and determines which of the two functions below are used.
char NUMtoDNA(int nums); //Convert number into DNA code value
int DNAtoNUM(char* letters); //"Encrypt" DNA code value into numbers
int findArrayLength(char* array); // Finds the Length of the array. NUMtoDNA: to specify length of temporary array to swap ints for correct decryption order. DNAtoNUM: setting highest power.
void printSequence(char* output, int arrayLength);

#define LENGTH 15
#define A 0
#define C 1
#define G 2
#define T 3

int sequenceNUM = 1;

int main(){

    int cases;

    scanf("%d",&cases);
    determineScenario(cases);





    system("pause");
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

char NUMtoDNA(int nums){

    int division = nums;
    int remainder;
    int arrayLength;
    char sequence[LENGTH];
    int i = 0;
    int k = 0;
    int j;

    printf("Sequence before memset: %s\n", sequence);
    memset(&sequence, 0, sizeof(sequence));
    printf("Sequence after memset: %s\n", sequence);

    printf("NUM to DNA (nums value): %d\n", nums);
    while(division > 0){
        remainder = division%4;
        division = division/4;
        sequence[i] = remainder + '0';
        printf("Division: %d\tRemainder: %d\t Sequence at i: %c\t Sequence: %s\n", division, remainder, sequence[i], sequence);
        i++;
    }

    arrayLength = findArrayLength(sequence);
    char sequenceCoded[arrayLength];
    printf("Sequence Length: %d\n", arrayLength);

    for(j=arrayLength-1;j>=0;j--){
        printf("K: %d\n", k);
        if(sequence[j] == '0') {
            sequenceCoded[k] = 'A';
            printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '1') {
            sequenceCoded[k] = 'C';
            printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '2') {
            sequenceCoded[k] = 'G';
            printf("HIT\n");
            k++;
        }
        else if(sequence[j] == '3') {
            sequenceCoded[k] = 'T';
            printf("HIT\n");
            k++;
        }
    }

    printf("Coded Sequence: %s (FINAL DIGIT IS TRASH)\n", sequenceCoded); //ignore any ending characters that aren't 'C','A','G', or 'T', remaining trash characters that don't get printed.

    printSequence(sequenceCoded, arrayLength);


    return 0;

}

int DNAtoNUM(char* letters){

    printf("DNA to NUM (letters value): %s\n", letters);
    return 0;

}

int findArrayLength(char* array){

    int count = 0;
    while(array[count]){
        count++;
    }
    return count;

}

void printSequence(char* output, int arrayLength){

    int i;

    printf("Sequence #%d: ",sequenceNUM);
    sequenceNUM++;
    for(i=0;i<arrayLength;i++){
        printf("%c", output[i]);
    }
    printf("\n");

}