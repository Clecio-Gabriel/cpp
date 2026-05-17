#include "lib.hpp"

void limpar_lista_simples(LinkedList& l) {
    Node* curr = l.head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    l.head = nullptr;
    l.size = 0;
}

void limpar_lista_dupla(DLinkedList& l) {
    DNode* curr = l.head;
    while (curr != nullptr) {
        DNode* next = curr->next;
        delete curr;
        curr = next;
    }
    l.head = nullptr;
    l.tail = nullptr;
    l.size = 0;
}

void limpar_lista_circular(CircList& c) {
    if (c.tail == nullptr) return;
    
    // Quebra temporariamente o ciclo para permitir a desalocação linear segura
    Node* head = c.tail->next;
    c.tail->next = nullptr; 
    
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    c.tail = nullptr;
    c.size = 0;
}