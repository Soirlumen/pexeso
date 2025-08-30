#include "Gameboard.h"
#include <typeinfo>

int main()
{
    std::cout<< std::filesystem::current_path()<<std::endl;
    vector_of_pics_names a=read_folder("pic");
    std::cout<<"pocet souboru: "<< a.size();
}
