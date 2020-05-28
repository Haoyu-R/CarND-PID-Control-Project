#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    /**
     * TODO: Initialize PID coefficients (and errors, if needed)
     */
    K[0] = Kp_;
    K[1] = Ki_;
    K[2] = Kd_;
}

// void PID::Init_d(double dp, double di, double dd){
//   d[0] = dp;
//   d[1] = di;
//   d[2] = dd; 
// }

void PID::UpdateError(double cte) {
    /**
     * TODO: Update PID errors based on cte.
     */
     // if(twiddle_mode){
     //   twiddle(cte);
     // }
    p_error = -K[0] * cte;
    i_error -= K[1] * cte;

    d_error = -K[2] * (cte - last_d_error);
    last_d_error = cte;
}

double PID::TotalError() {
    /**
     * TODO: Calculate and return the total error
     */
    return p_error + i_error + d_error;  // TODO: Add your total error calc here!
}

// bool PID::tol_reached(double tol){

//      if(d[0]+d[1]+d[2] < tol){
//         return true;
//      }
//      return false;
// }

// void PID::twiddle(double cte){

//   if(tol_reached(0.00001)){
//     std::cout << "Best Kp: " << K[0] << " Best Ki: " << K[1] << " Best Kd:" << K[2]
//           << std::endl;
//     while(true){};
//   }

//   // if(counter == 0){
//   //   K[index] += d[index];
//   //   counter++;
//   // }

//   counter++;

//   if(counter > 100){
//     err += cte;
//   }

//   if(counter > 1100){
//     counter = 0;

//     switch (case_switch)
//     {
//     case 0:
//       if(err < best_err){
//         best_err = err;
//         d[index] *= 1.1;
//         index = (index+1) %2;
//         K[index] += d[index];
//       }else{
//         case_switch = 1;
//         K[index] -= 2*d[index];
//       }
//       break;
//     case 1:
//       if(err < best_err){
//         best_err = err;
//         d[index] *= 1.1;
//         index = (index+1) %2;
//         K[index] += d[index];
//         case_switch = 0;
//       }else{
//         K[index] += d[index];
//         d[index] *= 0.9;
//         index = (index+1) %2;
//         K[index] += d[index];
//         case_switch = 0;
//       }
//       break;
//     }

//     err = 0;
//   }

// }
