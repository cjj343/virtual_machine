CXX = g++
CXXFLAGS =  -std=c++11
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors

OBJS =  vm_main.o vm_parser.o vm_writer.o
SRCS =  vm_main.cpp vm_parser.cpp vm_writer.cpp
HEADERS = vm_parser.h vm_writer.h

vector: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o vm

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

clean:
	rm *.o vm
