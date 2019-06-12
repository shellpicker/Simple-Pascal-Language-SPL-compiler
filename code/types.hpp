#ifndef TYPES_H_
#define TYPES_H_
#include <vector>
enum Type_t {e_integer, e_char, e_boolean, e_real, 
            e_enum, e_subrange, e_array, e_record, e_userdefined};
class BasicType{
public:
    enum Type_t type;
    BasicType(enum Type_t type = 0) : type(type){}
};
class EnumType : public BasicType
{
public:
    std::vector<std::string> names;
    EnumType(enum Type_t type = e_enum) : type(type){}
};
class SubrangeType : public BasicType
{
public:
    int isEnum;
    int i_start, i_end;
    std::string s_start, s_end;
    SubrangeType(enum Type_t type = e_subrange) : type(type){}
};

class ArrayType : public BasicType
{
public:
    BasicType * type;
    int start, end;
    ArrayType(enum Type_t type = e_array) : type(type){}
};
class RecordType : public BasicType
{
public:
    std::vector<BasicType*> types;
    std::vector<std::string> names;
    RecordType(enum Type_t type = e_record) : type(type){}
};
class UserDefinedType : public BasicType
{
public:
    std::string name;
    UserDefinedType(enum Type_t type = e_userdefined) : type(type){}
};

#endif