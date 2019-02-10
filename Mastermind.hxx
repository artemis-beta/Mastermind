#ifndef __MASTERMIND__HXX__
#define __MASTERMIND_HXX__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <stdexcept>
#include <random>
#include <map>
#include <QString>

enum Colour {Blue, Green, Purple, Orange, Red, White, Black, None};
enum pegBool {black, white, blank};
class Mastermind
{
    private:
            
            Colour getRandomColour();
            void setResult(int, pegBool);
            QString _version_string = "v0.2.0";
           
    public:
            std::vector<Colour> player_grid = {None, None, None, None};
            void printResult();
            static const int grid_size = 4; 
            static const int game_size = 12;
            bool isCorrectPosition(int,Colour);
            bool isCorrectColour(Colour);
            Colour grid[grid_size];
            std::vector<std::vector<Colour> > board;
            void setColours();
            Colour getColourFromString(std::string);
            QString getStrFromColour(Colour);
            QString getVersion(){return _version_string;}
            std::vector<unsigned int> getPegs();
            char getBWCharFromPeg(pegBool);
            void _start();
            std::vector<std::vector<pegBool>> player_result;
};
#endif
