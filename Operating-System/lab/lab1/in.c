#include "in.h"

int main(int argc, char *argv[]) 
{
	inChoTui();
}

/*
In this lab, we want to see how the code in a file is compiled into machine code (assembly)
Follow these steps:
1. Compile single file project
    $gcc -o in in.c
2. Read executable binary file
    $objdump -d in > in_asm_dump
    $objdump -s in > in_hex_dump
3. Read executable binary file
    $hexdump in > in.hex_bindump
    $vi in.hex_bindump
*/