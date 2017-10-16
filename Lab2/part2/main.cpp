#include <iostream>
#include <vector>
#include <math.h>

void thomasAlg(std::vector<double> &fn, std::vector<double> &fnplus, int N, std::vector<double> &a, std::vector<double> &b, std::vector<double> &c)
{
    c[0] = c[0] / b[0];
    fn[0] = fn[0] / b[0];
    for (int i = 1; i < N - 1; i++)
    {
        c[i] = c[i] / (b[i] - a[i] * c[i - 1]);
        std::cout << " c[i] : c = " << c[i] << " i = " << i << std::endl;
        fn[i] = (fn[i] - a[i] * fn[i - 1]) / (b[i] - a[i] * c[i - 1]);
        std::cout << " fn[i] = " << fn[i] << std::endl;
    }
    fn[N - 1] = (fn[N - 1] - a[N - 1] * fn[N - 2]) / (b[N - 1] - a[N - 1] * c[N - 2]);
    fnplus[N - 1] = fn[N - 1];

    for (int j = N - 2; j >= 0; j--)
    {
        std::cout << "Algo : " << fnplus[j] << std::endl;
        fnplus[j] = fn[j] - c[j] * fnplus[j + 1];
    }
}

int main()
{
    // Variables
    double D = 0.01;
    double r = 0.4;
    double dx = 0.05; // 20pts
    double dt = (r * pow(dx, 2)) / D;
    double C = (D * dt) / (pow(dx, 2));
    int N = 20;

    std::vector<double> fn(N, 0);
    std::vector<double> fnplus(N, 0);
    std::vector<double> a(N, 0);
    std::vector<double> b(N, 0);
    std::vector<double> c(N - 1, 0);
    for (int i = 0; i < N - 1; i++)
    {
        a[i] = -C;
        b[i] = 1 + 2 * C;
        c[i] = -C;
        fn[i] = 0;
    }
    b[N - 1] = 1 + 2 * C;
    fn[N - 1] = 1;

    for (int i = 0; i < N; i++)
    {
        std::cout << "a : " << a[i] << std::endl;
        std::cout << "b : " << b[i] << std::endl;
        std::cout << "c : " << c[i] << std::endl;
        std::cout << "fn+1 : " << fnplus[i] << std::endl;
    }
    thomasAlg(fn, fnplus, N, a, b, c);

    return 0;
}