// Program to perform BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    struct node *leftNode;
    int data;
    struct node *rightNode;
};

struct node *root = NULL;
struct node *InsertElement(struct node *, int);
struct node *preOrderTraversal(struct node *);

// struct node *newNode(int data){
//     struct node* newNode = (struct node*)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->leftNode = newNode->rightNode = NULL;
//     return newNode; 
// };


int main(){
   int option, val;
   do{
       printf("\n ********* MAIN MENU *********");
       printf("\n 1. Insert Element");
       printf("\n 2. Preorder Traversal");
       printf("\n 3. EXIT ");
       printf("\n 4. ENTER YOUR OPTION : ");
       scanf("%d",&option);

       switch(option)
       {
           case 1:
            printf("\n Enter value of the New Node : ");
            scanf("%d",&val);
            root = InsertElement(root, val);
            break;
           case 2:
            printf("\n The elements of the tree are : \n");
            preOrderTraversal(root);
            break; 
       }

   }while(option != 3);
    return 0;
}

struct node *InsertElement(struct node *root, int val){
    struct node *newNode; 
    newNode = (struct node*)malloc(sizeof(struct node));
    // newNode->data = val;
    // newNode->leftNode = newNode->rightNode = NULL;

    if(root == NULL){
        root = newNode;
        newNode->data = val;
        newNode->leftNode = newNode->rightNode = NULL;
    }else if(val <= root->data){
        root->leftNode = InsertElement(root->leftNode, val);
    }else{
        root->rightNode = InsertElement(root->rightNode, val);
    }
    return root;
}

struct node *preOrderTraversal(struct node *root){
    if(root != NULL){
        printf("%d\t",root->data);
        preOrderTraversal(root->leftNode);
        preOrderTraversal(root->rightNode);
    }
}