 /*      The game of NIM         */
#include<iostream>      // include two libraries
#include<cstdlib>
#include<ctime>
using namespace std;
int main()              // main starts the actual program
{
        //--------------------variable declarations-------------------------
        int num_objects = 23;
        int current_player = 1;
        int move;
        srand(time(NULL));
        char c;
        int Player1_score = 0;
        int Computer_score = 0;
        int minimum_move = 1;
        int maximum_move = 4;
        //-------------------- Beginning of the game loop -------------------
        cout << "How to play NIM: " << endl;
        cout << "The traditional game of Nim is played with a number of coins arranged in heaps: the number of coins and heaps is up to you. " << endl;
        cout << "There are two players. When it's a player's move he or she can take any number of coins from a single heap. They have to take at least" << endl;
        cout << "one coin, though, and they can't take coins from more than one heap. The winner is the player who makes the last move, so there are no" << endl;
        cout << "coins left after that move. (Some people play the game the other way around, with the last person to make a move losing the game, but we'll" << endl;
        cout << "ignore that version for the moment." << endl;
        cout << "It's clear that there is no luck involved here. You can work out the best move to make by cleverly predicting the sequence of moves that would follow it." << endl;

    do{
        cout << "Enter the number of objects you would like to begin with: ";
        cin >> num_objects;
        while(num_objects <= 0)
            {
            cout << "Invalid input, you cannot start with zero or negative objects. Enter another number: ";
            cin >> num_objects;
            }

        do {
           if (current_player == 1) {                                           // conditional: if
                cout << "Player 1, enter your move (1-3): ";            // output
                cin >> move;
                if(move >= minimum_move || move <= maximum_move || move <= num_objects)
                {
                    cout << "Player 1 removed " << move << endl;
                }                                                    // input
                while (move < minimum_move || move > maximum_move || move > num_objects) {
                cout << "Illegal move. \nEnter a new move: ";
                cin >> move;
                if(move >= minimum_move || move <= maximum_move || move <= num_objects)
                {
                    cout << "Player 1 removed " << move << endl;
                }
              }
           } else {                                                     // else part of conditional
                do {                                                    // make sure move is legal
                        move = 1 + rand() % 3;                          // random computer move
                        if(num_objects == 8 || num_objects == 7 || num_objects ==6)
                        {
                            move = num_objects % 5;
                        }
                            if(num_objects == 4)
                            {
                                move = 3;
                            }
                            if(num_objects == 3)
                            {
                                move = 2;
                            }
                            if(num_objects == 2)
                            {
                                move = 1;
                            }
                } while (move < minimum_move || move > maximum_move || move > num_objects);
                cout << "Computer removed " << move << endl;
           }

           num_objects = num_objects - move;                                    // implement the move
           cout << num_objects << " objects remaining. \n";
           current_player = (current_player + 1) % 2;                           // switch player
        } while (num_objects > 0);
        //--------------end of the game loop-----------------
        if(current_player == 0)
        {
            Player1_score = Player1_score + 1;
            cout << "Player 1 wins!" << endl;
        }
        if(current_player == 1)
        {
            Computer_score = Computer_score + 1;
            cout << "Computer wins!" << endl;
        }

        cout << "Score:" << endl;
        cout << "Computer: " << Computer_score << endl;
        cout << "Player 1: " << Player1_score << endl;

     // cout << "Nice going player " << current_player << ", you win!\n";
        cout << "Would you like to play again? [Y/N]: ";
        cin >> c;
    }
        while(c == 'Y' || c == 'y');

        if(c == 'N' || c == 'n')
        {
            return 0;
        }
}