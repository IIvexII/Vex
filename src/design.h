#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
using namespace std;

// Function Prototypes
void logo();
void login();
void weather_getter();
void not_found();
void weather_parser();

// Global Variables
float console_width=125.0f;

void logo(){
    /*
        This function is made for displaying logo with
        the delay of 100 miliseconds on displaying each line.
    */
    system("CLS");
    char version[]="V 1.0";

    cout << setw(console_width/2) << " __   __   ___  __  __\n";
    Sleep(100);
    cout << setw(console_width/2) << " \\ \\ / /  / _ \\ \\ \\/ /\n";
    Sleep(100);
    cout << setw(console_width/2) << "  \\ V /  |  __/  >  < \n";
    Sleep(100);
    cout << setw(console_width/2) << "   \\_/    \\___| /_/\\_\\ ";
    cout << endl << endl << setw(console_width/2);
    
    for(int i=0; i<5; i++){
        cout << version[i];
        Sleep(100);
    }
    cout << "\n\n";
}

void weather_getter(){
    /*
        This function will execute the python script
        and give the given city as an argument to the script.
    */
    char command[30] = "python .\\get_weahter.py";
    system(command);
}

void not_found(){
    /*
        Just for fancy 
    */
    cout << endl;
    cout << setw(63) << "  _  _    ___  _  _   " << endl;
    cout << setw(63) << " | || |  / _ \\| || |  " << endl;
    cout << setw(63) << " | || |_| | | | || |_ " << endl;
    cout << setw(63) << " |__   _| | | |__   _|" << endl;
    cout << setw(63) << "    | | | |_| |  | |  " << endl;
    cout << setw(63) << "    |_|  \\___/   |_|  " << endl << endl << endl;
}
void weather_parser(){
    /*
        This function will get data from file 
        and print it in a nice format.
    */
    string weather_tags[] = {"", "Countery", "City", "Temperature", "Feels Like", "Humidity",
                             "Pressure", "Wind Type", "Wind Speed", "Wind Direction",
                             "Sky", "Visibility", "Weather Type"},
            weather_values[13];

    // open file in read mode.
    ifstream Weather("weather_info.txt");

    for(int i=1; getline(Weather, weather_values[i]);i++);
    Weather.close();
    if(weather_values[1]=="404"){
        not_found();
    }
    else{
        cout << setw(23) <<"" << "  __________________________________________________"<< endl;
        cout << setw(23) <<"" << "/|                                                  |\\"<< endl;
        for(int index=1; index<13; index++){
            cout << setw(24) << "| " << "|" << left << setw(20) << weather_tags[index] << setw(10) << 
            "|" <<  setw(20) << weather_values [index] << setw(10) << "| |" << right << endl;
        }
        cout << setw(23) <<"" << "\\|__________________________________________________|/"<< endl;
    }
}