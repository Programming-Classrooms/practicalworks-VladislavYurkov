#include "Matrix.hpp"

void Matrix::mtrxMemAlloc(double** &pointer, size_t initRows, size_t initColumns)
{
    pointer = new double*[initRows];
    for (size_t i = 0; i < initRows; ++i) {
        pointer[i] = new double[initColumns];
    }
}

Matrix::Matrix(size_t initRows, size_t initColumns) :
rows(initRows),
columns(initColumns)
{
    mtrxMemAlloc(pMtrx, rows, columns);
}

Matrix::Matrix(const Matrix& rhs) :
rows(rhs.rows),
columns(rhs.columns)
{
    mtrxMemAlloc(pMtrx, rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j)
        {
            (*this)[i][j] = (rhs)[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& rhs)
{
    pMtrx = rhs.pMtrx;
    rhs.pMtrx = nullptr;
    rows = rhs.rows;
    rhs.rows = 0;
    columns = rhs.columns;
    rhs.columns = 0;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; ++i) {
        delete[] pMtrx[i];
    }
    delete[] pMtrx;
}

double* Matrix::operator[ ](size_t ind)
{
    return this->pMtrx[ind];
}

double* Matrix::operator[ ](size_t ind) const
{
    return this->pMtrx[ind];
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (pMtrx != nullptr) {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] pMtrx[i];
        }
        delete[] pMtrx;
    }
    pMtrx = nullptr;
    rows = rhs.rows;
    columns = rhs.columns;
    mtrxMemAlloc(pMtrx, rows, columns);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            (*this)[i][j] = (rhs)[i][j];
        }
        
    }
    return(*this);
}

Matrix& Matrix::operator=(Matrix&& rhs)
{
    if (pMtrx != nullptr) {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] pMtrx[i];
        }
        delete[] pMtrx;
    }
    pMtrx = rhs.pMtrx;
    rhs.pMtrx = nullptr;
    rows = rhs.rows;
    rhs.rows = 0;
    columns = rhs.columns;
    rhs.columns = 0;
    return *this;
}

Matrix& Matrix::operator*=(double rhs)
{
    *this = *this * rhs;
    return *this;
}

Matrix& Matrix::operator/=(double rhs)
{
    *this = *this / rhs;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    *this = *this + rhs;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    *this = *this - rhs;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    *this = *this * rhs;
    return *this;
}

Matrix Matrix::operator*(double rhs) const
{
    Matrix mtrxCpy;
    mtrxCpy = *this;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            (mtrxCpy)[i][j] *= rhs;
        }
    }
    return mtrxCpy;
    
}

Matrix operator*(double lhs, const Matrix& rhs)
{
    return rhs * lhs;
}

Matrix Matrix::operator/(double rhs) const
{
    if (rhs == 0.0) {
        throw std::logic_error("Division by zero!");
    }
    return (*this * (1/rhs));
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
    if (rows != rhs.rows) {
        throw std::logic_error("Matrix have different numbers of rows!");
    }
    if (columns != rhs.columns) {
        throw std::logic_error("Matrix have different numbers of columns!");
    }
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            (result)[i][j] = (*this)[i][j] + (rhs)[i][j];
        }
        
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const
{
    return *this + (rhs * -1.0);
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    if (rhs.rows != columns) {
        throw std::logic_error("Matrix can't be multiplied!");
    }
    Matrix result(rows, rhs.columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rhs.columns; ++j)
        {
            for (size_t k = 0; k < columns; ++k)
            {
                (result)[i][j] += (*this)[i][k] * (rhs)[k][j];
            }
            
        }
        
    }
    return result;
}

bool Matrix::operator==(const Matrix& rhs) const
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            if (*this[i][j] != rhs[i][j])
            {
                return false;
            }
            
        }
        
    }
    return true;
    
}

bool Matrix::operator!=(const Matrix& rhs) const
{
    return !(*this == rhs);
}

std::istream& operator>>(std::istream& in, Matrix& rhs)
{
    std::cout << "Input matrix(" << rhs.rows << " * " << rhs.columns << ")\n";
    for (size_t i = 0; i < rhs.rows; ++i)
    {
        for (size_t j = 0; j < rhs.columns; ++j)
        {
            in >> rhs[i][j];
        }
        
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
    size_t maxWidth = 0;
    for (size_t i = 0; i < rhs.rows; ++i) {
        for (size_t j = 0; j < rhs.columns; ++j) {
            std::string element = std::to_string(rhs[i][j]);
            size_t elementWidth = element.length();
            if (elementWidth > maxWidth) {
                maxWidth = elementWidth;
            }
        }
    }
    for (size_t i = 0; i < rhs.rows; ++i)
    {
        for (size_t j = 0; j < rhs.columns; ++j)
        {
            out << std::setw(maxWidth) << rhs[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}
