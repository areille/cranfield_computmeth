#include "PDEImplicit.h"

class LaasonenSolve : public PDEImplicit
{
public:
    LaasonenSolve() {};
    LaasonenSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEImplicit(D, dx, dt, L, T, Text, Tint) {};
    void advance();
};