BIN_FOLDER=.
CLANG=clang
LLVMDIS=llvm-dis

BUILD=build
SOURCES=$(wildcard *.cpp)
OBJECTS=$(addprefix $(BUILD)/, $(notdir $(SOURCES:.cpp=.o)))
LLVM_OBJS=$(OBJECTS:.o=.ll)
UNMANGLED=$(OBJECTS:.o=.unmangled.ll)

all: $(LLVM_OBJS) $(OBJECTS) $(UNMANGLED)

%.unmangled.ll: %.ll
	c++filt < $< > $@

%.ll: %.o
	$(LLVMDIS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CLANG) -c -flto $< -o $@

$(OBJECTS): | $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

.PHONY: clean all

clean:
	rm -rf $(BUILD)/*
