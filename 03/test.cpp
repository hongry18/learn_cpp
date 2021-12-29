#include <iostream>

int ex01() {
    int* p = new int;

    *p = 10;

    std::cout << *p << std::endl;

    delete p;
    return 0;
}

int ex02() {
    int a = 5;
    delete &a;
    return 0;
}

int ex03() {
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    int* list = new int[arr_size];
    for (int i=0, e=arr_size; i<e; i++) {
        std::cin >> list[i];
    }

    for(int i=0, e=arr_size; i<e; i++) {
        std::cout << i << "th element of list: " << list[i] << std::endl;
    }

    delete[] list;

    return 0;
}

int ex04() {
    int a = 3;
    {
        int a = 4;
        std::cout << a << std::endl;
    }

    std::cout << a << std::endl;


    return 0;
}

typedef struct Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal){
    std::cout << "name of animal ?";
    std::cin >> animal->name;

    std::cout << "age of animal ?";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal* animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal* animal) {
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal* animal) {
    std::cout << animal->name << " state is " << std::endl;
    std::cout << "health : " << animal->health << std::endl;
    std::cout << "food   : " << animal->food << std::endl;
    std::cout << "clean  : " << animal->clean << std::endl;
}

int ex05() {
    Animal* list[10];
    int animal_num = 0;

    for(;;) {
        std::cout << "1. add animal" << std::endl;
        std::cout << "2. play" << std::endl;
        std::cout << "3. show state" << std::endl;

        int input;
        std::cin >> input;

        switch(input) {
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "who ? ";
                std::cin >> play_with;
                if (play_with >= animal_num) {
                    break;
                }

                play(list[play_with]);
                break;
            case 3:
                std::cout << "who ? ";
                std::cin >> play_with;
                if (play_with >= animal_num) {
                    break;
                }

                show_stat(list[play_with]);
                break;
        }

        for (int i=0, e=animal_num; i != e; i++) {
            one_day_pass(list[i]);
        }
    }

    for (int i=0, e=animal_num; i != e; i++) {
        delete list[i];
    }

    return 0;
}

int main() {

    //ex01();
    //ex02();
    //ex03();
    //ex04();
    ex05();

    return 0;
}
