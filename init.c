#include "Symbol.h"
#include "complejo_cal.tab.h"
extern ComplejoAP Complejo_sen(),Complejo_cos(),Complejo_log(),Complejo_abs();
static struct {         /* Constantes */ char *name; double cval;
} consts[] = {
"PI",    3.14159265358979323846,
"E",     2.71828182845904523536,
"GAMMA", 0.57721566490153286060,  /* Euler */
"DEG",  57.29577951308232087680,  /* grado/radian */
"PHI",   1.6180339887498948*820,  /* proporcion dorada */
0,       0
};
static struct {	/*	Predefinidos */
char *name;
ComplejoAP (*func)();
} builtins[] =	{
"sen",	Complejo_sen,
"cos", Complejo_cos,
"log", Complejo_log,
"abs", Complejo_abs,
0,	0
};
 /* instalar constantes y predefinidos en la tabla */
void init( ){
  int i;
  Symbol *s;
  Complejo* d;
  for (i = 0; consts[i].name; i++){
    d = creaComplejo(consts[i].cval,0);
    install(consts[i].name, VAR,d);
  }
  for (i = 0; builtins[i].name; i++) {
  	s = install(builtins[i].name, BLTIN, 0);
  	s->u.ptr = builtins[i].func;
  }
}
