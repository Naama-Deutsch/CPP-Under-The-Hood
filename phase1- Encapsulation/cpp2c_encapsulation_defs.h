#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__
#include "stdbool.h"
#include <stdio.h>
#define SHELF_NUM_BOXES 3

/* Box */

typedef struct Box 
{
	double p_length;
	double p_width;
	double p_height;
}Box;
/* Box Defs */

void ctor_box_d(Box* const this,double dim);
void ctor_box_ddd(Box* const this,double l, double w, double h);
void dtor_box(Box* this);
Box* box_operator_dupeq_d(Box* this,double mult);
void box_print(const Box* this);


/* Shelf */
typedef struct Shelf 
{
	Box boxes[SHELF_NUM_BOXES];
}Shelf;


/* Shelf Defs */
void shelf_setbox(Shelf* this,int index, const Box* dims);
double shelf_getvolume(const Shelf* this);

void shelf_print(const Shelf* this);



#endif // __CPP2C_ENCAPSULATION_DEFS_H__

