#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "ast_types.hpp"

namespace SimpleCompiler {

class Node {
public:
    std::string type; // Node type (e.g., "program", "for_stmt")
    std::string value; // Node value (e.g., "i", "+", "5")
    int line; // Source line number for debugging
    std::vector<Node*> children; // Owned child nodes

        const std::string RESET = "\033[0m";
        const std::string BRIGHT_CYAN = "\033[1;36m";
        const std::string BRIGHT_BLUE = "\033[1;34m";
        const std::string BRIGHT_MAGENTA = "\033[1;35m";
        const std::string BLUE = "\033[0;34m";
        const std::string LIGHT_BLUE = "\033[0;94m";
        const std::string BRIGHT_GREEN = "\033[1;32m";
        const std::string GREEN = "\033[0;32m";
        const std::string BRIGHT_YELLOW = "\033[1;33m";
        const std::string YELLOW = "\033[0;33m";
        const std::string GRAY = "\033[0;90m";
        const std::string LIGHT_YELLOW = "\033[0;93m";
        const std::string BRIGHT_RED = "\033[1;31m";
        const std::string LIGHT_GREEN = "\033[0;92m";
        const std::string CYAN = "\033[0;36m";
        const std::string WHITE = "\033[1;37m";
        const std::string LIGHT_CYAN = "\033[0;96m";
        const std::string LIGHT_MAGENTA = "\033[0;95m";
        const std::string MAGENTA = "\033[0;35m";
        const std::string LIGHT_RED = "\033[0;91m";
        const std::string BRIGHT_WHITE = "\033[1;97m";

    Node(const std::string& t, const std::string& v = "", int l = 0)
        : type(t), value(v), line(l) {}
    virtual ~Node() = default;

    // Virtual print method for hierarchical display
    virtual void print(std::ostream& out, int indent = 0) const {
        out << std::string(indent, ' ') << type;
        if (!value.empty()) {
            out << ": " << value;
        }
        out << " (line " << line << ")" << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }

    // Placeholder for LLVM IR generation
    virtual void generateIR(/* LLVMContext& context */) const {
        // To be implemented later
    }
};

// Forward declarations for derived classes
class ProgramNode;
class StatementListNode;
class FunctionDefNode;
class ParamNode;
class DeclarationNode;
class AssignmentNode;
class IfStmtNode;
class ForStmtNode;
class WhileStmtNode;
class ReturnStmtNode;
class ExpressionStmtNode;
class AssignmentExprNode;
class BinaryOpNode;
class UnaryOpNode;
class FunctionCallNode;
class IdentifierNode;
class NumberNode;
class CharLiteralNode;
class TypeNode;

} // namespace SimpleCompiler

#endif // AST_HPP