// Static data array below are populated from the PlasticArmpit real dataset consisting of 179 samples

#define Num_Data_Samples 56


// Define sensor input vectors based on the provided dataset
const volatile double Temp_Sensor_Input_Vector[Num_Data_Samples] = {
    18, 22, 23, 22, 22, 25, 22, 22, 18, 23, 18, 22, 20, 20, 23, 21, 19, 22, 22, 19, 22, 21, 19, 19, 19, 19, 22, 20, 21, 20, 22, 21, 20, 22, 19, 18, 22, 23, 20, 20, 22, 20, 21, 19, 22, 21, 20, 19, 23, 23, 19, 19, 19, 21, 19, 21
};

const volatile double Humidity_Sensor_Input_Vector[Num_Data_Samples] = {
    58, 55, 68, 55, 53, 60, 55, 58, 59, 58, 55, 55, 60, 58, 59, 57, 55, 55, 60, 55, 55, 58, 55, 58, 55, 55, 55, 58, 55, 55, 55, 55, 58, 55, 55, 58, 55, 58, 55, 55, 55, 55, 58, 55, 55, 58, 55, 58, 58, 55, 55, 55, 55, 58, 55, 58
};

const volatile double CO2_Sensor_Input_Vector[Num_Data_Samples] = {
    410, 399, 399, 419, 400, 399, 399, 399, 400, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399, 399
};

const volatile double Days_Sensor_Input_Vector[Num_Data_Samples] = {
    5, 6, 4, 6, 5, 6, 5, 4, 5, 6, 4, 5, 5, 4, 5, 5, 4, 6, 6, 4, 6, 5, 4, 4, 4, 4, 5, 4, 5, 4, 5, 4, 4, 6, 4, 5, 4, 6, 5, 4, 6, 4, 5, 4, 6, 5, 4, 4, 6, 6, 4, 4, 4, 5, 4, 5
};

const volatile char Spoiled_Reference[Num_Data_Samples] = {
    0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1
};
