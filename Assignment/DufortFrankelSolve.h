#include "PDEExplicit.h"

/**
 * A subclass of PDE Explicit solver, specialized for Dufort-Frankel scheme.
 * 
 * The Dufort-Frankel class provides:
 * \n-basic constructors for creating a Solver object with all initial
 * \nconditions and data (not meant to be used)
 * \nonly with Dufort-Frankel scheme.
 * \n-a advance method which take to the next time and space step.
*/
class DufortFrankelSolve : public PDEExplicit
{
  public:
  // CONSTRUCTORS

  /**
 * Default constructor. Initialize an empty Dufort scheme solver.
 * @see DufortFrankelSolve(double D, double dx, double dt, double L, double T, double Text, double Tint)
 * 
*/
    DufortFrankelSolve() {};

     /**
   * Alternate constructor. Should be used instead of the default one.
   * Build an Dufort solver with all the problem data, values and initial conditions.
   * @see DufortFrankelSolve()
   * @exception invalid_argument ("value must be positive double")
   */
    DufortFrankelSolve(double D /**< double. Diffusivity of the wall */, double dx /**< double. Space step */, double dt /**< double. Time step */, double L /**< double. Thickness of the wall */, double T /**< double. Study total time */, double Text /**< double. External temperature */, double Tint /**< double. Initial temperature */) : PDEExplicit(D, dx, dt, L, T, Text, Tint) {};
    
    // METHODS

    /**
   * Dufort scheme advance method
   * advance at step k in time and step l in space
   * 
  */
    double advance(int k /**< int. Time step you want to access */, int l /**< int. Space step you want to access */) const;
};