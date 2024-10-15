#include<stdio.h>
int main(){
    int a = 20;
    int *p; //declare a pointer by using * operator
    p = &a; // store the address of a in pointer variable p

    /*
    For example: If Address of 'a' is '2001' and address of 'p' is '3001' and 'p' store 'a' address 
    its means 'p = 2001'. so, basically, 'p' pointing towards 'a' memory 'p -> a' 
    */

   printf("Address of a: %p",&a); //give address of 'p' using '&' operator
   printf("\nValue of a: %d",a); // print 'a' value that is '20' in this case
   printf("\nAddress of p: %p",&p); //print address of 'p'
   printf("\nValue of p: %p",p);  //print value of 'p' its mean address of 'a'
   printf("\nValue of p: %d",*p); // dereferencing the pointer its mean it print value of 'a' that is '20' in this case

    /*
    & sign used for printing address
    * used for printing value in printf and declare pointer-type in declaration
    both * and & at the same time print value. for example: *(&a)
    its mean if you have address in variable and you add * with variable it print "value at that address"
   */


}