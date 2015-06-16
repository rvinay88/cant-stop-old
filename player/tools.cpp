//					-*- mode:c++; tab-width:4 -*-
/* File: tools.cpp - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /
/  the tools library.                                                          /
/  Assorted utility routines for use in C programs.                            /
/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "tools.hpp"

/* -------------------------------------------------------------------------- */
/* I/O Extension.------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
** Used to flush the cin buffer as in cin >> x >> flush;  or cin >> flush;    */
istream&
flush( istream& is )
{
	return is.seekg( 0, ios::end );
}

/* --------------------------------------------------------------------------- /
/  Routine screen and process management.                                      /
/ --------------------------------------------------------------------------- */
void bye( void ) { cerr << "\n\nNormal termination.\n" ; }

/* -----------------------------------------------------------------------------
** Print a neat header on the output.                                        
*/
void 
fbanner( ostream& fout )
{   char date[16], time[10];
	setlinebuf(stdout);
	setlinebuf(stdin);
    when(date, time);
    fout<< "\n\n\n";
	fout << "\n--------------------------------------------------------------\n"
         << "\t" << NAME 
		 << "\n\t" << CLASS << "\n\t" <<  date << "\t" << time << endl
		 << "--------------------------------------------------------------\n";
}

void banner() { fbanner( cout ); }

/* ---------------------------------------------------------------------------- 
** this function is for error messages.  
**    It takes a format argument followed by any number of data arguments.
**    It formats and prints an error message, then exits.                
*/
void
fatal (const char* format, ...)
{   va_list vargs;                               /* optional arguments */

	cout << flush; 
    va_start(vargs, format);
    vfprintf(stderr, format, vargs);
    fprintf(stderr, "\n");
    fputs( "\n Error exit; press '.' and 'Enter' to continue", stderr );
    while (getchar() != '.')  /* tight loop */ ;    
    exit(1);
}

/* --------------------------------------------------------------------------
**  Print message and wait for the user to type a newline.                     
*/
void 
hold( void )                                    
{     
	 cerr << endl << endl << " Press 'Enter' to continue...";
	 cin >> flush;
	 cin.get();
	 cin >> flush;
}                                                      

/* --------------------------------------------------------------------------
** this is a handy function for messages of all sorts.  
**  It formats, prints, and rings the bell.                   
**  It accepts a format followed by a variable number of data items to print.
*/
void
say (const char* format, ...)
{   va_list vargs;                               /* optional arguments */

    va_start(vargs, format);
    vfprintf(stderr, format, vargs);
    fprintf(stderr, "\n");
}
/* ---------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------- /
/  Functions for handling the time anddate.                                    /
/ --------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
** Store the current date and time in the arguments.  
**      System's date format is: "Fri Jun  9 10:15:55 1995\n"  
**      After extraction, date is: "Fri Jun  9 1995"    hour is: "10:15:55" 
*/
void 
when( char* date, char* hour)
{   
    time_t now;         /* Stores an integer encoding of the date and time.  */
    char* nowstring;    /* Stores the date and time in a readable form.      */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);                   /* Convert to string form.    */
    strncpy( date, nowstring, 10);             /* Extract day, month, date.  */
    strncpy( &date[10], &nowstring[19], 5);    /* Extract space and year.    */
    date[15]  = '\0';                          /* Add the string terminator. */       
    strncpy( hour, &nowstring[11], 8);         /* Copy hour:minutes:seconds. */
    hour[8]  = '\0';                           /* Add the string terminator. */
}

/* --------------------------------------------------------------------------
** Store the current date in the argument and return a pointer to it. 
**      date format is: "Fri Jun  9 1995"                                    
*/
char*  
today( char* date )
{   
    time_t now;          /* Stores an integer encoding of the date and time. */ 
    char* nowstring;     /* Stores the date and time in a readable form.     */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);                   /* Convert to string form.    */
    strncpy( date, nowstring, 10);             /* Extract day, month, date.  */
    strncpy( &date[10], &nowstring[19], 5);    /* Extract space and year.    */
    date[15]  = '\0';                          /* Add the string terminator. */       
    return( date );  
}

/* --------------------------------------------------------------------------
** Store the current time in hour and return a pointer to it.   
**      hour format is: "10:15:55"                                           
*/
char* 
oclock( char* hour)
{   
    time_t now;          /* Stores an integer encoding of the date and time. */ 
    char* nowstring;     /* Stores the date and time in a readable form.     */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);              /* Convert to string form.         */
    strncpy( hour, &nowstring[11], 8);    /* Extract hour, minutes, seconds. */
    hour[8]  = '\0';                      /* Add the string terminator.      */
    return( hour );  
}





