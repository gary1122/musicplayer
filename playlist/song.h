// File:        song.h
// Author:      Geoffrey Tien
// Date:        2015-05-24
// Description: Declaration of a Song class to be used for CMPT 225 assignment #2
//              FILE REQUIRES NO MODIFICATIONS

#pragma once
#include <string>
using namespace std;

class Song
{
  private:
    string artist;
    string title;

  public:
    // Default constructor
    Song();

    // Parameterized constructor
    Song(string theartist, string thetitle);

    // Destructor not required.
    // Class does not contain any member variables in dynamic memory

    // Class will not support mutators

    // ACCESSORS
    // Methods for retrieving song information
    string GetArtist() const;
    string GetTitle() const;

    // other functions
    
    //OVERLOADED OPERATORS
    // assignment operator
    Song& operator=(const Song& s);
    // equality / not-equals operators
    // equality is true if all fields match
    // not-equals is true if any field does not match
    bool operator==(const Song& s) const;
    bool operator!=(const Song& s) const;
};