#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} nd;

// Recursive Approach
nd* search(nd* root, int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key < root->data){
        return search(root->left,key);
    }
    return search(root->right,key);
}

// Iterative Approach
nd* search(nd* root, int key){
    if(!root){
        return root;
    }
    nd* temp=root;
    while(temp){
        if(temp->data == key){
            return temp;
        }
        if(temp->data > key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return NULL;
}
