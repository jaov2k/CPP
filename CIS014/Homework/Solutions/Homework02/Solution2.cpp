#include <iostream>
#include <climits>

using namespace std;

/*
 * FUNCTION NAME: canAlwaysWin
 * PURPOSE: To analyze whether out of a certain number of moves
 *          there will be a 100% certainty that you will win,
 *          returning 1 (true) for victory or 0 (false) if you lose.
 * PARAMETER:
 *     int n
 * RETURN VALUE:
 *     bool: result either TRUE (1) or FALSE (0)
 * FUNCTION SINGATURE:
 *     bool canAlwaysWin(int n)
 */ 

bool canAlwaysWin(int n) 
{
   if (0 < n  && n < INT_MAX)
      return n % 9 ? 1 : 0;
}

int main() 
{
   cout << canAlwaysWin(23034);
   return 0;
}