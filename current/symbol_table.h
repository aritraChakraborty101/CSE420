#include "scope_table.h"

extern ofstream outlog;
extern ofstream errorlog;
extern int error_count;

class symbol_table
{
private:
    scope_table *current_scope;
    int bucket_count;
    int current_scope_id;

public:
    symbol_table(int bucket_count);
    ~symbol_table();
    void enter_scope();
    void exit_scope();
    bool insert(symbol_info* symbol);
    symbol_info* lookup(symbol_info* symbol);
    void print_current_scope(ofstream& outlog);
    void print_all_scopes(ofstream& outlog);
    scope_table* get_current_scope() { return current_scope; }
    
    // Semantic checking methods
    bool check_duplicate_declaration(string name, int line_num);
    bool check_variable_declared(string name, int line_num);
    void check_assignment_compatibility(string lhs_type, string rhs_type, int line_num);
    void report_error(int line_num, string message);
    void check_array_usage(string name, bool is_indexed, int line_num);
    void check_array_index_type(string index_type, int line_num);
    void check_modulus_operands(string type1, string type2, int line_num);
    void check_division_by_zero(string divisor, int line_num);
    void check_void_function_in_expression(string func_name, int line_num);
    void check_function_call(string func_name, list<string> arg_types, int line_num);
};

// Constructor
symbol_table::symbol_table(int bucket_count){
    this->bucket_count = bucket_count;
    this->current_scope_id = 1;
    this->current_scope = new scope_table(bucket_count, current_scope_id, nullptr);
    outlog << "New ScopeTable with ID " << current_scope_id << " created" << endl << endl;
}

// Destructor
symbol_table::~symbol_table(){
    while (current_scope != nullptr){
        scope_table *temp = current_scope;
        current_scope = current_scope->get_parent_scope();
        delete temp;
    }
}

// Enter a new scope
void symbol_table::enter_scope(){
    current_scope_id++;
    scope_table *new_scope = new scope_table(bucket_count, current_scope_id, current_scope);
    current_scope = new_scope;
}

// Exit current scope
void symbol_table::exit_scope(){
    if (current_scope != nullptr){
        int id = current_scope->get_unique_id();
        scope_table *temp = current_scope;
        current_scope = current_scope->get_parent_scope();
        delete temp;
        outlog << "Scopetable with ID " << id << " removed" << endl << endl;
    }
}

// Insert a symbol into current scope
bool symbol_table::insert(symbol_info* symbol){
    if (current_scope != nullptr){
        return current_scope->insert_in_scope(symbol);
    }
    return false;
}

// Lookup a symbol in all scopes (starting from current)
symbol_info* symbol_table::lookup(symbol_info* symbol){
    scope_table *temp = current_scope;
    while (temp != nullptr){
        symbol_info* found = temp->lookup_in_scope(symbol);
        if (found != nullptr){
            return found;
        }
        temp = temp->get_parent_scope();
    }
    return nullptr;
}

// Print current scope only
void symbol_table::print_current_scope(ofstream& outlog){
    if (current_scope != nullptr){
        current_scope->print_scope_table(outlog);
    }
}

// Print all scopes
void symbol_table::print_all_scopes(ofstream& outlog){
    outlog << "################################" << endl << endl;
    scope_table *temp = current_scope;
    while (temp != nullptr){
        temp->print_scope_table(outlog);
        temp = temp->get_parent_scope();
    }
    outlog << "################################" << endl << endl;
}

// Check if a symbol with the same name already exists in current scope
bool symbol_table::check_duplicate_declaration(string name, int line_num){
    if (current_scope != nullptr){
        symbol_info *dummy = new symbol_info(name, "", symbol_type::VARIABLE);
        symbol_info *found = current_scope->lookup_in_scope(dummy);
        delete dummy;
        if (found != nullptr){
            outlog << "Error at line " << line_num << ": Duplicate declaration of " << name << endl << endl;
            errorlog << "Error at line " << line_num << ": Duplicate declaration of " << name << endl << endl;
            error_count++;
            return false;
        }
    }
    return true;
}

// Check if a variable is declared before use
bool symbol_table::check_variable_declared(string name, int line_num){
    symbol_info *dummy = new symbol_info(name, "", symbol_type::VARIABLE);
    symbol_info *found = lookup(dummy);
    delete dummy;
    if (found == nullptr){
        outlog << "Error at line " << line_num << ": Undeclared variable " << name << endl << endl;
        errorlog << "Error at line " << line_num << ": Undeclared variable " << name << endl << endl;
        error_count++;
        return false;
    }
    return true;
}

// Check assignment compatibility between two types
void symbol_table::check_assignment_compatibility(string lhs_type, string rhs_type, int line_num){
    if (lhs_type == rhs_type) return;
    if (lhs_type == "error" || rhs_type == "error") return;
    
    if ((lhs_type == "float" && rhs_type == "int") || 
        (lhs_type == "int" && rhs_type == "float")){
        outlog << "Warning at line " << line_num << ": Implicit type conversion between " << lhs_type << " and " << rhs_type << endl << endl;
    } else {
        outlog << "Error at line " << line_num << ": Type mismatch: cannot assign " << rhs_type << " to " << lhs_type << endl << endl;
        errorlog << "Error at line " << line_num << ": Type mismatch: cannot assign " << rhs_type << " to " << lhs_type << endl << endl;
        error_count++;
    }
}

// Report an error message
void symbol_table::report_error(int line_num, string message){
    outlog << "Error at line " << line_num << ": " << message << endl << endl;
    errorlog << "Error at line " << line_num << ": " << message << endl << endl;
    error_count++;
}

// Check if array is being used correctly
void symbol_table::check_array_usage(string name, bool is_indexed, int line_num){
    symbol_info *dummy = new symbol_info(name, "", symbol_type::VARIABLE);
    symbol_info *found = lookup(dummy);
    delete dummy;
    
    if (found == nullptr) return;
    
    bool is_array = found->is_array();
    
    if (is_array && !is_indexed){
        outlog << "Error at line " << line_num << ": Array " << name << " used without index" << endl << endl;
        errorlog << "Error at line " << line_num << ": Array " << name << " used without index" << endl << endl;
        error_count++;
    } else if (!is_array && is_indexed){
        outlog << "Error at line " << line_num << ": Non-array variable " << name << " used with index" << endl << endl;
        errorlog << "Error at line " << line_num << ": Non-array variable " << name << " used with index" << endl << endl;
        error_count++;
    }
}

// Check if array index is of integer type
void symbol_table::check_array_index_type(string index_type, int line_num){
    if (index_type != "int"){
        outlog << "Error at line " << line_num << ": Array index must be of integer type, not " << index_type << endl << endl;
        errorlog << "Error at line " << line_num << ": Array index must be of integer type, not " << index_type << endl << endl;
        error_count++;
    }
}

// Check modulus operand compatibility
void symbol_table::check_modulus_operands(string type1, string type2, int line_num){
    if (type1 != "int" || type2 != "int"){
        outlog << "Error at line " << line_num << ": Modulus operator requires integer operands" << endl << endl;
        errorlog << "Error at line " << line_num << ": Modulus operator requires integer operands" << endl << endl;
        error_count++;
    }
}

// Check for division by zero
void symbol_table::check_division_by_zero(string divisor, int line_num){
    if (divisor == "0" || divisor == "0.0"){
        outlog << "Warning at line " << line_num << ": Division by zero detected" << endl << endl;
    }
}

// Check if void function is used in an expression
void symbol_table::check_void_function_in_expression(string func_name, int line_num){
    symbol_info *dummy = new symbol_info(func_name, "", symbol_type::FUNCTION);
    symbol_info *found = lookup(dummy);
    delete dummy;
    
    if (found != nullptr && found->get_type() == "void"){
        outlog << "Error at line " << line_num << ": Void function " << func_name << " cannot be used in an expression" << endl << endl;
        errorlog << "Error at line " << line_num << ": Void function " << func_name << " cannot be used in an expression" << endl << endl;
        error_count++;
    }
}

// Check if function call is valid
void symbol_table::check_function_call(string func_name, list<string> arg_types, int line_num){
    symbol_info *dummy = new symbol_info(func_name, "", symbol_type::FUNCTION);
    symbol_info *found = lookup(dummy);
    delete dummy;
    
    if (found == nullptr){
        outlog << "Error at line " << line_num << ": Undefined function " << func_name << endl << endl;
        errorlog << "Error at line " << line_num << ": Undefined function " << func_name << endl << endl;
        error_count++;
        return;
    }
    
    list<symbol_info*> params = found->get_parameters();
    if (params.size() != arg_types.size()){
        outlog << "Error at line " << line_num << ": Function " << func_name << " called with incorrect number of arguments" << endl << endl;
        errorlog << "Error at line " << line_num << ": Function " << func_name << " called with incorrect number of arguments" << endl << endl;
        error_count++;
        return;
    }
    
    auto arg_it = arg_types.begin();
    for (auto param : params){
        if (param->get_name() != "" && param->get_type() != *arg_it){
            outlog << "Warning at line " << line_num << ": Function " << func_name << " argument type mismatch" << endl << endl;
        }
        ++arg_it;
    }
}
