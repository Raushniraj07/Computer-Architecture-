#include <stdio.h>
#include <stdint.h>

// Function to perform non-restoring division
int non_restoring_division(int16_t dividend, int16_t divisor, int16_t *quotient, int16_t *remainder) {
    // Initializing quotient and remainder
    *quotient = 0;
    *remainder = 0;

    // Sign bit for quotient
    int16_t sign_bit = dividend ^ divisor;
    
    // Making both dividend and divisor positive
    if (dividend < 0)
        dividend = -dividend;
    if (divisor < 0)
        divisor = -divisor;
    
    // Loop to perform division
    for (int i = 15; i >= 0; i--) {
        *remainder = (*remainder << 1) | ((dividend >> i) & 1); // Left shift remainder and add next bit of dividend
        *quotient = (*quotient << 1); // Left shift quotient

        // If remainder is greater than or equal to divisor, subtract divisor from remainder
        if (*remainder >= divisor) {
            *remainder -= divisor;
            *quotient |= 1; // Set quotient bit to 1
        } else {
            *quotient &= ~1; // Set quotient bit to 0
        }
    }

    // Restoring sign of quotient
    if (sign_bit < 0)
        *quotient = -(*quotient);

    return *remainder == 0 ? 0 : 1; // Return 0 if successful, 1 if there's a remainder
}

int main() {
    int16_t dividend, divisor, quotient, remainder;

    // Input dividend and divisor
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Perform non-restoring division
    int result = non_restoring_division(dividend, divisor, &quotient, &remainder);

    // Output quotient and remainder if division is successful
    if (result == 0) {
        printf("Quotient: %d\n", quotient);
        printf("Remainder: %d\n", remainder);
    } else {
        printf("Error occurred during division.\n");
    }

    return 0;
}

