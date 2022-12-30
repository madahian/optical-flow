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
    std::cout<<"Matrix A:" <<A.tensor();

}

