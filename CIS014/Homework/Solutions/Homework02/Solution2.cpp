#include <iostream>
#include <climits>

using namespace std;

/*
 * FUNCTION NAME: canAlwaysWin
 * PURPOSE: To analyze whether out of a certain number of moves
 *          there will be a 100% certainty that you will win,
 *          returning 1 (true) for victory or 0 (false).
 * PARAMETER:
 *     int n
 * RETURN VALUE:
 *     bool: result either TRUE or FALSE
 * FUNCTION SINGATURE:
 *     bool canAlwaysWin(int n)
 */ 

void canAlwaysWin(int n) 
{
   if (0 < n  && n < INT_MAX)
   {
      int control = 4;
      int moves = n / control;
      int remainder = n % control;
      cout << "Total pebbles: " << n 
           << "\nNumber of Moves: " << moves 
           << "\nRemainder: "<< remainder;
   }
   else
   {
      cout << "Number is out of range. End Program.";
   } 
}

int main() 
{
   canAlwaysWin(21);
   return 0;
}