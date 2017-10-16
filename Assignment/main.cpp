#include <iostream>
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "PDESolve.h"
#define PI 3.141592


int main()
{  
    std::cout << "Hello world !" << std::endl;
    

    return 0;
}

// double D = 0.1;
    // double dx = 0.05;
    // double dt = 0.01;
    // double L = 1.0;

    // int nspace = 20; // 1ft divided by ∆x
    // int ntime = 100; // 1 hour divided by ∆t

    // double alpha = 2 * D * dt / pow(dx, 2);
    // double results[ntime][nspace];
    // double anres[ntime][nspace];
    // int Tinit = 100;
    // int Tsur = 300;

    // // init
    // for (int i = 0; i < nspace; i++)
    // {
    //     results[0][i] = Tinit;
    // }
    // for (int i = 0; i < ntime; i++)
    // {
    //     results[i][0] = Tsur;
    //     results[i][nspace - 1] = Tsur;
    // }

    // // TODO
    // // n = 1 !!!

    // // numerical results :
    // for (int n = 2; n < ntime; n++)
    // {
    //     for (int i = 1; i < nspace - 1; i++)
    //     {
    //         // Dufort-frankel method :
    //         results[n][i] = ((1 - alpha) / (1 + alpha)) * results[n - 2][i] + (alpha / (1 + alpha)) * (results[n - 1][i + 1] + results[n - 1][i - 1]);
    //     }
    // }
    

    // analytical results :
    // for (int n = 0; n < ntime; n++)
    // {
    //     for (int i = 0; i < nspace; i++)
    //     {
    //         double x = i * dx;
    //         double t = n * dt;
    //         // sum calculation
    //         double sum = 0.0;

    //         // Here we have L = 1, so it does not appear in the equation, hence equation is still homogenous
    //         for (int m = 1; m <= 100; m++)
    //         {
    //             sum += (exp(-D * pow((m * PI / 1), 2) * t)) * ((1 - pow(-1, m)) / m * PI) * sin(m * PI * x / 1);
    //             if (t == 0)
    //                 std::cout << "sum :" << sum << std::endl;
    //         }

    //         // result calculation
    //         anres[n][i] = Tsur + (2 * (Tinit - Tsur) * sum);
    //         if (t == 0)
    //             std::cout << "anres :" << anres[n][i] << std::endl;
    //     }
    // }

    // time equal to 0s
    // std::cout << std::endl;
    // std::cout << "t = 0 :" << std::endl;
    // std::cout << "Numerical :     "
    //           << "Analytical :" << std::endl;
    // for (int j = 0; j < nspace; j++)
    // {
    //     std::cout << "     " << results[0][j] << std::endl;
    // }
    
    // //analytical results
    // std::cout << std::endl;
    // std::cout << "Analytical results for t = 0 : " << std::endl;

    // for (int n = 0; n < ntime; n++)
    // {
    //     for (int i = 0; i < nspace; i++)
    //     {
    //         double x = i * dx;
    //         double t = 0.0;
    //         // sum calculation
    //         double sum = 0.0;
    //         double res = 0.0;
    //         for (int m = 0; m < 10; m++)
    //         {
    //             sum += exp(-D * (m * PI / L) * (m * PI / L) * t) * ((1 - pow(-1, m)) / (m * PI)) * sin(m * PI * x / L);
    //         }
    //         res = Tsur + 2 * (Tinit - Tsur) * sum;
    //         std::cout << res << std::endl;
    //     }
    // }