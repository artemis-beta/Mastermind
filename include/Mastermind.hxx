#ifndef __MASTERMIND__
#define __MASTERMIND__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <stdexcept>
#include <random>
#include <map>

enum Colour {Blue, Green, Purple, Orange, Red, White, Black, None};
enum pegBool {black, white, blank};
class Mastermind
{
    private:
            
            Colour getRandomColour();
            void setResult(int, pegBool);
           
    public:
            void printResult();
            static const int grid_size = 4; 
            static const int game_size = 12;
            bool isCorrectPosition(int,Colour);
            bool isCorrectColour(Colour);
	    Colour grid[grid_size];
            std::vector<std::vector<Colour> > board;
            void setColours();
            Colour getColourFromString(std::string);
	    char getCharFromColour(Colour);
	    char getBWCharFromPeg(pegBool);
	    std::vector<int> getPegs(std::vector<Colour>);
            void _start();
	    std::vector<Colour> player_grid;
	    std::vector<std::vector<pegBool>> player_result;
};
Mastermind initialiseGame();
void startGame();
#endif
