# ==============================================================================
# SystemC Project Makefile
# ==============================================================================

# --- Compiler & Standard ---
CXX        := g++
CXXFLAGS   := -std=c++20 -Wall -Wextra

# --- SystemC Paths ---
SYSTEMC_HOME ?= /usr/local/systemc-3.0.2
INC        := -I$(SYSTEMC_HOME)/include
LIBS       := -L$(SYSTEMC_HOME)/lib64 -lsystemc
RPATH      := -Wl,-rpath,$(SYSTEMC_HOME)/lib64

# --- Project Files ---
# Add your .cpp source files here (space-separated)
SRCS       := hello.cpp

# Output binary name
TARGET     := hello

# --- Build Modes ---
# Use: make DEBUG=1 to enable debug mode
ifdef DEBUG
    CXXFLAGS += -g -DSC_DEBUG
else
    CXXFLAGS += -O2
endif

# ==============================================================================
# Targets
# ==============================================================================

.PHONY: all clean run help

## all: Build the project (default)
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INC) $(RPATH) $(SRCS) $(LIBS) -o $(TARGET)
	@echo "✔ Build successful → ./$(TARGET)"

## run: Build and run the simulation
run: all
	@echo "--- Running $(TARGET) ---"
	./$(TARGET)

## clean: Remove compiled binary
clean:
	rm -f $(TARGET)
	@echo "✔ Cleaned"

## help: Show available targets
help:
	@echo ""
	@echo "Usage: make [target] [OPTIONS]"
	@echo ""
	@echo "Targets:"
	@grep -E '^## ' Makefile | sed 's/## /  /'
	@echo ""
	@echo "Options:"
	@echo "  DEBUG=1   Enable debug symbols and SC_DEBUG"
	@echo ""
	@echo "Examples:"
	@echo "  make              # Build"
	@echo "  make run          # Build and run"
	@echo "  make DEBUG=1      # Build with debug info"
	@echo "  make clean        # Remove binary"
	@echo "  make SRCS='a.cpp b.cpp' TARGET=sim  # Custom files"
