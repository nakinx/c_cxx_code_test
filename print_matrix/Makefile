C=gcc
CFLAGS=-Wall -g 

all: into_message print_matrix

into_message:
	@echo "Initiating the compilation..."

print_matrix: print_matrix.o
		@echo "Creating the final executable."
		$(C) -o print_matrix print_matrix.o

clean:
	@echo "Cleaning..."
	rm *.o
	rm print_matrix
