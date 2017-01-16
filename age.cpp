//we will be checking the variables at breakpoint by printing its value at checkpoint


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int DAYS_PER_YEAR = 365;
int GetAge(int &a);
int CalcDays( int age );
void PrintResults( int age, int days );
int main()
{
    int age = 0;
    int days = 0;
    // Breakpoint 1
    // Put breakpoint on the following line
    cout<<"Breakpoint1 age = "<<age<<" days = "<<days<<" address of age "<<&age<<endl;
    GetAge(age);
    days = CalcDays( age );
    // Breakpoint 2
    cout<<"Breakpoint2 age = "<<age<<" days = "<<days<<" address of age "<<&age<<endl;
    // Put breakpoint on the following line
    PrintResults( age, days );
    return 0;
}
/**
*    @brief Gets the age of the user.
*    Gets the age of the user.
*    @return non-0 on an error, 0 otherwise.
*/
int GetAge(int &age)
{
    cout<<" Breakpoint age = "<<age<<" At Address: "<<&age<<endl;
    cout << "Please enter your age: ";
    cin >> age;
    
    cout<<" Breakpoint age = "<<age<<" At Address: "<<&age<<endl;
    return age;
}
/**
*    @brief Calculates the number of days in years number of years.
*   Calculates the number of days in years number of years.
*   @param years Number of years
*    @return The number of days in years years
*/
int CalcDays( int years )
{
    int days;
    days = years * DAYS_PER_YEAR;
    
    return days;
}
/**
*    @brief Prints the number of years and number of days to the screen with
*    a message.
*      Prints the number of years and number of days to the screen with
*    a message.
*   
*   @param days Number of days in age years
*    @param age Age in years
*/
void PrintResults( int days, int age )
{
    cout << age << "! Boy are you old!\n";
    cout << "Did you know that you are at least "
         << days << " days old?\n\n";
}
