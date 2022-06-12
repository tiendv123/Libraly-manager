#pragma once
#include "header.h"

class Lib
{
	public:
		 char bookname[100];
		char auname[50];
		char sc[20];
		char sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
	   	  void get();
          void student();
          void pass();
          void librarian();
          void password();
          
};

