#include <iostream>

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

void canAlwaysWin(int n) {
   int control = 9;
   int moves = n / control;
   int remainder = n % control;
   cout <<"Number of Moves: " << moves <<"\nRemainder: "<< remainder;
}

int main() {
   canAlwaysWin(100);
   return 0;
}