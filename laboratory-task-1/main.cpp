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


#include <iostream>
#include <iomanip>
#include <cmath>


int main()
{
    try
    {
        double x;
        std::cout << "Input x that belongs to the interval (-1; 1): ";
        std::cin >> x;
        if (!(x > -1 && x < 1))
        {
            throw std::runtime_error("Wrong x");
        }

        int64_t k;
        std::cout << "Input natural k: ";
        std::cin >> k;
        if (!(k > 1))
        {
            throw std::runtime_error("Wrong k");
        }

        long double eps;
        std::cout << "Input epsilon: ";
        std::cin >> eps;
        if (!(0 < eps && eps < pow(10,-k)))
        {
            throw std::runtime_error("Wrong epsilon");
        }

        long double taylorSeriesMember = x / 2.0;
        long double taylorSeriesResult = 1;
        size_t i = 1;
        while (fabs(taylorSeriesMember) > eps)
        {
            taylorSeriesResult += taylorSeriesMember;
            taylorSeriesMember *= -x * i / (i+3);
            i += 2; 
        }
        
        std::cout << "Taylor series result: " << std::fixed << std::setprecision(k) << taylorSeriesResult << '\n';
        std::cout << "Standart function result: " << sqrt(1.0 + x);
    }
    catch(std::runtime_error e)
    {
        /*
            Использую runtime_error потому что exception не имеет конструктора связанного с char*
            Подробнее:
            https://stackoverflow.com/questions/28640553/exception-class-with-a-char-constructor
        */
        std::cerr << e.what() << '\n';
    }

    return 0;
}
