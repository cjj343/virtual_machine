#ifndef VM_WRITER_H
#define VM_WRITER_H
#pragma once
#include <fstream>
#include "vm_parser.h"

class vm_writer
{
private:
	std::ofstream outputFile;
	int eqCount = 1;
	int ltCount = 1;
	int gtCount = 1;

public:
	vm_writer();
	void writePushPop(Command c, Segment s, int x);
	void writeArithmetic(Segment);
	~vm_writer();
};
#endif

