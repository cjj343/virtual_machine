#ifndef VM_WRITER_H
#define VM_WRITER_H
#include <fstream>
#include <string>
#include "vm_parser.h"

class vm_writer
{
private:
	std::ofstream outputFile;
	std::string fileName;
	int eqCount;
	int ltCount;
	int gtCount;

public:
	vm_writer(std::string);
	void writePushPop(Command c, Segment s, int x);
	void writeArithmetic(Segment);
	void writeLabel(std::string);
	void writeIfGoto(std::string);
	void writeGoto(std::string);
	~vm_writer();
};
#endif

