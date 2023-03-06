#include <iostream>
#include "Playlist.h"
using namespace std;


void AddSong(PlaylistNode *head)
{
    string songID, songName, artist;
    int songLength;

    cout<<"ADD SONG"<<endl;
    cout<<"Enter song's unique ID:"<<endl;
    getline(cin, songID);
    cout<<"Enter song's name:"<<endl;
    getline(cin, songName);
    cout<<"Enter artist's name:"<<endl;
    getline(cin, artist);
    cout<<"Enter song's length (in seconds):"<<endl;
    cin>>songLength; 
    cin.ignore();
    cout<<endl;

    PlaylistNode* pNewsong = new PlaylistNode(songID, songName, artist, songLength);

    PlaylistNode* pNext = head->GetNext();
    PlaylistNode* pLast = head;

    while(pNext!=0)
    {
        pLast = pNext;
        pNext = pNext->GetNext();
    }

    pLast->SetNext(pNewsong);

}


void RemoveSong(PlaylistNode *head)
{
    cout<<"REMOVE SONG"<<endl;
    cout<<"Enter song's unique ID:"<<endl;
    string SongID2Remove;
    cin>>SongID2Remove;
    cin.ignore();

    PlaylistNode *pCurr=head, *pNext;
    
    while(pCurr->GetNext()->GetID()!=SongID2Remove)
    {
        pCurr = pCurr->GetNext();
    }

    pNext = pCurr->GetNext();
    pCurr->SetNext(pNext->GetNext());
    cout<<"\""<<pNext->GetSongName()<<"\" removed."<<endl<<endl;
    delete pNext;

}

void ChangeSongPosition(PlaylistNode *head)
{
    
    PlaylistNode *temp=head;
    int currentPos, newPos, listLen=0;

    if(temp->GetNext()==0) {cout<<"List is empty!"<<endl; return;}
    while(temp->GetNext()!=0) 
    {
        temp=temp->GetNext();
        listLen+=1;
    }

    cout<<"CHANGE POSITION OF SONG"<<endl;
    cout<<"Enter song's current position:"<<endl;
    cin>>currentPos;

    cout<<"Enter new position for song:"<<endl;
    cin>>newPos;
    cin.ignore();
     

    
    if(newPos<1) newPos = 1;
    if(newPos>listLen) newPos = listLen;

    PlaylistNode *pOldNext=head, *pOldCurr, *pNew=head;
    for(int i=0; i<currentPos; i++)
    {
       pOldCurr = pOldNext;
       pOldNext = pOldNext->GetNext();    
    }
    
    pOldCurr->SetNext(pOldNext->GetNext());
    

    for(int i=0; i<newPos-1; i++)
    {
        pNew = pNew->GetNext();
    }

    pNew->InsertAfter(pOldNext);
    cout<<"\""<<pOldNext->GetSongName()<<"\" moved to position "<<newPos<<endl<<endl;

}

void OutputSongByArtist(PlaylistNode *head)
{
    cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
    cout<<"Enter artist's name:"<<endl<<endl;

    string artistName;
    getline(cin, artistName);

    PlaylistNode *temp;
    if(head->GetNext()!=0) temp=head->GetNext();
    else 
    {
        cout<<"Empty list!"<<endl;
        return; 
    }

    int index=1;
    do
    {
        if(temp->GetArtistName()==artistName)
        {
            cout<<index<<"."<<endl;
            temp->PrintPlaylistNode();
            cout<<endl;
        }
        index+=1;
        temp = temp->GetNext();
    }while(temp!=0);

}

void OutputTotalTimeOfPlaylist(PlaylistNode* head)
{
    int totalTime=0;
    PlaylistNode *ptemp=head->GetNext();
    cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
    if(ptemp==0)
    {
        cout<<"Total time: 0 seconds"<<endl;
    }

    do
    {
        totalTime+=ptemp->GetSongLength();
        ptemp = ptemp->GetNext();
    }while(ptemp!=0);
    cout<<"Total time: "<<totalTime<<" seconds"<<endl<<endl;

}

void OutputFullPlaylist(PlaylistNode* head)
{
    if(head->GetNext()==0) {cout<<"Playlist is empty"<<endl<<endl; return;}

    PlaylistNode *ptemp=head->GetNext();
    int i=1;

    do
    {
        cout<<i<<"."<<endl;
        ptemp->PrintPlaylistNode();
        cout<<endl;
        ptemp = ptemp->GetNext();
        i+=1;

    }while(ptemp!=0);


}


void PrintMenu(string PlaylistName)
{

    PlaylistNode* head = new PlaylistNode;
    
    char option;

    do
    {
        cout<<PlaylistName<<" PLAYLIST MENU"<<endl;
        cout<<"a - Add song"<<endl;
        cout<<"d - Remove song"<<endl;
        cout<<"c - Change position of song"<<endl;
        cout<<"s - Output songs by specific artist"<<endl;
        cout<<"t - Output total time of playlist (in seconds)"<<endl;
        cout<<"o - Output full playlist"<<endl;
        cout<<"q - Quit"<<endl<<endl;
        cout<<"Choose an option:"<<endl;
        cin>>option;
        cin.ignore();

        switch(option)
        {
           case 'a': AddSong(head); break;
           case 'd': RemoveSong(head); break;
           case 'c': ChangeSongPosition(head); break;
           case 's': OutputSongByArtist(head); break;
           case 't':
                cout<<PlaylistName<<" - OUTPUT FULL PLAYLIST"<<endl; 
                OutputTotalTimeOfPlaylist(head); 
                break;
           case 'o':
                cout<<PlaylistName<<" - OUTPUT FULL PLAYLIST"<<endl;  
                OutputFullPlaylist(head); break;
           case 'q': break;


        }
        
    }while(option!='q');

}

int main()
{
    string PlaylistName;
    cout<<"Enter playlist's title:"<<endl<<endl;
    getline(cin, PlaylistName);


    PrintMenu(PlaylistName);
    return 0;
}