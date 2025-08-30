#include "Gameboard.h"

void Gameboard::inicialize_gameboard()
{
}

Str Gameboard::getWhereObraski() const
{
    return Str();
}

unsigned int Gameboard::getNumberOfPairs() const
{
    return 0;
}

Gameboard::Gameboard(Str _wo, unsigned int _nop) : where_obraski(_wo), number_of_pairs(_nop)
{

}

Gameboard::~Gameboard()
{
}

std::vector<Str> read_folder(const Str &fold)
{
    auto actual_path = std::filesystem::current_path() / fold;
    std::vector<Str> result;
    // std::string path = "/path/to/directory";
    try
    {
        for (const auto &entry : fs::directory_iterator(actual_path))
        {
            //std::cout << entry.path() << std::endl;
            result.push_back(entry.path().string());
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Chyba: " << e.what() << "\n";
    }

    return result;
}
