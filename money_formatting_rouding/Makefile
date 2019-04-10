CXX=g++
CXXFLAGS=-Wall -g --std=c++11

all: intomessage moneyformattingrounding

intomessage:
	@echo "Initiating the compilation..."

moneyformattingrounding: money_formatting_rouding.o
			@echo "Creating the final executable."
			$(CXX) $(CXXSTD) -o money_formatting_rouding money_formatting_rouding.o

clean:
	@echo "Cleaning..."
	rm *.o
	rm money_formatting_rouding
