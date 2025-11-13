#include <bits/stdc++.h>
using namespace std;

// Define the category of the symbol (identifier, function, or array)
enum class SymbolCategory
{
    IDENTIFIER,
    ARRAY_TYPE,
    FUNCTION_TYPE
};

class SymbolInfo
{
private:
    string idName;                 // The symbol name (identifier)
    string dataType;               // The data or return type (int, float, void, etc.)
    SymbolCategory category;       // The category (variable/array/function)
    vector<SymbolInfo*> paramList; // Function parameters
    int arrLength;                 // For arrays: holds size; otherwise -1

public:
    // Default + parameterized constructor
    SymbolInfo(string id = "", string dtype = "", SymbolCategory cat = SymbolCategory::IDENTIFIER, 
               const vector<SymbolInfo*>& params = {}, int length = -1)
        : idName(id), dataType(dtype), category(cat), arrLength(length)
    {
        if (cat == SymbolCategory::FUNCTION_TYPE)
        {
            paramList = params;
        }
    }

    // Copy constructor for safe object duplication
    SymbolInfo(const SymbolInfo& other)
    {
        idName = other.idName;
        dataType = other.dataType;
        category = other.category;
        arrLength = other.arrLength;

        // Deep copy of parameter list
        for (auto* p : other.paramList)
        {
            paramList.push_back(new SymbolInfo(*p));
        }
    }

    // ------------------- Basic Accessors -------------------
    string getIdentifier() const { return idName; }
    string getDataType() const { return dataType; }
    SymbolCategory getCategory() const { return category; }
    int getArrayLength() const { return arrLength; }

    // ------------------- Mutators -------------------
    void setIdentifier(const string& id) { idName = id; }
    void setDataType(const string& dtype) { dataType = dtype; }
    void setCategory(SymbolCategory cat) { category = cat; }
    void setArrayLength(int len) { arrLength = len; }

    // ------------------- Parameter Related -------------------
    void setParameters(const vector<SymbolInfo*>& params)
    {
        paramList = params;
    }

    const vector<SymbolInfo*>& getParameters() const
    {
        return paramList;
    }

    void addParameter(SymbolInfo* param)
    {
        paramList.push_back(param);
    }

    // ------------------- Type Checking Helpers -------------------
    bool isVariable() const { return category == SymbolCategory::IDENTIFIER; }
    bool isArray() const { return category == SymbolCategory::ARRAY_TYPE; }
    bool isFunction() const { return category == SymbolCategory::FUNCTION_TYPE; }

    // ------------------- Destructor -------------------
    ~SymbolInfo()
    {
        for (auto* param : paramList)
        {
            delete param;
        }
        paramList.clear();
    }
};

