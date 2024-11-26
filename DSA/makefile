CXX = g++
CFLAGS = -std=c++2a -g -Wall -fsanitize=address -fsanitize=leak
LDFLAGS = -fsanitize=address -fsanitize=leak
OBJ_DIR = obj
DEP_DIR = dep
BIN_DIR = bin

# 自动查找所有源文件
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)
TARGETS = $(SRCS:%.cpp=$(BIN_DIR)/%)

all: $(TARGETS)

# 自动生成 target 规则
$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS)

# 编译 .o 文件并生成依赖文件
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CFLAGS) -MMD -MP -c $< -o $@
	mv $(@:.o=.d) $(DEP_DIR)/

# 自动创建目录
$(OBJ_DIR) $(DEP_DIR) $(BIN_DIR):
	mkdir -p $@

# 清理构建生成的文件
clean:
	$(RM) -r $(BIN_DIR) $(OBJ_DIR) $(DEP_DIR)

# 包含依赖文件
-include $(DEPS)

.PHONY: all clean
