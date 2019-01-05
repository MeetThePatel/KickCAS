#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <vector>

enum class LITERAL_TYPE {
    INT = 0,
    DOUBLE = 1
};

struct INTEGER_LITERAL {
    int value;

    INTEGER_LITERAL(int);
};

struct DOUBLE_LITERAL{
    double value;

    DOUBLE_LITERAL(double);
};

enum class OPERATOR_TYPE {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

enum class ATOM_TYPE {
    LITERAL,
    OPERATOR
};

struct OPERATOR {
    OPERATOR_TYPE operatorType;

    OPERATOR(char);
};

struct LITERAL {
    LITERAL_TYPE literalType;
    union {
        INTEGER_LITERAL i;
        DOUBLE_LITERAL d;
    };

    LITERAL(double);
    LITERAL(int);

    void setType(LITERAL_TYPE);
    void setValue(int);
    void setValue(double);
};

struct EXPRESSION {
    OPERATOR op;
    std::vector<LITERAL> argList;

    EXPRESSION(OPERATOR, std::vector<LITERAL>);
};

int parse(std::string);

OPERATOR_TYPE operatorType(std::string);

#endif
