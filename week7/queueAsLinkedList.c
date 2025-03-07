//Ivan Escarciga
//Chpt5 PA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node structure for each element in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue structure to represent the queue implemented as a linked list
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create and initialize an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue operation: adds an item to the end of the queue, pseudocode found in PA 5.5.1
void enqueue(Queue* queue, int item) {
    // Allocate new node and assign data (newNode->next is set to NULL)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
	// Set the node's member values
    newNode->data = item;
    newNode->next = NULL;
    
    if (queue->front == NULL) {
        // If the queue is empty, set front to the new node
        queue->front = newNode;
    } else {
        // Otherwise, link the new node at the end of the queue
        queue->rear->next = newNode;
    }
    // Update the rear pointer to the new node
    queue->rear = newNode;
}

// Dequeue operation: removes and returns the item from the front of the queue, pseudocode found in PA 5.5.1
int dequeue(Queue* queue) {
	// If queue is empty return -1 (assuming only positive integers will be added) 
    if (queue->front == NULL) {
        return -1;
    }
    // Save the data from the front node and move the front pointer
    Node* temp = queue->front;
    int dequeuedItem = temp->data;
    queue->front = temp->next;
    // If the queue becomes empty, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
	// free memory for the dequeued node
    free(temp); 
    return dequeuedItem;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
	
	/*if Queue's first pointer points to null, There is nothing in the queue*/
	if(queue->front == NULL) {
		return true;
	}
	
	return false; // if there is something return true
	}

// Function to peek at the front item without removing it
int peek(Queue* queue) {
	/*if the data of the first Item is not Null, return the data*/
		if(&queue->front->data != NULL) {
		return queue->front->data;
	} else { // if it is Null return 0
		return 0;
	}
}

// Function to get the length of the queue
int getLength(Queue* queue) {
	int count = 0; // counting variable
	Node* test; // pointer for data checking
	test = queue->front; // sets to first node
	
	/*While Data is Not NULL increase count*/
	while (&test->data != NULL) {
		test = test->next; // increment to next Node 
		count++;
	}// while

		return count;
}

// Function to traverse and display the queue
void displayQueue(Queue* queue) {
	Node* test; // pointer for data displaying
	test = queue->front; // sets to first node
	
	/*While Data is Not NULL print data*/
	while (&test->data != NULL) {
		printf("%d -> ", test->data );
		test = test->next; // increment to next Node 
	}// while
	
	printf("NULL\n"); // Prints NULL and finishes statment with new line
		return;
}

void dequeueAndDisplay (Queue* queue) {
	int item = 0; // used for displaying the dequed item
	item = dequeue(queue);
	if (item == -1) {
		printf ("An item was NOT dequeue.\n");
	} else {
	printf ("Item %d was removed from the queue.\n", item);
	}
	return;
}

int main() {
    Queue* queue = createQueue();
	int item = 0; // used to display items from the queue
    
/*    Display the queue.*/
	displayQueue(queue);
/*2. Call isEmpty to display if the queue is empty.*/
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
	} else {
		printf("The queue is NOT empty.\n");
	}
/*3. Call peek and display the top item in the queue.*/
		if (isEmpty(queue)) {
		printf("The queue is empty.\n");
	} else {
	printf("The top of the queue is %d\n", peek(queue));
	}
/*4. Display the queue’s length.*/
	printf("The queue's length is %d\n", getLength(queue));
/*5/6. Enqueue item 1 and 2 to queue.*/
	enqueue(queue, 1);
	enqueue(queue, 2);
/*7. Call peek and display the top item in the queue.*/
	printf("The top of the queue is %d\n", peek(queue));
/*8. Enqueue item 3 to queue.*/
	enqueue(queue, 3);
/*9. Display the queue’s length.*/
	printf("The queue's length is %d\n", getLength(queue));
/*10.Dequeue an item from the queue and display the item’s value.*/
	dequeueAndDisplay(queue);
/*11.Call peek and display the top item in the queue.*/
	printf("The top of the queue is %d\n", peek(queue));
/*12.Enqueue item 4 to queue.*/
	enqueue(queue, 4);
/*13.Display the queue.*/
	displayQueue(queue);
/*14.Enqueue item 5 to queue.*/
	enqueue(queue, 5);
/*15.Dequeue an item from the queue and display the item’s value.*/
	dequeueAndDisplay(queue);
/*16.Enqueue item 6 to queue.*/
	enqueue(queue, 6);
/*17.Display the queue’s length.*/
	printf("The queue's length is %d\n", getLength(queue));
/*18.Display the queue.*/
	displayQueue(queue);
/*19.Dequeue an item from the queue and display the item’s value.*/
	dequeueAndDisplay(queue);
/*20.Call isEmpty to display if the queue is empty.*/
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
	} else {
		printf("The queue is NOT empty.\n");
	}
/*21/22.Dequeue an item from the queue and display the item’s value.x2*/
	dequeueAndDisplay(queue);
	dequeueAndDisplay(queue);
/*23.Display the queue’s length.*/
	printf("The queue's length is %d\n", getLength(queue));
/*24/25.Dequeue an item from the queue and display the item’s value.x2*/
	dequeueAndDisplay(queue);
	dequeueAndDisplay(queue);
/*26.Call isEmpty to display if the queue is empty*/
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
	} else {
		printf("The queue is NOT empty.\n");
	}
    // Free the queue structure (all nodes should have been dequeued by now)
    free(queue);
    
    return 0;
}
