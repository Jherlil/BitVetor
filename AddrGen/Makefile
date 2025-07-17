# -----------------------------------------
# BitCrack / AddrGen Makefile (patched)
# MSYS2 MinGW fix: add -lbcrypt for RNG
# -----------------------------------------

CPPSRC := $(wildcard *.cpp)

# Diretório dos binários relativos ao root do repo
BINDIR ?= ../bin

# Diretório das libs geradas no build root (ajuste se necessário)
LIBDIR ?= ../lib

# Inclui do CUDA (herdado do build raiz; não obrigatório p/ AddrGen, mas preservado)
CUDA_INCLUDE ?= /usr/local/cuda/include

# Flags extras opcionais
EXTRA_CXXFLAGS ?=
EXTRA_LDFLAGS  ?=

# Flags padrão de compilação
CXXFLAGS ?= -O2 -std=c++11
CXXFLAGS += $(EXTRA_CXXFLAGS)

# Includes comuns (mesmos usados no build root)
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

# Bibliotecas (ordem importa no MinGW: dependidos antes, deps depois)
LIBS = \
  -L$(LIBDIR) \
  -laddressutil \
  -lbitsecp256k1 \
  -lsecp256k1 \
  -lcryptoutil \
  -lutil \
  -lcmdparse \
  -lbcrypt

# -----------------------------------------
# Regras
# -----------------------------------------
all:
	${CXX} -o addrgen.bin $(CPPSRC) $(INCLUDE) -I$(CUDA_INCLUDE) $(CXXFLAGS) $(LIBS) $(EXTRA_LDFLAGS)
	mkdir -p $(BINDIR)
	cp addrgen.bin $(BINDIR)/addrgen

clean:
	rm -f addrgen.bin
