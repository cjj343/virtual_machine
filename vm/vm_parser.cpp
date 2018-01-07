#include "vm_parser.h"
#include <iostream>
#include <cctype>

//open the vm file and check for open errors
vm_parser::vm_parser(std::string s)
{
	openError = false;
	inputFile.open(s);
	type = CERROR;

	if (inputFile.fail())
	{
		openError = true;
	}
}

//returns status of file open procedure
bool vm_parser::errorCheck()
{
	return openError;
}

//checks to see if there are more commands in the file
bool vm_parser::hasMoreCommands()
{

	if (!(inputFile.eof()))
	{
		return true;
	}

	return false; 
}

//advances to the next instruction
//deletes any comments
//ignores blank lines
void vm_parser::advance()
{

	bool blankLine = true;
	
	//loop while line is a comment or blank line and file has more commands
	do
	{
		blankLine = true;

		getline(inputFile, instruction);

		//find and erase comments
		if (instruction.find("//") != std::string::npos)
		{
			instruction.erase(instruction.find("//"));
		}

		//test for blank line
		for (size_t i = 0; i < instruction.length(); i++)
		{
			if (instruction[i] != ' ' || instruction[i] != '\t' || instruction[i] != '\n')
			{
				blankLine = false;
			}
		}

	} while (blankLine && hasMoreCommands());

}

//find the command type
Command vm_parser::commandType()
{
	size_t found = instruction.find("add");
	if (found != std::string::npos) 
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("eq");
	if (found != std::string::npos) 
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("lt");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("gt");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("neg");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("not");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("and");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("or");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("sub");
	if (found != std::string::npos)
	{
		type = C_ARITHMETIC;
		return type;
	}

	found = instruction.find("push");
	if (found != std::string::npos)
	{
		type = C_PUSH;
		return type;
	}

	found = instruction.find("pop");
	if (found != std::string::npos)
	{
		type = C_POP;
		return type;
	}

	return CERROR;

}

//find the segment type
Segment vm_parser::arg1()
{
	if (type == C_ARITHMETIC)
	{
		size_t found = instruction.find("add");
		if (found != std::string::npos)
		{
			return ADD;
		}

		found = instruction.find("sub");
		if (found != std::string::npos)
		{
			return SUB;
		}

		found = instruction.find("neg");
		if (found != std::string::npos)
		{
			return NEG;
		}

		found = instruction.find("eq");
		if (found != std::string::npos)
		{
			return EQ;
		}

		found = instruction.find("gt");
		if (found != std::string::npos)
		{
			return GT;
		}

		found = instruction.find("lt");
		if (found != std::string::npos)
		{
			return LT;
		}

		found = instruction.find("and");
		if (found != std::string::npos)
		{
			return AND;
		}

		found = instruction.find("or");
		if (found != std::string::npos)
		{
			return OR;
		}

		found = instruction.find("not");
		if (found != std::string::npos)
		{
			return NOT;
		}
	}

	else if (type == C_PUSH || type == C_POP)
	{
		size_t found = instruction.find("argument");
		if (found != std::string::npos)
		{
			return ARGUMENT;
		}

		found = instruction.find("local");
		if (found != std::string::npos)
		{
			return LOCAL;
		}

		found = instruction.find("static");
		if (found != std::string::npos)
		{
			return STATIC;
		}

		found = instruction.find("constant");
		if (found != std::string::npos)
		{
			return CONSTANT;
		}

		found = instruction.find("this");
		if (found != std::string::npos)
		{
			return THIS;
		}

		found = instruction.find("that");
		if (found != std::string::npos)
		{
			return THAT;
		}

		found = instruction.find("pointer");
		if (found != std::string::npos)
		{
			return POINTER;
		}

		found = instruction.find("temp");
		if (found != std::string::npos)
		{
			return TEMP;
		}
	}

	return SERROR;
}

//find the last arge
std::string vm_parser::arg2()
{
	std::string temp;

	if (type == C_PUSH || type == C_POP)
	{
		for (size_t i = 0; i < instruction.length(); i++)
		{
			if (isdigit(instruction[i]))
			{
				temp += instruction[i];
			}
		}

		return temp;
	}

	return "";
}

//close the file
vm_parser::~vm_parser()
{
	inputFile.close();
}
