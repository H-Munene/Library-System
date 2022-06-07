#ifndef student_h
#define student_h
 
#include <iostream>
#include <fstream>
#include <string>
#include "librarian.h"
using namespace std;

string filepath = "C:/Users/hezem/Documents/Login/Student_users/";
void Already_Registered()
{
    string username , password , usern , passw;
    cout<<"\t\t\tEnter your username: ";
    cin>>username;

    cout<<"\t\t\tEnter your password: ";
    cin>>password;

    ifstream read( filepath + username + "DB.txt" , ios::in);
    getline( read , usern);
    getline( read , passw);
    read.close();

    if( username == usern && passw == password)
    {
           cout<< "Welcome"<<endl;
    }else 
    {
        Already_Registered();
    }
}

void passwordstd_reset()
{
    string username , password , password2 , user , pass;
    double amount , *amountptr;

    cout<<"\t\t\tEnter your username: ";
    cin>>username;
    cout<<"\t\t\tEnter new password: ";
    cin>>password;
    cout<<"\t\t\tConfirm new passowrd:";
    cin>>password2;

    if ( password2 == password)
    {
        cout<<"\t\t\tPassword reset Successfull"<<endl;
        ifstream check(filepath + username + "DB.txt" , ios::out);
        if(!check.is_open())
        {
            cerr<<"USERFILE NOT OPEN"<<endl;
            exit(1);
        }
        getline (check, user);
        getline (check ,pass);
        check >> amount;
        amountptr = &amount;

        ofstream password_reset(filepath + username+"DB.txt" , ios::out);
        password_reset << username <<endl;
        password_reset << password <<endl;
        password_reset << *amountptr << endl;
        

        password_reset.close();
    }else
    {
        cout<<"\t\t\tPasswords don't match! Retry"<<endl;
        passwordstd_reset();
    }
}

void ask_forgotpass()
{   
    string yes_no;
    cout<<"\t\t\tHave you fogotten your password: ";
    cin>>yes_no;

    if ( yes_no == "yes")
    {
        passwordstd_reset();
    }else
    {
        Already_Registered();
        if (true)
        {
            cout<<"\t\t\tLogin Success"<<endl;
        }else
        {
            passwordstd_reset();
        }
    }
}
//student details
//update to show if user has books borrowed
void std_details()
{   
    string username , password , usern , passw, status ,*statusptr;
    double deposit , *depositptr;
    cout<<"\t\t\tEnter your username: ";
    cin>>username;

    cout<<"\t\t\tEnter your password: ";
    cin>>password;

    ifstream read( filepath + username + "DB.txt" , ios::in);
    getline( read , usern);
    getline( read , passw);
    read >> deposit;
    depositptr = &deposit;

    if( username == usern && passw == password)
    { //include books borrowed 
        ifstream review ("C:/Users/hezem/Documents/Login/accepted/" + username + "ACC.txt" , ios::out);
        if(!review.is_open())
        {
            cout <<"\n\t\t\tName: "<<username<<endl;
            cout << "\t\t\tPassword is: "<<password<<endl;
            cout <<"\t\t\tYour current deposit is: "<<*depositptr<<endl;
            cout <<"\t\t\tNo book borrowed"<<endl;
        }else{
        string l1 , l2 , *l2ptr;
        getline( review , l1);
        getline (review , l2);
        l2ptr = &l2;

        cout<<"\t\t\tName: "<<username <<endl;
        cout<<"\t\t\tPassword is: "<<password<<endl;
        cout<<"\t\t\tYour current deposit is: "<<*depositptr <<endl;
        cout<<"\t\t\t"<<*l2ptr <<" is borrowed"<<endl;
        }
       //output
        read.close();
        review.close();
    }else 
    {
        cout<<"INVALID DETAILS!! TRY AGAIN."<<endl;
        std_details();
    }

}

string Bfilepath = "C:/Users/hezem/Documents/Login/books/";
string Reqfilepath = "C:/Users/hezem/Documents/Login/checkoutreq/";

// sends request to borrow book
void borrow_book()
{
    string book , username , password , user , pass;
    double amount , *amountptr;
    cout<<"\t\t\tWhat book would you like to borrow?\n";
    cout<<"\t\t\t1) English"<<endl;
    cout<<"\t\t\t2) Biology"<<endl;
    cout<<"\t\t\t3) Mathematics"<<endl;

    cout<<"\n\t\t\tBook: ";
    cin>>book;
    cout<<"\n\t\t\tYourname: ";
    cin>>username;
    cout<<"\t\t\tEnter password: ";
    cin >>password;

    ifstream fetch( filepath + username + "DB.txt" , ios::in);
    getline( fetch , user);
    getline( fetch , pass);
    fetch >> amount;
    amountptr  = &amount;

    if( username == user && pass == password)
    { //include books borrowed 
        ifstream bookread (Bfilepath + book +".txt", ios::in);
        if(!bookread.is_open())
        {
            cerr<< "\t\t\tERROR OPENING BOOK FILE"<<endl;
        }
        int line;
        bookread >> line;
        if ( line > 0)
        {
            cout << "\t\t\tREQUEST SENT AWAITING APPROVAL"<<endl;
            ofstream sendreq("request_checkout.txt" , ios::out);
            if(!sendreq.is_open())
            {
                cout<<"ACCEPTED NOT OPENED";
                exit(1);
            }else{
            sendreq << username <<" "<< book <<endl;
            }

            ofstream update( filepath + username + "DB.txt" , ios::out);
            if(!update.is_open())
            {
                cerr<< "\t\t\tERROR OPENING BOOK FILE"<<endl;
            }
            else{
            update << username <<endl;
            update << password <<endl;
            update << *amountptr << endl;
            update << book <<" is borrowed!"<<endl;
            }
            update.close();
            sendreq.close();
            fetch.close();
        }else
        {
            cout<<"\t\t\tNO "<<book<<" book available"<<endl;
            system("pause");
            //make return to main
        }
    }else 
    {
        cout<<"INVALID DETAILS!! TRY AGAIN."<<endl;
        borrow_book();
    }  
   
}

//HEEEERREEEEEEEEE


#endif