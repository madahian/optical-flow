#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
#include "derivative.hpp"
//template< typename ComponentType >
 //test A
template<typename ComponentType>
void getA(Matrix<ComponentType>& Ix, Matrix<ComponentType>& Iy, Matrix<ComponentType>& It) {
    float alpha = 0.5;
    Matrix<float> matA(18, 18, 0);
    Matrix<float> result(1, 18, 0);
    matA(0, 0) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(0, 1) = alpha * -1;
    matA(0, 3) = alpha * -1;
    matA(0, 9) = Ix(0, 0) * Iy(0, 0);
    matA(1, 1) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(1, 2) = alpha * -1;
    matA(1, 0) = alpha * -1;
    matA(1, 4) = alpha * -1;
    matA(1, 10) = Ix(0, 0) * Iy(0, 0);
    matA(2, 2) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(2, 1) = alpha * -1;
    matA(2, 5) = alpha * -1;
    matA(2, 11) = Ix(0, 0) * Iy(0, 0);
    matA(3, 3) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(3, 4) = alpha * -1;
    matA(3, 0) = alpha * -1;
    matA(3, 6) = alpha * -1;
    matA(3, 12) = Ix(0, 0) * Iy(0, 0);
    matA(4, 4) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(4, 5) = alpha * -1;
    matA(4, 1) = alpha * -1;
    matA(4, 7) = alpha * -1;
    matA(4, 3) = alpha * -1;
    matA(4, 13) = Ix(0, 0) * Iy(0, 0);
    matA(5, 5) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(5, 2) = alpha * -1;
    matA(5, 8) = alpha * -1;
    matA(5, 4) = alpha * -1;
    matA(5, 14) = Ix(0, 0) * Iy(0, 0);
    matA(6, 6) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(6, 7) = alpha * -1;
    matA(6, 3) = alpha * -1;
    matA(6, 15) = Ix(0, 0) * Iy(0, 0);
    matA(7, 7) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(7, 8) = alpha * -1;
    matA(7, 4) = alpha * -1;
    matA(7, 6) = alpha * -1;
    matA(7, 16) = Ix(0, 0) * Iy(0, 0);
    matA(8, 8) = pow(Ix(0, 0), 2) + 4 * alpha;
    matA(8, 5) = alpha * -1;
    matA(8, 7) = alpha * -1;
    matA(8, 17) = Ix(0, 0) * Iy(0, 0);
    matA(9, 9) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(9, 10) = alpha * -1;
    matA(9, 12) = alpha * -1;
    matA(9, 0) = Ix(0, 0) * Iy(0, 0);
    matA(10, 10) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(10, 11) = alpha * -1;
    matA(10, 13) = alpha * -1;
    matA(10, 9) = alpha * -1;
    matA(10, 1) = Ix(0, 0) * Iy(0, 0);
    matA(11, 11) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(11, 14) = alpha * -1;
    matA(11, 10) = alpha * -1;
    matA(11, 2) = Ix(0, 0) * Iy(0, 0);
    matA(12, 12) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(12, 13) = alpha * -1;
    matA(12, 9) = alpha * -1;
    matA(12, 15) = alpha * -1;
    matA(12, 3) = Ix(0, 0) * Iy(0, 0);
    matA(13, 13) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(13, 14) = alpha * -1;
    matA(13, 10) = alpha * -1;
    matA(13, 16) = alpha * -1;
    matA(13, 12) = alpha * -1;
    matA(13, 4) = Ix(0, 0) * Iy(0, 0);
    matA(14, 14) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(14, 11) = alpha * -1;
    matA(14, 17) = alpha * -1;
    matA(14, 13) = alpha * -1;
    matA(14, 5) = Ix(0, 0) * Iy(0, 0);
    matA(15, 15) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(15, 16) = alpha * -1;
    matA(15, 12) = alpha * -1;
    matA(15, 6) = Ix(0, 0) * Iy(0, 0);
    matA(16, 16) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(16, 17) = alpha * -1;
    matA(16, 13) = alpha * -1;
    matA(16, 15) = alpha * -1;
    matA(16, 7) = Ix(0, 0) * Iy(0, 0);
    matA(17, 17) = pow(Iy(0, 0), 2) + 4 * alpha;
    matA(17, 14) = alpha * -1;
    matA(17, 16) = alpha * -1;
    matA(17, 8) = Ix(0, 0) * Iy(0, 0);
    for (size_t i = 0;i < 18;i++) {
        for (size_t j = 0;j < 18;j++) {
            std::cout << matA(i, j) << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << "Get A Matrix" << std::endl;
};
int main() {
    // load data to a matrix object
    Matrix<float> img1(3, 3, 1);
    Matrix<float> img2(3, 3, 2);
    // create an object to calculate A and b
    Derivative d1(img1, img2);
    // call a method to calculate A and b
    auto A = d1.claculate_A(0.5);
    std::cout << "Matrix A:" << A.tensor() << std::endl;

    std::cout <<"Matrix 1" <<std::endl <<sample_Matrix("mat1").tensor() << std::endl;
    std::cout  <<"Matrix 2" << std::endl <<sample_Matrix("mat2").tensor() << std::endl;
    std::cout << "Manual Ix:" << std::endl << sample_Matrix("ix").tensor() << std::endl;
    std::cout << "Manual Iy:" << std::endl << sample_Matrix("iy").tensor() << std::endl;

    std::cout << "Manual It:" << std::endl << sample_Matrix("it").tensor() << std::endl;

    //test for Ix
    Matrix<float> mat1(3, 3, 1);
    Matrix<float>mat2(3, 3, 2);
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
   
//get a Template function 
getA(Ix, Iy, It);

}
