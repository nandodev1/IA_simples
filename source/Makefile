MAIN=main.cpp
MAIN_TESTE=main_teste.cpp
LIB_DEP=/lib/x86_64-linux-gnu/libglut.so /lib/x86_64-linux-gnu/libGL.so
OUT_DIR=./
CPP=/usr/bin/g++
LIB=${PWD}

all: copilar executar

copilar: ${MAIN}
	${CPP} ${MAIN} -lm ${LIB_DEP} -o ${OUT_DIR}main -g

executar: ${OUT_DIR}main
	${OUT_DIR}main base
	
executar_teste: ${OUT_DIR}main_teste
	${OUT_DIR}main_teste
	
teste: ${MAIN_TESTE}
	${CPP} ${MAIN_TESTE} -lm ${LIB_DEP} -o ${OUT_DIR}main_teste -g
