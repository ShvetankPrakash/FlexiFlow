#include "sample_data.h"

volatile char correct_result = -1;

char predict_random_forest(unsigned short features[]);

char Read_Sensor_Values_Run_RF() {
    char occupancy, golden_reference, GPIO;

    unsigned short features[] = {
        Temperature_Sensor_Sample_Input,
        Humidity_Sensor_Sample_Input,
        Light_Sensor_Sample_Input,
        CO2_Sensor_Sample_Input,
        HumidityRatio_Sensor_Sample_Input,
    };

    golden_reference = Golden_Reference_Occupancy;
    occupancy = predict_random_forest(features);

    if (occupancy) {
        GPIO = 1;
        return GPIO;
    }

    GPIO = 0;
    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_RF();

    return 0;
}

int predict_tree_0(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 245) {
            if (features[2] <= 48) {
                if (features[3] <= 68) {
                    return 0;
                } else {
                    if (features[2] <= 31) {
                        if (features[1] <= 189) {
                            if (features[3] <= 129) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 27) {
                    return 0;
                } else {
                    if (features[1] <= 134) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 227) {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    if (features[0] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 203) {
                    if (features[1] <= 30) {
                        if (features[1] <= 30) {
                            if (features[3] <= 38) {
                                return 1;
                            } else {
                                if (features[0] <= 168) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 200) {
                            if (features[3] <= 10) {
                                if (features[1] <= 66) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 43) {
                                    if (features[1] <= 43) {
                                        if (features[1] <= 42) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 79) {
                                                if (features[2] <= 78) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 63) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[4] <= 122) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[4] <= 115) {
                        if (features[3] <= 82) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[4] <= 129) {
                if (features[1] <= 111) {
                    return 0;
                } else {
                    if (features[0] <= 232) {
                        if (features[1] <= 112) {
                            if (features[3] <= 102) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_1(unsigned short features[]) {
    if (features[3] <= 33) {
        if (features[3] <= 13) {
            if (features[3] <= 11) {
                if (features[2] <= 63) {
                    if (features[3] <= 10) {
                        if (features[0] <= 105) {
                            return 0;
                        } else {
                            if (features[0] <= 107) {
                                if (features[3] <= 7) {
                                    return 0;
                                } else {
                                    if (features[2] <= 29) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[3] <= 10) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 7) {
                        if (features[4] <= 3) {
                            if (features[2] <= 69) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 9) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 67) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 32) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[0] <= 113) {
            if (features[4] <= 151) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 217) {
                if (features[2] <= 31) {
                    return 0;
                } else {
                    if (features[0] <= 234) {
                        if (features[3] <= 76) {
                            if (features[3] <= 76) {
                                if (features[1] <= 100) {
                                    if (features[4] <= 41) {
                                        if (features[0] <= 159) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 43) {
                                                if (features[0] <= 163) {
                                                    return 0;
                                                } else {
                                                    if (features[2] <= 79) {
                                                        if (features[3] <= 62) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[2] <= 74) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 63) {
                                            if (features[4] <= 111) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                if (features[1] <= 81) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 227) {
                                if (features[3] <= 100) {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 99) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 124) {
                                    return 0;
                                } else {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 91) {
                                            if (features[4] <= 127) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 110) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 204) {
                    if (features[4] <= 216) {
                        if (features[2] <= 39) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 37) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 27) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_2(unsigned short features[]) {
    if (features[3] <= 28) {
        if (features[1] <= 81) {
            if (features[2] <= 63) {
                if (features[2] <= 59) {
                    return 0;
                } else {
                    if (features[4] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 70) {
                    if (features[1] <= 24) {
                        if (features[4] <= 3) {
                            return 1;
                        } else {
                            if (features[0] <= 71) {
                                return 0;
                            } else {
                                if (features[0] <= 73) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[0] <= 32) {
                return 0;
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    if (features[2] <= 24) {
                        return 0;
                    } else {
                        if (features[0] <= 34) {
                            if (features[4] <= 77) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[1] <= 189) {
            if (features[2] <= 31) {
                if (features[4] <= 173) {
                    return 0;
                } else {
                    if (features[3] <= 131) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 227) {
                    if (features[0] <= 200) {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[2] <= 76) {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    if (features[3] <= 108) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 64) {
                                    if (features[1] <= 43) {
                                        if (features[2] <= 79) {
                                            if (features[2] <= 78) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[3] <= 38) {
                                                if (features[3] <= 37) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 153) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[1] <= 43) {
                                            if (features[2] <= 79) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 62) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 100) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 79) {
                            if (features[4] <= 119) {
                                if (features[2] <= 81) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 64) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 89) {
                        if (features[0] <= 230) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 110) {
                            return 0;
                        } else {
                            if (features[2] <= 91) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 148) {
                return 0;
            } else {
                if (features[0] <= 181) {
                    if (features[1] <= 229) {
                        if (features[2] <= 37) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 37) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 27) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_3(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[0] <= 110) {
            if (features[3] <= 11) {
                if (features[2] <= 60) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        if (features[4] <= 3) {
                            return 0;
                        } else {
                            if (features[0] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                if (features[2] <= 32) {
                    return 0;
                } else {
                    if (features[0] <= 36) {
                        if (features[4] <= 77) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 52) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 27) {
            if (features[1] <= 73) {
                if (features[1] <= 72) {
                    if (features[3] <= 26) {
                        return 0;
                    } else {
                        if (features[3] <= 26) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 56) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 28) {
                if (features[3] <= 132) {
                    return 0;
                } else {
                    if (features[1] <= 205) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 227) {
                    if (features[4] <= 115) {
                        if (features[0] <= 204) {
                            if (features[4] <= 115) {
                                if (features[0] <= 201) {
                                    if (features[4] <= 113) {
                                        if (features[1] <= 30) {
                                            if (features[1] <= 29) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 38) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[2] <= 78) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 40) {
                                                    if (features[4] <= 40) {
                                                        return 1;
                                                    } else {
                                                        if (features[2] <= 79) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 192) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 108) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 76) {
                                if (features[4] <= 111) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 116) {
                        if (features[3] <= 92) {
                            return 1;
                        } else {
                            if (features[2] <= 86) {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_4(unsigned short features[]) {
    if (features[2] <= 62) {
        if (features[0] <= 106) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[4] <= 91) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 63) {
                return 0;
            } else {
                if (features[4] <= 48) {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        if (features[3] <= 7) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 67) {
                        return 0;
                    } else {
                        if (features[1] <= 94) {
                            return 1;
                        } else {
                            if (features[1] <= 189) {
                                if (features[3] <= 129) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[3] <= 7) {
            return 0;
        } else {
            if (features[4] <= 3) {
                return 0;
            } else {
                if (features[2] <= 87) {
                    if (features[0] <= 204) {
                        if (features[0] <= 34) {
                            if (features[1] <= 120) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 10) {
                                if (features[2] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    if (features[2] <= 76) {
                                        if (features[3] <= 58) {
                                            if (features[2] <= 75) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[2] <= 76) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 97) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 103) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[1] <= 43) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[0] <= 171) {
                                                    if (features[1] <= 43) {
                                                        if (features[3] <= 62) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[0] <= 190) {
                                                return 1;
                                            } else {
                                                if (features[1] <= 112) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 192) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 114) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[3] <= 87) {
                                    if (features[3] <= 63) {
                                        if (features[4] <= 111) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 87) {
                        if (features[1] <= 29) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 106) {
                            if (features[4] <= 27) {
                                if (features[3] <= 37) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 230) {
                                if (features[1] <= 109) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 110) {
                                    return 0;
                                } else {
                                    if (features[2] <= 89) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_5(unsigned short features[]) {
    if (features[0] <= 139) {
        if (features[3] <= 18) {
            if (features[1] <= 29) {
                if (features[3] <= 7) {
                    if (features[2] <= 55) {
                        return 0;
                    } else {
                        if (features[3] <= 4) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 6) {
                        return 1;
                    } else {
                        if (features[0] <= 77) {
                            if (features[0] <= 73) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 13) {
                                return 0;
                            } else {
                                if (features[2] <= 34) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 13) {
                    if (features[0] <= 105) {
                        if (features[0] <= 32) {
                            return 0;
                        } else {
                            if (features[0] <= 33) {
                                if (features[4] <= 76) {
                                    if (features[1] <= 117) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[1] <= 55) {
                            return 0;
                        } else {
                            if (features[4] <= 47) {
                                if (features[3] <= 7) {
                                    if (features[3] <= 7) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 54) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 46) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 31) {
            return 0;
        } else {
            if (features[0] <= 227) {
                if (features[0] <= 163) {
                    if (features[1] <= 214) {
                        if (features[4] <= 38) {
                            if (features[1] <= 33) {
                                if (features[0] <= 159) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 72) {
                                if (features[1] <= 54) {
                                    if (features[1] <= 46) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 40) {
                                        if (features[3] <= 36) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[4] <= 176) {
                                    if (features[4] <= 168) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 41) {
                                            if (features[3] <= 131) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 26) {
                        return 0;
                    } else {
                        if (features[0] <= 200) {
                            if (features[4] <= 42) {
                                if (features[1] <= 43) {
                                    if (features[2] <= 79) {
                                        if (features[2] <= 78) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 115) {
                                            if (features[4] <= 115) {
                                                if (features[3] <= 100) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 209) {
                                if (features[3] <= 76) {
                                    if (features[2] <= 73) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 106) {
                                            if (features[4] <= 111) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[1] <= 111) {
                    return 0;
                } else {
                    if (features[3] <= 110) {
                        if (features[1] <= 112) {
                            if (features[4] <= 124) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_6(unsigned short features[]) {
    if (features[2] <= 65) {
        if (features[4] <= 247) {
            if (features[0] <= 142) {
                if (features[2] <= 56) {
                    return 0;
                } else {
                    if (features[2] <= 62) {
                        return 1;
                    } else {
                        if (features[4] <= 85) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 38) {
                    return 0;
                } else {
                    if (features[3] <= 40) {
                        return 1;
                    } else {
                        if (features[1] <= 189) {
                            if (features[1] <= 188) {
                                if (features[2] <= 27) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            if (features[2] <= 68) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 111) {
                if (features[1] <= 116) {
                    if (features[3] <= 106) {
                        if (features[4] <= 109) {
                            if (features[0] <= 107) {
                                if (features[0] <= 105) {
                                    return 1;
                                } else {
                                    if (features[4] <= 33) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[4] <= 41) {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 41) {
                                            if (features[4] <= 40) {
                                                if (features[1] <= 41) {
                                                    return 1;
                                                } else {
                                                    if (features[2] <= 79) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[0] <= 200) {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    if (features[3] <= 100) {
                                        if (features[4] <= 116) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[1] <= 107) {
                                    if (features[1] <= 106) {
                                        if (features[0] <= 205) {
                                            return 0;
                                        } else {
                                            if (features[1] <= 105) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 61) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 73) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 228) {
                                        if (features[0] <= 206) {
                                            if (features[3] <= 76) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[4] <= 124) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 86) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 126) {
                            return 1;
                        } else {
                            if (features[0] <= 228) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 110) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_7(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[2] <= 54) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[3] <= 6) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 65) {
                    if (features[2] <= 65) {
                        return 1;
                    } else {
                        if (features[4] <= 85) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 23) {
                        if (features[0] <= 71) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[3] <= 26) {
            if (features[2] <= 63) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 28) {
                if (features[4] <= 174) {
                    return 0;
                } else {
                    if (features[4] <= 175) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 104) {
                    if (features[2] <= 89) {
                        return 1;
                    } else {
                        if (features[4] <= 27) {
                            if (features[3] <= 37) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 109) {
                        if (features[3] <= 76) {
                            if (features[0] <= 201) {
                                return 1;
                            } else {
                                if (features[3] <= 63) {
                                    if (features[3] <= 62) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[4] <= 122) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 86) {
                            if (features[4] <= 115) {
                                if (features[1] <= 113) {
                                    if (features[2] <= 77) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                if (features[1] <= 114) {
                                    if (features[0] <= 234) {
                                        if (features[0] <= 232) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 91) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_8(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[1] <= 246) {
            if (features[3] <= 10) {
                if (features[1] <= 65) {
                    if (features[4] <= 45) {
                        return 0;
                    } else {
                        if (features[2] <= 29) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 31) {
                    if (features[3] <= 132) {
                        return 0;
                    } else {
                        if (features[4] <= 184) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 227) {
            if (features[4] <= 14) {
                if (features[3] <= 7) {
                    if (features[0] <= 70) {
                        if (features[0] <= 69) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 3) {
                            if (features[3] <= 4) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[0] <= 200) {
                    if (features[2] <= 66) {
                        if (features[1] <= 125) {
                            if (features[4] <= 68) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 162) {
                            return 1;
                        } else {
                            if (features[4] <= 27) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 76) {
                                    return 1;
                                } else {
                                    if (features[4] <= 113) {
                                        if (features[3] <= 64) {
                                            if (features[2] <= 79) {
                                                if (features[3] <= 63) {
                                                    if (features[1] <= 42) {
                                                        if (features[4] <= 39) {
                                                            return 1;
                                                        } else {
                                                            if (features[4] <= 41) {
                                                                if (features[2] <= 78) {
                                                                    return 1;
                                                                } else {
                                                                    if (features[2] <= 78) {
                                                                        return 0;
                                                                    } else {
                                                                        return 1;
                                                                    }
                                                                }
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[2] <= 76) {
                                            if (features[3] <= 103) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[0] <= 192) {
                                                if (features[3] <= 123) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 79) {
                        if (features[3] <= 63) {
                            if (features[4] <= 111) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[4] <= 122) {
                return 1;
            } else {
                if (features[3] <= 111) {
                    if (features[0] <= 228) {
                        if (features[2] <= 86) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 232) {
                            return 0;
                        } else {
                            if (features[3] <= 97) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_9(unsigned short features[]) {
    if (features[0] <= 111) {
        if (features[0] <= 104) {
            if (features[2] <= 47) {
                return 0;
            } else {
                if (features[1] <= 23) {
                    if (features[0] <= 73) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 12) {
                        if (features[4] <= 77) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[3] <= 9) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        if (features[4] <= 48) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 161) {
                    if (features[3] <= 20) {
                        if (features[1] <= 31) {
                            return 0;
                        } else {
                            if (features[2] <= 35) {
                                return 0;
                            } else {
                                if (features[1] <= 48) {
                                    return 1;
                                } else {
                                    if (features[0] <= 107) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[3] <= 22) {
            if (features[4] <= 58) {
                if (features[1] <= 55) {
                    return 0;
                } else {
                    if (features[1] <= 69) {
                        return 1;
                    } else {
                        if (features[2] <= 33) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[1] <= 217) {
                if (features[1] <= 108) {
                    if (features[4] <= 111) {
                        if (features[4] <= 37) {
                            if (features[1] <= 35) {
                                if (features[2] <= 35) {
                                    return 0;
                                } else {
                                    if (features[4] <= 27) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 28) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 54) {
                                    if (features[4] <= 24) {
                                        if (features[4] <= 23) {
                                            if (features[4] <= 23) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 30) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[2] <= 43) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 35) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[3] <= 58) {
                                if (features[4] <= 40) {
                                    if (features[0] <= 156) {
                                        if (features[3] <= 40) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 63) {
                                        if (features[2] <= 36) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[2] <= 34) {
                                            return 0;
                                        } else {
                                            if (features[1] <= 95) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 110) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 35) {
                                    return 0;
                                } else {
                                    if (features[3] <= 64) {
                                        if (features[0] <= 202) {
                                            if (features[3] <= 64) {
                                                if (features[1] <= 43) {
                                                    if (features[4] <= 41) {
                                                        return 1;
                                                    } else {
                                                        if (features[2] <= 84) {
                                                            if (features[3] <= 63) {
                                                                return 1;
                                                            } else {
                                                                return 0;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[4] <= 111) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] <= 237) {
                            if (features[3] <= 95) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 122) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 130) {
                        if (features[1] <= 181) {
                            if (features[0] <= 234) {
                                if (features[0] <= 227) {
                                    if (features[3] <= 100) {
                                        if (features[4] <= 117) {
                                            if (features[3] <= 100) {
                                                if (features[0] <= 203) {
                                                    if (features[1] <= 112) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 108) {
                                        if (features[3] <= 102) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 114) {
                                if (features[1] <= 184) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 173) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 27) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_10(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[4] <= 115) {
            if (features[1] <= 150) {
                if (features[1] <= 148) {
                    if (features[3] <= 13) {
                        if (features[2] <= 53) {
                            return 0;
                        } else {
                            if (features[1] <= 25) {
                                if (features[3] <= 7) {
                                    if (features[4] <= 3) {
                                        if (features[4] <= 3) {
                                            if (features[3] <= 5) {
                                                if (features[2] <= 69) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 77) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 79) {
                            if (features[3] <= 13) {
                                return 1;
                            } else {
                                if (features[3] <= 19) {
                                    if (features[1] <= 28) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 34) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[1] <= 32) {
                                        if (features[4] <= 18) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 22) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 63) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 35) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 40) {
            if (features[3] <= 27) {
                if (features[1] <= 34) {
                    return 0;
                } else {
                    if (features[2] <= 37) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[4] <= 27) {
                    if (features[1] <= 36) {
                        if (features[1] <= 30) {
                            if (features[1] <= 29) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 37) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 167) {
                        if (features[1] <= 30) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 54) {
                            if (features[3] <= 53) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 58) {
                if (features[2] <= 33) {
                    return 0;
                } else {
                    if (features[4] <= 93) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 228) {
                    if (features[2] <= 48) {
                        if (features[4] <= 175) {
                            if (features[1] <= 188) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[4] <= 115) {
                            if (features[1] <= 104) {
                                if (features[1] <= 43) {
                                    if (features[1] <= 43) {
                                        if (features[1] <= 42) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 170) {
                                                if (features[3] <= 62) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 62) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 80) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 63) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 107) {
                                    if (features[0] <= 198) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 87) {
                                            if (features[1] <= 106) {
                                                if (features[1] <= 105) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 203) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 99) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 110) {
                        if (features[1] <= 105) {
                            if (features[1] <= 104) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 113) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 129) {
                            return 1;
                        } else {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_11(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[0] <= 188) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[2] <= 48) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 90) {
                if (features[1] <= 49) {
                    return 0;
                } else {
                    if (features[1] <= 95) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 28) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[1] <= 24) {
            if (features[2] <= 67) {
                return 1;
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[0] <= 230) {
                if (features[0] <= 200) {
                    if (features[0] <= 34) {
                        if (features[2] <= 67) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 25) {
                            if (features[0] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[1] <= 30) {
                                if (features[0] <= 164) {
                                    if (features[4] <= 26) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 10) {
                                    return 0;
                                } else {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 76) {
                                            if (features[1] <= 150) {
                                                if (features[4] <= 111) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[4] <= 40) {
                                                if (features[1] <= 41) {
                                                    return 1;
                                                } else {
                                                    if (features[4] <= 40) {
                                                        return 1;
                                                    } else {
                                                        if (features[3] <= 62) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[4] <= 114) {
                        if (features[3] <= 76) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 227) {
                            return 1;
                        } else {
                            if (features[3] <= 107) {
                                if (features[2] <= 104) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 240) {
                    if (features[0] <= 232) {
                        if (features[2] <= 89) {
                            if (features[1] <= 115) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_12(unsigned short features[]) {
    if (features[2] <= 62) {
        if (features[2] <= 35) {
            return 0;
        } else {
            if (features[3] <= 24) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 25) {
            if (features[2] <= 69) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 116) {
                if (features[0] <= 200) {
                    if (features[1] <= 112) {
                        if (features[1] <= 42) {
                            if (features[3] <= 62) {
                                if (features[0] <= 163) {
                                    if (features[4] <= 27) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 79) {
                                    if (features[0] <= 171) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 11) {
                                if (features[1] <= 66) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 192) {
                            return 0;
                        } else {
                            if (features[4] <= 115) {
                                if (features[4] <= 115) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 73) {
                        return 1;
                    } else {
                        if (features[1] <= 110) {
                            if (features[0] <= 223) {
                                if (features[3] <= 63) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 106) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                if (features[3] <= 108) {
                                    if (features[3] <= 101) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[4] <= 129) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 110) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_13(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[3] <= 231) {
            if (features[4] <= 85) {
                if (features[2] <= 59) {
                    return 0;
                } else {
                    if (features[2] <= 59) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 105) {
                    return 1;
                } else {
                    if (features[0] <= 153) {
                        return 0;
                    } else {
                        if (features[0] <= 157) {
                            if (features[4] <= 175) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 25) {
            if (features[2] <= 70) {
                if (features[4] <= 5) {
                    if (features[1] <= 22) {
                        return 1;
                    } else {
                        if (features[1] <= 22) {
                            if (features[2] <= 69) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 94) {
                if (features[3] <= 12) {
                    if (features[1] <= 120) {
                        if (features[4] <= 48) {
                            if (features[0] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 227) {
                        if (features[0] <= 204) {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[4] <= 109) {
                                    if (features[4] <= 41) {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 106) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 115) {
                                            if (features[4] <= 115) {
                                                if (features[2] <= 77) {
                                                    return 1;
                                                } else {
                                                    if (features[1] <= 112) {
                                                        return 1;
                                                    } else {
                                                        if (features[4] <= 114) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[4] <= 114) {
                                if (features[4] <= 108) {
                                    return 1;
                                } else {
                                    if (features[3] <= 76) {
                                        if (features[3] <= 63) {
                                            if (features[3] <= 61) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 230) {
                            return 0;
                        } else {
                            if (features[1] <= 109) {
                                return 1;
                            } else {
                                if (features[4] <= 128) {
                                    return 0;
                                } else {
                                    if (features[3] <= 110) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 97) {
                    if (features[0] <= 199) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 109) {
                        return 1;
                    } else {
                        if (features[2] <= 102) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_14(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[3] <= 13) {
            if (features[3] <= 10) {
                if (features[2] <= 63) {
                    if (features[0] <= 105) {
                        return 0;
                    } else {
                        if (features[2] <= 59) {
                            return 0;
                        } else {
                            if (features[2] <= 59) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 91) {
                        if (features[2] <= 69) {
                            return 1;
                        } else {
                            if (features[3] <= 7) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 67) {
                    if (features[3] <= 10) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 54) {
                if (features[1] <= 79) {
                    if (features[1] <= 36) {
                        if (features[2] <= 29) {
                            return 0;
                        } else {
                            if (features[2] <= 89) {
                                if (features[2] <= 87) {
                                    return 1;
                                } else {
                                    if (features[2] <= 87) {
                                        if (features[1] <= 30) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 89) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 40) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 104) {
                    if (features[1] <= 45) {
                        if (features[4] <= 36) {
                            return 0;
                        } else {
                            if (features[0] <= 164) {
                                return 0;
                            } else {
                                if (features[2] <= 81) {
                                    if (features[3] <= 64) {
                                        if (features[1] <= 43) {
                                            if (features[2] <= 78) {
                                                if (features[1] <= 42) {
                                                    if (features[3] <= 61) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[2] <= 81) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 69) {
                            if (features[3] <= 58) {
                                if (features[4] <= 46) {
                                    return 1;
                                } else {
                                    if (features[2] <= 36) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 82) {
                                return 0;
                            } else {
                                if (features[2] <= 35) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 86) {
                        if (features[3] <= 63) {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[1] <= 105) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[4] <= 113) {
                            return 1;
                        } else {
                            if (features[3] <= 100) {
                                if (features[2] <= 76) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[2] <= 41) {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[2] <= 5) {
                    if (features[3] <= 110) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[0] <= 227) {
                return 1;
            } else {
                if (features[2] <= 102) {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        if (features[3] <= 110) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_15(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 62) {
            if (features[2] <= 59) {
                if (features[1] <= 117) {
                    return 0;
                } else {
                    if (features[1] <= 118) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 35) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[1] <= 25) {
                if (features[1] <= 24) {
                    if (features[1] <= 22) {
                        if (features[2] <= 69) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[4] <= 9) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 13) {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[2] <= 31) {
            return 0;
        } else {
            if (features[1] <= 116) {
                if (features[0] <= 200) {
                    if (features[3] <= 99) {
                        if (features[2] <= 79) {
                            return 1;
                        } else {
                            if (features[0] <= 170) {
                                if (features[1] <= 43) {
                                    if (features[1] <= 30) {
                                        if (features[0] <= 164) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 65) {
                                        if (features[4] <= 42) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[3] <= 99) {
                            return 0;
                        } else {
                            if (features[4] <= 115) {
                                if (features[4] <= 115) {
                                    if (features[0] <= 191) {
                                        if (features[0] <= 190) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 77) {
                        if (features[4] <= 111) {
                            if (features[3] <= 61) {
                                return 0;
                            } else {
                                if (features[3] <= 63) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[4] <= 123) {
                            if (features[3] <= 93) {
                                if (features[1] <= 105) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 98) {
                                return 0;
                            } else {
                                if (features[2] <= 91) {
                                    if (features[4] <= 124) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_16(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[0] <= 102) {
            if (features[4] <= 81) {
                if (features[3] <= 10) {
                    if (features[4] <= 6) {
                        if (features[0] <= 69) {
                            return 0;
                        } else {
                            if (features[2] <= 68) {
                                return 0;
                            } else {
                                if (features[4] <= 4) {
                                    if (features[0] <= 73) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 10) {
                            return 0;
                        } else {
                            if (features[2] <= 24) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[4] <= 11) {
                        return 1;
                    } else {
                        if (features[2] <= 67) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 10) {
                    return 0;
                } else {
                    if (features[1] <= 159) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 17) {
                if (features[1] <= 55) {
                    return 0;
                } else {
                    if (features[2] <= 51) {
                        return 0;
                    } else {
                        if (features[0] <= 107) {
                            if (features[4] <= 48) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[1] <= 33) {
                    if (features[4] <= 18) {
                        if (features[3] <= 19) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 118) {
                            if (features[3] <= 19) {
                                if (features[2] <= 35) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 33) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[2] <= 38) {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[4] <= 146) {
                    return 0;
                } else {
                    if (features[3] <= 131) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[0] <= 227) {
                if (features[1] <= 113) {
                    if (features[2] <= 75) {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[0] <= 201) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[4] <= 108) {
                            if (features[0] <= 170) {
                                if (features[1] <= 30) {
                                    if (features[0] <= 163) {
                                        if (features[4] <= 26) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 43) {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 76) {
                                if (features[2] <= 75) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[0] <= 191) {
                                    if (features[0] <= 190) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 76) {
                                        if (features[1] <= 113) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 123) {
                    return 1;
                } else {
                    if (features[1] <= 116) {
                        if (features[4] <= 125) {
                            if (features[3] <= 96) {
                                return 0;
                            } else {
                                if (features[0] <= 229) {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_17(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[0] <= 36) {
            if (features[2] <= 69) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 62) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        if (features[2] <= 58) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 7) {
                    if (features[4] <= 3) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        if (features[0] <= 113) {
            if (features[4] <= 150) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[3] <= 58) {
                if (features[4] <= 27) {
                    if (features[1] <= 35) {
                        if (features[2] <= 46) {
                            return 0;
                        } else {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                if (features[1] <= 28) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[1] <= 80) {
                        if (features[2] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 93) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 37) {
                    if (features[2] <= 5) {
                        return 0;
                    } else {
                        if (features[0] <= 182) {
                            if (features[3] <= 131) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 87) {
                        if (features[0] <= 204) {
                            if (features[0] <= 190) {
                                if (features[1] <= 43) {
                                    if (features[2] <= 79) {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 41) {
                                                if (features[3] <= 61) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 100) {
                                    if (features[3] <= 100) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 113) {
                                                if (features[3] <= 99) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 107) {
                                if (features[1] <= 104) {
                                    return 1;
                                } else {
                                    if (features[3] <= 83) {
                                        if (features[3] <= 63) {
                                            if (features[3] <= 62) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 230) {
                            if (features[2] <= 87) {
                                return 0;
                            } else {
                                if (features[4] <= 117) {
                                    if (features[2] <= 93) {
                                        if (features[0] <= 203) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 112) {
                                if (features[4] <= 125) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_18(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[2] <= 61) {
            if (features[2] <= 59) {
                if (features[3] <= 39) {
                    return 0;
                } else {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 156) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[4] <= 111) {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        if (features[0] <= 201) {
                            if (features[0] <= 36) {
                                if (features[0] <= 34) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[4] <= 48) {
                                    if (features[4] <= 48) {
                                        if (features[2] <= 78) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 170) {
                                                if (features[3] <= 65) {
                                                    if (features[3] <= 62) {
                                                        if (features[2] <= 86) {
                                                            return 1;
                                                        } else {
                                                            if (features[3] <= 37) {
                                                                return 1;
                                                            } else {
                                                                if (features[1] <= 30) {
                                                                    return 0;
                                                                } else {
                                                                    return 1;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[2] <= 83) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    if (features[1] <= 105) {
                                        if (features[2] <= 81) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[1] <= 107) {
                        if (features[3] <= 89) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 80) {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    } else {
        if (features[2] <= 41) {
            if (features[1] <= 189) {
                if (features[0] <= 154) {
                    return 0;
                } else {
                    if (features[0] <= 187) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 93) {
                if (features[0] <= 229) {
                    return 1;
                } else {
                    if (features[4] <= 128) {
                        return 1;
                    } else {
                        if (features[2] <= 89) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[3] <= 97) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_19(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[2] <= 62) {
            if (features[4] <= 47) {
                return 0;
            } else {
                if (features[3] <= 10) {
                    if (features[2] <= 54) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 117) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[4] <= 109) {
                if (features[3] <= 7) {
                    if (features[3] <= 7) {
                        if (features[3] <= 4) {
                            if (features[4] <= 3) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 7) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 28) {
                        if (features[4] <= 27) {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                if (features[0] <= 163) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 34) {
                            if (features[2] <= 67) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 43) {
                                if (features[0] <= 170) {
                                    if (features[1] <= 43) {
                                        if (features[2] <= 78) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[0] <= 169) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 85) {
                    if (features[3] <= 54) {
                        return 1;
                    } else {
                        if (features[4] <= 114) {
                            if (features[2] <= 75) {
                                return 0;
                            } else {
                                if (features[3] <= 64) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 113) {
                        return 1;
                    } else {
                        if (features[3] <= 100) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[0] <= 111) {
            if (features[4] <= 147) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 109) {
                if (features[0] <= 240) {
                    return 0;
                } else {
                    if (features[2] <= 92) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 41) {
                    return 0;
                } else {
                    if (features[1] <= 116) {
                        if (features[0] <= 229) {
                            return 1;
                        } else {
                            if (features[3] <= 112) {
                                if (features[1] <= 112) {
                                    if (features[0] <= 237) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_20(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[1] <= 247) {
            if (features[2] <= 56) {
                if (features[2] <= 35) {
                    return 0;
                } else {
                    if (features[2] <= 35) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 72) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 24) {
            if (features[2] <= 67) {
                return 1;
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[1] <= 116) {
                if (features[2] <= 94) {
                    if (features[1] <= 104) {
                        if (features[1] <= 43) {
                            if (features[3] <= 62) {
                                return 1;
                            } else {
                                if (features[1] <= 43) {
                                    if (features[0] <= 169) {
                                        if (features[2] <= 79) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[2] <= 80) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 70) {
                                if (features[3] <= 10) {
                                    if (features[1] <= 66) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[3] <= 74) {
                            if (features[1] <= 107) {
                                if (features[2] <= 80) {
                                    if (features[1] <= 106) {
                                        if (features[1] <= 105) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[3] <= 67) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 124) {
                                return 1;
                            } else {
                                if (features[2] <= 91) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 97) {
                        if (features[3] <= 62) {
                            if (features[2] <= 167) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 230) {
                            return 1;
                        } else {
                            if (features[4] <= 126) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_21(unsigned short features[]) {
    if (features[0] <= 138) {
        if (features[2] <= 55) {
            return 0;
        } else {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[0] <= 36) {
                    if (features[1] <= 120) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 10) {
                        if (features[1] <= 46) {
                            return 1;
                        } else {
                            if (features[4] <= 48) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[3] <= 31) {
            return 0;
        } else {
            if (features[3] <= 58) {
                if (features[2] <= 46) {
                    return 0;
                } else {
                    if (features[4] <= 93) {
                        if (features[2] <= 89) {
                            return 1;
                        } else {
                            if (features[0] <= 165) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 27) {
                    if (features[2] <= 5) {
                        return 0;
                    } else {
                        if (features[3] <= 131) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 204) {
                        if (features[3] <= 99) {
                            return 1;
                        } else {
                            if (features[3] <= 99) {
                                if (features[0] <= 192) {
                                    return 0;
                                } else {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 207) {
                            if (features[3] <= 82) {
                                if (features[3] <= 63) {
                                    if (features[0] <= 205) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 110) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 230) {
                                if (features[0] <= 227) {
                                    return 1;
                                } else {
                                    if (features[0] <= 229) {
                                        if (features[3] <= 102) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    if (features[4] <= 130) {
                                        if (features[0] <= 234) {
                                            if (features[1] <= 112) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 110) {
                                                    return 0;
                                                } else {
                                                    if (features[2] <= 89) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_22(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[1] <= 246) {
            if (features[4] <= 175) {
                if (features[2] <= 59) {
                    if (features[0] <= 188) {
                        if (features[1] <= 117) {
                            return 0;
                        } else {
                            if (features[2] <= 47) {
                                return 0;
                            } else {
                                if (features[1] <= 133) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 38) {
                            return 0;
                        } else {
                            if (features[4] <= 99) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 38) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 189) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            if (features[1] <= 22) {
                if (features[2] <= 69) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 234) {
                if (features[0] <= 204) {
                    if (features[3] <= 13) {
                        if (features[4] <= 77) {
                            if (features[2] <= 68) {
                                if (features[0] <= 74) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 162) {
                            return 1;
                        } else {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[1] <= 112) {
                                    if (features[0] <= 163) {
                                        if (features[4] <= 36) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[4] <= 42) {
                                            if (features[1] <= 43) {
                                                if (features[1] <= 42) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 62) {
                                                        return 1;
                                                    } else {
                                                        if (features[2] <= 79) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[2] <= 76) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 100) {
                                            if (features[0] <= 197) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[0] <= 206) {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[3] <= 87) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            if (features[4] <= 113) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 91) {
                                if (features[0] <= 228) {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 115) {
                                    return 1;
                                } else {
                                    if (features[4] <= 128) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[4] <= 122) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_23(unsigned short features[]) {
    if (features[2] <= 65) {
        if (features[1] <= 247) {
            if (features[3] <= 18) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        if (features[0] <= 103) {
                            return 0;
                        } else {
                            if (features[2] <= 58) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 18) {
                    return 1;
                } else {
                    if (features[0] <= 68) {
                        return 1;
                    } else {
                        if (features[2] <= 31) {
                            if (features[3] <= 131) {
                                return 0;
                            } else {
                                if (features[2] <= 3) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 24) {
            return 0;
        } else {
            if (features[4] <= 128) {
                if (features[4] <= 109) {
                    if (features[0] <= 36) {
                        if (features[1] <= 121) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[2] <= 87) {
                            if (features[0] <= 107) {
                                if (features[2] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[3] <= 62) {
                                    if (features[2] <= 78) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 79) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[0] <= 164) {
                                if (features[1] <= 30) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 107) {
                        if (features[2] <= 74) {
                            if (features[3] <= 83) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 197) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[4] <= 115) {
                                    if (features[2] <= 76) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 83) {
                                            if (features[1] <= 112) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 100) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 101) {
                                if (features[0] <= 234) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 90) {
                                    return 0;
                                } else {
                                    if (features[2] <= 96) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_24(unsigned short features[]) {
    if (features[2] <= 62) {
        if (features[1] <= 247) {
            if (features[3] <= 40) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[2] <= 59) {
                        if (features[1] <= 117) {
                            return 0;
                        } else {
                            if (features[2] <= 24) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 236) {
                    if (features[4] <= 28) {
                        if (features[1] <= 34) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 189) {
                            if (features[3] <= 131) {
                                if (features[1] <= 82) {
                                    return 0;
                                } else {
                                    if (features[4] <= 85) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[2] <= 86) {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[3] <= 13) {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        if (features[3] <= 10) {
                            if (features[2] <= 70) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[3] <= 76) {
                            if (features[0] <= 200) {
                                if (features[1] <= 43) {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 171) {
                                            if (features[3] <= 62) {
                                                return 0;
                                            } else {
                                                if (features[1] <= 43) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 63) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 202) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[4] <= 115) {
                            if (features[4] <= 115) {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[1] <= 113) {
                                        if (features[2] <= 77) {
                                            if (features[3] <= 99) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[1] <= 80) {
                if (features[4] <= 18) {
                    return 0;
                } else {
                    if (features[1] <= 29) {
                        if (features[0] <= 163) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 227) {
                    if (features[3] <= 85) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[3] <= 110) {
                        if (features[2] <= 113) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 129) {
                            if (features[0] <= 230) {
                                return 1;
                            } else {
                                if (features[3] <= 110) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_25(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[0] <= 138) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[3] <= 13) {
                    if (features[1] <= 25) {
                        return 0;
                    } else {
                        if (features[4] <= 77) {
                            if (features[1] <= 66) {
                                if (features[2] <= 69) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 33) {
                return 0;
            } else {
                if (features[0] <= 204) {
                    if (features[2] <= 28) {
                        return 0;
                    } else {
                        if (features[0] <= 200) {
                            if (features[1] <= 112) {
                                if (features[3] <= 64) {
                                    if (features[3] <= 63) {
                                        if (features[3] <= 62) {
                                            if (features[3] <= 38) {
                                                if (features[2] <= 90) {
                                                    if (features[1] <= 30) {
                                                        if (features[1] <= 29) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[3] <= 62) {
                                                if (features[0] <= 171) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 76) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[4] <= 109) {
                        return 1;
                    } else {
                        if (features[3] <= 91) {
                            if (features[2] <= 75) {
                                return 0;
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    if (features[1] <= 107) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 82) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[3] <= 98) {
            if (features[2] <= 31) {
                return 0;
            } else {
                if (features[0] <= 241) {
                    if (features[2] <= 96) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[1] <= 116) {
                    if (features[4] <= 126) {
                        if (features[2] <= 82) {
                            return 1;
                        } else {
                            if (features[2] <= 88) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[2] <= 100) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 157) {
                        if (features[3] <= 131) {
                            if (features[3] <= 130) {
                                if (features[2] <= 44) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_26(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 63) {
            return 0;
        } else {
            if (features[1] <= 25) {
                if (features[2] <= 69) {
                    if (features[4] <= 4) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 70) {
                    if (features[0] <= 36) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 69) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        if (features[1] <= 189) {
            if (features[2] <= 46) {
                if (features[1] <= 188) {
                    return 0;
                } else {
                    if (features[4] <= 175) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 240) {
                    if (features[3] <= 76) {
                        if (features[4] <= 107) {
                            if (features[1] <= 30) {
                                if (features[0] <= 163) {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 79) {
                                    return 1;
                                } else {
                                    if (features[3] <= 63) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 169) {
                                            if (features[3] <= 65) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 200) {
                                return 1;
                            } else {
                                if (features[3] <= 62) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 112) {
                            return 1;
                        } else {
                            if (features[1] <= 113) {
                                if (features[3] <= 99) {
                                    return 0;
                                } else {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[0] <= 230) {
                                    return 1;
                                } else {
                                    if (features[1] <= 116) {
                                        if (features[2] <= 91) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[4] <= 173) {
                return 0;
            } else {
                if (features[4] <= 235) {
                    if (features[0] <= 146) {
                        return 0;
                    } else {
                        if (features[2] <= 39) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 219) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_27(unsigned short features[]) {
    if (features[3] <= 32) {
        if (features[2] <= 62) {
            if (features[4] <= 47) {
                return 0;
            } else {
                if (features[1] <= 65) {
                    if (features[3] <= 7) {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 32) {
                        return 0;
                    } else {
                        if (features[0] <= 33) {
                            if (features[4] <= 74) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            if (features[4] <= 4) {
                if (features[0] <= 73) {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 22) {
                        if (features[0] <= 74) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 25) {
                    if (features[0] <= 91) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 13) {
                        if (features[2] <= 66) {
                            return 0;
                        } else {
                            if (features[1] <= 66) {
                                if (features[2] <= 69) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[2] <= 28) {
            return 0;
        } else {
            if (features[0] <= 228) {
                if (features[1] <= 113) {
                    if (features[0] <= 203) {
                        if (features[0] <= 190) {
                            if (features[2] <= 87) {
                                if (features[1] <= 43) {
                                    if (features[4] <= 41) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 170) {
                                            if (features[2] <= 79) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 163) {
                                    if (features[3] <= 53) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 115) {
                                if (features[1] <= 112) {
                                    if (features[0] <= 201) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 103) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 192) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 100) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 102) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[4] <= 118) {
                                if (features[3] <= 63) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 122) {
                    return 1;
                } else {
                    if (features[3] <= 110) {
                        if (features[2] <= 117) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 111) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_28(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[2] <= 61) {
            if (features[3] <= 66) {
                if (features[2] <= 59) {
                    if (features[0] <= 142) {
                        return 0;
                    } else {
                        if (features[0] <= 144) {
                            if (features[3] <= 38) {
                                return 0;
                            } else {
                                if (features[3] <= 40) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 59) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 85) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 104) {
                if (features[3] <= 11) {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        if (features[2] <= 70) {
                            if (features[0] <= 69) {
                                return 0;
                            } else {
                                if (features[2] <= 68) {
                                    return 1;
                                } else {
                                    if (features[4] <= 4) {
                                        if (features[2] <= 69) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 6) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[1] <= 43) {
                        if (features[1] <= 43) {
                            if (features[1] <= 30) {
                                if (features[0] <= 163) {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 171) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 76) {
                    if (features[0] <= 200) {
                        if (features[4] <= 81) {
                            if (features[3] <= 11) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 80) {
                            return 0;
                        } else {
                            if (features[2] <= 81) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 112) {
                        return 1;
                    } else {
                        if (features[4] <= 114) {
                            return 0;
                        } else {
                            if (features[1] <= 113) {
                                if (features[3] <= 99) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 113) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[2] <= 42) {
            if (features[1] <= 189) {
                if (features[4] <= 173) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 109) {
                if (features[3] <= 92) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 86) {
                    return 1;
                } else {
                    if (features[1] <= 115) {
                        if (features[1] <= 112) {
                            if (features[2] <= 101) {
                                return 1;
                            } else {
                                if (features[1] <= 111) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[1] <= 116) {
                            if (features[2] <= 90) {
                                if (features[2] <= 89) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_29(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 62) {
            if (features[3] <= 10) {
                return 0;
            } else {
                if (features[3] <= 10) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 13) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[1] <= 120) {
                        if (features[4] <= 3) {
                            return 0;
                        } else {
                            if (features[0] <= 94) {
                                return 1;
                            } else {
                                if (features[3] <= 10) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[2] <= 38) {
            return 0;
        } else {
            if (features[1] <= 114) {
                if (features[0] <= 204) {
                    if (features[1] <= 112) {
                        if (features[1] <= 30) {
                            if (features[0] <= 165) {
                                if (features[4] <= 26) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 79) {
                                return 1;
                            } else {
                                if (features[2] <= 79) {
                                    if (features[0] <= 169) {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[2] <= 81) {
                                        if (features[2] <= 81) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 41) {
                                                return 1;
                                            } else {
                                                if (features[1] <= 46) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 100) {
                            if (features[3] <= 82) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 74) {
                        if (features[2] <= 73) {
                            return 1;
                        } else {
                            if (features[1] <= 108) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 117) {
                            if (features[4] <= 111) {
                                if (features[1] <= 105) {
                                    if (features[2] <= 78) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 123) {
                                if (features[2] <= 92) {
                                    return 1;
                                } else {
                                    if (features[1] <= 109) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 109) {
                                    if (features[4] <= 124) {
                                        if (features[0] <= 235) {
                                            if (features[3] <= 102) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_30(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 233) {
            if (features[2] <= 35) {
                if (features[3] <= 131) {
                    return 0;
                } else {
                    if (features[2] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 45) {
                    return 0;
                } else {
                    if (features[4] <= 95) {
                        return 1;
                    } else {
                        if (features[4] <= 115) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 200) {
            if (features[0] <= 36) {
                if (features[4] <= 77) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[4] <= 4) {
                    if (features[1] <= 22) {
                        return 1;
                    } else {
                        if (features[0] <= 73) {
                            if (features[1] <= 23) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 116) {
                        if (features[1] <= 43) {
                            if (features[3] <= 63) {
                                if (features[1] <= 29) {
                                    if (features[1] <= 29) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 87) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 171) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 79) {
                if (features[1] <= 114) {
                    if (features[4] <= 111) {
                        if (features[4] <= 111) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[0] <= 230) {
                    if (features[1] <= 112) {
                        if (features[1] <= 112) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 106) {
                        return 1;
                    } else {
                        if (features[3] <= 111) {
                            if (features[2] <= 113) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_31(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 132) {
            if (features[2] <= 59) {
                if (features[3] <= 40) {
                    return 0;
                } else {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 165) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 3) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 25) {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[0] <= 71) {
                    if (features[2] <= 68) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[0] <= 228) {
                if (features[2] <= 66) {
                    if (features[4] <= 82) {
                        if (features[0] <= 77) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 204) {
                        if (features[2] <= 76) {
                            if (features[3] <= 10) {
                                if (features[2] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 190) {
                                if (features[3] <= 64) {
                                    if (features[2] <= 79) {
                                        if (features[1] <= 45) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 63) {
                                                    if (features[1] <= 41) {
                                                        return 1;
                                                    } else {
                                                        if (features[4] <= 41) {
                                                            if (features[2] <= 79) {
                                                                return 0;
                                                            } else {
                                                                return 1;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[2] <= 76) {
                                        if (features[4] <= 115) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[0] <= 192) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[2] <= 75) {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 110) {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        if (features[0] <= 230) {
                            if (features[2] <= 104) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 128) {
                        return 1;
                    } else {
                        if (features[4] <= 129) {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_32(unsigned short features[]) {
    if (features[2] <= 65) {
        if (features[4] <= 247) {
            if (features[2] <= 59) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[3] <= 9) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 125) {
                    if (features[2] <= 59) {
                        if (features[4] <= 34) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 25) {
            if (features[3] <= 7) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[4] <= 129) {
                if (features[0] <= 200) {
                    if (features[4] <= 113) {
                        if (features[0] <= 36) {
                            if (features[3] <= 11) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 42) {
                                if (features[4] <= 41) {
                                    if (features[2] <= 87) {
                                        if (features[3] <= 62) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 62) {
                                                if (features[2] <= 80) {
                                                    if (features[2] <= 78) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 164) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[2] <= 76) {
                                if (features[1] <= 113) {
                                    if (features[3] <= 103) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[3] <= 100) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[0] <= 203) {
                            if (features[4] <= 116) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 106) {
                                if (features[3] <= 61) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 84) {
                            return 1;
                        } else {
                            if (features[4] <= 124) {
                                if (features[1] <= 109) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 230) {
                                    if (features[3] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 115) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 110) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_33(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 68) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 31) {
                if (features[2] <= 5) {
                    return 0;
                } else {
                    if (features[4] <= 169) {
                        return 0;
                    } else {
                        if (features[4] <= 175) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[2] <= 95) {
            if (features[4] <= 5) {
                if (features[1] <= 22) {
                    if (features[0] <= 74) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 75) {
                    if (features[3] <= 13) {
                        if (features[0] <= 55) {
                            if (features[4] <= 77) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 116) {
                        if (features[1] <= 104) {
                            if (features[1] <= 43) {
                                if (features[1] <= 43) {
                                    if (features[3] <= 38) {
                                        if (features[0] <= 164) {
                                            if (features[4] <= 27) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[1] <= 42) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 79) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[2] <= 79) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 108) {
                                if (features[0] <= 198) {
                                    return 1;
                                } else {
                                    if (features[0] <= 226) {
                                        if (features[3] <= 63) {
                                            if (features[1] <= 105) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 106) {
                                    if (features[0] <= 227) {
                                        if (features[3] <= 84) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 100) {
                                                if (features[3] <= 100) {
                                                    if (features[3] <= 99) {
                                                        return 1;
                                                    } else {
                                                        if (features[1] <= 112) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 89) {
                                        if (features[3] <= 108) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[3] <= 112) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[1] <= 111) {
                return 0;
            } else {
                if (features[0] <= 230) {
                    return 1;
                } else {
                    if (features[2] <= 102) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_34(unsigned short features[]) {
    if (features[3] <= 13) {
        if (features[2] <= 68) {
            if (features[2] <= 59) {
                return 0;
            } else {
                if (features[4] <= 35) {
                    return 0;
                } else {
                    if (features[1] <= 93) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 7) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[2] <= 31) {
            if (features[4] <= 175) {
                return 0;
            } else {
                if (features[4] <= 175) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[0] <= 240) {
                if (features[1] <= 104) {
                    if (features[1] <= 30) {
                        if (features[1] <= 30) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 169) {
                            return 1;
                        } else {
                            if (features[0] <= 170) {
                                if (features[2] <= 80) {
                                    return 1;
                                } else {
                                    if (features[2] <= 82) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 204) {
                        if (features[1] <= 113) {
                            if (features[3] <= 99) {
                                return 1;
                            } else {
                                if (features[4] <= 114) {
                                    return 1;
                                } else {
                                    if (features[3] <= 101) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 206) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[3] <= 76) {
                                    if (features[2] <= 75) {
                                        if (features[2] <= 75) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 125) {
                                return 1;
                            } else {
                                if (features[1] <= 116) {
                                    if (features[2] <= 104) {
                                        if (features[3] <= 110) {
                                            if (features[2] <= 91) {
                                                return 0;
                                            } else {
                                                if (features[4] <= 127) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            if (features[3] <= 110) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return 0;
            }
        }
    }
}
int predict_tree_35(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[2] <= 62) {
            if (features[2] <= 35) {
                return 0;
            } else {
                if (features[4] <= 26) {
                    return 0;
                } else {
                    if (features[4] <= 94) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[0] <= 203) {
                if (features[2] <= 98) {
                    if (features[4] <= 4) {
                        return 0;
                    } else {
                        if (features[0] <= 36) {
                            if (features[3] <= 11) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 11) {
                                if (features[1] <= 45) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 30) {
                                    if (features[0] <= 163) {
                                        if (features[0] <= 159) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 99) {
                                        if (features[0] <= 200) {
                                            if (features[3] <= 64) {
                                                if (features[1] <= 43) {
                                                    if (features[3] <= 63) {
                                                        if (features[1] <= 42) {
                                                            return 1;
                                                        } else {
                                                            if (features[2] <= 78) {
                                                                if (features[3] <= 62) {
                                                                    return 1;
                                                                } else {
                                                                    return 0;
                                                                }
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        if (features[0] <= 171) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[1] <= 104) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        if (features[3] <= 99) {
                                            if (features[4] <= 112) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[1] <= 104) {
                    return 1;
                } else {
                    if (features[3] <= 87) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[0] <= 107) {
            if (features[0] <= 89) {
                if (features[4] <= 139) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[4] <= 148) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 97) {
                if (features[1] <= 112) {
                    if (features[1] <= 106) {
                        if (features[2] <= 31) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 185) {
                    if (features[2] <= 44) {
                        if (features[4] <= 173) {
                            return 0;
                        } else {
                            if (features[4] <= 175) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            return 1;
                        } else {
                            if (features[2] <= 91) {
                                if (features[2] <= 86) {
                                    if (features[0] <= 229) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 153) {
                        return 0;
                    } else {
                        if (features[3] <= 213) {
                            if (features[3] <= 168) {
                                if (features[1] <= 222) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 36) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[2] <= 27) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_36(unsigned short features[]) {
    if (features[3] <= 28) {
        if (features[2] <= 62) {
            if (features[1] <= 117) {
                return 0;
            } else {
                if (features[2] <= 47) {
                    return 0;
                } else {
                    if (features[4] <= 92) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[0] <= 36) {
                    if (features[1] <= 120) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        if (features[0] <= 111) {
            if (features[1] <= 180) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 28) {
                return 0;
            } else {
                if (features[0] <= 240) {
                    if (features[4] <= 108) {
                        if (features[1] <= 30) {
                            if (features[0] <= 163) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 78) {
                                return 1;
                            } else {
                                if (features[2] <= 79) {
                                    if (features[4] <= 41) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[2] <= 81) {
                                        if (features[2] <= 81) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 169) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 49) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[1] <= 110) {
                                if (features[0] <= 200) {
                                    return 1;
                                } else {
                                    if (features[1] <= 106) {
                                        if (features[4] <= 110) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 129) {
                                if (features[0] <= 230) {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 76) {
                                            if (features[1] <= 113) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[1] <= 112) {
                                                if (features[4] <= 124) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 102) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (features[0] <= 232) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_37(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 62) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[1] <= 24) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        if (features[1] <= 23) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[0] <= 36) {
                    return 0;
                } else {
                    if (features[1] <= 25) {
                        if (features[4] <= 9) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 10) {
                            if (features[0] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[0] <= 107) {
            if (features[0] <= 89) {
                return 1;
            } else {
                if (features[4] <= 148) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 31) {
                return 0;
            } else {
                if (features[2] <= 89) {
                    if (features[3] <= 76) {
                        if (features[0] <= 201) {
                            if (features[1] <= 42) {
                                if (features[4] <= 40) {
                                    return 1;
                                } else {
                                    if (features[1] <= 42) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 62) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 63) {
                                if (features[0] <= 205) {
                                    return 0;
                                } else {
                                    if (features[2] <= 75) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[1] <= 113) {
                                if (features[1] <= 113) {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 100) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[0] <= 165) {
                            if (features[1] <= 39) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 203) {
                                return 1;
                            } else {
                                if (features[1] <= 110) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}
int predict_tree_38(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[2] <= 54) {
            return 0;
        } else {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[3] <= 13) {
                    if (features[1] <= 120) {
                        if (features[2] <= 68) {
                            if (features[3] <= 7) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[2] <= 61) {
            if (features[4] <= 83) {
                return 0;
            } else {
                if (features[1] <= 84) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 93) {
                if (features[3] <= 74) {
                    if (features[0] <= 200) {
                        if (features[4] <= 41) {
                            if (features[4] <= 41) {
                                if (features[4] <= 41) {
                                    if (features[2] <= 87) {
                                        if (features[0] <= 168) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 82) {
                                                    if (features[0] <= 171) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 163) {
                                            if (features[3] <= 38) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[3] <= 63) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 41) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 113) {
                            if (features[3] <= 63) {
                                if (features[1] <= 105) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 226) {
                        if (features[4] <= 115) {
                            if (features[1] <= 112) {
                                if (features[2] <= 83) {
                                    return 1;
                                } else {
                                    if (features[4] <= 110) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[0] <= 192) {
                                    return 0;
                                } else {
                                    if (features[3] <= 102) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 102) {
                            return 1;
                        } else {
                            if (features[3] <= 107) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 234) {
                    if (features[0] <= 230) {
                        if (features[4] <= 118) {
                            if (features[4] <= 79) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 102) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_39(unsigned short features[]) {
    if (features[0] <= 110) {
        if (features[2] <= 56) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[0] <= 41) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[3] <= 13) {
                    if (features[1] <= 120) {
                        if (features[4] <= 3) {
                            return 0;
                        } else {
                            if (features[2] <= 70) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[2] <= 61) {
            if (features[3] <= 39) {
                return 0;
            } else {
                if (features[3] <= 40) {
                    return 1;
                } else {
                    if (features[1] <= 82) {
                        return 0;
                    } else {
                        if (features[3] <= 69) {
                            return 1;
                        } else {
                            if (features[2] <= 5) {
                                return 0;
                            } else {
                                if (features[1] <= 148) {
                                    return 0;
                                } else {
                                    if (features[4] <= 175) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 227) {
                if (features[3] <= 76) {
                    if (features[0] <= 203) {
                        if (features[4] <= 100) {
                            return 1;
                        } else {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[4] <= 111) {
                            if (features[1] <= 105) {
                                if (features[2] <= 78) {
                                    return 0;
                                } else {
                                    if (features[3] <= 63) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 99) {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[3] <= 99) {
                                return 1;
                            } else {
                                if (features[1] <= 111) {
                                    return 1;
                                } else {
                                    if (features[4] <= 127) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 115) {
                    if (features[4] <= 122) {
                        return 1;
                    } else {
                        if (features[3] <= 98) {
                            return 0;
                        } else {
                            if (features[2] <= 105) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_40(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 28) {
            return 0;
        } else {
            if (features[1] <= 34) {
                if (features[0] <= 146) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[0] <= 238) {
                    if (features[1] <= 65) {
                        if (features[4] <= 47) {
                            return 0;
                        } else {
                            if (features[2] <= 29) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[3] <= 10) {
                            return 0;
                        } else {
                            if (features[4] <= 75) {
                                if (features[2] <= 24) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[4] <= 5) {
            return 0;
        } else {
            if (features[0] <= 205) {
                if (features[1] <= 25) {
                    if (features[0] <= 91) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 64) {
                        if (features[3] <= 63) {
                            if (features[4] <= 27) {
                                if (features[0] <= 159) {
                                    return 1;
                                } else {
                                    if (features[1] <= 29) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[1] <= 42) {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 62) {
                                            if (features[4] <= 40) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 80) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 81) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[1] <= 113) {
                                return 1;
                            } else {
                                if (features[1] <= 113) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 76) {
                    if (features[3] <= 63) {
                        if (features[2] <= 76) {
                            return 1;
                        } else {
                            if (features[4] <= 110) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[3] <= 102) {
                            if (features[3] <= 101) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 89) {
                            if (features[2] <= 86) {
                                return 1;
                            } else {
                                if (features[0] <= 237) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_41(unsigned short features[]) {
    if (features[3] <= 29) {
        if (features[3] <= 13) {
            if (features[3] <= 10) {
                if (features[0] <= 69) {
                    if (features[0] <= 32) {
                        return 0;
                    } else {
                        if (features[2] <= 47) {
                            return 0;
                        } else {
                            if (features[0] <= 45) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 7) {
                        if (features[2] <= 68) {
                            return 0;
                        } else {
                            if (features[3] <= 7) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 78) {
                            return 1;
                        } else {
                            if (features[2] <= 64) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[1] <= 49) {
                    if (features[4] <= 11) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[1] <= 61) {
                if (features[2] <= 34) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 121) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[1] <= 189) {
            if (features[3] <= 58) {
                if (features[1] <= 36) {
                    if (features[2] <= 29) {
                        return 0;
                    } else {
                        if (features[3] <= 38) {
                            return 1;
                        } else {
                            if (features[3] <= 38) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[4] <= 76) {
                        if (features[0] <= 168) {
                            if (features[2] <= 41) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 60) {
                                if (features[2] <= 31) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 32) {
                            return 0;
                        } else {
                            if (features[0] <= 200) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 230) {
                    if (features[4] <= 70) {
                        if (features[1] <= 43) {
                            if (features[2] <= 79) {
                                if (features[2] <= 78) {
                                    return 1;
                                } else {
                                    if (features[4] <= 41) {
                                        if (features[4] <= 41) {
                                            if (features[3] <= 62) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 38) {
                            return 0;
                        } else {
                            if (features[3] <= 76) {
                                if (features[1] <= 100) {
                                    return 1;
                                } else {
                                    if (features[0] <= 203) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 106) {
                                            if (features[4] <= 111) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                if (features[0] <= 227) {
                                    return 1;
                                } else {
                                    if (features[4] <= 124) {
                                        if (features[3] <= 102) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 109) {
                        if (features[1] <= 106) {
                            if (features[0] <= 238) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[0] <= 148) {
                return 0;
            } else {
                if (features[2] <= 29) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_42(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[2] <= 35) {
            return 0;
        } else {
            if (features[3] <= 9) {
                if (features[2] <= 59) {
                    return 0;
                } else {
                    if (features[0] <= 156) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 7) {
            return 0;
        } else {
            if (features[3] <= 13) {
                if (features[0] <= 54) {
                    if (features[0] <= 32) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 108) {
                    if (features[1] <= 43) {
                        if (features[3] <= 63) {
                            if (features[3] <= 62) {
                                if (features[1] <= 30) {
                                    if (features[0] <= 163) {
                                        if (features[4] <= 19) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 42) {
                                    if (features[3] <= 62) {
                                        if (features[2] <= 80) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[2] <= 82) {
                                if (features[1] <= 42) {
                                    return 1;
                                } else {
                                    if (features[3] <= 65) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[0] <= 201) {
                            return 1;
                        } else {
                            if (features[1] <= 114) {
                                if (features[1] <= 106) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 230) {
                            if (features[4] <= 115) {
                                if (features[3] <= 99) {
                                    return 1;
                                } else {
                                    if (features[3] <= 99) {
                                        if (features[1] <= 109) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[4] <= 115) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 102) {
                                if (features[3] <= 92) {
                                    return 1;
                                } else {
                                    if (features[2] <= 89) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_43(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[4] <= 247) {
            if (features[3] <= 68) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[2] <= 48) {
                        return 1;
                    } else {
                        if (features[1] <= 27) {
                            return 0;
                        } else {
                            if (features[4] <= 67) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                if (features[2] <= 24) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 230) {
            if (features[3] <= 7) {
                if (features[3] <= 4) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[0] <= 36) {
                    if (features[4] <= 77) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        if (features[1] <= 113) {
                            if (features[4] <= 109) {
                                if (features[1] <= 30) {
                                    if (features[1] <= 30) {
                                        if (features[1] <= 29) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 26) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 29) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 81) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 81) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[1] <= 107) {
                                    if (features[3] <= 87) {
                                        if (features[2] <= 74) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 106) {
                                                if (features[4] <= 111) {
                                                    return 0;
                                                } else {
                                                    if (features[4] <= 111) {
                                                        if (features[3] <= 63) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 124) {
                                        if (features[4] <= 114) {
                                            if (features[1] <= 112) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 114) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[1] <= 113) {
                                                if (features[4] <= 115) {
                                                    if (features[2] <= 76) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    if (features[4] <= 124) {
                                                        return 1;
                                                    } else {
                                                        if (features[4] <= 124) {
                                                            if (features[2] <= 86) {
                                                                return 1;
                                                            } else {
                                                                return 0;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 110) {
                if (features[3] <= 92) {
                    return 1;
                } else {
                    if (features[2] <= 113) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[4] <= 129) {
                    if (features[3] <= 110) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_44(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[3] <= 230) {
            if (features[0] <= 142) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[1] <= 63) {
                        return 0;
                    } else {
                        if (features[3] <= 7) {
                            if (features[4] <= 48) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[0] <= 32) {
                                return 0;
                            } else {
                                if (features[0] <= 33) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[4] <= 83) {
                    if (features[0] <= 144) {
                        if (features[4] <= 31) {
                            if (features[3] <= 22) {
                                return 0;
                            } else {
                                if (features[1] <= 34) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 74) {
                        return 1;
                    } else {
                        if (features[4] <= 175) {
                            if (features[4] <= 174) {
                                if (features[1] <= 105) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[4] <= 12) {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 1;
            }
        } else {
            if (features[0] <= 227) {
                if (features[0] <= 204) {
                    if (features[3] <= 13) {
                        if (features[4] <= 77) {
                            if (features[1] <= 66) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 30) {
                            if (features[0] <= 163) {
                                if (features[0] <= 159) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 43) {
                                if (features[1] <= 43) {
                                    return 1;
                                } else {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[2] <= 76) {
                                    return 1;
                                } else {
                                    if (features[0] <= 193) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 114) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 113) {
                                                if (features[4] <= 115) {
                                                    if (features[3] <= 102) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[3] <= 63) {
                            if (features[3] <= 61) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[4] <= 122) {
                    return 1;
                } else {
                    if (features[4] <= 129) {
                        if (features[2] <= 86) {
                            return 1;
                        } else {
                            if (features[3] <= 110) {
                                return 0;
                            } else {
                                if (features[2] <= 89) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_45(unsigned short features[]) {
    if (features[4] <= 114) {
        if (features[2] <= 63) {
            if (features[3] <= 66) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[0] <= 45) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 26) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 7) {
                if (features[3] <= 5) {
                    if (features[2] <= 69) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[1] <= 104) {
                    if (features[0] <= 71) {
                        if (features[1] <= 23) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 30) {
                            if (features[3] <= 37) {
                                return 1;
                            } else {
                                if (features[0] <= 168) {
                                    if (features[1] <= 30) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 64) {
                                if (features[0] <= 168) {
                                    return 1;
                                } else {
                                    if (features[4] <= 41) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 171) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 201) {
                        if (features[0] <= 36) {
                            if (features[4] <= 78) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[1] <= 107) {
                                return 0;
                            } else {
                                if (features[2] <= 82) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[0] <= 123) {
            if (features[2] <= 35) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 30) {
                return 0;
            } else {
                if (features[1] <= 109) {
                    if (features[1] <= 106) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[2] <= 87) {
                            return 1;
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[4] <= 126) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 109) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_46(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 247) {
            if (features[0] <= 238) {
                if (features[2] <= 59) {
                    if (features[0] <= 142) {
                        return 0;
                    } else {
                        if (features[2] <= 48) {
                            return 0;
                        } else {
                            if (features[0] <= 150) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 156) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 240) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 230) {
            if (features[3] <= 13) {
                if (features[3] <= 7) {
                    if (features[4] <= 3) {
                        return 1;
                    } else {
                        if (features[4] <= 3) {
                            if (features[0] <= 71) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 70) {
                        if (features[4] <= 79) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 204) {
                    if (features[2] <= 75) {
                        return 1;
                    } else {
                        if (features[0] <= 201) {
                            if (features[1] <= 30) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    if (features[3] <= 40) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 113) {
                                    return 1;
                                } else {
                                    if (features[3] <= 99) {
                                        if (features[1] <= 123) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 110) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 108) {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[3] <= 63) {
                                if (features[2] <= 75) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[1] <= 116) {
                if (features[3] <= 92) {
                    return 1;
                } else {
                    if (features[3] <= 111) {
                        if (features[2] <= 108) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_47(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[0] <= 113) {
            if (features[1] <= 150) {
                if (features[4] <= 112) {
                    if (features[3] <= 12) {
                        if (features[2] <= 53) {
                            return 0;
                        } else {
                            if (features[0] <= 109) {
                                if (features[4] <= 77) {
                                    if (features[2] <= 70) {
                                        if (features[4] <= 4) {
                                            if (features[1] <= 22) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[1] <= 92) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 32) {
                            return 0;
                        } else {
                            if (features[3] <= 13) {
                                if (features[2] <= 67) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[4] <= 37) {
                if (features[1] <= 25) {
                    return 0;
                } else {
                    if (features[2] <= 46) {
                        return 0;
                    } else {
                        if (features[4] <= 27) {
                            return 1;
                        } else {
                            if (features[4] <= 28) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 58) {
                    if (features[1] <= 80) {
                        if (features[2] <= 33) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 200) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[0] <= 204) {
                        if (features[4] <= 70) {
                            if (features[4] <= 41) {
                                if (features[4] <= 41) {
                                    if (features[4] <= 40) {
                                        if (features[1] <= 42) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 157) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 78) {
                                                    if (features[2] <= 78) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 77) {
                                return 0;
                            } else {
                                if (features[2] <= 18) {
                                    return 0;
                                } else {
                                    if (features[3] <= 99) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 106) {
                            if (features[4] <= 109) {
                                return 1;
                            } else {
                                if (features[3] <= 61) {
                                    return 0;
                                } else {
                                    if (features[2] <= 81) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[3] <= 91) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[3] <= 88) {
            if (features[1] <= 167) {
                if (features[1] <= 110) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[0] <= 230) {
                    if (features[4] <= 115) {
                        if (features[3] <= 100) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 112) {
                            if (features[1] <= 112) {
                                return 1;
                            } else {
                                if (features[3] <= 102) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 109) {
                        if (features[1] <= 113) {
                            if (features[3] <= 97) {
                                if (features[4] <= 122) {
                                    if (features[3] <= 90) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_48(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[4] <= 115) {
            if (features[0] <= 32) {
                if (features[3] <= 11) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 81) {
                    if (features[1] <= 117) {
                        if (features[4] <= 5) {
                            if (features[0] <= 69) {
                                return 0;
                            } else {
                                if (features[0] <= 73) {
                                    return 1;
                                } else {
                                    if (features[4] <= 3) {
                                        if (features[4] <= 3) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 4) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 50) {
                                return 0;
                            } else {
                                if (features[2] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 11) {
                            if (features[4] <= 79) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 56) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[3] <= 50) {
                return 0;
            } else {
                if (features[4] <= 151) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[3] <= 27) {
            if (features[2] <= 63) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[0] <= 163) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[1] <= 30) {
                        if (features[3] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 27) {
                    return 0;
                } else {
                    if (features[0] <= 234) {
                        if (features[1] <= 116) {
                            if (features[1] <= 104) {
                                if (features[4] <= 41) {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 79) {
                                            if (features[0] <= 171) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[0] <= 169) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 204) {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 192) {
                                            return 0;
                                        } else {
                                            if (features[4] <= 115) {
                                                if (features[3] <= 99) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (features[2] <= 75) {
                                        if (features[3] <= 83) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[1] <= 110) {
                                            if (features[2] <= 78) {
                                                return 0;
                                            } else {
                                                if (features[1] <= 106) {
                                                    if (features[3] <= 63) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    if (features[3] <= 76) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[2] <= 90) {
                                                if (features[4] <= 124) {
                                                    if (features[2] <= 86) {
                                                        return 1;
                                                    } else {
                                                        if (features[4] <= 124) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                } else {
                                                    if (features[2] <= 88) {
                                                        return 0;
                                                    } else {
                                                        if (features[1] <= 115) {
                                                            return 0;
                                                        } else {
                                                            if (features[3] <= 110) {
                                                                return 1;
                                                            } else {
                                                                return 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 121) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_49(unsigned short features[]) {
    if (features[0] <= 138) {
        if (features[2] <= 54) {
            return 0;
        } else {
            if (features[4] <= 15) {
                if (features[2] <= 69) {
                    return 1;
                } else {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[2] <= 61) {
            if (features[4] <= 247) {
                if (features[1] <= 34) {
                    return 0;
                } else {
                    if (features[1] <= 35) {
                        return 1;
                    } else {
                        if (features[0] <= 238) {
                            if (features[2] <= 27) {
                                if (features[4] <= 173) {
                                    return 0;
                                } else {
                                    if (features[3] <= 143) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[0] <= 200) {
                if (features[4] <= 41) {
                    if (features[1] <= 42) {
                        if (features[0] <= 163) {
                            if (features[0] <= 159) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 41) {
                            if (features[1] <= 42) {
                                if (features[0] <= 170) {
                                    if (features[2] <= 78) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 78) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 79) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 190) {
                        return 1;
                    } else {
                        if (features[0] <= 191) {
                            if (features[4] <= 112) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[4] <= 114) {
                                return 1;
                            } else {
                                if (features[4] <= 115) {
                                    if (features[3] <= 101) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 76) {
                    if (features[0] <= 203) {
                        if (features[1] <= 112) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 97) {
                        if (features[0] <= 223) {
                            return 1;
                        } else {
                            if (features[2] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[0] <= 230) {
                            if (features[3] <= 103) {
                                if (features[3] <= 103) {
                                    return 1;
                                } else {
                                    if (features[4] <= 126) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 111) {
                                if (features[2] <= 89) {
                                    if (features[2] <= 87) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_50(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[1] <= 125) {
            if (features[1] <= 69) {
                if (features[4] <= 52) {
                    if (features[2] <= 50) {
                        return 0;
                    } else {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[4] <= 48) {
                                return 1;
                            } else {
                                if (features[1] <= 66) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 13) {
                    if (features[2] <= 67) {
                        if (features[0] <= 32) {
                            return 0;
                        } else {
                            if (features[2] <= 41) {
                                return 0;
                            } else {
                                if (features[4] <= 76) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 58) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[4] <= 37) {
            if (features[2] <= 61) {
                if (features[4] <= 28) {
                    return 0;
                } else {
                    if (features[2] <= 31) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[4] <= 27) {
                    return 1;
                } else {
                    if (features[1] <= 30) {
                        if (features[0] <= 164) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 42) {
                return 0;
            } else {
                if (features[2] <= 86) {
                    if (features[0] <= 204) {
                        if (features[1] <= 43) {
                            if (features[3] <= 63) {
                                return 1;
                            } else {
                                if (features[3] <= 64) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 115) {
                                if (features[4] <= 115) {
                                    if (features[1] <= 112) {
                                        if (features[3] <= 58) {
                                            if (features[2] <= 74) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[0] <= 192) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 99) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 112) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[1] <= 106) {
                                    if (features[4] <= 110) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 75) {
                                            if (features[2] <= 74) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 106) {
                        return 1;
                    } else {
                        if (features[3] <= 97) {
                            return 0;
                        } else {
                            if (features[0] <= 228) {
                                return 1;
                            } else {
                                if (features[1] <= 114) {
                                    return 0;
                                } else {
                                    if (features[1] <= 116) {
                                        if (features[3] <= 110) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 110) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 128) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_51(unsigned short features[]) {
    if (features[3] <= 28) {
        if (features[0] <= 106) {
            if (features[0] <= 32) {
                if (features[2] <= 63) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 119) {
                    if (features[3] <= 13) {
                        if (features[1] <= 29) {
                            if (features[3] <= 7) {
                                return 0;
                            } else {
                                if (features[1] <= 25) {
                                    if (features[2] <= 68) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 28) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 34) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[4] <= 11) {
                            return 1;
                        } else {
                            if (features[0] <= 91) {
                                if (features[2] <= 34) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 56) {
                        return 0;
                    } else {
                        if (features[4] <= 82) {
                            if (features[4] <= 77) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 13) {
                if (features[1] <= 55) {
                    return 0;
                } else {
                    if (features[4] <= 47) {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[2] <= 29) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 68) {
                            if (features[0] <= 107) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[0] <= 129) {
                    if (features[2] <= 33) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[2] <= 31) {
            if (features[3] <= 131) {
                return 0;
            } else {
                if (features[3] <= 132) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[0] <= 230) {
                if (features[3] <= 76) {
                    if (features[4] <= 107) {
                        if (features[4] <= 42) {
                            if (features[3] <= 62) {
                                if (features[2] <= 87) {
                                    return 1;
                                } else {
                                    if (features[2] <= 87) {
                                        if (features[4] <= 29) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 62) {
                                    if (features[2] <= 78) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 171) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[3] <= 64) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 201) {
                            return 1;
                        } else {
                            if (features[1] <= 113) {
                                if (features[4] <= 111) {
                                    if (features[2] <= 78) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 100) {
                        if (features[3] <= 99) {
                            return 1;
                        } else {
                            if (features[1] <= 112) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 89) {
                    return 1;
                } else {
                    if (features[1] <= 115) {
                        if (features[4] <= 124) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}
int predict_tree_52(unsigned short features[]) {
    if (features[3] <= 33) {
        if (features[2] <= 62) {
            return 0;
        } else {
            if (features[1] <= 26) {
                if (features[3] <= 7) {
                    if (features[1] <= 22) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 34) {
                    if (features[3] <= 11) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 10) {
                        if (features[3] <= 9) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[1] <= 190) {
            if (features[2] <= 31) {
                return 0;
            } else {
                if (features[0] <= 241) {
                    if (features[3] <= 68) {
                        if (features[4] <= 107) {
                            if (features[1] <= 30) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    if (features[4] <= 27) {
                                        if (features[2] <= 86) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 78) {
                                    return 1;
                                } else {
                                    if (features[3] <= 62) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 43) {
                                            if (features[0] <= 171) {
                                                if (features[3] <= 62) {
                                                    return 0;
                                                } else {
                                                    if (features[3] <= 63) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 109) {
                                if (features[0] <= 200) {
                                    return 1;
                                } else {
                                    if (features[3] <= 63) {
                                        if (features[2] <= 78) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 112) {
                            return 1;
                        } else {
                            if (features[2] <= 84) {
                                if (features[4] <= 115) {
                                    if (features[3] <= 100) {
                                        if (features[1] <= 113) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 109) {
                                    return 0;
                                } else {
                                    if (features[1] <= 115) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 226) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 86) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 232) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 230) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 117) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 127) {
                if (features[3] <= 120) {
                    return 0;
                } else {
                    if (features[2] <= 38) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 27) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_53(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[4] <= 92) {
            if (features[3] <= 13) {
                if (features[4] <= 11) {
                    if (features[3] <= 8) {
                        if (features[2] <= 68) {
                            return 0;
                        } else {
                            if (features[1] <= 24) {
                                if (features[0] <= 73) {
                                    if (features[0] <= 70) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 27) {
                            return 1;
                        } else {
                            if (features[3] <= 10) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 67) {
                        if (features[3] <= 10) {
                            if (features[2] <= 59) {
                                return 0;
                            } else {
                                if (features[2] <= 59) {
                                    if (features[3] <= 7) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[1] <= 116) {
                                return 0;
                            } else {
                                if (features[4] <= 77) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 70) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 32) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 0;
        }
    } else {
        if (features[1] <= 189) {
            if (features[2] <= 31) {
                if (features[2] <= 5) {
                    return 0;
                } else {
                    if (features[4] <= 169) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 230) {
                    if (features[1] <= 104) {
                        if (features[1] <= 42) {
                            if (features[1] <= 42) {
                                if (features[0] <= 163) {
                                    if (features[4] <= 27) {
                                        if (features[2] <= 87) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[4] <= 28) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 62) {
                                    return 1;
                                } else {
                                    if (features[4] <= 40) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[2] <= 80) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 111) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[2] <= 80) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 113) {
                                if (features[1] <= 113) {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 122) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 86) {
                        return 1;
                    } else {
                        if (features[3] <= 110) {
                            if (features[3] <= 97) {
                                return 0;
                            } else {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 27) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_54(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 247) {
            if (features[0] <= 238) {
                if (features[3] <= 40) {
                    if (features[2] <= 59) {
                        return 0;
                    } else {
                        if (features[4] <= 34) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 40) {
                        return 1;
                    } else {
                        if (features[2] <= 31) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 49) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[0] <= 230) {
            if (features[3] <= 7) {
                if (features[4] <= 3) {
                    if (features[3] <= 4) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 76) {
                    if (features[4] <= 107) {
                        if (features[2] <= 79) {
                            if (features[1] <= 121) {
                                if (features[2] <= 70) {
                                    if (features[2] <= 70) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 49) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 124) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 38) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    if (features[4] <= 26) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 37) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 63) {
                                    return 1;
                                } else {
                                    if (features[3] <= 64) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 74) {
                            if (features[4] <= 112) {
                                if (features[4] <= 112) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 106) {
                                if (features[3] <= 62) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 113) {
                        if (features[3] <= 99) {
                            return 1;
                        } else {
                            if (features[1] <= 113) {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[1] <= 112) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 114) {
                                            return 0;
                                        } else {
                                            if (features[2] <= 75) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 100) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 105) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_55(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 65) {
            if (features[0] <= 106) {
                return 0;
            } else {
                if (features[4] <= 43) {
                    return 0;
                } else {
                    if (features[4] <= 47) {
                        if (features[2] <= 29) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 7) {
                if (features[1] <= 22) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[1] <= 120) {
                    return 1;
                } else {
                    if (features[0] <= 36) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[0] <= 113) {
            if (features[2] <= 32) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 42) {
                if (features[3] <= 132) {
                    return 0;
                } else {
                    if (features[1] <= 205) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 234) {
                    if (features[4] <= 108) {
                        if (features[3] <= 38) {
                            if (features[1] <= 31) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    if (features[4] <= 27) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 79) {
                            if (features[4] <= 116) {
                                if (features[4] <= 111) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 228) {
                                if (features[4] <= 115) {
                                    if (features[1] <= 113) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 88) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[4] <= 122) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}
int predict_tree_56(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[2] <= 58) {
            return 0;
        } else {
            if (features[1] <= 24) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 36) {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[4] <= 32) {
            if (features[2] <= 65) {
                return 0;
            } else {
                if (features[0] <= 159) {
                    return 1;
                } else {
                    if (features[1] <= 29) {
                        return 1;
                    } else {
                        if (features[4] <= 27) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 31) {
                if (features[1] <= 188) {
                    return 0;
                } else {
                    if (features[4] <= 175) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 100) {
                    if (features[0] <= 204) {
                        if (features[3] <= 99) {
                            if (features[1] <= 43) {
                                if (features[3] <= 63) {
                                    return 1;
                                } else {
                                    if (features[3] <= 64) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 108) {
                                    return 1;
                                } else {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 113) {
                                if (features[0] <= 191) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 73) {
                            return 1;
                        } else {
                            if (features[1] <= 111) {
                                if (features[2] <= 78) {
                                    return 0;
                                } else {
                                    if (features[0] <= 230) {
                                        if (features[4] <= 113) {
                                            if (features[2] <= 81) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[3] <= 87) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[3] <= 92) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 230) {
                        return 1;
                    } else {
                        if (features[3] <= 111) {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_57(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[2] <= 35) {
            if (features[4] <= 175) {
                return 0;
            } else {
                if (features[1] <= 200) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 9) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 25) {
            if (features[1] <= 22) {
                if (features[0] <= 74) {
                    if (features[0] <= 73) {
                        if (features[2] <= 69) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[3] <= 13) {
                if (features[2] <= 67) {
                    return 0;
                } else {
                    if (features[3] <= 10) {
                        if (features[3] <= 9) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 86) {
                    if (features[0] <= 200) {
                        if (features[1] <= 43) {
                            if (features[4] <= 41) {
                                if (features[3] <= 62) {
                                    return 1;
                                } else {
                                    if (features[2] <= 79) {
                                        if (features[4] <= 40) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[0] <= 171) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[4] <= 113) {
                                    return 1;
                                } else {
                                    if (features[4] <= 113) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 115) {
                                            if (features[3] <= 100) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 114) {
                            if (features[4] <= 108) {
                                return 1;
                            } else {
                                if (features[3] <= 87) {
                                    if (features[2] <= 80) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[4] <= 85) {
                            if (features[4] <= 27) {
                                if (features[1] <= 29) {
                                    return 1;
                                } else {
                                    if (features[3] <= 38) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 110) {
                                return 0;
                            } else {
                                if (features[0] <= 227) {
                                    return 1;
                                } else {
                                    if (features[1] <= 114) {
                                        if (features[2] <= 86) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 112) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 114) {
                            if (features[2] <= 109) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 232) {
                                if (features[3] <= 110) {
                                    return 0;
                                } else {
                                    if (features[3] <= 110) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_58(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[0] <= 238) {
            if (features[2] <= 59) {
                if (features[3] <= 40) {
                    return 0;
                } else {
                    if (features[4] <= 28) {
                        if (features[2] <= 29) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 159) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 57) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 25) {
            if (features[1] <= 24) {
                if (features[2] <= 69) {
                    if (features[3] <= 7) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 89) {
                if (features[0] <= 200) {
                    if (features[2] <= 76) {
                        return 1;
                    } else {
                        if (features[3] <= 100) {
                            if (features[3] <= 99) {
                                if (features[4] <= 41) {
                                    if (features[1] <= 43) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 113) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[4] <= 111) {
                            return 0;
                        } else {
                            if (features[3] <= 63) {
                                return 1;
                            } else {
                                if (features[4] <= 118) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[0] <= 226) {
                            return 1;
                        } else {
                            if (features[4] <= 123) {
                                return 1;
                            } else {
                                if (features[1] <= 114) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 230) {
                    if (features[3] <= 71) {
                        if (features[1] <= 29) {
                            if (features[1] <= 28) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 86) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 113) {
                        if (features[1] <= 117) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_59(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[2] <= 54) {
            return 0;
        } else {
            if (features[3] <= 7) {
                if (features[1] <= 22) {
                    if (features[0] <= 74) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[4] <= 3) {
                    return 0;
                } else {
                    if (features[0] <= 34) {
                        if (features[4] <= 77) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 66) {
                            if (features[1] <= 65) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[1] <= 40) {
            if (features[3] <= 26) {
                return 0;
            } else {
                if (features[2] <= 46) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[0] <= 119) {
                if (features[2] <= 33) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 58) {
                    if (features[0] <= 133) {
                        if (features[1] <= 41) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 35) {
                            return 0;
                        } else {
                            if (features[3] <= 57) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 36) {
                        return 0;
                    } else {
                        if (features[2] <= 86) {
                            if (features[0] <= 204) {
                                if (features[1] <= 43) {
                                    if (features[4] <= 41) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 171) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 115) {
                                        if (features[4] <= 115) {
                                            if (features[4] <= 114) {
                                                if (features[3] <= 58) {
                                                    if (features[0] <= 201) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (features[2] <= 77) {
                                                    if (features[2] <= 76) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 112) {
                                    if (features[3] <= 82) {
                                        if (features[1] <= 106) {
                                            if (features[2] <= 75) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 76) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 238) {
                                if (features[0] <= 203) {
                                    return 1;
                                } else {
                                    if (features[1] <= 110) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 111) {
                                            if (features[0] <= 228) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 105) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[4] <= 130) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 91) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_60(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[3] <= 13) {
            if (features[4] <= 5) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 119) {
                    if (features[1] <= 117) {
                        if (features[0] <= 105) {
                            return 0;
                        } else {
                            if (features[1] <= 55) {
                                return 0;
                            } else {
                                if (features[2] <= 45) {
                                    return 0;
                                } else {
                                    if (features[2] <= 65) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 9) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 32) {
                return 0;
            } else {
                if (features[3] <= 13) {
                    if (features[4] <= 67) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[3] <= 57) {
            if (features[0] <= 104) {
                if (features[4] <= 134) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[4] <= 24) {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        if (features[4] <= 27) {
                            if (features[2] <= 87) {
                                return 1;
                            } else {
                                if (features[2] <= 87) {
                                    return 0;
                                } else {
                                    if (features[0] <= 165) {
                                        if (features[1] <= 30) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 123) {
                if (features[2] <= 35) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 221) {
                    if (features[1] <= 103) {
                        if (features[1] <= 47) {
                            if (features[1] <= 47) {
                                if (features[2] <= 38) {
                                    return 0;
                                } else {
                                    if (features[2] <= 79) {
                                        if (features[1] <= 43) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 42) {
                                                    if (features[2] <= 79) {
                                                        return 0;
                                                    } else {
                                                        if (features[1] <= 42) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 57) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[3] <= 66) {
                                if (features[3] <= 65) {
                                    if (features[1] <= 49) {
                                        if (features[1] <= 48) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 37) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[4] <= 78) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 79) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[2] <= 35) {
                            if (features[4] <= 173) {
                                return 0;
                            } else {
                                if (features[1] <= 189) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[4] <= 115) {
                                if (features[0] <= 200) {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 115) {
                                            if (features[2] <= 76) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 100) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[3] <= 76) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[0] <= 228) {
                                    return 1;
                                } else {
                                    if (features[2] <= 104) {
                                        if (features[4] <= 122) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 111) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[3] <= 97) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 180) {
                        return 0;
                    } else {
                        if (features[2] <= 27) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_61(unsigned short features[]) {
    if (features[3] <= 24) {
        if (features[2] <= 62) {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[0] <= 105) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        if (features[0] <= 109) {
                            if (features[1] <= 65) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[0] <= 36) {
                    if (features[3] <= 11) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[2] <= 41) {
            return 0;
        } else {
            if (features[4] <= 108) {
                if (features[1] <= 30) {
                    if (features[0] <= 163) {
                        if (features[4] <= 26) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[4] <= 41) {
                        if (features[4] <= 41) {
                            return 1;
                        } else {
                            if (features[3] <= 61) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 107) {
                    if (features[3] <= 94) {
                        if (features[3] <= 81) {
                            if (features[1] <= 107) {
                                if (features[4] <= 111) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 107) {
                                if (features[4] <= 122) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 86) {
                        if (features[1] <= 113) {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[3] <= 101) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 227) {
                            if (features[4] <= 116) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 114) {
                                if (features[2] <= 109) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 91) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_62(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[3] <= 13) {
            if (features[2] <= 66) {
                if (features[2] <= 59) {
                    if (features[4] <= 75) {
                        return 0;
                    } else {
                        if (features[4] <= 75) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[2] <= 59) {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 4) {
                    if (features[2] <= 67) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[4] <= 47) {
                if (features[0] <= 120) {
                    if (features[2] <= 34) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 32) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[0] <= 114) {
            if (features[2] <= 32) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 31) {
                return 0;
            } else {
                if (features[0] <= 240) {
                    if (features[3] <= 76) {
                        if (features[4] <= 101) {
                            if (features[4] <= 41) {
                                if (features[1] <= 43) {
                                    if (features[1] <= 29) {
                                        if (features[0] <= 163) {
                                            if (features[2] <= 87) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 45) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 111) {
                                if (features[4] <= 111) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            if (features[3] <= 100) {
                                if (features[3] <= 100) {
                                    if (features[3] <= 99) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 99) {
                                            if (features[2] <= 75) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[0] <= 191) {
                                                if (features[4] <= 112) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 114) {
                                if (features[4] <= 125) {
                                    if (features[3] <= 102) {
                                        if (features[1] <= 111) {
                                            if (features[4] <= 122) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_63(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[0] <= 142) {
            if (features[3] <= 20) {
                if (features[3] <= 13) {
                    if (features[2] <= 66) {
                        if (features[3] <= 10) {
                            return 0;
                        } else {
                            if (features[2] <= 24) {
                                return 0;
                            } else {
                                if (features[3] <= 11) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 25) {
                            if (features[3] <= 7) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 33) {
                        return 0;
                    } else {
                        if (features[3] <= 13) {
                            if (features[1] <= 96) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 32) {
                    if (features[2] <= 32) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[3] <= 41) {
                        if (features[4] <= 25) {
                            return 1;
                        } else {
                            if (features[4] <= 59) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[3] <= 31) {
                return 0;
            } else {
                if (features[2] <= 28) {
                    return 0;
                } else {
                    if (features[0] <= 204) {
                        if (features[1] <= 112) {
                            if (features[3] <= 38) {
                                if (features[0] <= 164) {
                                    if (features[0] <= 153) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 64) {
                                    if (features[3] <= 64) {
                                        if (features[2] <= 79) {
                                            if (features[2] <= 78) {
                                                if (features[0] <= 201) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 99) {
                                return 0;
                            } else {
                                if (features[4] <= 115) {
                                    return 1;
                                } else {
                                    if (features[1] <= 113) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 105) {
                            return 1;
                        } else {
                            if (features[3] <= 89) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[0] <= 114) {
            if (features[4] <= 149) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 230) {
                if (features[4] <= 190) {
                    if (features[2] <= 49) {
                        if (features[1] <= 188) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 227) {
                            return 1;
                        } else {
                            if (features[2] <= 97) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 213) {
                        if (features[1] <= 220) {
                            if (features[2] <= 38) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 176) {
                                return 0;
                            } else {
                                if (features[4] <= 229) {
                                    return 1;
                                } else {
                                    if (features[2] <= 36) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 110) {
                    if (features[4] <= 119) {
                        return 1;
                    } else {
                        if (features[1] <= 106) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 110) {
                        return 1;
                    } else {
                        if (features[4] <= 129) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_64(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[0] <= 138) {
            if (features[3] <= 13) {
                if (features[0] <= 106) {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        if (features[1] <= 25) {
                            return 1;
                        } else {
                            if (features[4] <= 8) {
                                if (features[3] <= 8) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 67) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[2] <= 52) {
                        return 0;
                    } else {
                        if (features[4] <= 30) {
                            return 0;
                        } else {
                            if (features[1] <= 66) {
                                if (features[1] <= 65) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[4] <= 33) {
                    if (features[4] <= 24) {
                        if (features[2] <= 34) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 42) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 136) {
                        return 1;
                    } else {
                        if (features[3] <= 33) {
                            return 0;
                        } else {
                            if (features[3] <= 35) {
                                return 1;
                            } else {
                                if (features[3] <= 46) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 61) {
                if (features[3] <= 67) {
                    if (features[1] <= 34) {
                        return 0;
                    } else {
                        if (features[4] <= 28) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[1] <= 95) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 104) {
                    if (features[4] <= 41) {
                        if (features[4] <= 41) {
                            if (features[3] <= 38) {
                                if (features[3] <= 38) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 77) {
                                return 1;
                            } else {
                                if (features[3] <= 60) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 107) {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[0] <= 198) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 113) {
                            return 1;
                        } else {
                            if (features[3] <= 99) {
                                if (features[0] <= 203) {
                                    if (features[3] <= 80) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[2] <= 44) {
            if (features[0] <= 154) {
                return 0;
            } else {
                if (features[0] <= 157) {
                    if (features[2] <= 5) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 109) {
                if (features[1] <= 106) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[4] <= 129) {
                    if (features[0] <= 227) {
                        return 1;
                    } else {
                        if (features[1] <= 115) {
                            return 0;
                        } else {
                            if (features[3] <= 110) {
                                return 0;
                            } else {
                                if (features[2] <= 89) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_65(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[4] <= 247) {
            if (features[2] <= 48) {
                return 0;
            } else {
                if (features[1] <= 27) {
                    return 0;
                } else {
                    if (features[3] <= 21) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 25) {
            if (features[4] <= 3) {
                if (features[0] <= 71) {
                    return 0;
                } else {
                    if (features[2] <= 71) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 69) {
                    if (features[0] <= 73) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 93) {
                if (features[3] <= 76) {
                    if (features[4] <= 107) {
                        if (features[3] <= 12) {
                            if (features[3] <= 11) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 42) {
                                if (features[4] <= 41) {
                                    if (features[1] <= 42) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 78) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 43) {
                                                if (features[3] <= 62) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 63) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                if (features[0] <= 159) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 201) {
                            return 1;
                        } else {
                            if (features[4] <= 118) {
                                if (features[4] <= 111) {
                                    if (features[2] <= 78) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 81) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 86) {
                        if (features[3] <= 100) {
                            if (features[3] <= 100) {
                                if (features[3] <= 99) {
                                    return 1;
                                } else {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 76) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 106) {
                            return 1;
                        } else {
                            if (features[1] <= 114) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 230) {
                    if (features[3] <= 86) {
                        if (features[4] <= 79) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 108) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_66(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 233) {
            if (features[0] <= 105) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[0] <= 41) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 34) {
                    return 0;
                } else {
                    if (features[0] <= 235) {
                        if (features[4] <= 47) {
                            if (features[1] <= 34) {
                                return 1;
                            } else {
                                if (features[1] <= 60) {
                                    return 0;
                                } else {
                                    if (features[3] <= 7) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 154) {
                                return 0;
                            } else {
                                if (features[0] <= 157) {
                                    if (features[2] <= 5) {
                                        return 0;
                                    } else {
                                        if (features[1] <= 189) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[2] <= 95) {
            if (features[3] <= 13) {
                if (features[0] <= 71) {
                    return 0;
                } else {
                    if (features[2] <= 70) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 108) {
                    if (features[2] <= 78) {
                        return 1;
                    } else {
                        if (features[2] <= 79) {
                            if (features[0] <= 157) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 38) {
                                if (features[1] <= 30) {
                                    return 1;
                                } else {
                                    if (features[4] <= 27) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[4] <= 42) {
                                    if (features[4] <= 41) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[0] <= 200) {
                        if (features[3] <= 100) {
                            if (features[3] <= 100) {
                                if (features[3] <= 99) {
                                    return 1;
                                } else {
                                    if (features[1] <= 112) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 99) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[4] <= 113) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 107) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[1] <= 106) {
                                    if (features[4] <= 111) {
                                        if (features[0] <= 205) {
                                            return 0;
                                        } else {
                                            if (features[2] <= 74) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[4] <= 114) {
                                if (features[2] <= 77) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[0] <= 226) {
                                    if (features[2] <= 93) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 89) {
                                            if (features[0] <= 229) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[0] <= 232) {
                                                return 0;
                                            } else {
                                                if (features[2] <= 93) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 98) {
                return 0;
            } else {
                if (features[4] <= 127) {
                    return 1;
                } else {
                    if (features[0] <= 230) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}
int predict_tree_67(unsigned short features[]) {
    if (features[3] <= 33) {
        if (features[2] <= 62) {
            if (features[0] <= 106) {
                return 0;
            } else {
                if (features[2] <= 59) {
                    return 0;
                } else {
                    if (features[0] <= 156) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[1] <= 24) {
                if (features[1] <= 22) {
                    if (features[3] <= 6) {
                        return 0;
                    } else {
                        if (features[0] <= 71) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 12) {
                        if (features[1] <= 120) {
                            if (features[0] <= 91) {
                                return 1;
                            } else {
                                if (features[2] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (features[2] <= 31) {
            if (features[3] <= 132) {
                return 0;
            } else {
                if (features[1] <= 189) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[4] <= 108) {
                if (features[1] <= 43) {
                    if (features[0] <= 170) {
                        if (features[4] <= 41) {
                            if (features[4] <= 41) {
                                if (features[2] <= 89) {
                                    if (features[1] <= 42) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 42) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 163) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 79) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 108) {
                    if (features[3] <= 76) {
                        if (features[0] <= 200) {
                            return 1;
                        } else {
                            if (features[2] <= 80) {
                                if (features[2] <= 80) {
                                    if (features[4] <= 111) {
                                        if (features[4] <= 111) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[0] <= 241) {
                            return 1;
                        } else {
                            if (features[2] <= 91) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[1] <= 113) {
                            if (features[4] <= 124) {
                                if (features[3] <= 100) {
                                    if (features[0] <= 191) {
                                        if (features[3] <= 98) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[3] <= 100) {
                                            if (features[4] <= 114) {
                                                return 1;
                                            } else {
                                                if (features[0] <= 197) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 116) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_68(unsigned short features[]) {
    if (features[2] <= 62) {
        if (features[1] <= 246) {
            if (features[1] <= 104) {
                if (features[3] <= 90) {
                    if (features[2] <= 59) {
                        if (features[3] <= 67) {
                            if (features[3] <= 39) {
                                return 0;
                            } else {
                                if (features[1] <= 35) {
                                    if (features[4] <= 28) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 188) {
                                return 0;
                            } else {
                                if (features[4] <= 102) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 35) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 12) {
            if (features[3] <= 4) {
                if (features[0] <= 74) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[4] <= 4) {
                    return 0;
                } else {
                    if (features[1] <= 120) {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[2] <= 69) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[2] <= 93) {
                if (features[1] <= 116) {
                    if (features[4] <= 109) {
                        if (features[1] <= 43) {
                            if (features[4] <= 41) {
                                return 1;
                            } else {
                                if (features[3] <= 63) {
                                    return 1;
                                } else {
                                    if (features[0] <= 171) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 83) {
                            if (features[0] <= 202) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    if (features[2] <= 75) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 63) {
                                        if (features[2] <= 78) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 229) {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 100) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 99) {
                                    return 1;
                                } else {
                                    if (features[2] <= 91) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 97) {
                    if (features[0] <= 199) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 230) {
                        return 1;
                    } else {
                        if (features[1] <= 113) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_69(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[1] <= 247) {
            if (features[4] <= 75) {
                return 0;
            } else {
                if (features[4] <= 75) {
                    return 1;
                } else {
                    if (features[0] <= 188) {
                        if (features[4] <= 175) {
                            return 0;
                        } else {
                            if (features[4] <= 175) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[3] <= 74) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            if (features[4] <= 3) {
                if (features[0] <= 74) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 201) {
                if (features[4] <= 115) {
                    if (features[0] <= 36) {
                        if (features[0] <= 32) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 112) {
                            if (features[1] <= 43) {
                                if (features[3] <= 63) {
                                    if (features[2] <= 87) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 38) {
                                            if (features[0] <= 163) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 171) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 76) {
                                return 1;
                            } else {
                                if (features[2] <= 77) {
                                    if (features[2] <= 76) {
                                        if (features[3] <= 103) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 76) {
                    if (features[3] <= 63) {
                        if (features[1] <= 105) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[2] <= 86) {
                            return 1;
                        } else {
                            if (features[1] <= 114) {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 114) {
                            if (features[4] <= 122) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 129) {
                                if (features[4] <= 128) {
                                    return 1;
                                } else {
                                    if (features[4] <= 128) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 110) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_70(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[1] <= 247) {
            if (features[4] <= 175) {
                if (features[1] <= 117) {
                    return 0;
                } else {
                    if (features[4] <= 75) {
                        if (features[1] <= 118) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 175) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            return 0;
        } else {
            if (features[0] <= 234) {
                if (features[3] <= 76) {
                    if (features[3] <= 76) {
                        if (features[0] <= 200) {
                            if (features[3] <= 13) {
                                if (features[3] <= 12) {
                                    if (features[2] <= 66) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 10) {
                                            if (features[0] <= 91) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 29) {
                                    if (features[1] <= 29) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 159) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 41) {
                                        if (features[4] <= 41) {
                                            if (features[1] <= 42) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 62) {
                                                    return 1;
                                                } else {
                                                    if (features[1] <= 42) {
                                                        if (features[2] <= 79) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[2] <= 79) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[3] <= 62) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[4] <= 128) {
                        if (features[0] <= 227) {
                            if (features[4] <= 114) {
                                return 1;
                            } else {
                                if (features[1] <= 113) {
                                    if (features[4] <= 115) {
                                        if (features[3] <= 100) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 128) {
                                if (features[0] <= 229) {
                                    if (features[3] <= 102) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 105) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_71(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[3] <= 233) {
            if (features[0] <= 238) {
                if (features[2] <= 59) {
                    if (features[3] <= 10) {
                        return 0;
                    } else {
                        if (features[0] <= 33) {
                            if (features[0] <= 32) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 188) {
                                return 0;
                            } else {
                                if (features[1] <= 95) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                } else {
                    if (features[1] <= 38) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[4] <= 72) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 13) {
            if (features[4] <= 77) {
                if (features[4] <= 4) {
                    if (features[3] <= 7) {
                        if (features[2] <= 67) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[2] <= 69) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        if (features[3] <= 9) {
                            return 1;
                        } else {
                            if (features[4] <= 49) {
                                if (features[0] <= 94) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 230) {
                if (features[0] <= 204) {
                    if (features[0] <= 162) {
                        return 1;
                    } else {
                        if (features[0] <= 163) {
                            if (features[3] <= 51) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 108) {
                                if (features[4] <= 40) {
                                    if (features[1] <= 41) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 42) {
                                            if (features[3] <= 62) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 62) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 75) {
                                    return 1;
                                } else {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        if (features[1] <= 113) {
                                            if (features[2] <= 76) {
                                                if (features[1] <= 112) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 103) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 89) {
                    if (features[1] <= 110) {
                        return 1;
                    } else {
                        if (features[4] <= 128) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 112) {
                        if (features[1] <= 110) {
                            return 0;
                        } else {
                            if (features[0] <= 232) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_72(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[2] <= 59) {
            if (features[2] <= 35) {
                return 0;
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[4] <= 35) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 25) {
            if (features[4] <= 3) {
                if (features[4] <= 3) {
                    if (features[0] <= 74) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 24) {
                    return 0;
                } else {
                    if (features[4] <= 9) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[4] <= 109) {
                if (features[0] <= 36) {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 107) {
                        if (features[3] <= 11) {
                            if (features[2] <= 69) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 43) {
                            if (features[2] <= 79) {
                                if (features[3] <= 63) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[0] <= 204) {
                    if (features[3] <= 100) {
                        if (features[3] <= 100) {
                            if (features[4] <= 109) {
                                return 0;
                            } else {
                                if (features[3] <= 99) {
                                    return 1;
                                } else {
                                    if (features[3] <= 99) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 113) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 113) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 193) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[3] <= 97) {
                        if (features[2] <= 72) {
                            return 1;
                        } else {
                            if (features[2] <= 75) {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    if (features[1] <= 106) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[1] <= 106) {
                                    if (features[4] <= 116) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            return 1;
                        } else {
                            if (features[2] <= 86) {
                                return 1;
                            } else {
                                if (features[2] <= 91) {
                                    if (features[2] <= 88) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 110) {
                                            return 0;
                                        } else {
                                            if (features[2] <= 89) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_73(unsigned short features[]) {
    if (features[3] <= 30) {
        if (features[0] <= 107) {
            if (features[2] <= 47) {
                return 0;
            } else {
                if (features[4] <= 6) {
                    if (features[0] <= 74) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 105) {
                        if (features[2] <= 56) {
                            if (features[1] <= 133) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[0] <= 36) {
                                if (features[1] <= 121) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 28) {
                            return 0;
                        } else {
                            if (features[1] <= 65) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 63) {
                return 0;
            } else {
                if (features[1] <= 28) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[0] <= 111) {
            if (features[2] <= 33) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 41) {
                return 0;
            } else {
                if (features[2] <= 97) {
                    if (features[3] <= 73) {
                        if (features[1] <= 99) {
                            if (features[2] <= 87) {
                                if (features[2] <= 81) {
                                    return 1;
                                } else {
                                    if (features[2] <= 81) {
                                        if (features[1] <= 37) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[0] <= 164) {
                                    if (features[2] <= 89) {
                                        if (features[1] <= 30) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 107) {
                                if (features[4] <= 111) {
                                    if (features[4] <= 110) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 116) {
                            if (features[3] <= 106) {
                                if (features[4] <= 124) {
                                    if (features[2] <= 83) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 99) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[3] <= 76) {
                                            if (features[1] <= 80) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 81) {
                                    return 1;
                                } else {
                                    if (features[1] <= 114) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 91) {
                                            if (features[3] <= 110) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 110) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 111) {
                        return 0;
                    } else {
                        if (features[2] <= 100) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_74(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[0] <= 113) {
            if (features[2] <= 58) {
                if (features[2] <= 47) {
                    return 0;
                } else {
                    if (features[1] <= 133) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[2] <= 70) {
                        if (features[0] <= 36) {
                            if (features[3] <= 11) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 71) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (features[4] <= 35) {
                if (features[1] <= 25) {
                    return 0;
                } else {
                    if (features[0] <= 163) {
                        if (features[1] <= 35) {
                            if (features[2] <= 35) {
                                return 0;
                            } else {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    if (features[4] <= 26) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 41) {
                                return 0;
                            } else {
                                if (features[3] <= 46) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 54) {
                    if (features[2] <= 38) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 200) {
                        if (features[2] <= 22) {
                            return 0;
                        } else {
                            if (features[1] <= 112) {
                                if (features[4] <= 41) {
                                    if (features[4] <= 41) {
                                        if (features[4] <= 41) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 63) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 64) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 99) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 82) {
                            if (features[3] <= 63) {
                                if (features[3] <= 62) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 107) {
                                    return 0;
                                } else {
                                    if (features[4] <= 113) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[2] <= 41) {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[4] <= 169) {
                    return 0;
                } else {
                    if (features[3] <= 131) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[0] <= 230) {
                return 1;
            } else {
                if (features[3] <= 110) {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        if (features[3] <= 97) {
                            return 0;
                        } else {
                            if (features[2] <= 106) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_75(unsigned short features[]) {
    if (features[0] <= 110) {
        if (features[2] <= 56) {
            return 0;
        } else {
            if (features[3] <= 13) {
                if (features[1] <= 120) {
                    if (features[4] <= 11) {
                        if (features[2] <= 69) {
                            return 1;
                        } else {
                            if (features[0] <= 73) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[2] <= 65) {
                                return 1;
                            } else {
                                if (features[4] <= 62) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 26) {
            if (features[3] <= 15) {
                if (features[2] <= 64) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 59) {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[0] <= 228) {
                if (features[0] <= 163) {
                    if (features[3] <= 55) {
                        if (features[1] <= 79) {
                            if (features[4] <= 27) {
                                if (features[4] <= 23) {
                                    return 1;
                                } else {
                                    if (features[1] <= 35) {
                                        if (features[3] <= 30) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[3] <= 38) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 35) {
                                    return 0;
                                } else {
                                    if (features[2] <= 86) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[4] <= 68) {
                        if (features[2] <= 40) {
                            return 0;
                        } else {
                            if (features[0] <= 170) {
                                if (features[0] <= 169) {
                                    if (features[3] <= 63) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 44) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (features[3] <= 65) {
                                        if (features[2] <= 82) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[1] <= 107) {
                            if (features[2] <= 44) {
                                return 0;
                            } else {
                                if (features[4] <= 109) {
                                    if (features[4] <= 108) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 76) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[2] <= 74) {
                                        if (features[3] <= 83) {
                                            if (features[0] <= 203) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[1] <= 106) {
                                            if (features[1] <= 105) {
                                                return 0;
                                            } else {
                                                if (features[2] <= 81) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 27) {
                                return 0;
                            } else {
                                if (features[4] <= 115) {
                                    if (features[4] <= 113) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[3] <= 101) {
                                            if (features[2] <= 75) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[1] <= 105) {
                    if (features[3] <= 90) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[4] <= 128) {
                        return 0;
                    } else {
                        if (features[2] <= 100) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_76(unsigned short features[]) {
    if (features[0] <= 138) {
        if (features[4] <= 115) {
            if (features[1] <= 82) {
                if (features[2] <= 55) {
                    return 0;
                } else {
                    if (features[1] <= 26) {
                        if (features[0] <= 73) {
                            if (features[4] <= 3) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 10) {
                    if (features[0] <= 32) {
                        return 0;
                    } else {
                        if (features[0] <= 33) {
                            if (features[1] <= 133) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 13) {
                        if (features[0] <= 34) {
                            if (features[2] <= 34) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[4] <= 152) {
                if (features[2] <= 35) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[2] <= 50) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[2] <= 61) {
            if (features[3] <= 233) {
                if (features[4] <= 119) {
                    if (features[3] <= 39) {
                        return 0;
                    } else {
                        if (features[2] <= 35) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 5) {
                        return 0;
                    } else {
                        if (features[0] <= 197) {
                            if (features[1] <= 189) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[0] <= 227) {
                if (features[0] <= 201) {
                    if (features[3] <= 38) {
                        if (features[4] <= 27) {
                            return 1;
                        } else {
                            if (features[4] <= 27) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 40) {
                            if (features[3] <= 62) {
                                return 1;
                            } else {
                                if (features[0] <= 169) {
                                    if (features[4] <= 40) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 113) {
                                return 1;
                            } else {
                                if (features[1] <= 113) {
                                    if (features[4] <= 115) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[2] <= 75) {
                            if (features[4] <= 111) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 111) {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        if (features[0] <= 230) {
                            if (features[2] <= 98) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_77(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 62) {
            if (features[2] <= 59) {
                if (features[3] <= 10) {
                    return 0;
                } else {
                    if (features[3] <= 10) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 38) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[1] <= 24) {
                if (features[3] <= 4) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[0] <= 34) {
                        if (features[4] <= 77) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 10) {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (features[1] <= 189) {
            if (features[3] <= 58) {
                if (features[1] <= 36) {
                    if (features[0] <= 163) {
                        if (features[0] <= 159) {
                            if (features[4] <= 27) {
                                if (features[0] <= 124) {
                                    return 1;
                                } else {
                                    if (features[1] <= 33) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[3] <= 40) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[1] <= 80) {
                        if (features[2] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 171) {
                            if (features[4] <= 107) {
                                return 1;
                            } else {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 44) {
                    if (features[4] <= 173) {
                        return 0;
                    } else {
                        if (features[4] <= 175) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 109) {
                        if (features[1] <= 43) {
                            if (features[1] <= 43) {
                                if (features[3] <= 62) {
                                    return 1;
                                } else {
                                    if (features[0] <= 169) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[0] <= 171) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[1] <= 106) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 230) {
                                if (features[0] <= 228) {
                                    return 1;
                                } else {
                                    if (features[2] <= 97) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[1] <= 116) {
                                    if (features[1] <= 106) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 113) {
                                            if (features[2] <= 94) {
                                                if (features[2] <= 91) {
                                                    if (features[2] <= 89) {
                                                        if (features[3] <= 108) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 129) {
                if (features[3] <= 119) {
                    return 0;
                } else {
                    if (features[1] <= 207) {
                        if (features[2] <= 41) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 27) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_78(unsigned short features[]) {
    if (features[3] <= 32) {
        if (features[2] <= 62) {
            if (features[2] <= 59) {
                if (features[3] <= 10) {
                    return 0;
                } else {
                    if (features[0] <= 33) {
                        if (features[4] <= 74) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 34) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 13) {
                if (features[2] <= 70) {
                    if (features[4] <= 65) {
                        if (features[4] <= 4) {
                            if (features[2] <= 67) {
                                return 1;
                            } else {
                                if (features[0] <= 73) {
                                    if (features[4] <= 3) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[2] <= 31) {
            if (features[3] <= 132) {
                return 0;
            } else {
                if (features[1] <= 189) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 116) {
                if (features[4] <= 123) {
                    if (features[2] <= 75) {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[1] <= 106) {
                                if (features[1] <= 78) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 108) {
                            if (features[4] <= 28) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    if (features[1] <= 28) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 159) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 64) {
                                    if (features[2] <= 81) {
                                        if (features[2] <= 81) {
                                            if (features[2] <= 78) {
                                                return 1;
                                            } else {
                                                if (features[1] <= 41) {
                                                    return 1;
                                                } else {
                                                    if (features[4] <= 40) {
                                                        if (features[3] <= 61) {
                                                            return 1;
                                                        } else {
                                                            if (features[3] <= 62) {
                                                                return 0;
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[1] <= 43) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[4] <= 115) {
                                if (features[1] <= 108) {
                                    if (features[0] <= 198) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 76) {
                                            if (features[3] <= 64) {
                                                if (features[3] <= 62) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[1] <= 112) {
                                        if (features[0] <= 199) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[0] <= 192) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 100) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 227) {
                        return 1;
                    } else {
                        if (features[1] <= 111) {
                            return 0;
                        } else {
                            if (features[0] <= 232) {
                                if (features[2] <= 89) {
                                    if (features[2] <= 88) {
                                        if (features[1] <= 112) {
                                            if (features[3] <= 102) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_79(unsigned short features[]) {
    if (features[3] <= 28) {
        if (features[4] <= 91) {
            if (features[3] <= 13) {
                if (features[2] <= 59) {
                    if (features[3] <= 10) {
                        return 0;
                    } else {
                        if (features[1] <= 117) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 45) {
                        if (features[3] <= 4) {
                            if (features[2] <= 69) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[0] <= 73) {
                                if (features[2] <= 69) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[4] <= 77) {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                if (features[0] <= 69) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 32) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 0;
        }
    } else {
        if (features[0] <= 109) {
            if (features[2] <= 32) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[0] <= 163) {
                if (features[2] <= 35) {
                    return 0;
                } else {
                    if (features[0] <= 162) {
                        return 1;
                    } else {
                        if (features[4] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[0] <= 203) {
                    if (features[3] <= 58) {
                        if (features[2] <= 77) {
                            if (features[1] <= 38) {
                                return 1;
                            } else {
                                if (features[2] <= 41) {
                                    return 0;
                                } else {
                                    if (features[0] <= 185) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 191) {
                            if (features[4] <= 68) {
                                if (features[2] <= 79) {
                                    return 1;
                                } else {
                                    if (features[4] <= 41) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 41) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 64) {
                                                if (features[2] <= 82) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 18) {
                                    return 0;
                                } else {
                                    if (features[2] <= 77) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 154) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[1] <= 113) {
                                return 1;
                            } else {
                                if (features[2] <= 33) {
                                    return 0;
                                } else {
                                    if (features[1] <= 113) {
                                        if (features[3] <= 102) {
                                            if (features[4] <= 116) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[2] <= 38) {
                        return 0;
                    } else {
                        if (features[3] <= 76) {
                            return 0;
                        } else {
                            if (features[2] <= 86) {
                                return 1;
                            } else {
                                if (features[0] <= 227) {
                                    return 1;
                                } else {
                                    if (features[1] <= 111) {
                                        return 0;
                                    } else {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 116) {
                                                if (features[3] <= 110) {
                                                    if (features[3] <= 101) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    if (features[4] <= 129) {
                                                        return 1;
                                                    } else {
                                                        if (features[3] <= 110) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_80(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 65) {
            if (features[1] <= 117) {
                return 0;
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    if (features[4] <= 77) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[4] <= 14) {
                if (features[1] <= 25) {
                    if (features[4] <= 9) {
                        if (features[2] <= 69) {
                            return 1;
                        } else {
                            if (features[2] <= 70) {
                                if (features[4] <= 3) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 13) {
                    if (features[4] <= 77) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[0] <= 111) {
            if (features[4] <= 148) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 163) {
                if (features[2] <= 44) {
                    return 0;
                } else {
                    if (features[2] <= 86) {
                        return 1;
                    } else {
                        if (features[1] <= 30) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[4] <= 69) {
                    if (features[2] <= 36) {
                        return 0;
                    } else {
                        if (features[0] <= 170) {
                            if (features[2] <= 79) {
                                return 1;
                            } else {
                                if (features[1] <= 43) {
                                    return 1;
                                } else {
                                    if (features[4] <= 42) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 27) {
                        return 0;
                    } else {
                        if (features[1] <= 108) {
                            if (features[1] <= 104) {
                                if (features[1] <= 104) {
                                    return 1;
                                } else {
                                    if (features[4] <= 107) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 109) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[0] <= 200) {
                                    return 1;
                                } else {
                                    if (features[4] <= 112) {
                                        if (features[4] <= 110) {
                                            return 0;
                                        } else {
                                            if (features[2] <= 75) {
                                                if (features[2] <= 74) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 61) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                if (features[1] <= 106) {
                                                    if (features[1] <= 105) {
                                                        return 0;
                                                    } else {
                                                        if (features[3] <= 63) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 121) {
                                                if (features[4] <= 117) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 230) {
                                if (features[4] <= 115) {
                                    if (features[3] <= 84) {
                                        if (features[2] <= 84) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[2] <= 77) {
                                            if (features[4] <= 115) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[0] <= 191) {
                                                if (features[0] <= 190) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (features[3] <= 103) {
                                        if (features[4] <= 124) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 102) {
                                                return 1;
                                            } else {
                                                if (features[0] <= 223) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[1] <= 114) {
                                    return 0;
                                } else {
                                    if (features[0] <= 232) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_81(unsigned short features[]) {
    if (features[0] <= 114) {
        if (features[2] <= 48) {
            return 0;
        } else {
            if (features[4] <= 4) {
                return 0;
            } else {
                if (features[3] <= 13) {
                    if (features[1] <= 120) {
                        if (features[0] <= 91) {
                            return 1;
                        } else {
                            if (features[1] <= 66) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[4] <= 35) {
            if (features[2] <= 65) {
                if (features[3] <= 39) {
                    return 0;
                } else {
                    if (features[4] <= 28) {
                        if (features[4] <= 28) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[2] <= 89) {
                    return 1;
                } else {
                    if (features[2] <= 89) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[0] <= 163) {
                if (features[3] <= 54) {
                    if (features[2] <= 33) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[4] <= 190) {
                        if (features[1] <= 45) {
                            return 0;
                        } else {
                            if (features[4] <= 165) {
                                if (features[2] <= 49) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[2] <= 40) {
                                    if (features[2] <= 5) {
                                        return 0;
                                    } else {
                                        if (features[4] <= 175) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 191) {
                            if (features[1] <= 211) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[4] <= 67) {
                    if (features[3] <= 64) {
                        if (features[3] <= 64) {
                            if (features[2] <= 35) {
                                return 0;
                            } else {
                                if (features[3] <= 62) {
                                    return 1;
                                } else {
                                    if (features[3] <= 62) {
                                        if (features[2] <= 80) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 27) {
                        return 0;
                    } else {
                        if (features[3] <= 73) {
                            if (features[4] <= 114) {
                                if (features[0] <= 200) {
                                    return 1;
                                } else {
                                    if (features[3] <= 63) {
                                        if (features[4] <= 110) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 86) {
                                if (features[3] <= 77) {
                                    if (features[1] <= 102) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 76) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 100) {
                                            if (features[3] <= 99) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 113) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 97) {
                                    return 0;
                                } else {
                                    if (features[1] <= 114) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 124) {
                                                if (features[2] <= 86) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        if (features[1] <= 115) {
                                            if (features[0] <= 228) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 128) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_82(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[2] <= 62) {
            if (features[3] <= 10) {
                if (features[2] <= 59) {
                    return 0;
                } else {
                    if (features[1] <= 38) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[1] <= 117) {
                    return 0;
                } else {
                    if (features[4] <= 113) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[2] <= 70) {
                if (features[3] <= 7) {
                    if (features[0] <= 74) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[3] <= 13) {
                        if (features[1] <= 121) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 52) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[1] <= 186) {
            if (features[2] <= 34) {
                return 0;
            } else {
                if (features[1] <= 104) {
                    if (features[3] <= 64) {
                        if (features[0] <= 169) {
                            if (features[2] <= 89) {
                                return 1;
                            } else {
                                if (features[2] <= 90) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 43) {
                                return 1;
                            } else {
                                if (features[3] <= 64) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[4] <= 115) {
                        if (features[4] <= 111) {
                            if (features[0] <= 200) {
                                return 1;
                            } else {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 81) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[3] <= 76) {
                                if (features[1] <= 109) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[3] <= 99) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 97) {
                            if (features[2] <= 88) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[2] <= 87) {
                                return 1;
                            } else {
                                if (features[0] <= 228) {
                                    return 1;
                                } else {
                                    if (features[4] <= 130) {
                                        if (features[4] <= 125) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 124) {
                if (features[2] <= 41) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[2] <= 5) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_83(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 246) {
            if (features[3] <= 39) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[0] <= 32) {
                        return 0;
                    } else {
                        if (features[3] <= 7) {
                            if (features[2] <= 58) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 117) {
                                return 0;
                            } else {
                                if (features[2] <= 24) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 40) {
                    return 1;
                } else {
                    if (features[4] <= 85) {
                        if (features[2] <= 28) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            if (features[2] <= 67) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 104) {
                if (features[4] <= 40) {
                    if (features[1] <= 30) {
                        if (features[3] <= 37) {
                            return 1;
                        } else {
                            if (features[0] <= 168) {
                                if (features[0] <= 159) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 40) {
                            return 1;
                        } else {
                            if (features[3] <= 62) {
                                return 1;
                            } else {
                                if (features[2] <= 79) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 108) {
                    if (features[2] <= 73) {
                        return 1;
                    } else {
                        if (features[3] <= 94) {
                            if (features[3] <= 82) {
                                if (features[2] <= 74) {
                                    if (features[4] <= 111) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[1] <= 106) {
                                        if (features[3] <= 61) {
                                            return 0;
                                        } else {
                                            if (features[3] <= 63) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[0] <= 241) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[4] <= 82) {
                        if (features[1] <= 120) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 116) {
                            if (features[2] <= 83) {
                                if (features[3] <= 100) {
                                    if (features[4] <= 113) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 75) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 227) {
                                    if (features[4] <= 116) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 112) {
                                        if (features[4] <= 125) {
                                            if (features[1] <= 111) {
                                                return 0;
                                            } else {
                                                if (features[0] <= 230) {
                                                    if (features[2] <= 86) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_84(unsigned short features[]) {
    if (features[3] <= 15) {
        if (features[0] <= 69) {
            if (features[2] <= 71) {
                if (features[3] <= 10) {
                    return 0;
                } else {
                    if (features[2] <= 24) {
                        return 0;
                    } else {
                        if (features[1] <= 120) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[3] <= 13) {
                if (features[2] <= 63) {
                    if (features[2] <= 59) {
                        return 0;
                    } else {
                        if (features[1] <= 38) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[3] <= 10) {
                        if (features[2] <= 67) {
                            return 1;
                        } else {
                            if (features[3] <= 7) {
                                return 0;
                            } else {
                                if (features[0] <= 70) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 34) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[2] <= 35) {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[2] <= 5) {
                    if (features[0] <= 187) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 116) {
                if (features[0] <= 204) {
                    if (features[4] <= 41) {
                        if (features[3] <= 62) {
                            if (features[1] <= 30) {
                                if (features[0] <= 163) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 41) {
                                if (features[3] <= 62) {
                                    if (features[0] <= 171) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[3] <= 100) {
                            if (features[4] <= 108) {
                                return 1;
                            } else {
                                if (features[0] <= 201) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[3] <= 100) {
                                if (features[2] <= 76) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[2] <= 74) {
                        if (features[4] <= 113) {
                            if (features[1] <= 106) {
                                return 1;
                            } else {
                                if (features[3] <= 85) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 118) {
                            if (features[3] <= 76) {
                                if (features[2] <= 75) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                if (features[1] <= 106) {
                                    return 1;
                                } else {
                                    if (features[4] <= 126) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 91) {
                                            if (features[3] <= 110) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_85(unsigned short features[]) {
    if (features[4] <= 115) {
        if (features[2] <= 61) {
            if (features[4] <= 28) {
                return 0;
            } else {
                if (features[3] <= 10) {
                    if (features[1] <= 65) {
                        if (features[0] <= 105) {
                            return 0;
                        } else {
                            if (features[1] <= 55) {
                                return 0;
                            } else {
                                if (features[2] <= 29) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[2] <= 33) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[1] <= 24) {
                return 0;
            } else {
                if (features[2] <= 94) {
                    if (features[0] <= 204) {
                        if (features[3] <= 99) {
                            if (features[1] <= 30) {
                                if (features[1] <= 30) {
                                    if (features[0] <= 163) {
                                        if (features[3] <= 26) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[0] <= 36) {
                                    if (features[0] <= 34) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[4] <= 109) {
                                        if (features[0] <= 107) {
                                            if (features[3] <= 11) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[1] <= 43) {
                                                if (features[4] <= 41) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 171) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[4] <= 109) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[0] <= 191) {
                                return 0;
                            } else {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    if (features[2] <= 77) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 74) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[3] <= 83) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[3] <= 75) {
                                if (features[2] <= 80) {
                                    return 0;
                                } else {
                                    if (features[3] <= 67) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 196) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        if (features[0] <= 126) {
            if (features[4] <= 150) {
                return 1;
            } else {
                if (features[2] <= 36) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[1] <= 110) {
                if (features[2] <= 31) {
                    return 0;
                } else {
                    if (features[4] <= 121) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 221) {
                    if (features[0] <= 230) {
                        if (features[2] <= 33) {
                            return 0;
                        } else {
                            if (features[0] <= 227) {
                                return 1;
                            } else {
                                if (features[4] <= 124) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[4] <= 128) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 27) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_86(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[3] <= 13) {
            if (features[2] <= 66) {
                if (features[4] <= 75) {
                    return 0;
                } else {
                    if (features[4] <= 75) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 7) {
                    if (features[1] <= 22) {
                        if (features[3] <= 4) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 9) {
                        if (features[1] <= 23) {
                            if (features[3] <= 7) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 94) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 66) {
                return 1;
            } else {
                if (features[0] <= 127) {
                    if (features[3] <= 23) {
                        if (features[2] <= 33) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 21) {
                            return 1;
                        } else {
                            if (features[0] <= 123) {
                                return 0;
                            } else {
                                if (features[4] <= 44) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[1] <= 189) {
            if (features[2] <= 28) {
                if (features[2] <= 5) {
                    return 0;
                } else {
                    if (features[2] <= 5) {
                        if (features[3] <= 111) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 109) {
                    if (features[4] <= 27) {
                        if (features[0] <= 159) {
                            return 1;
                        } else {
                            if (features[4] <= 27) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[1] <= 43) {
                            if (features[1] <= 43) {
                                return 1;
                            } else {
                                if (features[0] <= 183) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 108) {
                        if (features[2] <= 75) {
                            if (features[1] <= 107) {
                                if (features[3] <= 79) {
                                    if (features[2] <= 74) {
                                        if (features[3] <= 63) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 109) {
                                return 1;
                            } else {
                                if (features[1] <= 106) {
                                    if (features[0] <= 223) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 113) {
                                        return 0;
                                    } else {
                                        if (features[2] <= 79) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 87) {
                            if (features[3] <= 99) {
                                if (features[1] <= 114) {
                                    if (features[3] <= 99) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[2] <= 87) {
                                if (features[4] <= 133) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 237) {
                                    if (features[0] <= 230) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 110) {
                                            if (features[0] <= 232) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 30) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_87(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[1] <= 80) {
            if (features[3] <= 12) {
                if (features[2] <= 63) {
                    if (features[4] <= 47) {
                        return 0;
                    } else {
                        if (features[1] <= 65) {
                            if (features[2] <= 29) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 7) {
                        if (features[4] <= 3) {
                            if (features[0] <= 74) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[4] <= 3) {
                            return 0;
                        } else {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                if (features[0] <= 108) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[2] <= 33) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[4] <= 92) {
                if (features[2] <= 39) {
                    return 0;
                } else {
                    if (features[3] <= 13) {
                        if (features[4] <= 76) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 0;
            }
        }
    } else {
        if (features[2] <= 31) {
            if (features[2] <= 5) {
                return 0;
            } else {
                if (features[3] <= 122) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 93) {
                if (features[3] <= 76) {
                    if (features[4] <= 107) {
                        if (features[2] <= 78) {
                            return 1;
                        } else {
                            if (features[1] <= 43) {
                                if (features[1] <= 43) {
                                    if (features[3] <= 38) {
                                        if (features[1] <= 30) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[1] <= 42) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 79) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (features[4] <= 45) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 114) {
                            if (features[3] <= 60) {
                                if (features[0] <= 201) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 75) {
                                    if (features[3] <= 61) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[0] <= 227) {
                        if (features[3] <= 100) {
                            if (features[3] <= 100) {
                                if (features[1] <= 113) {
                                    return 1;
                                } else {
                                    if (features[3] <= 97) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 127) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[1] <= 113) {
                            if (features[2] <= 86) {
                                return 1;
                            } else {
                                if (features[3] <= 97) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[3] <= 97) {
                    if (features[1] <= 74) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_88(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[3] <= 40) {
            if (features[2] <= 59) {
                if (features[2] <= 48) {
                    return 0;
                } else {
                    if (features[3] <= 9) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 31) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[0] <= 227) {
            if (features[3] <= 7) {
                if (features[4] <= 3) {
                    if (features[2] <= 69) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[1] <= 124) {
                    if (features[0] <= 201) {
                        if (features[1] <= 120) {
                            if (features[3] <= 99) {
                                if (features[2] <= 78) {
                                    return 1;
                                } else {
                                    if (features[0] <= 170) {
                                        if (features[2] <= 79) {
                                            if (features[4] <= 42) {
                                                if (features[3] <= 50) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[3] <= 38) {
                                                if (features[0] <= 164) {
                                                    if (features[1] <= 31) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (features[1] <= 43) {
                                                    return 1;
                                                } else {
                                                    if (features[1] <= 43) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 99) {
                                    return 0;
                                } else {
                                    if (features[3] <= 100) {
                                        if (features[1] <= 112) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 75) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 69) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[3] <= 80) {
                            if (features[1] <= 114) {
                                if (features[3] <= 62) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 104) {
                if (features[3] <= 110) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[0] <= 237) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_89(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[4] <= 247) {
            if (features[2] <= 35) {
                if (features[4] <= 175) {
                    return 0;
                } else {
                    if (features[1] <= 189) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 115) {
                    if (features[3] <= 9) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 24) {
            if (features[1] <= 22) {
                if (features[2] <= 69) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[0] <= 73) {
                    if (features[2] <= 69) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 12) {
                if (features[1] <= 120) {
                    if (features[0] <= 91) {
                        return 1;
                    } else {
                        if (features[0] <= 107) {
                            return 0;
                        } else {
                            if (features[2] <= 155) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 86) {
                    if (features[4] <= 115) {
                        if (features[4] <= 108) {
                            if (features[3] <= 13) {
                                if (features[4] <= 67) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[1] <= 43) {
                                    if (features[1] <= 43) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 64) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 107) {
                                if (features[3] <= 85) {
                                    if (features[0] <= 200) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 111) {
                                            if (features[3] <= 62) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 63) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 115) {
                                    if (features[2] <= 80) {
                                        if (features[4] <= 113) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 192) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 99) {
                                                    if (features[2] <= 74) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 230) {
                        if (features[1] <= 114) {
                            if (features[0] <= 203) {
                                if (features[0] <= 163) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[0] <= 216) {
                                    return 0;
                                } else {
                                    if (features[0] <= 227) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 101) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 110) {
                            if (features[2] <= 113) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_90(unsigned short features[]) {
    if (features[2] <= 62) {
        if (features[1] <= 247) {
            if (features[3] <= 10) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        if (features[2] <= 58) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[3] <= 10) {
                    return 1;
                } else {
                    if (features[3] <= 68) {
                        return 0;
                    } else {
                        if (features[2] <= 31) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[1] <= 25) {
            if (features[4] <= 9) {
                if (features[2] <= 69) {
                    if (features[4] <= 4) {
                        if (features[4] <= 3) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 204) {
                if (features[2] <= 76) {
                    if (features[2] <= 65) {
                        if (features[1] <= 125) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 201) {
                            return 1;
                        } else {
                            if (features[1] <= 103) {
                                return 1;
                            } else {
                                if (features[3] <= 75) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[0] <= 190) {
                        if (features[1] <= 30) {
                            if (features[0] <= 163) {
                                if (features[1] <= 30) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[1] <= 43) {
                                if (features[4] <= 41) {
                                    return 1;
                                } else {
                                    if (features[3] <= 64) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[2] <= 76) {
                            if (features[1] <= 110) {
                                return 1;
                            } else {
                                if (features[3] <= 103) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[0] <= 191) {
                                if (features[3] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 76) {
                    if (features[3] <= 63) {
                        if (features[1] <= 105) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 98) {
                        if (features[2] <= 91) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 116) {
                            if (features[4] <= 124) {
                                if (features[4] <= 124) {
                                    return 1;
                                } else {
                                    if (features[2] <= 104) {
                                        if (features[3] <= 102) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[2] <= 104) {
                                    if (features[4] <= 128) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 110) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_91(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[3] <= 40) {
            if (features[3] <= 7) {
                return 0;
            } else {
                if (features[3] <= 7) {
                    if (features[2] <= 58) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[2] <= 27) {
                if (features[3] <= 131) {
                    return 0;
                } else {
                    if (features[2] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[1] <= 24) {
            if (features[4] <= 3) {
                if (features[0] <= 71) {
                    return 0;
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 116) {
                if (features[0] <= 227) {
                    if (features[4] <= 109) {
                        if (features[2] <= 99) {
                            if (features[4] <= 41) {
                                if (features[4] <= 41) {
                                    if (features[2] <= 87) {
                                        if (features[3] <= 62) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 78) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 79) {
                                                    return 0;
                                                } else {
                                                    if (features[1] <= 43) {
                                                        return 1;
                                                    } else {
                                                        if (features[0] <= 159) {
                                                            return 1;
                                                        } else {
                                                            return 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[3] <= 38) {
                                            if (features[0] <= 164) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[2] <= 74) {
                                if (features[0] <= 203) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[3] <= 63) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[1] <= 112) {
                                return 1;
                            } else {
                                if (features[0] <= 192) {
                                    return 0;
                                } else {
                                    if (features[3] <= 99) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[4] <= 122) {
                        return 1;
                    } else {
                        if (features[2] <= 108) {
                            if (features[4] <= 124) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[1] <= 110) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[0] <= 36) {
                    if (features[3] <= 12) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_92(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 131) {
            if (features[2] <= 59) {
                if (features[0] <= 238) {
                    if (features[2] <= 48) {
                        return 0;
                    } else {
                        if (features[3] <= 9) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[4] <= 72) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 165) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[3] <= 132) {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        if (features[0] <= 230) {
            if (features[3] <= 7) {
                if (features[2] <= 67) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[0] <= 204) {
                    if (features[2] <= 66) {
                        if (features[4] <= 83) {
                            if (features[3] <= 14) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 74) {
                            return 1;
                        } else {
                            if (features[2] <= 74) {
                                if (features[1] <= 109) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 100) {
                                    if (features[2] <= 79) {
                                        if (features[3] <= 99) {
                                            if (features[4] <= 114) {
                                                if (features[1] <= 43) {
                                                    if (features[2] <= 78) {
                                                        return 1;
                                                    } else {
                                                        if (features[0] <= 170) {
                                                            if (features[2] <= 79) {
                                                                if (features[3] <= 61) {
                                                                    return 1;
                                                                } else {
                                                                    return 0;
                                                                }
                                                            } else {
                                                                return 0;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (features[4] <= 125) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[1] <= 112) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 163) {
                                            if (features[2] <= 87) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 36) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 81) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 89) {
                if (features[2] <= 87) {
                    if (features[3] <= 109) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (features[2] <= 104) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_93(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[3] <= 12) {
            if (features[0] <= 69) {
                if (features[0] <= 32) {
                    return 0;
                } else {
                    if (features[2] <= 43) {
                        return 0;
                    } else {
                        if (features[2] <= 48) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[0] <= 73) {
                    if (features[2] <= 68) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 64) {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[4] <= 39) {
                                return 0;
                            } else {
                                if (features[2] <= 29) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (features[2] <= 70) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 66) {
                if (features[1] <= 124) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[0] <= 127) {
                    if (features[4] <= 108) {
                        if (features[1] <= 52) {
                            if (features[4] <= 11) {
                                return 1;
                            } else {
                                if (features[1] <= 32) {
                                    if (features[2] <= 34) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 19) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 34) {
                                            if (features[2] <= 35) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        }
    } else {
        if (features[2] <= 35) {
            if (features[0] <= 154) {
                return 0;
            } else {
                if (features[0] <= 157) {
                    if (features[3] <= 131) {
                        return 0;
                    } else {
                        if (features[1] <= 208) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (features[0] <= 204) {
                if (features[3] <= 38) {
                    if (features[2] <= 86) {
                        return 1;
                    } else {
                        if (features[2] <= 87) {
                            return 0;
                        } else {
                            if (features[3] <= 37) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[0] <= 190) {
                        if (features[1] <= 43) {
                            if (features[1] <= 43) {
                                return 1;
                            } else {
                                if (features[2] <= 80) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 78) {
                            return 1;
                        } else {
                            if (features[0] <= 191) {
                                if (features[2] <= 78) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[1] <= 108) {
                    if (features[1] <= 104) {
                        return 1;
                    } else {
                        if (features[1] <= 107) {
                            if (features[2] <= 74) {
                                return 1;
                            } else {
                                if (features[4] <= 117) {
                                    if (features[1] <= 106) {
                                        if (features[3] <= 61) {
                                            return 0;
                                        } else {
                                            if (features[1] <= 105) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[4] <= 122) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            if (features[2] <= 81) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 80) {
                        return 0;
                    } else {
                        if (features[2] <= 86) {
                            return 1;
                        } else {
                            if (features[2] <= 87) {
                                if (features[3] <= 105) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 109) {
                                    return 1;
                                } else {
                                    if (features[3] <= 109) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_94(unsigned short features[]) {
    if (features[3] <= 27) {
        if (features[4] <= 90) {
            if (features[1] <= 127) {
                if (features[3] <= 13) {
                    if (features[2] <= 67) {
                        if (features[2] <= 48) {
                            return 0;
                        } else {
                            if (features[0] <= 34) {
                                if (features[1] <= 119) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[3] <= 7) {
                            return 0;
                        } else {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[4] <= 48) {
                        if (features[1] <= 28) {
                            return 1;
                        } else {
                            if (features[2] <= 34) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 11) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 0;
        }
    } else {
        if (features[1] <= 189) {
            if (features[2] <= 31) {
                if (features[1] <= 188) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[1] <= 104) {
                    return 1;
                } else {
                    if (features[0] <= 201) {
                        if (features[3] <= 99) {
                            if (features[2] <= 77) {
                                return 1;
                            } else {
                                if (features[1] <= 112) {
                                    return 1;
                                } else {
                                    if (features[0] <= 196) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 76) {
                            if (features[2] <= 73) {
                                return 1;
                            } else {
                                if (features[2] <= 75) {
                                    if (features[4] <= 111) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 65) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[3] <= 97) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[0] <= 227) {
                                    return 1;
                                } else {
                                    if (features[4] <= 127) {
                                        if (features[3] <= 101) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 35) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_95(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[3] <= 233) {
            if (features[2] <= 35) {
                if (features[0] <= 155) {
                    return 0;
                } else {
                    if (features[4] <= 147) {
                        return 0;
                    } else {
                        if (features[2] <= 3) {
                            return 0;
                        } else {
                            if (features[3] <= 131) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 9) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[4] <= 4) {
            if (features[2] <= 67) {
                return 1;
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[3] <= 7) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        } else {
            if (features[0] <= 234) {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[0] <= 204) {
                        if (features[3] <= 13) {
                            if (features[2] <= 67) {
                                return 0;
                            } else {
                                if (features[4] <= 48) {
                                    if (features[4] <= 29) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 30) {
                                if (features[4] <= 27) {
                                    return 1;
                                } else {
                                    if (features[4] <= 27) {
                                        if (features[0] <= 165) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 41) {
                                    if (features[4] <= 41) {
                                        if (features[4] <= 40) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 40) {
                                                if (features[2] <= 78) {
                                                    if (features[3] <= 61) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[0] <= 171) {
                                            if (features[3] <= 61) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[2] <= 75) {
                                        return 1;
                                    } else {
                                        if (features[0] <= 201) {
                                            if (features[0] <= 190) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 113) {
                                                    return 1;
                                                } else {
                                                    if (features[1] <= 113) {
                                                        if (features[3] <= 99) {
                                                            return 0;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[4] <= 114) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[1] <= 108) {
                            if (features[3] <= 76) {
                                if (features[4] <= 111) {
                                    if (features[4] <= 110) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 80) {
                                return 0;
                            } else {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    if (features[2] <= 87) {
                                        if (features[3] <= 102) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        if (features[0] <= 230) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 112) {
                                                if (features[2] <= 89) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[2] <= 91) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}
int predict_tree_96(unsigned short features[]) {
    if (features[2] <= 61) {
        if (features[1] <= 247) {
            if (features[4] <= 175) {
                if (features[3] <= 40) {
                    if (features[4] <= 47) {
                        return 0;
                    } else {
                        if (features[1] <= 65) {
                            if (features[2] <= 29) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 75) {
                                if (features[2] <= 27) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[4] <= 28) {
                        if (features[3] <= 40) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 189) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[4] <= 14) {
            if (features[2] <= 69) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 86) {
                if (features[0] <= 204) {
                    if (features[0] <= 34) {
                        if (features[1] <= 120) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[2] <= 76) {
                            if (features[0] <= 107) {
                                if (features[0] <= 105) {
                                    return 1;
                                } else {
                                    if (features[3] <= 14) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 100) {
                                if (features[1] <= 111) {
                                    if (features[0] <= 169) {
                                        if (features[2] <= 79) {
                                            if (features[4] <= 41) {
                                                if (features[2] <= 78) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 156) {
                                                        return 1;
                                                    } else {
                                                        return 0;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[1] <= 122) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[1] <= 107) {
                        if (features[4] <= 109) {
                            return 1;
                        } else {
                            if (features[3] <= 87) {
                                if (features[1] <= 106) {
                                    if (features[1] <= 105) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[4] <= 114) {
                            if (features[1] <= 108) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[0] <= 227) {
                    if (features[0] <= 163) {
                        if (features[4] <= 26) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 204) {
                            return 1;
                        } else {
                            if (features[4] <= 117) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 92) {
                        return 1;
                    } else {
                        if (features[0] <= 234) {
                            if (features[3] <= 100) {
                                return 1;
                            } else {
                                if (features[1] <= 116) {
                                    return 0;
                                } else {
                                    if (features[3] <= 110) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_97(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[2] <= 48) {
            if (features[3] <= 68) {
                return 0;
            } else {
                if (features[4] <= 85) {
                    if (features[4] <= 83) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[0] <= 154) {
                        return 0;
                    } else {
                        if (features[1] <= 189) {
                            if (features[4] <= 147) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            if (features[3] <= 9) {
                if (features[4] <= 36) {
                    return 0;
                } else {
                    if (features[0] <= 82) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (features[0] <= 230) {
            if (features[3] <= 7) {
                if (features[4] <= 3) {
                    return 1;
                } else {
                    if (features[3] <= 7) {
                        return 0;
                    } else {
                        if (features[3] <= 7) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[3] <= 74) {
                    if (features[4] <= 108) {
                        if (features[3] <= 12) {
                            if (features[0] <= 54) {
                                return 0;
                            } else {
                                if (features[1] <= 66) {
                                    if (features[3] <= 9) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (features[1] <= 43) {
                                if (features[1] <= 43) {
                                    if (features[1] <= 30) {
                                        if (features[4] <= 27) {
                                            return 1;
                                        } else {
                                            if (features[0] <= 164) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 42) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 202) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 100) {
                        if (features[3] <= 100) {
                            if (features[1] <= 112) {
                                if (features[4] <= 113) {
                                    return 1;
                                } else {
                                    if (features[4] <= 114) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 120) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 89) {
                return 1;
            } else {
                if (features[2] <= 105) {
                    if (features[3] <= 112) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_98(unsigned short features[]) {
    if (features[0] <= 113) {
        if (features[3] <= 10) {
            if (features[1] <= 21) {
                if (features[2] <= 33) {
                    return 0;
                } else {
                    if (features[4] <= 3) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 7) {
                    return 0;
                } else {
                    if (features[2] <= 50) {
                        return 0;
                    } else {
                        if (features[4] <= 3) {
                            return 0;
                        } else {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[2] <= 32) {
                return 0;
            } else {
                if (features[0] <= 37) {
                    if (features[2] <= 67) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (features[4] <= 26) {
            if (features[1] <= 32) {
                if (features[3] <= 29) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (features[3] <= 27) {
                    if (features[2] <= 37) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    if (features[2] <= 35) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 24) {
                return 0;
            } else {
                if (features[0] <= 203) {
                    if (features[1] <= 29) {
                        if (features[1] <= 29) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 104) {
                            return 1;
                        } else {
                            if (features[3] <= 58) {
                                return 0;
                            } else {
                                if (features[4] <= 115) {
                                    if (features[4] <= 115) {
                                        if (features[4] <= 113) {
                                            return 1;
                                        } else {
                                            if (features[4] <= 113) {
                                                return 0;
                                            } else {
                                                if (features[4] <= 114) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 100) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[1] <= 109) {
                        if (features[1] <= 104) {
                            return 1;
                        } else {
                            if (features[3] <= 99) {
                                if (features[1] <= 106) {
                                    if (features[0] <= 223) {
                                        if (features[1] <= 105) {
                                            if (features[4] <= 111) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 63) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (features[0] <= 227) {
                            return 1;
                        } else {
                            if (features[2] <= 105) {
                                if (features[2] <= 86) {
                                    return 1;
                                } else {
                                    if (features[4] <= 127) {
                                        return 0;
                                    } else {
                                        if (features[0] <= 232) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_99(unsigned short features[]) {
    if (features[2] <= 60) {
        if (features[1] <= 247) {
            if (features[3] <= 39) {
                return 0;
            } else {
                if (features[2] <= 31) {
                    if (features[2] <= 5) {
                        return 0;
                    } else {
                        if (features[4] <= 169) {
                            return 0;
                        } else {
                            if (features[3] <= 131) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (features[3] <= 7) {
            if (features[2] <= 67) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[0] <= 230) {
                if (features[0] <= 200) {
                    if (features[2] <= 66) {
                        if (features[0] <= 37) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 10) {
                            if (features[3] <= 9) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[0] <= 193) {
                                if (features[2] <= 78) {
                                    return 1;
                                } else {
                                    if (features[3] <= 62) {
                                        if (features[2] <= 78) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[4] <= 114) {
                                    return 1;
                                } else {
                                    if (features[1] <= 113) {
                                        if (features[1] <= 113) {
                                            if (features[3] <= 100) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[3] <= 76) {
                        if (features[4] <= 118) {
                            if (features[3] <= 63) {
                                if (features[4] <= 110) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[3] <= 112) {
                    if (features[2] <= 113) {
                        if (features[1] <= 106) {
                            return 1;
                        } else {
                            if (features[3] <= 108) {
                                return 0;
                            } else {
                                if (features[3] <= 110) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}

char predict_random_forest(unsigned short features[]) {
    int votes[2] = {0};  // Assuming binary classification (class 0 and class 1)
    int prediction_0 = predict_tree_0(features);
    votes[prediction_0]++;
    int prediction_1 = predict_tree_1(features);
    votes[prediction_1]++;
    int prediction_2 = predict_tree_2(features);
    votes[prediction_2]++;
    int prediction_3 = predict_tree_3(features);
    votes[prediction_3]++;
    int prediction_4 = predict_tree_4(features);
    votes[prediction_4]++;
    int prediction_5 = predict_tree_5(features);
    votes[prediction_5]++;
    int prediction_6 = predict_tree_6(features);
    votes[prediction_6]++;
    int prediction_7 = predict_tree_7(features);
    votes[prediction_7]++;
    int prediction_8 = predict_tree_8(features);
    votes[prediction_8]++;
    int prediction_9 = predict_tree_9(features);
    votes[prediction_9]++;
    int prediction_10 = predict_tree_10(features);
    votes[prediction_10]++;
    int prediction_11 = predict_tree_11(features);
    votes[prediction_11]++;
    int prediction_12 = predict_tree_12(features);
    votes[prediction_12]++;
    int prediction_13 = predict_tree_13(features);
    votes[prediction_13]++;
    int prediction_14 = predict_tree_14(features);
    votes[prediction_14]++;
    int prediction_15 = predict_tree_15(features);
    votes[prediction_15]++;
    int prediction_16 = predict_tree_16(features);
    votes[prediction_16]++;
    int prediction_17 = predict_tree_17(features);
    votes[prediction_17]++;
    int prediction_18 = predict_tree_18(features);
    votes[prediction_18]++;
    int prediction_19 = predict_tree_19(features);
    votes[prediction_19]++;
    int prediction_20 = predict_tree_20(features);
    votes[prediction_20]++;
    int prediction_21 = predict_tree_21(features);
    votes[prediction_21]++;
    int prediction_22 = predict_tree_22(features);
    votes[prediction_22]++;
    int prediction_23 = predict_tree_23(features);
    votes[prediction_23]++;
    int prediction_24 = predict_tree_24(features);
    votes[prediction_24]++;
    int prediction_25 = predict_tree_25(features);
    votes[prediction_25]++;
    int prediction_26 = predict_tree_26(features);
    votes[prediction_26]++;
    int prediction_27 = predict_tree_27(features);
    votes[prediction_27]++;
    int prediction_28 = predict_tree_28(features);
    votes[prediction_28]++;
    int prediction_29 = predict_tree_29(features);
    votes[prediction_29]++;
    int prediction_30 = predict_tree_30(features);
    votes[prediction_30]++;
    int prediction_31 = predict_tree_31(features);
    votes[prediction_31]++;
    int prediction_32 = predict_tree_32(features);
    votes[prediction_32]++;
    int prediction_33 = predict_tree_33(features);
    votes[prediction_33]++;
    int prediction_34 = predict_tree_34(features);
    votes[prediction_34]++;
    int prediction_35 = predict_tree_35(features);
    votes[prediction_35]++;
    int prediction_36 = predict_tree_36(features);
    votes[prediction_36]++;
    int prediction_37 = predict_tree_37(features);
    votes[prediction_37]++;
    int prediction_38 = predict_tree_38(features);
    votes[prediction_38]++;
    int prediction_39 = predict_tree_39(features);
    votes[prediction_39]++;
    int prediction_40 = predict_tree_40(features);
    votes[prediction_40]++;
    int prediction_41 = predict_tree_41(features);
    votes[prediction_41]++;
    int prediction_42 = predict_tree_42(features);
    votes[prediction_42]++;
    int prediction_43 = predict_tree_43(features);
    votes[prediction_43]++;
    int prediction_44 = predict_tree_44(features);
    votes[prediction_44]++;
    int prediction_45 = predict_tree_45(features);
    votes[prediction_45]++;
    int prediction_46 = predict_tree_46(features);
    votes[prediction_46]++;
    int prediction_47 = predict_tree_47(features);
    votes[prediction_47]++;
    int prediction_48 = predict_tree_48(features);
    votes[prediction_48]++;
    int prediction_49 = predict_tree_49(features);
    votes[prediction_49]++;
    int prediction_50 = predict_tree_50(features);
    votes[prediction_50]++;
    int prediction_51 = predict_tree_51(features);
    votes[prediction_51]++;
    int prediction_52 = predict_tree_52(features);
    votes[prediction_52]++;
    int prediction_53 = predict_tree_53(features);
    votes[prediction_53]++;
    int prediction_54 = predict_tree_54(features);
    votes[prediction_54]++;
    int prediction_55 = predict_tree_55(features);
    votes[prediction_55]++;
    int prediction_56 = predict_tree_56(features);
    votes[prediction_56]++;
    int prediction_57 = predict_tree_57(features);
    votes[prediction_57]++;
    int prediction_58 = predict_tree_58(features);
    votes[prediction_58]++;
    int prediction_59 = predict_tree_59(features);
    votes[prediction_59]++;
    int prediction_60 = predict_tree_60(features);
    votes[prediction_60]++;
    int prediction_61 = predict_tree_61(features);
    votes[prediction_61]++;
    int prediction_62 = predict_tree_62(features);
    votes[prediction_62]++;
    int prediction_63 = predict_tree_63(features);
    votes[prediction_63]++;
    int prediction_64 = predict_tree_64(features);
    votes[prediction_64]++;
    int prediction_65 = predict_tree_65(features);
    votes[prediction_65]++;
    int prediction_66 = predict_tree_66(features);
    votes[prediction_66]++;
    int prediction_67 = predict_tree_67(features);
    votes[prediction_67]++;
    int prediction_68 = predict_tree_68(features);
    votes[prediction_68]++;
    int prediction_69 = predict_tree_69(features);
    votes[prediction_69]++;
    int prediction_70 = predict_tree_70(features);
    votes[prediction_70]++;
    int prediction_71 = predict_tree_71(features);
    votes[prediction_71]++;
    int prediction_72 = predict_tree_72(features);
    votes[prediction_72]++;
    int prediction_73 = predict_tree_73(features);
    votes[prediction_73]++;
    int prediction_74 = predict_tree_74(features);
    votes[prediction_74]++;
    int prediction_75 = predict_tree_75(features);
    votes[prediction_75]++;
    int prediction_76 = predict_tree_76(features);
    votes[prediction_76]++;
    int prediction_77 = predict_tree_77(features);
    votes[prediction_77]++;
    int prediction_78 = predict_tree_78(features);
    votes[prediction_78]++;
    int prediction_79 = predict_tree_79(features);
    votes[prediction_79]++;
    int prediction_80 = predict_tree_80(features);
    votes[prediction_80]++;
    int prediction_81 = predict_tree_81(features);
    votes[prediction_81]++;
    int prediction_82 = predict_tree_82(features);
    votes[prediction_82]++;
    int prediction_83 = predict_tree_83(features);
    votes[prediction_83]++;
    int prediction_84 = predict_tree_84(features);
    votes[prediction_84]++;
    int prediction_85 = predict_tree_85(features);
    votes[prediction_85]++;
    int prediction_86 = predict_tree_86(features);
    votes[prediction_86]++;
    int prediction_87 = predict_tree_87(features);
    votes[prediction_87]++;
    int prediction_88 = predict_tree_88(features);
    votes[prediction_88]++;
    int prediction_89 = predict_tree_89(features);
    votes[prediction_89]++;
    int prediction_90 = predict_tree_90(features);
    votes[prediction_90]++;
    int prediction_91 = predict_tree_91(features);
    votes[prediction_91]++;
    int prediction_92 = predict_tree_92(features);
    votes[prediction_92]++;
    int prediction_93 = predict_tree_93(features);
    votes[prediction_93]++;
    int prediction_94 = predict_tree_94(features);
    votes[prediction_94]++;
    int prediction_95 = predict_tree_95(features);
    votes[prediction_95]++;
    int prediction_96 = predict_tree_96(features);
    votes[prediction_96]++;
    int prediction_97 = predict_tree_97(features);
    votes[prediction_97]++;
    int prediction_98 = predict_tree_98(features);
    votes[prediction_98]++;
    int prediction_99 = predict_tree_99(features);
    votes[prediction_99]++;
    return (votes[0] > votes[1]) ? 0 : 1;  // Majority voting
}
