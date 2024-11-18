#include <iostream>

#include <iomanip>
#include <vector>

using namespace std;

void DisplayEmployeeTable(double employees[], int ARRAY_SIZE);
double* GetEmployeeInfo();
int GetID();
void ComputePay(double info[], int size);
double GetGrossPay();
double const STATE_TAX = .04;
double const FED_TAX = .05;
double const FICA = .05;
int const ARRAY_SIZE = 7;
string const empInfoType[7] = { "", "ID","Gross Pay","State Tax","Federal Tax","FICA","Net Pay" };
void SetFormat(int precision, int width);

void PopulateEmployeeTable(double employees[], double empInfo[], int  ARRAY_SIZE);

int main()

{
    vector <double*> Employees;
    double empInfo[7];
    double* ptr;

    ptr = GetEmployeeInfo();
    while (ptr[1] != 0)
    {
        Employees.push_back(ptr); //Brion You are pushing back a pointer to the same value each time, when you change the array in GetEmployeeInfo, the pointers in Employees all point to the same thing.
        DisplayEmployeeTable(ptr, 7);
        ptr = GetEmployeeInfo();  // Brion There is also an issue where the sentinel writes to the array and then it is copied across the whole Employees vector of pointers.
        // Brion essentially this is adding a new row of the same thing to Employees.  I believe the program either has to be rewritten to increment one 2d array or execute the pushback within the GetEmployeeInfo function.
    }

    // for (double* Employee : Employees)
   //  {
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << endl;
            cout << empInfoType[j] << "\t" << Employees[i][j];
        }
    }
    //  }

}
void DisplayEmployeeTable(double employees[], int ARRAY_SIZE) {

    double  empInfo = employees[0];
    cout << left << empInfoType[1] << ": " << employees[1] << endl;
    SetFormat(2, 15);
    double grossPay = employees[1];
    for (int i = 2; i < 7; i++)
    {
        cout << empInfoType[i] << ":\t$" << right << employees[i] << "\n";
    }

}

void SetFormat(int precision, int width) {
    cout.precision(precision);
    cout << setw(width);
    cout << fixed;
}

// To do: allow for multiple employees.

//         save in file and read in file

double* GetEmployeeInfo() { //return type shouldn't be a pointer, we are returning the array by address

    static double EmployeeInfo[6];
    EmployeeInfo[1] = GetID();
    if (EmployeeInfo[1] != 0) {
        EmployeeInfo[2] = GetGrossPay();
        EmployeeInfo[3] = STATE_TAX;
        EmployeeInfo[3] = FED_TAX;
        EmployeeInfo[5] = FICA;
        // ComputePay(EmployeeInfo, 6);
         //double* ptr2 = EmployeeInfo;

    }
    return EmployeeInfo;
}



int GetID() {
    int id;
    cout << "Please Enter the Employee ID:";
    cin >> id;
    return id;
}



void ComputePay(double info[], int size)

{
    double grossPay = info[1];
    double netPay = grossPay;
    for (int i = 2; i < size; i++)
    {
        info[i] = info[i] * grossPay;
        netPay = netPay - info[i];
    }
    info[size - 1] = netPay;
}

double GetGrossPay() {
    double gp;
    cout << "Please Enter the Employee's Gross Pay:";
    cin >> gp;
    return gp;
}



void PopulateEmployeeTable(double employees[], double empInfo[], int  ARRAY_SIZE) {
    static int EmployeeCount = 0;
    employees[EmployeeCount] = *empInfo;
    EmployeeCount += 1;
}



/*double GetStateTax() {

    double st;

    cout << "Please Enter the State tax percentage:";

    cin >> st;

    return st;



}

double GetFedTax() {

    double ft;

    cout << "Please Enter the Federal tax percentage:";

    cin >> ft;

    return ft;



}





double GetFICA() {

    double FICA;

    cout << "Please Enter the Employee's FICA withholding:";

    cin >> FICA;

    return FICA;



}

*/