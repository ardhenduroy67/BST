#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} nd;
nd* new(int data){
    nd* node=(nd*)malloc(sizeof(nd));
    node->data=data;
    node->left=NULL; node->right=NULL;
    return node;
}
// Recursive Approach
nd* insert(nd* node, int data){
    if(node==NULL){
        return new(data);
    }
    if(data < node->data){
        node->left=insert(node->left,data);
    }
    else if(data > node->data){
        node->right=insert(node->right,data);
    }
    return node;
}
// Iterative Approach - 1
nd* insert(nd* root,int key){
    nd* node=new(key);
    if(!root){
        return root=node; 
    }
    nd* temp=root;
    while(1){
        if(temp->data > node->data){
            if(temp->left){
                temp=temp->left;
            }
            else{
                temp->left=node;
                break;
            }
        }
        else if(temp->data < node->data){
            if(temp->right){
                temp=temp->right;
            }
            else{
                temp->right=node;
                break;
            }
        }
    }
    return root;
}
// Iterative Approach - 2
nd* insert(nd* root, int data){
    nd* node=new(data);
    if(!root){
        return root=node; 
    }
    nd* prev=NULL; nd* temp=root;
    while(temp){
        if(data < temp->data){
            prev=temp;
            temp=temp->left;
        }
        else if(data > temp->data){
            prev=temp;
            temp=temp->right;
        }
    }
    if(data < prev->data){
        prev->left=node;
    }
    else{
        prev->right=node;
    }

    return root;
}