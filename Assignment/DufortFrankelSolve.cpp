#include "DufortFrankelSolve.h"

double DufortFrankelSolve::advance(int k, int l) const
{
    return (
               (1 - this->alpha) / (1 + this->alpha)) *
               this->results[k][l + 1] +
           (this->alpha / (1 + this->alpha)) * (this->results[k + 1][l + 2] + this->results[k + 1][l]);
}
