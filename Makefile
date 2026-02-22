# Top-level convenience wrapper around CMake

BUILD_DIR ?= build

.PHONY: all clean checkpatch

all:
	cmake -B $(BUILD_DIR) -S . && cmake --build $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

# GPL dev tool — invoked as a standalone Perl script, never linked into firmware
checkpatch:
	@echo "Running code style check..."
	perl scripts/checkpatch.pl --file $(shell find src include -name '*.[ch]')
