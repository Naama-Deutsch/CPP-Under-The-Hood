#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


/* PhysicalBox Defs */
void ctor_PhysicalBox_ddd(PhysicalBox* const this, double l, double w, double h)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	ctor_box_ddd(&(this->box),l,w,h);
	//
	this->material.material=OTHER;
	printf("Material created, set to %s\n", "Other");
	//
	PhysicalBox_printp(this);
}
void ctor_PhysicalBox_dddMT(PhysicalBox* const this, double l, double w, double h, Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	ctor_box_ddd(&(this->box),l,w,h);
	//
	this->material.material=t;
	printf("Material created, set to %s\n", names[t]);
	//
	PhysicalBox_printp(this);
}
void ctor_PhysicalBox_MT(PhysicalBox* const this, Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	ctor_box_d(&(this->box),1);
	//
	this->material.material=t;
	printf("Material created, set to %s\n", names[t]);
	//
	PhysicalBox_printp(this);
}
void dtor_PhysicalBox(PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.p_length, this->box.p_width, this->box.p_height, names[this->material.material]);
	dtor_box(&(this->box));
}
void PhysicalBox_printp(const PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox, made of %s; ", names[this->material.material]);
	box_print(&(this->box));
	
}



/* WeightBox Defs */
void ctor_WeightBox_dddd(WeightBox* const this,double l, double w, double h, double wgt)
{
	ctor_box_ddd(&(this->box),l,w,h);
	this->weight=wgt;
	WeightBox_printw(this);
}

void copyctor_WeightBox(WeightBox* const this,const WeightBox* const other)
{
	ctor_box_d(&(this->box),1);
	this->weight=other->weight;
	WeightBox_printw(this);
}

void dtor_WeightBox(WeightBox* const this)
{
	printf("Destructing WeightBox; ");
	WeightBox_printw(this);
	dtor_box(&(this->box));
}
WeightBox* const assigmentctor_WeightBox(WeightBox* const this,const WeightBox* const other)
{

	this->weight=other->weight;
	return this;
}
void WeightBox_printw(const WeightBox* const this)
{
	printf("WeightBox, weight: %f; ", this->weight);
	box_print(&(this->box));
}



