#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determineScenario(int numCases); //Reads in each test case (of up to LENGTH characters), and determines which of the two functions below are used.
char NUMtoDNA(char* nums); //Convert number into DNA code value
int DNAtoNUM(char* letters); //"Encrypt" DNA code value into numbers

#define LENGTH 15



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
            NUMtoDNA(input);
        }
        else if(atoiVAL == 0){
            DNAtoNUM(input);
        }
    }

}

char NUMtoDNA(char* nums){

    printf("NUM to DNA (nums value): %s\n", nums);
    return 0;

}

int DNAtoNUM(char* letters){

    printf("DNA to NUM (letters value): %s\n", letters);
    return 0;

}