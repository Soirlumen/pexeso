#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <filesystem>
#include "Card.h"
typedef std::string Str; // konzolova verze
typedef std::vector<Str> vector_of_pics_names;
namespace fs = std::filesystem;

std::vector<Str> read_folder(const Str& fold);

class Gameboard
{
private:
    Str where_obraski;
    unsigned int number_of_pairs;
    vector_of_pics_names dEck;
    void inicialize_gameboard();

public:
    Str getWhereObraski()const;
    unsigned int getNumberOfPairs()const;
    Gameboard(Str _wo, unsigned int _nop);
    ~Gameboard();
};

#endif 