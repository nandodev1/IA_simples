MAIN=./source/base/main.cpp
LIB_DEP=/lib/x86_64-linux-gnu/libglut.so /lib/x86_64-linux-gnu/libGL.so
OUT_DIR=./bin
CPP=/usr/bin/g++

all: copilar executar

copilar: ${MAIN}
	${CPP} ${MAIN} -lm ${LIB_DEP} -o ${OUT_DIR}/main -g

executar: ${OUT_DIR}/main
	${OUT_DIR}/main