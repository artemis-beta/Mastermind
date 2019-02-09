//Include Specific Project Files
#include "Mastermind.hxx"

Colour Mastermind::getRandomColour()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> seeder(0,6);
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

std::vector<int> Mastermind::getPegs(std::vector<Colour> _player_choice)
{
	int nwhite = 0, nblack = 0;
	std::map<char, int> colour_count;
        colour_count['R'] = 0; colour_count['B'] = 0; colour_count['G'] = 0;
	colour_count['O'] = 0; colour_count['P'] = 0; colour_count['K'] = 0;
        colour_count['W'] = 0;
	for(auto j : grid)
	{
		switch(j)
		{
			case Red:
				colour_count['R'] += 1;
				break;
			case Blue:
				colour_count['B'] += 1;
				break;
			case White:
				colour_count['W'] += 1;
				break;
			case Black:
				colour_count['K'] += 1;
				break;
			case Green:
				colour_count['G'] += 1;
				break;
			case Purple:
				colour_count['P'] += 1;
				break;
			case Orange:
				colour_count['O'] += 1;
				break;
			default:
				break;
		}
	}

	std::map<char, int> _awarded;
        _awarded['R'] = 0; _awarded['B'] = 0; _awarded['G'] = 0;
	_awarded['O'] = 0; _awarded['P'] = 0; _awarded['K'] = 0;
        _awarded['W'] = 0;

	for(int l{0}; l < _player_choice.size(); ++l)
	{
		Colour m = _player_choice[l];
		if(isCorrectColour(m))
		{
			if(_awarded[getCharFromColour(m)] < colour_count[getCharFromColour(m)])
			{
				_awarded[getCharFromColour(m)]++;
				if(isCorrectPosition(l,m))nblack++;
				else nwhite++;
			}
		}
	}

	return {nwhite, nblack};
}



void Mastermind::printResult()
{
    board[board.size()-1] = player_grid;
    for(unsigned int m{0}; m<board.size(); ++m)
    {
	for(auto t : board[m])
        {
	    char colour_char = getCharFromColour(t);
            std::cout << "   " << colour_char << "\t";
        }
        std::cout << "|\t";
	for(auto i : player_result[m])
	{
		std::cout << getBWCharFromPeg(i) << " ";
	}
	std::cout << std::endl;
        std::cout << std::string(32,'_') << std::endl;
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
    std::cout << "-------------WELCOME TO MASTERMIND v0.1.3---------------\n";
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

	std::vector<pegBool> _result = {};

	std::vector<int> _pegs = getPegs(player_grid);

	for(unsigned int j{0}; j<_pegs[0]; ++j)_result.push_back(white);
	for(unsigned int k{0}; k<_pegs[1]; ++k)_result.push_back(black);

	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(_result), std::end(_result), rng);

	player_result.push_back(_result);

        printResult();

	if(_pegs[1] == 4) return;
    }
}

void startGame(){initialiseGame()._start();}
