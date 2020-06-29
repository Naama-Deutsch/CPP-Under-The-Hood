
#include "cpp2c_encapsulation_defs.h"
const char* SHELF_DEF_MSG = "The total volume held on the shelf is";
const char* message="The total volume held on the shelf is";


/* Box */


void ctor_box_d(Box* const this,double dim)
{
	this->p_length=dim;
	this->p_width=dim;
	this->p_height=dim;
	box_print(this);
	
}
void ctor_box_ddd(Box* const this,double l, double w, double h)
{
	this->p_length=l;
	this->p_width=w;
	this->p_height=h;
	box_print(this);
}
void dtor_box(Box* this)
{
	printf("Box destructor, %f x %f x %f\n", this->p_width, this->p_height, this->p_length);
}
void box_print(const Box* this)
{
	printf("Box: %f x %f x %f\n", this->p_length,this->p_width,this->p_height); 
}
Box* box_operator_dupeq_d(Box* this,double mult)
{
	this->p_length*=mult;
	this->p_width*=mult;
	this->p_height*=mult;
	return this;
}

/* Shelf */
void shelf_setbox(Shelf* this,int index, const Box* dims)
{
	this->boxes[index]=*dims;
}
double shelf_getvolume(const Shelf* this)
{
	double vol = 0;
   	for (size_t i = 0; i < SHELF_NUM_BOXES; ++i)
        	vol += (this->boxes[i].p_length*this->boxes[i].p_width*this->boxes[i].p_height);
	return vol;
}
void shelf_print(const Shelf* this)
{
	printf("%s %f\n", message, shelf_getvolume(this));
}

