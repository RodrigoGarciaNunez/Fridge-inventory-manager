/*lista_simple.h*/                        // Alan Yair Cortes Lopez y García Núñez Rodrigo
/*Prototipos y/o funciones*/
/*Estructuras principales*/

typedef struct Alimento
{
    char TipoAlimento[20];
    char nameAlimento[20];
    int precio;
    char FechaCompra[10];
    char FechaCad[10];
    int Estatus;
} Alimento;

typedef struct Nodo
{
    Alimento *datos;
    struct Nodo *sig;
} Nodo;

typedef struct ListaS
{
    char nombreLista[15];
    Nodo *cabeza;
    struct ListaS *sigLisa;
    //Nodo *cola;
} ListaS;

typedef struct ListaP{
    ListaS *cabezaLista;
}ListaP;

//FUNCIONES
Alimento *crear_Alimento(char TipoAlimento[20], char NAME[15], int precio, char FechaCompra[10], char FechaCad[10], int estatus);
Nodo *crear_Nodo(Alimento *alimento);
Nodo *copiar(Nodo *cop);
ListaS *crear_ListaS(char nombreLista[15]);
ListaP *crear_ListaP();
int isEmpty(ListaS lista);
int isEmptyListaP(ListaP lista);
void insertar_cabeza(ListaS *lista, Nodo *aux);
void insertar_cabezaLista(ListaP *listap, ListaS *aux) ;
void insertar_cola(ListaS *lista, Nodo *aux);
void insertar_enmedio(ListaS *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza(ListaS *lista);
void quitar_cola(ListaS *lista);
void quitar_enmedio(ListaS *lista, Nodo *elemento);
Nodo *quitar_enmedio1(ListaS *lista, int ent);
Nodo *buscaElemento(ListaS *lista, Nodo *elemento);
Nodo *buscaElemento1(ListaS *lista, int ent);
void quitar_enmedio2(ListaS *lista, int ent, Nodo *inferior, Nodo *superior);

//Nodo* buscaElemento(ListaS *lista, int ID);
void vaciarLista(ListaS *lista);
void printLista(ListaS *lista);
void printListaP(ListaP *lista);
void printListaPrecios(ListaS *lista);
void depurar_23(Nodo *aux, Nodo *aux1, Nodo *alu23, ListaS *L23, ListaS *p);
Nodo *getcentral(Nodo *n, Nodo *ultimo);
void MergeSort(ListaS *lista, ListaS *temp, Nodo *primero, Nodo *ultimo);
void mezcla(ListaS *lista, ListaS *temp,Nodo *izquierda, Nodo *central, Nodo *derecha);
void ordenamiento_burbuja2(ListaS *lista, Nodo *derecha);
Nodo *busqueda_binaria_recursiva(ListaS *lista, Nodo *inferior, Nodo *superior, int elemento);
