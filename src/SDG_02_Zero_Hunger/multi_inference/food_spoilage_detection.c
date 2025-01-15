#include "sample_data.h"
// #include <stdio.h>

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  
int correct = 0;

// Function to predict whether a fruit is spoiled based on the decision tree
char Predict_Spoiled(char Days, char Fruit_Litchi, short CO2, char Fruit_Plum, char Temp, char Humidity, char Fruit_Grapes, char Fruit_Apple, char Fruit_Lemon, char Fruit_Mango, char Fruit_Tomato, char Fruit_Papaya) {
    char predicted_class;

    if (Days <= 4) {
        if (Fruit_Litchi == 0) {
            if (CO2 <= 407) {
                if (Fruit_Plum == 0) {
                    predicted_class = 0;
                } else {
                    if (Temp <= 22) {
                        predicted_class = 0;
                    } else {
                        if (Days <= 3) {
                            predicted_class = 0;
                        } else {
                            predicted_class = 1;
                        }
                    }
                }
            } else {
                if (Humidity <= 66) {
                    predicted_class = 0;
                } else {
                    if (Days <= 3) {
                        predicted_class = 0;
                    } else {
                        predicted_class = 1;
                    }
                }
            }
        } else {
            if (Days <= 2) {
                predicted_class = 0;
            } else {
                if (Temp <= 20) {
                    predicted_class = 0;
                } else {
                    if (Temp <= 23) {
                        if (Days <= 3) {
                            if (CO2 <= 398) {
                                predicted_class = 1;
                            } else {
                                predicted_class = 0;
                            }
                        } else {
                            predicted_class = 1;
                        }
                    } else {
                        predicted_class = 1;
                    }
                }
            }
        }
    } else {
        if (Days <= 18) {
            if (Temp <= 22) {
                if (Days <= 5) {
                    if (Fruit_Litchi == 0) {
                        if (Fruit_Plum == 0) {
                            if (Fruit_Grapes == 0) {
                                predicted_class = 0;
                            } else {
                                if (Humidity <= 60) {
                                    predicted_class = 1;
                                } else {
                                    predicted_class = 0;
                                }
                            }
                        } else {
                            if (Temp <= 20) {
                                predicted_class = 0;
                            } else {
                                predicted_class = 1;
                            }
                        }
                    } else {
                        predicted_class = 1;
                    }
                } else {
                    if (Fruit_Apple == 0) {
                        if (Fruit_Mango == 0) {
                            if (Days <= 6) {
                                if (Humidity <= 53) {
                                    predicted_class = 0;
                                } else {
                                    if (Fruit_Lemon == 0) {
                                        if (CO2 <= 419) {
                                            if (Humidity <= 58) {
                                                predicted_class = 1;
                                            } else {
                                                predicted_class = 0;
                                            }
                                        } else {
                                            predicted_class = 0;
                                        }
                                    } else {
                                        predicted_class = 0;
                                    }
                                }
                            } else {
                                if (Humidity <= 55) {
                                    predicted_class = 1;
                                } else {
                                    if (Temp <= 18) {
                                        if (Days <= 7) {
                                            predicted_class = 0;
                                        } else {
                                            if (CO2 <= 400) {
                                                predicted_class = 1;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        }
                                    } else {
                                        if (Fruit_Lemon == 0) {
                                            predicted_class = 1;
                                        } else {
                                            if (Humidity <= 70) {
                                                predicted_class = 0;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (Days <= 11) {
                                predicted_class = 0;
                            } else {
                                predicted_class = 1;
                            }
                        }
                    } else {
                        predicted_class = 0;
                    }
                }
            } else {
                if (Days <= 5) {
                    if (Fruit_Tomato == 0) {
                        if (CO2 <= 399) {
                            if (Humidity <= 59) {
                                predicted_class = 0;
                            } else {
                                predicted_class = 1;
                            }
                        } else {
                            predicted_class = 1;
                        }
                    } else {
                        if (Temp <= 25) {
                            predicted_class = 0;
                        } else {
                            predicted_class = 1;
                        }
                    }
                } else {
                    if (Humidity <= 53) {
                        predicted_class = 1;
                    } else {
                        if (Days <= 15) {
                            if (Fruit_Papaya == 0) {
                                if (Days <= 6) {
                                    predicted_class = 0;
                                } else {
                                    if (Humidity <= 69) {
                                        if (Fruit_Apple == 0) {
                                            if (Days <= 10) {
                                                predicted_class = 0;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        } else {
                                            predicted_class = 0;
                                        }
                                    } else {
                                        if (Days <= 10) {
                                            predicted_class = 1;
                                        } else {
                                            if (Days <= 13) {
                                                predicted_class = 0;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                predicted_class = 1;
                            }
                        } else {
                            if (Humidity <= 62) {
                                if (Days <= 17) {
                                    predicted_class = 0;
                                } else {
                                    predicted_class = 1;
                                }
                            } else {
                                predicted_class = 1;
                            }
                        }
                    }
                }
            }
        } else {
            predicted_class = 1;
        }
    }

    return predicted_class;
}

// Read the sensor values from the data samples and run the DTs to make predictions
// Compare the predicted class made by this model to the predicted class made by the Python model for equivalence check
char Read_Sensor_Values_Run_DTs() {
    char GPIO = 1;
    for (unsigned short data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
        char Days = Days_Vector[data_sample];
        char Temp = Temp_Vector[data_sample];
        char Humidity = Humidity_Vector[data_sample];
        short CO2 = CO2_Vector[data_sample];
        char Fruit_Apple = Fruit_Apple_Vector[data_sample];
        char Fruit_Banana = Fruit_Banana_Vector[data_sample];
        char Fruit_Grapes = Fruit_Grapes_Vector[data_sample];
        char Fruit_Jackfruit = Fruit_Jackfruit_Vector[data_sample];
        char Fruit_Lemon = Fruit_Lemon_Vector[data_sample];
        char Fruit_Litchi = Fruit_Litchi_Vector[data_sample];
        char Fruit_Mango = Fruit_Mango_Vector[data_sample];
        char Fruit_Papaya = Fruit_Papaya_Vector[data_sample];
        char Fruit_Plum = Fruit_Plum_Vector[data_sample];
        char Fruit_Tomato = Fruit_Tomato_Vector[data_sample];

        char python_predicted_class = Spoiled_Vector[data_sample];
        char c_predicted_class = Predict_Spoiled(Days, Fruit_Litchi, CO2, Fruit_Plum, Temp, Humidity, Fruit_Grapes, Fruit_Apple, Fruit_Lemon, Fruit_Mango, Fruit_Tomato, Fruit_Papaya);

        if (python_predicted_class != c_predicted_class) {
            GPIO = 0;
        } else {
            correct++;
        }
    }

    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_DTs();
    // printf("Correct: %d\n", correct);
    return 0;
}
