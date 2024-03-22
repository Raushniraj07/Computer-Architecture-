#include <stdio.h>
#include <stdint.h>

// Function to perform restoring division
int restoring_division(int16_t dividend, int16_t divisor, int16_t *quotient, int16_t *remainder) {
    int16_t q = 0, r = 0; // Initialize quotient and remainder
    int16_t neg_divisor = -divisor; // Negative divisor

    for (int i = 0; i < 16; i++) {
        r = (r << 1) | ((dividend >> 15) & 1); // Shift remainder left and add next bit of dividend
        dividend <<= 1; // Shift dividend left
        r -= divisor; // Subtract divisor from the remainder

        if (r < 0) { // If remainder is negative, add divisor back and set quotient bit to 0
            q = (q << 1) | 0;
            r += divisor;
        } else { // If remainder is non-negative, set quotient bit to 1
            q = (q << 1) | 1;
        }
    }

    *quotient = q; // Store quotient
    *remainder = r; // Store remainder

    return 0; // Indicate success
}

int main() {
    int16_t dividend, divisor, quotient, remainder;

    // Input dividend and divisor
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Perform restoring division
    int result = restoring_division(dividend, divisor, &quotient, &remainder);

    // Output quotient and remainder if division is successful
    if (result == 0) {
        printf("Quotient: %d\n", quotient);
        printf("Remainder: %d\n", remainder);
    } else {
        printf("Error occurred during division.\n");
    }

    return 0;
}

