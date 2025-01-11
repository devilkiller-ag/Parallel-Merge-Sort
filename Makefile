CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -I. -Isrc/app/sorting


MAIN_TARGET = parallel_merge_sort


MAIN_SRC = src/app/main.cpp \
           src/app/sorting/mergeSort.cpp


MAIN_OBJ = $(MAIN_SRC:.cpp=.o)


all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(MAIN_TARGET)

.PHONY: clean all
