#include <iostream>
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "DufortFrankelSolve.h"
#include "RichardsonSolve.h"
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
    int nspace = L / dx;

    Matrix DFresults(ntime, nspace);
    Matrix Richresults(ntime, nspace);

    vector<PDESolve *> vect(2);
    vect[0] = new DufortFrankelSolve(D, dx, dt, L, T, Text, Tint);
    vect[1] = new RichardsonSolve(D, dx, dt, L, T, Text, Tint);

    vect[0]->solve();
    vect[1]->solve();

    DFresults = vect[0]->get_res();
    Richresults = vect[1]->get_res();

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

    std::cout << "Results with the Dufort Frankel method" << std::endl;
    std::cout << DFresults << std::endl;
    std::cout << "Results with the Richardson method" << std::endl;
    std::cout << Richresults << std::endl;
    std::cout << "Analytical results" << std::endl;
    std::cout << Anaresults << std::endl;

    return 0;
}

