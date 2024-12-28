#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else if (data > node->data)  
        node->right = insert(node->right, data);
    return node;
}

struct Node* minValueNode(struct Node* node){
    struct Node* atual = node;
    while (atual && atual->left != NULL){
        atual = atual->left;
    }
    return atual;
}

struct Node* deleteNode(struct Node* root, int data){

    if (root == NULL) return root;

    if (data < root->data){
        root->left = deleteNode(root->left, data);
    }

    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }

    else{
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){

    struct Node* root = NULL;
    
    int cpf[] ={0, 4, 8, 7, 2, 2, 0, 0, 1, 3, 6};
    
    for(int i = 0; i < 11; i++){
        root = insert(root, cpf[i]);
    }

    printf("Arvore apos insercao: ");
    inorder(root);
    
    root = deleteNode(root, cpf[6]);
    
    printf("\n");
    printf("Arvore apos remover o setimo digito: ");
    inorder(root);

    return 0;
}
