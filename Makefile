BUILDIR=${PWD}
ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

all:
	g++ -c -std=c++17 -I include ${ROOT_DIR}/src/Mastermind.cxx ${ROOT_DIR}/src/PlayMastermind.cxx -I .
	g++ -o ${ROOT_DIR}/game ${BUILDIR}/Mastermind.o ${BUILDIR}/PlayMastermind.o
	mkdir -p ${BUILDIR}/objects
	mv *.o ${BUILDIR}/objects/

clean:
	rm ${BUILDIR}/*.o
	rm ${ROOT_DIR}/game
