#include "vm_parser.h"
#include <iostream>
#include <cctype>

//open the vm file and check for open errors
vm_parser::vm_parser(std::string s)
{
	openError = false;
	inputFile.open(s);
	type = CERROR;
	functionName = "";

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

	if (instruction.substr(0, 3) == "add" || instruction.substr(0, 2) == "eq" || instruction.substr(0, 2) == "lt" || instruction.substr(0, 2) == "gt" || instruction.substr(0, 3) == "neg" ||
		instruction.substr(0, 3) == "not" || instruction.substr(0, 3) == "and" || instruction.substr(0, 2) == "or" || instruction.substr(0, 3) == "sub")
	{
		type = C_ARITHMETIC;
		return type;
	}

	else if (instruction.substr(0, 4) == "push")
	{
		type = C_PUSH;
		return type;
	}

	else if (instruction.substr(0, 3) == "pop")
	{
		std::cout << "pop" << std::endl;
		type = C_POP;
		return type;
	}

	else if (instruction.substr(0, 5) == "label")
	{
		type = C_LABEL;
		return type;
	}

	else if (instruction.substr(0, 8) == "function")
	{
		type = C_FUNCTION;
		return type;
	}

	else if (instruction.substr(0, 4) == "goto")
	{
		type = C_GOTO;
		return type;
	}

	else if (instruction.substr(0, 2) == "if")
	{
		type = C_IF;
		return type;
	}

	else if (instruction.substr(0, 6) == "return")
	{
		type = C_RETURN;
		return type;
	}

	else if (instruction.substr(0, 4) == "call")
	{
		type = C_CALL;
		return type;
	}
		
	return CERROR;

}

//find the segment type
Segment vm_parser::arg1()
{
	if (type == C_ARITHMETIC)
	{

		if(instruction.substr(0,3) == "add")
		{
			return ADD;
		}

		else if (instruction.substr(0, 3) == "sub")
		{
			return SUB;
		}

		else if (instruction.substr(0, 3) == "neg")
		{
			return NEG;
		}

		else if (instruction.substr(0, 2) == "eq")
		{
			return EQ;
		}

		else if (instruction.substr(0, 2) == "gt")
		{
			return GT;
		}

		else if (instruction.substr(0, 2) == "lt")
		{
			return LT;
		}

		else if (instruction.substr(0, 3) == "and")
		{
			return AND;
		}

		else if (instruction.substr(0, 2) == "or")
		{
			return OR;
		}

		else if (instruction.substr(0, 3) == "not")
		{
			return NOT;
		}

	}

	else if (type == C_PUSH)
	{
		//find the spaces
		size_t firstSpace = instruction.find(' ');
		size_t secondSpace = instruction.find(' ', firstSpace + 1);


		if (instruction.substr(firstSpace+1, secondSpace - firstSpace - 1) == "argument")
		{
			return ARGUMENT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "local")
		{
			return LOCAL;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "static")
		{
			return STATIC;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "constant")
		{
			return CONSTANT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "this")
		{
			return THIS;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "that")
		{
			return THAT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "pointer")
		{
			return POINTER;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "temp")
		{
			return TEMP;
		}
	}

	else if (type == C_POP)
	{
		//find the spaces
		size_t firstSpace = instruction.find(' ');
		size_t secondSpace = instruction.find(' ', firstSpace + 1);


		if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "argument")
		{
			return ARGUMENT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "local")
		{
			return LOCAL;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "static")
		{
			return STATIC;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "constant")
		{
			return CONSTANT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "this")
		{
			return THIS;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "that")
		{
			return THAT;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "pointer")
		{
			return POINTER;
		}

		else if (instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1) == "temp")
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
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);


	for (size_t i = secondSpace+1; i < instruction.length(); i++)
	{
		if (isdigit(instruction[i]))
		{
			temp += instruction[i];
		}
	}

	return temp;
	
}

//finds the name of a label command
//adds syntax for to be passed to writer
std::string vm_parser::labelName()
{
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);
	std::string labelName = instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1);
	labelName = "(" + functionName + "$" + labelName + ")";
	return labelName;
}

//finds the label for the if-goto statement
//adds syntax to be passed to writer
std::string vm_parser::ifGoto()
{
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);
	std::string ifGoto = instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1);
	ifGoto = "@" + functionName + "$" + ifGoto;
	return ifGoto;
}

//finds the label for the if-goto statement
//adds syntax to be passed to writer
std::string vm_parser::Goto()
{
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);
	std::string Goto = instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1);
	Goto = "@" + functionName + "$" + Goto;
	return Goto;
}

//handles parsing function commands
//adds syntax to be passed to writer
std::string vm_parser::Function()
{
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);

	//create substring without function designation
	functionName = instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1);

	return "(" + functionName + ")";
}

//parses function call commands
std::string vm_parser::Call()
{
	size_t firstSpace = instruction.find(' ');
	size_t secondSpace = instruction.find(' ', firstSpace + 1);

	return instruction.substr(firstSpace + 1, secondSpace - firstSpace - 1);
}

//close the file
vm_parser::~vm_parser()
{
	inputFile.close();
}
