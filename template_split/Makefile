.PHONY: info clean

MAJOR:=1
MINOR:=0
NAME:=template_split
MODE:=release
VERSION:=$(MAJOR).$(MINOR)
GXXVERSION:= $(shell g++ --version | head -n 1)

CXXFLAGS=-fPIC -O3 -Wall -Werror --std=c++11
LDFLAGS=

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)

all: info $(NAME)

debug: CXXFLAGS=-fPIC -O3 -Wall -Werror -ggdb --std=c++11
debug: MODE:=debug
debug: info $(NAME)

info:
	@echo "============================== Compilation Info ==============================="
	@echo "Compiler: $(GXXVERSION)"
	@echo "CXX Flags: $(CXXFLAGS)"
	@echo "LD Flags: $(LDFLAGS)"
	@echo "Sources: $(SRCS)"
	@echo "Objects: $(OBJS)"
	@echo "Lib: $(NAME)"
	@echo "Version: $(VERSION)"
	@echo "Mode: $(MODE)"
	@echo "==============================================================================="

$(NAME): $(OBJS)
	@echo "====== Compiling Application ======"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -I. $(LDFLAGS)

%.o: %.d
	@echo "====== Creating Object:" $@ "======"
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) -o $@

clean:
	@echo "====== Cleaning Project ======"
	-rm -r *.o *.d *.ii *.s *.so*
	-rm $(NAME)
