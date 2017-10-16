#include "PDESolve.h"

PDESolve::PDESolve() : m(Matrix(1)), D(0.0), dx(0.0), dt(0.0), L(0.0), T(0.0), Text(0.0), Tint(0.0) {}

PDESolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint)
{
    this->m = m;
    this->D = D;
    this->dx = dx;
    this->dt = dt;
    this->L = L;
    this->T = T;
    this->Text = Text;
    this->Tint = Tint;

    this->alpha = 2 * D * dt / pow(dx, 2);
    this->nspace = L / dx;
    this->ntime = T / dx;

    // Initialisation with boudary conditions
    for (int i = 0; i < nspace; i++)
    {
        m[0][i] = Tint;
    }
    for (int i = 0; i < ntime; i++)
    {
        m[i][0] = Text;
        m[i][nspace - 1] = Text;
    }
}
Matrix PDESolve::getMatrix() const
{
    return m;
}

DufortFrankelSolve::DufortFrankelSolve() :
{
    std::cerr << "Error : need arguments" << std::endl;
    return -1;
}
DufortFrankelSolve::DufortFrankelSolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint)
{
    for (int n = 2; n < ntime; n++)
    {
        for (int i = 1; i < nspace - 1; i++)
        {
            // Dufort-frankel method :
            m[n][i] = ((1 - alpha) / (1 + alpha)) * results[n - 2][i] + (alpha / (1 + alpha)) * (results[n - 1][i + 1] + results[n - 1][i - 1]);
        }
    }
}