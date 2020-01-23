#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <cassert>
#include "lib_playlist.h"


int main() {

    Player p;
    auto p1 = p.createPlaylist("p1");
    auto p2 = p.createPlaylist("p2");
    auto p3 = p.createPlaylist("p3");
    auto p4 = p.createPlaylist("p4");

    p1->add(p2);
    p1->add(p3);
    p1->add(p4);
    p1->add(p3);
    p1->add(p2);

    p1->play();

    std::cout << "=====\n";


    p1->play();
    std::cout << "=====\n";
    p1->play();

    return 0;
}