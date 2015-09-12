#include "PersisteBinarioPessoa.h"
#include "Sistema.h"

typedef Pessoa Persistivel_local;

PersisteBinarioPessoa::PersisteBinarioPessoa(Persistivel* p) : AbsPersisteBinario(p)
{
	strcpy_s(arquivo,	  "c:\\sisargsavedfiles\\Pessoa.txt");
	strcpy_s(arquivoTemp, "c:\\sisargsavedfiles\\Pessoa_temp.txt");
}

PersisteBinarioPessoa::PersisteBinarioPessoa() : AbsPersisteBinario()
{
}

PersisteBinarioPessoa::~PersisteBinarioPessoa()
{
}


//inherited methods
const bool PersisteBinarioPessoa::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);
	persistivel_local->setId(Sistema::Identificadores::getNextIdPessoa());

	ofstream stream(arquivo, ios::out | ios::app | ios::ate | ios::binary);
	
	int idLocal = persistivel_local->getId();
	strcpy_s(nome,	persistivel_local->getNome());
	strcpy_s(cargo, persistivel_local->getCargo());

	if (nullptr != persistivel_local->getInstituicao())	idInstituicao = persistivel_local->getInstituicao()->getId();
	else idInstituicao = -1;

	binary_write(stream, idLocal);
	binary_write(stream, nome);
	binary_write(stream, cargo);
	binary_write(stream, idInstituicao);

	stream.close();

	return true;
}
const bool PersisteBinarioPessoa::alterar()
{
	operacoesEmBinario(-1, persistivel, OPERACAO::Alterar);
	return true;
}
const bool PersisteBinarioPessoa::remover()
{
	operacoesEmBinario(-1, persistivel, OPERACAO::Remover);
	return true;
}
vector<Persistivel*> PersisteBinarioPessoa::operacoesEmBinario(int idCarregar, Persistivel* persistivel, OPERACAO operacao)
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
		binary_read(inStream, cargo);
		binary_read(inStream, idInstituicao);

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
				strcpy_s(cargo, persistivel_local->getCargo());
				idInstituicao = persistivel_local->getInstituicao()->getId();
			}
			if (operacao == OPERACAO::Alterar || idLocal != persistivel_local->getId())
			{
				binary_write(streamTemp, idLocal);
				binary_write(streamTemp, nome);
				binary_write(streamTemp, cargo);
				binary_write(streamTemp, idInstituicao);
			}
		}
		// ### LOCALIZANDO REGISTROS ###
		else
		{
			//cria novo elemento e atribui valores lidos do arquivo
			persistivel_local = new Persistivel_local();
			persistivel_local->setId(idLocal);
			persistivel_local->setNome(nome);
			persistivel_local->setCargo(cargo);
			Instituicao *instituicao = new Instituicao();
			instituicao->carregar(idInstituicao); //carrega instituição aonde quer que esteja
			persistivel_local->setInstituicao(instituicao);

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
	else if (idCarregar < 0 && maxId > Sistema::Identificadores::getAtualIdPessoa())
	{
		int geraId;
		do
		{
			geraId = Sistema::Identificadores::getNextIdPessoa();
		}
		while (maxId > geraId);
	}

	return cadastrosLocalizados;
}
vector<Persistivel*> PersisteBinarioPessoa::carregarCadastros(const int id)
{
	return operacoesEmBinario(id, nullptr, OPERACAO::Localizar);
}
