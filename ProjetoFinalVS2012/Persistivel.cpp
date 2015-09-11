#include "Persistivel.h"

Persistivel::Persistivel()
{
	idArgumentacao = -1;
}
Persistivel::~Persistivel() {}


//setters
void Persistivel::setIdArgumentacao(const int i)
{
	idArgumentacao = i;
}
const int Persistivel::getIdArgumentacao()
{
	return idArgumentacao;
}

void Persistivel::setId(const int i) {
	id = i;
}
const int Persistivel::getId() const {
	return id;
}