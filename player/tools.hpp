//					-*- mode:c++; tab-width:4 -*-
/* file: tools.hpp ---------------------------------------------------------- */
/* header file for the tools library.                                         */
/* -------------------------------------------------------------------------- */
/* Local definitions and portability code.                                    */
/* Please enter your own system, name, class, and printer stream name.        */
/* -------------------------------------------------------------------------- */
#ifndef TOOLSPP
#define TOOLSPP

#define NAME    "Alice Fischer"
#define CLASS   "CS 626"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>
using namespace std;

#include <cstdio>      // for NULL
#include <cstdlib>     // for malloc() and calloc()
#include <cmath>
#include <cstring>
#include <ctime>       // for time_t, time() and ctime()
#include <climits>     // for INT_MAX
#include <cfloat>      // for DOUBLE_MAX, etc.
#include <cstdarg>     // for functions with variable # of arguments

typedef FILE* cstream;
typedef const char* cstring;

/* -------------------------------------------------------------------------- */
/* Macros for debugging.                                                      */
/* -------------------------------------------------------------------------- */
#define DUMPp(p) "\n" <<"    " #p " @ " <<&p <<"    value = " <<p <<"    " #p " --> " <<*p 
#define DUMPv(k) "\n" <<"    " #k " @ " <<&k <<"    value = " <<k 

/* --------------------------------------------------------------------------- /
/  Portability code.                                                           /
/  Portable definition; requires user to #define name of local system.         /
/  -------------------------------------------------------------------------- */
void    clearscreen( void );             
void    bye( void );                                    

/* -------------------------------------------------------------------------- */
/* Routine screen and process management.------------------------------------- */
/* -------------------------------------------------------------------------- */
void     fbanner( ostream& fout );
void  	 banner();
void 	 delay( int );
void     hold( void );                                    
void     say( const char* format, ... );

/* -------------------------------------------------------------------------- */
/* I/O Extension.------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */
istream& flush( istream& is ); 		// Used in cin >> x >> flush;

/* -------------------------------------------------------------------------- */
/* Error handling. ---------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void    fatal( const char* format, ... );
void    cleanline( cstream ff );     

/* -------------------------------------------------------------------------- */
/* time and date. ------------------------------------------------------------*/
/* -------------------------------------------------------------------------- */
void   when( char* date, char* hour );
char*  today( char* date );
char*  oclock( char* hour );
#endif // ifndef TOOLSPP
