#include <iostream>
#include <string>
#include <vector>

struct _Atom {
    virtual std::string toString() = 0;
};

enum class _Structure_Type {
    _Left_Parens = 1,
    _Right_Parens = 2
};

struct _Structure : _Atom {
    _Structure(_Structure_Type);
    _Structure(std::string);
    std::string toString();

protected:
    _Structure_Type value;
};

enum class _Operator_Type {
    _Addition = 1,
    _Subtraction = 2,
    _Multiplication = 3,
    _Division = 4,
};

struct _Operator : _Atom {
    _Operator(_Operator_Type);
    std::string toString();

protected:
    _Operator_Type type;
};

struct _Number : _Atom {
    virtual std::string toString() = 0;
};

struct _Integer : _Number {
    _Integer(int);
    _Integer(std::string);
    _Integer operator+ (_Integer);
    _Integer operator* (_Integer);
    bool operator== (_Integer);
    std::string toString();

protected:
    int value;
};

struct _Decimal : _Number {
    _Decimal(double);
    _Decimal(std::string);
    _Decimal operator+ (_Decimal);
    _Decimal operator* (_Decimal);
    std::string toString();

protected:
    double value;
};

struct _Expression {
    _Expression(_Operator, std::vector<std::shared_ptr<_Number>>);
    std::string toString(); 

protected:
    _Operator op;
    std::vector<std::shared_ptr<_Number>> argList;
};

std::vector<std::string> parseIntoStringVector(std::string);
std::vector<std::shared_ptr<_Atom> > convertStringVectorIntoAtomVector(std::vector<std::string>);

void _Structure_Assertions();
void _Operator_Assertions();
void _Integer_Assertions();
void _Decimal_Assertions();
void _Parser_CPP_Assertions();
