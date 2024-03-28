#include "Fraction.hpp"

template <typename type>
void swap(type& first, type& second)
{
    type buff = first;
    first = second;
    second = buff;
}

uint32_t findGCD(uint32_t first, uint32_t second)
{
    if (second > first) {
        swap(first, second);
    }
    while (first % second != 0) {
        first %= second;
        swap(first, second);
    }
    return second;
}

Fraction Fraction::reduce()
{
    if (numerator == 0) {
        denominator = 1;
        return *this;
    }
    uint32_t numAbs = abs(numerator);
    uint32_t GCD = findGCD(numAbs, denominator);
    numerator /= GCD;
    denominator /= GCD;
    return *this;
}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int32_t numerator, int32_t denominator)
{
    if (!denominator) {
        throw std::runtime_error("Division by zero!");
    }
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    this->reduce();
}

Fraction::Fraction(const Fraction& rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

Fraction::Fraction(Fraction&& rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;

    rhs.numerator = 0;
    rhs.denominator = 0;
}

Fraction::~Fraction()
{

}

Fraction& Fraction::operator=(int32_t rhs)
{
    this->numerator = rhs;
    this->denominator = 1;
    return *this;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;

    return *this;
}

Fraction& Fraction::operator=(Fraction&& rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;

    rhs.numerator = 0;
    rhs.denominator = 0;

    return *this;
}

Fraction Fraction::operator+(int32_t rhs)
{
    Fraction result(*this);
    result.numerator += rhs * denominator;
    return result;
}

Fraction Fraction::operator-(int32_t rhs)
{
    Fraction result(*this);
    result.numerator -= rhs * denominator;
    return result;
}

Fraction Fraction::operator*(int32_t rhs)
{
    Fraction result(*this);
    result.numerator *= rhs;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(int32_t rhs)
{
    Fraction result(*this);
    if (!rhs) {
        throw std::runtime_error("Division by zero!");
    }
    if (rhs < 0) {
        result.numerator *= -1;
        rhs *= -1;
    }
    result.denominator *= rhs;
    result.reduce();
    return result;
}

Fraction Fraction::operator+(const Fraction& rhs)
{
    Fraction result;
    result.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
    result.denominator = this->denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator-(const Fraction& rhs)
{
    Fraction result;
    result.numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
    result.denominator = this->denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator*(const Fraction& rhs)
{
    Fraction result;
    result.numerator = this->numerator * rhs.numerator;
    result.denominator = this->denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(const Fraction& rhs)
{
    if (!rhs.numerator) {
        throw std::runtime_error("Division by zero!");
    }
    Fraction result;
    result.numerator = this->numerator * rhs.denominator;
    result.denominator = this->denominator * rhs.numerator;
    result.reduce();
    return result;
}

Fraction operator+(int32_t lhs, const Fraction& rhs)
{
    Fraction result(lhs,1);
    result = result + rhs;
    return result;
}

Fraction operator-(int32_t lhs, const Fraction& rhs)
{
    Fraction result(lhs,1);
    result = result - rhs;
    return result;
}

Fraction operator*(int32_t lhs, const Fraction& rhs)
{
    Fraction result(lhs,1);
    result = result * rhs;
    return result;
}

Fraction operator/(int32_t lhs, const Fraction& rhs)
{
    Fraction result(lhs,1);
    result = result / rhs;
    return result;
}

Fraction& Fraction::operator+=(int32_t rhs)
{
    *this = *this + rhs;
    return *this;
}

Fraction& Fraction::operator-=(int32_t rhs)
{
    *this = *this - rhs;
    return *this;
}

Fraction& Fraction::operator*=(int32_t rhs)
{
    *this = *this * rhs;
    return *this;
}

Fraction& Fraction::operator/=(int32_t rhs)
{
    *this = *this / rhs;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
    *this = *this + rhs;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
    *this = *this - rhs;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
    *this = *this * rhs;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
    *this = *this / rhs;
    return *this;
}

bool Fraction::operator==(int32_t rhs)
{
    return numerator == rhs && denominator == 1;
}

bool Fraction::operator!=(int32_t rhs)
{
    return !(*this == rhs);
}

bool Fraction::operator<(int32_t rhs)
{
    return numerator < (rhs * denominator);
}

bool Fraction::operator>(int32_t rhs)
{
    return *this != rhs && !(*this < rhs);
}

bool Fraction::operator<=(int32_t rhs)
{
    return !(*this > rhs);
}

bool Fraction::operator>=(int32_t rhs)
{
    return !(*this < rhs);
}

bool Fraction::operator==(const Fraction& rhs)
{
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction& rhs)
{
    return !(*this == rhs);
}

bool Fraction::operator<(const Fraction& rhs)
{
    return (*this / rhs) < 1;
}

bool Fraction::operator>(const Fraction& rhs)
{
    return *this != rhs && !(*this < rhs);
}

bool Fraction::operator<=(const Fraction& rhs)
{
    return !(*this > rhs);
}

bool Fraction::operator>=(const Fraction& rhs)
{
    return !(*this < rhs);
}

Fraction& Fraction::operator++()
{
    *this += 1;
    return *this;
}

Fraction Fraction::operator++(int rhs)
{
    Fraction temp = *this;
    *this += 1;
    return temp;
}

Fraction& Fraction::operator--()
{
    *this -= 1;
    return *this;
}

Fraction Fraction::operator--(int rhs)
{
    Fraction temp = *this;
    *this -= 1;
    return temp;
}

const Fraction operator-(const Fraction& rhs)
{
    Fraction result = rhs;
    result *= -1;
    return result; 
}

const Fraction operator!(const Fraction& rhs)
{
    Fraction result;
    result = 1;
    result /= rhs;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Fraction& rhs)
{
    if (rhs.denominator == 1) {
        out << rhs.numerator;
        return out;
    }
    out << rhs.numerator << '/' << rhs.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& rhs)
{
    std::string input;
    std::getline(in, input);

    std::string numerator;
    std::string denominator;

    std::string::size_type begInd = input.find_first_not_of(' ');
    std::string::size_type endInd = input.find_first_of('/');

    if (begInd == std::string::npos) {
        throw std::runtime_error("Input is empty!");
    }
    
    numerator = input.substr(begInd, endInd - begInd);

    rhs.numerator = std::stoi(numerator);

    if (endInd == std::string::npos) {
        rhs.denominator = 1;
        return in;
    }

    begInd = input.find_first_not_of('/', endInd);
    if (begInd == std::string::npos) {
        throw std::runtime_error("There is no denomimator!");
    }

    endInd = input.find_first_not_of("1234567890 ", begInd);
    if (endInd != std::string::npos) {
        throw std::runtime_error("Denominator has not only numbers!");
    }

    denominator = input.substr(begInd, endInd - begInd);

    rhs.denominator = std::stoul(denominator);

    if (!rhs.denominator) {
        throw std::runtime_error("Division by zero!");
    }

    rhs.reduce();

    return in;
}

double Fraction::toDouble()
{
    double result;
    result = static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    return result;
}
