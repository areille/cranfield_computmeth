#include "PDEExplicit.h"


class DufortFrankelSolve : public PDEExplicit
{
  public:
    DufortFrankelSolve() {};
    DufortFrankelSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEExplicit(D, dx, dt, L, T, Text, Tint) {};
    double advance(int k, int l) const;
};