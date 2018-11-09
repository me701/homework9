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
  Vec z, r;
  Mat J, J_mf;
  int ierr;

  // Initialize PETSc.
  ierr = PetscInitialize(&argc, &args, NULL, NULL);
  
  // Set up the nonlinear solver.
  ierr = SNESCreate(PETSC_COMM_SELF, &snes);

  // Create the vectors for the solution and residual, i.e.,
  // z and r=f(z), respectively.
  ierr = VecCreateSeq(PETSC_COMM_SELF, 2, &z);
  ierr = VecDuplicate(z, &r);

  // Provide an initial guess.
  double *z_a;
  ierr = VecGetArray(z, &z_a);
  // ...
  ierr = VecRestoreArray(z, &z_a);

  // Set the residual function.
  ierr = SNESSetFunction(snes, r, residual, NULL);


  ierr = MatCreateSNESMF(snes, &J_mf);
  ierr = SNESSetJacobian(snes, J_mf, J, SNESComputeJacobianDefault, NULL);

  // Last chance to override behavior.
  ierr = SNESSetFromOptions(snes);

  // Time to solve
  ierr = SNESSolve(snes, NULL, z);

  ierr = VecView(z, PETSC_VIEWER_STDOUT_WORLD);
  
  // Clean-up time!
  ierr = VecDestroy(&z); CHKERRQ(ierr);
  ierr = VecDestroy(&r); CHKERRQ(ierr); 
  ierr = SNESDestroy(&snes);CHKERRQ(ierr);
  ierr = PetscFinalize();
  return ierr;
}

