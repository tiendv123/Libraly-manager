#pragma once
#include"header.h"
#include"class.h"
#include"book.h"
void Lib::get()  
{

   int i;
SET_COLOR(14);
cout<<"                 .____     .__ ___.                                       ________         .__       .___" << endl;
cout<<"                 |    |    |__|\\_ |__ _______ _____  _______  ___.__.    /  _____/   ____  |  |    __| _/" << endl;
cout<<"                 |    |    |  | | __ \\\\_  __ \\\\__  \\ \\_  __ \\<   |  |   /   \\  ___  /  _ \\ |  |   / __ | " << endl;
cout<<"                 |    |___ |  | | \\_\\ \\|  | \\/ / __ \\_|  | \\/ \\___  |   \\    \\_\\  \\(  <_> )|  |__/ /_/ | " << endl;
cout<<"                 |_______ \\|__| |___  /|__|   (____  /|__|    / ____|    \\______  / \\____/ |____/\\____ | " << endl;
cout<<"                         \\/         \\/             \\/         \\/                \\/                    \\/ " << endl; SET_COLOR(6);               
cout<<"                                                        _  /_  _  _ _  _ "<<endl;
cout<<"                                                   |/|//_'//_ /_// / //_'"<<endl;
cout<<"                                                                         "<<endl;
SET_COLOR(6);                                  
cout<<"                                _  ___  ___  ___  ___  ___  ___  ___  ___   ___  ___  _  "<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_| "<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|     >> Choose which method to use:                |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          1. Customer.                             |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          2. Staff.                                |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          3. Exit.                                 |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;                                 
cout<<"                               |_| ___  ___  ___  ___  ___  ___  ___  ___   ___  ___ |_|"<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_|"<<endl;
		SET_COLOR(6);
        cout<<"\n\t\t>> ";SET_COLOR(14);
        cin>>i;
		SET_COLOR(6);
        if(i==1)
        {
            system("cls");
            student();   
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"=> Invalid selection, please choose again......";
            getch();
            system("cls");
            get();
        }
}

void Lib::student()  
{
	char fileName[] = "users.txt";
	Book a[50];
	int soLuongSach = inputFile(a, fileName);
	char choice;
	replace_string_underscores(a, soLuongSach);
	cout<<""<<endl;
    int i;
SET_COLOR(14);
cout<<"                 .____     .__ ___.                                       ________         .__       .___" << endl;
cout<<"                 |    |    |__|\\_ |__ _______ _____  _______  ___.__.    /  _____/   ____  |  |    __| _/" << endl;
cout<<"                 |    |    |  | | __ \\\\_  __ \\\\__  \\ \\_  __ \\<   |  |   /   \\  ___  /  _ \\ |  |   / __ | " << endl;
cout<<"                 |    |___ |  | | \\_\\ \\|  | \\/ / __ \\_|  | \\/ \\___  |   \\    \\_\\  \\(  <_> )|  |__/ /_/ | " << endl;
cout<<"                 |_______ \\|__| |___  /|__|   (____  /|__|    / ____|    \\______  / \\____/ |____/\\____ | " << endl;
cout<<"                         \\/         \\/             \\/         \\/                \\/                    \\/ " << endl; SET_COLOR(6);               
cout<<"                                                        _  /_  _  _ _  _ "<<endl;
cout<<"                                                   |/|//_'//_ /_// / //_'"<<endl;
cout<<"                                                                         "<<endl;
SET_COLOR(6);                                  
cout<<"                                _  ___  ___  ___  ___  ___  ___  ___  ___   ___  ___  _  "<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_| "<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|     >> Hello, how can we help you?                |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          1. List of library books.                |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          2. Find books.                           |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          3. Back.                                 |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|                                                   |_| "<<endl;                                 
cout<<"                               |_| ___  ___  ___  ___  ___  ___  ___  ___   ___  ___ |_|"<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_| "<<endl;
        SET_COLOR(6);
        cout<<"\n\t\t>> ";SET_COLOR(14);
        cin>>i;SET_COLOR(14);
            if(i==1)
			{
				system("cls");
				cout<<""<<endl;
				cout<<"                                          _     _  _                          " << endl;
        cout<<"                                         | |   (_)| |__  _ _  __ _  _ _  _  _ " << endl;
        cout<<"                                         | |__ | || '_ \\| '_|/ _` || '_|| || |" << endl;
        cout<<"                                         |____||_||_.__/|_|  \\__,_||_|   \\_, |" << endl;
        cout<<"                                                                         |__/ " << endl;
        cout<<"                                                    --- Welcome --- " << endl;SET_COLOR(6);
				
            if (soLuongSach <= 0)
			{
				cout<<"No information available, please enter information."<<endl;
			}
			else
			{
				Sort(a, soLuongSach);
				listBook(a, soLuongSach);
			}
			pressAnyKey();
			student();
			}
			
              
            else if(i==2)
			{SET_COLOR(6);
				system("cls");
				cout<<""<<endl;
				cout<<"                >>Please choose a search method:"<<endl;
				
               if (soLuongSach <= 0)
			{
				printf("No information available, please enter information.");
			}
			else
			{
				Search(a, soLuongSach);
			}
			pressAnyKey();
			student();
            }
            else if(i==3)
            {SET_COLOR(6);
            	system("cls");
                get();
            }
            else
            {SET_COLOR(6);
                cout<<"=> Invalid selection, please choose again......";
                getch();
                system("cls");
                student();
            }
            
}

void Lib::librarian() 
{
    int i;
SET_COLOR(14);
cout<<"                 .____     .__ ___.                                       ________         .__       .___" << endl;
cout<<"                 |    |    |__|\\_ |__ _______ _____  _______  ___.__.    /  _____/   ____  |  |    __| _/" << endl;
cout<<"                 |    |    |  | | __ \\\\_  __ \\\\__  \\ \\_  __ \\<   |  |   /   \\  ___  /  _ \\ |  |   / __ | " << endl;
cout<<"                 |    |___ |  | | \\_\\ \\|  | \\/ / __ \\_|  | \\/ \\___  |   \\    \\_\\  \\(  <_> )|  |__/ /_/ | " << endl;
cout<<"                 |_______ \\|__| |___  /|__|   (____  /|__|    / ____|    \\______  / \\____/ |____/\\____ | " << endl;
cout<<"                         \\/         \\/             \\/         \\/                \\/                    \\/ " << endl; SET_COLOR(6);               
cout<<"                                                        _  /_  _  _ _  _ "<<endl;
cout<<"                                                   |/|//_'//_ /_// / //_'"<<endl;
cout<<"                                                                         "<<endl;
SET_COLOR(6);                                  
cout<<"                                _  ___  ___  ___  ___  ___  ___  ___  ___   ___  ___  _  "<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_| "<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|     >> System features:                           |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          1. Book manage.                          |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          2. Change Password                       |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|          3. Exit.                                 |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;
cout<<"                               |_|                                                   |_|"<<endl;                                 
cout<<"                               |_| ___  ___  ___  ___  ___  ___  ___  ___   ___  ___ |_|"<<endl;
cout<<"                               |_||___||___||___||___||___||___||___||___| |___||___||_|"<<endl;
        cout<<"\n\t\t>> ";
        cin>>i;
        switch(i)
        {
            case 1:
            	system("cls");
            bookMain();
            break;
            case 2:password();
                    break;
            case 3:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}


