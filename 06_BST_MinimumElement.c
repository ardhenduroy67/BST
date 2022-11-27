#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} nd;

int minValue(nd* root){
    if(root==NULL) return -1;
    if(!root->left) return root->data;
    return minValue(root->left);
}
