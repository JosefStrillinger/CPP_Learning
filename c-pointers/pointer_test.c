#include <stdio.h>

int main(){
    int a = 1;
    int *pointer_to_a = &a;

    /* let's change the variable a */
    a += 1;

    /* we just changed the variable again! */
    *pointer_to_a += 1;

    /* will print out 3 */
    printf("The value of a is now %d\n", a);
}