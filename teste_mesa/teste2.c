#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Função para encontrar o nó com o valor mínimo
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Função para remover um nó
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
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

// Função para imprimir a árvore em ordem (opcional)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserindo os dígitos do CPF
    int cpf[] = {0, 4, 8, 7, 2, 2, 0, 0, 1, 3, 6};
    for (int i = 0; i < 11; i++) {
        root = insert(root, cpf[i]);
        // Aqui você pode imprimir a árvore após cada inserção para ver a estrutura
    }

    // Removendo o 7º dígito (dígito 0)
    root = deleteNode(root, 0);
    return 0;
}
