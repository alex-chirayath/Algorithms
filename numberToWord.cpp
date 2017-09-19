#include <iostream>
using namespace std;

// strings at index 0 is not used, it is to make array
// indexing simple
string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen "
               };

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety "
               };

// n is 1- or 2-digit number
string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n>99){
        str+= one[n/100] + "hundred";
        n=n%100;
        
    }
    
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}

// Function to print a given number in words
string convertToWords(long n)
{
    // stores word representation of given number n
    string out;

    // handles digits at ten millions and hundred
    // millions places (if any)
    out += numToWords((n / 1000000), "million ");
    n=n % 1000000;
    
    
    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) ), "thousand ");
    n=n%1000;
    
    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100)), "hundred ");
    n=n%100;

    if (n > 100 && n % 100)
        out += "and ";

    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");

    return out;
}

// Driver code
int main()
{
    // long handles upto 9 digit no
    // change to unsigned long long int to
    // handle more digit number
    long n = 754524364;

    // convert given number in words
    cout << convertToWords(n) << endl;

    return 0;
}
