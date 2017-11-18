#ifndef PDEIMPLICIT_H
#define PDEIMPLICIT_H

#include "PDESolve.h"
#include "matrix.h"
#include <vector>

using namespace std;


/**
 * A subclass of PDE Solver, specialized for implicit schemes.
 * 
 * The PDE implicit class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \n-a solve method which will solve the problem with all input values,
 * \nonly for implicit methods.
 * \n-a virtual advance method which take to the next time and space step.
*/
class PDEImplicit : public PDESolve
{
  protected:
    Matrix A, E, L, U;
    vector<double> B, X;
    double C;
    void lu_fact();
    void lu_solve();

  public:
  // CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty implicit methods solver.
 * @see PDEImplicit(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
    PDEImplicit() : PDESolve(){};

    /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an implicit solver with all the problem data, values and initial conditions.
   * @see PDEImplicit()
   * @exception invalid_argument ("value must be positive double")
   */
    PDEImplicit(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */) {};
    
     // SOLVE METHODS
  /**
   * Solve method
   * solves the problem for implicit schemes and writes the results in a matrix
   * 
  */
    void solve();

    /**
   * Virtual advance method
   * advance at next step
   * 
  */
    virtual void advance(){};
};

#endif
