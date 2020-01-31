#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>

#ifndef COUT_STUFF
#define COUT_STUFF


class Cout_stuff
{
    private:
        int p_num_of_tries;
        std::vector<char> p_wordbank;
        std::string p_word;
        char p_letter;

    public:
        int setNum_of_tries();

        void setWordbank();

        std::string setWord(std::string word);

        char getLetter();

        void display_intro();

        void display_rules();

        void check_and_display();    

        void no_more_attempts(); 

        void no_more_attempts2();   

        void You_win();

};

class Easy_or_hard 
{
    private:
    std::vector<std::string> p_comp_pick;

    public:

    std::string no_hint_mode();

    std::string hint_mode(std::string word);
};


#endif