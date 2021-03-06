#include "kalman_filter.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::endl;
using std::cout;

/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

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
   * TODO: predict the state
   */
  x_ = F_ * x_;
  P_ = F_ * P_ * F_.transpose() + Q_;
}

void KalmanFilter::update(const VectorXd &y) {
  MatrixXd S = H_ * P_ * H_.transpose() + R_;
  MatrixXd K = P_ * H_.transpose() * S.inverse();

  //new estimate
  x_ = x_ + (K * y);
  MatrixXd I = MatrixXd::Identity(x_.size(), x_.size());
  P_ = (I - K * H_) * P_;
}

void KalmanFilter::Update(const VectorXd &z) {
  /**
   * TODO: update the state by using Kalman Filter equations
   */

  VectorXd y = z - H_ * x_;
  update(y);
}

void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
   * TODO: update the state by using Extended Kalman Filter equations
   */
  float temp = sqrt(pow(x_[0],2) + pow(x_[1],2));
  
  VectorXd mapped_x = VectorXd(3);
  mapped_x << temp, 
              atan2(x_[1], x_[0]), 
              (x_[0]*x_[2]+x_[1]*x_[3]) / temp;
  
  VectorXd y = z - mapped_x;
  
  // Normalizing Angles
  if (y[1] < -M_PI) y[1] += 2*M_PI; 
  if (y[1] > M_PI) y[1] -= 2*M_PI;
  
  update(y);
}
