
#include "cpp2c_encapsulation_defs.h"
extern const char* SHELF_DEF_MSG;
extern const char* message;
static Box largeBox;
static Box box88;	
static Box box99;

void this_func()
{
	static bool s_is_first=true;
    printf("\n--- this_func() ---\n\n"); 

    if(s_is_first)
    {
    	ctor_box_ddd(&box99,99,99,99);
    	s_is_first=false;
    }
    
    box_operator_dupeq_d(&box99,10);
}

void that_func()
{
	static bool s_is_first=true;
    printf("\n--- that_func() ---\n\n"); 
    
    if(s_is_first)
    {
    	ctor_box_ddd(&box88,88,88,88);
    	s_is_first=false;
    }
    
    box_operator_dupeq_d(&box88,10);
}

void do_boxes()
{

    printf("\n--- Start do_boxes() ---\n\n");

    Box b1;
    Box b2;
    ctor_box_d(&b1,3);
    
    ctor_box_ddd(&b2,4, 5, 6);
    printf("b1 volume: %f\n", b1.p_length*b1.p_width*b1.p_height);
    printf("b2 volume: %f\n", b2.p_length*b2.p_width*b2.p_height);
	box_operator_dupeq_d(&b1,1.5);
	box_operator_dupeq_d(&b2,0.5);
  	printf("b1 volume: %f\n",  b1.p_length*b1.p_width*b1.p_height);
    printf("b2 volume: %f\n", b2.p_length*b2.p_width*b2.p_height);
    Box b3 = b2;
    Box b4=b2;
    box_operator_dupeq_d(&b4,3);
    //ctor_box_ddd(&b4,b2.p_width*3,b2.p_length*3,b2.p_height*3);
    printf("b3 %s b4\n", (b3.p_length==b4.p_length&&b3.p_width==b4.p_width&&b3.p_height==b4.p_height) ? "equals" : "does not equal");
	box_operator_dupeq_d(&b3,1.5);
	box_operator_dupeq_d(&b4,0.5);
    printf("Now, b3 %s b4\n", (b3.p_length==b4.p_length&&b3.p_width==b4.p_width&&b3.p_height==b4.p_height) ? "equals" : "does not equal");
    
    printf("\n--- End do_boxes() ---\n\n");
    dtor_box(&b1);
    dtor_box(&b2);
    dtor_box(&b3);
    dtor_box(&b4);
  
}

void do_shelves()
{

    printf("\n--- start do_shelves() ---\n\n");

    Box aBox;
	
    Shelf aShelf;
    Box b1;
    Box b2;
    Box b3;
    ctor_box_d(&aBox,5);
    ctor_box_d(&b1,1);
    ctor_box_d(&b2,1);
    ctor_box_d(&b3,1);
    aShelf.boxes[0]=b1;
    aShelf.boxes[1]=b2;
    aShelf.boxes[2]=b3;
	shelf_print(&aShelf);
	shelf_setbox(&aShelf,1,&largeBox);
	shelf_setbox(&aShelf,0,&aBox);
    shelf_print(&aShelf);
    message="This is the total volume on the shelf:";
   	shelf_print(&aShelf);
    message="Shelf's volume:";
  	shelf_print(&aShelf);
    ctor_box_ddd(&b1,2, 4, 6);
   	shelf_setbox(&aShelf,1,&b1);
    ctor_box_d(&b2,2);
    shelf_setbox(&aShelf,2,&b2);
    shelf_print(&aShelf);
	
    printf("\n--- end do_shelves() ---\n\n");
    dtor_box(&aBox);
	dtor_box(&b1);
	dtor_box(&b2);
	dtor_box(&b3);
}

int main()
{
	ctor_box_ddd(&largeBox,(double)10,(double)20,(double)30);
    printf("\n--- Start main() ---\n\n");
	
    do_boxes();

    this_func();
    this_func();
    this_func();
    that_func();
    that_func();

    do_shelves();
        
	printf("\n--- End main() ---\n\n");
	 
    dtor_box(&largeBox);
	dtor_box(&box88);
	dtor_box(&box99);
    return 0;
}

