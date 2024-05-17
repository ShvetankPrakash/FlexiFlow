#include <stdio.h>
#include "static_data.h"

#define DELAY 10000
#define PH_LOW 6.5
#define PH_HIGH 8.5

double read_sensor(int i) {
    return input_array[i];
}

void sensor_sleep() {
    for (int i = 0; i < DELAY; i++) {
        asm volatile("nop");
    }
}

// TODO: this function compiles into something like this:
// ------> Lots of unnecessary branches, loads and stores, not sure if this is retained in the binary
// ------> Should test with the target compiler stack, maybe it is easier to just write asm

//     .globl  _sensor_sleep                   ; -- Begin function sensor_sleep
//     .p2align    2
// _sensor_sleep:                          ; @sensor_sleep
//     .cfi_startproc
// ; %bb.0:
//     sub sp, sp, #16
//     .cfi_def_cfa_offset 16
//     str wzr, [sp, #12]
//     b   LBB1_1
// LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
//     ldr w8, [sp, #12]
//     mov w9, #10000
//     subs    w8, w8, w9
//     cset    w8, ge
//     tbnz    w8, #0, LBB1_4
//     b   LBB1_2
// LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
//     ; InlineAsm Start
//     nop
//     ; InlineAsm End
//     b   LBB1_3
// LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
//     ldr w8, [sp, #12]
//     add w8, w8, #1
//     str w8, [sp, #12]
//     b   LBB1_1
// LBB1_4:
//     add sp, sp, #16
//     ret
//     .cfi_endproc
//                                         ; -- End function

// TODO: With -O3 flag. Still there are subs/branches, is this expected in deployment or 
// -----> would there be other hardware for sleep/wake? Would we just want to essentially
// -----> eliminate any sleep operation in the benchmark workload?

// With -O3:
// _sensor_sleep:                          ; @sensor_sleep
//     .cfi_startproc
// ; %bb.0:
//     mov w8, #10000
// LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
//     ; InlineAsm Start
//     nop
//     ; InlineAsm End
//     subs    w8, w8, #1
//     b.ne    LBB1_1
// ; %bb.2:
//     ret
//     .cfi_endproc
//                                         ; -- End function

int predictions[SAMPLE_SIZE] = {0}; // is drinkable?

void run(int num_readings) {
    for (int i = 0; i < num_readings; i++) {
        double sensor_reading = read_sensor(i);
        if (sensor_reading >= 6.5 && sensor_reading <= 8.5) {
            predictions[i] = 1;
        }
        sensor_sleep();
    }
}

int main() {
    run(SAMPLE_SIZE);
    return 0;
}