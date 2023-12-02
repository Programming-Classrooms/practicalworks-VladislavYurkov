#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;

//Вариант 8
/*
Разработать консольное приложение для вычисления приближённого
значения функции, используя представление ее в виде ряда Тейлора.
Вычисления заканчивать, когда очередное слагаемое окажется по модулю
меньше заданного числа 𝑒𝑝𝑠𝑖𝑙𝑜𝑛, где 0 < 𝑒𝑝𝑠𝑖𝑙𝑜𝑛 < 10−𝑘 , 𝑘 – натуральное
число, 𝑘 > 1. Сравнить полученный результат со значением, вычисленным с
помощью стандартных функций. Значение 𝑥 и 𝑘 ввести по запросу.
*/
//8. √(1 + 𝑥)

int main()
{
    try
    {
        double x;
        cout << "Input x that belongs to the interval (-1; 1): ";
        cin >> x;
        if (!(x > -1 && x < 1))
        {
            throw "Wrong x";
        }

        int64_t k;
        cout << "Input natural k: ";
        cin >> k;
        if (!(k > 1))
        {
            throw "Wrong k";
        }

        long double eps;
        cout << "Input epsilon: ";
        cin >> eps;
        if (!(0 < eps && eps < pow(10,-k)))
        {
            throw "Wrong epsilon";
        }

        long double term = x / 2.0;
        long double result = 1;
        size_t i = 1;
        while (fabs(term) > eps)
        {
            result += term;
            term *= -x * i / (i+3);
            i += 2; 
        }
        
        cout << "Taylor series result: " << std::fixed << std::setprecision(k) << result << '\n';
        cout << "Standart function result: " << sqrt(1.0 + x);
    }
    catch(const char* e)
    {
        cout << e << '\n';
    }
        
    return 0;
}
