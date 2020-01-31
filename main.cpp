#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "intro_to_outro_display.h"



int main()
{
    
    // where all the initializations begin.
    int point = 0;
    int num_of_tries_left;
    int repeated_letter = 1;
    int length_of_num_of_words = 0;
    int num_of_tries = 0;
    int choice = 0;
    int point2 = 0;
    
    std::string word;
    std::vector<char> another_word;
    std::vector<char> wordbank;
    std::vector<char> design;
    
    char letter;
    char prev_letter = '_';
    char placeholder = '_';

    //user-defined classes
    Cout_stuff hangman;
    Easy_or_hard hangman_choice;
    
    //the program starts here

    hangman.display_intro();

    num_of_tries = hangman.setNum_of_tries();     
    
    //If they do not press the right number of tries
    
    while( (num_of_tries <= 0 ) || (num_of_tries > 26) ){
        
            std::cout << "Number was not betweeen 1 and 26" << std::endl;
            std::cout << " Game terminated, Goodbye!" << std::endl;
            
            exit(0);
    }
    
    hangman.display_rules();

    std::cout << "" << std::endl;
    std::cout << "You have two modes:" << std::endl;
    std::cout << "press 1 for hint mode" << std::endl;
    std::cout << "press 2 for non-hint mode" << std::endl;
    std::cin >> choice;

        while(!((choice == 1) || (choice == 2)))
        {
            std::cout << "please pick 1 or 2" << std::endl;
            std::cin >> choice;
           
        }

        if (choice == 2)
        {
            hangman.setWord(hangman_choice.no_hint_mode());
            word = hangman_choice.no_hint_mode();

        }
        if(choice == 1)
        {
            word = hangman.setWord(hangman_choice.hint_mode(word));
        }

        
        
      
        // can comment or uncomment out. uncomment to actually play game
        //std::cout << word << std::endl;
        
        //begin place holders for the words that will be inputed later
        for(int i = 0; i < word.length(); i++)
        {
            another_word.push_back(placeholder);
        }

        //cout the place holder on terminal
        //for(int i = 0; i < word.length(); i++){
           // std::cout << another_word[i] << '\t';
            
        //}

        //THE GAME BEGINS HERE!
        while(point == 0){

        hangman.setWordbank();
        
        // if there are more than three  or two non repeating then game over!
        hangman.check_and_display();    
        
            // see if previous letter matches with the inputed letter
                if (prev_letter == hangman.getLetter()){
                    
                    std::cout << "" << std::endl;
                    std::cout << "___________________________________________________________" << std::endl;

                    
                    std::cout << "please choose a different letter ";
                    repeated_letter = repeated_letter + 1;
                    num_of_tries_left = num_of_tries - repeated_letter + 1;
                        if(num_of_tries_left > 0){
                            std::cout << " (You have " << num_of_tries_left << " attempts left) " << std::endl;
                            std::cout << "___________________________________________________________" << std::endl;

                        }else if( num_of_tries_left <= 0 ){
                            
                            hangman.no_more_attempts();
                            
                            exit(0);
                        }
                            std::cout << "" << std::endl;
                    
                }else //otherwise continue and update some or non of the placeholders
                {
                    
                for(int i = 0; i < word.size(); i++){
                
                    if( hangman.getLetter() == word.at(i)){
                    //if so, update the vector with the place holder to replace the word
                                     
                    another_word[i] = word.at(i);
                    // reinitialize to zero to restart the number of attempts.
                    repeated_letter = 0;
                    
                    }
                    

                }

                    

                
                    
                    
                    
                //this will be more than 1 if we did not get any letter to match.
                repeated_letter = repeated_letter + 1;

                // if repeated_letter is zero then we got a letter correct and restart the number of attempts
                num_of_tries_left = num_of_tries - repeated_letter + 1;
                
                // the updated vetor!
                for(int i = 0; i < word.length(); i++){
                std::cout << another_word[i] << '\t';}
                
                if(num_of_tries_left > 0){
                std::cout << " You have " << num_of_tries_left << " attempts left " << std::endl;
                std::cout << "" << std::endl;
                
                }else if( num_of_tries_left <= 0 ){
                    
                    hangman.no_more_attempts();
                    
                    exit(0);
                }

        
            if( num_of_tries_left <= 0){
                
                //this will end the while loop
                point = 1;
                
                hangman.no_more_attempts2();
            }
            
            //will check if the words match by counting number of matchs
            for(int i = 0; i < word.length(); i++){
                
                if( another_word[i] == word.at(i)){
                    
                    length_of_num_of_words = length_of_num_of_words + 1;
                
                }
                
            }
                // if number is the number of words we are finished!
                if(word.length() == length_of_num_of_words){

                    hangman.You_win();    
                    
                    point = 1;
                }else{
                    length_of_num_of_words = 0;
                }
            
            
                }
                
                prev_letter = hangman.getLetter();
                
        }
        
        

            

    
}
