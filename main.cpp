#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h> 
#include <cmath>


int main()
{
    
    // where all the initializations begin.
    int point = 0;
    int num_of_tries_left;
    int repeated_letter = 1;
    int length_of_num_of_words = 0;
    unsigned int num_of_tries;
    int number_of_words = 5;
    
    std::string word;
    std::vector<char> another_word;
    std::vector<char> wordbank;
    std::vector<char> design;
    
    char answer;
    char letter;
    char prev_letter;
    char placeholder = '_';
    
    //the program starts here
    
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;  
    std::cout << "Hello!" << std::endl;
    std::cout << "" << std::endl;  
    std::cout << "Today you will be guessing a word letter by letter." << std::endl;
    std::cout << "___________________________________________________________" << std::endl;
    std::cout << "Please pick the number of attempts you'd like to have for each letter ( between 1 and 100)." << std::endl;
    std::cin >> num_of_tries;
    
    //If they do not press the right number of tries
    
    while( (num_of_tries <= 0 ) || (num_of_tries > 100) ){
        
            std::cout << "Number was not betweeen 1 and 100" << std::endl;
            std::cout << " Game terminated, Goodbye!" << std::endl;
            
            exit(0);
    }
    

    std::cout << "" << std::endl; 
    std::cout << "" << std::endl;
    std::cout << "You will have " << num_of_tries << " attempt for each letter of the word. " << std::endl;
        
    std::cout << "___________________________________________________________" << std::endl;
    
    std::cout << "RULE1: If you repeat a letter that is not the correct letter(e.g. r r) then that is an attempt." << std::endl;
    std::cout << "RULE2: If you repeat a letter more than three times or have you two non-consecutive letters which were already used" << std::endl;
    std::cout << "       (e.g.  a b b b  or  a b e d c a   ) then GAME OVER. " << std::endl;
    std::cout << "___________________________________________________________";
    std::cout << "___________________________________________________________";
    std::cout << "" << std::endl;
    std::cout << "Now, the guessing starts when you pick a letter." << std::endl;
    std::cout << "Good luck!" << std::endl;
        
     // set up the vector that will store the words for the "List of words" doc   
     std::vector<std::string> comp_pick;  
     
     std::ifstream file ("List of words");
     
     //random generator (everytime)
     srand(time (NULL));
     int random_number = rand()%1001;
     
     
        //store the words in comp_picks( short for computer picks)
         std::string input;
         
            while(file >> input){
                comp_pick.push_back(input);
            }
            
            // to check if it works uncomment the next two lines
            //for(int i = 0; i < comp_pick.size(); i++){
            // std:: cout << comp_pick[i] << std::endl;}
        
        //generate a random word everytime program runs
        word = comp_pick[random_number];
        
      
        // can comment or uncomment out. uncomment to actually play game
        //std::cout << word << std::endl;
        
        //begin place holders for the words that will be inputed later
        for(int i = 0; i < word.length(); i++){
            another_word.push_back(placeholder);
        }

        //cout the place holder on terminal
        //for(int i = 0; i < word.length(); i++){
           // std::cout << another_word[i] << '\t';
            
        //}

        //THE GAME BEGINS HERE!
        while(point == 0){
            
        std::cout << "please pick a letter" << std::endl;
        std::cout << "" << std::endl;
        std::cin >> letter;
        wordbank.push_back(letter);
        
        std::cout << "___________________________________________________________" << std::endl;
        std::cout << "" << std::endl;
        
        std::cout << "LETTERS YOU'VE ALREADY USED:";
        for(int i = 0; i < wordbank.size(); i++){
            std::cout << wordbank[i];
        } 
        std::cout << "" << std::endl;
        std::cout << "___________________________________________________________" << std::endl;

        
        // if there are more than three  or two non repeating then game over!
        if(wordbank.size() > 2){
            for(int i = 0; i < wordbank.size(); i++){
                for(int j = i+1; j < wordbank.size(); j++){
                        if(wordbank[i] == wordbank[j]){
                            for(int k = j+1 ; k < wordbank.size(); k++){
                                if(wordbank[i] == wordbank[k]){
                                    std::cout << "" << std::endl;
                                    std::cout << "___________________________________________________________" << std::endl;

                                    std::cout << "Too many repeated letter!(more than 3)" << std::endl;
                                    std::cout << "Game terminated"<< std::endl;
                                    std::cout << " The word was: " << word << std::endl;
                                    std::cout << "Goodbye!" << std::endl;
                                    
                                    exit(0);
                                    
                                }
                            }
                            
                        }
                }
            
                    
                }
            
            }
            
            if(wordbank.size() > 2){
            for(int i = 0; i < wordbank.size(); i++){
                for(int j = i+2; j < wordbank.size(); j++){
                        if(wordbank[i] == wordbank[j]){
                            
                                    std::cout << "" << std::endl;
                                    std::cout << "___________________________________________________________" << std::endl;

                            
                                    std::cout << "Game terminated!"<< std::endl;
                                    std::cout << "You have two non-consecutive letters that occured." << std::endl;
                                    std::cout << "(GAME OVER) The word was: " << word << std::endl;
                                    std::cout << "Goodbye!" << std::endl;
                                    
                                    exit(0);
                                    
                                }
                            }
                            
                        }
                }
            
        
            // see if previous letter matches with the inputed letter
                if (prev_letter == letter){
                    
                    std::cout << "" << std::endl;
                    std::cout << "___________________________________________________________" << std::endl;

                    
                    std::cout << "please choose a different letter ";
                    repeated_letter = repeated_letter + 1;
                    num_of_tries_left = num_of_tries - repeated_letter + 1;
                        if(num_of_tries_left > 0){
                            std::cout << " (You have " << num_of_tries_left << " attempts left) " << std::endl;
                            std::cout << "___________________________________________________________" << std::endl;

                        }else if( num_of_tries_left <= 0 ){
                            
                            std::cout << "" << std::endl;
                            std::cout << "___________________________________________________________" << std::endl;

                            std::cout << " You have no attempts left (GAME OVER)  " << std::endl;
                             std::cout << "You have lost. The word was: " << word << std::endl;
                            std::cout << "Goodbye!" << std::endl;
                            exit(0);
                        }
                            std::cout << "" << std::endl;
                    
                }else //otherwise continue and update some or non of the placeholders
                {
                    
                for(int i = 0; i < word.size(); i++){
                
                    if( letter == word.at(i)){
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
                    
                   
                    
                    std::cout << " You have no attempts left (GAME OVER) " << std::endl;
                    
                    std::cout << "" << std::endl;
                    std::cout << "___________________________________________________________" << std::endl;

                    std::cout << "You have lost. The word was: " << word << std::endl;
                    std::cout << "Goodbye!" << std::endl;
                    exit(0);
                }

        
            if( num_of_tries_left <= 0){
                
                //this will end the while loop
                point = 1;
                
                std::cout << "" << std::endl;
                std::cout << "___________________________________________________________" << std::endl;

                std::cout << "You have lost. The word was: " << word << std::endl;
                std::cout << "Better luck next time, goodbye!" << std::endl;
            }
            
            //will check if the words match by counting number of matchs
            for(int i = 0; i < word.length(); i++){
                
                if( another_word[i] == word.at(i)){
                    
                    length_of_num_of_words = length_of_num_of_words + 1;
                
                }
                
            }    
                // if number is the number of words we are finished!
                if(word.length() == length_of_num_of_words){
                    
                std::cout << "" << std::endl;
                std::cout << "___________________________________________________________" << std::endl;

                std::cout << "YOU WIN!! As you can see your word was: " << word << std::endl;
                std::cout << "Hope you come back and play again soon!" << std::endl;
                std::cout << "Goodbye!" << std::endl;
                point = 1;
                }else{
                    length_of_num_of_words = 0;
                }
            
            
                }
                
                prev_letter = letter; 
                
        } 
        
        

            

    
}