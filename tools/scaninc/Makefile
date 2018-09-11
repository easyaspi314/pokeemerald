ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

TOOLS_DIR ?= ..
SCANINC_DIR := $(basename $(TOOLS_DIR)/scaninc)
SCANINC ?= scaninc$(EXE)
CXX = g++

CXXFLAGS = -Wall -Werror -std=c++11 -fno-exceptions -fno-rtti -O2 -s

SCANINC_SRCS := $(addprefix $(SCANINC_DIR)/,scaninc.cpp c_file.cpp asm_file.cpp formatter.cpp)
SCANINC_OBJS := $(SCANINC_SRCS:.cpp=.o)

SCANINC_HEADERS := $(addprefix $(SCANINC_DIR)/,scaninc.h asm_file.h c_file.h formatter.h)

.PHONY: scaninc_all clean scaninc_clean

scaninc_all: $(SCANINC)
	@:

$(SCANINC_OBJS): %.o: %.cpp $(SCANINC_HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SCANINC): $(SCANINC_OBJS)
	$(CXX) $(CXXFLAGS) $(SCANINC_OBJS) -o $@ $(LDFLAGS)

clean: scaninc_clean
scaninc_clean:
	$(RM) $(SCANINC) $(SCANINC_OBJS)
