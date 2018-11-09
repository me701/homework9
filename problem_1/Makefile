TARGET     = problem1
OBJFILES   = problem1.o problem1_residual.o
CLEANFILES = $(TARGET)

include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	${CXXLINKER} -o $(TARGET) $(OBJFILES) ${PETSC_LIB}

