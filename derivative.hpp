#include "matvec.hpp"

class Derivative {
    public:
        Derivative(const Matrix<float>& img1, const Matrix<float>& img2 );
        float getIx(size_t i, size_t j) const;
        float getIy(size_t i, size_t j) const;
        float getIt(size_t i, size_t j) const;
        Matrix<float> claculate_A(const double alpha) const;
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
    if(i+1 >= img1.rows()){
        Ix = (h * (img1(i, j+1) - img1(i, j) + img2(i, j+1) - img2(i, j)));
    }
    else if(j+1 >= img1.cols()) {
        Ix = (h * (0 - img1(i, j) - img1(i+1, j) - img2(i, j) - img2(i+1, j)));
    }
    else if(i+1 >= img1.rows() && j+1 >= img1.cols()) {
        Ix = (h * (0 - img1(i, j) - img2(i, j)));
    }
    else {
        Ix = (h * (img1(i, j+1) - img1(i, j) + img1(i+1, j+1) - img1(i+1, j) + img2(i, j+1) - img2(i, j) + img2(i+1, j+1) - img2(i+1, j)));
    }
    return Ix;
}

float Derivative::getIy(size_t i, size_t j) const {
    float Iy = 0;
    if(i+1 >= img1.rows()){
        Iy = (h * (0 - img1(i, j) - img1(i, j+1) - img2(i, j) - img2(i, j+1)));
    }
    else if(j+1 >= img1.cols()) {
        Iy = (h * (img1(i+1, j) - img1(i, j) + img2(i+1, j) - img2(i, j)));
    }
    else if(i+1 >= img1.rows() && j+1 >= img1.cols()) {
        Iy = (h * (0 - img1(i, j) - img2(i, j)));
    }else {
        Iy = (h * (img1(i+1, j) - img1(i, j) + img1(i+1, j+1) - img1(i, j+1) + img2(i+1, j) - img2(i, j) + img2(i+1, j+1) - img2(i, j+1)));
    }
    return Iy;
}

float Derivative::getIt(size_t i, size_t j) const {
    float It = 0;
    if(i+1 >= img1.rows()){
        It = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1)));
    }
    else if(j+1 >= img1.cols()) {
        It = (h * (img2(i, j) - img1(i, j) + img2(i+1, j) - img1(i+1, j)));
    }
    else if(i+1 >= img1.rows() && j+1 >= img1.cols()) {
        It = (h * (img2(i, j) - img1(i, j)));
    }else {
        It = (h * (img2(i, j) - img1(i, j) + img2(i, j+1) - img1(i, j+1) + img2(i+1, j) - img1(i+1, j) + img2(i+1, j+1) - img1(i+1, j+1)));
    }
    return It;
}


std::tuple<size_t, size_t> calculate_index(size_t row, size_t col,size_t rows,size_t cols)
{
       if(col+1 == cols)
       {
           if(row+1==rows)
           {
           row = 0;
           }
           else
           {
            row++;
           }
            col = 0;
       }
       else
       {
        col++;
       }
       return std::tuple<size_t, size_t>{row, col};
}

Matrix<float> Derivative::claculate_A(const double alpha) const
{
    size_t row = 0;
    size_t col = 0;
    size_t matrix_size = img1.rows()*img1.cols();
    Matrix<float> A(2*matrix_size, 2*matrix_size, 0);
    for(size_t i = 0; i < 2*matrix_size; ++i) {

       //A(i,0) = row;
       //A(i,1) = col;
       std::tie (row, col) = calculate_index(row, col, img1.rows(), img1.cols());
       if(i<matrix_size)
       {
        auto Ix = this->getIx(row,col);
        auto Iy = this->getIy(row,col);
        A(i,i) = Ix*Ix + 4* alpha;
        A(i,i+matrix_size) = Ix * Iy;
       }
       else
       {
        auto Ix = this->getIx(row,col);
        auto Iy = this->getIy(row,col);
        A(i,i) = Iy*Iy + 4* alpha;
        A(i,i-matrix_size) = Ix * Iy;
       }
        if(i+1<2*matrix_size)
       {
        A(i, i+1) = -1* alpha;
       }
        if(i-1>=0 && i>0)
       {
        A(i, i-1) = -1* alpha;
       }
	}
	return A;
}



