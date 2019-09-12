//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
#include <iostream>
#include "Node.h"

template <typename N>
class Polynomial {
private:
    Node<N>* head1;
    Node<N>* tail1;

    Node<N>* head2;
    Node<N>* tail2;

    Node<N>* head;
    Node<N>* tail;

    Node<N>* aux;

public:
        Polynomial(){
            head1 = nullptr;
            tail1 = nullptr;
            head2 = nullptr;
            tail2 = nullptr;
            head = nullptr;
            tail = nullptr;
            aux = nullptr;
        }

        void push_back_1(N value){
            Node<N>* newNode = new Node(value);
            if (head1 == nullptr){
                head1 = newNode;
                newNode->setNext(tail1);
            }
            else if (is_merged()==true){
                push_back_Lista_Unida(value);
            }
            else {
                tail1 = head1;
                while(tail1 != nullptr){
                    aux = tail1;
                    tail1 = tail1->getNext();
                }
                aux->setNext(newNode);
                newNode->setNext(tail1);
            }
        }

        void push_back_2(N value){
            Node<N>* newNode = new Node(value);
            if (head2 == nullptr){
                head2 = newNode;
                newNode->setNext(tail2);
            }
            else if (is_merged()==true){
                push_back_Lista_Unida(value);
            }
            else {
                tail2 = head2;
                while(tail2 != nullptr){
                    aux = tail2;
                    tail2 = tail2->getNext();
                }
                aux->setNext(newNode);
                newNode->setNext(tail2);
            }
        }

        void push_back_Lista_Unida(N value){
            Node<N>* newNode = new Node(value);
            if (head == nullptr){
                std::cout << "Las listas 1 y 2 no estan unidas\n";
            }
            else {
                tail = head;
                while(tail != nullptr){
                    aux = tail;
                    tail = tail->getNext();
                }
                aux->setNext(newNode);
                newNode->setNext(tail);
            }
        }

        void merge(N value){
            Node<N>* newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
            }
            else {
                std::cout << "Operacion duplicada\n";
            }
        }

        bool is_merged(){
            if (head == nullptr)
                return false;
            else
                return true;
        }

        void getList(){
            int var;
            std::cout << "Ingrese lista que desee imprimir:\n";
            std::cout << "\t[0] Nodo compartido\n";
            std::cout << "\t[1] Exponentes\n";
            std::cout << "\t[2] Coeficientes\n";
            std::cin >> var;

            if (var == 0){
                std::cout << "Nodo compartido:\n";
                Print(head);
            }
            else if (var == 1) {
                std::cout << "Primera lista:\n";
                Print(head1);
            }
            else if (var == 2) {
                std::cout << "Segunda lista:\n";
                Print(head2);
            }
            else
                std::cout << "No existe la lista\n";
        }

        void Print(Node<N>* head){
            aux = head;
            while (aux != nullptr) {
                std::cout << aux->getValue() << std::endl;
                aux = aux->getNext();
            }
        }

        void search(N value){
            int contador1 = 0, contador2 = 0, contador_unido = 0;
            tail1 = head1;
            tail2 = head2;
            tail = head;
            while (tail1 != nullptr and tail1->getValue() != value) {
                tail1 = tail1->getNext();
                contador1++;
            }

            while (tail2 != nullptr and tail2->getValue() != value) {
                tail2 = tail2->getNext();
                contador2++;
            }

            while (tail != nullptr and tail->getValue() != value) {
                tail = tail->getNext();
                contador_unido++;
            }

            if(contador1 < contador2)
                if(contador1 < contador_unido){
                    std::cout << "Su valor se encuentra en la lista 1: \n";
                    Print(head1);
                }
                else {
                    std::cout << "Su valor se encuentra en el nodo compartido: \n";
                    Print(head);
                }
            else
            if(contador2 < contador_unido) {
                std::cout << "Su valor se encuentra en la lista 2: \n";
                Print(head2);
            }
            else {
                std::cout << "Su valor se encuentra en el nodo compartido: \n";
                Print(head);
            }

        }

        virtual ~Polynomial() {
            delete head1;
            delete tail1;
            delete head2;
            delete tail2;
            delete head;
            delete tail;
            delete aux;
        }


};

#endif //POLINOMIO_POLINOMIO_H
