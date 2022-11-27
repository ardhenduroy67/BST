#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} nd;
nd* findLastRight(nd* root){
    if(!root->right){
        return root;
    }
    return findLastRight(root->right);
}
nd* helper(nd* root){
    if(!root->left){
        return root->right;
    }
    if(!root->right){
        return root->left;
    }
    nd* right_child=root->right;
    nd* last_right=findLastRight(root->left);
    last_right->right=right_child;
    return root->left;
}
nd* deleteNode(nd* root, int key){
    if(!root) return NULL;
    if(root->data==key){
        return helper(root);
    }
    nd* temp=root;
    while(temp){
        if(temp->data > key){
            if(temp->left != NULL && temp->left->data==key){
                temp->left=helper(temp->left);
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else{
            if(temp->right != NULL && temp->right->data==key){
                temp->right=helper(temp->right);
                break;
            }
            else{
                temp=temp->right;
            }
        }
    }
    return root;
}