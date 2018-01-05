#ifndef VM_PARSER_H
#define VM_PARSER_H
#pragma once
#include <fstream>
#include <string>

enum Command{C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL, CERROR};
enum Segment{ARGUMENT, LOCAL, STATIC, CONSTANT, THIS, THAT, POINTER, TEMP, ADD, SUB, NEG, EQ, GT, LT, AND, OR, NOT, SERROR};

class vm_parser
{

private:
	//std::string file;
	std::ifstream inputFile;
	std::string instruction;
	Command type;
	std::string error = "null";
	bool openError;


public:
	vm_parser(std::string);
	bool hasMoreCommands();
	void advance();
	//bool notCommentLine();
	//bool notBlankLine();
	//void deleteComment();
	bool errorCheck();
	Command commandType();
	Segment arg1();
	std::string arg2();
	~vm_parser();
};

#endif

