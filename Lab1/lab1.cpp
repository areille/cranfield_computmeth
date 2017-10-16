#include <iostream>
#include <math.h>

int sign(double number)
{
    if (number < 0)
        return -1;
    else if (number > 0)
        return 1;
    else
        return 0;
}

double norm_0(double *values, int length)
{
    double max = values[0];
    for (int i = 0; i < length; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }
    return max;
}

double norm_1(double *values, int length)
{
    double res = 0.0;
    for (int i = 0; i < length; i++)
    {
        res += fabs(values[i]);
    }
    return res;
}

double norm_2(double *values, int length)
{
    double res = 0.0;
    for (int i = 0; i < length; i++)
    {
        res += fabs(values[i]) * fabs(values[i]);
    }
    return sqrt(res);
}

int main()
{

    int nspace = 100;
    int tottime = 22;
    double dx = 0.8;
    double dt = dx / 2;
    int ntime = tottime / dt;

    int onetime = 1 * dt;
    int ftime = 5 * dt;
    int tetime = 10 * dt;
    int twtime = 20 * dt;

    double courantNumber = dt / dx;

    double results[ntime][nspace];

    /* initial conditions
    *
    *
    *
    */
    for (int i = 0; i < nspace; i++)
    {
        // // fo
        // double x = -40 + i * dx;
        // results[0][i] = 0.5 * (sign(x) + 1);

        //f1
        double x = -40 + i * dx;
        results[0][i] = 0.5 * exp(-(x * x));
    }
    for (int n = 0; n < ntime; n++)
    {
        // //fo
        // results[n][0] = 0;
        // results[n][nspace - 1] = 1;

        //f1
        results[n][0] = 0;
        results[n][nspace - 1] = 0;
    }

    // loop
    for (int n = 1; n < ntime; n++)
    {
        for (int i = 1; i < nspace - 1; i++)
        {
            results[n][i] = results[n - 1][i] * (1 - courantNumber) + courantNumber * results[n - 1][i - 1];
        }
    }

    // time equal to 5s
    std::cout << "t = 5 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        std::cout << results[ftime][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        double x = -40 + j * dx;
        // // fo
        // double anres = 0.5 * (sign(x - 5) + 1);

        // f1
        double anres = 0.5 * exp(-(x - 5) * (x - 5));
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    // time equal to 10s
    std::cout << "t = 10 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        std::cout << results[tetime][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        double x = -40 + j * dx;
        // // fo
        // double anres = 0.5 * (sign(x - 10) + 1);

        // f1
        double anres = 0.5 * exp(-(x - 10) * (x - 10));
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    // time equal to 20s
    std::cout << "t = 20 :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        std::cout << results[twtime][j] << ", ";
    }
    std::cout << std::endl;

    std::cout << "analytical result :" << std::endl;
    for (int j = 0; j < nspace; j++)
    {
        double x = -40 + j * dx;
        // // fo
        // double anres = 0.5 * (sign(x - 20) + 1);

        // f1
        double anres = 0.5 * exp(-(x - 20) * (x - 20));
        std::cout << anres << ", ";
    }
    std::cout << std::endl;
    // -----------------------

    return 0;
}