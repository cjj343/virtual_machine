#include <iostream>
#include <string>
#include "vm_parser.h"
#include "vm_writer.h"
#include <vector>
#include <cctype>
  

std::string getFileName();
std::string getFileStub(std::string);

int main(int argc, char* argv[])
{
	Command comType;
	Segment segType;
	vm_writer *writePtr = nullptr;
	vm_parser *ptr = nullptr;
	int index;


	// Check the number of parameters
	if (argc < 2)
	{
		// Tell the user how to run the program
		std::cout << "Usage: " << argv[0] << "<FILE NAME or DIRECTORY>" << std::endl;
		return 1;
	}

	std::string fileName = getFileName();

	//new writer object with file stub
	writePtr = new vm_writer(fileName);
	writePtr->writeBootStrap();
	
	//loop for all the files entered on command line
	for (int fileCount = 1; fileCount < argc; fileCount++)
	{
		std::string s = argv[fileCount];
		std::string fileStub = getFileStub(s);
		writePtr->setFileStub(fileStub);

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

			//get command type
			comType = ptr->commandType();

			switch(comType)
			{
				case C_ARITHMETIC:
				{
					//get segment type
					segType = ptr->arg1();

					//write
					writePtr->writeArithmetic(segType);
				}
				break;

				case C_PUSH:
				{
					//get segment type
					segType = ptr->arg1();

					//get arg2
					index = std::stoi(ptr->arg2());

					//write
					writePtr->writePushPop(comType, segType, index);
				}
				break;

				case C_POP:
				{
					//get segment type
					segType = ptr->arg1();

					//get arg2
					index = std::stoi(ptr->arg2());

					//write
					writePtr->writePushPop(comType, segType, index);
				}
				break;

				case C_LABEL:
				{
					//send to writer
					writePtr->writeLabel(ptr->labelName());
				}
				break;

				case C_RETURN:
				{
					//send to writer
					writePtr->writeReturn();
				}
				break;

				case C_FUNCTION:
				{
					//get the function name and number of args
					std::string functionName = ptr->Function();
					int lcls = std::stoi(ptr->arg2());

					//semd to writer
					writePtr->writeFunction(functionName, lcls);
				}
				break;

				case C_IF:
				{
					//get label name and pass to writer
					writePtr->writeIfGoto(ptr->ifGoto());
				}
				break;

				case C_GOTO:
				{
					//get label name and pass to writer
					writePtr->writeGoto(ptr->Goto());
				}
				break;

				case C_CALL:
				{
					//get args
					int args = std::stoi(ptr->arg2());

					//send function name and args to writer
					writePtr->writeCall(ptr->Call(), args);
				}
				break;

			}
		}

		//memory clean up
		delete ptr;
		ptr = nullptr;
	}

	//memory clean up
	delete writePtr;
	writePtr = nullptr;


	return 0;
}



//get file name from user
std::string getFileName()
{
	std::string fileName;
	std::cout << "Enter the name of the output file: ";
	std::getline(std::cin, fileName);
	return fileName;

}

//get rid of file extension so that file name can be used by writer
std::string getFileStub(std::string s)
{
	std::string fileStub;
	size_t pos = s.find('.');
	fileStub = s.substr(0, pos);
	return fileStub;
}
