#include <iostream>
#include <string.h>

class PhotonCannon {
    int hp, shield;
    int coord_x, coord_y;
    int dmg;

    char* name;

public:
    PhotonCannon(int x, int y);
    PhotonCannon(int x, int y, const char* cannon_name);
    PhotonCannon(const PhotonCannon& pc);
    ~PhotonCannon();

    void showStatus();
};

PhotonCannon::PhotonCannon(const PhotonCannon& pc) {
    std::cout << "복사 생성자 호출 !" << std::endl;

    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    dmg = pc.dmg;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

PhotonCannon::PhotonCannon(int x, int y, const char* cannon_name) {
    std::cout << "생성자 호출 !" << std::endl;

    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    dmg = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}


PhotonCannon::PhotonCannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;

    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    dmg = 20;

    name = NULL;
}

PhotonCannon::~PhotonCannon() {
    if (name) delete[] name;
}

void PhotonCannon::showStatus() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << "Loc: (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main() {
    PhotonCannon pc1(3,3, "cannon");
    PhotonCannon pc2(pc1);

    pc1.showStatus();
    pc2.showStatus();
}
