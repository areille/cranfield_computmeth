#ifndef PDEEXPLICIT_H
#define PDEEXPLICIT_H

#include "PDESolve.h"
#include "matrix.h"

using namespace std;

class PDEExplicit : public PDESolve
{
public:
  PDEExplicit() : PDESolve(){};
  PDEExplicit(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDESolve(D, dx, dt, L, T, Text, Tint) {};
  void solve();
  virtual double advance(int k, int l) const = 0;
};

#endif