#ifndef PDESOLVE_H
#define PDESOLVE_H

#include "matrix.h"

using namespace std;

/**
 * A Solver class for one-dimensional PDE solving.
 * \n It has been designed only to solve one problem using differents
 * \nschemes. The problem is the evolution of the temperature
 * \ninside a wall as the function of time.
 * 
 * The PDESolve class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data
 * \n-a solve virtual method which will differ if the scheme is
 * \nimplicit or explicit
 * \n-a method which returns the results of the problems 
 * 
*/
// Abstract base class
class PDESolve
{
protected:
  double Text;
  double Tint;
  double D;
  double dx; // length step
  double dt; // time step
  double L;  // total length
  double T;  // total time
  double alpha;
  double r;
  int nspace;
  int ntime;
  Matrix results;

public:
  // CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty solver.
 * @see PDESolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
  PDESolve(){};

  /**
   * Alternate constructor. Should be used instead of the default one.
   * Build a solver with all the problem data, values and initial conditions.
   * @see PDESolve()
   * @exception invalid_argument ("value must be positive double")
   */
  PDESolve(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */);
  
  // VIRTUAL METHODS

  /**
   * Virtual solve methods
   * solves the problem and writes the results in a matrix
   * 
  */
  virtual void solve(){};

  // ACCESSOR METHODS

  /**
   * Normal public get method
   * get the results matrix
   * @return Matrix. results matrix
   */
  Matrix get_res() const;
};

#endif