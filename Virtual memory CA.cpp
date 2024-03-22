#include <stdio.h>

#define PAGE_SIZE 1024
#define NUM_FRAMES 32

int main() {
    int page_table[PAGE_SIZE] = {0};

    int virtual_address;
    printf("Enter a virtual address (0 - %d): ", PAGE_SIZE - 1);
    scanf("%d", &virtual_address);

    while (virtual_address >= 0 && virtual_address < PAGE_SIZE) {
        int page_number = virtual_address / PAGE_SIZE;
        int offset = virtual_address % PAGE_SIZE;

        if (!page_table[page_number]) {
            printf("Fetching page %d from disk into frame %d\n", page_number, page_number % NUM_FRAMES);
            page_table[page_number] = 1;
        }

        int physical_address = (page_number % NUM_FRAMES) * PAGE_SIZE + offset;
        printf("Accessing physical address %d (frame %d, offset %d)\n", physical_address, page_number % NUM_FRAMES, offset);

        printf("Enter another virtual address (or a negative number to exit): ");
        scanf("%d", &virtual_address);
    }

    return 0;
}

