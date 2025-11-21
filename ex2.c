/******************
Name: Avihay Ziv
ID: 216022558
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    int gameChoice; 
    
    int decimalNum, goldenCorns, tempNum;  
    
    int ducksInline, flag;
    unsigned long long quakOrSH; 
    
    int baseNum, exponentNum, powerNum;
    
    int drawnDucks, tempDucks, runDucks;
    
    int secretCode, tempCode, checkNum, numTimes;

    do {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        scanf("%d", &gameChoice);

        switch(gameChoice) {
            case 1: {
                printf("please enter a positive number:\n");
                do {
                    scanf("%d", &decimalNum);
                    if(decimalNum > 0) {
                        goldenCorns = 0;
                        tempNum = decimalNum;
                        while(tempNum > 0) {
                            if(tempNum % 2 != 0) 
                                goldenCorns++;
                            tempNum /= 2;
                        }
                        printf("Ducky earns %d corns\n", goldenCorns);
                    }
                    else {
                        printf("Invalid number, please try again\n");
                    }
                } while(decimalNum <= 0); 
                break;
            }
            
            case 2: {
                quakOrSH = 0; 
                printf("please enter the number of ducks:\n");
                do {
                    scanf("%d", &ducksInline);
                    
                    if (ducksInline > 0) {
                        printf("you entered %d ducks\n", ducksInline);
                        for(int i = 0; i < ducksInline; i++) { 
                            printf("duck %d do QUAK? 1 for yes, 0 for no\n", i+1);
                            do{
                                scanf("%d", &flag);
                                if(flag!=0 && flag!=1)
                                    printf("Invalid number, please try again\n");
                            }while(flag!=0 && flag!=1);
                            
                            if(flag == 1)
                                quakOrSH = quakOrSH | (1ULL << i);       
                        }
                        
                        for(int i=0; i < ducksInline; i++){
                            if(quakOrSH & (1ULL << i))
                                printf("duck number %d do Quak\n", i+1);
                            else
                                printf("duck number %d do Sh...\n", i+1);
                        }
                    } 
                    else {
                        printf("Invalid number, please try again\n");
                    }

                } while(ducksInline <= 0);
                break;
            }
            
            case 3: {
                powerNum=1;
                printf("please enter the number\n");
                do{
                    scanf("%d", &baseNum);
                    if (baseNum<0) 
                        printf("Invalid number, please try again\n");
                }while(baseNum<0); 
                
                printf("please enter the exponent\n");
                do{
                    scanf("%d", &exponentNum);
                    if (exponentNum<0) 
                        printf("Invalid number, please try again\n");
                }while(exponentNum<0);

                for(int i=0; i<exponentNum; i++)
                    powerNum*=baseNum;
                
                printf("your power is: %d\n", powerNum);
                break;
            }
            
            case 4: {
                printf("please enter number of ducks:\n");
                do{
                    scanf("%d", &drawnDucks);
                    if(drawnDucks<=0)
                        printf("Invalid number, please try again\n");
                    
                }while(drawnDucks<=0);

                runDucks = drawnDucks;
                for(int j=0; j<((runDucks/10)+1); j++){
                    if(drawnDucks/10>0){
                        tempDucks=10;
                        for(int i=0; i<tempDucks; i++){
                            printf("   _    ");
                            if(i+1==tempDucks) printf("\n");
                        }
                        for(int i=0; i<tempDucks; i++){
                            printf("__(o)>  "); 
                            if(i+1==tempDucks) printf("\n");
                        }
                        for(int i=0; i<tempDucks; i++){
                            printf("\\___)   ");
                            if(i+1==tempDucks) printf("\n");
                        }
                        drawnDucks-=10;
                    }
                    else{
                        tempDucks=drawnDucks;
                        if(tempDucks > 0) {
                            for(int i=0; i<tempDucks; i++){
                                printf("   _    ");
                                if(i+1==tempDucks) printf("\n");
                            }
                            for(int i=0; i<tempDucks; i++){
                                printf("__(o)>  "); 
                                if(i+1==tempDucks) printf("\n");
                            }
                            for(int i=0; i<tempDucks; i++){
                                printf("\\___)   ");
                                if(i+1==tempDucks) printf("\n");
                            }
                        }
                    }
                }
                break;
            }
            case 5: {
                printf("please enter number\n");
                do {
                    scanf("%d", &secretCode);
                    if(secretCode <= 0)
                        printf("Invalid number, please try again\n");
                } while(secretCode <= 0);

                tempCode = secretCode;
                
                while(secretCode > 0) {
                    checkNum = secretCode % 10;
                    secretCode = secretCode / 10;
                    
                    tempCode = secretCode;
                    numTimes = 0; 

                    while(tempCode > 0) {
                        if(tempCode % 10 == checkNum) {
                            numTimes++;
                        }
                        else {
                            numTimes = numTimes;
                        }
                        tempCode = tempCode / 10;
                    }

                    if(numTimes > 0) {
                        printf("%d appears more than once!\n", checkNum);
                    }
                }
                break;
            }
            
            case 6: {
                printf("Good night! See you at the pond tomorrow.\n");
                break;
            } 
            
            default: {
                printf("Invalid option, please try again\n");
                break;
            }
        }
        
    } while(gameChoice != 6);

    return 0;
}