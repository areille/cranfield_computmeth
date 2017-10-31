#include "PDEImplicit.h"

void PDEImplicit::solve()
{
    for (int n = 2; n < this->ntime; n++)
    {
        for (int i = 1; i < this->nspace - 1; i++)
        {
            this->results[n][i] = advance(n - 2);
        }
    }
}

// LaasonenSolve::LaasonenSolve() {}

// double LaasonenSolve::advance(int k) const
// {
//     // LU fact to have L and U
//     // for
//     // lu_solve => result[i] = x
//     return 0.0;
// }
