#include <iostream>
#include <string>
#include "vm_parser.h"
#include "vm_writer.h"
#include <vector>
#include <cctype>

std::string fileStub(std::string);

int main(int argc, char* argv[])
{
	Command comType;
	Segment segType;
	vm_writer *writePtr = nullptr;
	vm_parser *ptr = nullptr;
	int index;
	std::string stub;

	// Check the number of parameters
	if (argc < 2)
	{
		// Tell the user how to run the program
		std::cout << "Usage: " << argv[0] << "<FILE NAME or DIRECTORY>" << std::endl;
		return 1;
	}
	
	//loop for all the files entered on command line
	for (int fileCount = 1; fileCount < argc; fileCount++)
	{
		std::string s = argv[fileCount];
		stub = fileStub(s);

		//new parser object with initialized with file name
		ptr = new vm_parser(s);

		//check for file open errors, exit if error
		if (ptr->errorCheck())
		{
			std::cout << "There was an error opening the file" << std::endl;
			return 1;
		}

		//new writer object with file stub
		writePtr = new vm_writer(stub);

		//while there are more commands
		while (ptr->hasMoreCommands())
		{
			//advacne to the next instruction
			ptr->advance();

			//get command type
			comType = ptr->commandType();

			//get segment type
			segType = ptr->arg1();

			//if command is an arithmetic command
			if (comType == C_ARITHMETIC)
			{
				writePtr->writeArithmetic(segType);
			}

			//if command is a push or pop command
			else if (comType == C_PUSH || comType == C_POP)
			{
				index = std::stoi(ptr->arg2());
				writePtr->writePushPop(comType, segType, index);
			}

		}

		//memory clean up
		delete ptr;
		ptr = nullptr;

		delete writePtr;
		writePtr = nullptr;
	}

	return 0;
}

//get rid of file extension for writing
std::string fileStub(std::string s)
{
	std::size_t pos = s.find('.');
	std::string stub = s.substr(0, pos);
	std::cout << stub << std::endl;
	return stub;

}