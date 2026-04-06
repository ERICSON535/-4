#define _USE_MATH_DEFINES   // для M_PI в Visual Studio
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // ---------------------- a) Сумма ряда (цикл for) ----------------------
    double sum_a = 0.0;
    for (int n = 1; n <= 24; ++n) {
        // sin(π/2 + nπ) = (-1)^n
        double term = pow(-1.0, n) / (n * sqrt(n));
        sum_a += term;
    }
    printf("a) Сумма ряда = %.10f (ожидается -0.7610)\n\n", sum_a);

    // ---------------------- b) Поиск максимума последовательности (цикл for) -----
    double max_u = 0.0;
    int max_index = 0;
    for (int i = 1; i <= 25; ++i) {
        double u = i * exp(-0.1 * i);
        if (i == 1 || u > max_u) {
            max_u = u;
            max_index = i;
        }
    }
    printf("b) Максимальное значение = %.10f\n   Номер элемента = %d (ожидается 3.678794 и 10)\n\n", max_u, max_index);

    // ---------------------- c) Сумма бесконечного ряда (цикл while, оптимизация) --
    double x = 2.0;
    double eps = 1e-12;       // точность
    double a = x;             // первый член (i=0)
    double sum_c = 0.0;
    int i = 0;
    while (fabs(a) > eps) {
        sum_c += a;
        ++i;
        // рекуррентная формула: a_{i} = a_{i-1} * x^2 / ((2i)*(2i+1))
        a = a * x * x / ((2.0 * i) * (2.0 * i + 1.0));
    }
    printf("c) Сумма ряда (sinh(2)) = %.10f (ожидается 3.6269)\n\n", sum_c);

    // ---------------------- d) Рекуррентная последовательность (цикл do..while) --
    double A_prev = 1.0;   // A0
    double A_curr = 0.3;   // A1
    double A_next;
    int n = 1;             // текущий номер A_curr
    do {
        n++;               // переходим к следующему индексу
        // вычисляем A_n по формуле: A_{n} = cos(A_{n-1})/(n-1) + A_{n-2}
        // здесь A_prev = A_{n-2}, A_curr = A_{n-1}
        A_next = cos(A_curr) / (n - 1) + A_prev;
        A_prev = A_curr;
        A_curr = A_next;
    } while (A_curr > -0.5);   // продолжаем, пока A_n > -0.5

    printf("d) Наименьший номер n, при котором A_n <= -0.5: n = %d (ожидается 15)\n", n);

    return 0;
}