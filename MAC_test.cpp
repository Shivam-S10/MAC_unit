#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "ap_int.h"

typedef ap_uint<22> result_t;
typedef ap_uint<8> data_t;

void mac(data_t A[64], data_t B[64], result_t &X);

int main() {
    data_t A_test[64];
    data_t B_test[64];
    result_t hardware_X = 0;
    result_t expected_X = 0;

    srand(time(NULL)); 

    for (int i = 0; i < 64; i++) {
        A_test[i] = rand() % 256; 
        B_test[i] = rand() % 256; 
    }

    for (int i = 0; i < 64; i++) {
        expected_X = expected_X + (A_test[i] * B_test[i]);
    }

    mac(A_test, B_test, hardware_X);

    std::cout << "--- MAC Unit Testbench ---" << std::endl;
    std::cout << "Sample Inputs Sent:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "A[" << i << "]: " << A_test[i] 
                  << " \t B[" << i << "]: " << B_test[i] << std::endl;
    }
    std::cout << "... (and 60 more pairs)" << std::endl;

    std::cout << "\nVerification Result:" << std::endl;
    if (hardware_X == expected_X) {
        std::cout << "YES - MATCH! " << std::endl;
        std::cout << "Hardware Output: " << hardware_X << " | Expected: " << expected_X << std::endl;
        
        return 0; 
    } else {
        std::cout << "NO - MISMATCH! " << std::endl;
        std::cout << "Hardware Output: " << hardware_X << " | Expected: " << expected_X << std::endl;
        
        return 1; 
    }
}