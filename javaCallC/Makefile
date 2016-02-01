JAVAHOME := /home/craboyang/soft/java/jdk1.8.0_60
IDIR := ${JAVAHOME}/include ${JAVAHOME}/include/linux

all: TestJni.o libtestjni.so
TestJni.o : TestJni.c jni_TestJni.h
	gcc -Wall -fPIC -c TestJni.c -I${IDIR}
libtestjni.so : TestJni.o
	gcc -Wall -rdynamic -shared -o $@ TestJni.o
