#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree using level order
struct TreeNode* createLevelOrderTree(char levelOrder[], int size) {
    if (size <= 0)
        return NULL;

    struct TreeNode* root = createNode(levelOrder[0]);
    struct TreeNode* queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;
	int i;
    for ( i = 1; i < size; i += 2) {
    
        struct TreeNode* current = queue[front++];
        
        if (levelOrder[i] != '\0') {
            current->left = createNode(levelOrder[i]);
            queue[rear++] = current->left;
        }

        if (i + 1 < size && levelOrder[i + 1] != '\0') {
            current->right = createNode(levelOrder[i + 1]);
            queue[rear++] = current->right;
        }
    }

    return root;
}

// Function to create a binary tree using depth order (pre-order)
struct TreeNode* createDepthOrderTree(char depthOrder[], int* index) {
    if (depthOrder[*index] == '\0' || *index < 0)
        return NULL;

    struct TreeNode* root = createNode(depthOrder[(*index)++]);
    root->left = createDepthOrderTree(depthOrder, index);
    root->right = createDepthOrderTree(depthOrder, index);

    return root;
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char levelOrder[] = {'A', 'B', 'C', 'D', 'E', '\0', '\0', 'F', 'G'};
    int levelOrderSize = sizeof(levelOrder) / sizeof(levelOrder[0]);

    struct TreeNode* levelOrderRoot = createLevelOrderTree(levelOrder, levelOrderSize);

    int depthIndex = 0;
    char depthOrder[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G', '\0'};
    struct TreeNode* depthOrderRoot = createDepthOrderTree(depthOrder, &depthIndex);

    printf("Pre-order traversal: ");
    preOrderTraversal(levelOrderRoot);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(levelOrderRoot);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(levelOrderRoot);
    printf("\n");

    return 0;
}

