// File:        song.cpp
// Author:      Geoffrey Tien
// Date:        2015-05-24
// Description: Implementation of a Song class to be used for CMPT 225 assignment #2
//              FILE REQUIRES NO MODIFICATIONS

#include "song.h"

// Default constructor
Song::Song()
{
  artist = "";
  title = "";
}

// Parameterized constructor
Song::Song(string theartist, string thetitle)
{
  artist = theartist;
  title = thetitle;
}

// ACCESSORS
// Methods for retrieving song information
string Song::GetArtist() const
{
  return artist;
}

string Song::GetTitle() const
{
  return title;
}

// overloaded assignment operator
Song& Song::operator=(const Song& s)
{
  // only copy fields if the calling object is not the same as the parameter
  if (this != &s)
  {
    artist = s.artist;
    title = s.title;
  }
  return *this; // dereference pointer
}

// equality / not-equals operators
// equality is true if all fields match
// not-equals is true if any field does not match
bool Song::operator==(const Song& s) const
{
  return (artist == s.artist && title == s.title);
}

bool Song::operator!=(const Song& s) const
{
  return !(*this == s);
}