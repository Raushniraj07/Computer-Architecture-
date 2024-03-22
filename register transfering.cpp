#include <stdio.h>
int main() {
    // Define two variables
    int a = 5;
    int b;

    // Transfer data from variable 'a' to variable 'b' using a register
    b = a;

    // Print the result
    printf("Value of b after register transfer: %d\n", b);

    return 0;
}

