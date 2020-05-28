#ifndef PID_H
#define PID_H
#include <limits>
#include <vector>

class PID {
public:
    /**
     * Constructor
     */
    PID();

    /**
     * Destructor.
     */
    virtual ~PID();

    /**
     * Initialize PID.
     * @param (Kp_, Ki_, Kd_) The initial PID coefficients
     */
    void Init(double Kp_, double Ki_, double Kd_);

    /**
     * Update the PID error variables given cross track error.
     * @param cte The current cross track error
     */
    void UpdateError(double cte);

    //   void Init_d(double dp, double di, double dd);

    //   bool tol_reached(double tol);

    //   void twiddle(double cte);

      /**
       * Calculate the total PID error.
       * @output The total PID error
       */
    double TotalError();


    //   bool twiddle_mode = false;

private:
    /**
     * PID Errors
     */
    double p_error;
    double i_error;
    double d_error;
    double last_d_error = 0;

    //   std::vector<double> d{1, 1, 1};

    //   double best_err = std::numeric_limits<double>::max();
    //   double err = 0;

    //   int counter = 0;
    //   int index = 0;

    //   int case_switch = 0;
    //   /**
    //    * PID Coefficients
    //    */ 
    std::vector<double> K{ 0, 0, 0 };

};

#endif  // PID_H