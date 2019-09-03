#ifndef KINNIKINK_BST_H_INCLUDED
#define KINNIKINK_BST_H_INCLUDED
#include <iostream>
using namespace std;
class BST{
    public:
        struct TreeNode{
            double value;
            int height; //EXTRA CREDIT
            TreeNode *left;
            TreeNode *right;
                TreeNode(double v){
                    value = v;
                    left = NULL;
                    right = NULL;
                    height = 1;
                }
            };
    int maxheight; //EXTRA CREDIT
    TreeNode *head;
    TreeNode *temp;
    BST();  //constructor
    ~BST(); //deconstructor
    void add(double v);
    void add(TreeNode *node, TreeNode *curr); //adding function to the tree
    void printTree(TreeNode *curr);//printing the tree function
    void findVal(double v, TreeNode *curr);//finding a value in the tree
    void del(TreeNode *&curr, double val);  //delete function
    void del(TreeNode *&curr);
    void findRange(int minimum, int maximum, TreeNode *curr);
};
#endif // kinnikink_BST_H_INCLUDED
