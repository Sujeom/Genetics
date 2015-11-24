#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determineScenario(int numCases);
char NUMtoDNA();
int DNAtoNUM(char nums);

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
    char input[15];


    for(i=0;i<numCases;i++){
        memset(&input, 0, sizeof(input));
        scanf("%s",input);
        atoiVAL = atoi(input);
        if(atoiVAL !=0){
            NUMtoDNA(input);
        }
    }

}

char NUMtoDNA(char nums){



}