#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <filesystem>
#include <stdexcept>
#include "Card.h"
typedef std::string Str; // konzolova verze
typedef std::vector<Str> vector_of_pics_names;
typedef std::vector<Card<Str>> vector_of_cards;
namespace fs = std::filesystem;

std::vector<Str> read_folder(const Str& fold);

class Gameboard
{
private:
    Str where_obraski;
    unsigned int number_of_pairs;
    vector_of_cards dEck;

public:
    Str getWhereObraski()const;
    unsigned int getNumberOfPairs()const;
    Gameboard(const Str &_wo, unsigned int _nop);
    ~Gameboard();
};

#endif 