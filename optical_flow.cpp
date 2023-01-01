#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
#include "derivative.hpp"
//template< typename ComponentType >

int main() {
	auto loaded_matrix = load_image<float>("../../../test_images/rects_640x480_0.bmp");
	auto loaded_matrix2 = load_image<float>("../../../test_images/rects_640x480_1.bmp");
	save_image(loaded_matrix, "loadMAtrix");
	// Example for using Derivative class:
	Matrix<float> Ix{loaded_matrix.rows(), loaded_matrix.cols()};
	Matrix<float> Iy{ loaded_matrix.rows(), loaded_matrix.cols() };
	Matrix<float> It{ loaded_matrix.rows(), loaded_matrix.cols() };

	Derivative d1(loaded_matrix, loaded_matrix2);
	for(size_t i = 0; i < loaded_matrix.rows(); ++i) {
		for(size_t j = 0; j < loaded_matrix2.rows(); ++j) {
			Ix(i,j) = d1.getIx(i,j);
			Iy(i, j) = d1.getIy(i, j);
			It(i, j) = d1.getIt(i, j);
		}
	}
	//std::cout<<"Ix: " << Ix.tensor() << std::endl; 


	save_image(Ix,"Ix.bmp");
	save_image(Iy, "Iy.bmp");
	save_image(It, "It.bmp");
	//return 0;
}