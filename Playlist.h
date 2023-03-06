#include <iostream>

using namespace std;

class PlaylistNode
{
    public:
    PlaylistNode()
    {
        uniqueID = "none";
        songName = "none";
        artistName = "none";
        songLength = 0;
        nextNodePtr = 0;
    };
    PlaylistNode(string ID, string sName, string aName, int sLength, PlaylistNode* nPtr = 0)
    {
        uniqueID = ID;
        songName = sName;
        artistName = aName;
        songLength = sLength;
        nextNodePtr = nPtr;

    }

    void InsertAfter(PlaylistNode *pNode);
    void SetNext(PlaylistNode *pNode);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();

    private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr; 

    
};