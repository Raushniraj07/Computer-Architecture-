#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 256 // Define cache size in bytes
#define MAIN_MEMORY_SIZE 1024 // Define main memory size in bytes

// Cache structure
typedef struct {
    int valid; // Valid bit to indicate whether the cache block contains valid data
    int tag;   // Tag bits for identifying the memory block
    int data;  // Data stored in the cache block
} CacheBlock;

// Function to simulate cache access
void accessCache(int address, CacheBlock *cache) {
    int cacheIndex = address % CACHE_SIZE; // Calculate cache index
    int tag = address / CACHE_SIZE;        // Calculate tag bits

    // Check if cache block is valid and contains the required data
    if (cache[cacheIndex].valid && cache[cacheIndex].tag == tag) {
        printf("Cache hit! Data found at address %d\n", address);
    } else {
        // Cache miss scenario
        printf("Cache miss! Data not found at address %d\n", address);
        // Load data from main memory to cache
        cache[cacheIndex].valid = 1;
        cache[cacheIndex].tag = tag;
        cache[cacheIndex].data = address; // For simplicity, storing the address as data
    }
}

int main() {
    CacheBlock cache[CACHE_SIZE]; // Cache memory
    int memory[MAIN_MEMORY_SIZE]; // Main memory

    // Initialize cache and main memory
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = 0;
        cache[i].tag = 0;
        cache[i].data = 0;
    }
    for (int i = 0; i < MAIN_MEMORY_SIZE; i++) {
        memory[i] = i; // Initialize main memory with sequential data
    }

    int address;

    // Taking input for memory address
    printf("Enter the memory address to access (0 - %d): ", MAIN_MEMORY_SIZE - 1);
    scanf("%d", &address);

    // Accessing cache with the given memory address
    accessCache(address, cache);

    return 0; // Exiting the program successfully
}

