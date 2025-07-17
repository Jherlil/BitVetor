NAME=bitsecp256k1
SRC=$(filter-out bench.cpp,$(wildcard *.cpp))
OBJS=$(SRC:.cpp=.o)

all:    ${SRC}
	for file in ${SRC} ; do\
	 ${CXX} -c $$file ${INCLUDE} ${CXXFLAGS} ${LIBS} -lcryptoutil;\
	done
	mkdir -p ${LIBDIR}
	ar rvs ${LIBDIR}/lib$(NAME).a ${OBJS}

bench: all bench.cpp
	${CXX} bench.cpp ${INCLUDE} ${CXXFLAGS} -L${LIBDIR} -l$(NAME) -lcryptoutil -o ${BINDIR}/bench_bitsecp256k1

clean:
	rm -rf *.o
