#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
//template< typename ComponentType >

int main() {

	
	auto loaded_matrix = load_image<int>("C:/AdPT-optical_flow/test_images/rect_right_100x100_0.bmp");
	//std::cout << loaded_matrix.tensor() << std::endl;
	save_image(loaded_matrix,"new_image2.bmp");
	
	//return 0;
}