#include "globals.h"

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

void buildSymtab(TreeNode *); // Função para construir a tabela de símbolos

void st_insert( char * name, int lineno, DataTypes type, IDTypes idtype, char * escopo); // Função para inserir um nó na tabela de símbolos
 
int st_lookup ( char * name ); // Função para procurar um nó na tabela de símbolos

void printSymTab(); // Função para imprimir a tabela de símbolos

DataTypes getFunType(char *nome);

int st_lookup_scope(char *name, char *escopoAtual); // Função para procurar um nó na tabela de símbolos considerando o escopo

int main_declared(); // Função para verificar se a função main foi declarada

int isFunctionName(char *name); // Função para verificar se o nome é de uma função

#endif
