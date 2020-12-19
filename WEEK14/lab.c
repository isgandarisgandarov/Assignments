#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
    bool swapped;
};


void append(struct Node** head_ref, int new_data);

int check_swap(struct Node **head_ref, int data);

int swap(struct Node** head_ref, int data);

void printList(struct Node *head);

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;

    char input[250];
    int data;
    bool quit;
    printf("Enter numbers to add to your list: \n");

    while (!quit){
        scanf("%s", input);
        if (strcmp(input, "DONE") == 0) quit = 1;

        else{
            data = atoi(input);
            append(&head, data);
        }
    }
    printList(head);
    quit = 0;
    printf("Type a number to swap them around: \n");
    while(!quit){
        scanf("%s", input);
        if (strcmp(input, "DONE") == 0) quit = 1; 

        else{
            data = atoi(input);
            
            if (!check_swap(&head, data)){
                printf("No swap candidates found. Try again: \n");
                continue;
            }
            else if (check_swap(&head, data)){
                swap(&head, data);
                printf("result: ");
                printList(head);
            }
        }
    }
    free(head);
}

void append(struct Node** head_ref, int new_data){ 

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  
    struct Node *last = *head_ref;
    new_node->data = new_data; 
  
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    while (last->next != NULL) 
        last = last->next; 
   
    last->next = new_node; 
    return;     
}

int check_swap(struct Node **head_ref, int data){
    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    while (current && current->data != data){
        prev = current;
        current = current->next;
    }
    
    struct Node *second = current->next;
    struct Node *prev2 = current;
    if (current == NULL || second == NULL  || current->swapped == 1 || second->swapped == 1){
        return 0;
    }
    return 1;
}

int swap(struct Node** head_ref, int data){
    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    while (current && current->data != data){
        prev = current;
        current = current->next;
    }
    
    struct Node *second = current->next;
    struct Node *prev2 = current;	
    if (prev != NULL) prev->next = second;
    else *head_ref = second;
    
    if (prev2 != NULL) prev2->next = current;
    else *head_ref = current;
    
    struct Node *temp = second->next;
    second->next = current->next;
    current->next = temp;
    
    current->swapped = 1;
    second->swapped = 1;
    
    return 1;
}

void printList(struct Node *head){
    struct Node *temp = head->next;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

