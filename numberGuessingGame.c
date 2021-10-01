/*Create an interactive program that allows a user to guess a number between 1-10. 
You should create a menu that will have options (this should be displayed on the screen):*/

/*Press 1 to play a gamePress 
2 to change the max numberPress 
3 to quit*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    //declare variables 
    int randomNum;
    int option;
    int guessedNum;
    int newMax;
    

    //random numbers
    time_t t;
    srand((unsigned)time(&t));

    
    //
    //loop for the menu
    LOOP: do {
      printf("---Number Guessing Game ---\n");
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        scanf("%d", &option);

        //switch statement for the options 
        switch(option){
            //if option 1 is chosen   
            //if they press q, take them back to the menu
            case 1 :
            //print to the user to enter a number 
            //if the input is equal to the random number output you won! 
                randomNum = rand() %10;
                //printf("%d", randomNum);
              GUESS:  printf("Enter a number between 1-10\n");
                char check = getchar();
                scanf("%d", &guessedNum);

                if(guessedNum == randomNum)
                {

                    printf("You won!\n");
                    goto LOOP;
                }
                //if output is not equal to the random number 
                //if num is too high, let them know and allow themm to guess again
                else if (guessedNum > randomNum){
                    printf("Your guess is too high! Try again!\n");
                    goto GUESS;
                }
                //if num is too low, let them know and allow them to guess again 
                else{
                    printf("Your guess is too low! Try again!\n");
                    goto GUESS;
                }

                //if they press q, take them back to the menu

                break;
            //if option 2 is chosen 
            //tell them about the max number they can set it to 
            //check for negative numbers
            //checl if the num is too high
            case 2 : 
               MAX:  printf("The maximum value you can set the number to is 100.\n");
                printf("Enter a new maximum value\n");

                scanf("%d", newMax);

                if (newMax > 100)
                {
                    printf("The maximum value needs to be greater than or equal to 1 and less than or equal to 100.\n");
                    goto MAX;
                }
                break;
            //if option 3 is chosen
            //thank the user and end the game 
            case 3:
                printf("Thank you for playing!");
                exit(0);
            default :
                printf("Invalid option\n", option);
        }
    }while (option <= 3); 


    return 0;
}