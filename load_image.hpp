#include "matvec.hpp"
#include "tensor.hpp"
#include <iostream>
#include "./CImg/CImg.h"
using namespace cimg_library;
template< typename ComponentType >


Matrix< ComponentType > load_image(const std::string& filename)
{
	
	CImg<ComponentType>image(filename.c_str());
	size_t image_w = image.width();
	size_t image_h = image.height();
	Matrix< ComponentType > loaded_matrix(image_w,image_h, 0);
	for (size_t i = 0;i < image_w;i++) {
		for (size_t j = 0;j < image_h;j++) {
			loaded_matrix(i,j) = image(i, j);
		}
	}
	std::cout << image_w << std::endl;
	
	return loaded_matrix;

}