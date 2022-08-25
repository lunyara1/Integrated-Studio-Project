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
