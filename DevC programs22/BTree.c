#include <stdio.h>
#include <stdlib.h>

// B-tree node structure
typedef struct BTreeNode {
    int *keys;             // Array of keys
    int t;                 // Minimum degree
    struct BTreeNode **C;  // Array of child pointers
    int n;                 // Current number of keys
    int leaf;              // 1 if node is leaf, else 0
} BTreeNode;

// Function to create a new B-tree node
BTreeNode* createNode(int t, int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->t = t;
    node->leaf = leaf;
    node->keys = (int*)malloc(sizeof(int) * (2*t - 1));
    node->C = (BTreeNode**)malloc(sizeof(BTreeNode*) * (2*t));
    node->n = 0;
    return node;
}

// Function to search key k in subtree rooted with node
BTreeNode* search(BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;
    if (i < root->n && root->keys[i] == k)
        return root;
    if (root->leaf)
        return NULL;
    return search(root->C[i], k);
}

// Split the child y of node x at index i
void splitChild(BTreeNode* x, int i, BTreeNode* y) {
	int j;
    int t = y->t;
    BTreeNode* z = createNode(t, y->leaf);
    z->n = t - 1;

    // Copy last t-1 keys of y to z
    for ( j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    // Copy last t children of y to z
    if (!y->leaf) {
        for ( j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    y->n = t-1;

    // Create space for new child
    for (j = x->n; j >= i+1; j--)
        x->C[j+1] = x->C[j];

    x->C[i+1] = z;

    // Move keys of x to make space for middle key
    for ( j = x->n-1; j >= i; j--)
        x->keys[j+1] = x->keys[j];

    x->keys[i] = y->keys[t-1];
    x->n += 1;
}

// Insert key in non-full node
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n += 1;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;
        i++;
        if (x->C[i]->n == 2*x->t - 1) {
            splitChild(x, i, x->C[i]);
            if (k > x->keys[i])
                i++;
        }
        insertNonFull(x->C[i], k);
    }
}

// Insert key in B-tree
BTreeNode* insert(BTreeNode* root, int k, int t) {
    if (!root) {
        root = createNode(t, 1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*t - 1) {
        BTreeNode* s = createNode(t, 0);
        s->C[0] = root;
        splitChild(s, 0, root);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->C[i], k);
        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// Print B-tree (in-order)
void printBTree(BTreeNode* root, int level) {
    if (root) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                printBTree(root->C[i], level+1);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            printBTree(root->C[i], level+1);
    }
}

int main() {
    BTreeNode* root = NULL;
    int t = 3; // Minimum degree
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display B-tree\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key, t);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found in B-tree.\n", key);
                else
                    printf("Key %d not found in B-tree.\n", key);
                break;
            case 3:
                printf("B-tree in-order: ");
                printBTree(root, 0);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

