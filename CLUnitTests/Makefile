# -----------------------------------------
# BitCrack / CLUnitTests Makefile (patched)
# Gera cltest.cpp via embedcl e compila junto
# -----------------------------------------

NAME    := CLUnitTests
SYMBOL  := _secp256k1_test_cl

# OpenCL include/lib fallback (pode ser injetado pelo Makefile raiz)
OPENCL_INCLUDE ?= /mingw64/include
OPENCL_LIB     ?= /mingw64/lib

# Diretório de binários (a partir deste subdir)
BINDIR ?= ../bin
LIBDIR ?= ../lib

# Fontes de kernel OpenCL
CLSRC  := ../clMath/secp256k1.cl secp256k1test.cl
GENCL  := cltest.cl
GENCPP := cltest.cpp

# Fontes C++ (main + gerado)
CPPSRC := main.cpp $(GENCPP)

# Flags extras
EXTRA_CXXFLAGS ?=
EXTRA_LDFLAGS  ?=

CXXFLAGS ?= -O2 -std=c++11 -DCL_TARGET_OPENCL_VERSION=110
CXXFLAGS += $(EXTRA_CXXFLAGS)

# Includes (iguais ao build raiz)
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

# Bibliotecas necessárias
LIBS = \
  -L$(LIBDIR) \
  -lclutil \
  -lutil \
  -lOpenCL

.PHONY: all clean

all: clunittest.bin

# Gera cltest.cpp a partir dos kernels OpenCL
$(GENCPP): $(CLSRC)
	cat $^ > $(GENCL)
	$(BINDIR)/embedcl $(GENCL) $(GENCPP) $(SYMBOL)

# Compila e linka
clunittest.bin: $(CPPSRC)
	${CXX} -o $@ $(CPPSRC) $(INCLUDE) -I$(OPENCL_INCLUDE) $(CXXFLAGS) $(LIBS) -L$(OPENCL_LIB) $(EXTRA_LDFLAGS)
	mkdir -p $(BINDIR)
	cp $@ $(BINDIR)/clunittest

clean:
	rm -f clunittest.bin $(GENCL) $(GENCPP) *.o *.a
