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

