# Define the compiler to use
CC = gcc

# Compiler flags:
# -Iinclude tells the compiler to look in the 'include' directory for header files
CFLAGS = -Iinclude

# Object files to be created
# Specifies the paths in the 'build' directory where the compiled object files will be placed
OBJECTS = build/obst.o build/utils.o

# Additional flags for the compiler
# -w suppresses all warnings
INCFLAGS = -w

# Linker flags
# Empty in this case, but can be used to specify linker options
LDFLAGS =

# Libraries to be included in the linking process
# Empty in this case, but can be used to specify external libraries
LIBS =

# The 'all' target builds the final executable named 'obst'
all: obst

# The 'obst' target depends on the object files listed in $(OBJECTS)
# This rule links the object files into the final executable
# The $(CC) command uses $(LDFLAGS) for linking options, outputs (-o) the executable named 'obst', and uses $(OBJECTS) as input files and $(LIBS) for any libraries
obst: $(OBJECTS)
	$(CC) $(LDFLAGS) -o obst $(OBJECTS) $(LIBS)

# Special target to declare file suffixes that are significant
.SUFFIXES: .c .o

# Rule for building .o files from .c source files
# The pattern rule src/%.c matches C source files in the 'src' directory
# The rule uses the $(CC) command with $(CFLAGS) and $(INCFLAGS) for compiler flags, -c to compile without linking,
# $< is the name of the first prerequisite (the .c file), and -o build/$*.o specifies the output file (in the 'build' directory)
src/%.c:
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o build/$*.o

# The 'count' target uses the 'wc' command to count lines, words, and characters in all .c source files in the 'src' directory and .h header files in the 'include' directory
count:
	wc src/*.c include/*.h

# The 'clean' target removes all compiled object files in the 'build' directory and the final executable 'obst'
# The rm -f command forces removal without prompting for confirmation
clean:
	rm -f build/*.o
	rm -f obst
