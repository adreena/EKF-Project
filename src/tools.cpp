#include <iostream>
#include "tools.h"
#define THRESHOLD 0.00001

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using namespace std;


Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd total = VectorXd(4);
  total << 0, 0, 0, 0 ;

  // ground truth is always greater or equal to estimates
  // becuase estimations are pushed back to the list once their process is finished
  // while ground truth is directly pushed to its list once sensor data is received
  for(int i = 0 ; i < estimations.size(); i++){
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    total += residual;
  }
  total /= estimations.size();
  total = total.array().sqrt();
  return total;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
  TODO:
    * Calculate a Jacobian here.
  */
  	MatrixXd Hj = MatrixXd::Zero(3,4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	float c1 = pow(px,2) + pow(py,2);
	float c2 = sqrt(c1);
	float c3 = (c1*c2);

	//check division by zero
	if(fabs(c1) > THRESHOLD){		
	//compute the Jacobian matrix
	  Hj <<(px/c2), (py/c2), 0, 0,
		  	-(py/c1), (px/c1), 0, 0,
		  	py*(vx*py - vy*px)/c3, px*(px*vy - py*vx)/c3, px/c2, py/c2;

	  return Hj;
	}

	std::cout << "CalculateJacobian () - Error - Underflow. Zero out the Jacobian" << std::endl;
	return Hj;
}
