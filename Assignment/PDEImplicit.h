#ifndef PDEIMPLICIT_H
#define PDEIMPLICIT_H

#include "PDESolve.h"
#include "matrix.h"

using namespace std;


class PDEImplicit : public PDESolve
{
public:
  PDEImplicit() : PDESolve(){};
  PDEImplicit(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDESolve(D, dx, dt, L, T, Text, Tint) {};
  void solve();
  virtual double advance(int k) const = 0;
};


// class LaasonenSolve : public PDEImplicit
// {
//   public:
//     LaasonenSolve();
//     LaasonenSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEImplicit(D, dx, dt, L, T, Text, Tint){}
//     virtual double advance(int k) const;
// };

// class CrankNicholsonSolve : public PDEImplicit
// {
//   public:
//     CrankNicholsonSolve();
//     CrankNicholsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEImplicit(D, dx, dt, L, T, Text, Tint){}
//     virtual double advance(int k) const;
// };

#endif
