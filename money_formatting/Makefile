CXX=g++
CXXFLAGS=-Wall -g --std=c++11

all: into_message money_formatting

into_message:
	@echo "Initiating the compilation..."

money_formatting: money_formatting.o
		@echo "Creating the final executable."
		$(CXX) $(CXXSTD) -o money_formatting money_formatting.o

clean:
	@echo "Cleaning..."
	rm *.o
	rm money_formatting
