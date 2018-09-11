ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

CC ?= gcc
TOOLS_DIR ?= ..
GBAFIX_DIR := $(basename $(TOOLS_DIR)/gbafix)
FIX ?= $(GBAFIX_DIR)/gbafix$(EXE)

.PHONY: gbafix_all gbafix_clean clean

GBAFIX_SRCS = $(GBAFIX_DIR)/gbafix.c

gbafix_all: $(GBAFIX)
$(FIX): $(GBAFIX_SRCS)
	$(CC) $(GBAFIX_SRCS) -o $@ $(LDFLAGS)

clean: gbafix_clean
gbafix_clean:
	$(RM) $(FIX)
