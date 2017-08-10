#include <stdio.h>
#include <stdlib.h>

void displayStory(char *story, char *option1, char *option2);
int getInt();

int main(int argc, char *argv[])
{
    displayStory("Your eyes open, and all you see is darkness.", "Go back to sleep.", "Look around.");

    int input = getInt();

    if (input == 1)
    {
        printf("1 pressed\n");
    }
    else if (input == 2)
    {
        printf("2 pressed\n");
    }
    else
    {
        printf("Invalid input.\n", );
    }

    return 0;
}

void displayStory(char *story, char *option1, char *option2)
{
    printf("%s\n", story);
    printf("Press 1: %s\n", option1);
    printf("Press 2: %s\n", option2);
}

int getInt()
{
    char inputChar[1];
    char *error;
    fgets(inputChar, 2, stdin);

    int input = strtol(inputChar, &error, 10);

    if (*error != '\0')
    {
        printf("Invalid input: %s", error);
        return -1;
    }

    return input;
}
