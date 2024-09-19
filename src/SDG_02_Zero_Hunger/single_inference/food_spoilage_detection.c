#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;

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


char Read_Sensor_Values_Run_Check() {
    char GPIO;

    char days = Days;
    char temp = Temp;
    char humidity = Humidity;
    short co2 = CO2;
    char fruit_apple = Fruit_Apple;
    char fruit_banana = Fruit_Banana;
    char fruit_grapes = Fruit_Grapes;
    char fruit_jackfruit = Fruit_Jackfruit;
    char fruit_lemon = Fruit_Lemon;
    char fruit_litchi = Fruit_Litchi;
    char fruit_mango = Fruit_Mango;
    char fruit_papaya = Fruit_Papaya;
    char fruit_plum = Fruit_Plum;
    char fruit_tomato = Fruit_Tomato;

    char golden_reference = Spoiled;

    char spoiled = Predict_Spoiled(days, fruit_litchi, co2, fruit_plum, temp, humidity, fruit_grapes, fruit_apple, fruit_lemon, fruit_mango, fruit_tomato, fruit_papaya);

    if (spoiled != golden_reference) {
        // Failure case - this really shouldn't happen for basic thresholding
        GPIO = 0;
        return GPIO;
    }

    GPIO = 1;
    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_Check();
    return 0;
}
