//Maxwell koegler | COMSC 210 | lab 23
#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip); //function prototpyes
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> trip;
    int c;

    do { //menu iterator
        c = main_menu();
        if(c ==1){
            add_goat(trip, names, colors);
        } else if(c == 2) {
            delete_goat(trip);
        } else if(c == 3) {
            display_trip(trip);
        }
    } while(c != 4);




    return 0;
}

int main_menu() { //menu setings
    int choice;
    cout << endl << "Goat manager 3000" << endl;
    cout << "1) add a goat" << endl;
    cout << "2) delete a goat" << endl;
    cout << "3) set goats" << endl;
    cout << "4) exit" << endl;
    cout << "choice : " << endl;

    cin >> choice;
    return choice;
}

void add_goat(set<Goat> &trip, string names[], string colors[]) { //random goat generator and adder
    trip.insert(Goat(names[rand()%SZ_NAMES], rand()%(MAX_AGE + 1), colors[rand() % SZ_COLORS]));
}

int select_goat(set<Goat> trip) {
    int i = 1;

    for(Goat goat:trip) {//selects a goat in a set
        cout << "[" << i++ << "] " << goat.get_name();        cout << " (" << goat.get_age() << ", ";
        cout << goat.get_color() << ")" << endl;
    }

    int choice;
    cout << "select gaot: ";
    cin >> choice;
    return choice;
}

void delete_goat(set<Goat> &trip) { //removes goat from set
    if(trip.empty()){
        return;
    }

    int choice = select_goat(trip); //goes thru the set and removes the goat
    set<Goat>::iterator t = trip.begin();
    advance(t, choice - 1);
    trip.erase(t);

}

void display_trip(set<Goat> trip) { //displays the trip
    for(Goat goat:trip){
        cout << goat.get_name() << " (" << goat.get_age();
        cout << ", " << goat.get_color() << ")" << endl;
    }
}

