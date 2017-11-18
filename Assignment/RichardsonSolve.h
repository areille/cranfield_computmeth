#include "PDEExplicit.h"

/**
 * A subclass of PDE Explicit solver, specialized for Richardson scheme.
 * 
 * The PDE explicit class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \n-a solve method which will solve the problem with all input values,
 * \nonly with Richardson scheme.
 * \n-a advance method which take to the next time and space step.
*/
class RichardsonSolve : public PDEExplicit
{
  public:

  // CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty Richardson scheme solver.
 * @see RichardsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
    RichardsonSolve() {};

    /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an Richardson solver with all the problem data, values and initial conditions.
   * @see RichardsonSolve()
   * @exception invalid_argument ("value must be positive double")
   */
    RichardsonSolve(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */) {};

    // METHODS

    /**
   * Richardson scheme advance method
   * advance at step k in time and step l in space
   * 
  */
    double advance(int k /**< int. Time step you want to access */, int l /**< int. Space step you want to access */) const;
};