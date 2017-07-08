#OBJS specifies your file to be compiled
OBJS = main.c Neural/net.c Neural/neuron.c Neural/weights.c Genetic/population.c Images/trainingset.c Images/testset.c

#CC specifies the compiler
CC = gcc

#COMPILER_FLAGS specifies additional compiler options
COMPILER_FLAGS = -o

#OTHER_FLAGS, if needed (ex. debug, optimization)
OTHER_FLAGS =

#EXEC specifies the executable
EXEC = main.exe

all: $(OBJS)
	$(CC) $(OBJS) $(OTHER_FLAGS) $(COMPILER_FLAGS) $(EXEC)
