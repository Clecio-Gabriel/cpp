#include "lib.hpp"

// [ 1 ] INVERTE()
//===TIME COMPLEXITY: O(n)
//===SPACE COMPLEXITY: O(1)
void inverte(LinkedList& l){
    // CASE: Empty List
    if (l.head==nullptr){
        return;
    }

    Node* ptr;
    

}

// [ 2 ] ROTACIONA()
//===TIME COMPLEXITY: O(k mod n)
//===SPACE COMPLEXITY: O(1)
void rotaciona(CircList& c, int k){
    //CASE: Empty List
    if (c.tail==nullptr){
        return;
    }

    //TO OPTIMIZE
    int rot = k;
    if (k>c.size){
        rot%=c.size;
    }

    for (int i = 0; i <= rot; i++){
        c.tail = c.tail->next;
    }

}

// [ 3 ] ENQUEUE_PRIORITY()
//===TIME COMPLEXITY: O(1)
//===SPACE COMPLEXITY: O(1)
void enqueue_priority(DLinkedList& l, int data, int priority){

}

// [ 4 ] MERGE()
//===TIME COMPLEXITY: O(n+m)
//===SPACE COMPLEXITY: O(1)
LinkedList merge(LinkedList& a, LinkedList& b){
    
    Node dummy(0);
    Node* ptr = &dummy;

    //To update size
    a.size += b.size;

    while (a.head!=nullptr and b.head!=nullptr){
        if (a.head->data < b.head->data){
            ptr->next = a.head;
            a.head = a.head->next;
        }
        else if(b.head->data < a.head->data){
            ptr->next = b.head;
            b.head = b.head->next;
        }
        ptr = ptr->next;
    }

    if (a.head==nullptr){
        ptr->next = b.head;
    }
    else if (b.head==nullptr){
        ptr->next = a.head;
    }

    a.head = dummy.next;

    return a;
}

// [ 5 ] TEM_CICLO()
//===TIME COMPLEXITY: O(n)
//===SPACE COMPLEXITY: O(1)
bool tem_ciclo(const LinkedList& l){
    bool res;

    return res;
}