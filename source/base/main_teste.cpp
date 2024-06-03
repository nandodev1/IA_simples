#include<iostream>
#include <cstdlib>

using namespace std;

int main( int argc, char * argv [])
{

string Text = "456";//string containing the number
int Result;//number which will contain the result

stringstream ss(); // stringstream used for the conversion initialized with the contents of Text



if ( !(ss >> Result) )//give the value to Result using the characters in the string
    Result = 0;//if that fails set Result to 0
//Result now equal to 456 
}
