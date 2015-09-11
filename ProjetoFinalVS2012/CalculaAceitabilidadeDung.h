#ifndef _CALCULAACEITABILIDADEDEDUNG_H_
#define _CALCULAACEITABILIDADEDEDUNG_H_

#pragma once
#include <list>
#include "ListaArgsDung.h"
#include "ListaArgumentos.h"
#include "ListaAtaques.h"

using namespace std;

class CalculaAceitabilidadeDung
{
private:
	ListaArgumentos*	listaArgumentos;
	ListaAtaques*		listaAtaques;

	//ListaArgsDung		argsAcceptable;
	list<ListaArgsDung*>	*setsConflictFree; //criado por criarInicialConflictFreeSets() e criarDemaisConflictFreeSets()
	list<ListaArgsDung*>	*setsConflictFreeAdmissible; //criado por criarInicialConflictFreeSets() e criarDemaisConflictFreeSets()
	

	//list<ListaArgsDung*>	*setsAdmissible;
	//list<ListaArgsDung*>	*setsMinimal;
	//list<ListaArgsDung*>	*setsMaximal;
	
	//list<ListaArgsDung*>	*extComplete;
	//list<ListaArgsDung*>	*extGrounded;
	list<ListaArgsDung*>	*extPrefered;
	//list<ListaArgsDung*>	*extStable;
	
	//void updateAcceptedArgs();
	//void updateConflictFreeSets();
	//void updateMinimalSets();
	//void updateMaximalSets();
	//void updateIndividualConflictFrseSets();

	void criarInicialConflictFreeSets(); //utilizado por atualizaTodos()
	void criarDemaisConflictFreeSets(); //utilizado por atualizaTodos()
	void criarConflictFreeAdmissible(); //utilizado por atualizaTodos()
	void criarPreferedExtension(); //utilizado por atualizaTodos()
	
	bool existeAtaqueEmConjunto(ListaArgsDung* cfSets, int indexParaVerificar);
	bool argEhAtacadoPorConjunto(ListaArgsDung* cfSets, Argumento* argumento);
	bool argAceitavelComRespeitoConjunto(ListaArgsDung* conjunto, Argumento* argumento);
	bool conjEhAdmissivel(ListaArgsDung* conjunto);
	bool conjAdmissivelEhPreferido(ListaArgsDung* conjunto);
	bool conjuntoEstaContidoEmOutro(ListaArgsDung* conjunto, ListaArgsDung* conjQueContemOutro, int indexParaVerificar);
	bool conjEhMinimo(ListaArgsDung* conjunto);
	bool conjEhMaximo(ListaArgsDung* conjunto);

	ListaArgsDung* atacantesDoArgumento(Argumento* argumento);
	//bool existConflictFreeSetWithThisArg(Argumento* a);

public:
	CalculaAceitabilidadeDung(ListaArgumentos* lar, ListaAtaques* lat);
	//CalculaAceitabilidadeDung();
	~CalculaAceitabilidadeDung();

	/*void addArgumento(Argumento* a);
	void addAtaque(Ataque* a);
	void removeArgumento(Argumento* a);
	void removeAtaque(Ataque* a);*/

	//ListaArgumentos			getAcceptedArgs();
	//list<ListaArgumentos>	getAdmissibleSets();
	void atualizaTodos();
	list<ListaArgsDung*>	*getSetsConflictFree();
	list<ListaArgsDung*>	*getSetsConflictFreeAdmissible();
	//list<ListaArgumentos>	getCompleteExtensions();
	//list<ListaArgumentos>	getGroundedExtensions();
	list<ListaArgsDung*>	*getPreferedExtensions();
	//list<ListaArgumentos>	getStableExtensions();

};
#endif