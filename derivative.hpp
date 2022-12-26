#include "matvec.hpp"

class Derivative {
    public:
        Derivative( Matrix<float>& img1, Matrix<float>& img2 );
        float& Ix(size_t i, size_t j);
        float& Iy(size_t i, size_t j);
        float& It(size_t i, size_t j);
        
    private:
        Matrix<float> img1;
        Matrix<float> img2;
        float h;
};

Derivative::Derivative( Matrix<float>& img1, Matrix<float>& img2 ) {
    this->img1 = img1;
    this->img2 = img2;
    this->h = 1/4;
}


float& Derivative::Ix(size_t i, size_t j) {
    float Ix = (h * (img1(i, j+1) - img1(i, j) + img1(i+1, j+1) - img1(i+1, j) + img2(i, j+1) - img2(i, j) + img2(i+1, j+1) - img2(i+1, j)));
    return Ix;
}

float& Derivative::Iy(size_t i, size_t j) {
    float Iy = (h * (img1(i+1, j) - img1(i, j) + img1(i+1, j+1) - img1(i, j+1) + img2(i+1, j) - img2(i, j) + img2(i+1, j+1) - img2(i, j+1)));
    return Iy;
}

float& Derivative::It(size_t i, size_t j) {
    float It = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1) + img2(i+1, j) - img1(i+1, j) + img2(i+1, j+1) - img1(i+1, j+1)));
    return It;
}

