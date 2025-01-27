#define DEBUG

#define ECG_DATA_LENGTH 361111
#define SAMPLE_RATE             200 //sampling frequency in Hz
#define ACLT_FIFO_SIZE           20 
#define RPEAK_HIST_FIFO_SIZE      8
#define NEC_THRESHOLD            19
#define BLOOM_FILTER_SIZE        16
#define RR_WINDOW_SIZE           32
#define MAXRR_VALUE             255
#define BLOOM_FILTER_SCALE        2
#define NUM_RR_BIN_ITEMS         35
#define NUM_DRR_BIN_ITEMS        30
#define BIN_INTERVAL_BW           3
#define RR_BIN_BW                 6
#define DRR_BIN_BW                5


#define NUM_SW_PREDICTED_LABELS   98