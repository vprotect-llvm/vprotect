#BIN=/usr/bin
BIN=../build-no-test/bin
CLANG=$(BIN)/clang
CLANGPP=$(BIN)/clang++
LLVMDIS=$(BIN)/llvm-dis
OPT=$(BIN)/opt

BUILD=build
SOURCES=$(wildcard *.cpp)
OBJECTS=$(addprefix $(BUILD)/, $(notdir $(SOURCES:.cpp=.o)))
MODOBJS=$(OBJECTS:.o=.mod.o)
LLVM_OBJS=$(OBJECTS:.o=.ll)
MODLLVM_OBJS=$(OBJECTS:.o=.mod.ll)
BINS=$(OBJECTS:.o=.bin)
MODBINS=$(OBJECTS:.o=.mod.bin)
UNMANGLED=$(OBJECTS:.o=.unmangled.ll)
MODUNMANGLED=$(MODOBJS:.o=.unmangled.ll)

all: $(LLVM_OBJS) $(OBJECTS) $(UNMANGLED) $(BINS) $(MODBINS) $(MODLLVM_OBJS) $(MODOBJS) $(MODUNMANGLED)

%.unmangled.ll: %.ll
	c++filt < $< > $@

%.ll: %.o
	$(LLVMDIS) $< -o $@

%.mod.o: %.o
	$(OPT) -vt-protect $< -o $@

$(BUILD)/%.o: %.cpp $(CLANG)
	$(CLANG) -c -flto $< -o $@

$(BUILD)/%.mod.bin: %.cpp $(CLANGPP)
	$(CLANGPP) -O0 -g $< -o $@

$(BUILD)/%.bin: %.cpp
	clang++ -O0 -g $< -o $@

$(OBJECTS): | $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

.PHONY: clean all

clean:
	rm -rf $(BUILD)/*
