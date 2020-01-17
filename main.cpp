#include <iostream>
#include "lib_playlist.h"
int main() {

    std::shared_ptr<Playable> song1 = std::make_shared<Song>(Song("A", "A", "", "lalalalalala"));
    std::shared_ptr<Playable> song2 = std::make_shared<Song>(Song("B", "B", "", "lalalalalala"));
    std::shared_ptr<Playable> song3 = std::make_shared<Song>(Song("C", "C", "", "lalalalalala"));
    std::shared_ptr<Playable> song4 = std::make_shared<Song>(Song("D", "D", "", "lalalalalala"));


    Playlist list("lista");
    list.add(song1);
    list.add(song2);
    list.add(song3);
    list.add(song4);

    list.play();


    return 0;
}