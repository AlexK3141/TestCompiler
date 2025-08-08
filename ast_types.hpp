#ifndef AST_TYPES_HPP
#define AST_TYPES_HPP

#include <string>
#include <stdexcept>

namespace SimpleCompiler {

enum class BaseType {
    Int,
    Float,
    Char,
    Void
};

class Type {
public:
    BaseType base_type;
    bool is_pointer; // For future pointer types
    int array_size; // For future array types

    Type(BaseType bt, bool ptr = false, int arr_size = 0)
        : base_type(bt), is_pointer(ptr), array_size(arr_size) {}

    std::string toString() const {
        std::string result;
        switch (base_type) {
            case BaseType::Int: result = "int"; break;
            case BaseType::Float: result = "float"; break;
            case BaseType::Char: result = "char"; break;
            case BaseType::Void: result = "void"; break;
            default: throw std::runtime_error("Unknown base type");
        }
        if (is_pointer) result += "*";
        if (array_size > 0) result += "[" + std::to_string(array_size) + "]";
        return result;
    }

    // Equality for type checking
    bool operator==(const Type& other) const {
        return base_type == other.base_type &&
               is_pointer == other.is_pointer &&
               array_size == other.array_size;
    }
};

} // namespace SimpleCompiler

#endif // AST_TYPES_HPP