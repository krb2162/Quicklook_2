
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fitsio.h"
 
 double My_variable = 3.0;
 
void modifyArray(int sizex, int sizey, double *npyArray2D) {
    /*for (int i=0; i<sizex; i++) {
  	for (int j=0; j<sizey; j++) {
  		int n=i*sizey+j;

  		npyArray2D[n] = i*j;
  	}
  }*/
/*    for(int i=0; i<sizey; i++){
	npyArray2D[i]=5;
}
    for( int k=sizey; k < sizey*sizex+1; k++)
	{
		npyArray2D[k]=6;
	}*/
    char *file_name = "FirstLight.fits";    
    // this is the pointer to the fits file
    fitsfile *fptr;      /* FITS file pointer, defined in fitsio.h */
        //pointer to val, a buffer of values size 1000, and an array of nullstr that holds just an asterisk
    char *val, value[1000], nullstr[]="*";
        //there is a string that is the size of the FLEN_KEYWORD which needs to be looked up, because built in, and same for colname
    char keyword[FLEN_KEYWORD], colname[FLEN_VALUE];
        //status starts at 0
    int status = 0;   /*  CFITSIO status value MUST be initialized to zero!  */

    int hdunum, hdutype, ncols, ii, anynul, dispwidth[1000];
    int firstcol, lastcol = 0, linewidth;
    long jj, nrows;
    int count = 0;
        //open file
    if (!fits_open_file(&fptr, file_name, READONLY, &status))
    {
        //this gets the primary array ( assume 1 is returned if it worked correctly)
      if ( fits_get_hdu_num(fptr, &hdunum) == 1 )
          /* This is the primary array;  try to move to the */
          /* first extension and see if it is a table */
          fits_movabs_hdu(fptr, 2, &hdutype, &status);
       else
          fits_get_hdu_type(fptr, &hdutype, &status); /* Get the HDU type */

      if (hdutype == IMAGE_HDU)
          printf("Error: this program only displays tables, not images\n");
      else
      {
        fits_get_num_rows(fptr, &nrows, &status);
        fits_get_num_cols(fptr, &ncols, &status);

        /* find the number of columns that will fit within 80 characters */
        //lastcol innitialized to 0 so it will be incremented to be less than ncol

          linewidth = 0;
          firstcol = lastcol+1;
          for (lastcol = firstcol; lastcol <= ncols; lastcol++) {
             fits_get_col_display_width
                (fptr, lastcol, &dispwidth[lastcol], &status);
             linewidth += dispwidth[lastcol] + 1;
             if (linewidth > 80)break;
          }
          if (lastcol > firstcol)lastcol--;  /* the last col didn't fit */
	// create two arrays one that hold the time, the other that holds the count.
          /* print each column, row by row (there are faster ways to do this) */
          val = value;

        //array for id's
        int array_ids[nrows];
        //array for count
        int array_count[nrows];
        //to iterate through the arrays
        int entry_index = 0;
        //to compare when time's change to change count/times array
        char time1[1000];
        //take first column
        ii = firstcol;
        int final=1;
	int start_time;
        //iterate down all rows


        for (jj = 1; jj <= nrows && !status; jj++) {

                int status = 0;
              /* read value as a string, regardless of intrinsic datatype */
              if (fits_read_col_str (fptr,ii,jj, 1, 1, nullstr, &val, &anynul, &status) )
                     break;  /* jump out of loop on error */
//            printf("%-*s ",dispwidth[ii], value);

                //compare integer value to 0 to skip void data "throw out"
                if(atoi(value)!=0)
                {
                        //access the time stamp to make a count which is the lastcol
                        if(fits_read_col_str(fptr,lastcol,jj,1,1,nullstr,&val, &anynul, &status))
                        {
                                printf("error reading column data in fits file\n");
                                break;
                        }
                        else if(count == 0)
                        {
                                //happens on first instance of a time
                                printf("%d\n", atoi(value));
                                strcpy(time1, value);
                                count++;
                        }
                        else if(strcmp(value, time1)==0)
                        {
                                count++;
                                final = count;
                        }
                        else
                        {
                                //array_ids[entry_index]=atoi(time1);
        			npyArray2D[entry_index]=atoi(time1);

				npyArray2D[1000+entry_index] = count;
				entry_index++;
                                count = 1;
                                strcpy(time1,value);
                        }

                }
//          }

	 array_count[1000+entry_index] = final;
        array_ids[entry_index]=atoi(time1);
      }//close else?
/*        int iiii=0;
       while(array_count[iiii])
       {
//           printf(" %d, ",array_count[iiii++]);
       }
        iiii=0;
       while(array_ids[iiii])
       {
 //         printf(" %d, ",array_ids[iiii++]);
       }
//       int* cleaned_data [2];
      //  cleaned_data[0]=array_count;
      //  cleaned_data[1]=array_ids;
*/
}//close if?

      fits_close_file(fptr, &status);
    }

    if (status) fits_report_error(stderr, status); /* print any error message */
//    return(cleaned_data);
}





//}

 int fact(int n) {
     if (n <= 1) return 1;
     else return n*fact(n-1);
 }
 
 int my_mod(int x, int y) {
     return (x%y);
 }

 int name(int n) {
	return n;
 }

 int alison(void) {
 	printf("hi\n");
	return 3;
 }
 
 int hi(int *x)
 {
	int hello=*x;
	//int balance[3] = {1,2,3};
	//hello = balance;
	return hello;
 }
 void hello(char* file_name, int sizex, int sizey, int *cleaned_data)
 {
//	static int* cleaned_data [2];
	// this is the pointer to the fits file
    fitsfile *fptr;      /* FITS file pointer, defined in fitsio.h */
        //pointer to val, a buffer of values size 1000, and an array of nullstr that holds just an asterisk
    char *val, value[1000], nullstr[]="*";
        //there is a string that is the size of the FLEN_KEYWORD which needs to be looked up, because built in, and same for colname
    char keyword[FLEN_KEYWORD], colname[FLEN_VALUE];
        //status starts at 0
    int status = 0;   /*  CFITSIO status value MUST be initialized to zero!  */

    int hdunum, hdutype, ncols, ii, anynul, dispwidth[1000];
    int firstcol, lastcol = 0, linewidth;
    long jj, nrows;
    int count = 0;
        //open file
    if (!fits_open_file(&fptr, file_name, READONLY, &status))
    {
        //this gets the primary array ( assume 1 is returned if it worked correctly)
      if ( fits_get_hdu_num(fptr, &hdunum) == 1 )
          /* This is the primary array;  try to move to the */
          /* first extension and see if it is a table */
          fits_movabs_hdu(fptr, 2, &hdutype, &status);
       else
          fits_get_hdu_type(fptr, &hdutype, &status); /* Get the HDU type */

      if (hdutype == IMAGE_HDU)
          printf("Error: this program only displays tables, not images\n");
      else
      {
        fits_get_num_rows(fptr, &nrows, &status);
        fits_get_num_cols(fptr, &ncols, &status);

        /* find the number of columns that will fit within 80 characters */
        //lastcol innitialized to 0 so it will be incremented to be less than ncol

          linewidth = 0;
          firstcol = lastcol+1;
          for (lastcol = firstcol; lastcol <= ncols; lastcol++) {
             fits_get_col_display_width
                (fptr, lastcol, &dispwidth[lastcol], &status);
             linewidth += dispwidth[lastcol] + 1;
             if (linewidth > 80)break;
          }
          if (lastcol > firstcol)lastcol--;  /* the last col didn't fit */

        // create two arrays one that hold the time, the other that holds the count.
          /* print each column, row by row (there are faster ways to do this) */
          val = value;

        //array for id's
        int array_ids[nrows];
        //array for count
        int array_count[nrows];
        //to iterate through the arrays
        int entry_index = 0;
        //to compare when time's change to change count/times array
        char time1[1000];
        //take first column
        ii = firstcol;
        int final=1;
	//iterate down all rows
        for (jj = 1; jj <= nrows && !status; jj++) {

                int status = 0;
              /* read value as a string, regardless of intrinsic datatype */
              if (fits_read_col_str (fptr,ii,jj, 1, 1, nullstr, &val, &anynul, &status) )
                     break;  /* jump out of loop on error */
//            printf("%-*s ",dispwidth[ii], value);

                //compare integer value to 0 to skip void data "throw out"
                if(atoi(value)!=0)
                {
                        //access the time stamp to make a count which is the lastcol
                        if(fits_read_col_str(fptr,lastcol,jj,1,1,nullstr,&val, &anynul, &status))
                        {
                                printf("error reading column data in fits file\n");
                                break;
                        }
                        else if(count == 0)
                        {
                                //happens on first instance of a time
//                                printf("%d\n", atoi(value));
                                strcpy(time1, value);
                                count++;
                        }
                        else if(strcmp(value, time1)==0)
                        {
                                count++;
                                final = count;
                        }
                        else
                        {
                                array_ids[entry_index]=atoi(time1);
                                array_count[entry_index++] = count;
                                count = 1;
                                strcpy(time1,value);
                        }

                }
//          }
        array_count[entry_index] = final;
        array_ids[entry_index]=atoi(time1);
      }//close else?
       /* int iiii=0;
       while(array_count[iiii])
       {
//           printf(" %d, ",array_count[iiii++]);
       }
        iiii=0;
       while(array_ids[iiii])
       {
  //         printf(" %d, ",array_ids[iiii++]);
       }
//       int* cleaned_data [2];
//	cleaned_data[0]=array_count;
	//cleaned_data[1]=array_ids;
	*/
}//close if?

      fits_close_file(fptr, &status);
    }

    if (status) fits_report_error(stderr, status); /* print any error message */
//    return(cleaned_data); 
}
