#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpg.h"

#define MAX_LINE_LENGTH 500

int main(int argc, char *argv[])
{
    TreeNode *root = createTree();
    displayStory(root);
    int input = getInt();
    free(root);
    return 0;
}

TreeNode * createTree()
{
    FILE *f;
    f = fopen("story.txt", "r");

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, f);
    TreeNode *tree = (TreeNode *) malloc(sizeof(TreeNode));

    while (strcmp(line, "END\n") != 0)
    {
        tree->story = strdup(line);
        fgets(line, MAX_LINE_LENGTH, f);
        tree->option1 = strdup(line);
        fgets(line, MAX_LINE_LENGTH, f);
        tree->option2 = strdup(line);
        fgets(line, MAX_LINE_LENGTH, f);
    }

    fclose(f);

    return tree;
}

void displayStory(TreeNode *tree)
{
    printf("%s", tree->story);
    printf("Press 1: %s", tree->option1);
    printf("Press 2: %s", tree->option2);
}

int getInt()
{
    char inputChar[1];
    char *error;
    fgets(inputChar, 2, stdin);

    int input = strtol(inputChar, &error, 10);

    if (*error != '\0')
    {
        printf("Invalid input");
        return -1;
    }

    return input;
}
