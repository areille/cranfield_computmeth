#include "PDEImplicit.h"

/**
 * A subclass of PDE Implicit solver, specialized for Richardson scheme.
 * 
 * The Crank Nicholson class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \nonly with Crank-Nicholson scheme.
 * \n-a advance method which take to the next time and space step.
*/
class CrankNicholsonSolve : public PDEImplicit
{
public:

// CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty Crank-Nicholson scheme solver.
 * @see CrankNicholsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
    CrankNicholsonSolve() {};

    /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an Crank Nicholson solver with all the problem data, values and initial conditions.
   * @see CrankNicholsonSolve()
   * @exception invalid_argument ("value must be positive double")
   */
    CrankNicholsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint) : PDEImplicit(D, dx, dt, L, T, Text, Tint) {};
    
    // METHODS

    /**
   * Crank-Nicholson scheme advance method
   * advance in time and space
   * 
  */
    void advance();
};