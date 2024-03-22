#include <stdio.h>

// Define the size of the ROM
#define ROM_SIZE 10

// Define the ROM data (example data)
int rom[ROM_SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

int main() {
    int address;

    printf("Enter the address (0 to %d) to read from the ROM: ", ROM_SIZE - 1);
    scanf("%d", &address);

    // Check if the entered address is valid
    if (address >= 0 && address < ROM_SIZE) {
        printf("Data at address %d: %d\n", address, rom[address]);
    } else {
        printf("Invalid address! Please enter a valid address between 0 and %d\n", ROM_SIZE - 1);
    }

    return 0;
}

