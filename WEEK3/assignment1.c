#include <stdio.h>


void swapArrays(int a1[], int a2[], int len);           
void print2DArr(int *arr2D[], int rows, int columns);

int main() {
    
    int a1[] = {1,2,3,4,5};
    int a2[] = {0,0,0,0,0};
    int len = sizeof(a1)/sizeof(int);
    int *arr2D[2] = {a1,a2};
    
    print2DArr(arr2D, 2, len);
    swapArrays(a1, a2, len);
    print2DArr(arr2D, 2, len);
    
    return 0;
}


void swapArrays(int a1[], int a2[], int len){
    
    int temp[len];
    
    for(int i = 0; i < len; i++){
        temp[i] = a1[i];  			// a temporary array to store the elements of a1 in the process of swapping.
        a1[i] = a2[i];
        a2[i] = temp[i];
    }
}


void print2DArr(int *arr2D[], int rows, int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            
            if(j == columns - 1 && i == rows - 1) printf("%d\n", arr2D[i][j]); /* to be sure there is no space after the last element  */
            else printf("%d ", arr2D[i][j]);
        }
    }
}
