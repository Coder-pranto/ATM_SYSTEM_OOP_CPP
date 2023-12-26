#include <conio.h>
#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

/* Mini Project - ATM_SYSTEM
FEATURES:
   -> Check Balance
   -> Cash withdraw
   -> User Details
   -> Update Mobile No.
*/

class ATM
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setData(long int account_no_x, string name_x, int PIN_x, double balance_x, string mobile_no_x)
    {
        account_no = account_no_x;
        PIN = PIN_x;
        balance = balance_x;
        name = name_x;
        mobile_no = mobile_no_x;
    }

    long int getAccountNo()
    {
        return account_no;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

    void setMobile(string mobile_prev, string mobile_new){
        if(mobile_prev == mobile_no){
            mobile_no = mobile_new;
            cout << endl << "Sucessfully Updated Mobile no.";
            getch();
        }else{
            cout << endl << "Incorrect !!! Old Mobile no";
            getch();
        }
    }

    void cashWithDraw(int amount_x){
        if(amount_x >0 and amount_x<=balance-100){
            balance-= amount_x;
            cout << endl << "Please Collect Your Cash";
            cout << endl<< "Available Balance :" << balance;
            getch();
        }
    }

};


/////////////////////////////////////////////////////////////////////////////////////////////*

int main(){
    int enterPIN;
    long int enterAccountNo;

    system("cls");

    ATM user1;
    user1.setData(1234567, "Pranto", 1234, 45000.90, "01727889688");

    do
    {
        system("cls");
        cout << endl<< "****Welcome to XYZ Bank ATM*****" << endl;
        cout << endl<< "Enter Your Account No ";
        cin >> enterAccountNo;

        cout << endl<< "Enter PIN ";
        cin >> enterPIN;

        if((user1.getAccountNo() == enterAccountNo) and (user1.getPIN() == enterPIN)){
            do
            {
                int amount =0;
                int choice =0;
                string oldMobileNo, newMobileNo;
                system("cls");
                // USER INTERFACE
                cout << endl<< "**** Welcome to ATM *****" << endl;
                cout << endl<< "Select Options ";
                cout << endl<< "1. Check Balance";
                cout << endl<< "2. Cash withdraw";
                cout << endl<< "3. Show User Details";
                cout << endl<< "4. Update Mobile no.";
                cout << endl<< "5. Exit" << endl;

                cin>>choice;

                switch (choice)
                {
                case 1: // if user presses 1
                    cout<<endl<<"Your account balance is :"<<user1.getBalance();
                    getch();
                    break;

                case 2:
                    cout << endl<< "Enter the amount :";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout << endl<< "*** User Details are :- ";
                    cout << endl << "-> Account no : " << user1.getAccountNo();
                    cout << endl<< "-> Name      : " << user1.getName();
                    cout << endl<< "-> Balance   : " << user1.getBalance();
                    cout << endl<< "-> Mobile No. : " << user1.getMobileNo();
                    getch();
                    break;

                case 4:
                    cout << endl<< "Enter Old Mobile No. ";
                    cin >> oldMobileNo; // take old mobile no
                    cout << endl<< "Enter New Mobile No. ";
                    cin >> newMobileNo; // take new mobile no
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0); // exit application
                }
            } while (1);
        }

    } while (1);

}
