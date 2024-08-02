#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  

// Function to predict whether a fruit is spoiled based on the decision tree
char Predict_Spoiled(char Days, char Fruit_Litchi, char CO2, char Fruit_Plum, char Temp, char Humidity, char Fruit_Grapes, char Fruit_Apple, char Fruit_Lemon, char Fruit_Mango, char Fruit_Tomato, char Fruit_Papaya) {
    char predicted_class;

    if (Days <= 4.50) {
        if (Fruit_Litchi <= 0.50) {
            if (CO2 <= 407.50) {
                if (Fruit_Plum <= 0.50) {
                    predicted_class = 0;
                } else {
                    if (Temp <= 22.50) {
                        predicted_class = 0;
                    } else {
                        if (Days <= 3.50) {
                            predicted_class = 0;
                        } else {
                            predicted_class = 1;
                        }
                    }
                }
            } else {
                if (Humidity <= 66.50) {
                    predicted_class = 0;
                } else {
                    if (Days <= 3.50) {
                        predicted_class = 0;
                    } else {
                        predicted_class = 1;
                    }
                }
            }
        } else {
            if (Days <= 2.50) {
                predicted_class = 0;
            } else {
                if (Temp <= 20.00) {
                    predicted_class = 0;
                } else {
                    if (Temp <= 23.50) {
                        if (Days <= 3.50) {
                            if (CO2 <= 398.00) {
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
        if (Days <= 18.50) {
            if (Temp <= 22.50) {
                if (Days <= 5.50) {
                    if (Fruit_Litchi <= 0.50) {
                        if (Fruit_Plum <= 0.50) {
                            if (Fruit_Grapes <= 0.50) {
                                predicted_class = 0;
                            } else {
                                if (Humidity <= 60.50) {
                                    predicted_class = 1;
                                } else {
                                    predicted_class = 0;
                                }
                            }
                        } else {
                            if (Temp <= 20.50) {
                                predicted_class = 0;
                            } else {
                                predicted_class = 1;
                            }
                        }
                    } else {
                        predicted_class = 1;
                    }
                } else {
                    if (Fruit_Apple <= 0.50) {
                        if (Fruit_Mango <= 0.50) {
                            if (Days <= 6.50) {
                                if (Humidity <= 53.50) {
                                    predicted_class = 0;
                                } else {
                                    if (Fruit_Lemon <= 0.50) {
                                        if (CO2 <= 419.50) {
                                            if (Humidity <= 58.00) {
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
                                if (Humidity <= 55.00) {
                                    predicted_class = 1;
                                } else {
                                    if (Temp <= 18.50) {
                                        if (Days <= 7.50) {
                                            predicted_class = 0;
                                        } else {
                                            if (CO2 <= 400.00) {
                                                predicted_class = 1;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        }
                                    } else {
                                        if (Fruit_Lemon <= 0.50) {
                                            predicted_class = 1;
                                        } else {
                                            if (Humidity <= 70.00) {
                                                predicted_class = 0;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (Days <= 11.50) {
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
                if (Days <= 5.50) {
                    if (Fruit_Tomato <= 0.50) {
                        if (CO2 <= 399.50) {
                            if (Humidity <= 59.00) {
                                predicted_class = 0;
                            } else {
                                predicted_class = 1;
                            }
                        } else {
                            predicted_class = 1;
                        }
                    } else {
                        if (Temp <= 25.50) {
                            predicted_class = 0;
                        } else {
                            predicted_class = 1;
                        }
                    }
                } else {
                    if (Humidity <= 53.00) {
                        predicted_class = 1;
                    } else {
                        if (Days <= 15.50) {
                            if (Fruit_Papaya <= 0.50) {
                                if (Days <= 6.50) {
                                    predicted_class = 0;
                                } else {
                                    if (Humidity <= 69.00) {
                                        if (Fruit_Apple <= 0.50) {
                                            if (Days <= 10.50) {
                                                predicted_class = 0;
                                            } else {
                                                predicted_class = 1;
                                            }
                                        } else {
                                            predicted_class = 0;
                                        }
                                    } else {
                                        if (Days <= 10.00) {
                                            predicted_class = 1;
                                        } else {
                                            if (Days <= 13.50) {
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
                            if (Humidity <= 62.50) {
                                if (Days <= 17.50) {
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
    char GPIO;
    for (unsigned short data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
        char Days = Days_Vector[data_sample];
        char Temp = Temp_Vector[data_sample];
        char Humidity = Humidity_Vector[data_sample];
        char CO2 = CO2_Vector[data_sample];
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
            return GPIO;
        } else {
            GPIO = 1;
        }
    }

    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_DTs();
    return 0;
}