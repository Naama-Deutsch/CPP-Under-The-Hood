#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__

#define DOLLAR_DEFAULT_SYMBOL '$'
#define HASH_DEFAULT_SYMBOL '#'
#define FLOAT_DOLLAR_DEFAULT_SYMBOL '@'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*funcptr)(void*,...);
typedef char (*charfuncptr)(void*,...);
typedef struct {
	funcptr* vptr;
}TextFormatter;

typedef struct{
	TextFormatter tf;
	int id;
}DefaultTextFormatter;

typedef struct {
	DefaultTextFormatter dtf;
	char* pre;
    char* post;
}PrePostFixer;

typedef struct {
	PrePostFixer ppf;
}PrePostDollarFixer;


typedef struct {
	PrePostDollarFixer ppdf;
		int precision;
}PrePostHashFixer;

typedef struct{
	PrePostDollarFixer ppdf;
}PrePostFloatDollarFixer;

typedef struct {
	PrePostFloatDollarFixer ppfdf;
}PrePostChecker;

typedef struct {
	DefaultTextFormatter dtf;
	int times;
}Multiplier;

void TextFormatter_dtor(TextFormatter* const this);
void TextFormatter_print(const TextFormatter*const this,const char* text);
//// DefaultTextFormatter ////////////


void ctor_DefaultTextFormatter(DefaultTextFormatter* const this);
void copyctor_DefaultTextFormatter(DefaultTextFormatter* const this,const DefaultTextFormatter* const dtf);
DefaultTextFormatter* DefaultTextFormatter_assighmentoperator(DefaultTextFormatter* const this,const DefaultTextFormatter* const dtf);
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this);
void DefaultTextFormatter_print(const DefaultTextFormatter* const this,const char* text);

DefaultTextFormatter* generateFormatterArray();
//// PrePostFixer ////////////

//// PrePostFixer Defs ////////////
void ctor_PrePostFixer(PrePostFixer * this, const char* prefix, const char* postfix);
void dtor_PrePostFixer(PrePostFixer *const this);

void PrePostFixer_print_c(const PrePostFixer *const this,const char* text);
void PrePostFixer_print_lc(const PrePostFixer *const this, long num, char symbol);
char PrePostFixer_getDefaultSymbol(PrePostFixer *const this);




void ctor_PrePostDollarFixer_cc(PrePostDollarFixer* const this, const char* prefix, const char* postfix);
void copyctor_PrePostDollarFixer(PrePostDollarFixer* const this, const PrePostDollarFixer* other);
void PrePostDollarFixer_dtor(PrePostDollarFixer* const this);
void PrePostDollarFixer_print_ic(const PrePostDollarFixer* const this, int num, char symbol);

void PrePostDollarFixer_print_lc(const PrePostDollarFixer* const this, long num, char symbol);
void PrePostDollarFixer_print_dc(const PrePostDollarFixer* const this, double num, char symbol);
char PrePostDollarFixer_getDefaultSymbol(const PrePostDollarFixer* const this);

//// PrePostHashFixer ////////////

void ctor_PrePostHashFixer(PrePostHashFixer * const this, int prc);
void dtor_PrePostHashFixer(PrePostHashFixer* const this);
void PrePostHashFixer_print_ic(const PrePostHashFixer* const this, int num, char symbol);
void PrePostHashFixer_print_lc(const PrePostHashFixer* const this, long num, char symbol);

char PrePostHashFixer_getDefaultSymbol(const PrePostHashFixer* const this);

//// PrePostHashFixer Defs ////////////

//// PrePostFloatDollarFixer ////////////

void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix);
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this);
void PrePostFloatDollarFixer_print_f(const PrePostFloatDollarFixer* const this,float num);
void PrePostFloatDollarFixer_print_fc(const PrePostFloatDollarFixer* const this,float num,char symbol);
char PrePostFloatDollarFixer_getDefaultSymbol(const PrePostFloatDollarFixer* const this);


//// PrePostChecker ////////////

void PrePostChecker_ctor(PrePostChecker* const this);
void PrePostChecker_dtor(PrePostChecker* const this);
void PrePostChecker_printThisSymbolUsingFunc( PrePostChecker* this);
void PrePostChecker_printThisSymbolDirectly(const PrePostChecker* const this);    
void PrePostChecker_printDollarSymbolByCastUsingFunc( PrePostChecker* this);
void PrePostChecker_printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this);
void PrePostChecker_printDollarSymbolByCastDirectly(const PrePostChecker* const this);
void PrePostChecker_printDollarSymbolByScopeDirectly(const PrePostChecker* const this);



//// Multiplier ////////////

void Multiplier_dtor(Multiplier * const this);
void Multiplier_print(Multiplier * this, const char * c);



#endif // __CPP2C_POLYMORPHISM_H__

