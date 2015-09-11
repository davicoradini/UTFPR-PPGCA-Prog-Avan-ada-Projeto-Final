#ifndef _LISTA_H_
#define _LISTA_H_

template<class T>
class Lista
{
private:
	class Elemento
	{
	private:
		Elemento *pAnterior;
		Elemento *pProximo;
		T objeto;

	public:
		Elemento() { pAnterior = pProximo = nullptr; }
		~Elemento() {	}

		void setAnterior(Elemento* ele) { 
			pAnterior = ele;
		}
		Elemento* getAnterior() { 
			return pAnterior; 
		}
		void setProximo(Elemento* ele) { 
			pProximo = ele; 
		}
		Elemento* getProximo() { 
			return pProximo; 
		}
		void setValor(T val) { 
			objeto = val; 
		}
		T getValor() { 
			return objeto;
		}
	};

	Elemento *pPrimeiro, *pAtual;

public:
	class Iterator
	{
	private:
		Elemento* pElem;
	public:
		Iterator() {	}
		~Iterator() {	}
		void operator ++(int) { pElem = pElem->getProximo(); }
		void operator --(int) { pElem = pElem->getAnterior(); }
		T operator *() { return pElem->getValor(); }
		void operator =(Elemento* ele) { pElem = ele; }
		bool operator ==(Elemento* ele) { return (pElem == ele); }
		bool operator !=(Elemento* ele) { return !(ele == pElem); }
	};

public:
	Lista() { pPrimeiro = pAtual = nullptr; }
	~Lista() {	/*limpar();*/ }
	void limpar()
	{
		Elemento *aux;
		Elemento *it = pPrimeiro;
		while (it != nullptr)
		{
			aux = it;
			it = it->getProximo();
			delete aux;
		}
		pPrimeiro = pAtual = nullptr;
	}
	void incluir(T objeto)
	{
		Elemento *novo = new Elemento;
		novo->setValor(objeto);
		if (nullptr == pPrimeiro)
		{
			pAtual = pPrimeiro = novo;
		}
		else
		{
			pAtual->setProximo(novo);
			novo->setAnterior(pAtual);
			pAtual = novo;
		}
	}

	int tamanho()
	{
		int tam = 0;
		Elemento *it = pPrimeiro;
		while (it != nullptr)
		{
			tam++;
			it = it->getProximo();
		}
		return tam;
	}

	bool remover(int index)
	{
		int contIndex = 0;

		Elemento *aux;
		Elemento *it = pPrimeiro;
		while (it != nullptr)
		{
			if (contIndex == index)
			{
				if (it == pPrimeiro)
				{
					pPrimeiro = pPrimeiro->getProximo();
				}
				else
				{
					aux = it->getAnterior();

					if (it == pAtual)
					{
						pAtual = aux;
						pAtual->setProximo(nullptr);

						if (pPrimeiro == pAtual)
						{
							pPrimeiro->setProximo(nullptr);
							pPrimeiro->setAnterior(nullptr);
						}
					}

					else aux->setProximo(it->getProximo());
					
				}
				
				delete it;
				return true;
			}
			contIndex++;
			it = it->getProximo();
		}
		return false;
	}

	Elemento* begin()
	{
		return pPrimeiro;
	}
	Elemento* end()
	{
		if(pAtual != nullptr)	return pAtual->getProximo();
		else					return nullptr;
	}
	Elemento* rBegin()
	{
		return pAtual; 
}
	Elemento* rEnd()
	{
		return pPrimeiro->getAnterior();
	}
};

#endif