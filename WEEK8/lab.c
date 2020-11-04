#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data[256];
    struct Node *next;
};

void luckyCustomer(struct Node** head_ref, char *key){
    struct Node *temp = (*head_ref), *prev;

    if(temp != NULL && strcmp(temp->data, key) == 0){
        *head_ref = temp->next;
    }else {
        while (temp != NULL && strcmp(temp->data, key) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("There is no such customer.\n");
            return;
        }
        prev->next = temp->next;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    strcpy(new_node->data, temp->data);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    free(temp);
    temp = NULL;
}

void admit(struct Node **head_ref){
    if (*head_ref == NULL){
        printf("The queue is empty.\n");
        return;
    }
    struct Node* next_node = (*head_ref)->next;
    printf("%s was admitted\n", (*head_ref)->data);
    free(*head_ref);
	
    *head_ref = next_node;
}

void append(struct Node **head_ref, char *key){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    strcpy(new_node->data, key);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node *node){
    printf("Queue: ");
    while(node != NULL){
    	if (node -> next == NULL) printf("%s", node -> data); //not to put comma after the last element.
        else printf("%s, ", node->data);
        node = node->next;
        
    }
    printf("\n");
}

void deleteList(struct Node** head_ref){   //Freeing dynamically allocated memory
	struct Node* current = *head_ref, *next;

	while (current != NULL){
		next = current -> next;
		free(current);
		current = next;
	}

	*head_ref = NULL;
}

int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->data, "Isgandar");
    head->next = NULL;
    append(&head, "Arif");
    append(&head, "Kamil");
    append(&head, "Qabil");
    append(&head, "Fuad");
    printList(head);
    char input[256];
    bool quit = 0;
    while(!quit){
        printf("\n");
        printf("Enter a command:");
        scanf("%s", input);
        if(strcmp(input, "quit") == 0) quit = 1;
        else if(strcmp(input, "admit") == 0){
            admit(&head);
        }else{
            luckyCustomer(&head, input);
        }
        printList(head);
    }
    deleteList(&head); //freeing dynamically allocated memory

    return 0;
}
