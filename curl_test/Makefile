CXX=g++
CFLAGS=-Wall -ggdb3 -std=c++11

all: into_message curl_test

into_message:
	@echo "Initiating the compilation..."

curl_test: curl_test.o
		@echo "Creating the final executable."
		$(CXX) -o curl_test curl_test.o -l curl

clean:
	@echo "Cleaning..."
	rm *.o
	rm curl_test
