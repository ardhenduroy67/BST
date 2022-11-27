#include<stdio.h>
#include<stdlib.h>
#define s(val) sizeof(val)

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} nd;
nd* Node(int data){
    nd* node=(nd*)malloc(s(nd));
    node->data=data;
    node->left=NULL; node->right=NULL;
    return node;
}
void insert(nd** head, int data){
    nd* node=Node(data);
    if(*head){
        nd* ptr=*head;
        while(1){
            if(ptr->data > node->data){
                if(ptr->left){
                    ptr=ptr->left;
                }
                else{
                    ptr->left=node;
                    break;
                }
            }
            else{
                if(ptr->right){
                    ptr=ptr->right;
                }
                else{
                    ptr->right=node;
                    break;
                }
            }
        }
    }
    else{
        *head=node;
    }
}
nd* BST(){
    nd* head=NULL;
    int n,data;
    printf("Number of Element : ");
    scanf("%d", &n);
    printf("Enter Tree : ");
    while(n--){
        scanf("%d",&data);
        insert(&head,data);
    }
    return head;
}
void inorder(nd* head){
    if(head){
        inorder(head->left);
        printf("%d ",head->data);
        inorder(head->right);
    }
}
void preorder(nd* head){
    if(head){
        printf("%d ",head->data);
        preorder(head->left);
        preorder(head->right);
    }
}
void postorder(nd* head){
    if(head){
        postorder(head->left);
        postorder(head->right);
        printf("%d ",head->data);
    }
}
signed main()
{
    nd* start=NULL;
    start=BST();
    preorder(start); printf("\n");
    postorder(start); printf("\n");
    inorder(start); printf("\n");
    return 0;
}