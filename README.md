# Homework 9

In this homework, you will leverage the numerical libraries discussed
in class (1) to solve a relevant engineering problem and (2) to understand
the basic performance of different implementations of a standard linear
algebraic operation (in this case, the matrix-vector operation).

## Problem 1 - 5 points

Consider the one-dimensional, steady-state, head-conduction equation
in *Cartesian* coordinates:

$$
  \frac{d}{dx} k(x, T(x)) \frac{dT}{dx} = Q(x) \, ,
$$

subject to 

$$
  \frac{dT}{dx}\Bigg|_{x=0} = 0 \, ,
$$

and the 

$$
  -k(1, T(L)) \frac{dT}{dx} \Bigg|_{x=L} = h[T_{\infty} - T(L)] \, .
$$

Here, $T$ is temperature (in [K]), $x$ is a spatial coordinate, 
$k(x, T(x))$ is the space- and temperature-dependent thermal
conductivity [W/m-K], $h$ is the heat-transfer coefficient [W/m$^2$-K],
$T_{\infty}$ is the bulk temperature of the working coolant, and
$Q(x)$ is the space-dependent heat-generation rate [W/m$^3$]$

As stated, the set of equations represents an element of width $2L$ heated
and cooled symmetrically by a moving fluid.  This could be a heater that
heats water under forced-flow conditions.  Such a heater could be a fuel
element in a nuclear reactor (but there are other applications with similar
geometries).

For this problem, assume the following:

  - $L = 0.01$ m (i.e., 1 cm)
  - $h = 30000$ [W/m$^2$-K]
  - $k(x, T(x)) =  (0.1148+2.475\cdot 10^{-4} T(x))^{-1} + 0.0132 e^{0.00188 T(x)}$
  - $Q = 3.5\cdot 10^{8}$ [W/m$^3$]

Because $k$ depends on $T(x)$, this problem is a nonlinear boundary-value
problem.  You will use PETSc to solve it using the Jacobian-free, Newton-Krylov
method.

### Part 1


## Problem 2 - 2 points

Follow the discussion in the video (Lecture 37 in Canvas) 
and use the example Fortran code to
plot the observed FLOPS as a function of `n` for the row-major, column-major,
built-in BLAS, and MKL version of the matrix-vector operation.  A Makefile
is provided in the Problem 2 folder.  You need only set the appropriate
paths and install certain packages (see the Makefile for instruction).

To make just one of the executables, do, e.g.,
 
```
make driver-mv-col-x 
```

which uses the column-major, Fortran version of the matrix-vector operation.

You are to produce a Python script that runs each of these, captures the output,
and produces a plot of the FLOPS as a function of `n` for each executable.


