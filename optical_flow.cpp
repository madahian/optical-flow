#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
#include "derivative.hpp"
//template< typename ComponentType >

int main() {
	auto loaded_matrix = load_image<float>("../test_images/rect_right_100x100_0.bmp");
	auto loaded_matrix2 = load_image<float>("../test_images/rect_right_100x100_1.bmp");
	
	/* Example for using Derivative class:
	Matrix<float> Ix{loaded_matrix.rows(), loaded_matrix.cols()};
	Derivative d1(loaded_matrix, loaded_matrix2);
	for(size_t i = 0; i < loaded_matrix.rows(); ++i) {
		for(size_t j = 0; j < loaded_matrix.rows(); ++j) {
			Ix(i,j) = d1.getIx(i,j);
		}
	}
	std::cout<<"Ix: " << Ix.tensor() << std::endl; 
	*/

	save_image(loaded_matrix,"new_image2.bmp");
	//return 0;
}