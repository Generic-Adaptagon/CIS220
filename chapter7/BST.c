//Ivan Escarciga
//Chpt7 PA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

// Definition of the BST Node
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function to create a new BST node
BSTNode* createNode(int key) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Definition of the Binary Search Tree (BST)
typedef struct BST {
    BSTNode* root;
} BST;

// Function to create an empty BST
BST* createBST() {
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

BSTNode* getRoot(BST* tree) {
    return tree->root;
}

// Implement the BSTSearchRecursive PseudoCode found in PA 7.9.1
BSTNode* searchRecursive(BSTNode* node, int key) {
	
	/* if node Null move on */
	if (node != NULL) {
		if (key == node->key){
			return node;
		}
	 /* Determine if the key is to the left or right of the node. Then go to that branch*/
		if(key < node->key) {
		return searchRecursive(node->left, key);  // left branch
		} else {
		return searchRecursive(node->right, key);	//right branch
		}
		
		}//if not null 
	return NULL; // returns NULL to end ALL recusive instances
}

// Implement the BSTSearch PseudoCode found in PA 7.9.1
BSTNode* search(BST* tree, int key) {
	/*pass the root tree node to the search function*/
	return searchRecursive(tree->root, key);
}

// Function to check if the tree contains a node with the given key
bool contains(BST* tree, int key) {
    return search(tree, key) != NULL;
}

// Implement the BSTInsertRecursive PseudoCode found in Fig. 7.9.2
void insertRecursive(BSTNode* parent, BSTNode* nodeToInsert) {
	/*If less than parent node preform leftside code (if this was a diagram), else preform right code*/
		if(nodeToInsert->key < parent->key) {
	/*leftside code*/
		/*If parent node is empty make the nodeToInsert that node*/
			if(parent->left == NULL) {
			parent->left = nodeToInsert;
		/*else go into that node and repeat*/
			} else {
				insertRecursive(parent->left, nodeToInsert);
			} //else
		} else { 
	/*right side code*/
		/*If parent node is empty make the nodeToInsert that node*/
			if (parent->right == NULL) {
				parent->right = nodeToInsert;
			} else { 
			/*else go into that node and repeat*/
				insertRecursive(parent->right, nodeToInsert);
			}
		}//else
}

// Implement the BSTInsertNode PseudoCode found in Fig. 7.9.2
void insertNode(BST* tree, BSTNode* node) {
/*if tree is empty, make inserting node the root node*/
	if (tree->root == NULL) {
		tree->root = node;
	} else {
	/*if not, go to the search and insert function*/
		insertRecursive(tree->root, node); 
	}
	
}

// Function to insert a key into the BST
bool insertKey(BST* tree, int key) {
    if (contains(tree, key)) {
        return false; // Duplicate keys not allowed
    }  
	// Create a new node
    BSTNode* newNode = createNode(key);
	// Call insertNode method
    insertNode(tree, newNode);
    return true;
}

// Implement a printInReverseOrder function discussed in Section 7.7 
void printInReverseOrder(BSTNode* node) {
	
	if (node == NULL) {
      return;
   }
   
   printInReverseOrder(node->left); // go as far left as possible
		printf("%d ", node->key); // print variable
   printInReverseOrder(node->right); // go to right one
	
}

 // Function to print the binary tree in 2D using reverse inorder traversal
void print2DUtil(BSTNode* root, int space) {
    // Base case: If the node is NULL, return
    if (root == NULL) {
        return;
    }

    // Increase space for the next level
    space += COUNT;

    // First, process the right child
    print2DUtil(root->right, space);

    // Print the current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // Then, process the left child
    print2DUtil(root->left, space);
}

// Wrapper function to print the tree
void print2D(BSTNode* root) {
    // Start with 0 space
    print2DUtil(root, 0);
}

// Function to free memory allocated for BST nodes
void freeTree(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Implement the main function based on the program instructions
int main() {
	
/*Make a tree called "tree"*/
    BST* tree = createBST();
/*insertions galore, in specified order*/
	insertKey(tree, 35);
	insertKey(tree, 41);
	insertKey(tree, 13);
	insertKey(tree, 57);
	insertKey(tree, 3);
	insertKey(tree, 83);
	insertKey(tree, 88);
	insertKey(tree, 51);
	insertKey(tree, 38);
	insertKey(tree, 20);
	insertKey(tree, 11);
	insertKey(tree, 22);
	insertKey(tree, 27);
	insertKey(tree, 21);
	insertKey(tree, 48);
	insertKey(tree, 8);
	
/*print in reverse order*/
	printInReverseOrder(tree->root);
	printf("\n");// new line as to not confuse users output reading.
/*print the tree as a 2d map from left (root) to right (leaves)*/
	print2D(tree->root);
	
/*search for 27 (in the tree), if statement to output wheather it was sccuessful or not*/
	if (searchRecursive(tree->root, 27) == NULL) {
		printf("key %d not found\n", 27);
	} else {
		printf("found node with key = %d\n", 27);
	}	
	printf("\n"); // spacer
	
/*search for 89 (does not exist), if statement to output wheather it was sccuessful or not*/
	if (searchRecursive(tree->root, 89) == NULL) {
		printf("key %d not found\n", 89);
	} else {
		printf("found node with key = %d\n", 89);
	}	
	
/*Bogner's end of program stuff*/
	freeTree(tree->root);
	free(tree);
   
    return 0;
}
