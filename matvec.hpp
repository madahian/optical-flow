#pragma once

#include "tensor.hpp"

template< typename ComponentType >
class Vector
{
public:
    // Default-constructor.
    Vector() = default;

    // Constructor for vector of certain size.
    explicit Vector(size_t size)
    {
        Tensor< ComponentType > tensor_temp({size});
        tensor_ = std::move(tensor_temp);
    }

    // Constructor for vector of certain size with constant fill-value.
    Vector(size_t size, const ComponentType& fillValue)
    {
       Tensor< ComponentType > tensor_temp({size}, fillValue);
       tensor_ = std::move(tensor_temp);
    }

    // Constructing vector from file.
    Vector(const std::string& filename)
    {
        auto tensor_temp = readTensorFromFile< ComponentType >(filename);
        tensor_ = std::move(tensor_temp);
    }

    // Number of elements in this vector.
    [[nodiscard]] size_t size() const
    {
        return tensor_.numElements();
    }

    // Element access function
    const ComponentType&
    operator()(size_t idx) const
    {
        return tensor_({idx});
    }

    // Element mutation function
    ComponentType&
    operator()(size_t idx)
    {
        return tensor_({idx});
    }

    // Reference to internal tensor.
    Tensor< ComponentType >& tensor()
    {
        return tensor_;
    }

private:
    Tensor< ComponentType > tensor_;
};




template< typename ComponentType >
class Matrix
{
public:
    // Default-constructor.
    Matrix() = default;

    // Constructor for matrix of certain size.
    explicit Matrix(size_t rows, size_t cols)
    {
        Tensor< ComponentType > tensor_temp({rows, cols});
        tensor_ = std::move(tensor_temp);
    }

    // Constructor for matrix of certain size with constant fill-value.
    Matrix(size_t rows, size_t cols, const ComponentType& fillValue)
    {
        Tensor< ComponentType > tensor_temp({rows, cols}, fillValue);
        tensor_ = std::move(tensor_temp);
    }

    // Constructing matrix from file.
    Matrix(const std::string& filename)
    {
        auto tensor_temp = readTensorFromFile< ComponentType >(filename);
        tensor_ = std::move(tensor_temp);
    }

    // Number of rows.
    [[nodiscard]] size_t rows() const
    {
        return tensor_.shape()[0];
    }

    // Number of columns.
    [[nodiscard]] size_t cols() const
    {
        return tensor_.shape()[1];
    }

    // Element access function
    const ComponentType& operator()(size_t row, size_t col) const
    {
        return tensor_({row, col});
    }

    // Element mutation function
    ComponentType& operator()(size_t row, size_t col)
    {
        return tensor_({row, col});
    }


    // Reference to internal tensor.
    Tensor< ComponentType >& tensor()
    {
        return tensor_;
    }

private:
    Tensor< ComponentType > tensor_;
};

// TODO: Implement all methods.


// Performs a matrix-vector multiplication.
template< typename ComponentType >
Vector< ComponentType > matvec(const Matrix< ComponentType >& mat, const Vector< ComponentType >& vec)
{
    ComponentType result = 0;
    assert("Matrix and vector size dose not match" && mat.cols()==vec.size());
    Vector< ComponentType > vector_result(mat.rows());
    for (size_t i = 0; i < mat.rows(); ++i)
    {
        for (size_t j = 0; j < mat.cols(); ++j)
        {
            result = mat(i,j) * vec(j) + result;
        }
        vector_result(i) = result;
        result = 0;
    }
    return vector_result;

}
