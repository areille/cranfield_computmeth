#include "PDEExplicit.h"
//#include "PDESolve.h"


void PDEExplicit::solve()
{
    for (int n = 2; n < this->ntime; n++)
    {
        for (int i = 1; i < this->nspace - 1; i++)
        {
            this->results[n][i] = advance(n - 2, i - 1);
        }
    }
}
