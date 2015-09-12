#ifndef _MODERADOR_H_
#define _MODERADOR_H_

#pragma once
#include "stdafx.h"

#include "Persistivel.h"
#include "Pessoa.h"

class Moderador : public Pessoa
{
private:
	string teste;
public:
	Moderador();
	~Moderador();
};
#endif