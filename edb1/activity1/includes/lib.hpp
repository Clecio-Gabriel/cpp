#ifndef ACT_LIB
#define ACT_LIB

#include <iostream> 
#include <stdexcept>

// ──── Lista Encadeada Simples ─────────────────────────────
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

struct LinkedList {
    Node* head = nullptr;
    int size = 0;
};

// ──── Lista Duplamente Encadeada ──────────────────────────
struct DNode {
    int data;
    int priority; // 0 = normal, 1 = alta
    DNode* prev;
    DNode* next;
    DNode(int d, int p) : data(d), priority(p),
    prev(nullptr), next(nullptr) {}
};

struct DLinkedList {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    int size = 0;
};

// ──── Lista Circular (reusa Node) ────────────────────────
struct CircList {
    Node* tail = nullptr; // tail->next == head
    int size = 0;
};

// [ 1 ] INVERTE()
//===TIME COMPLEXITY: O(n)
//===SPACE COMPLEXITY: O(1)
void inverte(LinkedList& l);

// [ 2 ] ROTACIONA()
//===TIME COMPLEXITY: O(k mod n)
//===SPACE COMPLEXITY: O(1)
void rotaciona(CircList& c, int k);

// [ 3 ] ENQUEUE_PRIORITY()
//===TIME COMPLEXITY: O(1)
//===SPACE COMPLEXITY: O(1)
void enqueue_priority(DLinkedList& l, int data, int priority);

// [ 4 ] MERGE()
//===TIME COMPLEXITY: O(n+m)
//===SPACE COMPLEXITY: O(1)
LinkedList merge(LinkedList& a, LinkedList& b);

// [ 5 ] TEM_CICLO()
//===TIME COMPLEXITY: O(n)
//===SPACE COMPLEXITY: O(1)
bool tem_ciclo(const LinkedList& l);

#endif