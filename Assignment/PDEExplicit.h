#ifndef PDEEXPLICIT_H
#define PDEEXPLICIT_H

#include "PDESolve.h"
#include "matrix.h"

using namespace std;


/**
 * A subclass of PDE Solver, specialized for explicit schemes.
 * 
 * The PDE explicit class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \n-a solve method which will solve the problem with all input values,
 * \nonly for explicit methods.
 * \n-a virtual advance method which take to the next time and space step.
*/
class PDEExplicit : public PDESolve
{
public:
// CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty explicit methods solver.
 * @see PDEExplicit(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
  PDEExplicit() : PDESolve(){};

  /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an explicit solver with all the problem data, values and initial conditions.
   * @see PDEExplicit()
   * @exception invalid_argument ("value must be positive double")
   */
  PDEExplicit(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */) {};

  // SOLVE METHODS
  /**
   * Solve method
   * solves the problem for explicit schemes and writes the results in a matrix
   * 
  */
  void solve();

  // VIRTUAL METHODS

  /**
   * Virtual advance method
   * advance at step k in time and step l in space
   * 
  */
  virtual double advance(int k /**< int. Time step you want to access */, int l /**< int. Space step you want to access */) const = 0;
};

#endif