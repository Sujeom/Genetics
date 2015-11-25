#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void determineScenario(int numCases); //Reads in each test case (of up to LENGTH characters), and determines which of the two functions below are used.
char NUMtoDNA(int nums); //Convert number into DNA code value
int DNAtoNUM(char* letters); //"Encrypt" DNA code value into numbers
int findArrayLength(char* array); // Finds the Length of the array. NUMtoDNA: to specify length of temporary array to swap ints for correct decryption order. DNAtoNUM: setting highest power.
void printSequence(char* output);

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
    printf("Sequence Length: %d\n", arrayLength);


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