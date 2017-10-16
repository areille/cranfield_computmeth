#include "PDESolve.h"

PDESolve::PDESolve() : D(0.0), dx(0.0), dt(0.0), L(0.0), T(0.0), Text(0.0), Tint(0.0) {}

PDESolve::PDESolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
{
    this->D = D;
    this->dx = dx;
    this->dt = dt;
    this->L = L;
    this->T = T;
    this->Text = Text;
    this->Tint = Tint;

    this->alpha = 2 * D * dt / pow(dx, 2);
    this->nspace = L / dx;
    this->ntime = T / dt;

    // Initialisation with boudary conditions
    for (int i = 0; i < nspace; i++)
    {
        this->results[0][i] = Tint;
        this->results[1][i] = Tint;
    }
    for (int i = 0; i < ntime; i++)
    {
        this->results[i][0] = Text;
        this->results[i][nspace - 1] = Text;
    }
}
double **PDESolve::get_res() const
{
    return this->results;
}

void PDESolve::solve()
{
    for (int n = 2; n <= this->ntime + 1; n++)
    {
        for (int i = 1; i <= this->nspace - 1; i++)
        {
            advance(n - 2, i - 1);
        }
    }
}

DufortFrankelSolve::DufortFrankelSolve() {}

DufortFrankelSolve::DufortFrankelSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDESolve(D, dx, dt, L, T, Text, Tint){}

double DufortFrankelSolve::advance(int k, int l) const
{
    return ((1 - alpha) / (1 + alpha)) * results[k][l+1] + (alpha / (1 + alpha)) * (results[k+1][l+2] + results[k+1][l]);
}
