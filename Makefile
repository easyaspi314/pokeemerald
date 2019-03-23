PREFIX := $(CURDIR)/tools/binutils/bin/arm-none-eabi-
export CPP := gcc -E -x c
export AS  := $(PREFIX)as
export LD := $(PREFIX)ld
export OBJCOPY := $(PREFIX)objcopy

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

TITLE       := POKEMON EMER
GAME_CODE   := BPEE
MAKER_CODE  := 01
REVISION    := 0

SHELL := bash -o pipefail

ROM := pokeemerald.gba
OBJ_DIR := build/emerald

ELF = $(ROM:.gba=.elf)
MAP = $(ROM:.gba=.map)

C_SUBDIR = src
ASM_SUBDIR = asm
DATA_ASM_SUBDIR = data
SONG_SUBDIR = sound/songs
MID_SUBDIR = sound/songs/midi

C_BUILDDIR = $(OBJ_DIR)/$(C_SUBDIR)
ASM_BUILDDIR = $(OBJ_DIR)/$(ASM_SUBDIR)
DATA_ASM_BUILDDIR = $(OBJ_DIR)/$(DATA_ASM_SUBDIR)
SONG_BUILDDIR = $(OBJ_DIR)/$(SONG_SUBDIR)
MID_BUILDDIR = $(OBJ_DIR)/$(MID_SUBDIR)

ASFLAGS := -mcpu=arm7tdmi

CC1             := tools/agbcc/bin/agbcc$(EXE)
override CC1FLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm

CPPFLAGS := -I tools/agbcc/include -I tools/agbcc -I include

LDFLAGS = -Map ../../$(MAP)

LIB := -L ../../tools/agbcc/lib -lgcc -lc

TOOLS_DIR := $(CURDIR)/tools
SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c
GFX := $(TOOLS_DIR)/gbagfx/gbagfx$(EXE)
AIF := $(TOOLS_DIR)/aif2pcm/aif2pcm$(EXE)
MID := $(TOOLS_DIR)/mid2agb/mid2agb$(EXE)
SCANINC := $(TOOLS_DIR)/scaninc/scaninc$(EXE)
PREPROC := $(TOOLS_DIR)/preproc/preproc$(EXE)
RAMSCRGEN := $(TOOLS_DIR)/ramscrgen/ramscrgen$(EXE)
FIX := $(TOOLS_DIR)/gbafix/gbafix$(EXE)
MAPJSON := $(TOOLS_DIR)/mapjson/mapjson$(EXE)

ALL_TOOLS := $(GFX) $(SCANINC) $(PREPROC) $(BIN2C) $(RSFONT) $(AIF) $(RAMSCRGEN) $(MID) $(FIX) $(MAPJSON)
ALL_TOOL_NAMES := gbagfx scaninc preproc bin2c rsfont aif2pcm ramscrgen mapjson

# Check agbcc's version. The '' prevents old agbcc versions
# from eating stdin, they will simply fail with "No such file
# or directory" and exit non-zero. That is why we silence
# stderr and report 0 if it fails.
CC1_REQ_VER := 1
CC1_VER     := $(shell $(CC1) -agbcc-version '' 2>/dev/null || echo 0)

$(shell mkdir -p $(OBJ_DIR) $(C_BUILDDIR) $(ASM_BUILDDIR) $(DATA_ASM_BUILDDIR) $(MID_BUILDDIR) $(SONG_BUILDDIR))
ifneq ($(CC1_REQ_VER),$(CC1_VER))
    $(error Please update agbcc!)
endif

# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PHONY: rom clean compare tidy

C_SRCS := $(wildcard $(C_SUBDIR)/*.c $(C_SUBDIR)/*/*.c $(C_SUBDIR)/*/*/*.c)
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(ASM_BUILDDIR)/%.o,$(ASM_SRCS))

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_SUBDIR)/*.s)
DATA_ASM_OBJS := $(patsubst $(DATA_ASM_SUBDIR)/%.s,$(DATA_ASM_BUILDDIR)/%.o,$(DATA_ASM_SRCS))

SONG_SRCS := $(wildcard $(SONG_SUBDIR)/*.s)
SONG_OBJS := $(patsubst $(SONG_SUBDIR)/%.s,$(SONG_BUILDDIR)/%.o,$(SONG_SRCS))

MID_SRCS := $(wildcard $(MID_SUBDIR)/*.mid)
MID_OBJS := $(patsubst $(MID_SUBDIR)/%.mid,$(MID_BUILDDIR)/%.o,$(MID_SRCS))

OBJS     := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS) $(SONG_OBJS) $(MID_OBJS)
OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJS))

ifeq (,$(filter-out rom,$(MAKECMDGOALS)))
TOOLS_DEP = tools
else
TOOLS_DEP :=
NODEP := 1
endif

# TODO: make this configurable. scaninc is hardcoded to use .d.
DEPDIR := .d

# Disable dependency scanning when NODEP is used for quick building
ifeq ($(NODEP),)
  # Add the .d files to the dependencies.
  $(C_BUILDDIR)/%.o: $(DEPDIR)/$(C_SUBDIR)/%*.d
  $(ASM_BUILDDIR)/%.o: $(DEPDIR)/$(ASM_SUBDIR)/%*.d
  $(DATA_ASM_BUILDDIR)/%.o: $(DEPDIR)/$(DATA_ASM_SUBDIR)/%*.d

  # scaninc puts the deps files into .d/path/file.Td
  C_DEPS        := $(addprefix $(DEPDIR)/, $(C_SRCS:%.c=%.d))
  ASM_DEPS      := $(addprefix $(DEPDIR)/, $(ASM_SRCS:%.s=%.d))
  DATA_DEPS := $(addprefix $(DEPDIR)/, $(DATA_ASM_SRCS:%.s=%.d))
else
  # Dummy things out.
  C_DEPS       :=
  ASM_DEPS     :=
  DATA_DEPS :=
endif

rom: $(ALL_TOOLS) | $(ROM)

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(ROM)
	@$(SHA1) rom.sha1

clean: tidy
	rm -f sound/direct_sound_samples/*.bin
	rm -rf $(DEPDIR)
	rm -f $(SONG_OBJS) $(MID_OBJS) $(MID_SUBDIR)/*.s
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +
	rm -f $(DATA_ASM_SUBDIR)/layouts/layouts.inc $(DATA_ASM_SUBDIR)/layouts/layouts_table.inc
	rm -f $(DATA_ASM_SUBDIR)/maps/connections.inc $(DATA_ASM_SUBDIR)/maps/events.inc $(DATA_ASM_SUBDIR)/maps/groups.inc $(DATA_ASM_SUBDIR)/maps/headers.inc
	find $(DATA_ASM_SUBDIR)/maps \( -iname 'connections.inc' -o -iname 'events.inc' -o -iname 'header.inc' \) -exec rm {} +

tidy:
	rm -f $(ROM) $(ELF) $(MAP)
	rm -r build/*

tools: $(ALL_TOOLS)

include tools.mk

# Dependency scanning. The new scaninc creates similar output
# to gcc -M and only does it when needed.
# If NODEP is enabled, these rules will be orphaned.
$(C_DEPS) $(ASM_DEPS) $(DATA_DEPS): $(SCANINC)
$(DEPDIR)/%.d: %.c
	@$(SCANINC) -I include $<

$(DEPDIR)/%.d: %.s
	@$(SCANINC) -I include $<

.PRECIOUS: $(C_DEPS) $(ASM_DEPS) $(DATA_DEPS)
#.PRECIOUS: $(C_DEPS) $(ASM_DEPS)

# Include our dependencies. This will be empty on NODEP.
-include $(C_DEPS)
-include $(ASM_DEPS)
-include $(DATA_DEPS)

include graphics_file_rules.mk
include map_data_rules.mk
include spritesheet_rules.mk
include songs.mk

%.s: ;
%.png: ;
%.pal: ;
%.aif: ;

%.1bpp: %.png | $(GFX) ; $(GFX) $< $@
%.4bpp: %.png | $(GFX) ; $(GFX) $< $@
%.8bpp: %.png | $(GFX) ; $(GFX) $< $@
%.gbapal: %.pal | $(GFX) ; $(GFX) $< $@
%.gbapal: %.png | $(GFX) ; $(GFX) $< $@
%.lz: % | $(GFX); $(GFX) $< $@
%.rl: % | $(GFX); $(GFX) $< $@
sound/direct_sound_samples/cry_%.bin: sound/direct_sound_samples/cry_%.aif | $(AIF); $(AIF) $< $@ --compress
sound/%.bin: sound/%.aif | $(AIF); $(AIF) $< $@


$(C_BUILDDIR)/libc.o: CC1 := tools/agbcc/bin/old_agbcc
$(C_BUILDDIR)/libc.o: CC1FLAGS := -O2

$(C_BUILDDIR)/siirtc.o: CC1FLAGS := -mthumb-interwork

$(C_BUILDDIR)/agb_flash.o: CC1FLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_1m.o: CC1FLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_mx.o: CC1FLAGS := -O -mthumb-interwork

$(C_BUILDDIR)/m4a.o: CC1 := tools/agbcc/bin/old_agbcc

$(C_BUILDDIR)/record_mixing.o: CC1FLAGS += -ffreestanding

ifeq ($(DINFO),1)
override CFLAGS += -g
endif

$(C_BUILDDIR)/%.o : $(C_SUBDIR)/%.c $(C_DEP) | $(PREPROC)
	$(PREPROC) $(CPPFLAGS) -c charmap.txt $< | $(CC1) $(CC1FLAGS) | $(AS) $(ASFLAGS) -o $@

$(ASM_BUILDDIR)/%.o: $(ASM_SUBDIR)/%.s $(ASM_DEP)
	$(AS) $(ASFLAGS) -o $@ $<

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s $(DATA_DEP) | $(PREPROC)
	$(PREPROC) -n -c charmap.txt $< | $(CPP) -P -I include - | $(AS) $(ASFLAGS) -o $@

$(SONG_BUILDDIR)/%.o: $(SONG_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -I sound -o $@ $<

$(OBJ_DIR)/sym_bss.ld: sym_bss.txt | $(RAMSCRGEN)
	$(RAMSCRGEN) .bss $< ENGLISH > $@

$(OBJ_DIR)/sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt) | $(RAMSCRGEN)
	$(RAMSCRGEN) COMMON $< ENGLISH -c $(C_BUILDDIR),common_syms > $@

$(OBJ_DIR)/sym_ewram.ld: sym_ewram.txt | $(RAMSCRGEN)
	$(RAMSCRGEN) ewram_data $< ENGLISH > $@

$(OBJ_DIR)/ld_script.ld: ld_script.txt $(OBJ_DIR)/sym_bss.ld $(OBJ_DIR)/sym_common.ld $(OBJ_DIR)/sym_ewram.ld
	cd $(OBJ_DIR) && sed "s#tools/#../../tools/#g" ../../ld_script.txt > ld_script.ld

$(ELF): $(OBJ_DIR)/ld_script.ld | $(OBJS)
	cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ld_script.ld -o ../../$@ $(OBJS_REL) $(LIB)

$(ROM): $(ELF) | $(FIX)
	$(OBJCOPY) -O binary $< $@
	$(FIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent
