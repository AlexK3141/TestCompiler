#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include "ast.hpp"
#include "color_utils.hpp"
#include <string>
#include <vector>
#include <memory>

namespace SimpleCompiler {

class ProgramNode : public Node {
public:
    ProgramNode(int line = 0) : Node("program", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_CYAN << std::string(indent, ' ') << type;
        if (!value.empty()) {
            out << ": " << value;
        }
        out << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class StatementListNode : public Node {
public:
    StatementListNode(int line = 0) : Node("statement_list", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_BLUE << std::string(indent, ' ') << type;
        if (!value.empty()) {
            out << ": " << value;
        }
        out << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class FunctionDefNode : public Node {
public:
    Type return_type;
    FunctionDefNode(const Type& ret_type, const std::string& name, int line = 0)
        : Node("function_def", name, line), return_type(ret_type) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_MAGENTA << std::string(indent, ' ') << type << ": " << value
            << " (return: " << return_type.toString() << ", line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class ParamNode : public Node {
public:
    Type param_type;
    ParamNode(const Type& p_type, const std::string& name, int line = 0)
        : Node("param", name, line), param_type(p_type) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_BLUE << std::string(indent, ' ') << type << ": " << value
            << " (" << param_type.toString() << ", line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class DeclarationNode : public Node {
public:
    Type var_type;
    DeclarationNode(const Type& v_type, const std::string& name, int line = 0)
        : Node("declaration", name, line), var_type(v_type) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_GREEN << std::string(indent, ' ') << type << ": " << value
            << " (" << var_type.toString() << ", line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class AssignmentNode : public Node {
public:
    AssignmentNode(const std::string& name, int line = 0)
        : Node("assignment", name, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << GREEN << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class IfStmtNode : public Node {
public:
    IfStmtNode(int line = 0) : Node("if_stmt", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_YELLOW << std::string(indent, ' ') << type
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class ForStmtNode : public Node {
public:
    ForStmtNode(int line = 0) : Node("for_stmt", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << YELLOW << std::string(indent, ' ') << type
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class WhileStmtNode : public Node {
public:
    WhileStmtNode(int line = 0) : Node("while_stmt", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_YELLOW << std::string(indent, ' ') << type
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class ReturnStmtNode : public Node {
public:
    ReturnStmtNode(int line = 0) : Node("return_stmt", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_RED << std::string(indent, ' ') << type
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class ExpressionStmtNode : public Node {
public:
    ExpressionStmtNode(int line = 0) : Node("expression_stmt", "", line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_GREEN << std::string(indent, ' ') << type
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class AssignmentExprNode : public Node {
public:
    AssignmentExprNode(const std::string& name, int line = 0)
        : Node("assignment", name, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << GREEN << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class BinaryOpNode : public Node {
public:
    BinaryOpNode(const std::string& op, int line = 0)
        : Node("binary_op", op, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << CYAN << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class UnaryOpNode : public Node {
public:
    UnaryOpNode(const std::string& op, int line = 0)
        : Node("unary_op", op, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_RED << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class FunctionCallNode : public Node {
public:
    FunctionCallNode(const std::string& name, int line = 0)
        : Node("function_call", name, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << MAGENTA << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class IdentifierNode : public Node {
public:
    Type var_type;
    IdentifierNode(const std::string& name, const Type& v_type, int line = 0)
        : Node("identifier", name, line), var_type(v_type) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << WHITE << std::string(indent, ' ') << type << ": " << value
            << " (" << var_type.toString() << ", line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class NumberNode : public Node {
public:
    Type num_type;
    NumberNode(const std::string& value, const Type& n_type, int line = 0)
        : Node("number", value, line), num_type(n_type) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_CYAN << std::string(indent, ' ') << type << ": " << value
            << " (" << num_type.toString() << ", line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class CharLiteralNode : public Node {
public:
    CharLiteralNode(const std::string& value, int line = 0)
        : Node("char_literal", value, line) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << LIGHT_MAGENTA << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

class TypeNode : public Node {
public:
    Type type_value;
    TypeNode(const Type& t, int line = 0)
        : Node("type", t.toString(), line), type_value(t) {}
    void print(std::ostream& out, int indent = 0) const override {
        out << BRIGHT_WHITE << std::string(indent, ' ') << type << ": " << value
            << " (line " << line << ")" << RESET << std::endl;
        for (const auto& child : children) {
            child->print(out, indent + 2);
        }
    }
};

} // namespace SimpleCompiler

#endif // AST_NODES_HPP