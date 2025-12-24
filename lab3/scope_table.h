#include "symbol_info.h"

class scope_table
{
private:
    int bucket_count;
    int unique_id;
    scope_table *parent_scope = NULL;
    vector<list<symbol_info *>> table;

    int hash_function(string name)
    {
        // write your hash function here
        int hash_val = 0;
        for (char c : name) {
            if (c >= 'a' && c <= 'z') {
                hash_val += (c - 'a' + 1);
            } else if (c >= 'A' && c <= 'Z') {
                hash_val += (c - 'A' + 1);
            } else {
                hash_val += c;
            }
        }
        return hash_val % bucket_count;
    }

public:
    scope_table();
    scope_table(int bucket_count, int unique_id, scope_table *parent_scope);
    scope_table *get_parent_scope();
    int get_unique_id();
    symbol_info *lookup_in_scope(symbol_info* symbol);
    bool insert_in_scope(symbol_info* symbol);
    bool delete_from_scope(symbol_info* symbol);
    void print_scope_table(ofstream& outlog);
    ~scope_table();

    // you can add more methods if you need
};


// Default constructor
scope_table::scope_table(){
    this->bucket_count = 10;
    this->unique_id = 0;
    this->parent_scope = nullptr;
    table.resize(bucket_count);
}

// Parameterized constructor
scope_table::scope_table(int bucket_count, int unique_id, scope_table *parent_scope){
    this->bucket_count = bucket_count;
    this->unique_id = unique_id;
    this->parent_scope = parent_scope;
    table.resize(bucket_count);
}

// Get parent scope
scope_table *scope_table::get_parent_scope(){
    return parent_scope;
}

// Get unique ID
int scope_table::get_unique_id(){
    return unique_id;
}

// Lookup symbol in this scope only
symbol_info *scope_table::lookup_in_scope(symbol_info* symbol){
    int index = hash_function(symbol->get_name());
    
    for (auto& sym : table[index]){
        if (sym->get_name() == symbol->get_name()){
            return sym;
        }
    }
    return nullptr;
}

// Insert symbol into this scope
bool scope_table::insert_in_scope(symbol_info* symbol){
    // Check if symbol already exists in current scope
    if (lookup_in_scope(symbol) != nullptr){
        return false; // Symbol already exists
    }
    
    int index = hash_function(symbol->get_name());
    table[index].push_back(symbol);
    return true;
}

// Delete symbol from this scope
bool scope_table::delete_from_scope(symbol_info* symbol){
    int index = hash_function(symbol->get_name());
    
    for (auto it = table[index].begin(); it != table[index].end(); ++it){
        if ((*it)->get_name() == symbol->get_name()){
            delete *it; 
            table[index].erase(it);
            return true;
        }
    }
    return false;
}

// Print scope table
void scope_table::print_scope_table(ofstream& outlog){
    outlog << "ScopeTable # " << unique_id << endl;
    
    for (int i = 0; i < bucket_count; i++){
        if (!table[i].empty()){
            outlog << i << " --> " << endl;
            for (auto& sym : table[i]){
                outlog << "< " << sym->get_name() << " : ID >" << endl;
                
                // Print detailed information based on symbol type
                if (sym->is_function()){
                    outlog << "Function Definition" << endl;
                    outlog << "Return Type: " << sym->get_type() << endl;
                    outlog << "Number of Parameters: " << sym->get_parameters().size() << endl;
                    outlog << "Parameter Details: ";
                    bool first = true;
                    for (auto& param : sym->get_parameters()){
                        if (!first) outlog << ", ";
                        outlog << param->get_type();
                        if (!param->get_name().empty()) {
                            outlog << " " << param->get_name();
                        }
                        first = false;
                    }
                    outlog << endl;
                } else if (sym->is_array()){
                    outlog << "Array" << endl;
                    outlog << "Type: " << sym->get_type() << endl;
                    outlog << "Size: " << sym->get_array_size() << endl;
                } else {
                    outlog << "Variable" << endl;
                    outlog << "Type: " << sym->get_type() << endl;
                }
                outlog << endl;
            }
        }
    }
}

// Destructor
scope_table::~scope_table(){
    for (int i = 0; i < bucket_count; i++){
        for (auto& sym : table[i])
        {
            delete sym;
        }
        table[i].clear();
    }
}
