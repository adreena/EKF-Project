#include "kalman_filter.h"
#include <iostream>

#define PI 3.14159265
#define THRESHOLD 0.001

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  Q_ = Q_in;
}

void KalmanFilter::Predict() {
  /**
  TODO:
    * predict the state
  */
  x_ = F_ * x_;
  P_ = F_ * P_ * F_.transpose() + Q_;
  cout << "P_ estimated: "<<P_<<endl;
}

void KalmanFilter::Update(const VectorXd &z) {
  /**
  TODO:
    * update the state by using Kalman Filter equations
  */
  VectorXd y = z - H_ * x_ ; // error
  Update_Helper(y); 
}

void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
  TODO:
    * update the state by using Extended Kalman Filter equations
  */
  //estimated z
  float rho =  sqrt(pow(x_[0],2) + pow(x_[1],2));
  float phi =  0.0;
  float rho_dot = 0.0;

  if (fabs(x_[0]) > THRESHOLD)
    phi  = atan2(x_[1],x_[0]);
  
  if (fabs(rho) >THRESHOLD)
    rho_dot= (x_[0]*x_[2] + x_[1]*x_[3]) / rho;
  
  VectorXd hx = VectorXd(3);
  hx << rho, phi, rho_dot;

  VectorXd y = z - hx;  
  if(y(1) > PI)
    y(1) = y(1) -  2*PI;
  else if (y(1) < -1*PI)
    y(1) = y(1)+ 2*PI;
  
  Update_Helper(y);
}

void KalmanFilter::Update_Helper(const VectorXd &y){
  MatrixXd S = H_ * P_ * H_.transpose()  + R_;
  MatrixXd K_gain = P_ * H_.transpose() * S.inverse();
  MatrixXd I = MatrixXd::Identity(x_.size(), x_.size());
  //applying updates to estimate values
  x_ = x_ + K_gain * y; 
  cout << "K_gain :"<< K_gain<<endl;
  cout << "P_ before: "<<P_<<endl;
  P_ = (I - K_gain * H_) * P_;
  cout << "P_after: "<<P_<<endl;

}