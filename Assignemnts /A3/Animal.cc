// Mihir Gupta
// 101172281
#include <iostream>
#include<string>
#include <iomanip>

using namespace std;

#include "Animal.h"

int Animal::nextID = 1001;

Animal::Animal(SpeciesType spec, string b, string col, string n, string gen, int year, int month)
    : Identifiable("A",nextID), name(n), breed(b), gender(gen), colour(col), species(spec)
{
    age = ((year*12) + month);
}

Animal::~Animal()
{

}

string Animal::getName(){
    return name;
}
string Animal::getBreed(){
    return breed;
}
string Animal::getGender(){
    return gender;
}

int Animal::getAge(){
    return age;
}

// returns the species 
string Animal::getSpecies(){

    if(species == 0){
        return "Dog";
    }
    else if(species == 1){
        return "Cat";
    }
    else if(species == 2){
        return "Bird";
    }
    else if(species == 3){
        return "Rabbit";
    }
    else if(species == 4){
        return "Other";
    }

    return "Other";
}

void Animal::print() const{

    int y = age/12;
    int m = age - (y*12);

    cout    << setw(10) << left << id     <<" "  
            << setw(25) << left << breed  <<" "
            << setw(15) << left << name   << " "
            << setw(5)  << left << gender << " "
            << setw(12)  << left << colour << " ";

    cout<<"   ";

    if(species == 0){
        cout<<"Dog"<<"     ";
    }
    if(species == 1){
        cout<<"Cat" <<"     ";
    }

    if(species == 2){
        cout<<"Bird" <<"    ";
    }

    if(species == 3){
        cout<<"Rabbit" <<"  ";
    }

    if(species == 4){
        cout<<"Other" <<"   ";
    }

    cout << setw(5) << right << y << "Y, " << m << "M"<<endl;
}