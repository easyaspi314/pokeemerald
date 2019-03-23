#
# tools.mk: Makes tools.
#
# We use it this way so it's easier for make to track dependencies,
# while still being able to reuse the individual Makefiles.
#
# 'clean' rules are automatically added.

# We specify this so the included Makefiles know where they
# are building.
#
# The individual Makefiles will set this to .. if it's not set,
# and expect their files to be found in $(TOOLS_DIR)/tool/
# e.g. $(TOOLS_DIR)/preproc
TOOLS_DIR := tools

# Phonied in the root Makefile
mid2agb: $(MID)
gbagfx: $(GFX)
scaninc: $(SCANINC)
preproc: $(PREPROC)
bin2c: $(BIN2C)
rsfont: $(RSFONT)
aif2pcm: $(AIF)
ramscrgen: $(RAMSCRGEN)
fix: $(FIX)
mapjson: $(MAPJSON)

include tools/mid2agb/Makefile
include tools/gbagfx/Makefile
include tools/scaninc/Makefile
include tools/preproc/Makefile
include tools/bin2c/Makefile
include tools/rsfont/Makefile
include tools/aif2pcm/Makefile
include tools/ramscrgen/Makefile
include tools/gbafix/Makefile
include tools/mapjson/Makefile
