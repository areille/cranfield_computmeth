#include "PDEImplicit.h"

void PDEImplicit::lu_fact()
{
    Matrix temp;
    double mult;
    int i, j, k;
    int n = this->A.getNcols();
    // temp = Matrix(this->A.getNrows(), this->A.getNcols());
    temp = this->A;
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
        this->L[i][i] = 1.0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            this->L[i][j] = temp[i][j];

    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            this->U[i][j] = temp[i][j];
}

void PDEImplicit::solve()
{
    for (int n = 2; n < this->ntime; n++)
    {
        this->results[n] = advance(n - 2);
    }
}
