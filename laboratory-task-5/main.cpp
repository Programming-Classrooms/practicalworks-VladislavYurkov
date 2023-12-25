/*
    Вычислить значение определенного интеграла с аналитически заданной подынтегральной
    функцией с заданной точностью eps
    Б) по формуле правых прямоугольников;
    Г) по формуле трапеций;
    Формула средних прямоугольников:
    b
    ∫f(x)dx ≈ h*[f(x 1 )+ f(x 2 )+…+ f(x n )], где h=(b-a)/n, f(x i )=a+i*h-h/2,
    a
    где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
    n=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
    приближение. Для этого можно увеличить n в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
    – s 2 | < eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
    противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
    вычисляется новое значение s 2 . Процесс удвоения n и вычисления s 2 надо продолжать до тех пор,
    пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
    Разработать функции, реализующие методы вычислений интеграла, входными параметрами
    которых должны быть функция для вычисления значения подынтегрального выражения, пределы
    интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
    для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута
    заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
    Номер задания равен вашему индивидуальному номеру.
    Вариант 15(Б, Г)
*/


#include <iostream>
#include <cmath>
#include <cstdint>


double firstFunction(double x)
{
    return 1 / (1 + x * x * x);
}

double secondFunction(double x)
{
    return std::exp(0.1 * x) / x;
}

double thirdFunction(double x)
{
    return sin(0.4 * x) * pow(x, 0.23);
}

double rightRectangleIntegral
(
    size_t numberOfFunction,
    double leftBorder, 
    double rightBorder, 
    double eps, 
    uint64_t& n
)
{
    double (*function) (double) = nullptr;
    switch(numberOfFunction) {
        case 1: {
            function = firstFunction;
            break;
        }
        case 2: {
            function = secondFunction;
            break;
        }
        case 3: {
            function = thirdFunction;
            break;
        }
    }

    n = 4;
    double x = leftBorder;
    
    double firstApprox = 0;
    double secondApprox = 0;
    double deltaX = (rightBorder - leftBorder) / static_cast<double>(n);

    for (size_t i = 0; i < n; ++i) {
        x += deltaX;
        firstApprox += function(x) * deltaX;
    }

    while (fabs(firstApprox - secondApprox) >= eps) {
        n *= 2;
        deltaX = (rightBorder - leftBorder) / static_cast<double>(n);

        secondApprox = firstApprox;
        firstApprox = 0;
        x = leftBorder;

        for (size_t i = 0; i < n; ++i) {
            x += deltaX;
            firstApprox += function(x) * deltaX;
        }
    }
    
    return firstApprox;
}

double trapezoidIntegral
(
    size_t numberOfFunction,
    double leftBorder, 
    double rightBorder, 
    double eps, 
    uint64_t& n
)
{
    double (*function) (double) = nullptr;
    switch(numberOfFunction) {
        case 1: {
            function = firstFunction;
            break;
        }
        case 2: {
            function = secondFunction;
            break;
        }
        case 3: {
            function = thirdFunction;
            break;
        }
    }

    n = 4;
    double x = leftBorder;

    double firstApprox = 0;
    double secondApprox = 0;
    double deltaX = (rightBorder - leftBorder) / static_cast<double>(n);

    for (size_t i = 0; i < n; ++i) {
        firstApprox += (function(x) + function(x + deltaX)) / 2 * deltaX;
        x += deltaX;
    }

    while (fabs(firstApprox - secondApprox) >= eps) {
        n *= 2;
        deltaX = (rightBorder - leftBorder) / static_cast<double>(n);

        secondApprox = firstApprox;
        firstApprox = 0;
        x = leftBorder;

        for (size_t i = 0; i < n; ++i) {
            firstApprox += (function(x) + function(x + deltaX)) / 2 * deltaX;
            x += deltaX;
        }
    }
    
    return firstApprox;
}

int main()
{
    uint64_t n = 4;
    return 0;
}
