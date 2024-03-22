#include <stdio.h>

// Function to perform Booth's multiplication algorithm
int boothMultiplication(int m, int q) {
    int ac = 0; // Accumulator (16 bits in this example)
    int q0 = 0; // Previous value of the least significant bit of Q
    int counter = 4; // Number of iterations, assuming a 4-bit multiplier

    while (counter > 0) {
        // Check the two least significant bits of q
        int q1 = q & 1;
        int q2 = (q >> 1) & 1;

        if (q1 == 1 && q0 == 0) {
            ac = ac + m;
        } else if (q1 == 0 && q0 == 1) {
            ac = ac - m;
        }

        // Arithmetic shift right A and Q
        q = (q >> 1) | (q2 << 3);
        ac = (ac >> 1) | ((ac & 1) << 15);

        // Update previous value of q0
        q0 = q1;

        // Decrement counter
        counter--;
    }

    return ac;
}

int main() {
    int m, q;
    printf("Enter the multiplier (m): ");
    scanf("%d", &m);
    printf("Enter the multiplicand (q): ");
    scanf("%d", &q);

    int result = boothMultiplication(m, q);
    printf("Result of multiplication: %d\n", result);

    return 0;
}

