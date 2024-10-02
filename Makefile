CXX := g++
CXXFLAGS := -O0 -g -Wall -std=c++14 -Werror=return-type

# enable asan
#CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer
#LDFLAGS  += -fsanitize=address -fno-omit-frame-pointer

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: main.out
	./main.out

clean:
	rm -f *.out
