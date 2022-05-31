#include <math.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void print();
int keepPlaying();
int getPlayerHand();
void wait(int seconds);
int generateComputerHand();
void stringToCaps(char a[]);
char* stringifyHand(int hand);
void printResult(int computerHand, int playerHand);

int main() {	
	srand(time(NULL));
	
	do {
		print("ROCK, PAPER, SCISSORS");
		
		printResult(generateComputerHand(), getPlayerHand());
	} while(keepPlaying());
	
	print("Thanks for playing! UwU");
    
    wait(1000);

    return 0;
}

void print(char title[]){
    int j = 0;
    printf("%c%c",176,177);
    for(int i = 0; i <= strlen(title)+7; i++)
        printf("%c",178);
    printf("%c%c\n",177,176);
    printf("%c%c%c%c%c ",176,177,178,177,176);
    while(title[j]!='\0'){
        printf("%c",title[j]);
        j++;
    }
    printf(" %c%c%c%c%c\n",176,177,178,177,176);
    printf("%c%c",176,177);
    for(int i = 0; i <= strlen(title)+7; i++)
        printf("%c",178);
    printf("%c%c\n",177,176);

}

int keepPlaying() {
	char answer = 'Y';
	
	do{
		printf("Do you want to keep playing? [Y/N]: ");
		fflush(stdin);
		scanf("%c", &answer);
		answer = toupper(answer);
	} while(answer != 'Y' && answer != 'N');
	
    system("@cls||clear");
    
    return answer == 'Y' ? 1 : 0;
}

int getPlayerHand() {
	char playerHand[10];
	
	do
	{
		printf("\nRock, paper or scissors?: ");	
		
		scanf("%s", playerHand);
		stringToCaps(playerHand);
		
		 if(!strcmp(playerHand, "ROCK"))
            return 0;
        else if(!strcmp(playerHand, "PAPER"))
            return 1;
        else if(!strcmp(playerHand, "SCISSORS"))
            return 2;
	} while (1);
}

void wait(int seconds) {
	clock_t start_time = clock(); 
    while (clock() < start_time + 1000);
}

int generateComputerHand() {
	return rand() % 3;
}

void stringToCaps(char a[])
{
	for(int i = 0; i < strlen(a); i++)
		a[i] = toupper(a[i]);
}

char* stringifyHand(int hand)
{
	switch(hand){
        case 0:
            return "ROCK";
        case 1:
            return "PAPER";
        case 2:
            return "SCISSORS";
        default:
            return "";
    }
}

void printResult(int computerHand, int playerHand) {
	int result;
	
	printf("\n\nYour hand: %s", stringifyHand(playerHand));
    printf("\nComputer's hand: %s\n\n", stringifyHand(computerHand));
    
    result = playerHand - computerHand;
    
    if(result < 0)
        result += 3;
    
    switch(result){
        case 0:
            printf("It's a draw, gg\n\n");
            break;
        case 1:
            printf("YOU WON YAY!\n\n");
            break;
        case 2:
            printf("Oh, you lost. GG EZ NOOB\n\n");
            break;
        default:
            break;
    }
}
