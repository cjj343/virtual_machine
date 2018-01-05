#include <iostream>
#include <string>
#include "vm_parser.h"
#include "vm_writer.h"
#include <vector>
#include <cctype>


int main(int argc, char* argv[])
{
	Command comType;
	Segment segType;
	vm_writer asmFile;
	vm_parser *ptr = nullptr;
	int index;

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

		//new parser object with initialized with file name
		ptr = new vm_parser(s);

		//check for file open errors, exit if error
		if (ptr->errorCheck())
		{
			std::cout << "There was an error opening the file" << std::endl;
			return 1;
		}

		//while there are more commands
		while (ptr->hasMoreCommands())
		{
			//advacne to the next instruction
			ptr->advance();

			comType = ptr->commandType();
			segType = ptr->arg1();

			if (comType == C_ARITHMETIC)
			{
				asmFile.writeArithmetic(segType);
			}

			else if (comType == C_PUSH || comType == C_POP)
			{
				index = std::stoi(ptr->arg2());
				asmFile.writePushPop(comType, segType, index);
			}

		}

		delete ptr;
		ptr = nullptr;
	}

	return 0;
}