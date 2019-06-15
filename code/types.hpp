#ifndef TYPES_H_
#define TYPES_H_
#include <vector>
#include <string>
enum Type_t {e_integer, e_char, e_boolean, e_real, 
            e_enum, e_subrange, e_array, e_record, e_userdefined};

class BasicType{
public:
    enum Type_t type;
    BasicType(enum Type_t type = e_integer) : type(type){}
};
class EnumType : public BasicType
{
public:
    std::vector<std::string> names;
    EnumType(enum Type_t type = e_enum) : BasicType(type){}
};
class SubrangeType : public BasicType
{
public:
    int isEnum;
    int i_start, i_end;
    std::string s_start, s_end;
    SubrangeType(enum Type_t type = e_subrange) : BasicType(type){}
};

class ArrayType : public BasicType
{
public:
    BasicType * myType;
    int start, end;
    ArrayType(enum Type_t type = e_array) : BasicType(type){}
};
class RecordType : public BasicType
{
public:
    std::vector<BasicType*> myTypes;
    std::vector<std::string> names;
    RecordType(enum Type_t type = e_record) : BasicType(type){}
};
class UserDefinedType : public BasicType
{
public:
    std::string name;
    UserDefinedType(enum Type_t type = e_userdefined) : BasicType(type){}
};

#endif