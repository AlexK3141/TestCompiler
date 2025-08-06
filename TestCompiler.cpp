#include <iostream>
#include <fstream>
#include <string>
#include "simple_compiler.h"

SimpleCompiler::SimpleCompiler() : lexer(std::cin, std::cerr) {}

void SimpleCompiler::set_input(std::istream& input) {
    lexer.switch_streams(&input, &std::cerr);
}

int SimpleCompiler::parse() {
    return yy::parser::parse(*this);
}

int SimpleCompiler::yylex() {
    return lexer.yylex();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Cannot open input file: " << argv[1] << std::endl;
        return 1;
    }

    SimpleCompiler compiler;
    compiler.set_input(input_file);
    int result = compiler.parse();
    input_file.close();

    if (result == 0) {
        std::cout << "Parsing successful" << std::endl;
    } else {
        std::cout << "Parsing failed" << std::endl;
    }

    return result;
}