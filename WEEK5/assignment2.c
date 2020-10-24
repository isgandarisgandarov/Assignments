#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define STACK_CAPACITY 2 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack() 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = STACK_CAPACITY; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack) 
{ 
    free(stack->array);
    free(stack);
    printf("deallocated\n"); 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void resize(struct Stack* stack) 
{
    stack->capacity *= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        resize(stack);
    stack->array[++stack->top] = item; 
} 
  
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
}

int IsPair(char char1, char char2){
	if (char1 == '(' && char2 == ')') return 1;
	else if (char1 == '[' && char2 == ']') return 1;
	else if (char1 == '{' && char2 == '}') return 1;
	else return 0;
}

int IsBalanced(char string[]){
	int i = 0;
	struct Stack* stack = createStack();
	while (i < strlen(string)){
		if (string[i] == '(' || string[i] == '[' || string[i] == '{'){
		   push(stack, string[i]);
		}
		else if (string[i] == ')' || string[i] == ']' || string[i] == '}'){
			if(isEmpty(stack) || !IsPair(peek(stack), string[i])) return 0; 
			else pop(stack);
		}
		i++;
	}
	if(isEmpty(stack)) return 1;
	else return 0;
}

int main(int argc, char *argv[]){
	if (IsBalanced(argv[1])) printf("Yes\n");
	else printf("No\n");

}

