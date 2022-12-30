#include "matvec.hpp"

class Derivative {
    public:
        Derivative(const Matrix<float>& img1, const Matrix<float>& img2 );
        float getIx(size_t i, size_t j) const;
        float getIy(size_t i, size_t j) const;
        float getIt(size_t i, size_t j) const; 
    private:
        Matrix<float> img1;
        Matrix<float> img2;
        static constexpr float h = 0.25;
};

Derivative::Derivative(const Matrix<float>& img1, const Matrix<float>& img2 ) {
    this->img1 = img1;
    this->img2 = img2;
}

float Derivative::getIx(size_t i, size_t j) const {
    float Ix = 0;
    if(i+1 >= img1.rows() || j+1 >= img1.cols()) {
        Ix = (h * (0 - img1(i, j) - img2(i, j)));
    }else {
        Ix = (h * (img1(i, j+1) - img1(i, j) + img1(i+1, j+1) - img1(i+1, j) + img2(i, j+1) - img2(i, j) + img2(i+1, j+1) - img2(i+1, j)));
    }
    return Ix;
}

float Derivative::getIy(size_t i, size_t j) const {
    float Iy = 0;
    if(i+1 >= img1.rows() || j+1 >= img1.cols()) {
        Iy = (h * (0 - img1(i, j) - img2(i, j)));
    }else {
        Iy = (h * (img1(i+1, j) - img1(i, j) + img1(i+1, j+1) - img1(i, j+1) + img2(i+1, j) - img2(i, j) + img2(i+1, j+1) - img2(i, j+1)));
    }
    return Iy;
}

float Derivative::getIt(size_t i, size_t j) const {
    float It = 0;
    if(i+1 >= img1.rows() || j+1 >= img1.cols()) {
        It = (h * (img2(i, j) - img1(i, j)));
    }else {
        It = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1) + img2(i+1, j) - img1(i+1, j) + img2(i+1, j+1) - img1(i+1, j+1)));
    }
    return It;
}