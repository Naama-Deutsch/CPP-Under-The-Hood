#include "cpp2c_polymorphism_defs.h"


extern Multiplier_virtual_table[2];


void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    ctor_PrePostFixer(&angleBrackets,"<<< ", " >>>");
    PrePostFixer_print_c(&angleBrackets,"Hello World!");
    PrePostFixer_print_lc(&angleBrackets,-777,'\0');
    PrePostFixer_print_lc(&angleBrackets,350,'#');
    PrePostFixer_print_lc(&angleBrackets,(long int) 3.14,'\0');


    printf("\n--- end doPrePostFixer() ---\n\n");
    
    dtor_PrePostFixer(&angleBrackets);
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    ctor_PrePostDollarFixer_cc(&asterisks,"***** ", " *****");
    PrePostDollarFixer_print_ic(&asterisks,-777,DOLLAR_DEFAULT_SYMBOL);
    PrePostDollarFixer_print_ic(&asterisks,350,'#');
	PrePostDollarFixer_print_dc(&asterisks,3.14f,DOLLAR_DEFAULT_SYMBOL);


    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixer_dtor(&asterisks);
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    PrePostChecker_ctor(&check);
    
    PrePostChecker_printThisSymbolUsingFunc(&check);
    PrePostChecker_printThisSymbolDirectly(&check);
    PrePostChecker_printDollarSymbolByCastDirectly(&check);
    PrePostChecker_printDollarSymbolByScopeDirectly(&check);
    PrePostChecker_printDollarSymbolByCastUsingFunc(&check);
	PrePostChecker_printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    
    PrePostChecker_dtor(&check);
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    PrePostFloatDollarFixer_ctor(&hashes,"### ", " ###");
    PrePostFloatDollarFixer_print_f(&hashes,-777);
  	PrePostFloatDollarFixer_print_fc(&hashes,350, '#');
    PrePostFloatDollarFixer_print_f(&hashes,3.14f);
    

    PrePostDollarFixer hashes2;
    copyctor_PrePostDollarFixer(&hashes2,&hashes.ppdf);
    PrePostDollarFixer_print_dc(&hashes2,7.5,DOLLAR_DEFAULT_SYMBOL);
    PrePostDollarFixer_print_ic(&hashes2,100,DOLLAR_DEFAULT_SYMBOL);
 

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    PrePostDollarFixer_dtor(&hashes2);
    PrePostFloatDollarFixer_dtor(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{

    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
	
	pp->dtf.tf.vptr[2](&pp,123,'\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
	
	PrePostDollarFixer_print_ic(pp,123,'\0');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
	PrePostDollarFixer a;
	copyctor_PrePostDollarFixer(&a,&pp);
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");
	PrePostDollarFixer_print_ic(&a,123,DOLLAR_DEFAULT_SYMBOL);
    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
    PrePostDollarFixer_dtor(&a);
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    
    PrePostHashFixer_print_ic(&pp,123,HASH_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");
	
    Multiplier m1;
    ctor_DefaultTextFormatter(&m1.dtf);
    m1.dtf.tf.vptr=Multiplier_virtual_table;
    m1.times=3;
    printf("--- Multiplier CTOR: times = %d\n", m1.times);
    
    Multiplier m2;
    ctor_DefaultTextFormatter(&m2.dtf);
    m2.dtf.tf.vptr=Multiplier_virtual_table;
    m2.times=5;
    printf("--- Multiplier CTOR: times = %d\n", m2.times);
    
    Multiplier m3;
    copyctor_DefaultTextFormatter(&m3.dtf,&m1.dtf);
    m3.times=m1.times;
    
    Multiplier m4;
    copyctor_DefaultTextFormatter(&m4.dtf,&m2.dtf);
    m4.times=m2.times;
    
    Multiplier_print(&m1,"abc ");
    Multiplier_print(&m2,"abc ");
    Multiplier_print(&m3,"abc ");
    Multiplier_print(&m4,"abc ");

    printf("\n--- start doMultiplier() ---\n\n");
    Multiplier_dtor(&m4);
    Multiplier_dtor(&m3);
    Multiplier_dtor(&m2);
    Multiplier_dtor(&m1);
    
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    PrePostDollarFixer ppdf;
    ctor_PrePostDollarFixer_cc(&ppdf,"!!! ", " !!!");
    DefaultTextFormatter d1;
    copyctor_DefaultTextFormatter(&d1,&ppdf.ppf.dtf);
    PrePostDollarFixer_dtor(&ppdf);
    
    Multiplier mul;
    ctor_DefaultTextFormatter(&mul.dtf);
    mul.dtf.tf.vptr=Multiplier_virtual_table;
    mul.times=4;
    printf("--- Multiplier CTOR: times = %d\n", mul.times);
    DefaultTextFormatter d2;
    copyctor_DefaultTextFormatter(&d2,&mul.dtf);
    Multiplier_dtor(&mul);
    
    PrePostChecker ppc;
    PrePostChecker_ctor(&ppc);
    DefaultTextFormatter d3;
    copyctor_DefaultTextFormatter(&d3,&ppc.ppfdf.ppdf.ppf.dtf);
    PrePostChecker_dtor(&ppc);
    
    DefaultTextFormatter formatters[] =
    {
        d1,
        d2,
        d3
    };

    for (int i = 0; i < 3; ++i)
    	DefaultTextFormatter_print(&formatters[i],"Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
    DefaultTextFormatter_dtor(&d3);
    DefaultTextFormatter_dtor(&d2);
    DefaultTextFormatter_dtor(&d1);
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");
	
    PrePostDollarFixer ppdf;
    ctor_PrePostDollarFixer_cc(&ppdf,"!!! ", " !!!");
 
    
    Multiplier mul;
    ctor_DefaultTextFormatter(&mul.dtf);
    mul.dtf.tf.vptr=Multiplier_virtual_table;
    mul.times=4;
    
    printf("--- Multiplier CTOR: times = %d\n", mul.times);
    
    
    PrePostChecker ppc;
    PrePostChecker_ctor(&ppc);
   
    
    DefaultTextFormatter* pfmt[] =
    {
        (DefaultTextFormatter*)&ppdf,
        (DefaultTextFormatter*)&mul,
        (DefaultTextFormatter*)&ppc
    };

	
    for (int i = 0; i < 3; ++i)
      	pfmt[i]->tf.vptr[1](pfmt[i],"Hello World!");
   
	
   for (int i = 2; i >= 0; --i)
    	pfmt[i]->tf.vptr[0](pfmt[i],"Hello World!");
    

    

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    
    for (int i = 0; i < 3; ++i)
        formatters[i].tf.vptr[1](&formatters[i],"Hello World!");
        
    for (int i = 0; i < 3; ++i)
        formatters[i].tf.vptr[0](&formatters[i]);

    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    ctor_PrePostHashFixer(&hfix,4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    runAsPrePostDollarFixerObj(hfix.ppdf);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");
	dtor_PrePostHashFixer(&hfix);
    return 0;
}



