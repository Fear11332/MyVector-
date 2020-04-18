
#include <iostream>
#include <cstring>
#include <cstddef>
#include "MyVector.h"

MyVector::MyVector(size_t size, ResizeStrategy flag, float coefficient)
{
    this->_size = size;
    this->_flag = flag;
    this->_coefficient = coefficient;

    if (this->_flag == ResizeStrategy::Multiplicative) {
        if (this->_size == 0) {
            this->_capacity = 2;
        }

        else {
            this->_capacity = this->_size * this->_coefficient;
        }

        this->_data = new ValueType[_capacity];
    }

    else {
        this->_capacity = this->_size + 2;
        this->_data = new ValueType[_capacity];
    }
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy flag, float coefficient)
{
    this->_size = size;
    this->_flag = flag;
    this->_coefficient = coefficient;

    if (this->_flag == ResizeStrategy::Multiplicative) {
        if (this->_size == 0) {
            this->_capacity = 2;
        }

        else {
            this->_capacity = this->_size * this->_coefficient;
        }

        this->_data = new ValueType[_capacity];

        for (int i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }

    else {
        this->_capacity = this->_size + 2;
        this->_data = new ValueType[_capacity];

        for (int i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }
}

MyVector::~MyVector()
{
    delete[] _data;
}

MyVector::MyVector(const MyVector& copy)
{
    this->_capacity = copy._capacity;
    this->_size = copy._size;
    this->_coefficient = copy._coefficient;
    this->_flag = copy._flag;
    this->_data = new ValueType[copy._size];

    for (int i = 0; i < copy._size; i++) {
        this->_data[i] = copy._data[i];
    }
}

MyVector& MyVector::operator=(const MyVector& copy)
{
    this->_size = copy._size;
    this->_capacity = copy._capacity;
    this->_data = new ValueType[copy._size];

    for (int i = 0; i < _size; i++) {
        _data[i] = copy._data[i];
    }

    return *this;
}

ValueType& MyVector::operator[](const size_t i) const
{
    return _data[i - 1];
}

void MyVector::pushBack(const ValueType& value)
{
    reserve(_size + 1);
    _data[_size] = value;
    _size += 1;
}

void MyVector::insert(const size_t i, const ValueType& value)
{
    if (_capacity == _size) {

        _capacity *= this->_coefficient;
        _size += 1;
        ValueType* _data1 = new ValueType[_capacity];

        for (int k = 0; k < _size - 1; k++) {
            _data1[k] = _data[k];
        }

        for (int j = _size - 1; j >= i - 1; j--) {
            _data1[j + 1] = _data1[j];
        }
        _data1[i - 1] = value;

        for (int t = 0; t < _size - 1; t++) {
            _data[t] = _data1[t];
        }

        delete[] _data1;
    }
    else if (_capacity > _size) {

        _size += 1;

        for (int j = _size - 1; j >= i - 1; j--) {
            _data[j + 1] = _data[j];
        }
        _data[i - 1] = value;
    }
}

void MyVector::insert(const size_t i, const MyVector& value)
{
    size_t _size3 = _size + value._size;
    ValueType buffer[_size3];
    const size_t _sizee3 = _size + value._size;
    size_t j = i - 1;

    for (int i = 0; i < _size3; i++) {
        buffer[i] = 0;
    }

    int t = 0;

    while (t != value._size) {
        buffer[j] = value._data[t];
        t++;
        j++;
    }
    t = 0;
    j = i - 1;

    for (int k = i + value._size - 1; k < _size3; k++) {
        buffer[k] = _data[j];
        j++;
    }

    for (int n = 0; n < i - 1; n++) {
        buffer[n] = _data[n];
    }

    resize(_size + value._size);

    _capacity += value._capacity;

    for (int i = 0; i < _size; i++) {

        _data[i] = buffer[i];
    }
}

void MyVector::popBack()
{
    _size -= 1;
}

void MyVector::Show()
{
    for (int i = 0; i < _size; ++i) {
        std::cout << _data[i] << " ";
    }
}

void MyVector::erase(const size_t i)
{
    ValueType _data1[_capacity];

    for (int t = 0; t < _size; t++) {
        _data1[t] = _data[t];
    }

    for (int j = i - 1; j < _size - 1; j++) {
        _data1[j] = _data1[j + 1];
    }

    for (int i = 0; i < _size; i++) {
        _data[i] = _data1[i];
    }

    _size -= 1;
}

void MyVector::erase(const size_t i, const size_t len)
{
    size_t newsize = _size - len;

    ValueType buffer[newsize];
    size_t k = 0;

    for (int j = i - 1; j < _size; j++) {
        if (k != len) {
            _data[j] = int(&_data[j]);
            k++;
        }
    }
    k = 0;

    for (int i = 0; i < _size; i++) {

        if (int(&_data[i]) != _data[i]) {
            buffer[k] = _data[i];
            k++;
        }
    }

    _size = newsize;

    for (int i = 0; i < newsize; i++) {
        _data[i] = buffer[i];
    }
}

long long int MyVector::find(const ValueType& value, bool isBegin) const
{

    long long int t = -1;

    if (isBegin) {
        int counter = 0;

        for (int i = 0; i < _size; i++) {
            if (_data[i] == value) {
                counter += 1;

                if (counter == 1) {
                    t = i + 1;
                }
            }
        }
    }

    else {
        int counter = 0;

        for (int i = _size - 1; i >= 0; i--) {
            if (_data[i] == value && counter != 1) {
                counter += 1;

                if (counter == 1) {
                    t = (_size - (i + 1))+1;
                }
            }
        }
    }

    return t;
}

void MyVector::clear()
{
    for (int i = 0; i < _size; i++) {
        _data[i] = 0;
    }

    _size = 0;
}

void MyVector::resize(const size_t size, const ValueType value)
{
    if (size > _size) {
        for (int i = _size; i < size; ++i)
            pushBack(value);
    }
    else {
        _size = size;

        if (_flag == ResizeStrategy::Multiplicative)
            _capacity = _size * _coefficient;
        else {
            _capacity = _size + 2;
        }
    }
}

void MyVector::reserve(const size_t capacity)
{
    if (capacity <= _capacity)
        return;

    if (_flag == ResizeStrategy::Additive) {
        _capacity = (_capacity == 0) ? 1 : _capacity;
        while (_capacity < capacity)
            _capacity <<= 1;

        if (_data == nullptr)
            _data = new ValueType[_capacity];
        else {
            ValueType* temp = this->_data;
            _data = new ValueType[_capacity];
            memcpy(this->_data, temp, _size * sizeof(ValueType));
            delete[] temp;
        }
    }
    else {
        _capacity = _capacity * _coefficient;

        if (_data == nullptr)
            _data = new ValueType[_capacity];
        else {
            ValueType* temp = this->_data;
            _data = new ValueType[_capacity];
            memcpy(this->_data, temp, _size * sizeof(ValueType));
            delete[] temp;
        }
    }
}
