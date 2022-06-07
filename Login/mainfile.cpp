#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "librarian.h"
#include <cstdio>
using namespace std;

void start_menu()
{
    cout<<"\t\t*******Bienvenue a la bibliotheque*****\n"<<endl;    
    cout<<"\t\t*******Welcome to the library***********\n"<<endl;
    cout<<"\t\t__________________________________________"<<endl;
    cout<<"\t\t\tSelect your role: "<<endl;
    cout<<"\t\t\t1) Normal student Login"<<endl;
    cout<<"\t\t\t2) Librarian Login"<<endl;
}

int main()
{
    bool status;
    start_menu();
    int choice;
    cout<<"\n\t\t\tEnter role to proceed: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            // STUDENT PAGE
            cout<<"\t\t\t1) View profile details"<<endl;
            cout<<"\t\t\t2) Request to checkout book"<<endl;
            cout<<"\t\t\t3) Return book"<<endl;
            cout<<"\t\t\t2) Change / Forgotten Password"<<endl;
            int selection;
            cout<<"\n\t\t\tMake a selection: ";
            cin>> selection;

                switch (selection)
                {
                case 1:   // view profile
                    std_details();
                    break;
                case 2 : //request checkout
                    borrow_book();
                    break;
                case 3: //return book
                    break;
                case 4: // password change
                    passwordstd_reset();
                    break;
                default :
                    cerr<<"ERROR!";
                    main();
                    break;
                }
            break;
                
        case 2:
        //LIBRARIAN PAGE
            cout<<"\n\t\t\t1) Register new student"<<endl;
            cout<<"\t\t\t2) Accept borrow request"<<endl;
            cout<<"\t\t\t3) Return book"<<endl;
            cout<<"\t\t\t4) Change password"<<endl;
                    
            int choice;
            cout<<"\t\t\tSelect a choice: ";
            cin>>choice;
            switch (choice)
                {
                    case 1:
                        Stdnew_user();
                        break;
                    case 2:
                        accept_req();
                        break;
                    case 3:
                        book_return();
                        break;
                    case 4:
                    //test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1111
                        passwordlibr_reset();
                        break;
                }
            break;

    }
    string answer;
    cout<<"\n\t\t\tDo you want to return to main page? ";
    cin>>answer;
    if(answer == "yes")
    {   system("cls");
        main();
    }else
    {
        system ("pause");
        system ("cls");
    }
    return 0;
}