#include "cpp2c_polymorphism_defs.h"

funcptr TextFormatter_virtual_table[2] = {(funcptr)TextFormatter_dtor,NULL};

funcptr DefaultTextFormatter_virtual_table[2] = {(funcptr)DefaultTextFormatter_dtor,(funcptr)DefaultTextFormatter_print};

funcptr PrePostFixer_virtual_table[4] = {(funcptr)dtor_PrePostFixer,(funcptr)PrePostFixer_print_c,(funcptr)PrePostFixer_print_lc,(funcptr)PrePostFixer_getDefaultSymbol};

funcptr PrePostDollarFixe_virtual_table[4] = {(funcptr)PrePostDollarFixer_dtor,(funcptr)PrePostFixer_print_c,(funcptr)PrePostDollarFixer_print_lc,(funcptr)PrePostDollarFixer_getDefaultSymbol};

funcptr PrePostHashFixer_virtual_table[4] = {(funcptr)dtor_PrePostHashFixer,(funcptr)PrePostFixer_print_c,(funcptr)PrePostHashFixer_print_lc,(funcptr)PrePostHashFixer_getDefaultSymbol};

funcptr PrePostFloatDollarFixer_virtual_table[4] = {(funcptr)PrePostFloatDollarFixer_dtor,(funcptr)PrePostFixer_print_c,(funcptr)PrePostDollarFixer_print_lc,(funcptr)PrePostFloatDollarFixer_getDefaultSymbol};

funcptr PrePostChecker_virtual_table[4] = {(funcptr)PrePostChecker_dtor,(funcptr)PrePostFixer_print_c,(funcptr)PrePostDollarFixer_print_lc,(funcptr)PrePostFloatDollarFixer_getDefaultSymbol};

funcptr Multiplier_virtual_table[2] = {(funcptr)Multiplier_dtor,(funcptr)Multiplier_print};

void TextFormatter_dtor(TextFormatter*const this)
{
}
void TextFormatter_print(const TextFormatter*const this,const char * text)
{
}
//// DefaultTextFormatter Defs ////////////
int Ider_next_id=0;
//int DefaultTextFormatter::Ider::next_id = 0;
void ctor_DefaultTextFormatter(DefaultTextFormatter* const this)
{
	this->tf.vptr=DefaultTextFormatter_virtual_table;
	this->id=Ider_next_id++;
	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);

	
}
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this)
{
	    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	    this->tf.vptr=TextFormatter_virtual_table;
	    TextFormatter_dtor(&this->tf);
}
void copyctor_DefaultTextFormatter(DefaultTextFormatter* const this,const DefaultTextFormatter* const dtf)
{
	this->tf.vptr=dtf->tf.vptr;
	this->id=Ider_next_id++;
	printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", dtf->id, this->id);
}
DefaultTextFormatter* DefaultTextFormatter_assighmentoperator(DefaultTextFormatter* const this,const DefaultTextFormatter* const dtf)
{
		printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", dtf->id, this->id);
    	return this;
}

void DefaultTextFormatter_print(const DefaultTextFormatter* const this,const char* text)
{
	printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
	printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
	DefaultTextFormatter* arr=malloc(sizeof(DefaultTextFormatter)*3);
	DefaultTextFormatter d1;
	ctor_DefaultTextFormatter(&d1);
	DefaultTextFormatter d2;
	ctor_DefaultTextFormatter(&d2);
	DefaultTextFormatter d3;
	ctor_DefaultTextFormatter(&d3);
	arr[0]=d1;
	arr[1]=d2;
	arr[2]=d3;
	return arr;
	 
}


//// PrePostFixer Defs ////////////
void ctor_PrePostFixer(PrePostFixer * this, const char* prefix, const char* postfix)
{
	ctor_DefaultTextFormatter(&this->dtf);
	
	this->dtf.tf.vptr=PrePostFixer_virtual_table;
	this->pre=prefix;
	this->post=postfix;
	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}
void dtor_PrePostFixer(PrePostFixer *const this)
{
	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	this->dtf.tf.vptr=DefaultTextFormatter_virtual_table;
	DefaultTextFormatter_dtor(&this->dtf);
}

void PrePostFixer_print_c(const PrePostFixer *const this,const char* text)
{
	printf("%-60s | ", "[PrePostFixer::print(const char*)]");
	printf("%s%s%s\n", this->pre, text, this->post);
}
void PrePostFixer_print_lc(const PrePostFixer *const this, long num, char symbol)
{
	printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    
    if (symbol)    
	{
		printf("%-60s | ", "[PrePostFixer::print_num(long, char)]"); 
    	printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
	}
    else
    {
       	printf("%-60s | ","[PrePostFixer::print_num(long)]"); 
    	printf("%s%ld%s\n", this->pre, num, this->post);
    }
}
char PrePostFixer_getDefaultSymbol(PrePostFixer *const this)
{
	return '\0';
}

//// PrePostDollarFixer Defs ////////////

void ctor_PrePostDollarFixer_cc(PrePostDollarFixer* const this, const char* prefix, const char* postfix)
{
	ctor_PrePostFixer(&this->ppf,prefix,postfix);
	this->ppf.dtf.tf.vptr=PrePostDollarFixe_virtual_table;
	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}
void copyctor_PrePostDollarFixer(PrePostDollarFixer* const this, const PrePostDollarFixer* other)
{
	copyctor_DefaultTextFormatter(&this->ppf.dtf,&other->ppf.dtf);
	this->ppf.dtf.tf.vptr=PrePostFixer_virtual_table;
	this->ppf.pre=other->ppf.pre;
	this->ppf.post=other->ppf.post;
	this->ppf.dtf.tf.vptr=other->ppf.dtf.tf.vptr;
	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}
void PrePostDollarFixer_dtor(PrePostDollarFixer* const this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n",  this->ppf.pre, this->ppf.post);
    this->ppf.dtf.tf.vptr=PrePostFixer_virtual_table;
    dtor_PrePostFixer(&this->ppf);
}
void PrePostDollarFixer_print_ic(const PrePostDollarFixer* const this, int num, char symbol)
{
	printf("%-60s | ","[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    this->ppf.dtf.tf.vptr[2](this,(long)num,symbol);
    //PrePostDollarFixer_print_lc(this,(long)num, symbol);
}
void PrePostDollarFixer_print_lc(const PrePostDollarFixer* const this, long num, char symbol)
{
	printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
	PrePostFixer_print_lc(&this->ppf,num, symbol);

}
void PrePostDollarFixer_print_dc(const PrePostDollarFixer* const this, double num, char symbol)
{
	printf("%-60s | ","[PrePostDollarFixer::print(double, char)]"); 
    printf("%s%c%f%s\n", this->ppf.pre , symbol, num, this->ppf.post);
}
char PrePostDollarFixer_getDefaultSymbol(const PrePostDollarFixer* const this)
{
	return DOLLAR_DEFAULT_SYMBOL;
}


//// PrePostHashFixer Defs ////////////

void ctor_PrePostHashFixer(PrePostHashFixer* const this, int prc)
{
	ctor_PrePostDollarFixer_cc(&this->ppdf,"===> ", " <===");
	this->ppdf.ppf.dtf.tf.vptr=PrePostHashFixer_virtual_table;
	this->precision=prc;
	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->ppdf.ppf.pre, this->ppdf.ppf.post, this->precision);   
	printf("%-60s | ","[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n",this->ppdf.ppf.pre, HASH_DEFAULT_SYMBOL, this->precision, 9999.9999, this->ppdf.ppf.post);
    
}
void dtor_PrePostHashFixer(PrePostHashFixer* const this)
{
	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
	this->ppdf.ppf.dtf.tf.vptr=PrePostDollarFixe_virtual_table;
	PrePostDollarFixer_dtor(&this->ppdf);
}
void PrePostHashFixer_print_ic(const PrePostHashFixer* const this, int num, char symbol)
{
	printf("%-60s | ","[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre, symbol, this->precision, (double)num,this->ppdf.ppf.post);

}
void PrePostHashFixer_print_lc(const PrePostHashFixer* const this, long num, char symbol)
{
	printf("%-60s | ","[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre, symbol, this->precision, (double)num,this->ppdf.ppf.post);
}

char PrePostHashFixer_getDefaultSymbol(const PrePostHashFixer* const this)
{
	return HASH_DEFAULT_SYMBOL;
}


//// PrePostFloatDollarFixer Defs ////////////
void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix)
{
	ctor_PrePostDollarFixer_cc(&this->ppdf,prefix,postfix);
	this->ppdf.ppf.dtf.tf.vptr=PrePostFloatDollarFixer_virtual_table;
	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
}
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this)
{
	printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
	this->ppdf.ppf.dtf.tf.vptr=PrePostDollarFixe_virtual_table;
	PrePostDollarFixer_dtor(&this->ppdf);
}
void PrePostFloatDollarFixer_print_f(const PrePostFloatDollarFixer* const this,float num)
{
	printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
 	printf("-->\n");
	PrePostFloatDollarFixer_print_fc(this, num,FLOAT_DOLLAR_DEFAULT_SYMBOL);
}
void PrePostFloatDollarFixer_print_fc(const PrePostFloatDollarFixer* const this,float num,char symbol)
{
	printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");
	printf("%s%c%.2f%s\n", this->ppdf.ppf.pre, symbol, num, this->ppdf.ppf.post);
}
char PrePostFloatDollarFixer_getDefaultSymbol(const PrePostFloatDollarFixer* const this)
{
	return FLOAT_DOLLAR_DEFAULT_SYMBOL;
}
/**/




//// PrePostChecker Defs ////////////
void PrePostChecker_ctor(PrePostChecker* const this)
{
	PrePostFloatDollarFixer_ctor(&this->ppfdf,"[[[[ ", " ]]]]");
	this->ppfdf.ppdf.ppf.dtf.tf.vptr=PrePostChecker_virtual_table;
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->ppfdf.ppdf.ppf.pre, this->ppfdf.ppdf.ppf.post);
}
void PrePostChecker_dtor(PrePostChecker* const this)
{
	printf("--- PrePostChecker DTOR: \"%s\"...\"%s\"\n",this->ppfdf.ppdf.ppf.pre, this->ppfdf.ppdf.ppf.post);
	this->ppfdf.ppdf.ppf.dtf.tf.vptr=PrePostFloatDollarFixer_virtual_table;
	PrePostFloatDollarFixer_dtor(&this->ppfdf);
}

void PrePostChecker_printThisSymbolUsingFunc(PrePostChecker* this)
{
		printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");
		printf("Default symbol is %c\n", ((char(*)(const void * const))(this->ppfdf.ppdf.ppf.dtf.tf.vptr[3]))(this));
}

void PrePostChecker_printThisSymbolDirectly(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");
	printf("Default symbol is %c\n", FLOAT_DOLLAR_DEFAULT_SYMBOL);
	
}

void PrePostChecker_printDollarSymbolByCastUsingFunc(PrePostChecker* this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
	this->ppfdf.ppdf.ppf.dtf.tf.vptr=PrePostFloatDollarFixer_virtual_table;
	printf("Default symbol is %c\n", ((char(*)(const void * const))(this->ppfdf.ppdf.ppf.dtf.tf.vptr[3]))((PrePostFloatDollarFixer*)this));
	this->ppfdf.ppdf.ppf.dtf.tf.vptr=PrePostChecker_virtual_table;
}

void PrePostChecker_printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
	printf("Default symbol is %c\n", PrePostDollarFixer_getDefaultSymbol(&this->ppfdf.ppdf));
}
void PrePostChecker_printDollarSymbolByCastDirectly(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n",DOLLAR_DEFAULT_SYMBOL);
}
void PrePostChecker_printDollarSymbolByScopeDirectly(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n",DOLLAR_DEFAULT_SYMBOL);
}


//// Multiplier Defs ////////////
void Multiplier_dtor(Multiplier * const this)
{
	printf("--- Multiplier DTOR: times = %d\n", this->times);
	this->dtf.tf.vptr=DefaultTextFormatter_virtual_table;
	DefaultTextFormatter_dtor(&this->dtf);

}
void Multiplier_print(Multiplier *  this, const char * c)
{
	
	printf("%-60s | ","[Multiplier::print(const char*)]");    
    	for (int i = 0; i < this->times; ++i)
        	printf("%s", c);
    	printf("\n");
}



