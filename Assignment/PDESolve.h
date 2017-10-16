#include "matrix.h"

using namespace std;

// Abstract base class
class PDESolve
{
protected:
  double Text;
  double Tint;
  Matrix m;
  double D;
  double dx; // length step
  double dt; // time step
  double L;  // total length
  double T;  // total time
public:
  PDESolve();
  PDESolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint);
  Matrix getMatrix() const;
  virtual double advance(int k) const = 0;
};

class DufortFrankelSolve : public PDESolve
{
public:
  DufortFrankelSolve();
  DufortFrankelSolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k) const;
};

class RichardsonSolve : public PDESolve
{
public:
  RichardsonSolve();
  RichardsonSolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k) const;
};

class LaasonenSolve : public PDESolve
{
public:
  LaasonenSolve();
  LaasonenSolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k) const;
  std::cout << "Coucou" << endl;
};

class CrankNicholsonSolve : public PDESolve
{
public:
  CrankNicholsonSolve();
  CrankNicholsonSolve(Matrix m, double D, double dx, double dt, double L, double T, double Text, double Tint);
};