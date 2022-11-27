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
    node->left=node->right=NULL;
    return node;
}
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
    } else{
        prev->right=node;
    }
    return root;
}
nd* BST(){
    nd* root=NULL;
    printf("Enter Size of the Tree : ");
    int n,data;
    scanf("%d", &n);
    printf("Enter Tree : ");
    while(n--){
        scanf("%d", &data);
        root=insert(root,data);
    }
    return root;
}
int search(nd* root, int key){
    if(!root){
        return 0;
    }
    nd* temp=root;
    while(temp){
        if(temp->data==key){
            return 1;
        }
        if(temp->data > key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return 0;
}
void inorder(nd* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(nd* root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(nd* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    nd* root=NULL;
    printf("1)BST Creation\n2)InOrder Traversal\n3)PreOrder Traversal\n4)PostOrder Traversal\n5)Search Element\n");
    printf("6)Exit From Loop\n");
    int n;
    while(1){
        printf("Enter Choice : ");
        scanf("%d",&n);
        switch (n){
            case 1:
                root=BST();
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the Element you want to search : ");
                int p; scanf("%d",&p);
                (search(root,p))?printf("Successfull\n"):printf("Unsucessfull\n");
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}