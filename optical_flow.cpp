#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
//template< typename ComponentType >

int main() {

	
	auto loaded_matrix = load_image<int>("C:/AdPT-optical_flow/img.bmp");
	std::cout << loaded_matrix.tensor() << std::endl;
	
	//return 0;
}