#ifndef librarian_h
#define librarian_h

#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include <cstdio>


using namespace std;

string filepathlibr= "C:/Users/hezem/Documents/Login/Libr_users/";


void Libr_login()
{
    string username , password , usern , passw;
    cout<<"Enter admin username: ";
    cin>>username;

    cout<<"Enter admin password: ";
    cin>>password;

    ifstream read(username + ".txt" , ios::in);
    getline( read , usern);
    getline( read , passw);

    if( username == usern && passw == password)
    {
        cout<<"\t\t\tWELCOME"<<endl;
        read.close();
    }else 
    {
        cout<<"INVALID DETAILS!!TRY AGAIN."<<endl;
        Libr_login();
    }
}

void passwordlibr_reset()
{
    string username , password , password2;

    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter new password: ";
    cin>>password;
    cout<<"Confirm new password:";
    cin>>password2;

    if ( password2 == password)
    {
        cout<<"Password reset Successfull"<<endl;

        ofstream password_reset(username+".txt" , ios::out);

        password_reset << username <<endl;
        password_reset << password <<endl;

        password_reset.close();
    }else
    {
        cout<<"Passwords don't match! Retry"<<endl;
        passwordlibr_reset();
    }
}
void ask_Librforgotpass()
{   
    string yes_no;
    cout<<"Have you fogotten your password: ";
    cin>>yes_no;

    if ( yes_no == "yes")
    {
        passwordlibr_reset();
    }else
    {
        Libr_login();
        if (true)
        {
            cout<<"Login Success"<<endl;
        }else
        {
            passwordlibr_reset();
        }
    }
}



void Stdnew_user()
{
    //librarian to login first
    Libr_login();

    string password , username , password2;
    cout<<" Enter new username: ";
    cin>>username;
    cout<<"Enter unique password: ";
    cin>>password;

    cout<<"Confirm your password: ";
    cin>>password2;

    if( password2 == password)
    {   
        double deposit;
        cout<<"Deposit at least ksh. 1000 to account: ";
        cin>>deposit;
        if(deposit >= 1000)
        {
            cout<<"\t\t\tProfile created"<<endl;
        }else
        {
            cout<<"\t\t\tDeposit at least ksh. 1000 to account: ";
            Stdnew_user();
            
        }
        
        ofstream write( "C:/Users/hezem/Documents/Login/Student_users/"+ username + "DB.txt" , ios::out);
    
        write << username <<endl;
        write << password <<endl;
        write << deposit  <<endl;

        write.close();
    }else
    {
        cout<<"Wrong password!"<<endl;
        Stdnew_user();
    }  
}

void accept_req()
{
    string username , user , pass, book;
    double amount;
    ifstream validate("request_checkout.txt" , ios::in);
    if(!validate.is_open())
    {
        cerr<<"\t\t\tREQUESTCHECKOUT FILE NOT OPEN!"<<endl;
        exit(1);
    }

    string line;
    while( getline( validate , line))
    {
        cout<<"\t\t\t"<<line<<endl;
    }

    cout<<"\n\t\t\tEnter username to check if user is valid for approval: ";
    cin>>username;
    validate.close();
    cout<<"Book: ";
    cin>>book;
    
    ifstream amount_check("C:/Users/hezem/Documents/Login/Student_users/" + username +"DB.txt", ios::in);
    if(!amount_check.is_open())
    {
        cerr<<"USERFILE FILE NOT OPEN"<<endl;
        exit(1);
    }else{
    getline ( amount_check ,user );
    getline ( amount_check , pass );
    amount_check >> amount;
    if( username == user)
    {
        if(amount > 100)
        {
            ifstream sendreq("C:/Users/hezem/Documents/Login/Student_users/"+ username + "DB.txt" , ios::in);
            string l1 , l2 ,l4, *l4ptr;
            double l3 ;

            getline ( sendreq , l1);
            getline ( sendreq , l2);
            sendreq >> l3;
          
            
            cout<<"\t\t\tAPPROVED TO BORROW"<<endl;

            ofstream borrowed("C:/Users/hezem/Documents/Login/accepted/" + username + "ACC.txt" , ios::out);
            if(!borrowed.is_open())
            {
                cerr<<"USERFILE FILE NOT OPEN"<<endl;
                exit(1);
            }

            borrowed << username<<endl;
            borrowed << book<<endl;
            borrowed.close();
            amount_check.close();

            ifstream bookupdate("C:/Users/hezem/Documents/Login/books/" + book + ".txt" , ios::in);
            if(!bookupdate.is_open())
            {
                cerr<<"BOOKS FILE NOT OPEN"<<endl;
                exit(1);
            }else
            {   int line, upd_line;
                bookupdate >> line;
                upd_line = line -1;
                ofstream bookupate("C:/Users/hezem/Documents/Login/books/" + book + ".txt" , ios::out);
                bookupate << upd_line;
                bookupate.close();
                bookupdate.close();
            }
        }
    }else 
    {
        cout<<"\t\t\tINSUFFICIENT BALANCE"<<endl;
        system (" pause");
    }
    }
}

void book_return()
{
    string username , book , book1 , user;

    cout<<"User returning book: ";
    cin>>username;
    cout<<"Book: ";
    cin>>book;

    ifstream retbook("C:/Users/hezem/Documents/Login/books/" + book + ".txt" , ios::in);
    if(!retbook.is_open())
    {
        cerr<<"BOOKS FILE NOT OPEN"<<endl;
        exit(1);
    }else
    {
        int line , line2;
        retbook >> line;
        line2 = line+1;

        ofstream addbook("C:/Users/hezem/Documents/Login/books/" + book + ".txt" , ios::out);
        if(!addbook.is_open())
        {
            cerr<<"BOOKS FILE NOT OPEN"<<endl;
            exit(1);  
        }else{

            
            addbook << line2;
            retbook.close();
            addbook.close();
    }
}
}

#endif