#include "LaasonenSolve.h"

void LaasonenSolve::advance()
{
    C = (D * dt) / (dx * dx);
    // Creation of matrix A
    for (int i = 0; i < nspace - 2; i++)
    {
        for (int j = 0; j < nspace - 2; j++)
        {
            if (i == j)
                A[i][j] = 1 + 2 * C;
            if (i == (j + 1) || (j > 0 && i == (j - 1)))
                A[i][j] = -C;
        }
    }

    // creation of vector B
    B = results[0];
    X = B; // find smthng better
    lu_fact();
    for (int n = 2; n < ntime; n++)
    {
        lu_solve();
        results[n] = X;
        B = X;
    }
}