#include "sample_data.h"

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

int main() {
    char Days = Sensor_2_A_Sample_Input;
    char Temp = Sensor_1_A_Sample_Input;
    char Humidity = Sensor_3_A_Sample_Input;
    char CO2 = Sensor_4_A_Sample_Input;
    char Fruit_Apple = Sensor_1_B_Sample_Input;
    char Fruit_Banana = Sensor_2_B_Sample_Input;
    char Fruit_Grapes = Sensor_3_B_Sample_Input;
    char Fruit_Jackfruit = Sensor_4_B_Sample_Input;
    char Fruit_Lemon = 0;  // Replace with appropriate sensor value if available
    char Fruit_Litchi = 0;  // Replace with appropriate sensor value if available
    char Fruit_Mango = 0;  // Replace with appropriate sensor value if available
    char Fruit_Papaya = 0;  // Replace with appropriate sensor value if available
    char Fruit_Plum = 0;  // Replace with appropriate sensor value if available
    char Fruit_Tomato = 0;  // Replace with appropriate sensor value if available

    char result = Predict_Spoiled(Days, Fruit_Litchi, CO2, Fruit_Plum, Temp, Humidity, Fruit_Grapes, Fruit_Apple, Fruit_Lemon, Fruit_Mango, Fruit_Tomato, Fruit_Papaya);

    if (result == Golden_Reference_Class_Prediction) {
        correct_result = 1;
    } else {
        correct_result = 0;
    }

    return 0;
}
