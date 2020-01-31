#include "intro_to_outro_display.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>

void Cout_stuff::display_intro()
{
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Hello!" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Today you will be guessing a word letter by letter." << std::endl;
    std::cout << "___________________________________________________________" << std::endl;
    
}

int Cout_stuff::setNum_of_tries()
{
    std::cout << "Please pick the number of attempts you'd like to have for each letter (between 1 and 26)." << std::endl;    
    std::cin >> p_num_of_tries;
    
    return p_num_of_tries;
}

void Cout_stuff::display_rules()
{
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "You will have " << p_num_of_tries << " attempt for each letter of the word. " << std::endl;
    std::cout << "___________________________________________________________" << std::endl;
    std::cout << "RULE1: If you repeat a letter that is not the correct letter(e.g. r r) then that is an attempt." << std::endl;
    std::cout << "RULE2: If you repeat a letter more than three times or you have two non-consecutive letters which were already used" << std::endl;
    std::cout << "       (e.g.  a b b b  or  a b e d c a   ) then GAME OVER. " << std::endl;
    std::cout << "___________________________________________________________";
    std::cout << "___________________________________________________________";
    std::cout << "" << std::endl;
    std::cout << "The guessing begins when you pick a letter." << std::endl;
    std::cout << "Good luck!" << std::endl;
    
}

void Cout_stuff::check_and_display()
{
    if(p_wordbank.size() > 2){
            for(int i = 0; i < p_wordbank.size(); i++){
                for(int j = i+1; j < p_wordbank.size(); j++){
                        if(p_wordbank[i] == p_wordbank[j]){
                            for(int k = j+1 ; k < p_wordbank.size(); k++){
                                if(p_wordbank[i] == p_wordbank[k]){
                                    std::cout << "" << std::endl;
                                    std::cout << "___________________________________________________________" << std::endl;

                                    std::cout << "Too many repeated letter!(more than 3)" << std::endl;
                                    std::cout << "Game terminated"<< std::endl;
                                    std::cout << " The word was: " << p_word << std::endl;
                                    std::cout << "Goodbye!" << std::endl;
                                    
                                    exit(0);
                                    
                                }
                            }
                            
                        }
                }
            
                    
                }
            
            }
            
            if(p_wordbank.size() > 2){
            for(int i = 0; i < p_wordbank.size(); i++){
                for(int j = i+2; j < p_wordbank.size(); j++){
                        if(p_wordbank[i] == p_wordbank[j]){
                            
                                    std::cout << "" << std::endl;
                                    std::cout << "___________________________________________________________" << std::endl;

                            
                                    std::cout << "Game terminated!"<< std::endl;
                                    std::cout << "You have two non-consecutive letters that occured." << std::endl;
                                    std::cout << "(GAME OVER) The word was: " << p_word << std::endl;
                                    std::cout << "Goodbye!" << std::endl;
                                    
                                    exit(0);
                                    
                                }
                            }
                            
                        }
                }
        
}

void Cout_stuff::setWordbank()
{
    std::cout << "please pick a letter" << std::endl;
        std::cout << "" << std::endl;
        std::cin >> p_letter;
        p_wordbank.push_back(p_letter);
        
        std::cout << "___________________________________________________________" << std::endl;
        std::cout << "" << std::endl;
        
        std::cout << "LETTERS YOU'VE ALREADY USED:";
        for(int i = 0; i < p_wordbank.size(); i++){
            std::cout << p_wordbank[i];
        }
        std::cout << "" << std::endl;
        std::cout << "___________________________________________________________" << std::endl;

}


std::string Cout_stuff::setWord(std::string word)
{
    p_word = word;

    return word;
}

char Cout_stuff::getLetter()
{
    return p_letter;
}

void Cout_stuff::no_more_attempts()
{
    std::cout << "" << std::endl;
    std::cout << "___________________________________________________________" << std::endl;
    std::cout << "You have no attempts left (GAME OVER)  " << std::endl;
    std::cout << "You have lost. The word was: " << p_word << std::endl;
    std::cout << "Goodbye!" << std::endl;
}

void Cout_stuff::no_more_attempts2()
{
    std::cout << "" << std::endl;
                std::cout << "___________________________________________________________" << std::endl;

                std::cout << "You have lost with no attempts left. The word was: " << p_word << std::endl;
                std::cout << "Better luck next time, goodbye!" << std::endl;
}

void Cout_stuff::You_win()
{
    std::cout << "" << std::endl;
                std::cout << "___________________________________________________________" << std::endl;

                std::cout << "YOU WIN!! As you can see your word was: " << p_word << std::endl;
                std::cout << "Hope you come back and play again soon!" << std::endl;
                std::cout << "Goodbye!" << std::endl;
               
}

std::string Easy_or_hard::no_hint_mode()
{
    //random generator (everytime)
     srand(static_cast<unsigned int>(time(nullptr)));
     int random_number = rand()%1001;
        
     // set up the vector that will store the words for the "List of words" doc
     std::vector<std::string> p_comp_pick;

     std::ifstream file ("List of words");
     
     
        //store the words in comp_picks( short for computer picks)
         std::string input;
         
            while(file >> input){
                p_comp_pick.push_back(input);
            }
            
            // to check if it works uncomment the next two lines
            //for(int i = 0; i < comp_pick.size(); i++){
            //std:: cout << comp_pick[i] << std::endl;}
        
        //generate a random word everytime program runs
        
   

        return p_comp_pick[random_number];
        
}

std::string Easy_or_hard::hint_mode(std::string word)
{
    //random generator (everytime)
     srand(static_cast<unsigned int>(time(nullptr)));
     int random_number2 = rand()%29;
        
     // set up the vector that will store the words for the "List of words" doc
     std::vector<std::string> p_comp_pick_syn;
     std::vector<std::string> p_comp_pick_syn2;

     std::ifstream file ("easywords");
     std::ifstream file2 ("easywords syn");
     
     
        //store the words in comp_picks( short for computer picks)
         std::string syn;
         std::string syn2;
         
            while(file >> syn)
            {
                p_comp_pick_syn.push_back(syn);
            }

            while(file2 >> syn2)
            {
                p_comp_pick_syn2.push_back(syn2);
            }
            
            //to check if it works uncomment the next two lines
            //for(int i = 0; i < comp_pick.size(); i++){
            //std:: cout << comp_pick[i] << std::endl;}
        
        //generate a random word everytime program runs

        std::cout << "" << std::endl;
        std::cout << "Your word has the following synonyms: "  << p_comp_pick_syn2[random_number2] << std::endl;
        std::cout << "Please remember the given hint." << std::endl;
        
        word = p_comp_pick_syn[random_number2];


        


        return word;
        
}
