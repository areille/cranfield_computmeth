#include "RichardsonSolve.h"

double RichardsonSolve::advance(int k, int l) const
{
    return (
        this->results[k][l + 1] + this->alpha * (this->results[k + 1][l] - 2 * this->results[k + 1][l + 1] + this->results[k + 1][l + 2]));
}