#include <iostream>
#include <math.h>

#define PI 3.14

int main()
{
    // Variables
    double D = 0.01;

    double r = 0.6;
    double dx = 0.05; // 20pts
    double dt = (r * pow(dx, 2)) / D;


    int nspace = 20; // 20pts
    int ntime = 100;

    double results[ntime][nspace];

    // initialisation
    for (int i = 0; i < nspace; i++)
    {
        results[0][i] = 0;
    }
    for (int i = 1; i <= ntime; i++)
    {
        results[i][0] = 0;
        results[i][nspace - 1] = 1;
    }

    // loop
    for (int n = 1; n < ntime; n++)
    {
        for (int i = 1; i < nspace - 1; i++)
        {
            results[n][i] = r * (results[n - 1][i + 1] + results[n - 1][i - 1]) + (1 - 2 * r) * results[n - 1][i];
        }
    }

    // time equal to 0s
    std::cout << std::endl;
    std::cout << "t = 0 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        std::cout << results[0][j] << ", ";
    }
    std::cout << "r = " << r << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int x = 0; x < nspace; x++)
    {
        double sum = 0.0;
        for (int n = 1; n < 100; n++)
        {
            sum += ((pow(-1.0, n) / (PI * n)) * exp(-D * pow(PI, 2) * pow(n, 2) * 0) * sin(PI * n * dx * x));
        }
        double anres = x * dx + 2 * sum;
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    // time equal to 1,2s
    std::cout << std::endl;
    std::cout << "t = 1,2 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        int t = 1.2 / dt;
        std::cout << results[t][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int x = 0; x < nspace; x++)
    {
        double sum = 0.0;
        for (int n = 1; n < 100; n++)
        {
            sum += ((pow(-1.0, n) / (PI * n)) * exp(-D * pow(PI, 2) * pow(n, 2) * 1.2) * sin(PI * n * dx * x));
        }
        double anres = x * dx + 2 * sum;
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    // time equal to 5,2s
    std::cout << std::endl;
    std::cout << "t = 5,2 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        int t = 5.2 / dt;
        std::cout << results[t][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int x = 0; x < nspace; x++)
    {
        double sum = 0.0;
        for (int n = 1; n < 100; n++)
        {
            sum += ((pow(-1.0, n) / (PI * n)) * exp(-D * pow(PI, 2) * pow(n, 2) * 5.2) * sin(PI * n * dx * x));
        }
        double anres = x * dx + 2 * sum;
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    // time equal to 10s
    std::cout << std::endl;
    std::cout << "t = 10 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        int t = 10 / dt;
        std::cout << results[t][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int x = 0; x < nspace; x++)
    {
        double sum = 0.0;
        for (int n = 1; n < 100; n++)
        {
            sum += ((pow(-1.0, n) / (PI * n)) * exp(-D * pow(PI, 2) * pow(n, 2) * 10) * sin(PI * n * dx * x));
        }
        double anres = x * dx + 2 * sum;
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    return 0;
}