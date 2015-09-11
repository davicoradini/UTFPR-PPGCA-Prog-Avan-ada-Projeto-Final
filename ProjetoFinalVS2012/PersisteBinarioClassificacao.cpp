#include "PersisteBinarioClassificacao.h"
#include "Sistema.h"

typedef Classificacao Persistivel_local;

PersisteBinarioClassificacao::PersisteBinarioClassificacao(Persistivel* p) : AbsPersisteBinario(p)
{
	strcpy_s(arquivo,	  "c:\\sisargsavedfiles\\Classificacao.txt");
	strcpy_s(arquivoTemp, "c:\\sisargsavedfiles\\Classificacao_temp.txt");
}

PersisteBinarioClassificacao::PersisteBinarioClassificacao() : AbsPersisteBinario(){}

PersisteBinarioClassificacao::~PersisteBinarioClassificacao()
{
}


//inherited methods
const bool PersisteBinarioClassificacao::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);
	persistivel_local->setId(Sistema::Identificadores::getNextIdClassificacao());

	ofstream stream(arquivo, ios::out | ios::app | ios::ate | ios::binary);
		
	int idLocal = persistivel_local->getId();
	strcpy_s(nome,	persistivel_local->getNome());
	strcpy_s(descricao, persistivel_local->getDescricao().c_str());

	binary_write(stream, idLocal);
	binary_write(stream, nome);
	binary_write(stream, descricao);

	stream.close();

	return true;
}
const bool PersisteBinarioClassificacao::alterar()
{
	operacoesEmBinario(-1, persistivel, OPERACAO::Alterar);
	return true;
}
const bool PersisteBinarioClassificacao::remover()
{
	operacoesEmBinario(-1, persistivel, OPERACAO::Remover);
	return true;
}
vector<Persistivel*> PersisteBinarioClassificacao::operacoesEmBinario(int idCarregar, Persistivel* persistivel, OPERACAO operacao)
{
	//vector<Persistivel*> vLista;
	Persistivel_local *persistivel_local;

	//abre arquivo para leitura /gravação
	ifstream inStream(arquivo, ios::in | ios::ate | ios::binary);
	ofstream streamTemp;

	// ### ALTERANDO OU REMOVENDO REGISTRO ###
	//se estiver alterando o processo é diferente
	if (operacao == OPERACAO::Alterar || operacao == OPERACAO::Remover)
	{
		streamTemp.open(arquivoTemp, ios::out | ios::app | ios::ate | ios::binary);
		persistivel_local = static_cast<Persistivel_local*>( persistivel );
	}

	//armazena tamanho do arquivo para saber quando parar
	int totalSize = (int)inStream.tellg();
	int totalNow  = 0;
	int maxId = 0;
	int idLocal;
	inStream.seekg(0, ios::beg);

	//variáveis necessárias para armazenar temporariamente valores do arquivo
	//int  idAtual, i2; int  	char c1[201]; char c2[101];

	//enquanto não acabar o arquivo, realiza leitura dos cadastros
	while (totalNow < totalSize)
	{
		//realiza leitura das info. do arquivo
		binary_read(inStream, idLocal);
		binary_read(inStream, nome);
		binary_read(inStream, descricao);

		//guarda posição atual do ponteiro lendo o arquivo
		totalNow = (int)inStream.tellg();

		//armazena maior Identificador armazenado
		if (idLocal > maxId) maxId = idLocal;
		

		// ### ALTERANDO OU REMOVENDO REGISTRO ###
		//se operação == alterar, deve criar novo arquivo temporário
		//armazenando os cadastros até encontrar o registro a alterar
		//então insere o registro alterado e continua copiando
		if (operacao == OPERACAO::Alterar || operacao == OPERACAO::Remover)
		{
			//quando encontrar o registro a atualizar, copia novos valores
			//no caso de estar removendo, não utiliza o registro na cópia para novo arquivo
			if (idLocal == persistivel_local->getId())
			{
				strcpy_s(nome, persistivel_local->getNome());
				strcpy_s(descricao, persistivel_local->getDescricao().c_str());
			}
			if (operacao == OPERACAO::Alterar || idLocal != persistivel_local->getId())
			{
				binary_write(streamTemp, idLocal);
				binary_write(streamTemp, nome);
				binary_write(streamTemp, descricao);
			}
		}
		// ### LOCALIZANDO REGISTROS ###
		else
		{
			//cria novo elemento e atribui valores lidos do arquivo
			persistivel_local = new Persistivel_local();
			persistivel_local->setId(idLocal);
			persistivel_local->setNome(nome);
			persistivel_local->setDescricao(descricao);

			//caso pasado ID por parâmetro, retorna apenas o registro correspondente
			if (idCarregar > 0 && idCarregar == idLocal)
			{
				cadastrosLocalizados.push_back( static_cast<Persistivel_local*>( persistivel_local ) );

				totalNow = totalSize;
			}
			else if (idCarregar < 0)
			{
				cadastrosLocalizados.push_back( static_cast<Persistivel_local*>( persistivel_local ) );
			}
		}
	}

	inStream.close();
	streamTemp.close();

	// ### ALTERANDO OU REMOVENDO REGISTRO ###
	//necessário renomear arquivos e remover temporário
	if (operacao == OPERACAO::Alterar || operacao == OPERACAO::Remover)
	{
		remove(arquivo);
		rename(arquivoTemp, arquivo);
	}

	//atribui /atualiza identificador (ID)
	else if (idCarregar < 0 && maxId > Sistema::Identificadores::getAtualIdClassificacao())
	{
		int geraId;
		do
		{
			geraId = Sistema::Identificadores::getNextIdClassificacao();
		}
		while (maxId > geraId);
	}

	return cadastrosLocalizados;
}
vector<Persistivel*> PersisteBinarioClassificacao::carregarCadastros(const int id)
{
	return operacoesEmBinario(id, nullptr, OPERACAO::Localizar);
}
