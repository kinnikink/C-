#include "kinnikink_BST.h"
#include <iostream>
using namespace std;
int imported;
BST::BST(){
head = NULL;
maxheight = 0; //initializes max height of 0
}
BST::~BST(){
head = NULL;
maxheight = 0;
}
void BST::add(double v){
    imported = 1;
    TreeNode *node = new TreeNode(v);
    if(head == NULL){
        head = node;
        node->height = 1;
        maxheight = 1;
        return;
    }
    add(node, head);
}

void BST::add(TreeNode *node, TreeNode *curr){
    node->height++; // keeps track of a number's height within the tree
    if(node->value < curr->value){
        if(curr->left == NULL){
            curr->left = node;
            if (maxheight < node->height) {
                maxheight = node->height; //adjusts the max height
            }
            return;
        }
    add(node, curr->left); //function call for the lesser side of the tree
    }
    else{
        if(curr->right == NULL){
            curr->right = node;
            if (maxheight < node->height) {
                maxheight = node->height;
            }
            return;
        }
    add(node, curr->right); //function call for the greater side of the tree
    }
}
void BST::printTree(TreeNode *curr){
    int height_counter = 0;
    if(curr != NULL){
        printTree(curr->left);
        cout << curr->value << "\t";
        int holder_storage = 0;
        for (int i = 1;i < curr->height;i++) {
            cout << "-";
            height_counter++;
        }
        cout << "\t Level: " << height_counter;
        cout << endl;
        height_counter = 0;
        printTree(curr->right);
    }
}
void BST::findVal(double v, TreeNode *curr){
    BST leaf;
    if(curr != NULL){
        if(curr->value == v){
            cout << v << " was found within the Tree!\n";
        }
        else if(curr->value > v){
            temp = curr; // value closest to __ happens with these temporary pointers
            findVal(v, curr->left);
        }
        else{
            temp = curr;
            findVal(v, curr->right);
        }
    }
    else{
        cout << "\"" << v << "\"" << " not Found!\n";
        if (imported == 1) {
            cout << "Reason: " << "\"" << v << "\" does not exist within this Tree.\n";
            cout << "Closest value found within the list:  " << temp->value << endl;
        }
        else { //if the user forgot to import a file
            cout << "Reason: No file has been imported into the program.\n";
        }
    }
}
void BST::del(TreeNode *&curr, double val){
    if(curr != NULL){
        if(curr->value == val){ //the value that the user wants to delete HAS been found
            del(curr);
            cout << val << " was deleted.\n"; //telling the user that the value has been deleted
        }
        else if(curr->value > val){
            del(curr->left, val); // function call to continue searching through the left side of the tree
        }
        else{
            del(curr->right, val); // function call to continue searching through the right side of the tree
        }

    }
    else {
        cout << val << " was not found within the list.\n";
    }
}
void BST::del(TreeNode *&curr){
    TreeNode *node;
    if(curr->left == NULL){ //searches through the left side of the tree
        curr = curr->right;
    }
    else if(curr->right == NULL){ //searches through the right side of the tree
        curr = curr->left;
    }
    else {
        node = curr->right;
        while (node->left != NULL) {
            node = node->left;
        }
        node->left = curr->left;
        curr = curr->right;
    }
}
void BST::findRange(int min, int max, TreeNode*curr){
    if(curr!=NULL){
        findRange(min, max, curr->left);
        if(min <= curr->value && curr->value <=max){
            cout<< curr->value<< endl;
        }
        findRange(min, max,curr->right);
    }
}
