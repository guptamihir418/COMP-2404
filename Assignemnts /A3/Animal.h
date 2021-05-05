// Mihir Gupta
// 101172281
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "Identifiable.h"
#include "defs.h"

class Animal : public Identifiable 
{

    public:
        Animal(SpeciesType=C_OTHER, string="Breed", string="Colour", string="Name", string="Gender", int=0, int=0);
        ~Animal();

        string getName();
        string getBreed();
        string getGender();
        int getAge();
        string getSpecies();
        void print() const;

    private:
        // independence
        static int nextID;
        string name, breed, gender, colour;
        SpeciesType species;
        int age;  // should be no. of months


    };

#endif