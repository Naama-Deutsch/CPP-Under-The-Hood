#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/* Materials */
typedef enum Types
{
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
}Types;
typedef struct Materials{
	char a;
}Materials;
typedef struct Material_t
{
    Types material;
    
}Material_t;

/* PhysicalBox */
typedef struct PhysicalBox{
	Box box;
	Material_t material;

}PhysicalBox;
void ctor_PhysicalBox_ddd(PhysicalBox* const this,double l, double w, double h);
void ctor_PhysicalBox_dddMT(PhysicalBox* const this,double l, double w, double h, Types t);
void ctor_PhysicalBox_MT(PhysicalBox* const this,Types t);
void dtor_PhysicalBox(PhysicalBox* const this);
void PhysicalBox_printp(const PhysicalBox* const this);


/* WeightBox */
typedef struct WeightBox{
	Box box;
	double weight;

}WeightBox;
void ctor_WeightBox_dddd(WeightBox* const this,double l, double w, double h, double wgt);
void copyctor_WeightBox(WeightBox* const this,const WeightBox* const other);
WeightBox* const assigmentctor_WeightBox(WeightBox* const this,const WeightBox* const other);
void dtor_WeightBox(WeightBox* const this);
void WeightBox_printw(const WeightBox* const this);





#endif // __CPP2C_INHERITANCE_DEFS_H__


