// ME 701 - Homework 9 - Problem 1

#include <petscsnes.h>
#include "problem1_residual.hh"

int main(int argc,char **args)
{
  int option = 0;

  // Declare variables.
  SNES snes;
  KSP ksp;
  PC pc;
  Vec T, r;
  Mat J, J_mf;
  int ierr;

  // Initialize PETSc.
  ierr = PetscInitialize(&argc, &args, NULL, NULL);

  // Get "n" from the command line.
  int n = 10; // this is the default value!
  ierr = PetscOptionsGetInt(NULL,NULL,"-n", &n, NULL);
  
  // Set up the nonlinear solver.
  ierr = SNESCreate(PETSC_COMM_SELF, &snes);

  // Create the vectors for the solution and residual, i.e.,
  // T and r=f(T), respectively.
  ierr = VecCreateSeq(PETSC_COMM_SELF, n, &T);
  ierr = VecDuplicate(T, &r);

  // Provide an initial guess.
  double *T_a;
  ierr = VecGetArray(T, &T_a);
  // ...
  ierr = VecRestoreArray(T, &T_a);

  // Set the residual function.
  ierr = SNESSetFunction(snes, r, residual, NULL);

  ierr = MatCreateSNESMF(snes, &J_mf);
  ierr = SNESSetJacobian(snes, J_mf, J, SNESComputeJacobianDefault, NULL);

  // Last chance to override behavior.
  ierr = SNESSetFromOptions(snes);

  // Time to solve
  ierr = SNESSolve(snes, NULL, T);

  // This prints the temperatures to standard output.
  ierr = VecView(T, PETSC_VIEWER_STDOUT_WORLD);
  
  // Here, you should open a file a print x and T.
  

  // Clean-up time!
  ierr = VecDestroy(&T); CHKERRQ(ierr);
  ierr = VecDestroy(&r); CHKERRQ(ierr); 
  ierr = SNESDestroy(&snes);CHKERRQ(ierr);
  ierr = PetscFinalize();
  return ierr;
}

