#include <cstdio>

#include "problem1_residual.hh"

int residual(SNES snes, Vec T, Vec f, void *ctx)
{

  int n;
  VecGetSize(T, &n);  // Get the number of temperatures.  This should be 
                      // useful for any implementation you might choose to
                      // use.


  // You need to implement this!  Feel free to add additional functions to
  // facilitate your construction of the residual (but you don't need more than
  // just this one to complete the job).  You can build a matrix (like in 
  // example1 from the course repository), or use regular arrays as needed.
  // Just get'er done!



  return 0;
}

