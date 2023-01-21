#include "./eigen/Eigen/Dense"
#include <iostream>
#include "matvec.hpp"
//#include "derivative.hpp"

int main()
{
  Eigen::MatrixXd A(2,2);
  A << 1, 2,
       3, 4;
  Eigen::VectorXd b(2);
  b << 1, 2;
  Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(A);
  Eigen::VectorXd x = qr.solve(b);
  std::cout << "The solution is:\n" << x << std::endl;
}