#pragma once
#include <stdexcept>
#include <iostream>

template <typename T> 
class ListaSequencial
{
private:
    T   *m_dados;
    int m_tamanhoAtual;
    int m_tamanhoMax;

public:
    ListaSequencial()
    {
        m_tamanhoMax = 100;
        m_dados = new T[m_tamanhoMax];
        m_tamanhoAtual = 0;
    };
    
    ListaSequencial(int tamanho)
    {
        m_tamanhoMax = tamanho;
        m_dados = new T[m_tamanhoMax];
        m_tamanhoAtual = 0;
    };
    
    ~ListaSequencial()
    {
        if (m_dados != nullptr)
        {
            delete [] m_dados;
        }
    };
    
    bool isVazia()
    {
        return m_tamanhoAtual == 0;
    };
    
    bool isCheia()
    {
        return m_tamanhoAtual == m_tamanhoMax;
    };
    
    int getTamanho()
    {
        return m_tamanhoAtual;
    };
    
    T getElemento(int pos)
    {
        if(pos < 1 || pos > m_tamanhoAtual)
        {
            throw std::invalid_argument("Argumento pos invalido para getElemento");
        }
        return m_dados[pos-1];
    };
    
    void setElemento(T dado,int pos)
    {
        if(pos < 1 || pos > m_tamanhoAtual)
        {
            throw std::invalid_argument("Argumento pos invalido para setElemento");
        }
        m_dados[pos-1] = dado;
    };
    
    int getPosicao(T dado)
    {
        for (int i = 0; i < m_tamanhoMax; ++i)
        {
            if (m_dados[i] == dado)
            {
                return i+1;
            }
        }
        return -1;
    };
    
    bool inserir(T dado, int pos)
    {
        if (isCheia() || pos < 1 || pos > (m_tamanhoAtual+1))
        {
            return false;
        }

        for (int i = m_tamanhoAtual; i >= pos; --i)
        {
            m_dados[i] = m_dados[i-1];
        }
        m_dados[pos-1] = dado;
        m_tamanhoAtual++;

        return true;
    };

    T remover(int pos)
    {
        if (pos < 1 || pos > m_tamanhoAtual)
        {
            throw std::invalid_argument("Argumento pos invalido para remover");
        }
        T dado = m_dados[pos-1];
        for (int i = pos-1; i < m_tamanhoAtual-1; ++i)
        {
            m_dados[i] = m_dados[i+1];
        }
        m_tamanhoAtual--;
        return dado;
    };
    
    void print()
    {
        std::cout << "Lista: [ ";
        for (int i = 0; i < m_tamanhoAtual; ++i)
        {
            std::cout << m_dados[i] << " ";
        }
        std::cout << "]\n";
    };
};