#include <iostream>
#include <fstream>
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

void printsMethod(Matrix &results, bool printOne, double dt)
{
    if (printOne)
    {
        int x1 = 0.1 / dt;
        int x2 = 0.2 / dt;
        int x3 = 0.3 / dt;
        int x4 = 0.4 / dt;
        int x5 = 0.5 / dt;
        vector<double> t0 = results[0];
        vector<double> t01 = results[x1];
        vector<double> t02 = results[x2];
        vector<double> t03 = results[x3];
        vector<double> t04 = results[x4];
        vector<double> t05 = results[x5];
        ofstream csvFile;
        csvFile.open("results.csv");
        csvFile << "∆t = " << dt << "\n";
        csvFile << "x, t = 0, t = 0.1, t = 0.2, t = 0.3, t = 0.4, t = 0.5\n";
        double x = 0.0;
        for (int i = 0; i < t0.size(); i++)
        {
            csvFile << x << ", "<< t0[i] << ", " << t01[i] << ", " << t02[i] << ", " << t03[i] << ", " << t04[i] << ", " << t05[i] << "\n";
            x+=0.05;
        }
        csvFile.close();
    }
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
    std::cout << "Value of ∆t? (default is 0.01)" << std::endl;
    std::cin >> dt;
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
    Matrix Anaresults(ntime, nspace);

    for (int n = 0; n < ntime; n++)
    {
        for (int i = 0; i < nspace; i++)
        {
            double x = i * dx;
            double t = n * dt;
            double sum = 0.0;

            sum = calculateSum(1000, D, L, t, x);

            Anaresults[n][i] = Text + 2 * (Tint - Text) * sum;
        }
    }

    double time = 0.0;
    // std::cout << "Results : type the time you want" << std::endl;
    // std::cin >> time;
    // std::cout << std::endl;
    // std::cout << std::endl;

    int accessor = time * 100;

    // vector<double> dft20 = DFresults[accessor];
    // vector<double> r20 = Richresults[accessor];
    // vector<double> las20 = Laasresults[accessor];
    // vector<double> cr20 = CrankNicholsonResults[accessor];
    // vector<double> an20 = Anaresults[accessor];

    // std::cout << "Results with the Dufort Frankel method at t = " << time << "h :"<< std::endl;
    // for (int i = 0; i < dft20.size(); i++)
    // {
    //     std::cout << dft20[i] << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "Results with the Richardson method at t = " << time << "h :"<< std::endl;
    // for (int i = 0; i < r20.size(); i++)
    // {
    //     std::cout << r20[i] << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "Results with the Laasonen method at t = " << time << "h :"<< std::endl;
    // for (int i = 0; i < las20.size(); i++)
    // {
    //     std::cout << las20[i] << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "Results with the Crank Nicholson method at t = " << time << "h :"<< std::endl;
    // for (int i = 0; i < cr20.size(); i++)
    // {
    //     std::cout << cr20[i] << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "Analytical results at t = " << time << "h :"<< std::endl;
    // for (int i = 0; i < an20.size(); i++)
    // {
    //     std::cout << an20[i] << ", ";
    // }
    printsMethod(Laasresults, true, dt);

    return 0;
}
