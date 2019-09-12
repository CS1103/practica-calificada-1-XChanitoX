#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <string>
#include "Polynomial.h"
#include "Node.h"

using namespace std;

int main() {
    unsigned int x;
    int y = 0;
    cout << "De que grado quiere ingresar el polinomio?" << endl;
    cin>> x;
    Polynomial<int>* linked_list = new Polynomial<int>;

    do{
        double a;
        cout <<"Ingrese el coeficiete: "<< endl;
        cin >> a;
        linked_list->push_back_1(a);
        y++;
    }while(y<=x);

    linked_list->push_back_2(13);
    linked_list->push_back_2(12);
    linked_list->push_back_2(45);
    linked_list->push_back_2(34);
    linked_list->push_back_2(15);

    linked_list->getList();
    linked_list->getList();

    linked_list->merge(81);
    linked_list->getList();
    linked_list->push_back_2(15);
    linked_list->push_back_1(12);
    linked_list->getList();

    linked_list->search(2);

    delete linked_list;
    return 0;
}
