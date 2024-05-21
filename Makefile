MAIN=./source/base/main.cpp
MAIN_TESTE=./source/IA/main_teste.cpp
LIB_DEP=/lib/x86_64-linux-gnu/libglut.so /lib/x86_64-linux-gnu/libGL.so
OUT_DIR=./bin
CPP=/usr/bin/g++

all: copilar executar

copilar: ${MAIN}
	mkdir ${OUT_DIR}
	${CPP} ${MAIN} -lm ${LIB_DEP} -o ${OUT_DIR}/main -g

executar: ${OUT_DIR}/main
	${OUT_DIR}/main
	
executar_teste: ${OUT_DIR}/main_teste
	${OUT_DIR}/main_teste
	
teste: ${MAIN_TESTE}
	${CPP} ${MAIN_TESTE} -lm ${LIB_DEP} -o ${OUT_DIR}/main_teste -g
