CXX = g++
CFLAGS = -std=c++2a -g -Wall
TARGETS = bin/insertsort bin/selectionsort bin/mergesort
SRCS = insertsort.cpp selectionsort.cpp mergesort.cpp 
OBJ_DIR = obj
DEP_DIR = dep
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)

all: $(TARGETS)

bin/insertsort: $(OBJ_DIR)/insertsort.o | bin
	$(CXX) $(CFLAGS) $(OBJ_DIR)/insertsort.o -o bin/insertsort

bin/selectionsort: $(OBJ_DIR)/selectionsort.o | bin
	$(CXX) $(CFLAGS) $(OBJ_DIR)/selectionsort.o -o bin/selectionsort

bin/mergesort: $(OBJ_DIR)/mergesort.o | bin
	$(CXX) $(CFLAGS) $(OBJ_DIR)/mergesort.o -o bin/mergesort

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CFLAGS) -MMD -MP -c $< -o $@
	mv $(@:.o=.d) $(DEP_DIR)/

$(OBJ_DIR) $(DEP_DIR) bin:
	mkdir -p $@

clean:
	$(RM) -r bin obj dep

-include $(DEPS)

.PHONY: all clean
