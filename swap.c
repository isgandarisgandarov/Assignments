#include <stdio.h>


void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
int main() 
{ 
    int x, y;
    x = 7;
    y = 10;
    printf("Before Swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y); 
    printf("After Swapping: x = %d, y = %d\n", x, y); 
    return 0; 
} 
