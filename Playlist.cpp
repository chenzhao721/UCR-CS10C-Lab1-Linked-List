#include "Playlist.h"

void PlaylistNode::InsertAfter(PlaylistNode *pNode)
{
    PlaylistNode *pnext = this->GetNext(); 
    this->SetNext(pNode);
    pNode->SetNext(pnext);

}

void PlaylistNode::SetNext(PlaylistNode *pNode)
{
    this->nextNodePtr = pNode;
}

string PlaylistNode::GetID()
{
    return this->uniqueID;
}

string PlaylistNode::GetSongName()
{
    return this->songName;
}

string PlaylistNode::GetArtistName()
{
    return this->artistName;
}

int PlaylistNode::GetSongLength()
{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
    cout<<"Unique ID: "<<uniqueID<<endl;
    cout<<"Song Name: "<<songName<<endl;
    cout<<"Artist Name: "<<artistName<<endl;
    cout<<"Song Length (in seconds): "<<songLength<<endl;
}