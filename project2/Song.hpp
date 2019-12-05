#pragma once

#include <string>

class Song {
private:
    std::string name_;
    std::string artist_;
    std::string album_;
    unsigned int duration_;
    bool explicit_lyrics_;

public:
    Song(std::string, std::string, std::string, unsigned int, bool);
    Song();

    std::string name();
    std::string artist();
    std::string album();
    unsigned int minutes();
    unsigned int seconds();
    bool explicit_lyrics();

};
bool Song::explicit_lyrics(){ return explicit_lyrics_; }

Song::Song(std::string name1, std::string artist1, std::string album1, unsigned int duration1, bool explicit_lyrics1) : name_(name1), artist_(artist1), album_(album1), duration_(duration1), explicit_lyrics_(explicit_lyrics1) {}

Song::Song(){
  name_ = "";
  artist_= "";
  album_= "";
  duration_= 0;
  explicit_lyrics_ = false;
}

std::string Song::name(){ return name_;}
std::string Song::artist(){ return artist_;}
std::string Song::album(){ return album_;}

unsigned int Song::minutes(){
  int minutes = duration_ / 60;
  return minutes;
}
unsigned int Song::seconds(){
  int seconds = duration_ % 60;
  return seconds;
}
