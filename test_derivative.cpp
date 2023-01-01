#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
#include "derivative.hpp"
//template< typename ComponentType >

int main() {
    // load data to a matrix object
    Matrix<float> img1(3, 3, 1);
    Matrix<float> img2(3, 3, 2);
    // create an object to calculate A and b
    Derivative d1(img1, img2);
    // call a method to calculate A and b
    auto A = d1.claculate_A(0.1);
    std::cout << "Matrix A:" << A.tensor() << std::endl;

    std::cout <<"Matrix 1" <<std::endl <<sample_Matrix("mat1").tensor() << std::endl;
    std::cout  <<"Matrix 2" << std::endl <<sample_Matrix("mat2").tensor() << std::endl;
    std::cout << "Manual Ix:" << std::endl << sample_Matrix("ix").tensor() << std::endl;
    std::cout << "Manual Iy:" << std::endl << sample_Matrix("iy").tensor() << std::endl;

    std::cout << "Manual It:" << std::endl << sample_Matrix("it").tensor() << std::endl;

    //test for Ix
    Matrix<float> mat1(3, 3, 0);
    Matrix<float>mat2(3, 3, 0);
    mat1(1, 1) = 1;
    mat2(0, 1) = 1;
    Matrix<float> Ix(mat1.rows(), mat1.cols());
    Derivative d2(mat1, mat2);
    for (size_t i = 0; i < mat1.rows(); ++i) {
        for (size_t j = 0; j < mat2.rows(); ++j) {
            Ix(i, j) = d2.getIx(i, j);
        }
    }
    std::cout << "IX derivitive: " << Ix.tensor() << std::endl;

    //test for Iy
    Matrix<float> Iy(mat1.rows(), mat1.cols());
    for (size_t i = 0; i < mat1.rows(); ++i) {
        for (size_t j = 0; j < mat2.rows(); ++j) {
            Iy(i, j) = d2.getIy(i, j);
        }
    }

    std::cout << "Iy derivitive: " << Iy.tensor() << std::endl;
    //test for It
    Matrix<float> It(mat1.rows(), mat1.cols());
    for (size_t i = 0; i < mat1.rows(); ++i) {
        for (size_t j = 0; j < mat2.rows(); ++j) {
            It(i, j) = d2.getIt(i, j);
        }
    }

    std::cout << "It derivitive: " << It.tensor() << std::endl;


}
