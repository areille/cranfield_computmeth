#include "CrankNicholsonSolve.h"

void CrankNicholsonSolve::advance()
{
    C = (D * dt) / ((dx * dx));

    // Creation of matrix A
    for (int i = 0; i < nspace - 2; i++)
    {
        for (int j = 0; j < nspace - 2; j++)
        {
            if (i == j)
                A[i][j] = 1 + C;
            if (i == (j + 1) || (j > 0 && i == (j - 1)))
                A[i][j] = -C / 2;
        }
    }
    // Creation of matrix E
    for (int i = 0; i < nspace - 2; i++)
    {
        for (int j = 0; j < nspace - 2; j++)
        {
            if (i == j)
                E[i][j] = 1 - C;
            if (i == (j + 1) || (j > 0 && i == (j - 1)))
                E[i][j] = C / 2;
        }
    }

    // creation of vector B
    B = results[0];
    // B = E * results[0];
    for (int i = 0; i < nspace - 2; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < nspace - 2; j++)
        {
            sum += E[i][j] * results[0][j + 1];
        }
        B[i + 1] = sum;
    }

    X = B; // find smthng better

    lu_fact();
    for (int n = 2; n < ntime; n++)
    {
        lu_solve();
        results[n] = X;
        // B = E * X;
        for (int i = 0; i < nspace - 2; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < nspace - 2; j++)
            {
                sum += E[i][j] * X[j + 1];
            }
            B[i + 1] = sum;
        }
    }
}