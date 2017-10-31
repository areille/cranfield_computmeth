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

void PDEImplicit::lu_solve()
{
    vector<double> temp(this->nspace);
    int i, j;
    temp = this->B;
    for (i = 0; i < this->nspace; i++)
        for (j = 0; j < i; j++)
            temp[i] -= this->L[i][j] * temp[j];

    for (i = this->nspace - 1; i >= 0; i--)
    {
        for (j = i + 1; j < this->nspace; j++)
            temp[i] -= this->U[i][j] * temp[j];
        temp[i] /= this->U[i][i];
    }
    for (i = 0; i < this->nspace; i++)
        this->X[i] = temp[i];
}

void PDEImplicit::solve()
{
    this->A = Matrix(this->nspace - 2, this->nspace - 2);
    this->L = Matrix(this->nspace - 2, this->nspace - 2);
    this->U = Matrix(this->nspace - 2, this->nspace - 2);
    this->C = (this->D * this->dt) / (this->dx * this->dx);
    // Creation of matrix A
    for (int i = 0; i < this->nspace - 2; i++)
    {
        for (int j = 0; j < this->nspace - 2; j++)
        {
            if (i == j)
                this->A[i][j] = 1 + 2 * this->C;
            if (i == (j + 1) || (j > 0 && i == (j - 1)))
                this->A[i][j] = -this->C;
        }
    }
    // creation of vector B
    this->B = this->results[0];
    lu_fact();
    for (int n = 2; n < this->ntime; n++)
    {
        lu_solve();
        this->results[n] = this->X;
        this->B = this->X;
    }
}
