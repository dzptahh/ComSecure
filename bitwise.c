#include <stdio.h>

// Bitwise AND using only ~ and |
int bitAnd(int x, int y) {
    return ~(~x | ~y); 
}

// Get nth byte from an integer
int getByte(int x, int n) {
    return (x >> (n * 8)) & 0xFF;  
}

// Logical right shift (shift zeros in)
int logicalShift(int x, int n) {
    return (x >> n) & ~((1 << (32 - n)) >> 1); 
}

// Check if there is an odd number of 1's
int odd_ones(unsigned x) {
    x = x ^ (x >> 1);
    x = x ^ (x >> 2);
    x = x ^ (x >> 4);
    x = x ^ (x >> 8);
    x = x ^ (x >> 16);
    return x & 1;  //
}

// Return the smallest negative number
int tmin() {
    return 1 << 31;
}

// Get the absolute value of a number
int abs_val(int x) {
    int mask = x >> 31; 
    return (x + mask) ^ mask; 
}

// Check if x is less than y
int lessThan(int x, int y) {
    return (((x + (~y)) >> 31) & 1); 
}

// Check if there's a 1 in any odd bit position
int oddBitOne(int x) {
    return (x & 0x55555555) != 0; 
}

int main() {
    // Store results
    int results[] = {
        bitAnd(6, 5),
        getByte(0x12345678, 1),
        logicalShift(0x87654321, 4),
        odd_ones(4),
        tmin(),
        abs_val(-9),
        lessThan(45, 172),
        oddBitOne(25)
    };

    // Store function names for printing
    const char *func_names[] = {
        "bitAnd(6, 5)",
        "getByte(0x12345678, 1)",
        "logicalShift(0x87654321, 4)",
        "odd_ones(4)",
        "tmin()",
        "abs_val(-9)",
        "lessThan(45, 172)",
        "oddBitOne(25)"
    };

    // Print results with separators
    for (int i = 0; i < 8; i++) {
        printf("%s = ", func_names[i]);
        
        if (i == 1 || i == 2) {
            printf("0x%x", results[i]);
        } else {
            printf("%d", results[i]); 
        }
        
        printf("\n");
        for (int j = 0; j < 35; j++) {
            printf("=");
        }
        printf("\n");
    }

    return 0;
}
