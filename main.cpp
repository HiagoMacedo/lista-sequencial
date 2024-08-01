#include <iostream>
#include <stdexcept>
#include "ListaSequencial.hpp"

int main()
{
    int tamanhoMax = 20;
    ListaSequencial<int> lista(tamanhoMax);
    
    std::cout << "Lista esta vazia: " << lista.isVazia() << "\n";
    std::cout << "Lista esta cheia: " << lista.isCheia() << "\n";
    std::cout << "Tamanho da lista: " << lista.getTamanho() << "\n";

    lista.print();

    lista.inserir(10, 1);
    lista.inserir(30, 2);
    lista.inserir(50, 3);
    lista.inserir(40, 4);
    lista.inserir(20, 5);

    lista.print();

    std::cout << "Posicao de 50: " << lista.getPosicao(50) << "\n";
    
    std::cout << "Removido posicao 2: " << lista.remover(2) << "\n";

    lista.print();

    std::cout << "Elemento da posicao 4: " << lista.getElemento(4) << "\n";
    
    std::cout << "Tamanho da lista: " << lista.getTamanho() << "\n";

    std::cout << "Preenchendo toda a lista...\n";
    for (int pos = 5; pos <= tamanhoMax; ++pos)
    {
        lista.inserir(pos*10, pos);
    }

    lista.print();
    
    std::cout << "Lista esta vazia: " << lista.isVazia() << "\n";
    std::cout << "Lista esta cheia: " << lista.isCheia() << "\n";

    std::cout << "Tamanho da lista: " << lista.getTamanho() << "\n";

    try 
    {
        std::cout << "Tentando remover da pos 0: \n";
        lista.remover(0);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
