#include <iostream>
#include <vector>

using namespace std;

class Insurance
{
private:
string custName;
int policyNumber;
double premium;

public:
Insurance()
{
custName="";
policyNumber=0;
premium=0.0;
}
Insurance(string cn,int pn,double prem)
{
custName = cn;
policyNumber=pn;
premium=prem;
}
string getCustomerName()
{
return custName;
}
void setCustomerName(string name)
{
custName = name;
}
int getPolicyNumber()
{
return policyNumber;
}
void setPolicyNumber(int pn)
{
policyNumber = pn;
}
double getPremiumValue()
{
return premium;
}
void setPremium(double prem)
{
premium = prem;
}  
virtual double getPremium()=0;
virtual void print()=0;
template<typename T>
bool isA()
{
return (dynamic_cast<T*>(this) != NULL);
}
};

class AutoPolicy:public Insurance
{
private:
int noOfTickets;

public:

AutoPolicy(string cn,int pn,double prem,int tick):Insurance(cn,pn,prem)
{
noOfTickets = tick;
}
//The cost of insurance depends on the number of tickets
double getPremium()
{
double ret;
if(noOfTickets>=3)
ret=175;
else if(noOfTickets>=1 && noOfTickets<=2)
ret=140;
else
ret=95;
return ret;
}
int getNoOfTickets()
{
return noOfTickets;
}
void print()
{
cout << "Auto Insurance premium is: $" << getPremium() << endl;
cout << endl;
}
};
//Main function
int main() {

//Registeration block
  string login;
  string user;
  int login_times;
  string password_login;
  string password;
  
  string command;

      cout << "Welcome to Vehicle Insurance System" << endl<<"-----------------------------------"<<endl;
      cout << "Registeration new Admin"<<endl<<"-----------------------"<<endl;
      cout <<"New Username: ";
      cin >> user;
      cout <<"New Password: ";
      cin >> password;

      cout << "\n";
      cout << "Registered Successfully!"<<endl;
     
      login_times = 3;
      while(login_times > 0){
        
        cout << "\n";
        cout << "Login"<<endl<<"_____"<<endl;

        cout << "Username: ";
        cin >> login;
        cout << "Password: ";
        cin >> password_login;

        if(login == user && password_login == password){
          cout << "Loged in Successfully!"<<endl;
          cout << "Welcome "<< user<<"!\n"<<endl;

//Vehicle Insurance System menu block
vector<Insurance*> insurances;
bool cont = true;
while(cont)
{
int choice;
cout << "Vehicle Insurance System" << endl;
cout << "1-New Customer" << endl;
cout << "2-Print Customer" << endl;
cout << "3-Find Customer" << endl;
cout << "4-Exit" << endl;

cout << "Enter your choice: ";
cin >> choice;

switch(choice)
{
//=============== case 1 ========================
case 1:
{
string name;
int policynum;
int nooftick;
double prem = 0.0;
cout << "Enter customer name: ";
cin.ignore();
getline(cin, name);
cout << "Enter policy number: ";
cin >> policynum;
cout << "Enter number of tickets: ";
cin >> nooftick;
cout << endl;
AutoPolicy * abc = new AutoPolicy(name,policynum,prem,nooftick);
abc->print();
insurances.push_back(abc);
}
break;
