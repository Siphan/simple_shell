/* Coding style conventions */

/* Functions have the opening brace at the beginning of the next line */
int function(int x)
{
	body of function
}

/*For all non-function statement blocks */
if (x is true) { /* opening brace last on the line */
  we do y
}

/* Do not unnecessarily use braces where a single statement will do */
if (condition)
		action();

if (condition)
		do_this();
else
		do_that();

/* Do not add spaces around (inside) parenthesized expressions */
s = sizeof(struct file);

/* Use one space around (on each side of) most binary and ternary operators */
=  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=  ?  :

/* but no space after unary operators */
&  *  +  -  ~  !  sizeof  typeof  alignof  __attribute__  defined

/* Names of macros defining constants and labels in enums are capitalized */
#define CONSTANT 0x12345

/*
 * Allocating memory
 * Preferred form for passing a size of a struct
 */
p = kmalloc(sizeof(*p), ...);
