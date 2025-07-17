# -----------------------------
# BitCrack / KeyFinder Makefile
# Build targets for CUDA / OpenCL
# Patched for MSYS2 MinGW (BCrypt)
# -----------------------------

# Source files in this dir
CPPSRC := $(wildcard *.cpp)

# Provide fallback include/lib paths if not passed in from top-level Makefile
CUDA_INCLUDE ?= /usr/local/cuda/include
CUDA_LIB     ?= /usr/local/cuda/lib64

# For MSYS2 MinGW OpenCL packages:
OPENCL_INCLUDE ?= /mingw64/include
OPENCL_LIB     ?= /mingw64/lib

# Binaries output dir (relative to repo root)
BINDIR ?= ../bin

# Allow user to inject extra flags (useful for debugging)
EXTRA_CXXFLAGS ?=
EXTRA_LDFLAGS  ?=

# Common compiler flags
CXXFLAGS ?= -O2 -std=c++11 -DCL_TARGET_OPENCL_VERSION=110
CXXFLAGS += $(EXTRA_CXXFLAGS)

# Common include dirs (from repo root)
INCLUDE = \
  -I../util \
  -I../AddressUtil \
  -I../CmdParse \
  -I../CryptoUtil \
  -I../KeyFinderLib \
  -I../CLKeySearchDevice \
  -I../CudaKeySearchDevice \
  -I../cudaMath \
  -I../clUtil \
  -I../cudaUtil \
  -I../secp256k1lib \
  -I../Logger \
  -I../embedcl

# Default libs common to both (except backend-specific below)
# NOTE: order matters on MinGW, list deps after users
COMMON_LIBS = \
  -lkeyfinder \
  -laddressutil \
  -lbitsecp256k1 \
  -lsecp256k1 \
  -lcryptoutil \
  -llogger \
  -lutil \
  -lcmdparse

# ---------------------------------------------------------
# Main rule: build whatever was requested (CUDA, OpenCL)
# ---------------------------------------------------------
all:
ifeq ($(BUILD_CUDA), 1)
	${CXX} -DBUILD_CUDA -o cuKeyFinder.bin $(CPPSRC) $(INCLUDE) -I$(CUDA_INCLUDE) $(CXXFLAGS) $(LIBS) -L$(CUDA_LIB) \
	$(COMMON_LIBS) -lcudautil -lCudaKeySearchDevice -lcudadevrt -lcudart $(EXTRA_LDFLAGS)
	mkdir -p $(BINDIR)
	cp cuKeyFinder.bin $(BINDIR)/cuBitCrack
endif

ifeq ($(BUILD_OPENCL), 1)
	${CXX} -DBUILD_OPENCL -o clKeyFinder.bin $(CPPSRC) $(INCLUDE) -I$(OPENCL_INCLUDE) $(CXXFLAGS) $(LIBS) -L$(OPENCL_LIB) \
	$(COMMON_LIBS) -lCLKeySearchDevice -lclutil -lOpenCL -lbcrypt $(EXTRA_LDFLAGS)
	# Se der erro de socket no futuro: adicione -lws2_32 -luser32 -lkernel32 ao final da linha acima
	mkdir -p $(BINDIR)
	cp clKeyFinder.bin $(BINDIR)/clBitCrack
endif

clean:
	rm -f cuKeyFinder.bin
	rm -f clKeyFinder.bin
