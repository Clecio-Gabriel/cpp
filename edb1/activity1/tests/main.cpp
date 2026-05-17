#include "lib.hpp"

#define YES 1
#define NO 0

//MUDE ALGUM CASO PARA "YES" PARA TESTAR ALGUM CASO ESPECÍFICO
#define INVERTE NO
#define ROTACIONA NO
#define ENQUEUE_PRIORITY NO
#define MERGE NO
#define TEM_CICLO NO

int main(){

    #if INVERTE
    std::cout << "TESTANDO [inverte()]...\n";
    #endif

    #if ROTACIONA
    std::cout << "TESTANDO [rotaciona()]...\n";
    #endif

    #if ENQUEUE_PRIORITY
    std::cout << "TESTANDO [enqueue_priority()]...\n";
    #endif

    #if MERGE
    std::cout << "TESTANDO [merge()]...\n";
    #endif

    #if TEM_CICLO
    std::cout << "TESTANDO [tem_ciclo()]...\n";
    #endif

    return EXIT_SUCCESS;
}