CXX=g++
CXXFLAGS=-Wall -Wextra -g -save-temps --std=c++11

all: intomessage define

intomessage:
	@echo "Initiating the compilation..."

define: define.o
			@echo "Creating the final executable."
			$(CXX) $(CXXSTD) -o define define.o

clean:
	@echo "Cleaning..."
	-rm *.o
	-rm *.ii
	-rm *.s
	-rm define
