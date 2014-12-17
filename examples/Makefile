#BIN=/usr/bin
BIN=../build-no-test/bin
CLANG=$(BIN)/clang
CLANGPP=$(BIN)/clang++
LLVMDIS=$(BIN)/llvm-dis

BUILD=build
SOURCES=$(wildcard *.cpp)
OBJECTS=$(addprefix $(BUILD)/, $(notdir $(SOURCES:.cpp=.o)))
LLVM_OBJS=$(OBJECTS:.o=.ll)
BINS=$(OBJECTS:.o=.bin)
MODBINS=$(OBJECTS:.o=.mod.bin)
UNMANGLED=$(OBJECTS:.o=.unmangled.ll)

all: $(LLVM_OBJS) $(OBJECTS) $(UNMANGLED) $(BINS) $(MODBINS)

%.unmangled.ll: %.ll
	c++filt < $< > $@

%.ll: %.o
	$(LLVMDIS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CLANG) -c -flto $< -o $@

$(BUILD)/%.mod.bin: %.cpp
	$(CLANGPP) $< -o $@

$(BUILD)/%.bin: %.cpp
	clang++ $< -o $@

$(OBJECTS): | $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

.PHONY: clean all

clean:
	rm -rf $(BUILD)/*
