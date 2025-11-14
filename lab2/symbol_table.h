#include "scope_table.h"

extern ofstream outlog;

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

    // you can add more methods if you need 
};

// complete the methods of symbol_table class


// void symbol_table::print_all_scopes(ofstream& outlog)
// {
//     outlog<<"################################"<<endl<<endl;
//     scope_table *temp = current_scope;
//     while (temp != NULL)
//     {
//         temp->print_scope_table(outlog);
//         temp = temp->get_parent_scope();
//     }
//     outlog<<"################################"<<endl<<endl;
// }
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