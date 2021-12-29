#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    const int dmg;
    bool is_dead;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_dmg);
    ~Marine() {total_marine_num--;}

    int atk() const;
    //void beAtked(int dmg_earn);
    Marine& beAttacked(int dmg_earn);
    void move(int x, int y);

    static void showTotalMarine();
    void showStatus();
};
int Marine::total_marine_num = 0;
void Marine::showTotalMarine() {
    std::cout << " total marine num is : " << total_marine_num << std::endl;
}

Marine::Marine(): hp(50), coord_x(0), coord_y(0), dmg(5), is_dead(false) {total_marine_num++;}
Marine::Marine(int x, int y): coord_x(x), coord_y(y), hp(50), dmg(5), is_dead(false) {total_marine_num++;}
Marine::Marine(int x, int y, int default_dmg): coord_x(x), coord_y(y), hp(50), dmg(default_dmg), is_dead(false) {total_marine_num++;}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::atk() const { return dmg; }
//void Marine::beAtked(int dmg_earn) {
//    hp -= dmg_earn;
//    if (hp < 1) is_dead = true;
//}

Marine& Marine::beAttacked(int dmg_earn) {
    hp -= dmg_earn;
    if (hp < 1) {
        is_dead = true;
    }

    return *this;
}

void Marine::showStatus() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location: (" << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << " HP: " << hp << std::endl;
    std::cout << " current total marine num is : " << total_marine_num << std::endl;
}

void createMarine() {
    Marine m3(10, 10, 4);
    Marine::showTotalMarine();
}

int main() {
    Marine m1(2, 3, 10);
    Marine::showTotalMarine();
    Marine m2(3, 5, 10);
    Marine::showTotalMarine();

    //m1.showStatus();
    //m2.showStatus();

    createMarine();

    std::cout << std::endl;
    std::cout << "마린1 이 마린2 를 2번 공격!" << std::endl;
    m2.beAttacked(m1.atk()).beAttacked(m1.atk());

    m1.showStatus();
    m2.showStatus();

    return 0;
}
