#include <iostream>

int main() {
    /*
    int i;
    char c;
    double d;
    float f;
    */

    // snake case
    int number_of_people;
    double interest_rate;

    // pascal case
    int NumberOfPeople;

    int arr[10];
    int *parr = arr;

    int i, sum = 0;
    int *pi = &i;

    for (i=0; i<10; i++) {
        std::cout << i << std::endl;
    }


    for (i=0;i<=10;i++) {
        sum += i;
    }

    std::cout << "sum is : " << i << endl;

    return 0;
}
