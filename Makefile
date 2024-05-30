MAIN=./source/base/main.cpp
MAIN_TESTE=./source/base/main_teste.cpp
LIB_DEP=/lib/x86_64-linux-gnu/libglut.so /lib/x86_64-linux-gnu/libGL.so
OUT_DIR=./bin
CPP=/usr/bin/g++
LIB=./source/

all: copilar executar

copilar: ${MAIN}
	if [ ! -d ${OUT_DIR} ]; then mkdir ${OUT_DIR};fi
	${CPP} ${MAIN} -I ${LIB} -lm ${LIB_DEP} -o ${OUT_DIR}/main -g

executar: ${OUT_DIR}/main
	${OUT_DIR}/main
	
executar_teste: ${OUT_DIR}/main_teste
	${OUT_DIR}/main_teste
	
teste: ${MAIN_TESTE}
	${CPP} ${MAIN_TESTE} -lm ${LIB_DEP} -o ${OUT_DIR}/main_teste -g
