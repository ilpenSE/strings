CC = gcc
CFLAGS = -g -DSTR_IMPLEMENTATION

STR_H = ../str.h
BUILD = build

LIFECYCLE = lifecycle
TRIMS = trims
APPENDS = appends
CHARS = chars
VIEWS = views
SPLIT = split
EQUALS = equals

TARGETS = $(LIFECYCLE) \
          $(APPENDS) \
          $(TRIMS) \
          $(CHARS) \
          $(VIEWS) \
					$(SPLIT) \
					$(EQUALS)

.PHONY: all clean
all: $(BUILD) $(TARGETS)

$(BUILD):
	mkdir -p $(BUILD)

%: %.c $(STR_H) | $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $<

clean:
	rm -rf $(BUILD)

