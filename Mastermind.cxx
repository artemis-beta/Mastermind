//Include Specific Project Files
#include "Mastermind.hxx"

Colour Mastermind::getRandomColour()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> seeder(0,7);
    Colour randomColour = Colour(seeder(rng));
    return randomColour;
}

void Mastermind::setColours()
{
    for(unsigned int i{0};i<grid_size;++i)
    {
        grid[i] = getRandomColour();
    }
}

bool Mastermind::isCorrectPosition(int position, Colour colour)
{
    if(grid[position] == colour){return true;}
    return false;
} 

bool Mastermind::isCorrectColour(Colour colour)
{
    for(unsigned int j = 0; j<grid_size;++j)
    {
        if(grid[j] == colour){return true;}
    }
    return false;
}

void Mastermind::printResult()
{
    board[board.size()-1] = player_grid;
    for(unsigned int m{0}; m<board.size(); ++m)
    {
	for(auto t : board[m])
        {
	    char colour_char = getCharFromColour(t);
            std::cout << colour_char << "\t";
        }
        std::cout << "\t|\t";
	for(auto i : player_result[m])
	{
		std::cout << getBWCharFromPeg(i) << " ";
	}
	std::cout << std::endl;
        std::cout << std::string(30,'_') << std::endl;
    }
}

Mastermind initialiseGame()
{
    Mastermind game;
    game.setColours();
    return game;
}

Colour Mastermind::getColourFromString(std::string colour)
{
    std::transform(colour.begin(), colour.end(),colour.begin(), ::toupper);
  
    if(colour ==  "BLUE")  return Blue;
    if(colour ==  "RED")   return Red;
    if(colour ==  "GREEN") return Green;
    if(colour ==  "PURPLE")return Purple;
    if(colour ==  "WHITE") return White;
    if(colour ==  "BLACK") return Black;
    if(colour ==  "ORANGE")return Orange;
    else{
	throw std::invalid_argument("Invalid Colour Choice!");
    }
}

char Mastermind::getBWCharFromPeg(pegBool peg)
{
	if(peg == black)return 'b';
	if(peg == white)return 'w';
	else{return ' ';}
}

char Mastermind::getCharFromColour(Colour colour)
{
    if(colour ==  Blue)  return 'B';
    if(colour ==  Red)   return 'R';
    if(colour ==  Green) return 'G';
    if(colour ==  Purple)return 'P';
    if(colour ==  White) return 'W';
    if(colour ==  Black) return 'K';
    if(colour ==  Orange)return 'O';
    if(colour == None)return ' ';
    else{
	throw std::invalid_argument("Invalid Colour Choice!");
    }
}

void Mastermind::_start()
{
    std::cout << "-------------WELCOME TO MASTERMIND v0.1.0---------------\n";
    std::cout << "                by Kristian Zarebski                    \n";
    std::cout << "--------------------------------------------------------\n";
    for(unsigned int l{0}; l<game_size; ++l)
    {
        std::cout << "State your colour choice, enter each colour followed by enter:" << std::endl;
	player_grid = {};
        for(unsigned int p{0}; p<grid_size; ++p){
            std::string colour = "";
            while(true)
            {
                try
                {
                    std::cin >> colour;
                    player_grid.push_back(getColourFromString(colour)); 
                    break;
                }
                catch(std::invalid_argument)
                {
                    std::cout << "Invalid Colour!\n";
                    continue;
                }
            }
        }

        board.push_back(player_grid);

	std::vector<pegBool> _result;

        for(unsigned int i{0}; i<grid_size; ++i)
        {
            Colour temp = player_grid[i];
	    pegBool peg;
            if(isCorrectPosition(i,temp) && isCorrectColour(temp))
            {
                peg = black;
            }
            else if(isCorrectColour(temp))
            {
		    peg = white;
            }
            else{
                    peg = blank;
            }

	    _result.push_back(peg);
        }

	player_result.push_back(_result);

        printResult();

	int blackPegs = 0;

        for(unsigned int x{0}; x<grid_size; ++x)
        {
            if(player_result[player_result.size()-1][x] == black) blackPegs++;
        }

	if(blackPegs == 4) return;
    }
}

void startGame(){initialiseGame()._start();}
