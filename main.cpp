#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include "lib_playlist.h"
int main() {

    std::shared_ptr<Playable> song1 = std::make_shared<Song>(Song("A", "A", "", "lalalalalala"));
    std::shared_ptr<Playable> song2 = std::make_shared<Song>(Song("B", "B", "", "lalalalalala"));
    std::shared_ptr<Playable> song3 = std::make_shared<Song>(Song("C", "C", "", "lalalalalala"));
    std::shared_ptr<Playable> song4 = std::make_shared<Song>(Song("D", "D", "", "lalalalalala"));


    std::shared_ptr<Playlist> list = std::make_shared<Playlist>("lista");
    list->add(song1);
    list->add(song2);
    list->add(song3);
    list->add(song4);

    std::shared_ptr<Playlist> list2 = std::make_shared<Playlist>("lista");
    list2->add(song2);
    list2->add(song3);
    list2->add(song4);

    auto mode = createShuffleMode(0);
    list->setMode(mode);
    //list2->setMode(mode);

    list2->play();
    std::cout << "drugie play\n";
    list2->add(list);
    //list2->add(list);
    list2->play();



    return 0;
}