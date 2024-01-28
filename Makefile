# Executable names
TEST_EXE = s21_containers.bin
GCOV_EXE = s21_containers_gcov.bin

# Detected OS
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
# FLAGS_ADDITIONAL = -Wdeprecated-declaration
LIBS_ADDITIONAL = 
CMD_OPEN = open
endif

ifeq ($(OS), Linux)
LIBS_ADDITIONAL = -lm -lpthread -lrt
CMD_OPEN = xdg-open
endif

# For example: make test MODE=4
# Before changing mode: make clean
# Maximum compiler errors
MAX_ERRORS = 10
# Default value=1
MODE?=1
ifeq ($(MODE), 2)
	# With fsanitizer
	LFLAGS=-g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover \
	-fstack-protector -fanalyzer
	CFLAGS_TESTS=-Wall -Werror -Wextra -c -std=c++17 -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable \
	-fno-sanitize-recover -fstack-protector -fmax-errors=$(MAX_ERRORS) -O3
	CFLAGS += $(CFLAGS_TESTS) -fanalyzer
else 
	ifeq ($(MODE), 3)
		# For valgrind
		LFLAGS=-g
		CFLAGS=-Wall -Werror -Wextra -c -std=c++17 -g -fmax-errors=$(MAX_ERRORS) -O3
		CFLAGS_TESTS = $(CFLAGS)
	else 
		# Default
		LFLAGS= 
		CFLAGS=-Wall -Werror -Wextra -c -std=c++17 -pedantic -fmax-errors=$(MAX_ERRORS) -O3
		CFLAGS_TESTS = $(CFLAGS)
	endif
endif

# 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lgtest -lgtest_main -lstdc++ $(LIBS_ADDITIONAL)
LIBS_GCOV = $(LIBS) -lgcov

# Directories
OBJ_DIR = obj
GCOV_OBJ_DIR = obj/gcov
INC_DIR = include
TESTS_DIR = tests
REPORT_DIR = report


# Main code
# ALL_INC_DIRS = $(shell find $(INC_DIR) -type d)
ALL_INC_DIRS = include/ \
				include/associative \
				include/associative/utils \
				include/sequence

# INC_H = $(shell find $(INC_DIR) -maxdepth 5 -name "*.h")
INC_H = include/associative/s21_set.h \
		include/associative/utils/rb_tree.h \
		include/associative/utils/rb_tree_iter.h \
		include/associative/utils/mypair.h \
		include/associative/utils/rb_tree_node.h \
		include/associative/s21_map.h \
		include/associative/s21_multiset.h \
		include/s21_containers.h \
		include/s21_containersplus.h \
		include/sequence/s21_queue.h \
		include/sequence/s21_array.h \
		include/sequence/s21_stack.h \
		include/sequence/s21_vector.h \
		include/sequence/s21_list.h 

# Test code
# ALL_TESTS_DIRS = $(shell find $(TEST_DIR) -type d)
ALL_TESTS_DIRS =	tests/ \
					tests/utils \
					tests/s21_stl \
					tests/s21_stl/vector \
					tests/s21_stl/list \
					tests/s21_stl/rb_tree \
					tests/s21_stl/array \
					tests/s21_stl/multiset \
					tests/s21_stl/map \
					tests/s21_stl/set \
					tests/s21_stl/queue \
					tests/s21_stl/stack

# TESTS_C = $(notdir $(shell find $(TESTS_DIR) -maxdepth 5 -name "*.cc"))
TESTS_C = 	tests/gt_main.cc \
			tests/s21_stl/vector/gt_vector_all.cc \
			tests/s21_stl/list/gt_list_all.cc \
			tests/s21_stl/rb_tree/gt_tree_2_module_iterators.cc \
			tests/s21_stl/rb_tree/gt_tree_1_module_member_function.cc \
			tests/s21_stl/rb_tree/gt_tree_4_module_modifiers.cc \
			tests/s21_stl/rb_tree/gt_tree_3_module_capacity.cc \
			tests/s21_stl/rb_tree/gt_tree_5_module_lookup.cc \
			tests/s21_stl/array/gt_array_all.cc \
			tests/s21_stl/multiset/gt_multiset_all.cc \
			tests/s21_stl/map/gt_map_5_module_lookup.cc \
			tests/s21_stl/map/gt_map_3_module_capacity.cc \
			tests/s21_stl/map/gt_map_2_module_element_access.cc \
			tests/s21_stl/map/gt_map_1_module_members_function.cc \
			tests/s21_stl/map/gt_map_4_module_modifiers.cc \
			tests/s21_stl/set/gt_set_5_module_lookup.cc \
			tests/s21_stl/set/gt_set_2_module_iterators.cc \
			tests/s21_stl/set/gt_set_4_module_modifiers.cc \
			tests/s21_stl/set/gt_set_3_module_capacity.cc \
			tests/s21_stl/set/gt_set_1_module_members_function.cc \
			tests/s21_stl/queue/gt_queue_all.cc \
			tests/s21_stl/stack/gt_stack_all.cc

# TESTS_H = $(shell find $(TESTS_DIR) -maxdepth 5 -name "*.h")
TESTS_H = 	tests/gt_main.h \
			tests/s21_stl/vector/gt_vector.h \
			tests/s21_stl/list/gt_list.h \
			tests/s21_stl/rb_tree/gt_tree.h \
			tests/s21_stl/array/gt_array.h \
			tests/s21_stl/multiset/gt_multiset.h \
			tests/s21_stl/map/gt_map.h \
			tests/s21_stl/set/gt_set.h \
			tests/s21_stl/queue/gt_queue.h \
			tests/s21_stl/stack/gt_stack.h

TESTS_O = $(addprefix $(OBJ_DIR)/, $(notdir $(TESTS_C:%.cc=%.o)))

# gcov
GCOV_TESTS_O = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(TESTS_C:%.cc=%.o)))

# cpplint/cppcheck
# ALL_SOURCES_FILES = $(shell find . -type f | grep -E "\.(cpp|cc|h|hpp)$$")
ALL_SOURCES_FILES = $(INC_H) $(TESTS_C) $(TESTS_H)

# Specifying the list of directories in which make performs the search
vpath %.cc $(ALL_INC_DIRS) : $(ALL_TESTS_DIRS)
vpath %.o $(OBJ_DIR)

# Targets
all: test

test: build	
	./$(TEST_EXE)

build: $(OBJ_DIR) $(TESTS_O) 
	$(CC) $(LFLAGS) $(TESTS_O) $(LIBS) -o $(TEST_EXE)

gcov_report: $(GCOV_OBJ_DIR) $(OBJ_DIR) $(REPORT_DIR) $(GCOV_TESTS_O)
	$(CC) $(LFLAGS) $(GCOV_TESTS_O) $(LIBS_GCOV) -o ./$(GCOV_EXE)
	./$(GCOV_EXE)
	gcov -o $(GCOV_OBJ_DIR) $(INC_H)
	lcov -b ./ -d $(GCOV_OBJ_DIR) --gcov-tool /usr/bin/gcov -c -o report.info --no-external
	genhtml -o $(REPORT_DIR) report.info
	$(CMD_OPEN) $(REPORT_DIR)/index.html 

$(OBJ_DIR)/%.o : %.cc $(INC_H) $(TESTS_H)
	$(CC) $(CFLAGS_TESTS) -o $@ $< 

$(GCOV_OBJ_DIR)/%.o : %.cc $(INC_H) $(TESTS_H)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(GCOV_OBJ_DIR):
	mkdir -p $(GCOV_OBJ_DIR)
$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -f report.info manual.bin
	rm -f ./$(GCOV_EXE) ./$(TEST_EXE)
	rm -f *.a *.o *.bin

rebuild: clean all

style_fix:
	clang-format -i --style="{BasedOnStyle: Google}" $(ALL_SOURCES_FILES)
cpplint: 
	clang-format -n --style="{BasedOnStyle: Google}" --verbose $(ALL_SOURCES_FILES)
cppcheck:
	cppcheck --enable=all --force --suppress=missingIncludeSystem --language=c++ $(ALL_SOURCES_FILES)
leaks:
	leaks --atExit -- ./$(TEST_EXE)
valgrind: build
	valgrind  --tool=memcheck --track-fds=yes --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(TEST_EXE)

.PHONY: all clean rebuild cpplint cppcheck leaks valgrind
