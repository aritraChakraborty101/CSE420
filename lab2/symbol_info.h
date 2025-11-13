class symbol_info
{
private:
    string idname;
    string datatype;
    SymbolCategory category;
    vector<SymbolInfo*>paramList;
    int arrLength;
    // Write necessary attributes to store what type of symbol it is (variable/array/function)
    // Write necessary attributes to store the type/return type of the symbol (int/float/void/...)
    // Write necessary attributes to store the parameters of a function
    // Write necessary attributes to store the array size if the symbol is an array

public:
    symbol_info(string id=" ", string dtype=" ",SymbolCategory c=SymbolCategory::IDENTIFIER,const vector<SymbolInfo*>& params={},int length=-1):idName(id),dataType(dCOtype),category(c),arrLength(length){
        if (c==SymbolCategory::FUNCTION_TYPE)
        {
        paramList = params;
        }
    }

    
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

    
    string getIdentifier() 
    const { 
        return idName;
     }
    string getDataType() 
    const { 
        return dataType; 
    }
    SymbolCategory getCategory() 
    const { 
        return category;
     }
    int getArrayLength() 
    const { 
        return arrLength; 
    }

    

  void setIdentifier(const string& id) { idName = id; }
    void setDataType(const string& dtype) { dataType = dtype; }
    void setCategory(SymbolCategory cat) { category = cat; }
    void setArrayLength(int len) { arrLength = len; }

    
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

    
    bool isVariable() 
    const { 
        return category == SymbolCategory::IDENTIFIER; }
    bool isArray() 
    const { 
        return category == SymbolCategory::ARRAY_TYPE; }
    bool isFunction() 
    const { return category == SymbolCategory::FUNCTION_TYPE; }

    
    ~SymbolInfo()
    {
        for (auto* param : paramList)
        {
            delete param;
        }
        paramList.clear();
    }
};
