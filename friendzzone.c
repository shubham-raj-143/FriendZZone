#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <windows.h>

#define BUFFER_SIZE 1000

void delay()
{
    for (int i = 0; i < 40; i++)
    {
        printf("-");
        Sleep(20);
    }
    printf("\n");

}
void delay1()
{
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<7;j++)
        {
            printf(" ");
            Sleep(20);
            
        }
        Sleep(1);
        printf("\r");
    }
    printf("\n");
}

int countOccurrences(FILE *fptr, const char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;

    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}

void signup(char *name, int key)
{
    char k[20];
    //Convert Integer to String
    sprintf(k, "%d", key);
    // printf("%s", name);
    FILE *ptr;
    
    ptr = fopen("LogInfo.txt", "w");
    
    fprintf(ptr, "%s\n", k);
    fprintf(ptr, "%s", name);
    fprintf(ptr, "\n");
    fclose(ptr);
    
    printf("At time of SignIn you will require the \nAuto generated key %d and username\n", key);
    delay();
    signin();
}
void signin()
{
    FILE *fptr;
    char path[100];

    char word[50], ke[20];
    
    int wCount, kcount;

    printf("Welcome To SignIn Page\n");
    delay();

    /* Input word to search in file */
    printf("UserName: ");
    scanf("%s", word);
    printf("\nKey : ");
    scanf("%s", ke);

    /* Try to open file */
    fptr = fopen("LogInfo.txt", "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    // Call function to count all occurrence of word
    kcount = countOccurrences(fptr, ke);
    fclose(fptr);
    fptr = fopen("LogInfo.txt", "r");
    wCount = countOccurrences(fptr, word);
    

    // printf("'%s' is found %d times in file.\n", word, wCount);
    // printf("'%s' is found %d times in file.\n", ke, kcount);

    // Close file
    delay();
    if(wCount>=1 && kcount>=1)
    {
        printf("Congrats!! You are now successfully LogedIn\n");
        
    }
    else
    {
        printf("Oops!!! Unsuccessful SignIn\nTry Again\n");
        exit(0);
    }
    fclose(fptr);
    delay();
    
}

//Sign
void sign()
{
    system("cls");
    int choice, key;
    char name[20];
    printf("Press 1 to SignUp\nPress 2 to SignIn\n");
    scanf("%d", &choice);
    delay();
    switch (choice)
    {
    case 1:
        srand(time(NULL)); //srand seeds the random value---so each time we will get random numbers (otherwise compiler take seed value as 1 always)
        printf("Welcome to SignIn Page\n");
        delay();
        key = (rand() % (9999 - 100 + 1)) + 100;
        printf("User Name : ");
        scanf("%s", name);
        signup(name, key);
        break;

    case 2:
        delay();
        signin();
        break;
    
    default:
        break;
    }

}
int snakeWaterGun(char you, char comp)
{
    // returns 1 if yo win , -1 if you loose, and 0 if there is a tie

    if (you == 's' && comp == 'w')
    {
        return 1;
    }
    else if (you == 'w' && comp == 's')
    {
        return -1;
    }
    if (you == 's' && comp == 'g')
    {
        return -1;
    }
    else if (you == 'g' && comp == 's')
    {
        return 1;
    }
    if (you == 'w' && comp == 'g')
    {
        return 1;
    }
    else if (you == 'g' && comp == 'w')
    {
        return -1;
    }
    // if all above conditions are false that means the match has been drawn
    return 0;
}


int main()
{
    // Alternative to clrscr --- as it is Ms Dos
    system("cls");
    char chat[100], name[20];
    int friend = 0;
    
    sign();
    fflush;
    system("cls");
    printf("Enter your name :\n");
    scanf("%s", name);
    delay();
    
    printf("Libiya and %s are connected now!\n", name);
    delay();
    printf("Start chat with Libiya and make sure not to get friendzzoned!\nBest Of Luck\n");
    delay();
    int i = 2;
    
        // int up, low;
        // if(i<=4)
        // {
        //     up = 4;
        //     low = 1;
        // }
        // if (i <= 6)
        // {
        //     up = 6;
        //     low = 5;
        // }
        // else{
        //     up=7;
        //     low = 7;
        // }
        int l = (rand() % (2 - 0 + 1)) + 0;
       
            srand(time(NULL));
            printf("Libiya : Lets Play Snake Water Gun Game. Rules are- Snake > Water, Gun > Snake & Water > Gun---Lets Go:)\n");

            printf("\n");
        int c;
            printf("%s : ", name);
            
              char you, comp;
              int y;
                int num, r;

                srand(time(0));         // by writing thid line rand will generate random number everytime we run our code otherwise it will generate only one random number everytime
                num = rand() % 100 + 1; // will generate random no.  between 1 and 100

                if (num < 33)
                {
                    comp = 's';
                }
                else if (num >= 33 && num < 66)
                {
                    comp = 'w';
                }
                else
                {
                    comp = 'g';
                }

                printf("Enter 's' for snake, 'w' foe water and 'g' for gun\n");
                fflush;
                scanf("%s", &you);
                int result = snakeWaterGun(you, comp);
                if (result == 1)
                {
                    printf("You won the game\n");
                    printf("You choose %c and Libiya choose %c\n", you, comp);
                    r = 1;
                }
                else if (result == -1)
                {
                    printf("You Lost the game\n");
                    printf("You choose %c and Libiya choose %c\n", you, comp);
                    r=-1;
                    
                }
                else
                {
                    printf("The match has been drawn \n Play again\n");
                    printf("You choose %c and Libiya choose %c\n", you, comp);
                    r=0;
                }
                delay();
                if(r == 1)
                {
                    printf("Libiya : You are my dear One!!\n========You Won!!!!=======\n");
                    delay();
                    exit(0);
                }
                else if(r == -1)
                {
                    friend = 1;
                }
                else
                {
                    delay();
                    printf("Nice\n =============Will Meet you Soon===================");
                    return 0;
                }

            
            printf("\n");
            delay1();

        

        if(friend == 1)
        {
            delay();
            printf("You have been friendzzoned by Libiya, \nEnhance your skill and try later!\n");
            delay();
            exit(0);
        }
    
    return 0;
    
}