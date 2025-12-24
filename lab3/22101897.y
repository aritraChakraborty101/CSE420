
%{

#include "symbol_table.h"

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

symbol_table* sym_table;

int lines = 1;

ofstream outlog;
ofstream errorlog;
int error_count = 0;

string current_var_type;
stack<symbol_info*> fn_name;
stack<list<string>> arg_types_stack;
string current_expr_type;
string current_op_type;

symbol_info* addSymbol(string name, string type, symbol_type symType, int arrSize = 0, list<symbol_info*> params = {}){
	return new symbol_info(name, type, symType, arrSize, params);
}

void enterFn(string name, string return_type){
	fn_name.push(addSymbol(name, return_type, symbol_type::FUNCTION));
	sym_table->insert(fn_name.top());
	sym_table->enter_scope();	
}

void enterScopeDecl(){
	outlog<<"Entering new scope for declaration at line "<<lines<<endl<<endl;
} 

void exitScopeDecl(){
	sym_table->print_all_scopes(outlog);
	sym_table->exit_scope();
}

void yyerror(char *s)
{
	outlog<<"At line "<<lines<<" "<<s<<endl<<endl;
}

%}

%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON CONST_INT CONST_FLOAT ID

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start : program
	{
		outlog<<"At line no: "<<lines<<" start : program "<<endl<<endl;
		outlog<<"Symbol Table"<<endl<<endl;
		
		sym_table->print_all_scopes(outlog);
		outlog<<"Total lines: "<<lines<<endl;
		outlog<<"Total errors: "<<error_count<<endl;
		
		errorlog<<"Total errors: "<<error_count<<endl;
	}
	;

program : program unit
	{
		outlog<<"At line no: "<<lines<<" program : program unit "<<endl<<endl;
		outlog<<$1->get_name()+"\n"+$2->get_name()<<endl<<endl;
		
		$$ = new symbol_info($1->get_name()+"\n"+$2->get_name(),"program", symbol_type::VARIABLE);
	}
	| unit
	{
		outlog<<"At line no: "<<lines<<" program : unit "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
		
		$$ = new symbol_info($1->get_name(),"program", symbol_type::VARIABLE);
	}
	;

unit : var_declaration
	 {
		outlog<<"At line no: "<<lines<<" unit : var_declaration "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
		
		$$ = new symbol_info($1->get_name(),"unit", symbol_type::VARIABLE);
	 }
     | func_definition
     {
		outlog<<"At line no: "<<lines<<" unit : func_definition "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
		
		$$ = new symbol_info($1->get_name(),"unit", symbol_type::VARIABLE);
	 }
     ;

func_definition : type_specifier ID LPAREN {enterFn($2->get_name(), $1->get_name());} parameter_list RPAREN {outlog << "New ScopeTable with ID " << sym_table->get_current_scope()->get_unique_id() << " created" << endl << endl;} compound_statement
		{	
			exitScopeDecl();
			fn_name.pop();
			
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement "<<endl<<endl;
			outlog<<$1->get_name()<<" "<<$2->get_name()<<"("+$5->get_name()+")\n"<<$8->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name()+" "+$2->get_name()+"("+$5->get_name()+")\n"+$8->get_name(),"func_def", symbol_type::VARIABLE);
		}
		| type_specifier ID LPAREN RPAREN {enterFn($2->get_name(), $1->get_name());} {outlog << "New ScopeTable with ID " << sym_table->get_current_scope()->get_unique_id() << " created" << endl << endl;} compound_statement
		{
			exitScopeDecl();
			fn_name.pop();
			
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement "<<endl<<endl;
			outlog<<$1->get_name()<<" "<<$2->get_name()<<"()\n"<<$7->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name()+" "+$2->get_name()+"()\n"+$7->get_name(),"func_def", symbol_type::VARIABLE);
		}
 		;

parameter_list : parameter_list COMMA type_specifier ID
		{
			outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier ID "<<endl<<endl;
			outlog<<$1->get_name()<<","<<$3->get_name()<<" "<<$4->get_name()<<endl<<endl;
			
			// Check for duplicate parameter declaration
			if (!sym_table->check_duplicate_declaration($4->get_name(), lines)) {
				// Error already reported
			} else {
				fn_name.top()->add_parameter(addSymbol($4->get_name(), $3->get_name(), symbol_type::VARIABLE));
				sym_table->insert(addSymbol($4->get_name(), $3->get_name(), symbol_type::VARIABLE));
			}
			
			$$ = new symbol_info($1->get_name()+","+$3->get_name()+" "+$4->get_name(),"param_list", symbol_type::VARIABLE);
		}
		| parameter_list COMMA type_specifier
		{
			outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier "<<endl<<endl;
			outlog<<$1->get_name()<<","<<$3->get_name()<<endl<<endl;
			
			fn_name.top()->add_parameter(addSymbol("", $3->get_name(), symbol_type::VARIABLE));
			$$ = new symbol_info($1->get_name()+","+$3->get_name(),"param_list", symbol_type::VARIABLE);
		}
 		| type_specifier ID
 		{
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier ID "<<endl<<endl;
			outlog<<$1->get_name()<<" "<<$2->get_name()<<endl<<endl;
			
			// Check for duplicate parameter declaration
			if (!sym_table->check_duplicate_declaration($2->get_name(), lines)) {
				// Error already reported
			} else {
				fn_name.top()->add_parameter(addSymbol($2->get_name(), $1->get_name(), symbol_type::VARIABLE));
				sym_table->insert(addSymbol($2->get_name(), $1->get_name(), symbol_type::VARIABLE));
			}
			
			$$ = new symbol_info($1->get_name()+" "+$2->get_name(),"param_list", symbol_type::VARIABLE);
		}
		| type_specifier
		{
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			fn_name.top()->add_parameter(addSymbol("", $1->get_name(), symbol_type::VARIABLE));
			$$ = new symbol_info($1->get_name(),"param_list", symbol_type::VARIABLE);
		}
 		;

compound_statement : LCURL statements RCURL
			{ 
 		    	outlog<<"At line no: "<<lines<<" compound_statement : LCURL statements RCURL "<<endl<<endl;
				outlog<<"{\n"+$2->get_name()+"\n}"<<endl<<endl;
				
				$$ = new symbol_info("{\n"+$2->get_name()+"\n}","comp_stmnt", symbol_type::VARIABLE);
 		    }
 		    | LCURL RCURL
 		    { 
 		    	outlog<<"At line no: "<<lines<<" compound_statement : LCURL RCURL "<<endl<<endl;
				outlog<<"{\n}"<<endl<<endl;
				
				$$ = new symbol_info("{\n}","comp_stmnt", symbol_type::VARIABLE);
 		    }
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
		 {
			outlog<<"At line no: "<<lines<<" var_declaration : type_specifier declaration_list SEMICOLON "<<endl<<endl;
			outlog<<$1->get_name()<<" "<<$2->get_name()<<";"<<endl<<endl;
			
			$$ = new symbol_info($1->get_name()+" "+$2->get_name()+";","var_dec", symbol_type::VARIABLE);
		 }
 		 ;

type_specifier : INT
		{
			outlog<<"At line no: "<<lines<<" type_specifier : INT "<<endl<<endl;
			outlog<<"int"<<endl<<endl;
			
			$$ = new symbol_info("int","type", symbol_type::VARIABLE);
			current_var_type = "int";
	    }
 		| FLOAT
 		{
			outlog<<"At line no: "<<lines<<" type_specifier : FLOAT "<<endl<<endl;
			outlog<<"float"<<endl<<endl;
			
			$$ = new symbol_info("float","type", symbol_type::VARIABLE);
			current_var_type = "float";
	    }
 		| VOID
 		{
			outlog<<"At line no: "<<lines<<" type_specifier : VOID "<<endl<<endl;
			outlog<<"void"<<endl<<endl;
			
			$$ = new symbol_info("void","type", symbol_type::VARIABLE);
			current_var_type = "void";
	    }
 		;

declaration_list : declaration_list COMMA ID
		  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID "<<endl<<endl;
 		  	outlog<<$1->get_name()+","<<$3->get_name()<<endl<<endl;

			// Check for duplicate declaration
			if (sym_table->check_duplicate_declaration($3->get_name(), lines)) {
				sym_table->insert(addSymbol($3->get_name(),current_var_type,symbol_type::VARIABLE));
			}
			
			$$ = new symbol_info($1->get_name()+","+$3->get_name(),"decl_list", symbol_type::VARIABLE);
 		  }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD //array after some declaration
 		  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
 		  	outlog<<$1->get_name()+","<<$3->get_name()<<"["<<$5->get_name()<<"]"<<endl<<endl;

			// Check for duplicate declaration
			if (sym_table->check_duplicate_declaration($3->get_name(), lines)) {
				sym_table->insert(addSymbol($3->get_name(),current_var_type,symbol_type::ARRAY,stoi($5->get_name())));
			}
			
			$$ = new symbol_info($1->get_name()+","+$3->get_name()+"["+ $5->get_name()+"]","decl_list", symbol_type::VARIABLE);
 		  }
 		  |ID
 		  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;

			// Check for duplicate declaration
			if (sym_table->check_duplicate_declaration($1->get_name(), lines)) {
				sym_table->insert(addSymbol($1->get_name(),current_var_type,symbol_type::VARIABLE));
			}
			
			$$ = new symbol_info($1->get_name(),"decl_list", symbol_type::VARIABLE);
 		  }
 		  | ID LTHIRD CONST_INT RTHIRD //array
 		  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
			outlog<<$1->get_name()<<"["<<$3->get_name()<<"]"<<endl<<endl;

			// Check for duplicate declaration
			if (sym_table->check_duplicate_declaration($1->get_name(), lines)) {
				sym_table->insert(addSymbol($1->get_name(),current_var_type,symbol_type::ARRAY,stoi($3->get_name())));
			}
			
			$$ = new symbol_info($1->get_name()+"["+$3->get_name()+"]","decl_list", symbol_type::VARIABLE);
 		  }
 		  ;
 		  

statements : statement
	   {
	    	outlog<<"At line no: "<<lines<<" statements : statement "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"stmnts", symbol_type::VARIABLE);
	   }
	   | statements statement
	   {
	    	outlog<<"At line no: "<<lines<<" statements : statements statement "<<endl<<endl;
			outlog<<$1->get_name()<<"\n"<<$2->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name()+"\n"+$2->get_name(),"stmnts", symbol_type::VARIABLE);
	   }
	   ;
	   
statement : var_declaration
	  {
	    	outlog<<"At line no: "<<lines<<" statement : var_declaration "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | func_definition
	  {
	  		outlog<<"At line no: "<<lines<<" statement : func_definition "<<endl<<endl;
            outlog<<$1->get_name()<<endl<<endl;

            $$ = new symbol_info($1->get_name(),"stmnt", symbol_type::VARIABLE);
	  		
	  }
	  | expression_statement
	  {
	    	outlog<<"At line no: "<<lines<<" statement : expression_statement "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | compound_statement
	  {
	    	outlog<<"At line no: "<<lines<<" statement : compound_statement "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  {
	    	outlog<<"At line no: "<<lines<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement "<<endl<<endl;
			outlog<<"for("<<$3->get_name()<<$4->get_name()<<$5->get_name()<<")\n"<<$7->get_name()<<endl<<endl;
			
			$$ = new symbol_info("for("+$3->get_name()+$4->get_name()+$5->get_name()+")\n"+$7->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
	  {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"if("<<$3->get_name()<<")\n"<<$5->get_name()<<endl<<endl;
			
			$$ = new symbol_info("if("+$3->get_name()+")\n"+$5->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement
	  {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement ELSE statement "<<endl<<endl;
			outlog<<"if("<<$3->get_name()<<")\n"<<$5->get_name()<<"\nelse\n"<<$7->get_name()<<endl<<endl;
			
			$$ = new symbol_info("if("+$3->get_name()+")\n"+$5->get_name()+"\nelse\n"+$7->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | WHILE LPAREN expression RPAREN statement
	  {
	    	outlog<<"At line no: "<<lines<<" statement : WHILE LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"while("<<$3->get_name()<<")\n"<<$5->get_name()<<endl<<endl;
			
			$$ = new symbol_info("while("+$3->get_name()+")\n"+$5->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  {
	    	outlog<<"At line no: "<<lines<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl<<endl;
			outlog<<"printf("<<$3->get_name()<<");"<<endl<<endl; 
			
			// Check if variable is declared
			sym_table->check_variable_declared($3->get_name(), lines);
			
			$$ = new symbol_info("printf("+$3->get_name()+");","stmnt", symbol_type::VARIABLE);
	  }
	  | RETURN expression SEMICOLON
	  {
	    	outlog<<"At line no: "<<lines<<" statement : RETURN expression SEMICOLON "<<endl<<endl;
			outlog<<"return "<<$2->get_name()<<";"<<endl<<endl;
			
			// Check return type compatibility with function
			if (!fn_name.empty()) {
				string func_type = fn_name.top()->get_type();
				if (func_type != "void") {
					sym_table->check_assignment_compatibility(func_type, current_expr_type, lines);
				} else {
					if (current_expr_type != "") {
						sym_table->report_error(lines, "Void function cannot return a value");
					}
				}
			}
			
			$$ = new symbol_info("return "+$2->get_name()+";","stmnt", symbol_type::VARIABLE);
	  }
	  ;
	  
expression_statement : SEMICOLON
			{
				outlog<<"At line no: "<<lines<<" expression_statement : SEMICOLON "<<endl<<endl;
				outlog<<";"<<endl<<endl;
				
				$$ = new symbol_info(";","expr_stmt", symbol_type::VARIABLE);
	        }			
			| expression SEMICOLON 
			{
				outlog<<"At line no: "<<lines<<" expression_statement : expression SEMICOLON "<<endl<<endl;
				outlog<<$1->get_name()<<";"<<endl<<endl;
				
				$$ = new symbol_info($1->get_name()+";","expr_stmt", symbol_type::VARIABLE);
	        }
			;
	  
variable : ID 	
      {
	    outlog<<"At line no: "<<lines<<" variable : ID "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
			
		// Check if variable is declared
		if (!sym_table->check_variable_declared($1->get_name(), lines)) {
			current_expr_type = "error";
		} else {
			// Get variable type
			symbol_info* dummy = new symbol_info($1->get_name(), "", symbol_type::VARIABLE);
			symbol_info* var = sym_table->lookup(dummy);
			delete dummy;
			if (var) {
				current_expr_type = var->get_type();
				// Store for array checking
				current_op_type = var->is_array() ? "array" : "variable";
			}
		}
		
		// Check if array is used without index
		sym_table->check_array_usage($1->get_name(), false, lines);
		
		$$ = new symbol_info($1->get_name(),"varbl", symbol_type::VARIABLE);
	 }	
	 | ID LTHIRD expression RTHIRD 
	 {
	 	outlog<<"At line no: "<<lines<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
		outlog<<$1->get_name()<<"["<<$3->get_name()<<"]"<<endl<<endl;
		
		// Check if variable is declared and is an array
		if (sym_table->check_variable_declared($1->get_name(), lines)) {
			sym_table->check_array_usage($1->get_name(), true, lines);
			
			// Check array index type
			sym_table->check_array_index_type(current_expr_type, lines);
			
			// Get array type
			symbol_info* dummy = new symbol_info($1->get_name(), "", symbol_type::VARIABLE);
			symbol_info* var = sym_table->lookup(dummy);
			delete dummy;
			if (var) {
				current_expr_type = var->get_type();
				current_op_type = "array_element";
			}
		}
		
		$$ = new symbol_info($1->get_name()+"["+$3->get_name()+"]","varbl", symbol_type::VARIABLE);
	 }
	 ;
	 
expression : logic_expression
	   {
	    	outlog<<"At line no: "<<lines<<" expression : logic_expression "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"expr", symbol_type::VARIABLE);
	   }
	   | variable ASSIGNOP logic_expression 	
	   {
	    	outlog<<"At line no: "<<lines<<" expression : variable ASSIGNOP logic_expression "<<endl<<endl;
			outlog<<$1->get_name()<<"="<<$3->get_name()<<endl<<endl;

			// Get variable type
			string var_name = $1->get_name();
			symbol_info* dummy = new symbol_info(var_name, "", symbol_type::VARIABLE);
			symbol_info* var = sym_table->lookup(dummy);
			delete dummy;
			
			if (var) {
				string var_type = var->get_type();
				// Check assignment compatibility
				sym_table->check_assignment_compatibility(var_type, current_expr_type, lines);
				current_expr_type = var_type; // Assignment expression takes LHS type
			}
			
			$$ = new symbol_info($1->get_name()+"="+$3->get_name(),"expr", symbol_type::VARIABLE);
	   }
	   ;
			
logic_expression : rel_expression
	     {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"lgc_expr", symbol_type::VARIABLE);
	     }	
		 | rel_expression LOGICOP rel_expression 
		 {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression LOGICOP rel_expression "<<endl<<endl;
			outlog<<$1->get_name()<<$2->get_name()<<$3->get_name()<<endl<<endl;
			
			// Check operand types for logical operators
			string op_type = $2->get_type();
			if (op_type == "&&" || op_type == "||") {
				// For logical operators, result is always integer
				current_expr_type = "int";
				current_op_type = "logic_op";
			}
			
			$$ = new symbol_info($1->get_name()+$2->get_name()+$3->get_name(),"lgc_expr", symbol_type::VARIABLE);
	     }	
		 ;
			
rel_expression	: simple_expression
		{
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"rel_expr", symbol_type::VARIABLE);
	    }
		| simple_expression RELOP simple_expression
		{
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression RELOP simple_expression "<<endl<<endl;
			outlog<<$1->get_name()<<$2->get_name()<<$3->get_name()<<endl<<endl;
			
			// For relational operators, result is always integer
			current_expr_type = "int";
			current_op_type = "rel_op";
			
			$$ = new symbol_info($1->get_name()+$2->get_name()+$3->get_name(),"rel_expr", symbol_type::VARIABLE);
	    }
		;
				
simple_expression : term
          {
	    	outlog<<"At line no: "<<lines<<" simple_expression : term "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"simp_expr", symbol_type::VARIABLE);
			
	      }
		  | simple_expression ADDOP term 
		  {
	    	outlog<<"At line no: "<<lines<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
			outlog<<$1->get_name()<<$2->get_name()<<$3->get_name()<<endl<<endl;
			
			// Type conversion for arithmetic operations
			string op_type = $2->get_type();
			if (op_type == "+" || op_type == "-") {
				// Determine result type based on operands
				string type1 = current_expr_type;
				string type2 = $3->get_type();
				
				if (type1 == "float" || type2 == "float") {
					current_expr_type = "float";
				} else {
					current_expr_type = "int";
				}
				current_op_type = "arith_op";
			}
			
			$$ = new symbol_info($1->get_name()+$2->get_name()+$3->get_name(),"simp_expr", symbol_type::VARIABLE);
	      }
		  ;
					
term :	unary_expression
     {
	    	outlog<<"At line no: "<<lines<<" term : unary_expression "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"term", symbol_type::VARIABLE);
			
	 }
     |  term MULOP unary_expression
     {
	    	outlog<<"At line no: "<<lines<<" term : term MULOP unary_expression "<<endl<<endl;
			outlog<<$1->get_name()<<$2->get_name()<<$3->get_name()<<endl<<endl;
			
			string op_type = $2->get_type();
			string type1 = current_expr_type;
			string type2 = $3->get_type();
			
			if (op_type == "%") {
				// Check modulus operands
				sym_table->check_modulus_operands(type1, type2, lines);
				current_expr_type = "int";
				current_op_type = "mod_op";
			} else if (op_type == "/") {
				// Check division by zero (if constant)
				if ($3->get_name() == "0" || $3->get_name() == "0.0") {
					sym_table->check_division_by_zero($3->get_name(), lines);
				}
				// Determine result type
				if (type1 == "float" || type2 == "float") {
					current_expr_type = "float";
				} else {
					current_expr_type = "int";
				}
				current_op_type = "div_op";
			} else if (op_type == "*") {
				// Determine result type
				if (type1 == "float" || type2 == "float") {
					current_expr_type = "float";
				} else {
					current_expr_type = "int";
				}
				current_op_type = "mul_op";
			}
			
			$$ = new symbol_info($1->get_name()+$2->get_name()+$3->get_name(),"term", symbol_type::VARIABLE);
			
	 }
     ;

unary_expression : ADDOP unary_expression
		 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : ADDOP unary_expression "<<endl<<endl;
			outlog<<$1->get_name()<<$2->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name()+$2->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
		 | NOT unary_expression 
		 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : NOT unary_expression "<<endl<<endl;
			outlog<<"!"<<$2->get_name()<<endl<<endl;
			
			// NOT operator produces integer result
			current_expr_type = "int";
			current_op_type = "not_op";
			
			$$ = new symbol_info("!"+$2->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
		 | factor 
		 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : factor "<<endl<<endl;
			outlog<<$1->get_name()<<endl<<endl;
			
			$$ = new symbol_info($1->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
		 ;
	
factor	: variable
    {
	    outlog<<"At line no: "<<lines<<" factor : variable "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
			
		$$ = new symbol_info($1->get_name(),"fctr", symbol_type::VARIABLE);
	}
	| ID LPAREN argument_list RPAREN
	{
	    outlog<<"At line no: "<<lines<<" factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
		outlog<<$1->get_name()<<"("<<$3->get_name()<<")"<<endl<<endl;

		// Check void function in expression
		sym_table->check_void_function_in_expression($1->get_name(), lines);
		
		// Check function call parameters
		list<string> arg_types = arg_types_stack.top();
		arg_types_stack.pop();
		sym_table->check_function_call($1->get_name(), arg_types, lines);
		
		// Get function return type
		symbol_info* dummy = new symbol_info($1->get_name(), "", symbol_type::VARIABLE);
		symbol_info* func = sym_table->lookup(dummy);
		delete dummy;
		if (func) {
			current_expr_type = func->get_type();
			current_op_type = "function_call";
		}
		
		$$ = new symbol_info($1->get_name()+"("+$3->get_name()+")","fctr", symbol_type::VARIABLE);
	}
	| LPAREN expression RPAREN
	{
	   	outlog<<"At line no: "<<lines<<" factor : LPAREN expression RPAREN "<<endl<<endl;
		outlog<<"("<<$2->get_name()<<")"<<endl<<endl;
		
		$$ = new symbol_info("("+$2->get_name()+")","fctr", symbol_type::VARIABLE);
	}
	| CONST_INT 
	{
	    outlog<<"At line no: "<<lines<<" factor : CONST_INT "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
			
		current_expr_type = "int";
		current_op_type = "constant";
		$$ = new symbol_info($1->get_name(),"fctr", symbol_type::VARIABLE);
	}
	| CONST_FLOAT
	{
	    outlog<<"At line no: "<<lines<<" factor : CONST_FLOAT "<<endl<<endl;
		outlog<<$1->get_name()<<endl<<endl;
			
		current_expr_type = "float";
		current_op_type = "constant";
		$$ = new symbol_info($1->get_name(),"fctr", symbol_type::VARIABLE);
	}
	| variable INCOP 
	{
	    outlog<<"At line no: "<<lines<<" factor : variable INCOP "<<endl<<endl;
		outlog<<$1->get_name()<<"++"<<endl<<endl;
			
		// Increment/decrement doesn't change type
		$$ = new symbol_info($1->get_name()+"++","fctr", symbol_type::VARIABLE);
	}
	| variable DECOP
	{
	    outlog<<"At line no: "<<lines<<" factor : variable DECOP "<<endl<<endl;
		outlog<<$1->get_name()<<"--"<<endl<<endl;
			
		// Increment/decrement doesn't change type
		$$ = new symbol_info($1->get_name()+"--","fctr", symbol_type::VARIABLE);
	}
	;
	
argument_list : arguments
			  {
					outlog<<"At line no: "<<lines<<" argument_list : arguments "<<endl<<endl;
					outlog<<$1->get_name()<<endl<<endl;
						
					$$ = new symbol_info($1->get_name(),"arg_list", symbol_type::VARIABLE);
			  }
			  |
			  {
					outlog<<"At line no: "<<lines<<" argument_list :  "<<endl<<endl;
					outlog<<""<<endl<<endl;
						
					// Push empty argument list
					list<string> empty_list;
					arg_types_stack.push(empty_list);
					
					$$ = new symbol_info("","arg_list", symbol_type::VARIABLE);
			  }
			  ;
	
arguments : arguments COMMA logic_expression
		  {
				outlog<<"At line no: "<<lines<<" arguments : arguments COMMA logic_expression "<<endl<<endl;
				outlog<<$1->get_name()<<","<<$3->get_name()<<endl<<endl;
						
				// Get argument types from stack
				list<string> arg_types = arg_types_stack.top();
				arg_types_stack.pop();
				arg_types.push_back(current_expr_type);
				arg_types_stack.push(arg_types);
				
				$$ = new symbol_info($1->get_name()+","+$3->get_name(),"arg", symbol_type::VARIABLE);
		  }
	      | logic_expression
	      {
				outlog<<"At line no: "<<lines<<" arguments : logic_expression "<<endl<<endl;
				outlog<<$1->get_name()<<endl<<endl;
						
				// Create new argument list with current expression type
				list<string> arg_types;
				arg_types.push_back(current_expr_type);
				arg_types_stack.push(arg_types);
				
				$$ = new symbol_info($1->get_name(),"arg", symbol_type::VARIABLE);
		  }
	      ;
 

%%

int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout<<"Please input file name"<<endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	outlog.open("22101892_log.txt", ios::trunc);
	errorlog.open("22101892_error.txt", ios::trunc);
	
	if(yyin == NULL)
	{
		cout<<"Couldn't open file"<<endl;
		return 0;
	}
	
	// Initialize symbol table
	sym_table = new symbol_table(10);

	yyparse();
	
	outlog<<endl<<"Total lines: "<<lines<<endl;
	outlog<<"Total errors: "<<error_count<<endl;
	
	errorlog<<"Total errors: "<<error_count<<endl;
	
	outlog.close();
	errorlog.close();
	
	fclose(yyin);
	
	delete sym_table;
	
	return 0;
}
