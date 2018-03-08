# virtual_machine
Virtual Machine for the Hack Computer build

Virtual Machine:
This is the virtual machine for the Hack Computer built in Nand2Tetris curriculum. It is designed to take VM files and translate them into Hack assembly code.  The assembler then takes the assembly code and translates it into binary.
There are a lot of things I would do different if I were to redo this project, but I think this means that I must have learned a lot. For one, I worked on this while learning c++ which is why there are some varying design choices and some things aren’t quite optimized. For example, if I were to redo this project, I would rework the vm_writer class so that there isn’t so much repeated assembly code. A simple optimization would be to create separate functions for certain commands like pushing and popping onto the stack.
This was also one of the first projects where I attempted to use Git correctly (rather than just blindly pushing completed code in one commit).  I learned a lot about the value of version control and how to efficiently use Git in the dev process.

Getting Started:
If you are interested in running this VM, take the source code and compile it using c++ 11 or later. I mainly used Visual Studio to write, compile and test but I also compiled and tested on a Linux server using GCC.
For now, the VM files must be in the same directory as the src code.  After you compile, run the executable with the VM files that you want to translate as command line args.  The order matters for the command line arguments so, in general, the first argument should always be the Sys.vm file followed by Main.vm.  This will then create an xxx.asm file in the same directory.  If you want to take it further, you can then take the xxx.asm file and repeat the process above using the assembler source code.

Tests and Bugs:
I tested the VM using CPU emulator supplied in the Nand2Tetris curriculum. The VM has passed all the supplied tests in the Nand2Tetris book but there might be some bugs and errors that pop up with more rigorous testing.

Stack Arithmetic:
Tests for simple stack functions like push, pop, add and subtract

Basic Loop:
Tests for basic looping functionality

Memory Access:
Tests variables, pointers, static variables and memory access

Function Calls:
Tests functions and bootstrap code
