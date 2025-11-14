#include <bits/stdc++.h>

using namespace std;

enum class symbol_type { VARIABLE, ARRAY, FUNCTION };

class symbol_info
{
private:
    string name;
    string type;
    symbol_type symbolType; // Enum to represent variable/array/function
    list<symbol_info*> parameters; // List to store function parameters
    int arraySize; // To store size if symbol is an array

    // Write necessary attributes to store what type of symbol it is (variable/array/function)
    // Write necessary attributes to store the type/return type of the symbol (int/float/void/...)
    // Write necessary attributes to store the parameters of a function
    // Write necessary attributes to store the array size if the symbol is an array

public:
    symbol_info(string name, string type, symbol_type symType, int arrSize = 0, list<symbol_info*> params = {})
    {
        this->name = name;
        this->type = type;
        this->symbolType = symType;
        if (symType == symbol_type::ARRAY){
            this->arraySize = arrSize;
        }
        if (symType == symbol_type::FUNCTION){
            this->parameters = params;
        }
    }
    string get_name()
    {
        return name;
    }
    string get_type()
    {
        return type;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_type(string type)
    {
        this->type = type;
    }
    // Write necessary functions to set and get the attributes
    symbol_type get_symbol_type(){
        return symbolType;
    }
    void set_symbol_type(symbol_type symType){
        this->symbolType = symType;
    }
    list<symbol_info*> get_parameters(){
        return parameters;
    }
    void set_parameters(list<symbol_info*> params){
        this->parameters = params;
    }
    void add_parameter(symbol_info* param){
        this->parameters.push_back(param);
    }
    int get_array_size(){
        return arraySize;
    }
    void set_array_size(int arrSize){
        this->arraySize = arrSize;
    }
    bool is_array(){
        return symbolType == symbol_type::ARRAY;
    }
    bool is_function(){
        return symbolType == symbol_type::FUNCTION;
    }

    ~symbol_info()
    {
        // Write necessary code to deallocate memory, if necessary
        for (auto param : parameters){
            delete param;
        }
    }
};