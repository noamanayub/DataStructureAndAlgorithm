#include<stdio.h>

/*
'x' and 'y' are two pointers that store the addresses of two variables, 'a' and 'b', respectively.
You cannot swap the values of 'a' and 'b' without using pointers because, in a regular function,
swapping only happens in the local scope of the 'swap' function. However, if you use pointers,
the function operates on the actual memory addresses of 'a' and 'b', allowing the values to be swapped
in the local variables of the 'main' function. This is because pointers hold the memory addresses of 'a' and 'b',
giving the 'swap' function direct access to their values in memory.
*/
void swap(int *x, int *y){ 
    int z; //its a local variable of swap function after function call complete execution this variable remove from memory 

    //code for swap variables
    z = *x; // z = 10
    *x = *y; // *x = 20
    *y = z; // *y = 10
}

int main(){
    int a = 10, b=20; //its a local variable of main body after complete execution this variable remove from memory
    printf("Before Function Call: a = %d, b = %d\n", a, b);
    swap(&a, &b); //it is taking address from variable and then pass to function swap
    printf("After Function Call: a = %d, b = %d", a, b);
}