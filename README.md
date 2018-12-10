# Gestão de Residuos 
----------------
Trabalho Prático Final da Disciplina de PDS2 - UFMG - 2018/2
Trata-se de um sistema de gerenciamento de resíduos feito em C++

## TODO
-------
- [x] Criar Makefile
- [x] Desenvolver User Stories
- [x] Desenvolver CRC
- [x] Desenvolver Testes
- [x] Bootstrap no Projeto
- [x] Desenvolver Usuário
- [x] Desenvolver Agendamento das Coletas
- [x] Desenvolver Pontos de Coletas
- [x] Desenvolver Funcionalidade Extra


### Autores
-----------
- Lucas Silva Chaves
- Lucas Gonçalves Bispo
- Pedro Herculano Flores
- Rayane Hellen Dias Soares

### Funcionalidade Extra
------------------------
- Como funcionalidade extra, temos como proposta a persistência dos dados inseridos pelo usuário num banco de dados relacional.
- A escolha do SQLite como banco de dados, se dá pela facilidade em trabalhar com ele, pensando a tempo necessário para configuração e tamanho.

### Compilação
---------------
É necessário a instalação da biblioteca "libsqlite3-dev", para compilação do projeto.

> sudo apt install libsqlite3-dev

> sudo pacman -S sqlite

> sudo dnf install sqlite sqlite-devel

Compilar a main.
> make

Rodar a main.
> make run

Rodar os casos de Teste.
> make tests

Limpar o banco de dados.
> ./bin/main RESET

### Observações
* Feito com C++/11
