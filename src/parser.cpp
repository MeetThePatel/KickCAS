#include "../include/parser.h"

_Structure::_Structure(_Structure_Type x) {
    this->value = x;
}

_Structure::_Structure(std::string x) {
    switch (x[0]) {
        case '(':
            this->value = _Structure_Type::_Left_Parens;
            break;
        case ')':
            this->value = _Structure_Type::_Right_Parens;
            break;
    }
}

std::string _Structure::toString() {
    switch (this->value) {
        case _Structure_Type::_Left_Parens:
            return "(";
            break;
        case _Structure_Type::_Right_Parens:
            return ")";
            break;
        default: break;
    }
}

_Operator::_Operator(_Operator_Type opType) {
    this->type = opType;
}

std::string _Operator::toString() {
    switch (this->type) {
        case _Operator_Type::_Addition:
            return "Addition";
        case _Operator_Type::_Subtraction:
            return "Subtraction";
        case _Operator_Type::_Multiplication:
            return "Multiplication";
        case _Operator_Type::_Division:
            return "Division";
    }
}

_Integer::_Integer(int value) {
    this->value = value;
}

_Integer _Integer::operator+(_Integer b) {
    return _Integer(this->value + b.value);
}

_Integer _Integer::operator*(_Integer b) {
    return _Integer(this->value * b.value);
}

bool _Integer::operator==(_Integer b) {
    return (this->value == b.value);
}

_Integer::_Integer(std::string value) {
    this->value = std::stoi(value);
}

std::string _Integer::toString() {
    return std::to_string(this->value);
}

_Decimal::_Decimal(double value) {
    this->value = value;
}

_Decimal::_Decimal(std::string value) {
    this->value = std::stod(value);
}

_Decimal _Decimal::operator+(_Decimal b) {
    return this->value + b.value;
}

_Decimal _Decimal::operator*(_Decimal b) {
    return this->value * b.value;
}

std::string _Decimal::toString() {
    std::string str = std::to_string(this->value);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    return str;
}

_Expression::_Expression(_Operator x, std::vector<std::shared_ptr<_Number> > y) : op(x), argList(y) {
    this->op = x;
    this->argList = y;
}

std::string _Expression::toString() {
    std::string ret = "";
    ret += (this->argList.at(0))->toString();
    for (auto i = 1; i < this->argList.size(); i++) {
        ret += " + ";
        ret += (this->argList.at(i))->toString();
    }
    return ret;
}

std::vector<std::string> parseIntoStringVector(std::string input) {
    std::vector<std::string> stringVector;
    for (auto &&i : input) {
        std::string s(1, i);
        if (s != " ") {
            stringVector.push_back(s);
        }
    }
    return stringVector;
}

std::vector<std::shared_ptr<_Atom> > convertStringVectorIntoAtomVector(std::vector<std::string> input) {
    std::vector<std::shared_ptr<_Atom> > ret;
    for (std::string i : input) {
        if (i == "(") {
            std::shared_ptr<_Atom> x(new _Structure("("));
            ret.push_back(x);
            break;
        }
        if (i == ")") {
            std::shared_ptr<_Atom> x(new _Structure(")"));
            ret.push_back(x);
            break;
        }
        if (std::isdigit(i[1])) {
            std::size_t found = i.find(".");
            if (found != std::string::npos) {
                std::shared_ptr<_Atom> x(new _Integer(i));
                ret.push_back(x);
                break;
            } else {
                std::shared_ptr<_Atom> x(new _Decimal(i));
                ret.push_back(x);
                break;
            }
        }
    }
    return ret;
}

void _Structure_Assertions() {
    assert(_Structure("(").toString() == "(");
}

void _Operator_Assertions() {
    assert(_Operator(_Operator_Type::_Addition).toString() == "Addition");
    assert(_Operator(_Operator_Type::_Subtraction).toString() == "Subtraction");
    assert(_Operator(_Operator_Type::_Multiplication).toString() == "Multiplication");
    assert(_Operator(_Operator_Type::_Division).toString() == "Division");
}

void _Integer_Assertions() {
    assert(_Integer(0).toString() == "0");
    assert(_Integer(1) + _Integer(1) == _Integer(2));
    assert(_Integer(2) * _Integer(2) == _Integer(4));
}

void _Decimal_Assertions() {
    assert(_Decimal(0.0123).toString() == "0.0123");
    assert((_Decimal(0.1) + _Decimal(0.1)).toString() == "0.2");
}

void _Parser_CPP_Assertions() {
    _Structure_Assertions();
    _Operator_Assertions();
    _Integer_Assertions();
    _Decimal_Assertions();
}
