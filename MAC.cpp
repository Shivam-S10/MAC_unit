#include <stdio.h>
#include "ap_int.h"
typedef ap_uint<22> result_t;
typedef ap_uint<8> data_t;
void mac(data_t A[64], data_t B[64] , result_t &X){
    #pragma HLS ARRAY_PARTITION variable =A complete
    #pragma HLS ARRAY_PARTITION variable =B complete
    X=0; 
    #pragma HLS PIPELINE II=1 
    for (int i=0; i<64; i++) {
        #pragma HLS UNROLL
        X= X+ A[i]*B[i]; 
    }   
}