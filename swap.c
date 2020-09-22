#include <stdio.h>


void swap(int x, int y) 
{ 
    printf("Before Swapping: x = %d, y = %d\n", x, y);
    int temp = x; 
    x = y; 
    y = temp;
    printf("After Swapping: x = %d, y = %d\n", x, y);
} 
  
int main() 
{ 
    int x, y;
    x = 7;
    y = 10;
    swap(x, y); 
    return 0; 
} 
