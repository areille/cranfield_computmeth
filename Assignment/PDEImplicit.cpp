#include "PDEImplicit.h"

void PDEImplicit::lu_fact()
{
    Matrix temp;
    double mult;
    int i, j, k;
    int n = A.getNcols();
    temp = A;
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            if (fabs(temp[k][k] < 1.e-07))
            {
                std::cout << "Pivot is zero" << std::endl;
                exit(1);
            }
            mult = temp[i][k] / temp[k][k];
            temp[i][k] = mult;
            for (j = k + 1; j < n; j++)
            {
                temp[i][j] -= mult * temp[k][j];
                if (fabs(temp[i][i]) < 1.e-07)
                {
                    std::cout << "Pivot is zero" << std::endl;
                    exit(1);
                }
            }
        }
    }
    // create L and U from temp
    for (i = 0; i < n; i++)
        L[i][i] = 1.0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            L[i][j] = temp[i][j];

    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            U[i][j] = temp[i][j];
}

void PDEImplicit::lu_solve()
{
    vector<double> temp(nspace);
    int i, j;
    temp = X;
    temp[1] += C * temp[0];
    temp[nspace - 2] += C * temp[nspace - 1];
    for (i = 0; i < nspace - 2; i++)
    {
        for (j = 0; j < i; j++)
        {
            temp[i + 1] -= L[i][j] * temp[j+1];
        }
    }

    for (i = nspace - 3; i >= 0; i--)
    {
        for (j = i + 1; j < nspace - 2; j++)
            temp[i + 1] -= U[i][j] * temp[j + 1];
        temp[i+1] /= U[i][i];
    }
    X = temp;
}

void PDEImplicit::solve()
{
    A = Matrix(nspace - 2, nspace - 2);
    L = Matrix(nspace - 2, nspace - 2);
    U = Matrix(nspace - 2, nspace - 2);
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

    // creation of vector X
    X = results[0];
    Y = X; // find smthng better 
    lu_fact();
    for (int n = 2; n < ntime; n++)
    {
        lu_solve();
        results[n] = Y;
        X = Y;
    }
}
