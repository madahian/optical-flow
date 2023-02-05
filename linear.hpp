#include "./eigen/Eigen/Dense"
#include <iostream>
#include "matvec.hpp"

//test linear equation
template<typename ComponentType>
Eigen::VectorXd solveA(Matrix<ComponentType>& A, Vector<ComponentType>& b) {
    Eigen::MatrixXd Aa(A.rows(), A.cols());
    Eigen::VectorXd Bb(b.size());
    for (int i = 0;i < A.rows();i++) {
        for (int j = 0;j < A.cols();j++) {
            Aa(i, j) = A(i, j);
        }
        Bb(i) = b(i);
    }
    //std::cout << "The Aa is:\n" << Aa << std::endl;
   // std::cout << "The Bb is:\n" << Bb << std::endl;

    Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(Aa);
    Eigen::VectorXd x = qr.solve(Bb);
   // std::cout << "The solution is:\n" << x << std::endl;
    return x;
}

Matrix<float>  getU(Eigen::VectorXd x, size_t rows, size_t cols) {
    Matrix<float> u(rows, cols, 0);
    size_t index = 0;
    for (size_t i = 0;i < rows;i++) {
        for (size_t j = 0;j < cols;j++) {
            u(i, j) = x(index);
            index++;

        }
    }
    return u;
}

Matrix<float> getV(Eigen::VectorXd x, size_t rows, size_t cols) {
    Matrix<float> v(rows, cols, 0);
    size_t index = rows*cols;
    for (size_t i = 0;i < rows;i++) {
        for (size_t j = 0;j < cols;j++) {
            v(i, j) = x(index);
            index++;

        }
    }
    return v;
}