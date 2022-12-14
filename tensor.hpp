
#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <fstream>



template< class T >
concept Arithmetic = std::is_arithmetic_v< T >;

template< Arithmetic ComponentType >
class Tensor
{
public:
// Constructs a tensor with rank = 0 and zero-initializes the element.
    Tensor();

// Constructs a tensor with arbitrary shape and zero-initializes all elements.
    Tensor(const std::vector< size_t >& shape);

// Constructs a tensor with arbitrary shape and fills it with the specified value.
    explicit Tensor(const std::vector< size_t >& shape, const ComponentType& fillValue);

// Copy-constructor.
    Tensor(const Tensor< ComponentType >& other);
// Move-constructor.
    Tensor(Tensor< ComponentType >&& other) noexcept;
// Copy-assignment
    Tensor& operator=(const Tensor< ComponentType >& other);
// Move-assignment
    Tensor&
    operator=(Tensor< ComponentType >&& other) noexcept;
// Destructor
    ~Tensor(){
        if (data != nullptr)
        {
            delete [] data;
        };
    }
    // Returns the rank of the tensor.
    [[nodiscard]] size_t rank() const;


    [[nodiscard]] size_t numElements() const;

        // Returns the shape of the tensor.
    [[nodiscard]] std::vector< size_t > shape() const;


    [[nodiscard]] const ComponentType& get_value_at_index(size_t& index) const;

    // Element access function
    const ComponentType&
    operator()(const std::vector< size_t >& idx) const;
    // Element mutation function
    ComponentType&
    operator()(const std::vector< size_t >& idx);


private:
    // TODO: Probably you need some members here...
    ComponentType* data;
    std::vector< size_t > tensor_shape;
    size_t tensor_size;


};

// Constructs a tensor with rank = 0 and zero-initializes the element.
template< Arithmetic ComponentType >
Tensor <ComponentType>::Tensor()
{
    data = new ComponentType[0];
    data[0] = 0;
    tensor_shape = {};
    tensor_size = 0;
}

// Constructs a tensor with arbitrary shape and zero-initializes all elements.
template< Arithmetic ComponentType >
Tensor <ComponentType>::Tensor(const std::vector< size_t >& shape)
    {
        tensor_shape = shape;
        tensor_size = 1;
        for (size_t i=0; i<shape.size(); i++)
            {
                tensor_size = tensor_size * shape[i];
            }
        data=new ComponentType[tensor_size];
        for (size_t i = 0; i < tensor_size; ++i)
            {
                data[i]=0;
            }
    }


// Constructs a tensor with arbitrary shape and fills it with the specified value.
template< Arithmetic ComponentType >
Tensor <ComponentType>::Tensor(const std::vector< size_t >& shape, const ComponentType& fillValue)
    {
        tensor_shape = shape;
        tensor_size = 1;
        for (size_t i=0; i<shape.size(); i++)
            {
                tensor_size = tensor_size * shape[i];
            }
        data=new ComponentType[tensor_size];
        for (size_t i = 0; i < tensor_size; ++i)
            {
                data[i]=fillValue;
            }
    };

//copy constructor
template< Arithmetic ComponentType >
Tensor <ComponentType>::Tensor (const Tensor< ComponentType >& other)
{
        tensor_shape = other.tensor_shape;
        tensor_size = other.tensor_size;
        data=new ComponentType[tensor_size];
        for (size_t i = 0; i < tensor_size; ++i)
            {
                data[i]=other.data[i];
            }

}
// Move-constructor
template< Arithmetic ComponentType >
Tensor <ComponentType>::Tensor(Tensor< ComponentType >&& other) noexcept
{
    //std::cout<<"move constructor -------------"<<std::endl;
    tensor_shape = other.tensor_shape;
    other.tensor_shape = {};

    tensor_size = other.tensor_size;
    other.tensor_size = 0;
    data=new ComponentType[tensor_size];
    for (size_t i = 1; i < tensor_size; ++i)
        {
            data[i]=std::move(other.data[i]);
        }
    data[0] = other.data[0];
    other.data[0] = 0;
}


//copy assignment
// return   /  name of the class to address / operator  / input
template< Arithmetic ComponentType >
Tensor<ComponentType>& Tensor<ComponentType>::operator=(const Tensor< ComponentType >& other)
{
    //std::cout<<"copy assignmet -------------"<<std::endl;
    tensor_shape = other.tensor_shape;
    tensor_size = other.tensor_size;
    delete [] data;
    data=new ComponentType[tensor_size];
    for (size_t i = 0; i < tensor_size; i++)
        {
            data[i]=other.data[i];
        }
        return *this;
}

// Move-assignment
template< Arithmetic ComponentType >
Tensor<ComponentType>& Tensor<ComponentType>::operator=(Tensor< ComponentType >&& other) noexcept
{
    //std::cout<<"move assignmet -------------"<<std::endl;
    tensor_shape = other.tensor_shape;
    other.tensor_shape = {};

    tensor_size = other.tensor_size;
    other.tensor_size = 0;
    delete [] data;
    data=new ComponentType[tensor_size];
    for (size_t i = 1; i < tensor_size; ++i)
        {
            data[i]=std::move(other.data[i]);
        }
    data[0] = other.data[0];
    other.data[0] = 0;
    return *this;
}

// Tensor numElements method
template< Arithmetic ComponentType >
size_t Tensor<ComponentType>::numElements() const
{
    return tensor_size;
}
// Tensor () operator - Element access function
template< Arithmetic ComponentType >
const ComponentType& Tensor<ComponentType>::operator()(const std::vector< size_t >& idx) const
{
    assert("The Tensor size are not match" && tensor_shape.size()==idx.size());

    if (idx.size() > 0)
    {
        size_t index_location = 0;
        size_t index_multi = 1;
        for (size_t i=idx.size(); i>0; i--)
        {
            assert("The input argument is out of range" && idx[i-1]<tensor_shape[i-1]);
            if (i == idx.size())
            {
                index_location = idx[i-1];
            }
            else
            {
                index_multi = 1;
                for (size_t j=i;j<idx.size();j++)
                {
                    index_multi = index_multi * tensor_shape[j];
                }

                index_location = index_location + idx[i-1] * index_multi;
            }
        }
        return data[index_location];
    }
    else return data[0];


}
// Tensor rank method
template< Arithmetic ComponentType >
size_t Tensor<ComponentType>::rank() const
{

    return tensor_shape.size();

}


// == operator
template< Arithmetic ComponentType >
bool operator==(const Tensor< ComponentType >& a, const Tensor< ComponentType >& b)
{
     std::vector< size_t > empty_shape = {};
    if (a.shape() == b.shape())
    {
        if (a.shape() == empty_shape)
        {
            //if (a.get_value_at_index(0) == b.get_value_at_index(0))
            return  true;
            //else
            //return false;

        }
        else
        {
            for (size_t i = 0; i < a.numElements(); ++i)
                {
                    if (a.get_value_at_index(i) != b.get_value_at_index(i))
                        return false;
                }
                return true;
        }
    }

    else return false;
}
// Tensor shape method
template< Arithmetic ComponentType >
std::vector< size_t > Tensor<ComponentType>::shape() const
{
    return tensor_shape;
}

// tensor value at index method
template< Arithmetic ComponentType >
const ComponentType& Tensor<ComponentType>::get_value_at_index(size_t& index) const
{
    return data[index];
}



// Tensor () operator - Element mutation function
template< Arithmetic ComponentType >
ComponentType& Tensor<ComponentType>::operator()(const std::vector< size_t >& idx)
{
    assert("The Tensor size are not match" && tensor_shape.size()==idx.size());
    if (idx.size() > 0)
    {
        size_t index_location = 0;
        size_t index_multi = 1;
        for (size_t i=idx.size(); i>0; i--)
        {
            assert("The input argument is out of range" && idx[i-1]<tensor_shape[i-1]);
            if (i == idx.size())
            {
                index_location = idx[i-1];
            }
            else
            {
                index_multi = 1;
                for (size_t j=i;j<idx.size();j++)
                {
                    index_multi = index_multi * tensor_shape[j];
                }

                index_location = index_location + idx[i-1] * index_multi;
            }
        }
        return data[index_location];
    }
    return data[0];
}

// Pretty-prints the tensor to stdout.
// This is not necessary (and not covered by the tests) but nice to have, also for debugging (and for exercise of course...).
template< Arithmetic ComponentType >
std::ostream&
operator<<(std::ostream& out, const Tensor< ComponentType >& tensor)
{
    if (tensor.rank() == 1)
    {
        for (size_t i = 0; i < tensor.numElements(); ++i)
            out << tensor.get_value_at_index(i) << " ";
        return out;
    }
    else if (tensor.rank() == 2)
    {
        size_t index = 0;
        for (size_t dim_index = 0; dim_index < tensor.rank(); ++dim_index)
        {
            for (size_t column_index = 0; column_index < tensor.shape()[0]; ++column_index)
            {
                out << tensor.get_value_at_index(index) << " ";
                index++;
            }
            out <<std::endl;
        }
        return out;
    }
    else
    {
        out<<"Rank of the tensor is: "<< tensor.rank()<<std::endl;
        out<<"Tesor elements are:"<<std::endl;
        for (size_t i = 0; i < tensor.numElements(); ++i)
            out << tensor.get_value_at_index(i) << " ";
        return out;
    }

}

// Reads a tensor from file.
template< Arithmetic ComponentType >
Tensor< ComponentType > readTensorFromFile(const std::string& filename)
{
    // TODO: Implement this function to read in tensors from file.
    //       The format is defined in the instructions.
    std::string myText;
    std::ifstream MyReadFile(filename);
    size_t line_number = 0;

    size_t tensor_rank = 0;
    std::vector< size_t > tensor_shape;
    while (getline (MyReadFile, myText)) {
      if (line_number == 0)
         {
            line_number++;
            std::vector< size_t > tensor_shape_t(2, 0);
            tensor_shape = tensor_shape_t;
         }
      else
        {
            if (line_number<= tensor_rank)
            {
                tensor_shape[line_number-1] = 3;
                line_number++;
            }
            else if(line_number == tensor_rank +1)
            {
                Tensor<float> tensor(tensor_shape);
            }

        }

    }
    // Close the file
    MyReadFile.close();

}

// Writes a tensor to file.
template< Arithmetic ComponentType >
void writeTensorToFile(const Tensor< ComponentType >& tensor, const std::string& filename)
{
    // TODO: Implement this function to write tensors to file.
    //       The format is defined in the instructions.

}


