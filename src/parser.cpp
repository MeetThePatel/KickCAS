#include "../include/parser.h"

INTEGER_LITERAL::INTEGER_LITERAL(int x) {
    this->value = x;
}

DOUBLE_LITERAL::DOUBLE_LITERAL(double x) {
    this->value = x;
}

OPERATOR::OPERATOR(char x) {
    switch (x) {
        case '+':
            this->operatorType = OPERATOR_TYPE::ADDITION;
        case '-':
            this->operatorType = OPERATOR_TYPE::SUBTRACTION;
        case '*':
            this->operatorType = OPERATOR_TYPE::MULTIPLICATION;
        case '/':
            this->operatorType = OPERATOR_TYPE::DIVISION;
  }
}

LITERAL::LITERAL(double x) {
    this->setType(LITERAL_TYPE::DOUBLE);
    this->setValue(x);
}

LITERAL::LITERAL(int x) {
    this->setType(LITERAL_TYPE::INT);
    this->setValue(x);
}

void LITERAL::setType(LITERAL_TYPE x) {
    this->literalType = x;
}

void LITERAL::setValue(int x) {
    if (this->literalType == LITERAL_TYPE::INT) {
        this->i = INTEGER_LITERAL(x);
    } else if (this->literalType == LITERAL_TYPE::DOUBLE) {
        this->literalType = LITERAL_TYPE::INT;
        this->i = INTEGER_LITERAL(x);
    };
}

void LITERAL::setValue(double x) {

    if (this->literalType == LITERAL_TYPE::INT) {
        this->d = x;
    } else if (this->literalType == LITERAL_TYPE::INT) {
        this->literalType = LITERAL_TYPE::DOUBLE;
        this->d = x;
    };
}

EXPRESSION::EXPRESSION(OPERATOR x, std::vector<LITERAL> y) : op(x), argList(y) {
    this->op = x;
    this->argList = y;
}

// Rewrite this function to return a data structure
// that represents the AST of the input.
int parse(std::string input) {
    if (input.empty()) {
        return 0;
    }
    switch (input[0]) {
        case '+':
            return 1 + parse(input.substr(1));
        case '-':
            return 2 + parse(input.substr(1));
        case '*':
            return 3 + parse(input.substr(1));
        case '/':
            return 4 + parse(input.substr(1));
        case ' ':
            return parse(input.substr(1));
        default:
            return 0 + parse(input.substr(1));
    }
}

OPERATOR_TYPE operatorType(std::string input) {
    switch (input[0]) {
        case '+':
            return OPERATOR_TYPE::ADDITION;
        case '-':
            return OPERATOR_TYPE::SUBTRACTION;
        case '*':
            return OPERATOR_TYPE::MULTIPLICATION;
        case '/':
            return OPERATOR_TYPE::DIVISION;
    }
}
