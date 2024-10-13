#include<stdio.h>
int main(){
    int i = 10;
    char *ii;

    ii = (char*)&i; // Cast the address of i to a char pointer
    printf("%d\n", *ii);    // Dereferences the pointer to access the first byte
    printf("%d\n", ii[0]);  // Accesses the same byte using array-like notation
    // both printf statement print 10

}