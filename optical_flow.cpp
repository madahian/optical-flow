#include <iostream>
#include "load_image.hpp"
#include "tensor.hpp"
#include "derivative.hpp"
#include "linear.hpp"

int main(int argc, char** argv) {
	if(argc < 5) {
		std::cerr << "Usage: " << argv[0] << " <img_in_0> <img_in_1> <img_out_u> <img_out_v>\n";
		return 1;
	}
	auto loaded_matrix = load_image<float>(argv[1]);
	auto loaded_matrix2 = load_image<float>(argv[2]);

	// Example for using Derivative class:
	Matrix<float> Ix{loaded_matrix.rows(), loaded_matrix.cols()};
	Matrix<float> Iy{ loaded_matrix.rows(), loaded_matrix.cols() };
	Matrix<float> It{ loaded_matrix.rows(), loaded_matrix.cols() };

	Derivative d1(loaded_matrix, loaded_matrix2);
	d1.claculate_A_b(0.5);
  auto A = d1.getA();
  auto b = d1.getb();
	for(size_t i = 0; i < loaded_matrix.rows(); ++i) {
		for(size_t j = 0; j < loaded_matrix2.rows(); ++j) {
			Ix(i,j) = d1.getIx(i,j);
			Iy(i, j) = d1.getIy(i, j);
			It(i, j) = d1.getIt(i, j);
		}
	}
    auto x = solveA(A, b);
    std::cout << "solution using function :\n" << x<<std::endl;
    auto u = getU(x, loaded_matrix.rows(), loaded_matrix.cols());
    std::cout << " U:\n " << u.tensor() << std::endl;
    auto v = getV(x, loaded_matrix.rows(), loaded_matrix.cols());
    std::cout << " V:\n " << v.tensor() << std::endl;

		save_image(u, argv[3]);
		save_image(v, argv[4]);

		return 0;
}