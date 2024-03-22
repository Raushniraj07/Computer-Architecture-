#include <stdio.h>

// Structure representing a bus
typedef struct {
    int data;
    int address;
} Bus;

// Structure representing a CPU
typedef struct {
    Bus *bus;
} CPU;

// Structure representing a Memory
typedef struct {
    Bus *bus;
    int data[100]; // For simplicity, assuming memory size of 100 locations
} Memory;

// Structure representing an I/O Device
typedef struct {
    Bus *bus;
} IO_Device;

// Function to read data from memory
int memory_read(Memory *mem, int address) {
    return mem->data[address];
}

// Function to write data to memory
void memory_write(Memory *mem, int address, int data) {
    mem->data[address] = data;
}

// Function to perform CPU operation (read from memory)
int cpu_operation(CPU *cpu, Memory *mem, int address) {
    return memory_read(mem, address);
}

// Function to perform I/O device operation (write to memory)
void io_device_operation(IO_Device *device, Memory *mem, int address, int data) {
    memory_write(mem, address, data);
}

int main() {
    // Initialize buses, CPU, memory, and I/O device
    Bus data_bus;
    Bus io_bus;
    CPU cpu;
    Memory memory;
    IO_Device io_device;

    // Set bus pointers
    cpu.bus = &data_bus;
    memory.bus = &data_bus;
    io_device.bus = &io_bus;

    // Write data to memory
    memory_write(&memory, 0, 10); // Writing value 10 at address 0

    // CPU reads data from memory
    int data_read = cpu_operation(&cpu, &memory, 0);
    printf("Data read by CPU: %d\n", data_read);

    // I/O device writes data to memory
    io_device_operation(&io_device, &memory, 1, 20); // Writing value 20 at address 1

    // CPU reads updated data from memory
    data_read = cpu_operation(&cpu, &memory, 1);
    printf("Data read by CPU after I/O operation: %d\n", data_read);

    return 0;
}

