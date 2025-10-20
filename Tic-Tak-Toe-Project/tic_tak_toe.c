/*Developed by Nandan Kumar T 
Date:19/10/2025
Description:tic-tac-toe game*/

#include<stdio.h>
#define RED     "\033[1;31m"
#define YELLOW  "\033[4;33m"
#define YELLOW1  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m" 
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m" 
// Function declarations
void printbox();      // Function to display the tic-tac-toe board
void markbox();       // Function to mark X or O on the board
int check_win();      // Function to check if there is a winner
void reset();       // Function to reset the board
void system();

// Global array representing the tic-tac-toe board
char box[] = {'1','2','3','4','5','6','7','8','9'};

int main()
{
    int choice;
    do
    {
        // Display main menu
        printf(YELLOW1"\n========Tic-Tak-Toe========\n"RESET);
        printf(CYAN"1.Let's Play\n2.Exit\n"RESET);
        printf(YELLOW1"===========================\n\n"RESET);
        printf(GREEN"Enter your Choice: "RESET);
        scanf("%d", &choice);

        // Menu options
        switch(choice)
        {
            case 1:
                markbox();   // Start game
                reset();   // Reset the board
                break;
            default:
                printf(RED"Invalid choice. Please try again.❎\n"RESET);
        }
    } while(choice != 2); // Continue until user chooses Exit
    // mark=(player)
}

void printbox()
{
    // Display the current state of the board
    system("clear");
    printf(YELLOW1"\n\n\t\t========Tic-Tak-Toe========\n"RESET);
    printf("\t\t\t|\t|\t\n");
    printf("\t\t\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t\n", box[0], box[1], box[2]);
    printf("\t\t--------|-------|--------\n");
    printf("\t\t\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t\n", box[3], box[4], box[5]);
    printf("\t\t--------|-------|--------\n");
    printf("\t\t\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t|\033[1;31m%4c\033[0m\t\n", box[6], box[7], box[8]);
    printf("\t\t\t|\t|\t\n"RESET);
    printf(YELLOW1"\t\t===========================\n\n"RESET);
}

void markbox()
{
    char str1[10], str2[10];
    int ret = 0, player = 1, input;

    // Get player names
    printf(CYAN"Enter the player 1 Name: "RESET);
    scanf("%s", str1);
    printf(CYAN"Enter the player 2 Name: "RESET);
    scanf("%s", str2);
    int count=0;
    int arr[20];
    // Main game loop
    while(ret != 1)
    {
        // Determine which player's turn it is
        char *name = (player % 2 == 0) ? str2 : str1;

        printbox(); // Display board
        int valid = 0;
        while (!valid)  // keep asking until a valid move
        {
            printf(GREEN"\t\t     %s->{0}\t%s->{X}\n\n"RESET,str1,str2);
            printf(MAGENTA"\tEnter the player %s Index choice (From 1 to 9): "RESET, name);
            scanf("%d", &input);

           // Check for invalid range
           if (input < 1 || input > 9){
            printf(RED"\tInvalid choice.❎\n"RESET);
            continue; // ask again
            }

           // Check for duplicate move
            int duplicate = 0;
            for (int j = 0; j < count; j++)
            {
                if (arr[j] == input)
                {
                    duplicate = 1;
                    printf(RED"\tEntered index is already chosen. Please enter another index.\n\n"RESET);
                    break;
                }
            }

            if (!duplicate)
            {
                valid = 1; // valid move found
            }
        }
        // Once valid input is confirmed, store it
        arr[count++] = input;

        // Mark 'O' for player 1 and 'X' for player 2
        char mark = (player % 2 == 0) ? 'X' : 'O';
        box[input - 1] = mark;

        // Check game status
        ret = check_win();
        if(ret == -1)
        {
            printbox();
            printf("\033[1;35m\n\t\tThe Game is Drawn 🤝\n\n"RESET);
            return;
        }
        else if(ret == 1)
        {
            printbox();
            printf("\033[1;35m\n\t\tCongrats,%s You Won ! ❤️\n\n\033[0m", name);
        }
        player++; // Next player's turn
    }
}

int check_win()
{
    // Check all possible winning combinations
    if(box[0] == box[4] && box[0] == box[8])
        return 1;
    else if(box[2] == box[4] && box[2] == box[6])
        return 1;
    else if(box[0] == box[1] && box[0] == box[2])
        return 1;
    else if(box[3] == box[4] && box[3] == box[5])
        return 1;
    else if(box[6] == box[7] && box[6] == box[8])
        return 1;
    else if(box[0] == box[3] && box[0] == box[6])
        return 1;
    else if(box[1] == box[4] && box[1] == box[7])
        return 1;
    else if(box[2] == box[5] && box[2] == box[8])
        return 1;
    else
    {
        // Check for draw (all boxes filled)
        int count = 0;
        for(int i = 0; i < 9; i++)
        {
            if(box[i] == 'O' || box[i] == 'X')
            {
                count++;
            }
        }
        if(count == 9)
        {
            return -1; // Game draw
        }
    }
    return 0; // Continue game
}

void reset()
{
    // Reset the board for a new game
    for(int i = 0; i < 9; i++)
    {
        box[i] = '0' + (i + 1);
    }
}
