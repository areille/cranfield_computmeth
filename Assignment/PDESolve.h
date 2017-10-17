#include "matrix.h"

using namespace std;

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
  PDESolve();
  PDESolve(double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k, int l) const = 0;
  void solve();
  Matrix get_res() const;
};

class DufortFrankelSolve : public PDESolve
{
public:
  DufortFrankelSolve();
  DufortFrankelSolve(double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k, int l) const;
};

class RichardsonSolve : public PDESolve
{
public:
  RichardsonSolve();
  RichardsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k, int l) const;
};

class LaasonenSolve : public PDESolve
{
public:
  LaasonenSolve();
  LaasonenSolve(double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k, int l) const;
};

class CrankNicholsonSolve : public PDESolve
{
public:
  CrankNicholsonSolve();
  CrankNicholsonSolve(double D, double dx, double dt, double L, double T, double Text, double Tint);
  virtual double advance(int k, int l) const;
};