#ifndef PDEIMPLICIT_H
#define PDEIMPLICIT_H

#include "PDESolve.h"
#include "matrix.h"
#include <vector>

using namespace std;

class PDEImplicit : public PDESolve
{
  protected:
    Matrix A, E, L, U;
    vector<double> B, X;
    double C;
    void lu_fact();
    void lu_solve();

  public:
    PDEImplicit() : PDESolve(){};
    PDEImplicit(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDESolve(D, dx, dt, L, T, Text, Tint){};
    void solve();
    virtual void advance(){};
};

#endif
