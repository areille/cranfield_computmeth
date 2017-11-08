#include <iostream>
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "DufortFrankelSolve.h"
#include "RichardsonSolve.h"
#include "LaasonenSolve.h"
#include "CrankNicholsonSolve.h"
#define PI 3.141592

double calculateSum(int max_m, double D, double L, double t, double x)
{
    double sum = 0.0;
    for (int m = 1; m < max_m; m++)
    {
        double term_1 = -D * (m * PI / L) * (m * PI / L) * t;
        double term_2 = (1 - pow(-1, m)) / (m * PI);
        double term_3 = m * PI * x / L;
        sum += exp(term_1) * term_2 * sin(term_3);
    }
    return sum;
}

int main()
{
    // Initialization
    int Tint = 100;
    int Text = 300;
    double dx = 0.05;
    double dt = 0.01;
    double L = 1.0;
    double T = 1.0;
    double D = 0.1;
    int ntime = T / dt;
    int nspace = L / dx + 1;

    Matrix DFresults(ntime, nspace);
    Matrix Richresults(ntime, nspace);
    Matrix Laasresults(ntime, nspace);
    Matrix CrankNicholsonResults(ntime, nspace);

    vector<PDESolve *> vect(4);
    vect[0] = new DufortFrankelSolve(D, dx, dt, L, T, Text, Tint);
    vect[1] = new RichardsonSolve(D, dx, dt, L, T, Text, Tint);
    vect[2] = new LaasonenSolve(D, dx, dt, L, T, Text, Tint);
    vect[3] = new CrankNicholsonSolve(D, dx, dt, L, T, Text, Tint);

    vect[0]->solve();
    vect[1]->solve();
    vect[2]->solve();
    vect[3]->solve();

    DFresults = vect[0]->get_res();
    Richresults = vect[1]->get_res();
    Laasresults = vect[2]->get_res();
    CrankNicholsonResults = vect[3]->get_res();

    // Calculation of analytical results
    Matrix Anaresults(ntime, nspace + 1);

    for (int n = 0; n < ntime; n++)
    {
        for (int i = 0; i < nspace + 1; i++)
        {
            double x = i * dx;
            double t = n * dt;
            double sum = 0.0;

            sum = calculateSum(1000, D, L, t, x);

            Anaresults[n][i] = Text + 2 * (Tint - Text) * sum;
        }
    }

    vector<double> dft10 = DFresults[10];
    vector<double> r10 = Richresults[10];
    vector<double> las10 = Laasresults[10];
    vector<double> cr10 = CrankNicholsonResults[10];
    vector<double> an10 = Anaresults[10];

    std::cout << "Results with the Dufort Frankel method at t = 0.1h" << std::endl;
    for (int i = 0; i < dft10.size(); i++)
    {
        std::cout << dft10[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Results with the Richardson method at t = 0.1h" << std::endl;
    for (int i = 0; i < r10.size(); i++)
    {
        std::cout << r10[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Results with the Laasonen method at t = 0.1h" << std::endl;
    for (int i = 0; i < las10.size(); i++)
    {
        std::cout << las10[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Results with the Crank Nicholson method at t = 0.1h" << std::endl;
    for (int i = 0; i < cr10.size(); i++)
    {
        std::cout << cr10[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Analytical results at t = 0.1h" << std::endl;
    for (int i = 0; i < an10.size(); i++)
    {
        std::cout << an10[i] << ", ";
    }
    // std::cout << Anaresults[10] << std::endl;

    return 0;
}
