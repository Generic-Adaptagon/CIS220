//Ivan Escarciga
//Chpt6 PA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define structure to represent the key-value pair (Item)
typedef struct Item {
    char *key;  
    char *value;  
    struct Item *next;  
} Item;

// Define structure to represent the hash table
typedef struct HashTable {
    Item **hashTable;  
    int length;  
} HashTable;

// Function to create a new Item (key-value pair)
Item* createItem(char *key, char *value) {
    Item *newItem = (Item*)malloc(sizeof(Item));  
    newItem->key = strdup(key);  
    newItem->value = strdup(value);  
    newItem->next = NULL;  
    return newItem;
}

// Function to create a new hash table with a specified number of buckets
HashTable* createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));  
    table->length = size;  
    table->hashTable = (Item**)malloc(sizeof(Item*) * size);  

    for (int i = 0; i < size; i++) {
        table->hashTable[i] = NULL;  
    }
    return table;
}

// Hash function to compute the index for a given key
int hash(char *key) {
 
	int stringHash = 0; //  initial value set to 0 as specified

	/*loops through entire string until end character*/
	while (*key != '\0') {
		// mutiplyer set to 13 as instucted and character value added to stringHash
	stringHash = (stringHash * 13) + *key; 
		key++; //increment pointer
	}
	return stringHash; // returns non %'d integer;
}

// Function to insert a key-value pair into the hash table, pseudocode found in Figure 6.3.1
int hashInsert(HashTable *table, char *key, char *value) {
    int bucketIndex = hash(key) % table->length;
   
    Item *currentItem = table->hashTable[bucketIndex];
    Item *previousItem = NULL;

    while (currentItem != NULL) {
        if (strcmp(currentItem->key, key) == 0) {
            free(currentItem->value);
            currentItem->value = strdup(value);
            return 1;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->key = strdup(key);
    newItem->value = strdup(value);
    newItem->next = NULL;

    if (table->hashTable[bucketIndex] == NULL) {
        table->hashTable[bucketIndex] = newItem;
    } else {
        previousItem->next = newItem;
    }
    return 1;  
}

// Function to search for the specified key and return the corresponding value, pseudocode found in Figure 6.3.1
char *hashGet(HashTable *table, char *key) {
    int bucketIndex = hash(key) % table->length;
    

    Item *item = table->hashTable[bucketIndex];

    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        item = item->next;
    }
    return NULL;
}

// Function to remove the key-value pair from the hash table, pseudocode found in Figure 6.3.1 
int hashRemove(HashTable *table, char *key) {
    int bucketIndex = hash(key) % table->length;
    
    Item *currentItem = table->hashTable[bucketIndex];
    Item *previousItem = NULL;

    while (currentItem != NULL) {
        if (strcmp(currentItem->key, key) == 0) {
            if (previousItem == NULL) {
                table->hashTable[bucketIndex] = currentItem->next;
            } else {
                previousItem->next = currentItem->next;
            }
            free(currentItem->key);
            free(currentItem->value);
            free(currentItem);
            return 1;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }
    return 0;
}

// Function to print the contents of the hash table
// Update the function to display the hash for each key-value pair
void printTable(HashTable *table) {
    for (int i = 0; i < table->length; i++) {  
        printf("Bucket %d: ", i);  
        Item *currentItem = table->hashTable[i];  
        if (currentItem == NULL) {  
            printf("empty\n");  
        } else {
            while (currentItem != NULL) {  
                printf("[Hash is: %d, key is: %s, value is: %s] ", hash(currentItem->key), currentItem->key, /*added the hash as well */
					currentItem->value);  
                currentItem = currentItem->next;  
            }
            printf("\n");  
        }
    }
}

// Main function to test the hash table
// Implement the main function per the assignment instructions
int main() {
    // Create a hash table with 5 buckets
    HashTable *table = createHashTable(5);
/*hash inserts*/
	hashInsert(table, "keyA1", "value1");
	hashInsert(table, "keyB2", "value2");
	hashInsert(table, "keyC3", "value3");
	hashInsert(table, "keyD23", "value23");
	hashInsert(table, "keyE45", "value45");
	hashInsert(table, "keyF52", "value52");
	
/*prints table*/
	printf("HashTable contents:\n"); // header
	printTable(table);
	printf("\n"); // spacer
	
/*remove keyF52; print result by output of hashRemove*/
	if (hashRemove(table, "keyF52") ==0) {
		printf("Item keyF52 was NOT found\n");
		} else {
			printf("Item keyF52 was removed\n");
		}
	printf("\n"); // spacer
	
/*remove non-existant keyZ6; print result by output of hashRemove*/
		if (hashRemove(table, "keyZ6") ==0) {
		printf("Item keyZ6 was NOT found\n");
		} else {
			printf("Item keyZ6 was removed\n");
		}
	printf("\n"); // spacer
	
/*get existing key "keyC3"; output result based on hashGet()*/
	
		if (hashGet(table, "keyC3") == NULL) {
		printf("Item keyC3 does NOT exist\n");
		} else {
			printf("Item keyC3 was gotten\n");
		}
	printf("\n"); // spacer	
/*More insertions*/
	hashInsert(table, "keyG18", "value18");	
	hashInsert(table, "keyH7", "value7");	
	hashInsert(table, "keyI33", "value33");	
	
/*update "keyD23 with "newvalue23"*/
	hashRemove(table, "keyD23");
	hashInsert(table, "keyD23", "newvalue33");
	
/*display table*/
	printf("HashTable after inserts, removals, and update:\n"); // header
	printTable(table);
		
    for (int i = 0; i < table->length; i++) {
        Item *currentItem = table->hashTable[i];
        while (currentItem != NULL) {
            Item *temp = currentItem;
            currentItem = currentItem->next;
            free(temp->value);
            free(temp);
        }
    }

    free(table->hashTable);  
    free(table);  

    return 0;
}
