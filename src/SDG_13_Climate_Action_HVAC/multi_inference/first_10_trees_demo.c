#include "sample_data.h"  // Must define: Num_Features, Data[]

/* 
 * Tree functions (exactly as provided). Each returns 0 or 1.
 */

int predict_tree_0(float features[]) {
    if (features[2] <= 15378) {
        if (features[4] <= 62709) {
            if (features[2] <= 12258) {
                if (features[3] <= 17501) {
                    return 0;
                } else {
                    if (features[2] <= 8052) {
                        if (features[1] <= 48277) {
                            if (features[3] <= 33052) {
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
                if (features[1] <= 6963) {
                    return 0;
                } else {
                    if (features[1] <= 34348) {
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
        if (features[0] <= 58208) {
            if (features[3] <= 1884) {
                if (features[2] <= 17170) {
                    return 1;
                } else {
                    if (features[0] <= 18048) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 52048) {
                    if (features[1] <= 7665) {
                        if (features[1] <= 7625) {
                            if (features[3] <= 9602) {
                                return 1;
                            } else {
                                if (features[0] <= 43076) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 51328) {
                            if (features[3] <= 2538) {
                                if (features[1] <= 16803) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[1] <= 11035) {
                                    if (features[1] <= 10991) {
                                        if (features[1] <= 10640) {
                                            return 1;
                                        } else {
                                            if (features[2] <= 20194) {
                                                if (features[2] <= 19982) {
                                                    return 1;
                                                } else {
                                                    return 0;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 20130) {
                                            return 1;
                                        } else {
                                            if (features[3] <= 16051) {
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
                            if (features[2] <= 18774) {
                                return 1;
                            } else {
                                if (features[4] <= 31266) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (features[4] <= 29446) {
                        if (features[3] <= 20948) {
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
            if (features[4] <= 33034) {
                if (features[1] <= 28486) {
                    return 0;
                } else {
                    if (features[0] <= 59320) {
                        if (features[1] <= 28745) {
                            if (features[3] <= 26166) {
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

int predict_tree_1(float features[]) {
    if (features[3] <= 8355) {
        if (features[3] <= 3381) {
            if (features[3] <= 2778) {
                if (features[2] <= 16127) {
                    if (features[3] <= 2472) {
                        if (features[0] <= 26973) {
                            return 0;
                        } else {
                            if (features[0] <= 27352) {
                                if (features[3] <= 1763) {
                                    return 0;
                                } else {
                                    if (features[2] <= 7543) {
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
                        if (features[3] <= 2479) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 1884) {
                        if (features[4] <= 739) {
                            if (features[2] <= 17679) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[3] <= 2416) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                if (features[2] <= 17121) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[2] <= 8243) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[0] <= 28877) {
            if (features[4] <= 38621) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[1] <= 55548) {
                if (features[2] <= 8052) {
                    return 0;
                } else {
                    if (features[0] <= 59800) {
                        if (features[3] <= 19468) {
                            if (features[3] <= 19387) {
                                if (features[1] <= 25704) {
                                    if (features[4] <= 10529) {
                                        if (features[0] <= 40759) {
                                            return 1;
                                        } else {
                                            if (features[1] <= 10991) {
                                                if (features[0] <= 41824) {
                                                    return 0;
                                                } else {
                                                    if (features[2] <= 20194) {
                                                        if (features[3] <= 15848) {
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
                                    if (features[2] <= 18933) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 16004) {
                                            if (features[4] <= 28316) {
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
                                if (features[1] <= 20804) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[0] <= 58142) {
                                if (features[3] <= 25610) {
                                    if (features[1] <= 28717) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 25359) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 31783) {
                                    return 0;
                                } else {
                                    if (features[1] <= 28709) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 23245) {
                                            if (features[4] <= 32447) {
                                                return 0;
                                            } else {
                                                if (features[3] <= 28273) {
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
                if (features[3] <= 52302) {
                    if (features[4] <= 55301) {
                        if (features[2] <= 9975) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 9408) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 6950) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}

int predict_tree_2(float features[]) {
    if (features[3] <= 7060) {
        if (features[1] <= 20812) {
            if (features[2] <= 16114) {
                if (features[2] <= 15044) {
                    return 0;
                } else {
                    if (features[4] <= 8846) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[2] <= 17831) {
                    if (features[1] <= 6034) {
                        if (features[4] <= 739) {
                            return 1;
                        } else {
                            if (features[0] <= 18248) {
                                return 0;
                            } else {
                                if (features[0] <= 18581) {
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
            if (features[0] <= 8191) {
                return 0;
            } else {
                if (features[3] <= 2411) {
                    return 0;
                } else {
                    if (features[2] <= 6139) {
                        return 0;
                    } else {
                        if (features[0] <= 8790) {
                            if (features[4] <= 19682) {
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
        if (features[1] <= 48325) {
            if (features[2] <= 8052) {
                if (features[4] <= 44351) {
                    return 0;
                } else {
                    if (features[3] <= 33607) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (features[0] <= 58208) {
                    if (features[0] <= 51328) {
                        if (features[2] <= 19441) {
                            return 1;
                        } else {
                            if (features[2] <= 19473) {
                                if (features[1] <= 28916) {
                                    return 1;
                                } else {
                                    if (features[3] <= 27697) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[3] <= 16365) {
                                    if (features[1] <= 10991) {
                                        if (features[2] <= 20194) {
                                            if (features[2] <= 20035) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        } else {
                                            if (features[3] <= 9714) {
                                                if (features[3] <= 9572) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 39080) {
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
                                        if (features[1] <= 11035) {
                                            if (features[2] <= 20130) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 15772) {
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
                                    if (features[1] <= 28721) {
                                        return 1;
                                    } else {
                                        if (features[3] <= 25570) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[3] <= 20259) {
                            if (features[4] <= 30412) {
                                if (features[2] <= 20618) {
                                    if (features[4] <= 28289) {
                                        return 0;
                                    } else {
                                        if (features[3] <= 16284) {
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
                    if (features[2] <= 22666) {
                        if (features[0] <= 58874) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[3] <= 28099) {
                            return 0;
                        } else {
                            if (features[2] <= 23245) {
                                return 0;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 37802) {
                return 0;
            } else {
                if (features[0] <= 46413) {
                    if (features[1] <= 58673) {
                        if (features[2] <= 9525) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[2] <= 9408) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[2] <= 6950) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}

int predict_tree_3(float features[]) {
    if (features[0] <= 28811) {
        if (features[0] <= 28191) {
            if (features[3] <= 2778) {
                if (features[2] <= 15357) {
                    return 0;
                } else {
                    if (features[3] <= 1765) {
                        return 0;
                    } else {
                        if (features[4] <= 792) {
                            return 0;
                        } else {
                            if (features[0] <= 23356) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                if (features[2] <= 8243) {
                    return 0;
                } else {
                    if (features[0] <= 9123) {
                        if (features[4] <= 19601) {
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
            if (features[2] <= 13386) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 6952) {
            if (features[1] <= 18725) {
                if (features[1] <= 18358) {
                    if (features[3] <= 6535) {
                        return 0;
                    } else {
                        if (features[3] <= 6616) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 14401) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 7296) {
                if (features[3] <= 33735) {
                    return 0;
                } else {
                    if (features[1] <= 52466) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[0] <= 58142) {
                    if (features[4] <= 29443) {
                        if (features[0] <= 52168) {
                            if (features[4] <= 29407) {
                                if (features[0] <= 51388) {
                                    if (features[4] <= 28952) {
                                        if (features[1] <= 7564) {
                                            if (features[1] <= 7366) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 9764) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (features[2] <= 20067) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 10228) {
                                                    if (features[4] <= 10217) {
                                                        return 1;
                                                    } else {
                                                        if (features[2] <= 20194) {
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
                                        if (features[0] <= 49150) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 27582) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 19483) {
                                if (features[4] <= 28395) {
                                    if (features[4] <= 28289) {
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
                    if (features[1] <= 29757) {
                        if (features[3] <= 23428) {
                            return 1;
                        } else {
                            if (features[2] <= 22138) {
                                if (features[1] <= 28940) {
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

int predict_tree_4(float features[]) {
    if (features[2] <= 15913) {
        if (features[0] <= 27013) {
            if (features[2] <= 12235) {
                return 0;
            } else {
                if (features[4] <= 23318) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            if (features[1] <= 16110) {
                return 0;
            } else {
                if (features[4] <= 12218) {
                    if (features[3] <= 1748) {
                        return 0;
                    } else {
                        if (features[3] <= 1804) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[3] <= 17129) {
                        return 0;
                    } else {
                        if (features[1] <= 23991) {
                            return 1;
                        } else {
                            if (features[1] <= 48277) {
                                if (features[3] <= 33052) {
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
        if (features[3] <= 1779) {
            return 0;
        } else {
            if (features[4] <= 792) {
                return 0;
            } else {
                if (features[2] <= 22191) {
                    if (features[0] <= 52168) {
                        if (features[0] <= 8790) {
                            if (features[1] <= 30650) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[3] <= 2538) {
                                if (features[2] <= 17856) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 19224) {
                                    return 1;
                                } else {
                                    if (features[2] <= 19473) {
                                        if (features[3] <= 14790) {
                                            if (features[2] <= 19256) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[2] <= 19425) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 24795) {
                                                    return 1;
                                                } else {
                                                    if (features[3] <= 26407) {
                                                        return 0;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[1] <= 11048) {
                                            if (features[3] <= 15943) {
                                                return 1;
                                            } else {
                                                if (features[0] <= 43696) {
                                                    if (features[1] <= 10991) {
                                                        if (features[3] <= 15963) {
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
                                            if (features[0] <= 48551) {
                                                return 1;
                                            } else {
                                                if (features[1] <= 28684) {
                                                    return 1;
                                                } else {
                                                    if (features[0] <= 49150) {
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
                        if (features[4] <= 29088) {
                            if (features[2] <= 18785) {
                                return 1;
                            } else {
                                if (features[3] <= 22378) {
                                    if (features[3] <= 16102) {
                                        if (features[4] <= 28289) {
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
                    if (features[2] <= 22233) {
                        if (features[1] <= 7420) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[1] <= 27176) {
                            if (features[4] <= 6888) {
                                if (features[3] <= 9527) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[0] <= 58874) {
                                if (features[1] <= 27937) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[3] <= 28092) {
                                    return 0;
                                } else {
                                    if (features[2] <= 22737) {
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

int predict_tree_5(float features[]) {
    if (features[0] <= 35704) {
        if (features[3] <= 4623) {
            if (features[1] <= 7503) {
                if (features[3] <= 1828) {
                    if (features[2] <= 14020) {
                        return 0;
                    } else {
                        if (features[3] <= 1125) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (features[4] <= 1620) {
                        return 1;
                    } else {
                        if (features[0] <= 19720) {
                            if (features[0] <= 18561) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[3] <= 3310) {
                                return 0;
                            } else {
                                if (features[2] <= 8666) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] <= 3445) {
                    if (features[0] <= 26973) {
                        if (features[0] <= 8191) {
                            return 0;
                        } else {
                            if (features[0] <= 8457) {
                                if (features[4] <= 19561) {
                                    if (features[1] <= 29914) {
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
                        if (features[1] <= 14060) {
                            return 0;
                        } else {
                            if (features[4] <= 12147) {
                                if (features[3] <= 1804) {
                                    if (features[3] <= 1748) {
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
                    if (features[1] <= 13734) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (features[2] <= 11781) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        if (features[3] <= 7913) {
            return 0;
        } else {
            if (features[0] <= 58208) {
                if (features[0] <= 41758) {
                    if (features[1] <= 54791) {
                        if (features[4] <= 9853) {
                            if (features[1] <= 8541) {
                                if (features[0] <= 40759) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                return 0;
                            }
                        } else {
                            if (features[4] <= 18533) {
                                if (features[1] <= 13847) {
                                    if (features[1] <= 11716) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[3] <= 10200) {
                                        if (features[3] <= 9186) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[4] <= 44976) {
                                    if (features[4] <= 43029) {
                                        return 1;
                                    } else {
                                        if (features[2] <= 10488) {
                                            if (features[3] <= 33607) {
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
                    if (features[2] <= 6696) {
                        return 0;
                    } else {
                        if (features[0] <= 51328) {
                            if (features[4] <= 10641) {
                                if (features[1] <= 10991) {
                                    if (features[2] <= 20194) {
                                        if (features[2] <= 20035) {
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
                                if (features[1] <= 28721) {
                                    return 1;
                                } else {
                                    if (features[2] <= 19441) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 29428) {
                                            if (features[4] <= 29407) {
                                                if (features[3] <= 25570) {
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
                            if (features[0] <= 53586) {
                                if (features[3] <= 19433) {
                                    if (features[2] <= 18689) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 27092) {
                                            if (features[4] <= 28342) {
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
                if (features[1] <= 28373) {
                    return 0;
                } else {
                    if (features[3] <= 28199) {
                        if (features[1] <= 28745) {
                            if (features[4] <= 31783) {
                                if (features[2] <= 22138) {
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

int predict_tree_6(float features[]) {
    if (features[2] <= 16644) {
        if (features[4] <= 63181) {
            if (features[0] <= 36459) {
                if (features[2] <= 14266) {
                    return 0;
                } else {
                    if (features[2] <= 15860) {
                        return 1;
                    } else {
                        if (features[4] <= 21731) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (features[3] <= 9668) {
                    return 0;
                } else {
                    if (features[3] <= 10303) {
                        return 1;
                    } else {
                        if (features[1] <= 48277) {
                            if (features[1] <= 48072) {
                                if (features[2] <= 6902) {
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
        if (features[3] <= 1718) {
            if (features[2] <= 17382) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (features[2] <= 28338) {
                if (features[1] <= 29728) {
                    if (features[3] <= 27178) {
                        if (features[4] <= 27838) {
                            if (features[0] <= 27352) {
                                if (features[0] <= 26773) {
                                    return 1;
                                } else {
                                    if (features[4] <= 8442) {
                                        return 1;
                                    } else {
                                        return 0;
                                    }
                                }
                            } else {
                                if (features[4] <= 10607) {
                                    if (features[3] <= 15943) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 10582) {
                                            if (features[4] <= 10230) {
                                                if (features[1] <= 10567) {
                                                    return 1;
                                                } else {
                                                    if (features[2] <= 20194) {
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
                            if (features[0] <= 51328) {
                                if (features[1] <= 28953) {
                                    return 1;
                                } else {
                                    if (features[3] <= 25664) {
                                        if (features[4] <= 29812) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (features[1] <= 27465) {
                                    if (features[1] <= 27056) {
                                        if (features[0] <= 52407) {
                                            return 0;
                                        } else {
                                            if (features[1] <= 26881) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 15630) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[2] <= 18753) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                } else {
                                    if (features[0] <= 58475) {
                                        if (features[0] <= 52787) {
                                            if (features[3] <= 19453) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[4] <= 31664) {
                                                return 1;
                                            } else {
                                                if (features[2] <= 22138) {
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
                        if (features[4] <= 32301) {
                            return 1;
                        } else {
                            if (features[0] <= 58341) {
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
                if (features[1] <= 28275) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}

int predict_tree_7(float features[]) {
    if (features[0] <= 28811) {
        if (features[2] <= 13762) {
            if (features[2] <= 12235) {
                return 0;
            } else {
                if (features[3] <= 1495) {
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if (features[3] <= 1774) {
                if (features[2] <= 17213) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 16644) {
                    if (features[2] <= 16560) {
                        return 1;
                    } else {
                        if (features[4] <= 21731) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 6004) {
                        if (features[0] <= 18248) {
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
        if (features[3] <= 6759) {
            if (features[2] <= 16114) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (features[2] <= 7296) {
                if (features[4] <= 44428) {
                    return 0;
                } else {
                    if (features[4] <= 44903) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[1] <= 26591) {
                    if (features[2] <= 22747) {
                        return 1;
                    } else {
                        if (features[4] <= 6888) {
                            if (features[3] <= 9364) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (features[1] <= 27860) {
                        if (features[3] <= 19483) {
                            if (features[0] <= 51388) {
                                return 1;
                            } else {
                                if (features[3] <= 16102) {
                                    if (features[3] <= 15838) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 0;
                                }
                            }
                        } else {
                            if (features[4] <= 31179) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    } else {
                        if (features[2] <= 22016) {
                            if (features[4] <= 29428) {
                                if (features[1] <= 28916) {
                                    if (features[2] <= 19828) {
                                        return 1;
                                    } else {
                                        if (features[1] <= 28630) {
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
                            if (features[0] <= 58208) {
                                return 1;
                            } else {
                                if (features[1] <= 29229) {
                                    if (features[0] <= 59800) {
                                        if (features[0] <= 59320) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 0;
                                    }
                                } else {
                                    if (features[2] <= 23245) {
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

int predict_tree_8(float features[]) {
    if (features[2] <= 15728) {
        if (features[1] <= 63085) {
            if (features[3] <= 2465) {
                if (features[1] <= 16615) {
                    if (features[4] <= 11521) {
                        return 0;
                    } else {
                        if (features[2] <= 7543) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                if (features[2] <= 8052) {
                    if (features[3] <= 33735) {
                        return 0;
                    } else {
                        if (features[4] <= 47132) {
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
        if (features[0] <= 58142) {
            if (features[4] <= 3579) {
                if (features[3] <= 1889) {
                    if (features[0] <= 18048) {
                        if (features[0] <= 17782) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[4] <= 739) {
                            if (features[3] <= 1033) {
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
                if (features[0] <= 51328) {
                    if (features[2] <= 16878) {
                        if (features[1] <= 31960) {
                            if (features[4] <= 17514) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (features[0] <= 41358) {
                            return 1;
                        } else {
                            if (features[4] <= 7027) {
                                if (features[1] <= 7322) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            } else {
                                if (features[2] <= 19441) {
                                    return 1;
                                } else {
                                    if (features[4] <= 28952) {
                                        if (features[3] <= 16289) {
                                            if (features[2] <= 20335) {
                                                if (features[3] <= 16205) {
                                                    if (features[1] <= 10838) {
                                                        if (features[4] <= 10066) {
                                                            return 1;
                                                        } else {
                                                            if (features[4] <= 10378) {
                                                                if (features[2] <= 19982) {
                                                                    return 1;
                                                                } else {
                                                                    if (features[2] <= 20095) {
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
                                        if (features[2] <= 19473) {
                                            if (features[3] <= 26407) {
                                                return 0;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (features[0] <= 49150) {
                                                if (features[3] <= 31606) {
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
                    if (features[3] <= 20284) {
                        if (features[3] <= 16102) {
                            if (features[4] <= 28289) {
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
            if (features[4] <= 31329) {
                return 1;
            } else {
                if (features[3] <= 28462) {
                    if (features[0] <= 58475) {
                        if (features[2] <= 22138) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        if (features[0] <= 59320) {
                            return 0;
                        } else {
                            if (features[3] <= 24868) {
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

int predict_tree_9(float features[]) {
    if (features[0] <= 28431) {
        if (features[0] <= 26706) {
            if (features[2] <= 12067) {
                return 0;
            } else {
                if (features[1] <= 5968) {
                    if (features[0] <= 18581) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (features[3] <= 3040) {
                        if (features[4] <= 19771) {
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
            if (features[3] <= 2205) {
                if (features[3] <= 1774) {
                    return 0;
                } else {
                    if (features[3] <= 1804) {
                        if (features[4] <= 12218) {
                            return 1;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                if (features[4] <= 41288) {
                    if (features[3] <= 5206) {
                        if (features[1] <= 8029) {
                            return 0;
                        } else {
                            if (features[2] <= 8864) {
                                return 0;
                            } else {
                                if (features[1] <= 12410) {
                                    return 1;
                                } else {
                                    if (features[0] <= 27352) {
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
        if (features[3] <= 5666) {
            if (features[4] <= 14891) {
                if (features[1] <= 14093) {
                    return 0;
                } else {
                    if (features[1] <= 17780) {
                        return 1;
                    } else {
                        if (features[2] <= 8476) {
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
            if (features[1] <= 55527) {
                if (features[1] <= 27740) {
                    if (features[4] <= 28446) {
                        if (features[4] <= 9525) {
                            if (features[1] <= 8886) {
                                if (features[2] <= 9002) {
                                    return 0;
                                } else {
                                    if (features[4] <= 7022) {
                                        return 1;
                                    } else {
                                        if (features[4] <= 7049) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (features[3] <= 13921) {
                                    if (features[4] <= 6117) {
                                        if (features[4] <= 5928) {
                                            if (features[4] <= 5846) {
                                                return 1;
                                            } else {
                                                if (features[3] <= 7770) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[2] <= 10987) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (features[4] <= 8854) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (features[3] <= 14961) {
                                if (features[4] <= 10126) {
                                    if (features[0] <= 39880) {
                                        if (features[3] <= 10332) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (features[4] <= 16254) {
                                        if (features[2] <= 9175) {
                                            return 0;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (features[2] <= 8582) {
                                            return 0;
                                        } else {
                                            if (features[1] <= 24346) {
                                                return 1;
                                            } else {
                                                if (features[4] <= 28137) {
                                                    return 0;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 9027) {
                                    return 0;
                                } else {
                                    if (features[3] <= 16365) {
                                        if (features[0] <= 51688) {
                                            if (features[3] <= 16350) {
                                                if (features[1] <= 11035) {
                                                    if (features[4] <= 10521) {
                                                        return 1;
                                                    } else {
                                                        if (features[2] <= 21571) {
                                                            if (features[3] <= 16205) {
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
                                            if (features[4] <= 28342) {
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
                        if (features[0] <= 60619) {
                            if (features[3] <= 24315) {
                                return 0;
                            } else {
                                return 1;
                            }
                        } else {
                            if (features[4] <= 31329) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    if (features[3] <= 33253) {
                        if (features[1] <= 46267) {
                            if (features[0] <= 59800) {
                                if (features[0] <= 58142) {
                                    if (features[3] <= 25630) {
                                        if (features[4] <= 29924) {
                                            if (features[3] <= 25557) {
                                                if (features[0] <= 51868) {
                                                    if (features[1] <= 28717) {
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
                                    if (features[3] <= 27764) {
                                        if (features[3] <= 26166) {
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
                            if (features[3] <= 29167) {
                                if (features[1] <= 47080) {
                                    return 0;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (features[4] <= 44326) {
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
                if (features[2] <= 6950) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}

/****************************************************
 * Now, we combine the 10 trees in a simple majority.
 *   If at least 5 of them return '1', final=1
 *   otherwise final=0
 ****************************************************/

static int predict_forest_10(float features[]) {
    int votes = 0;

    votes += predict_tree_0(features);
    votes += predict_tree_1(features);
    votes += predict_tree_2(features);
    votes += predict_tree_3(features);
    votes += predict_tree_4(features);
    votes += predict_tree_5(features);
    votes += predict_tree_6(features);
    votes += predict_tree_7(features);
    votes += predict_tree_8(features);
    votes += predict_tree_9(features);

    // Majority threshold for 10 trees
    if (votes >= 5) {
        return 1;
    } else {
        return 0;
    }
}

/****************************************************
 * Global volatile variable to prevent compiler
 * optimizing away the "GPIO-like" result.
 ****************************************************/
volatile char correct_result = -1;

/****************************************************
 * This function reads sensor inputs from Data[],
 * calls the ensemble (10-tree) predictor, compares
 * with "golden_reference" from Data[Num_Features],
 * and returns 1 (GPIO=1) if match, else 0 (GPIO=0).
 ****************************************************/
char Read_Sensor_Values_Run_Trees(void) {
    // We expect Data[] to have at least Num_Features + 1 entries
    // where Data[Num_Features] is the label/golden reference
    char golden_reference;
    float sensor_inputs[Num_Features];
    char GPIO = 1;  // default

    // 1) Fill in the current sensor input from Data[]
    for (int i = 0; i < Num_Features; ++i) {
        sensor_inputs[i] = (float)Data[i];
    }

    // 2) The label is the "golden reference" (what we expect)
    golden_reference = (char)Data[Num_Features];

    // 3) Predict using the 10-tree random forest (majority vote)
    int final_prediction = predict_forest_10(sensor_inputs);

    // 4) Compare final_prediction to golden_reference
    if (golden_reference != final_prediction) {
        GPIO = 0;  // mismatch => turn GPIO off
    }
    // If match, GPIO stays 1

    return GPIO;
}

int main(void) {
    // Run the read-and-predict routine
    correct_result = Read_Sensor_Values_Run_Trees();

    // For debugging, you could print:
    // printf("GPIO (correct_result) = %d\n", correct_result);

    return 0;
}
