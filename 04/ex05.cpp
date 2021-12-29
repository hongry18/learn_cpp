#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int dmg;
    bool is_dead;
    char* name;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);
    ~Marine();

    int attack();
    void beAttacked(int damage_earn);
    void move(int x, int y);

    void showStatus();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    dmg = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    dmg = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    dmg = 5;
    is_dead = false;
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
}

Marine::~Marine() {
    if (name != NULL) {
        std::cout << name << " 의 소명자 호출 !" << std::endl;
        delete[] name;
    }
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return dmg; }
void Marine::beAttacked(int damage_earn) {
    hp -= damage_earn;
    if (hp < 1) is_dead = true;
}
void Marine::showStatus() {
    std::cout << " *** Marine : " << name << " *** " << std::endl;
    std::cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(3, 5, "Marine 1");

    marines[0]->showStatus();
    marines[1]->showStatus();

    std::cout << std::endl << "m1 attack to m2" << std::endl;
    marines[0]->beAttacked(marines[1]->attack());

    marines[0]->showStatus();
    marines[1]->showStatus();

    delete marines[0];
    delete marines[1];

    return 0;
}
