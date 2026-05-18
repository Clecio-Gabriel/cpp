#include "lib.hpp"

#define YES 1
#define NO 0

//MUDE ALGUM CASO PARA "YES" PARA TESTAR ALGUM CASO ESPECÍFICO
#define INVERTE NO
#define ROTACIONA YES
#define ENQUEUE_PRIORITY YES
#define MERGE YES
#define TEM_CICLO YES

int main(){

#if INVERTE
    std::cout << "TESTANDO [inverte()]...\n";
    
    // ---- 1. CASO NORMAL ----
    std::cout << "-> TIPO: Caso Normal (Lista com multiplos elementos)\n";
    LinkedList l1;
    l1.head = new Node(1);
    l1.head->next = new Node(2);
    l1.head->next->next = new Node(3);
    l1.head->next->next->next = new Node(4);
    l1.size = 4;

    inverte(l1);
    std::cout << "Invertida (Esperado: 4 -> 3 -> 2 -> 1): ";
    for (Node* curr = l1.head; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << (curr->next ? " -> " : " -> nullptr\n");
    }
    limpar_lista_simples(l1); // Evita leak do caso normal

    // ---- 2. CASO DE BORDA: LISTA VAZIA ----
    std::cout << "-> TIPO: Caso de Borda (Lista Vazia)\n";
    LinkedList l_vazia; // head = nullptr, size = 0
    inverte(l_vazia);
    std::cout << "Invertida (Esperado: nullptr): " << (l_vazia.head == nullptr ? "nullptr\n" : "ERRO (nao e nulo)\n");

    // ---- 3. CASO DE BORDA: APENAS UM ELEMENTO ----
    std::cout << "-> TIPO: Caso de Borda (Lista com apenas 1 elemento)\n";
    LinkedList l_unica;
    l_unica.head = new Node(99);
    l_unica.size = 1;
    inverte(l_unica);
    std::cout << "Invertida (Esperado: 99 -> nullptr): ";
    if (l_unica.head) std::cout << l_unica.head->data << " -> nullptr\n";
    else std::cout << "nullptr\n";
    limpar_lista_simples(l_unica); // Evita leak

    std::cout << "--------------------------------------------------------\n\n";
    #endif


    #if ROTACIONA
    std::cout << "TESTANDO [rotaciona()]...\n";
    
    // ---- 1. CASO NORMAL ----
    std::cout << "-> TIPO: Caso Normal (Rotacionar k < n posicoes à direita)\n";
    CircList c1;
    Node* n1 = new Node(1); Node* n2 = new Node(2); Node* n3 = new Node(3); 
    Node* n4 = new Node(4); Node* n5 = new Node(5);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n1;
    c1.tail = n5; c1.size = 5;

    rotaciona(c1, 2); // Rotacionar 2 posições
    std::cout << "Rotacionada k=2 (Esperado Head: 4): ";
    Node* currC = c1.tail->next;
    for (int i = 0; i < c1.size; ++i) { std::cout << currC->data << " "; currC = currC->next; }
    std::cout << "\n";
    limpar_lista_circular(c1);

    // ---- 2. CASO DE BORDA: LISTA VAZIA ----
    std::cout << "\n-> TIPO: Caso de Borda (Lista Circular Vazia)\n";
    CircList c_vazia;
    rotaciona(c_vazia, 3); // Não deve quebrar/dar SegFault
    std::cout << "Resultado (Esperado: executado sem falhas de segmentacao)\n";

    // ---- 3. CASO DE BORDA: K MAIOR QUE O TAMANHO (Otimização k mod n) ----
    std::cout << "\n-> TIPO: Caso de Borda (k maior que o tamanho da lista)\n";
    CircList c2;
    Node* x1 = new Node(10); Node* x2 = new Node(20); Node* x3 = new Node(30);
    x1->next = x2; x2->next = x3; x3->next = x1;
    c2.tail = x3; c2.size = 3;
    
    rotaciona(c2, 7); // 7 mod 3 = 1 rotação efetiva. Novo tail deve ser o 20, Head deve ser 30.
    std::cout << "Rotacionada k=7 em tam=3 (Esperado Head: 30): ";
    currC = c2.tail->next;
    for (int i = 0; i < c2.size; ++i) { std::cout << currC->data << " "; currC = currC->next; }
    std::cout << "\n--------------------------------------------------------\n\n";
    limpar_lista_circular(c2);
    #endif


    #if ENQUEUE_PRIORITY
    std::cout << "TESTANDO [enqueue_priority()]...\n";
    
    // ---- 1. CASO NORMAL ----
    std::cout << "-> TIPO: Caso Normal (Insercao intercalada de prioridades)\n";
    DLinkedList dl;
    enqueue_priority(dl, 10, 0); // Normal (A)
    enqueue_priority(dl, 20, 0); // Normal (B)
    enqueue_priority(dl, 30, 1); // Alta (C) -> vai para a frente
    enqueue_priority(dl, 40, 0); // Normal (D)
    enqueue_priority(dl, 50, 1); // Alta (E) -> vai para trás de C, mas frente dos normais

    std::cout << "Fila Resultante (Esperada Ordem: 30, 50, 10, 20, 40):\n";
    for (DNode* curr = dl.head; curr != nullptr; curr = curr->next) {
        std::cout << " -> Item: " << curr->data << " [P:" << curr->priority << "]\n";
    }
    limpar_lista_dupla(dl);

    // ---- 2. CASO DE BORDA: INSERÇÃO EM LISTA VAZIA ----
    std::cout << "\n-> TIPO: Caso de Borda (Insercao em Fila Vazia)\n";
    DLinkedList dl_vazia;
    enqueue_priority(dl_vazia, 99, 1); // Insere alta prioridade em fila vazia
    std::cout << "Fila (Esperado: Head e Tail apontando para 99): ";
    if(dl_vazia.head && dl_vazia.tail && dl_vazia.head == dl_vazia.tail) {
        std::cout << "OK (" << dl_vazia.head->data << ")\n";
    } else {
        std::cout << "ERRO de encadeamento\n";
    }
    limpar_lista_dupla(dl_vazia);

    std::cout << "--------------------------------------------------------\n\n";
    #endif


    #if MERGE
    std::cout << "TESTANDO [merge()]...\n";
    
    // ---- 1. CASO NORMAL ----
    std::cout << "-> TIPO: Caso Normal (Duas listas populadas e ordenadas)\n";
    LinkedList m1, m2;
    m1.head = new Node(1); m1.head->next = new Node(3); m1.head->next->next = new Node(5); m1.size = 3;
    m2.head = new Node(2); m2.head->next = new Node(4); m2.size = 2;

    LinkedList mesclada = merge(m1, m2);
    std::cout << "Mesclada (Esperado: 1 -> 2 -> 3 -> 4 -> 5): ";
    for (Node* curr = mesclada.head; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << (curr->next ? " -> " : " -> nullptr\n");
    }
    // IMPORTANTE: Como a função faz merge in-place reaproveitando nós, 'mesclada' agora detém 
    // a propriedade de todos os nós criados acima. Limpar 'mesclada' limpa tudo com segurança.
    limpar_lista_simples(mesclada); 

    // ---- 2. CASO DE BORDA: UMA DAS LISTAS VAZIA ----
    std::cout << "\n-> TIPO: Caso de Borda (Uma das listas está vazia)\n";
    LinkedList m_vazia, m_cheia;
    m_cheia.head = new Node(10); m_cheia.head->next = new Node(20); m_cheia.size = 2;

    LinkedList mesclada_vazia = merge(m_vazia, m_cheia);
    std::cout << "Mesclada (Esperado: 10 -> 20): ";
    for (Node* curr = mesclada_vazia.head; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << (curr->next ? " -> " : " -> nullptr\n");
    }
    limpar_lista_simples(mesclada_vazia);

    std::cout << "--------------------------------------------------------\n\n";
    #endif


    #if TEM_CICLO
    std::cout << "TESTANDO [tem_ciclo()]...\n";
    
    // ---- 1. CASO NORMAL: SEM CICLO ----
    std::cout << "-> TIPO: Caso Normal (Lista Linear sem Ciclo)\n";
    LinkedList cyList;
    cyList.head = new Node(3);
    cyList.head->next = new Node(2);
    cyList.head->next->next = new Node(0);
    Node* cy4 = new Node(-4);
    cyList.head->next->next->next = cy4;
    cyList.size = 4;

    std::cout << "Resultado (Esperado: 0 - Falso): " << tem_ciclo(cyList) << "\n";
    limpar_lista_simples(cyList);

    // ---- 2. CASO NORMAL: COM CICLO ----
    std::cout << "\n-> TIPO: Caso Normal (Lista com Ciclo de Floyd)\n";
    LinkedList cyList2;
    cyList2.head = new Node(3);
    Node* cy_target = new Node(2); // Nó onde o ciclo vai apontar
    cyList2.head->next = cy_target;
    cyList2.head->next->next = new Node(0);
    Node* cy_last = new Node(-4);
    cyList2.head->next->next->next = cy_last;
    
    // Forçando o ciclo intencionalmente: o último aponta para o segundo
    cy_last->next = cy_target; 

    std::cout << "Resultado (Esperado: 1 - Verdadeiro): " << tem_ciclo(cyList2) << "\n";
    
    // AVISO DE SEGURANÇA: Para evitar loop infinito na desalocação da memória, 
    // precisamos quebrar o ciclo manualmente antes de limpar a lista!
    cy_last->next = nullptr; 
    limpar_lista_simples(cyList2);

    // ---- 3. CASO DE BORDA: LISTA VAZIA ----
    std::cout << "\n-> TIPO: Caso de Borda (Lista Vazia para verificacao de ciclo)\n";
    LinkedList cy_vazia;
    std::cout << "Resultado (Esperado: 0 - Falso): " << tem_ciclo(cy_vazia) << "\n";

    std::cout << "--------------------------------------------------------\n\n";
    #endif

    return EXIT_SUCCESS;
}