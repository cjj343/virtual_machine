#ifndef VM_PARSER_H
#define VM_PARSER_H
#include <fstream>
#include <string>

enum Command{C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL, CERROR};
enum Segment{ARGUMENT, LOCAL, STATIC, CONSTANT, THIS, THAT, POINTER, TEMP, ADD, SUB, NEG, EQ, GT, LT, AND, OR, NOT, SERROR};

class vm_parser
{

private:
	std::ifstream inputFile;
	std::string instruction;
	Command type;
	bool openError;
	std::string functionName;


public:
	vm_parser(std::string);
	bool hasMoreCommands();
	void advance();
	bool errorCheck();
	Command commandType();
	Segment arg1();
	std::string arg2();
	std::string labelName();
	std::string ifGoto();
	std::string Goto();
	std::string Function();
	std::string Call();
	~vm_parser();
};

#endif

