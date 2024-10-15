#include<stdio.h>
int main(){
    float a = 7.99999;
    float *b, *c;
    b = &a;
    c = b;
    printf("\n %u  %u  %u ",&a,b,c);
    printf("\n %d  %d  %d  %d",a ,*(&a), *b, *c); //unpredictable answer
    printf("\n %f  %f  %f  %f", a, *(&a), *b, *c); // Correct format specifiers
    /*
    The values of a, *(&a), *b, and *c are all of type float, but since you are using %d, which expects an int, 
    the program will interpret the bits of the float values incorrectly, leading to unpredictable output. 
    The actual values in memory for float may not correspond meaningfully when read as int.
    */
}
