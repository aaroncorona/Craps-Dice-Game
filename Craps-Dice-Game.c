/******************************************************************************
Name: Aaron Corona
Date: 4/26/2022
CS50 Project #5

Crabs game requirement:
1) Generate random number between 2 and 12 (the first throw)
2) Check for an initial win (7 or 11) or an initial loss (2, 3, or 12)
3) Otherwise, the first throw becomes the target score
4) Keeping rolling until a secondary win (the target score) or a secondary loss (7)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Prototypes
int getRollResult();
int checkWin(int rollNum, int rollResult, int target);
int checkLoss(int rollNum, int rollResult);

int main() 
{   
    // Variables for tracking results
    int rollNum = 0;
    int rollResult = 0;
    int target = 0;
    srand(time(NULL));

    while(1){
        rollNum++;
        rollResult = getRollResult();
        printf("Roll Result: %d\n", rollResult);
        // Check for a win (initial or secondary)
        if(checkWin(rollNum, rollResult, target) == 1){
            printf("You Win!");
            break;
        }
        // Check for a loss (initial or secondary)
        if(checkLoss(rollNum, rollResult) == 1){
            printf("You Lost");
            break;
        }
        printf("Roll again.\n");
        // The first roll becomes the target for the secondary win
        if(rollNum == 1){ 
            target = rollResult;
            printf("Target is %d\n", target);
        }
    }
    return 0;
}

// Function to get a random number between 2-12
int getRollResult() 
{  
    int minValue = 2;
    int maxValue = 12;
    int value = rand() % (maxValue - minValue) + minValue; 
    return value;
}

// Function to check for a win 
int checkWin(int rollNum, int rollResult, int target) 
{ 
    int winFlag = 0;
    if(rollNum == 1
       && (rollResult == 7
           || rollResult == 11)) {
    winFlag = 1;
    }
    if(rollNum > 1
       && rollResult == target) {
    winFlag = 1;
    }
    return winFlag;
}

// Function to check for a loss 
int checkLoss(int rollNum, int rollResult) 
{ 
    int lossFlag = 0;
    if(rollNum == 1
       && (rollResult == 2
           || rollResult == 3
           || rollResult == 12)) {
    lossFlag = 1;
    }
    if(rollNum > 1
       && rollResult == 7) {
    lossFlag = 1;
    }
    return lossFlag;
}


