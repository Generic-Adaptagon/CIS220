// Ivan Escarciga
// Chpt4 PA
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the list itself
typedef struct List {
    Node* head;
    Node* tail;
} List;
Node* allocateNewNode(int item) ;void initList(List* list) ;
void ListAppendNode(List* list, Node* newNode) ;
void ListAppend(List* list, int item) ;
void ListPrependNode(List* list, Node* newNode) ;
void ListPrepend(List* list, int item) ;
Node* ListSearch(List *list, int key) ;
void ListInsertNodeAfter(List* list, Node* currentNode, Node* newNode) ;
int ListInsertAfter(List *list, int currentItem, int newItem) ;
void ListRemoveNodeAfter(List* list, Node* curNode) ;
int ListRemove(List *list, int itemToRemove) ;
void ListTraverse(List* list) ;
Node* ListFindInsertionPosition(List* list, int dataValue) ;
void ListInsertionSortSinglyLinked(List* list) ;
/*Added functions(may have gone overboard)*/
int sumDataValues(List* list) ;
void printList (List* list);
void findNode(List* list, int key);


// main function
int main() {
/*Initalize list and varaiables to help the list preform its neccessary functions*/
	struct List mainList = {NULL, NULL}; //creates List called mainList
	List* listPtr;//creates list pointer for main list
	listPtr = &mainList; //assigns pointer for passing MainList into functions.
	Node* newNodePtr; // node pointer for creating new nodes
	Node* currNodeptr; // a node pointer for passing a second node into a function
	newNodePtr = NULL;//assigns to Null to prevent SegFaults
	currNodeptr = NULL;//assigns to Null to prevent SegFaults
	int sum = 0; // for sum with no display functionality

	/*display the list*/
	printList(listPtr);
	
	/* Sum and display node values*/
	sum = sumDataValues(listPtr);
	printf("The sum of all nodes is: %d\n", sum);
	
    /*Append a node with a data value of 10, 20, and prepend 30 to the linked list*/
	ListAppend(listPtr, 10);
	ListAppend(listPtr, 20);
	ListPrepend(listPtr, 30);
	
    /*Insert a node with a data value of 40 after the head node in the linked list*/
		//use currNode as head for insertafter function.
	currNodeptr = listPtr->head; 
	ListInsertAfter(listPtr, currNodeptr->data, 40);
	
    /*Insert a node with a data value of 50 at the end of the linked list*/
	ListAppend(listPtr, 50);
	
    /*Insert a node with a data value of 60 after the node with a data value of 10 in the linked list*/
		//Use curnode as the data value 10 node to pass into listinsertafter function
	currNodeptr = ListSearch(listPtr, 10);
	ListInsertAfter(listPtr, currNodeptr->data, 60);
	
    /*Insert a node with a data value of 70 after the node with a data value of 40 in the linked list*/
		//Use curnode as the data value 40 node to pass into listinsertafter function
	currNodeptr = ListSearch(listPtr, 40);
	ListInsertAfter(listPtr, currNodeptr->data, 70);	
	
    /*Display the list*/
	printList(listPtr); 
	
	/*Remove the head node*/
		/*Use curnode as the data value before head node listRemoveNode function	*/
 	currNodeptr = NULL;
	ListRemoveNodeAfter(listPtr, currNodeptr);
	
    /*Remove the node after the node with a data value of 70*/
		//Use curnode as the data value of 70 fo listRemoveNodeafter function	
	currNodeptr = ListSearch(listPtr, 70);
	ListRemoveNodeAfter(listPtr, currNodeptr);
	
    /*Display the list
		printList(listPtr); 	
		
    /*Search for the node with a data value of 50 and display if it was found or not found*/
	findNode(listPtr, 50);

    /*Search for the node with a data value of 15 and display if it was found or not found*/
	findNode(listPtr, 15);
	
    /*Sort and display the list*/
	ListInsertionSortSinglyLinked(listPtr);//sort
	printf("Sorted ");
	printList(listPtr);//display
	
    /*Sum and display the sum of the node values*/
	sum = sumDataValues(listPtr);//use other function to get total
	/*print header*/
	printf("The sum of all nodes is: %d.\n", sum);
    return 0;
}

	
	/* this function finds the node with the specificed data value, using ListSearch, 
		and displays wheather it was found or not*/
void findNode(List* list, int key){
	/*creates node pointer to receive value from ListSearch*/
	Node* curNode;
	curNode = ListSearch(list, key);
	
	/*if found, print found. If not, print not found*/
	if (curNode != NULL){
		printf("Data node %d was found.\n", key);
	} else {
		printf("Data node %d was NOT found.\n", key);
	}
	return;
}// findNode

/*Prints the list header and new line; Uses ListTraverse ro print raw data values.*/
void printList (List* list){
	/*prints header*/
	printf("List: ");
	/*print raw list data*/
	ListTraverse(list);
	return;
}//printList

int sumDataValues(List* list) {
	int sum = 0;
	//set curr node to head node
	Node *curNode = list->head;
	/*while node has data*/
    while (curNode != NULL) {
    
        sum = sum + curNode->data; // adds data
        curNode = curNode->next; // moves to next node
    }
    return sum;

}//sum data values

/*end of custom functions*/

// Function to allocate memory for a new node and initialize it with data
Node* allocateNewNode(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty list
void initList(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to append a node to the list, pseudocode found in PA 4.2.6
void ListAppendNode(List* list, Node* newNode) {
	// If list is empty, new head and tail node
    if (list->head == NULL) {  
        list->head = newNode;
        list->tail = newNode;
	// list not empty, new tail node	
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to append an item to the list, pseudocode found in PA 4.2.6
void ListAppend(List* list, int item) {
	// Create node to add
    Node* newNode = allocateNewNode(item);
    ListAppendNode(list, newNode);
}

// Function to prepend a node to the list, pseudocode found in PA 4.2.9
void ListPrependNode(List* list, Node* newNode) {
	// If list is empty, new head and tail node
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
		// list not empty, new head node
        newNode->next = list->head;
        list->head = newNode;
    }
}

// Function to prepend an item to the list, pseudocode found in PA 4.2.9
void ListPrepend(List* list, int item) {
	// Create node to add
    Node* newNode = allocateNewNode(item);
    ListPrependNode(list, newNode);
}

// Function searches for a node with a specific data value, pseudocode found in PA 4.3.1 
Node* ListSearch(List *list, int key) {
    Node *curNode = list->head;
    while (curNode != NULL) {
        if (curNode->data == key) {
            return curNode;
        }
        curNode = curNode->next;
    }
    return NULL;
}

// Function to insert a node after a specific node in the list, pseudocode found in PA 4.3.4
void ListInsertNodeAfter(List* list, Node* currentNode, Node* newNode) {
    // If list is empy, new head and tail node
	if (list->head == NULL) {  
        list->head = newNode;
        list->tail = newNode;
	// Inserting after list's tail node, new tail node
    } else if (currentNode == list->tail) {
        list->tail->next = newNode;
        list->tail = newNode;
	// Inserting in middle of list
    } else {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

// Function to insert a new item after a specific item, pseudocode found in Figure 4.3.1
int ListInsertAfter(List *list, int currentItem, int newItem) {
	// Search for the node to insert after
    Node *currentNode = ListSearch(list, currentItem);    
    if (currentNode != NULL) {
        Node *newNode = allocateNewNode(newItem);
		// Call ListInsertNodeAfter method
        ListInsertNodeAfter(list, currentNode, newNode);
		// Success
        return 1; 
    }
	// Failure
    return 0; 
}

// Function to remove a node after a specific node in the list, pseudocode found in PA 4.4.1
void ListRemoveNodeAfter(List* list, Node* curNode) {
    Node* sucNode;
	// Special case, remove head
    if (curNode == NULL) {  // Special case, remove head
        sucNode = list->head->next;
        list->head = sucNode;
		// Removed last item
        if (sucNode == NULL) {  
            list->tail = NULL;
        }
	// Node exists after curNode
    } else if (curNode->next != NULL) {
        sucNode = curNode->next->next;
        curNode->next = sucNode;
		// Removed tail, set tail to curNode
        if (sucNode == NULL) {  
            list->tail = curNode;
        }
    }
}

// Function to remove a node with a specific data value, pseudocode found in Figure 4.4.1
int ListRemove(List *list, int itemToRemove) {
    Node *previous = NULL;
    Node *current = list->head;    
    while (current != NULL) {
        if (current->data == itemToRemove) {
			// Call ListRemoveNodeAfter method
            ListRemoveNodeAfter(list, previous);
            // Success
			return 1; 
        }
        previous = current;
        current = current->next;
    }
    // Not found
    return 0; 
}

// Function to traverse and print the list, pseudocode found in PA 4.8.1
void ListTraverse(List* list) {
	// Start at head
    Node* curNode = list->head;  
    while (curNode != NULL) {
		// Prints the node's data
        printf("%d -> ", curNode->data); 
        // Traverse to next node in the list		
        curNode = curNode->next;
    }
    printf("NULL\n");
}

// Function to find the insertion position for a data value, pseudocode found in figure 4.9.1 
Node* ListFindInsertionPosition(List* list, int dataValue) {
	// curNodeA keeps track of the node before the insertion position
    Node* curNodeA = NULL;
	// curNodeB starts at the head and traverses the list list
    Node* curNodeB = list->head;
	// Traverse the list until we find the correct insertion position
	// Stop when curNodeB is null (end of list) or dataValue is small than or equal to curNode
    while (curNodeB != NULL && dataValue > curNodeB->data) {
		// Move curNodeA to curNodeB (keeping track of previous node)
        curNodeA = curNodeB;
		// Move curNodeB to the next node
        curNodeB = curNodeB->next;
    }
	// Return curNodeA, which is the node after which the new value should be inserted
	// If curNodeA is null, it means the new value should be inserted at the head
    return curNodeA;
}

// Function to perform insertion sort on the list, pseudocode found in PA 4.9.1
void ListInsertionSortSinglyLinked(List* list) {
	// Initalize beforeCurrent to the head of the list
    Node* beforeCurrent = list->head;
	// Start curNode from the second node (if head is not null)
    Node* curNode = list->head ? list->head->next : NULL;
	// Traverse through the linked list
    while (curNode != NULL) {
		// Store the next node before manipulating curNode
        Node* next = curNode->next;
		// Find the correct position for curNode in the sorted portion of the list
        Node* position = ListFindInsertionPosition(list, curNode->data);
		// If curNode is already in the correct position, move beforeCurrent foward
        if (position == beforeCurrent) {
            beforeCurrent = curNode;
        } else {
			// Removes the curNode from its current position
            ListRemoveNodeAfter(list, beforeCurrent);
			// If position is null, curNode should be inserted at the beginning
            if (position == NULL) {
                ListPrependNode(list, curNode);
            } else {
				// Insert curNode after the found position
                ListInsertNodeAfter(list, position, curNode);
            }
        }
		// Move to the next node in the original list
        curNode = next;
    }
}
