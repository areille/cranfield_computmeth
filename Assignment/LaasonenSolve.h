#include "PDEImplicit.h"

/**
 * A subclass of PDE Implicit solver, specialized for Richardson scheme.
 * 
 * The Laasonen class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \nonly with Laasonen scheme.
 * \n-a advance method which take to the next time and space step.
*/
class LaasonenSolve : public PDEImplicit
{
public:

// CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty Laasonen scheme solver.
 * @see LaasonenSolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
    LaasonenSolve() {};

    /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an Laasonen solver with all the problem data, values and initial conditions.
   * @see LaasonenSolve()
   * @exception invalid_argument ("value must be positive double")
   */
    LaasonenSolve(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */) : PDEImplicit(D, dx, dt, L, T, Text, Tint) {};
    
    // METHODS

    /**
   * Laasonen scheme advance method
   * advance in time and space
   * 
  */
    void advance();
};