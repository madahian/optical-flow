#include "matvec.hpp"
#include "tensor.hpp"
#include <iostream>
#define cimg_display 0
#include "CImg/CImg.h"
#include <vector>
std::vector<std::vector<int>> vect;
using namespace cimg_library;

template< typename ComponentType >
Matrix< ComponentType > load_image(const std::string& filename)
{

	CImg<ComponentType>image(filename.c_str());
	size_t image_w = image.width();
	size_t image_h = image.height();
	//std::cout <<"load image" << image_w << "*" << image_h;
	Matrix< ComponentType > loaded_matrix(image_h, image_w, 0);
	for (size_t i = 0;i < image_w;i++) {
		for (size_t j = 0;j < image_h;j++) {
			loaded_matrix(j, i) = image(i, j)/255;
		}
	}
	return loaded_matrix;

};

template< typename ComponentType >
void save_image(Matrix<ComponentType>& input_matrix ,std::string filename)
{
	size_t image_h = input_matrix.rows();
	size_t image_w = input_matrix.cols();

	CImg<unsigned char>image(image_w, image_h,1,1,255);
	for (size_t i = 0;i < image_w; i++) {
		for (size_t j = 0;j < image_h; j++) {

			image(i, j) = input_matrix(j,i)*255;

		}
	}
	//std::cout <<"save Image" << image_h << "*" << image_w;
	CImgDisplay main_disp(image, "Click a point");
	image.save(filename.c_str());
	while (!main_disp.is_closed()) {
		main_disp.wait();

	}

};
