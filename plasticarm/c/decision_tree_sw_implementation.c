#include <stdio.h>
//#include <stdlib.h>
//#include "uRSD.h"
//#include "static_data_small.h"
#include "static_data.h"

// Female DT uses only Sensors J & L
char  Female_DT(Sensor_J_FF_Delta, Sensor_L_FF_Delta, Sensor_J_BB_Delta, Sensor_L_BB_Delta) {
  char predicted_class;

  if (Sensor_J_FF_Delta <= 41) {
    if (Sensor_L_BB_Delta <= 45) {
      if (Sensor_L_FF_Delta <= 43) {
        if (Sensor_J_FF_Delta <= 39) {
          if (Sensor_L_BB_Delta <= 39) predicted_class =  4;
          else {
            if (Sensor_J_FF_Delta <= 35) predicted_class =  8;
            else {
              if (Sensor_J_BB_Delta <= 37) predicted_class =  8;
              else {
                if (Sensor_J_FF_Delta <= 37) {
                  if (Sensor_L_BB_Delta <= 41) {
                    if (Sensor_J_BB_Delta <= 39) {
                      //if (Sensor_L_FF_Delta <= 39) predicted_class =  4;
                      //else predicted_class =  4;
                      predicted_class =  4;
                    } // if Sensor_J_BB_Delta > 39
                    else predicted_class =  4;
                  } //if Sensor_L_BB_Delta > 41
                  else predicted_class =  4;
                }
                else { //if Sensor_J_FF_Delta > 37
                  if (Sensor_L_FF_Delta <= 41) predicted_class =  8;
                  else predicted_class =  4;
                }
              }
            }
          }
        } // if Sensor_J_FF_Delta > 39
        else predicted_class =  8;
     } // if Sensor_L_FF_Delta > 43
     else predicted_class =  4;
    } //if Sensor_L_BB_Delta > 45
    else {
      if (Sensor_J_FF_Delta <= 39) predicted_class =  16;
      else {
        if (Sensor_J_BB_Delta <= 43) predicted_class =  8;
        else {
          //if (Sensor_L_BB_Delta <= 47) predicted_class=  4;
          //else predicted_class =  4;
          predicted_class =  4;
        }
      }
    }
  } // if Sensor_J_FF_Delta > 41
  else {
    if (Sensor_L_BB_Delta <= 47) {
      //if (Sensor_J_BB_Delta <= 43) predicted_class =  1;
      //else predicted_class =  1;
      predicted_class =  1;
    } // if Sensor_L_BB_Delta > 47
    else {
      //if (Sensor_J_FF_Delta <= 46) predicted_class =  4;
      //else predicted_class =  4;
      predicted_class =  4;
    }
  }

  return predicted_class;
}


// Male DT uses only Sensors I & K but Sensor_I_FF_Delta value is never used
char Male_DT(Sensor_K_FF_Delta, Sensor_I_BB_Delta, Sensor_K_BB_Delta) {
  char predicted_class;

  if (Sensor_K_FF_Delta <= 27) {
    if (Sensor_K_FF_Delta <= 25) {
      if (Sensor_K_BB_Delta <= 25) predicted_class =  4;
      else predicted_class =  8;
    } // if Sensor_K_FF_Delta > 25
    else {
      //if (Sensor_K_BB_Delta <= 27) predicted_class =  8;
      //else predicted_class =  8;
      predicted_class =  8;
    }
  } // if Sensor_K_FF_Delta > 27
  else {
    if (Sensor_K_BB_Delta <= 37) {
      if (Sensor_K_BB_Delta <= 31) {
        if (Sensor_K_BB_Delta <= 27) predicted_class =  8;
        else {
          if (Sensor_K_BB_Delta <= 29) predicted_class =  2;
          else predicted_class =  4;
        }
      } // if Sensor_K_BB_Delta > 31
      else {
        if (Sensor_K_FF_Delta <= 33) {
          if (Sensor_K_FF_Delta <= 31) {
            //if (Sensor_K_BB_Delta <= 33) predicted_class =  16;
            //else predicted_class =  16;
            predicted_class =  16;
          } // if Sensor_K_FF_Delta > 31
          else {
            if (Sensor_K_BB_Delta <= 33) predicted_class =  1;
            else predicted_class =  8;
          }
        } // if Sensor_K_FF_Delta > 33
        else {
          //if (Sensor_K_BB_Delta <= 35) predicted_class =  2;
          //else predicted_class =  2;
          predicted_class =  2;
        }
      }
    } // if Sensor_K_BB_Delta > 37
    else {
      if (Sensor_I_BB_Delta <= 1) {
        //if (Sensor_K_FF_Delta <= 35) predicted_class =  4;
        //else predicted_class =  4;
        predicted_class =  4;
      } // if Sensor_I_BB_Delta > 1
      else predicted_class =  8;
    }
  }

  return predicted_class;
}


// Read the sensor values from the data samples and run the DTs to make predictions
// Compare the predicted class made by this model to the predicted class made by the Python model for equivalence check
void Read_Sensor_Values_Run_DTs() {
  char Sensor_J_FF_Delta, Sensor_K_FF_Delta, Sensor_L_FF_Delta, Sensor_I_BB_Delta, Sensor_J_BB_Delta, Sensor_K_BB_Delta, Sensor_L_BB_Delta, python_predicted_class, onehot_encoded_python_predicted_class, gender, c_predicted_class;
  //char Sensor_J_FF_Delta, Sensor_L_FF_Delta, Sensor_J_BB_Delta, Sensor_L_BB_Delta, data_sample, python_predicted_class, c_predicted_class, onehot_encoded_python_predicted_class;
  unsigned short data_sample;
  char GPIO;
  // Read sensor values from the static data array
  // Because trained Decision Trees use half-point boundary conditions (e.g. 9.5)
  // so I have multiplied these conditions by 2 to make them integer numbers
  // Therefore when the sensor values are received from SRI to MLE
  // Sensor values will be multiplied by 2
  for (data_sample=0; data_sample<Num_Data_Samples; data_sample++) {
    Sensor_J_FF_Delta = Sensor_J_FF_Delta_Vector[data_sample] << 1;
    Sensor_K_FF_Delta = Sensor_K_FF_Delta_Vector[data_sample] << 1;
    Sensor_L_FF_Delta = Sensor_L_FF_Delta_Vector[data_sample] << 1;
    Sensor_I_BB_Delta = Sensor_I_BB_Delta_Vector[data_sample] << 1;
    Sensor_J_BB_Delta = Sensor_J_BB_Delta_Vector[data_sample] << 1;
    Sensor_K_BB_Delta = Sensor_K_BB_Delta_Vector[data_sample] << 1;
    Sensor_L_BB_Delta = Sensor_L_BB_Delta_Vector[data_sample] << 1;

    python_predicted_class                = SW_Predicted_Class_Vector[data_sample];
    // Predicted classes spitted out by the HW are in one-hot encoded format
    // Because of this, we need to convert the predicted classes coming from the datasets into one-hot format
    onehot_encoded_python_predicted_class = 1 << python_predicted_class;
    gender                                = Gender_Vector[data_sample];

    // Female
    if (gender == 0) {
      c_predicted_class = Female_DT(Sensor_J_FF_Delta, Sensor_L_FF_Delta, Sensor_J_BB_Delta, Sensor_L_BB_Delta);
    }
    else c_predicted_class = Male_DT(Sensor_K_FF_Delta, Sensor_I_BB_Delta, Sensor_K_BB_Delta);

    if (onehot_encoded_python_predicted_class != c_predicted_class) {
      //printf("Error: Python model prediction does not match the C model\n");
      //printf("Data Sample %d: onehot_encoded_python_predicted_class= %d --- c_predicted_class= %d\n", data_sample, onehot_encoded_python_predicted_class, c_predicted_class);
      //exit(-1);
      GPIO = 0;
    }
    else GPIO = 1;
    //printf ("GPIO=%d for Data Sample:%d\n", GPIO, data_sample);
  }

  //printf("SUCCESS: Predicted classes from the Python model match the predicted classes C model for all data samples in the PlasticArmpit dataset!\n");

}

int main() {
  Read_Sensor_Values_Run_DTs();

  return 0;
}
