#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Statement;
class Expression;
class IdentifierNode;

// AST node structure (simplified)
using namespace std;
struct Node {
    string type;
    string value;
    vector<Node*> children;
    Node(string t, string v = "") : type(t), value(v) {}
};

// Root of the AST
extern Node* ast_root;

/*
class Node {
public:
    virtual ~Node() = default;
    virtual void print(int indent = 0) const = 0; 
protected:
    void print_indent(int indent) const {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
    }
};

class Expression : public Node {};

class Statement : public Node {};

class StatementList : public Node {
public:
    std::vector<std::unique_ptr<Statement>> statements;
    void print(int indent = 0) const override {
        for (const auto& stmt : statements) {
            stmt->print(indent);
        }
    }
};

class NumberNode : public Expression {
public:
    double value;
    NumberNode(double val) : value(val) {}
    void print(int indent = 0) const override { 
        print_indent(indent);
        std::cout << "Number(" << value << ")"; 
    }
};

class IdentifierNode : public Expression {
public:
    std::string name;
    IdentifierNode(const std::string& n) : name(n) {}
    void print(int indent = 0) const override { 
        std::cout << name; 
    }
};

class BinaryOpNode : public Expression {
public:
    std::string op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

    BinaryOpNode(std::unique_ptr<Expression> l, const std::string& o, std::unique_ptr<Expression> r) 
        : op(o), left(std::move(l)), right(std::move(r)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "BinaryOp(" << op << ")" << std::endl;
        left->print(indent + 1);
        std::cout << std::endl;
        right->print(indent + 1);
    }
};

class FunctionCallNode : public Expression {
public:
    std::unique_ptr<IdentifierNode> function_name;
    std::vector<std::unique_ptr<Expression>> args;

    FunctionCallNode(std::unique_ptr<IdentifierNode> name, std::vector<std::unique_ptr<Expression>> a) 
        : function_name(std::move(name)), args(std::move(a)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Call: ";
        function_name->print();
        std::cout << " with args:" << std::endl;
        for (const auto& arg : args) {
            arg->print(indent + 1);
            std::cout << std::endl;
        }
    }
};

class ParamNode : public Node {
public:
    std::string type;
    std::unique_ptr<IdentifierNode> identifier;
    ParamNode(const std::string& t, std::unique_ptr<IdentifierNode> id)
        : type(t), identifier(std::move(id)) {}
    
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Param: " << type << " ";
        identifier->print();
    }
};


class DeclarationNode : public Statement {
public:
    std::string type;
    std::unique_ptr<IdentifierNode> identifier;
    std::unique_ptr<Expression> assignment_expr;

    DeclarationNode(const std::string& t, std::unique_ptr<IdentifierNode> id, std::unique_ptr<Expression> expr = nullptr)
        : type(t), identifier(std::move(id)), assignment_expr(std::move(expr)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Declare " << type << " ";
        identifier->print();
        if (assignment_expr) {
            std::cout << " = " << std::endl;
            assignment_expr->print(indent + 1);
        }
        std::cout << ";" << std::endl;
    }
};

class AssignmentNode : public Statement {
public:
    std::unique_ptr<IdentifierNode> identifier;
    std::unique_ptr<Expression> expression;
    AssignmentNode(std::unique_ptr<IdentifierNode> id, std::unique_ptr<Expression> expr) 
        : identifier(std::move(id)), expression(std::move(expr)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        identifier->print();
        std::cout << " = " << std::endl;
        expression->print(indent + 1);
        std::cout << ";" << std::endl;
    }
};

class ExpressionStatement : public Statement {
public:
    std::unique_ptr<Expression> expression;
    ExpressionStatement(std::unique_ptr<Expression> expr) : expression(std::move(expr)) {}
    void print(int indent = 0) const override {
        expression->print(indent);
        std::cout << ";" << std::endl;
    }
};

class IfNode : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<StatementList> then_block;
    std::unique_ptr<StatementList> else_block; // Can be nullptr

    IfNode(std::unique_ptr<Expression> cond, std::unique_ptr<StatementList> then_b, std::unique_ptr<StatementList> else_b = nullptr)
        : condition(std::move(cond)), then_block(std::move(then_b)), else_block(std::move(else_b)) {}
    
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "If Statement" << std::endl;
        print_indent(indent);
        std::cout << "Condition:" << std::endl;
        condition->print(indent + 1);
        std::cout << std::endl;
        print_indent(indent);
        std::cout << "Then Block:" << std::endl;
        then_block->print(indent + 1);
        if (else_block) {
            print_indent(indent);
            std::cout << "Else Block:" << std::endl;
            else_block->print(indent + 1);
        }
    }
};

class ForNode : public Statement {
public:
    std::unique_ptr<Statement> init; // Can be Declaration or Assignment
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Expression> increment;
    std::unique_ptr<StatementList> body;

    ForNode(std::unique_ptr<Statement> i, std::unique_ptr<Expression> c, std::unique_ptr<Expression> inc, std::unique_ptr<StatementList> b)
        : init(std::move(i)), condition(std::move(c)), increment(std::move(inc)), body(std::move(b)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "For Loop" << std::endl;
        if(init) {
            print_indent(indent);
            std::cout << "Init:" << std::endl;
            init->print(indent + 1);
        }
        if(condition) {
            print_indent(indent);
            std::cout << "Condition:" << std::endl;
            condition->print(indent + 1);
            std::cout << std::endl;
        }
        if(increment) {
            print_indent(indent);
            std::cout << "Increment:" << std::endl;
            increment->print(indent + 1);
            std::cout << std::endl;
        }
        print_indent(indent);
        std::cout << "Body:" << std::endl;
        body->print(indent + 1);
    }
};

class WhileNode : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<StatementList> body;

    WhileNode(std::unique_ptr<Expression> c, std::unique_ptr<StatementList> b)
        : condition(std::move(c)), body(std::move(b)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "While Loop" << std::endl;
        print_indent(indent);
        std::cout << "Condition:" << std::endl;
        condition->print(indent + 1);
        std::cout << std::endl;
        print_indent(indent);
        std::cout << "Body:" << std::endl;
        body->print(indent + 1);
    }
};

class ReturnNode : public Statement {
public:
    std::unique_ptr<Expression> return_value; // Can be nullptr

    ReturnNode(std::unique_ptr<Expression> val = nullptr) : return_value(std::move(val)) {}

    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Return";
        if (return_value) {
            std::cout << ":" << std::endl;
            return_value->print(indent + 1);
        }
        std::cout << ";" << std::endl;
    }
};

class FunctionDefNode : public Statement {
public:
    std::string return_type;
    std::unique_ptr<IdentifierNode> function_name;
    std::vector<std::unique_ptr<ParamNode>> params;
    std::unique_ptr<StatementList> body; 

    FunctionDefNode(const std::string& ret_type, std::unique_ptr<IdentifierNode> name, std::vector<std::unique_ptr<ParamNode>> p, std::unique_ptr<StatementList> b)
        : return_type(ret_type), function_name(std::move(name)), params(std::move(p)), body(std::move(b)) {}
    
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Function " << return_type << " ";
        function_name->print();
        std::cout << "(" << std::endl;
        for(const auto& p : params) {
            p->print(indent + 1);
            std::cout << std::endl;
        }
        print_indent(indent);
        std::cout << ") {" << std::endl;
        body->print(indent + 1);
        print_indent(indent);
        std::cout << "}" << std::endl;
    }
};
*/

#endif // AST_HPP
