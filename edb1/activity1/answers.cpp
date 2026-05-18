#include "lib.hpp"

// [ 1 ] INVERTE()
//===TIME COMPLEXITY: O(n)
//===SPACE COMPLEXITY: O(1)
void inverte(LinkedList& l){
    // CASE: Empty List or with only one element
    if (l.head==nullptr or l.head->next==nullptr){
        return;
    }
    
    Node* prev {nullptr};
    Node* curr {l.head};
    Node* next {l.head->next};

    while (curr!=nullptr){
        curr->next = prev;
        prev = curr;

        curr = next;

        if (next==nullptr) break;
        next = next->next;
    }

    l.head = prev;

}

// [ 2 ] ROTACIONA()
//===TIME COMPLEXITY: O(k mod n)
//===SPACE COMPLEXITY: O(1)
void rotaciona(CircList& c, int k){
    // CASE: Empty List
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
    DNode* temp = new DNode (data, priority);
    l.size++;
    
    // CASE: Empty List
    if (l.head == nullptr){
        l.head = temp;
        l.tail = temp;

        if (priority == 1){
            l.priority_tail = temp;
        }

        return;
    }

    if (priority==0){
        temp->prev = l.tail;

        l.tail->next = temp;
        l.tail = temp;
    }
    else if(priority==1){

        if (l.priority_tail==nullptr){
            temp->next = l.head;
            
            l.head->prev = temp;

            l.head = temp;
            l.priority_tail = temp;
        }
        else{
            temp->prev = l.priority_tail;

            // ⇒ (l.priority_tail==l.tail)
            if (l.priority_tail->next == nullptr){
                l.tail = temp;
            }

            else{
                l.priority_tail->next->prev = temp;
                temp->next = l.priority_tail->next;
            }

            l.priority_tail->next = temp;
            l.priority_tail = temp;
        }

    }
    else{
        throw std::invalid_argument("[enqueue_priority()]: invalid priority argument.");
    }
    
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
        else{
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

    //  if empty list or list with only one element that doesn't cycle
    if (l.head==nullptr or l.head->next==nullptr){
        return false;
    }

    auto slow {l.head};
    auto fast {l.head};

    while (fast != nullptr and fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;

        if (fast==slow){
            return true;
        }
    }
    
    return false;

}