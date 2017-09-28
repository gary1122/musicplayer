// File:        a2playlistdriver.cpp
// Author:      Geoffrey Tien
// Date:        2015-05-24
// Description: Interactive test driver for PlayList class
//              Only PlayList functions are tested. You are still responsible
//              for thoroughly testing your CircularLinkedList functions
//              using your own test driver.

#include <iostream>
#include <string>
#include "playlist.h"

using namespace std;

// forward declarations
void PrintMenu();

// program entry point
int main()
{
  int choice = 0;
  string artistname;
  string songname;
  PlayList pl;

  while (choice != 7)
  {
    PrintMenu();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush the cin stream including newline

    switch (choice)
    {
      case 1: // Print playlist
        pl.PrintPlayList();
        break;
      case 2: // Add a song
        cout << "\nEnter the artist name: ";
        getline(cin, artistname);
        cout << "\nEnter the song name: ";
        getline(cin, songname);
        pl.Add(Song(artistname, songname));
        break;
      case 3: // Move a song up
        pl.MoveUp();
        break;
      case 4: // Move a song down
        pl.MoveDown();
        break;
      case 5: // Play a song
        pl.Play();
        break;
      case 6: // Remove a song
        pl.Remove();
        break;
      case 7: // Quit
        // no need to do anything, will cause while loop to break
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  }

  return 0;
}

void PrintMenu()
{
  cout << "****************************************************\n"
       << "* Please select an option:                         *\n"
       << "* 1. Print playlist            5. Play a song      *\n"
       << "* 2. Add a song to playlist    6. Remove a song    *\n"
       << "* 3. Move a song up                                *\n"
       << "* 4. Move a song down          7. Quit             *\n"
       << "****************************************************\n" << endl;
  cout << "Enter your choice: ";
}