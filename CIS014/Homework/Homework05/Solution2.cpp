/*
Jose Ortiz
3/23/2021
CIS014 - Spring 2021
Homework Assignment 5: Problem 2 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * PURPOSE: Helper function to compareVersions to concatenate
 *          a leading zero should it be missing from a string,
 *          facilitating sizing and parsing.
 * PARAMETERS: string
 * RETURN VALUES: string
 * FUNCTION SINGATURE: string leadingZero(string str)
 */
string leadingZero(string str){
   if (str[0] == '.')
      str = '0' + str;
   return str;
}

/**
 * PURPOSE: Helper function to compareVersions() to balance
 *          the number of catagories by appending zero revision.
 *          This avoids possible out of bound issues.
 * PARAMETERS: string, int
 * RETURN VALUES: string
 * FUNCTION SINGATURE: string trailingZero(string str, int n)
 */
string trailingZero(string str, int n){
   for (int i = 0; i <= ((n-str.size())/2); i++)
      str = str + '.' + '0';   
   return str;
}

/**
 * PURPOSE: Helper function to compareVersions to total
 *          the number of catagories (major, minor, etc.) in the version.
 *          This then determines the size of the vector for comparisons.
 * PARAMETERS: string
 * RETURN VALUES: int
 * FUNCTION SINGATURE: int countCatagories(string str)
 */
int countCatagories(string str){
   int counter = 0;
   for (char a : str)
      if (a == '.')
         counter++;
   return (counter + 1);
}

/**
 * PURPOSE: Compares the two version strings, ver1 and ver2, of a software product 
 *          to determine which product version is the latest
 * PARAMETERS: string, string
 * RETURN VALUES: int
 * FUNCTION SINGATURE: int compareVersions(string ver1, string ver2)
 */
int compareVersions(string ver1, string ver2){

   ver1 = leadingZero(ver1);
   ver2 = leadingZero(ver2);

   if (ver1.size() < ver2.size())
      ver1 = trailingZero(ver1, ver2.size());
   else if (ver1.size() > ver2.size())
      ver2 = trailingZero(ver2, ver1.size());

   int catagoryQty = countCatagories(ver1);

   //First index to hold the catagories of ver1, and second index for ver2.
   vector< vector<int> > verArr (catagoryQty,vector<int>(2));

   for (int i = 0; i < catagoryQty; i++){
      //Extract first catagory values
      verArr[i][0] = stoi(ver1.substr(0,ver1.find('.')));
      verArr[i][1] = stoi(ver2.substr(0,ver2.find('.')));
      
      //Compare the catagories
      if (verArr[i][0] > verArr[i][1])       //If ver1 > ver2: return -1
         return -1;
      else if (verArr[i][0] < verArr[i][1])  //If ver1 < ver2: return 1
         return 1;
      
      //If the catagory is equal then truncate the strings to check the next catagory
      ver1 = ver1.substr(ver1.find('.') + 1,ver1.size());
      ver2 = ver2.substr(ver2.find('.') + 1,ver2.size());
   }
   //Otherwise the versions are equal.
   return 0;
}

int main() {
   // your target function will be tested as such, with 
   // random input. To streamline your testing, you may
   // also test your own code this way:   
   cout << compareVersions("0.1.2.3", "0.1.2.3") << endl;                  // 0
   cout << compareVersions("1.0", "1.1") << endl;                          // 1
   cout << compareVersions("2.2.2.2.2.2.2", "2.2.2.2.2.2.1") << endl;      // -1
   cout << compareVersions(".1", ".1.2") << endl;                          // 1
   cout << compareVersions("1.1.0", ".1.9") << endl;                       // -1   
   cout << compareVersions("2.2.0", "2.2.0.1") << endl;                    // 1
   cout << compareVersions("1.23.1235.897.15.0.1", ".12.345.67") << endl;  // -1
   return 0;
}