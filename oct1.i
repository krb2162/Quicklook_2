/* oct1.i */
 %module oct1
 %{
 #define SWIG_FILE_WITH_INIT
 /* Put header files here or function declarations like below */
 #include <fitsio.h>
 void modifyArray(int sizex, int sizey, double *npyArray2D);
 extern double My_variable;
 extern int fact(int n);
 extern int my_mod(int x, int y);
 extern int name(int x);
 extern int alison(void);
 extern int hi(int *x);
// extern int** hello(char *filename);
// extern void hello(char* file_name, int sizex, int sizey, int *cleaned_array);
 %}

 %include "numpy.i"

 %init %{
 import_array();
 %}
%apply (int DIM1, int DIM2, double* INPLACE_ARRAY2) {(int sizex, int sizey, double *npyArray2D)};
//%apply(char* filename, int DIM1, int DIM2, int* ARGOUTVIEW_ARRAY2){(char* filename, int sizex, int sizey, int *arr)}
//%apply(int DIM1, int DIM2, int* ARGOUTVIEW_ARRAY2){(int sizex, int sizey, int *npyArray2D)}
//DATA_TYPE ARGOUT_ARRAY2[ANY][ANY]
   
  
//%include typemap.i
 #include <fitsio.h>
 void modifyArray(int sizex, int sizey, double *npyArray2D);
 extern double My_variable;
 extern int fact(int n);
 extern int my_mod(int x, int y);
 extern int name(int x);
 extern int alison(void);
 extern int hi(int *x);
// extern int** hello(char *filename);
//extern ARGOUTVIEW_ARRAY2 hello(char* file_name);
// extern void hello(char* file_name, int sizex, int sizey, int *cleaned_array);

