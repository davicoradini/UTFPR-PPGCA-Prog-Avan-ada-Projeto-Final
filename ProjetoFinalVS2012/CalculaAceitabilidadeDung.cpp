#include "CalculaAceitabilidadeDung.h"

CalculaAceitabilidadeDung::CalculaAceitabilidadeDung(ListaArgumentos* lar, ListaAtaques* lat)
{
	listaArgumentos  = lar;
	listaAtaques	 = lat;

	setsConflictFree			= new list<ListaArgsDung*>;
	setsConflictFreeAdmissible	= new list<ListaArgsDung*>;
	

	//setsAdmissible	 = new list<ListaArgsDung*>;
	//setsMinimal		 = new list<ListaArgsDung*>;
	//setsMaximal		 = new list<ListaArgsDung*>;
	
	//extComplete					= new list<ListaArgsDung*>;
	//extGrounded		 = new list<ListaArgsDung*>;
	extPrefered		 = new list<ListaArgsDung*>;
	//extStable		 = new list<ListaArgsDung*>;
}

/*CalculaAceitabilidadeDung::CalculaAceitabilidadeDung()
{
}*/

CalculaAceitabilidadeDung::~CalculaAceitabilidadeDung()
{
}


/*void CalculaAceitabilidadeDung::addArgumento(Argumento* a)
{
	setsConflictFree->clear();
}
void CalculaAceitabilidadeDung::addAtaque(Ataque* a)
{

}
void CalculaAceitabilidadeDung::removeArgumento(Argumento* a)
{

}
void CalculaAceitabilidadeDung::removeAtaque(Ataque* a)
{

}*/

void CalculaAceitabilidadeDung::atualizaTodos()
{
	criarInicialConflictFreeSets();
	criarDemaisConflictFreeSets();
	criarConflictFreeAdmissible();
	criarPreferedExtension();
}

list<ListaArgsDung*>* CalculaAceitabilidadeDung::getSetsConflictFree()
{
	return setsConflictFree;
}
list<ListaArgsDung*>* CalculaAceitabilidadeDung::getSetsConflictFreeAdmissible()
{
	return setsConflictFreeAdmissible;
}

void CalculaAceitabilidadeDung::criarInicialConflictFreeSets()
{
	setsConflictFree->clear();
	setsConflictFreeAdmissible->clear();
	extPrefered->clear();

	ListaArgsDung *listaCF;// = new ListaArgsDung();

	//setsConflictFree->push_back(listaCF); //conjunto vazio é um conjunto livre de conflitos

	Argumento* argumento;
	Lista<Persistivel*> *lista = listaArgumentos->getLista(); //todos os argumentos do framework
	Lista<Persistivel*>::Iterator it;
	it = lista->begin();

	while (it != lista->end())
	{
		argumento = static_cast<Argumento*>(*it);

		listaCF = new ListaArgsDung(); //cada elemento sozinho já é um conjunto
		listaCF->incluir(argumento);
		setsConflictFree->push_back(listaCF);

		it++;
	}
}
void CalculaAceitabilidadeDung::criarDemaisConflictFreeSets()
{
	ListaArgsDung *listaCF;
	
	//varre cada lista CF existente (inicialmente cada lista possui apenas um argumento que não ataca a si próprio)
	for (list<ListaArgsDung*>::iterator itListaArgs = setsConflictFree->begin(); itListaArgs != setsConflictFree->end(); itListaArgs++)
	{
		Lista<Persistivel*> *listaArgs = listaArgumentos->getLista(); //todos os argumentos do framework
		Lista<Persistivel*>::Iterator itArgs;
		itArgs = listaArgs->begin();

		bool passouArgIgual = false;

		while (itArgs != listaArgs->end())
		{
			Argumento* argumento = static_cast<Argumento*>(*itArgs);
			
			listaCF = new ListaArgsDung();
			listaCF->copiarArgsLista(*itListaArgs);

			if (passouArgIgual)
			{
				listaCF->incluir(argumento);
				if (!existeAtaqueEmConjunto(listaCF, 0))
				{
					setsConflictFree->push_back(listaCF);
				}
				else delete listaCF;
			}
			else
			{
				Argumento* ultimo = listaCF->getUltimoArgumento();
				if (ultimo == argumento) passouArgIgual = true;
				delete listaCF;
			}
			itArgs++;
		}
	}
}
void CalculaAceitabilidadeDung::criarConflictFreeAdmissible()
{
	//varre cada lista CF admissíveis existente
	for (list<ListaArgsDung*>::iterator itListaArgs = setsConflictFree->begin(); itListaArgs != setsConflictFree->end(); itListaArgs++)
	{
		//verifica se CF é admissível e insere na lista
		if (conjEhAdmissivel(*itListaArgs))
		{
			setsConflictFreeAdmissible->push_back(*itListaArgs);
		}
	}
}
void CalculaAceitabilidadeDung::criarPreferedExtension()
{
	//varre cada lista CF admissíveis existente
	for (list<ListaArgsDung*>::iterator itListaArgs = setsConflictFreeAdmissible->begin(); itListaArgs != setsConflictFreeAdmissible->end(); itListaArgs++)
	{
		//verifica se CF é preferida e insere na lista
		if (conjAdmissivelEhPreferido(*itListaArgs))
		{
			extPrefered->push_back(*itListaArgs);
		}
	}
}
bool CalculaAceitabilidadeDung::existeAtaqueEmConjunto(ListaArgsDung* conjunto, int indexParaVerificar)
{
	for (vector<Argumento*>::iterator it = conjunto->getLista()->begin(); it != conjunto->getLista()->end(); it++)
	{
		Argumento* arg = *it;
		if (listaAtaques->ataqueExiste(arg, conjunto->getLista()->at(indexParaVerificar))) return true; // || arg == ehAtacado
	}

	if (++indexParaVerificar < (int)conjunto->getLista()->size()) return existeAtaqueEmConjunto(conjunto, indexParaVerificar);
	
	else return false;
}
bool CalculaAceitabilidadeDung::argAceitavelComRespeitoConjunto(ListaArgsDung* conjunto, Argumento* argumento)
{
	ListaArgsDung* atacantes = atacantesDoArgumento(argumento);
	bool ehAceitavel = true;

	for (vector<Argumento*>::iterator it = atacantes->getLista()->begin(); it != atacantes->getLista()->end(); it++)
	{
		Argumento* arg = *it;
		if (!argEhAtacadoPorConjunto(conjunto, arg)) ehAceitavel = false;
	}
	
	return ehAceitavel;
}
bool CalculaAceitabilidadeDung::argEhAtacadoPorConjunto(ListaArgsDung* conjunto, Argumento* ehAtacado)
{
	for (vector<Argumento*>::iterator it = conjunto->getLista()->begin(); it != conjunto->getLista()->end(); it++)
	{
		Argumento* arg = *it;
		if (listaAtaques->ataqueExiste(arg, ehAtacado) || arg == ehAtacado) return true;
	}
	return false;
}
ListaArgsDung* CalculaAceitabilidadeDung::atacantesDoArgumento(Argumento* argumento)
{
	ListaArgsDung* listaAtacantes = new ListaArgsDung();

	Lista<Persistivel*> *listaAtt = listaAtaques->getLista(); //todos os argumentos do framework
	Lista<Persistivel*>::Iterator itAtt;
	itAtt = listaAtt->begin();

	while (itAtt != listaAtt->end())
	{
		Ataque* ataque = static_cast<Ataque*>(*itAtt);
		if (ataque->getPDestino() == argumento) listaAtacantes->incluir(ataque->getPOrigem());

		itAtt++;
	}

	return listaAtacantes;
}
bool CalculaAceitabilidadeDung::conjEhAdmissivel(ListaArgsDung* conjunto)
{
	for (vector<Argumento*>::iterator it = conjunto->getLista()->begin(); it != conjunto->getLista()->end(); it++)
	{
		Argumento* arg = *it;
		if (!argAceitavelComRespeitoConjunto(conjunto, arg)) return false;
	}
	return true;
}

bool CalculaAceitabilidadeDung::conjAdmissivelEhPreferido(ListaArgsDung* conjunto)
{
	return conjEhMaximo(conjunto);
}

bool CalculaAceitabilidadeDung::conjEhMinimo(ListaArgsDung* conjunto)
{
	/*for (vector<Argumento*>::iterator it = conjunto->getLista()->begin(); it != conjunto->getLista()->end(); it++)
	{
		Argumento* arg = *it;

	}*/
	return false;
}
bool CalculaAceitabilidadeDung::conjEhMaximo(ListaArgsDung* conjunto)
{
	//varre cada lista CF existente
	for (list<ListaArgsDung*>::iterator itListaArgs = setsConflictFree->begin(); itListaArgs != setsConflictFree->end(); itListaArgs++)
	{
		if (conjunto != *itListaArgs)
		{
			if (conjuntoEstaContidoEmOutro(conjunto, *itListaArgs, 0)) return false;
		}
	}

	return true;
}
bool CalculaAceitabilidadeDung::conjuntoEstaContidoEmOutro(ListaArgsDung* conjunto, ListaArgsDung* conjQueContemOutro, int indexParaVerificar)
{
	if (conjQueContemOutro->isThere(conjunto->getLista()->at(indexParaVerificar)))
	{
		if (++indexParaVerificar >= (int)conjunto->getLista()->size()) return true;

		return conjuntoEstaContidoEmOutro(conjunto, conjQueContemOutro, indexParaVerificar);
	}
	else return false;
}
/*void CalculaAceitabilidadeDung::updateIndividualConflictFreeSets()
{
}*/
/*bool CalculaAceitabilidadeDung::existConflictFreeSetWithThisArg(Argumento* a)
{
	list<ListaArgsDung*>::iterator it;
	it = setsConflictFree->begin();

	while (it != setsConflictFree->end())
	{
		ListaArgsDung *listaArgsDung = *it;

		if (listaArgsDung->isThere(a)) return true;

		it++;
	}

	return false;
}*
/*void CalculaAceitabilidadeDung::updateAcceptedArgs()
{

}*/
/*void CalculaAceitabilidadeDung::updateMinimalSets()
{

}
void CalculaAceitabilidadeDung::updateMaximalSets()
{

}*/
/*
ListaArgumentos		CalculaAceitabilidadeDung::getAcceptedArgs()
{

}
list<ListaArgumentos>	CalculaAceitabilidadeDung::getAdmissibleSets()
{

}*/
/*list<ListaArgumentos>	CalculaAceitabilidadeDung::getCompleteExtensions()
{

}
list<ListaArgumentos>	CalculaAceitabilidadeDung::getGroundedExtensions()
{

}*/
list<ListaArgsDung*>*	CalculaAceitabilidadeDung::getPreferedExtensions()
{
	return extPrefered;
}
/*list<ListaArgumentos>	CalculaAceitabilidadeDung::getStableExtensions()
{

}
*/