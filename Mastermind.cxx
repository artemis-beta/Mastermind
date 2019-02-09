//Include Specific Project Files
#include "Mastermind.hxx"
#include <QDebug>

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

std::vector<unsigned int> Mastermind::getPegs()
{
    unsigned int nwhite = 0, nblack = 0;
    std::map<QString, int> colour_count;
        colour_count["R"] = 0; colour_count["B"] = 0; colour_count["G"] = 0;
    colour_count["O"] = 0; colour_count["P"] = 0; colour_count["K"] = 0;
        colour_count["W"] = 0;
    for(auto j : grid)
    {
        switch(j)
        {
            case Red:
                colour_count["R"] += 1;
                break;
            case Blue:
                colour_count["B"] += 1;
                break;
            case White:
                colour_count["W"] += 1;
                break;
            case Black:
                colour_count["K"] += 1;
                break;
            case Green:
                colour_count["G"] += 1;
                break;
            case Purple:
                colour_count["P"] += 1;
                break;
            case Orange:
                colour_count["O"] += 1;
                break;
            default:
                break;
        }
    }

    std::map<QString, int> _awarded;
        _awarded["R"] = 0; _awarded["B"] = 0; _awarded["G"] = 0;
    _awarded["O"] = 0; _awarded["P"] = 0; _awarded["K"] = 0;
        _awarded["W"] = 0;

    for(int l{0}; l < player_grid.size(); ++l)
    {
        Colour m = player_grid[l];
        if(isCorrectColour(m))
        {
            if(_awarded[getStrFromColour(m)] < colour_count[getStrFromColour(m)])
            {
                _awarded[getStrFromColour(m)]++;
                if(isCorrectPosition(l,m))nblack++;
                else nwhite++;
            }
        }
    }

    return {nwhite, nblack};
}

char Mastermind::getBWCharFromPeg(pegBool peg)
{
	if(peg == black)return 'b';
	if(peg == white)return 'w';
	else{return ' ';}
}

QString Mastermind::getStrFromColour(Colour colour)
{
    if(colour ==  Blue)  return "B";
    if(colour ==  Red)   return "R";
    if(colour ==  Green) return "G";
    if(colour ==  Purple)return "P";
    if(colour ==  White) return "W";
    if(colour ==  Black) return "K";
    if(colour ==  Orange)return "O";
    if(colour == None)return "";
    else{
	throw std::invalid_argument("Invalid Colour Choice!");
    }
}
