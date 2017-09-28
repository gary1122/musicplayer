
 
#include "playlist.h"
 
 
//default constructor
PlayList::PlayList()
{
nowplaying = NULL;
}
 
int PlayList::Size() const
{
return sequence.Count();
}
 
void PlayList::Play()
{
if (nowplaying==NULL) { } // do nothing since the list is empty
else if (nowplaying == sequence.Count()) { nowplaying = 1;} //case when the end of the list is reached
else
{
 	 nowplaying++;
}
 
 
}
 
 
void PlayList::Add(Song song)
{
  
	if (nowplaying == NULL) {nowplaying = 1;sequence.Insert(song);}      //case when add a song to an empty list
	else
		{sequence.Insert(song);}
	

}
 
 
void PlayList::MoveUp()
{
 
if (nowplaying==NULL){}             //do nothing
else if (nowplaying ==1){}       //case do nothing when the nowplaying item is at the front ,
else
{
int index = nowplaying -1;      //0 indexed lined list;
try{
sequence.InsertAt(sequence.RemoveAt(index), index-1);
}  catch (exception e){ cout << e.what() << endl;}
nowplaying--;
}
 
}
 
void PlayList::MoveDown()
{
if (nowplaying==NULL){}             //do nothing 
else if (nowplaying == sequence.Count()){}       //case do nothing when the nowplaying item is at the back ,
else
{
int index = nowplaying -1;      //0 indexed lined list;
try{
sequence.InsertAt(sequence.RemoveAt(index), index+1);
}  catch (exception e){ cout << e.what() << endl;}
nowplaying++;
}
 
}
 
void PlayList::Remove()
{
if (nowplaying==NULL){}             //do nothing
else if (nowplaying == sequence.Count())     //remove last item in the list
{
 	  	  int index = nowplaying-1;
		  try{	  sequence.RemoveAt(index);}  catch (exception e){ cout << e.what() << endl;}
 	  	  nowplaying --;
}
else
{
int index = nowplaying-1;
try{sequence.RemoveAt(index);} catch (exception e){ cout << e.what() << endl;}
 
}
}
// Prints the contents of the (1-indexed) playlist to console,
 
    //  with one song on each line of output, preceded by nowplaying icon and number, in the following format:
 
    // "<now playing><position>. <artist> - <title>"
 
    //  e.g. (* indicates nowplaying)
 
    //   1. dj whocares - my favourite song
 
    //  *2. dj whocares - my least favourite song
 
    //   3. mc noname - forgettable
void PlayList::PrintPlayList() const
{
 Song song;
 for (int i= 0 ; i<sequence.Count();i++)
 {
	 try{	 song = sequence.ElementAt(i);} catch (exception e){ cout << e.what() << endl;}
 	 if (i+1 == nowplaying)
 	 {cout << "*"<<i+1 << ". " << song.GetArtist() << " - " <<song.GetTitle()<<endl;}
 	 else {cout << " "<<i+1 << ". " << song.GetArtist() << " - " <<song.GetTitle()<<endl;}
 }
 
}
 
 
 
