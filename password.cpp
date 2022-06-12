#pragma once
#include"class.h"
#include"book.h"
void Lib::pass()  // mat khau cho nhan vien
{
	
SET_COLOR(14);
cout<<"            _                 _   "<<endl;    
cout<<"           | |    ___  __ _  (_) _ _  "<<endl;
cout<<"           | |__ / _ \\/ _` | | || ' \\ "<<endl;
cout<<"           |____|\\___/\\__, | |_||_||_|"<<endl;
cout<<"                      |___/           "<<endl;
SET_COLOR(6);	
	
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\t>> Enter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\t=> Password Erro!.\n\n\t\tPlease enter again...........\n";
        getch();
        system("cls");
        get();
    }
    
    
}

void Lib::password() // doi mat khau cho nhanh vien
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
SET_COLOR(14);	
cout<<"                          __________                                                    .___"<<endl;
cout<<"                          \\______   \\_____     ______  ________  _  __ ____ _______   __| _/"<<endl;
cout<<"                           |     ___/\\__  \\   /  ___/ /  ___/\\ \\/ \\/ //  _ \\\\_  __ \\ / __ | "<<endl;
cout<<"                           |    |     / __ \\_ \\___ \\  \\___ \\  \\     /(  <_> )|  | \\// /_/ | "<<endl;
cout<<"                           |____|    (____  //____  >/____  >  \\/\\_/  \\____/ |__|   \\____ | "<<endl;
cout<<"                                         \\/      \\/      \\/                             \\/  "<<endl;
SET_COLOR(6);
    cout<<"\n\n\t\t>>Enter old password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t>> Passwords no more than 20 characters and special characters <<\n\n";
        cout<<"\n\t\tEnter new password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tNot in accordance with the password requirements \n\n\t\tPlease enter again...........";
                getch();
                system("cls");
                librarian();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tThe password changed successfully..";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        get();
    }
    else
    {
        cout<<"\n\n\t\tIncorrect password.....\n";
        cout<<"\n\t\tEnter 1 to try again or 2 to exit >> ";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}
