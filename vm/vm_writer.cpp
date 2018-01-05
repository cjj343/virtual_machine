#include "vm_writer.h"
#include <iostream>


vm_writer::vm_writer()
{
	outputFile.open("C:\\Users\\Cameron\\nand2tetris\\projects\\07\\MemoryAccess\\BasicTest\\BasicTest.asm");
}

void vm_writer::writePushPop(Command c, Segment s, int x)
{
	if (c == C_PUSH)
	{
		if (s == CONSTANT)
		{
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
	}

	else if (c = C_POP)
	{
		if (s == LOCAL)
		{
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

	}

}

void vm_writer::writeArithmetic(Segment s)
{

	if (s == ADD)
	{
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


vm_writer::~vm_writer()
{
	outputFile.close();
}
