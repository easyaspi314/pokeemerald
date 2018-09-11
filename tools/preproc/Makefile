ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

TOOLS_DIR ?= ..
PREPROC_DIR := $(basename $(TOOLS_DIR)/preproc)
PREPROC ?= $(PREPROC_DIR)/preproc$(EXE)
CC := gcc

CFLAGS := -std=c99 -O2 -Wall -Wno-switch -Werror
LDFLAGS := -s
PREPROC_SRCS := $(addprefix $(PREPROC_DIR)/,asm_file.c c_file.c charmap.c preproc.c string_parser.c \
	utf8.c stack.c my_string.c hash_map.c)
PREPROC_OBJS := $(PREPROC_SRCS:.c=.o)
PREPROC_HEADERS := $(addprefix $(PREPROC_DIR)/,asm_file.h c_file.h char_util.h charmap.h preproc.h string_parser.h \
	utf8.h stack.h hash_map.h)

.PHONY: preproc_all clean preproc_clean

preproc_all: $(PREPROC)

$(PREPROC): $(PREPROC_OBJS) $(PREPROC_DIR)/ucpp/libucpp.a
	$(CC) $(PREPROC_OBJS) $(PREPROC_DIR)/ucpp/libucpp.a -o $@ $(LDFLAGS)

$(PREPROC_DIR)/ucpp/libucpp.a:
	$(MAKE) -C $(PREPROC_DIR)/ucpp STAND_ALONE=

$(PREPROC_OBJS): %.o: %.c $(PREPROC_HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

clean: preproc_clean
preproc_clean:
	$(RM) $(PREPROC)
	$(MAKE) -C $(PREPROC_DIR)/ucpp clean
	$(RM) $(PREPROC_OBJS)
