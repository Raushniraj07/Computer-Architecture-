
#include <stdio.h>

// Structure representing an instruction
typedef struct {
    int opcode;
    int operand1;
    int operand2;
} Instruction;

// Function to simulate instruction fetch stage
void fetch_stage(int *instruction_count, Instruction *instruction_buffer) {
    // Simulating fetching instructions from memory
    // Increment instruction count
    (*instruction_count)++;
    // Simulating instruction decoding and filling instruction buffer
    instruction_buffer->opcode = (*instruction_count) % 3;  // Example: alternating opcodes
    instruction_buffer->operand1 = (*instruction_count) * 2;
    instruction_buffer->operand2 = (*instruction_count) * 2 + 1;
}

// Function to simulate instruction execution stage
void execute_stage(Instruction *instruction_buffer, int *result) {
    // Simulating instruction execution
    switch (instruction_buffer->opcode) {
        case 0:
            *result = instruction_buffer->operand1 + instruction_buffer->operand2;
            break;
        case 1:
            *result = instruction_buffer->operand1 - instruction_buffer->operand2;
            break;
        case 2:
            *result = instruction_buffer->operand1 * instruction_buffer->operand2;
            break;
        default:
            printf("Invalid opcode\n");
            break;
    }
}

int main() {
    int instruction_count = 0;
    Instruction current_instruction;
    int execution_result;

    // Perform multiple cycles of instruction fetch and execution
    for (int i = 0; i < 5; i++) { // Example: 5 cycles
        // Instruction fetch stage
        fetch_stage(&instruction_count, &current_instruction);

        // Instruction execution stage
        execute_stage(&current_instruction, &execution_result);

        // Output the result of the executed instruction
        printf("Cycle %d: Result = %d\n", i + 1, execution_result);
    }

    return 0;
}

