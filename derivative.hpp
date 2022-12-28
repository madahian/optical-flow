#include "matvec.hpp"

class Derivative {
    public:
        Derivative(const Matrix<float>& img1, const Matrix<float>& img2 );
        void calculateDerivatives();
        Matrix<float>& getIx();
        Matrix<float>& getIy();
        Matrix<float>& getIt();   
    private:
        Matrix<float> img1;
        Matrix<float> img2;
        Matrix<float> Ix, Iy, It {img1.rows(),img1.cols()};
        static constexpr float h = 0.25;
};

Derivative::Derivative(const Matrix<float>& img1, const Matrix<float>& img2 ) {
    this->img1 = img1;
    this->img2 = img2;
}
Matrix<float>& Derivative::getIx() {
    return Ix;
}
Matrix<float>& Derivative::getIy() {
    return Iy;
}
Matrix<float>& Derivative::getIt() {
    return It;
}

void Derivative::calculateDerivatives() {
    for(size_t i = 0; i < img1.rows(); ++i) {
        for(size_t j = 0; j < img1.cols(); ++j) {
            if(i+1 >= img1.rows() || j+1 >= img1.cols()) {
                img1(i+1, j+1) = 0;
                img1(i+1, j) = 0;
                img1(i, j+1) = 0;
                img2(i+1, j+1) = 0;
                img2(i+1, j) = 0;
                img2(i, j+1) = 0;
            }
            Ix(i,j) = (h * (img1(i, j+1) - img1(i, j) + img1(i+1, j+1) - img1(i+1, j) + img2(i, j+1) - img2(i, j) + img2(i+1, j+1) - img2(i+1, j)));
            Iy(i,j) = (h * (img1(i+1, j) - img1(i, j) + img1(i+1, j+1) - img1(i, j+1) + img2(i+1, j) - img2(i, j) + img2(i+1, j+1) - img2(i, j+1)));
            It(i,j) = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1) + img2(i+1, j) - img1(i+1, j) + img2(i+1, j+1) - img1(i+1, j+1)));
        }
    }
}

