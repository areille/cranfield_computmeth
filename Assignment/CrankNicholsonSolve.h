#include "PDEImplicit.h"

class CrankNicholsonSolve : public PDEImplicit
{
public:
    CrankNicholsonSolve() {};
    CrankNicholsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEImplicit(D, dx, dt, L, T, Text, Tint) {};
    void advance();
};