#include "matvec.hpp"

class Derivative {
    public:
        Derivative(const Matrix<float>& img1, const Matrix<float>& img2 );
        [[nodiscard]] float& Ix(size_t i, size_t j) const;
        [[nodiscard]] float& Iy(size_t i, size_t j) const;
        [[nodiscard]] float& It(size_t i, size_t j) const;
        
    private:
        Matrix<float> img1;
        Matrix<float> img2;
        static constexpr float h = 0.25;
};

Derivative::Derivative(const Matrix<float>& img1, const Matrix<float>& img2 ) {
    this->img1 = img1;
    this->img2 = img2;
}


[[nodiscard]] float& Derivative::Ix(size_t i, size_t j) const {
    float Ix = (h * (img1(i, j+1) - img1(i, j) + img1(i+1, j+1) - img1(i+1, j) + img2(i, j+1) - img2(i, j) + img2(i+1, j+1) - img2(i+1, j)));
    return Ix;
}

[[nodiscard]] float& Derivative::Iy(size_t i, size_t j) const {
    float Iy = (h * (img1(i+1, j) - img1(i, j) + img1(i+1, j+1) - img1(i, j+1) + img2(i+1, j) - img2(i, j) + img2(i+1, j+1) - img2(i, j+1)));
    return Iy;
}

[[nodiscard]] float& Derivative::It(size_t i, size_t j) const {
    float It = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1) + img2(i+1, j) - img1(i+1, j) + img2(i+1, j+1) - img1(i+1, j+1)));
    return It;
}

