#include "PDEExplicit.h"


void PDEExplicit::solve()
{
    for (int n = 2; n < ntime; n++)
    {
        for (int i = 1; i < nspace - 1; i++)
        {
            results[n][i] = advance(n - 2, i - 1);
        }
    }
}
