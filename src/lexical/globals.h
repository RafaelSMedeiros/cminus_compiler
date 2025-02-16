#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER

#include "parser.tab.h"

#define ENDFILE 0 // Definido implicitamente pelo Yacc/Bison, e não está incluso no arquivo tab.h file

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern int lineno; // Contador de linhas no código fonte

typedef int TokenType;

// Tipo do noh da arvore
typedef enum {
    StmtK,
    ExpK
} NodeKind;

// Tipo de declaracao de noh
typedef enum {
    IfK,
    WhileK,
    AssignK,
    ReturnINT,
    ReturnVOID
} StmtKind;

// Tipo de expressao de noh
typedef enum {
    OpK, // Kind of Operation (Tipo de Operação)
    ConstK, // Valor numérico constante.
    IdK, // Uso de variável.
    VarDeclK, // Declaração de variável.
    VetDeclK, // Declaração de vetor.
    FunDeclK, // Declaração de função.
    AtivK, // Chamada de função.
    TypeK, // Palavra reservada de tipo.
    VetorK, // Uso de parâmetro vetor.
    VarParamK, // Declaração de variável parâmetro.
    VetParamK // Declaração de vetro parâmetro.
} ExpKind;

/* ExpType is used for type checking */
typedef enum {Void,Integer,Boolean} ExpType;

#define MAXCHILDREN 3
typedef struct treeNode {
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    int lineno;
    NodeKind nodekind;
    
    union { 
       StmtKind stmt;
       ExpKind exp;
    } kind;

    union { TokenType op;
             int val;
             char * name; 
    } attr;
    
    // ExpType type; /* for type checking of exps */
} TreeNode;

#endif
