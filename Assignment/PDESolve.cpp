#include "PDESolve.h"

// PDESolve::PDESolve() : D(0.0), dx(0.0), dt(0.0), L(0.0), T(0.0), Text(0.0), Tint(0.0) {}

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
    this->r = D * dt / pow(dx, 2);
    this->nspace = L / dx + 1;
    this->ntime = T / dt;
    this->results = Matrix(this->ntime, this->nspace);

    // Initialisation with boudary conditions
    for (int i = 0; i < nspace; i++)
    {
        results[0][i] = Tint;
    }
    for (int n = 0; n < ntime; n++)
    {
        results[n][0] = Text;
        results[n][nspace - 1] = Text;
    }
    for (int i = 0; i < nspace; i++)
    {
        // using an order one scheme to find n = 1
        this->results[1][i] = this->r * (this->results[0][i + 1] + this->results[0][i - 1]) + (1 - 2 * this->r) * this->results[0][i];
    }
    this->results[1][0] = Text;
    this->results[1][nspace - 1] = Text;
}
Matrix PDESolve::get_res() const
{
    return this->results;
}
