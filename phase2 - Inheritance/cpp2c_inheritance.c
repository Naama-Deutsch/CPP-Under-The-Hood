#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


void doMaterials()
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	Materials mat;
	Material_t mat1;
	Material_t mat2;
    printf("\n--- Start doMaterials() ---\n\n");
    
    
    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest{ Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %ld\n", sizeof(MatTest));
 
   
    mat1.material=OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);
    
    mat2.material=METAL;
    printf("Material created, set to %s\n", names[mat2.material]);
    

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
	PhysicalBox pb1;
	PhysicalBox pb2;
	PhysicalBox pb3;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    
    ctor_PhysicalBox_dddMT(&pb1,8, 6, 4,PLASTIC);
    
    ctor_PhysicalBox_MT(&pb2,WOOD);
   
    ctor_PhysicalBox_ddd(&pb3,7,7,7);
    
    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4 = pb1;
    PhysicalBox_printp(&pb4);
	PhysicalBox_printp(&pb1);

    printf("pb4 %s pb1\n", pb4.box.p_length==pb1.box.p_length&&pb4.box.p_width==pb1.box.p_width&&pb4.box.p_height==pb1.box.p_height&& pb4.material.material== pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
	PhysicalBox_printp(&pb4);
	PhysicalBox_printp(&pb3);

    printf("pb4 %s pb3\n", pb4.box.p_length==pb3.box.p_length&&pb4.box.p_width==pb3.box.p_width&&pb4.box.p_height==pb3.box.p_height&& pb4.material.material== pb3.material.material? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    dtor_PhysicalBox(&pb4);
    dtor_PhysicalBox(&pb3);
    dtor_PhysicalBox(&pb2);
    dtor_PhysicalBox(&pb1);
    
}

void doWeightBox()
{
	WeightBox pw1;
	WeightBox pw2;
	WeightBox pw3;
	WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    
    ctor_WeightBox_dddd(&pw1,8, 6, 4, 25);
    
    
    ctor_WeightBox_dddd(&pw2,1, 2, 3, 0.0);
    
    ctor_WeightBox_dddd(&pw3,10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
    
    copyctor_WeightBox(&pw4,&pw1);
    WeightBox_printw(&pw4);
    WeightBox_printw(&pw1);
    printf("pw4 %s pw1\n", pw4.box.p_length==pw1.box.p_length&&pw4.box.p_width==pw1.box.p_width&&pw4.box.p_height==pw1.box.p_height&& pw4.weight== pw1.weight ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    assigmentctor_WeightBox(&pw4,&pw3);
     WeightBox_printw(&pw4);
    WeightBox_printw(&pw3);
    printf("pw4 %s pw3\n", pw4.box.p_length==pw3.box.p_length&&pw4.box.p_width==pw3.box.p_width&&pw4.box.p_height==pw3.box.p_height&& pw4.weight== pw3.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    dtor_WeightBox(&pw4);
    dtor_WeightBox(&pw3);
    dtor_WeightBox(&pw2);
    dtor_WeightBox(&pw1);
}




int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");
    return 0;

}
