// File:        playlist.h
// Author:      Geoffrey Tien
// Date:        2015-05-25
// Description: Declaration of a music PlayList class to be used for CMPT 225 assignment #2
//              FILE REQUIRES NO MODIFICATIONS

#pragma once

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <string>
#include "circularlinkedlist.h"
#include "song.h"

using namespace std;

class PlayList
{
  private:
    CircularLinkedList<Song> sequence;
    int nowplaying; // 1-indexed value of currently selected song

  public:
    // default constructor
    PlayList();

    // ACCESSORS

    // Returns the number of items in the playlist
    // Calls LinkedList.Size();
    int Size() const;

    // MUTATORS

    // Advances the nowplaying counter by 1.
    // If the end of the list is reached, loop to the start of the list.
    void Play();

    // Enqueues an item at the back of the playlist
    // nowplaying remains the same unless the added item is the first in an empty playlist
    void Add(Song song);

    // Moves the item in nowplaying position up (towards the front) by 1, if playlist contains any items.
    // Has no effect if playlist is empty.
    // If item is already at the front, it remains at the front
    // POST:   position of nowplaying item is swapped with one ahead,
    //         nowplaying is reduced by 1 unless it is at the front of the list
    void MoveUp();

    // Moves the item in nowplaying position down (towards the back) by 1, if playlist contains any items.
    // Has no effect if playlist is empty.
    // If item is already at the back, it remains at the back
    // POST:   position of item is swapped with one behind,
    //         nowplaying is increased by 1 unless it is at the back of the list
    void MoveDown();

    // Removes the nowplaying item from the playlist
    // POST: nowplaying item is removed, nowplaying index moves to next item (if any)
    //       if last item is removed, nowplaying index moves to new last item
    void Remove();

    // OTHER

    // Prints the contents of the (1-indexed) playlist to console,
    //  with one song on each line of output, preceded by nowplaying icon and number, in the following format:
    // "<now playing><position>. <artist> - <title>"
    //  e.g. (* indicates nowplaying)
    //   1. dj whocares - my favourite song
    //  *2. dj whocares - my least favourite song
    //   3. mc noname - forgettable
    void PrintPlayList() const;

    // Returns a reference to the underlying CircularLinkedList object
    // You do not need to implement this function in your .cpp file.
    // NOTE: This is dangerous and should not be used in practice!
    //       This function is here only for the instructor/TA to check the correctness of your linked list!
    CircularLinkedList<Song> GetList() const
    {
      return sequence;
    }
};