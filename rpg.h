#ifndef rpg_h
#define rpg_h

typedef struct TreeNode
{
    char *story;
    char *option1;
    char *option2;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void displayStory(TreeNode *tree);
int getInt();
TreeNode * createTree();

#endif
