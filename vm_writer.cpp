#include "vm_writer.h"
#include <iostream>


vm_writer::vm_writer(std::string s)
{
	ltCount = 1;
	eqCount = 1;
	gtCount = 1;
	retCount = 1;

	//create file name with asm extension
	s = s + ".asm";
	s = "C:\\Users\\Cameron\\Documents\\nand2tetris\\projects\\08\\FunctionCalls\\StaticsTest\\" + s;

	//open file for writing
	outputFile.open(s);
}

//writes push and pop commands for all segments
void vm_writer::writePushPop(Command c, Segment s, int x)
{
	if (c == C_PUSH)
	{
		if (s == CONSTANT)
		{
			outputFile << "//writing push constant" << std::endl;
			outputFile << '@' << x <<  std::endl;
			outputFile << "D=A" <<  std::endl;
			outputFile << "@SP" <<  std::endl;
			outputFile << "A=M" <<  std::endl;
			outputFile << "M=D" <<  std::endl;
			outputFile << "@SP" <<  std::endl;
			outputFile << "M=M+1" <<  std::endl;
		}

		else if (s == LOCAL)
		{
			outputFile << "//writing push local" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "M=M-D" << std::endl;

		}
		else if (s == ARGUMENT)
		{
			outputFile << "//writing push arg" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}
		else if (s == THIS)
		{
			outputFile << "//writing push this" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}
		else if (s == THAT)
		{
			outputFile << "//writing push that" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" <<  std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}

		else if (s == TEMP)
		{
			outputFile << "//writing push temp" << std::endl;
			outputFile << "@R5" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
		}

		else if (s == POINTER)
		{
			outputFile << "//writing push ptr" << std::endl;
			outputFile << "@R3" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
		}

		else if (s == TEMP)
		{
			outputFile << "//writing push ptr" << std::endl;
			outputFile << "@R5" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
		}

		else if (s == STATIC)
		{
			outputFile << "//writing push static" << std::endl;
			outputFile << "@" << fileStub << '.' << x << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M+1" << std::endl;
		}
	}

	else if (c == C_POP)
	{
		if (s == LOCAL)
		{
			outputFile << "//writing pop local" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@LCL" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}
		else if (s == ARGUMENT)
		{
			outputFile << "//writing pop arg" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@ARG" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}
		else if (s == THIS)
		{
			outputFile << "//writing pop this" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THIS" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}
		else if (s == THAT)
		{
			outputFile << "//writing pop that" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "M=M+D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@THAT" << std::endl;
			outputFile << "M=M-D" << std::endl;
		}

		else if (s == TEMP)
		{
			outputFile << "//writing pop temp" << std::endl;
			outputFile << "@R5" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;

		}

		else if (s == POINTER)
		{
			outputFile << "//writing pop ptr" << std::endl;
			outputFile << "@R3" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
		}

		else if (s == TEMP)
		{
			outputFile << "//writing temp" << std::endl;
			outputFile << "@R5" << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << '@' << x << std::endl;
			outputFile << "D=D+A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
		}

		else if (s == STATIC)
		{
			outputFile << "//writing pop static" << std::endl;
			outputFile << "@" << fileStub << '.' << x << std::endl;
			outputFile << "D=A" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "M=D" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "M=M-1" << std::endl;
			outputFile << "@SP" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "D=M" << std::endl;
			outputFile << "M=0" << std::endl;
			outputFile << "@R13" << std::endl;
			outputFile << "A=M" << std::endl;
			outputFile << "M=D" << std::endl;
		}

	}

}

//writes arithmetic commands
void vm_writer::writeArithmetic(Segment s)
{

	if (s == ADD)
	{
		outputFile << "//writing add" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D+M" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;
	}

	else if (s == SUB)
	{
		outputFile << "//writing sub" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M-D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;
	}

	else if (s == EQ)
	{
		outputFile << "//writing eq" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D-M" <<  std::endl;
		outputFile << "@EQUAL" << eqCount <<  std::endl;
		outputFile << "D;JEQ" <<  std::endl;
		outputFile << "@NOTEQUAL" << eqCount <<  std::endl;
		outputFile << "D;JNE" <<  std::endl;
		outputFile << "(EQUAL" << eqCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=-1" <<  std::endl;
		outputFile << "@ENDEQ" << eqCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(NOTEQUAL" << eqCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@ENDEQ" << eqCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(ENDEQ" << eqCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;

		eqCount++;
	}

	else if (s == LT)
	{
		outputFile << "//writing lt" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D-M" <<  std::endl;
		outputFile << "@LESSTHAN" << ltCount <<  std::endl;
		outputFile << "D;JGT" <<  std::endl;
		outputFile << "@NOTLESS" << ltCount <<  std::endl;
		outputFile << "D;JLE" <<  std::endl;
		outputFile << "(LESSTHAN" << ltCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=-1" <<  std::endl;
		outputFile << "@ENDLT" << ltCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(NOTLESS" << ltCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@ENDLT" << ltCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(ENDLT"<< ltCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;

		ltCount++;
	}

	else if (s == GT)
	{
		outputFile << "//writing gt" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D-M" <<  std::endl;
		outputFile << "@GREATERTHAN" << gtCount <<  std::endl;
		outputFile << "D;JLT" <<  std::endl;
		outputFile << "@NOTGREATER" << gtCount <<  std::endl;
		outputFile << "D;JGE" <<  std::endl;
		outputFile << "(GREATERTHAN" << gtCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=-1" <<  std::endl;
		outputFile << "@ENDGT" << gtCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(NOTGREATER" << gtCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@ENDGT" << gtCount <<  std::endl;
		outputFile << "0;JEQ" <<  std::endl;
		outputFile << "(ENDGT" << gtCount << ")" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;

		gtCount++;
	}

	else if (s == NOT) 
	{
		outputFile << "//writing not" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=!M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;
	}

	else if (s == NEG)
	{
		outputFile << "//writing neg" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "D=D-M" <<  std::endl;
		outputFile << "D=D-M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;		
	}

	else if (s == AND)
	{
		outputFile << "//writing and" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D&M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;
	}

	else if (s == OR)
	{
		outputFile << "//writing or" << std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=M" <<  std::endl;
		outputFile << "M=0" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M-1" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "A=M" <<  std::endl;
		outputFile << "D=D|M" <<  std::endl;
		outputFile << "M=D" <<  std::endl;
		outputFile << "@SP" <<  std::endl;
		outputFile << "M=M+1" <<  std::endl;
	}
}

void vm_writer::writeLabel(std::string s)
{
	outputFile << "//writing label" << std::endl;
	outputFile << s << std::endl;
}

void vm_writer::writeIfGoto(std::string s)
{
	outputFile << "//writing if-goto" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "AM=M-1" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "M=0" << std::endl;
	outputFile << s << std::endl;
	outputFile << "D;JNE" << std::endl;
}

void vm_writer::writeGoto(std::string s)
{
	outputFile << "//writing goto" << std::endl;
	outputFile << s << std::endl;
	outputFile << "0;JMP" << std::endl;
}

void vm_writer::writeFunction(std::string functionName, int lcls) 
{
	outputFile << "//writing function" << std::endl;
	outputFile << functionName << std::endl;

	for (int i = 0; i < lcls; i++)
	{
		writePushPop(C_PUSH, CONSTANT, 0);
	}

}

void vm_writer::writeReturn()
{
	outputFile << "//writing return" << std::endl;

	//MAKE "FRAME" THE START OF LOCAL VARIABLES
	outputFile << "@LCL" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "M=D" << std::endl;

	//SUBTRACT 5 TO GET BACK TO BEGGINING OF ARGS
	outputFile << "@5" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "A=M-D" << std::endl;
	outputFile << "D=M" << std::endl;

	//MAKE THIS THE RETURN ADDRESS
	outputFile << "@RET" << std::endl;
	outputFile << "M=D" << std::endl;

	//GET THE RETURN VALUE
	outputFile << "@SP" << std::endl;
	outputFile << "AM=M-1" << std::endl;
	outputFile << "D=M" << std::endl;

	//PLACE THE RETURN VALUE AT THE ADDRESSS OF THE LAST ARG
	outputFile << "@ARG" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;

	//RESET STACK PTR TO BEFORE FUNCTION CALL
	outputFile << "@ARG" << std::endl;
	outputFile << "D=M+1" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=D" << std::endl;
	//outputFile << "M=M+1" << std::endl;

	//RESTORE THAT
	outputFile << "@1" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "A=M-D" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@THAT" << std::endl;
	outputFile << "M=D" << std::endl;

	//RESTORE THIS
	outputFile << "@2" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "A=M-D" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@THIS" << std::endl;
	outputFile << "M=D" << std::endl;

	//RESTORE ARG
	outputFile << "@3" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "A=M-D" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@ARG" << std::endl;
	outputFile << "M=D" << std::endl;

	//RESTORE LCL
	outputFile << "@4" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@FRAME" << std::endl;
	outputFile << "A=M-D" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@LCL" << std::endl;
	outputFile << "M=D" << std::endl;

	//JUMP TO RETURN
	outputFile << "@RET" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "0;JMP" << std::endl;

}

void vm_writer::writeCall(std::string functionName, int args)
{
	//save return address
	outputFile << "@RETURN" << retCount << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=M+1" << std::endl;

	//save LCL
	outputFile << "@LCL" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=M+1" << std::endl;

	//save ARG
	outputFile << "@ARG" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=M+1" << std::endl;

	//save THIS
	outputFile << "@THIS" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=M+1" << std::endl;

	//save THAT
	outputFile << "@THAT" << std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=M+1" << std::endl;

	//deal with args
	outputFile << "@" << args << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "D=M-D" << std::endl;
	outputFile << "@" << 5 << std::endl;
	outputFile << "D=D-A" << std::endl;
	outputFile << "@ARG" << std::endl;
	outputFile << "M=D" << std::endl;

	//deal with local
	outputFile << "@SP" <<  std::endl;
	outputFile << "D=M" << std::endl;
	outputFile << "@LCL" << std::endl;
	outputFile << "M=D" << std::endl;

	//go to function
	outputFile << "@" << functionName << std::endl;
	outputFile << "0;JMP" << std::endl;

	//make a label
	outputFile << "(RETURN" << retCount << ")" << std::endl;
	retCount++;
}

void vm_writer::writeBootStrap()
{
	//initialize SP to 256
	outputFile << "@256" << std::endl;
	outputFile << "D=A" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "M=D" << std::endl;
	outputFile << "@START" << std::endl;
	outputFile << "0; JMP" << std::endl;
	outputFile << "(MAKETRUE)" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "AM = M - 1" << std::endl;
	outputFile << "M = -1" << std::endl;
	outputFile << "@SP" << std::endl;
	outputFile << "AM = M + 1" << std::endl;
	outputFile << "@R15" << std::endl;
	outputFile << "A=M" << std::endl;
	outputFile << "D; JMP" << std::endl;
	outputFile << "(START)" << std::endl;
	writeCall("Sys.init", 0);

}

void vm_writer::setFileStub(std::string s)
{
	fileStub = s;
}

//close the file
vm_writer::~vm_writer()
{
	outputFile.close();
}
