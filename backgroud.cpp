#include "header.h"
#include "book.h"

void SET_COLOR(int color) 
{
   WORD wColor;
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    { wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
    } 
}




void backgroud(){
	SET_COLOR(6);
cout<<"                                         __      __     _                      "<<endl;
cout<<"                                         \\ \\    / /___ | | __  ___  _ __   ___ "<<endl;
cout<<"                                          \\ \\/\\/ // -_)| |/ _|/ _ \\| '  \\ / -_)"<<endl;
cout<<"                                           \\_/\\_/ \\___||_|\\__|\\___/|_|_|_|\\___|"<<endl;
                                       
//========================================================================================================================									   		
		SET_COLOR(14);
cout<<"                         _____     _____  ______   _______          _       _______   ____  ____  "<<endl;
cout<<"                        |_   _|   |_   _||_   _ \\ |_   __ \\        / \\     |_   __ \\ |_  _||_  _| "<<endl;
cout<<"                          | |       | |    | |_) |  | |__) |      / _ \\      | |__) |  \\ \\  / /   "<<endl;
cout<<"                          | |   _   | |    |  __'.  |  __ /      / ___ \\     |  __ /    \\ \\/ /    "<<endl;
cout<<"                         _| |__/ | _| |_  _| |__)| _| |  \\ \\_  _/ /   \\ \\_  _| |  \\ \\_  _|  |_    "<<endl;
cout<<"                        |________||_____||_______/|____| |___||____| |____||____| |___||______|   "<<endl;
                                                                                                                                                    
//================================================================================================================   
SET_COLOR(6);                               
cout<<"                                                                        ____ "<<endl;
cout<<"                                           __ _  _ _  ___  _  _  _ __  |__  |"<<endl;
cout<<"                                          / _` || '_|/ _ \\| || || '_ \\   / / "<<endl;
cout<<"                                          \\__, ||_|  \\___/ \\_,_|| .__/  /_/  "<<endl;
cout<<"                                          |___/                 |_|          "<<endl;
                                        
//===========================================================================================================================                                                                                                      
	SET_COLOR(6);
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"\n\t\t>> Pham Quoc Cong - 19071590"<<endl;
	cout<<"\n\t\t>> xxxx xxxx xxxx - ********"<<endl;
	cout<<"\n\t\t>> xxxx xxxx xxxx - ********"<<endl;
	cout<<"\n\t\t>> xxxx xxxx xxxx - ********"<<endl;
	cout<<"\n\t\t>> xxxx xxxx xxxx - ********"<<endl;
	cout<<""<<endl;
	SET_COLOR(14);
	cout<<"                                     ----- Cau truc du lieu & giai thuat -----"<<endl;
}
