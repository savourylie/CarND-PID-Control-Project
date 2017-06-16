#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
    tau_p = fabs(Kp);
    tau_d = fabs(Kd);
    tau_i = fabs(Ki);    
    cte_prev = 0;
    cum_cte = 0;
    p_error = 0;
    d_error = 0;
    i_error = 0;

    // std::cout << "Init WTF?" << std::endl;
}

void PID::UpdateError(double cte, double dt) {
    // Initialize cte_prev
    if (cte_prev == 0) {
        cte_prev = cte;
    }

    // Accumuluate cum_cte
    cum_cte = cum_cte + cte;

    p_error = tau_p * cte;
    d_error = tau_d * (cte - cte_prev) / dt;
    i_error = tau_i * cum_cte * dt;

    cte_prev = cte;
    // std::cout << "P: " << tau_p << std::endl;
    // std::cout << "D: " << tau_d << std::endl;
    // std::cout << "I: " << tau_i << std::endl;
}

double PID::TotalError() {
    double raw_output = -(p_error + i_error + d_error);
    std::cout << "P error: " << p_error << std::endl;
    std::cout << "D error: " << d_error << std::endl;
    std::cout << "I error: " << i_error << std::endl;
    // std::cout << "Raw output: " << raw_output << std::endl;
    return raw_output;
}

