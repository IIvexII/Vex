/*
    Project Name:   Vex
    Submitted to:   Imran Khalid
    Group Members:  Muhammad Zafeer(Group leader)
                    Raees Abbas
*/
#include "design.h"
#include <cstring>
using namespace std;

int main(){
    // Made a variable for storing choice of user.(y/n)
    string choice;
    do{
        // character array for storing city name
        char city_name[100]={};

        // for storing single character.
        char character=0;

        // for storing index of that city_name array
        int index=0;
        
        // Printing Logo
        logo();
        
        // Show search city
        // - setw is a manipulator which set the width of the output.
        cout << setw(40) << "Search City: ";

        // Get city name from user
        while(character!='\r' && index<100){
            character = getch();
            if(character!='\r'){
                if(character!='\b' && character!='\t'){
                    cout << character;
                    city_name[index] = character;
                    index++;
                }
                else if(index!=0 && character!='\t'){
                    index--;
                    city_name[index]= '\0';
                    cout << '\b' << " " << '\b';
                }
            }
        }
        // Store null byte at the end of city name.
        city_name[index]='\0';
        cout << endl << endl;

        // reset the index to 0 for next input if required.
        index = 0;

        // Open file in write mode.
        ofstream city_file;
        city_file.open ("weather_info.txt");
        // Store city name in file.
        city_file << city_name;
        city_file.close();
        
        // get data from file
        // - run our python script to get
        //   data from openweathermap.com using API
        weather_getter();

        // Print that data into a nice format
        weather_parser();

        do{
            cout << setw(40) << "Do you want to check again? (y/n)";
            getline(cin, choice);            
        }while(choice!="Y" && choice!="y" && choice!="n" && choice!="N");

    }while(choice=="Y" || choice=="y");
    return 0;
}
