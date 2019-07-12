CXX=g++
CXXFLAGS=-Wall -g --std=c++11

all: into_message trim

into_message:
	@echo "Initiating the compilation..."

trim: trim.o
		@echo "Creating the final executable."
		$(CXX) $(CXXSTD) -o trim trim.o

clean:
	@echo "Cleaning..."
	rm *.o
	rm trim
