CXX ?= g++
CXXFLAGS_V = -std=c++17 -Wall -Wextra -g -O3
CXXFLAGS = -std=c++17 -g -O3
INCLUDES = -I include/ -I /usr/local/include

SRC_PATH = src
BUILD_PATH = build
TARGET_EXEC ?= runner

SOURCES = $(shell find $(SRC_PATH) -name '*.cpp' | sort -k 1nr | cut -f2-)
OBJECTS = $(SOURCES: $(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
DEPS = $(OBJECTS:.o=.d)

MKDIR_P = mkdir -p

.PHONY: run
run: all
	@echo "\n\n\n"
	./build/runner

.PHONY: all
all: $(BUILD_PATH)/$(TARGET_EXEC)

$(BUILD_PATH)/$(TARGET_EXEC): $(OBJECTS) dirs
	@echo "START PROCESS 1"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $@
	@echo "END PROCESS 1"

$(BUILD_PATH)/%.cpp.o: %.cpp
	@echo "START PROCESS 2"
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "END PROCESS 2"

.PHONY: dirs
dirs:
	@echo "START dirs------"
	@echo "Creating Directories."
	@mkdir -p $(BUILD_PATH)
	@echo "END dirs------"

.PHONY: clean
clean:
	@echo "START clean------"
	@echo "Cleaning Project."
	@rm -rf $(BUILD_PATH)
	@echo "END clean------"

