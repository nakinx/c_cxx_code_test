CXX=g++
CXXFLAGS=-Wall -g --std=c++11

all: into_message parsing_specifier

into_message:
	@echo "Initiating the compilation..."

parsing_specifier: parsing_specifier.o
		@echo "Creating the final executable."
		$(CXX) $(CXXSTD) -o parsing_specifier parsing_specifier.o

clean:
	@echo "Cleaning..."
	rm *.o
	rm parsing_specifier
