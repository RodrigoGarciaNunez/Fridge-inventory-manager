/*plista_simple.c* todas funciones*/         //García Núñez Rodrigo y Alan Yair Cortes Lopez
/*Librerias*/
#include "FuncionesPY.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funciones y/o procedimientos*/

Alimento *crear_Alimento(char TipoAlimento[20], char NAME[20], int Precio, char Fechacompra[10], char FechaCad[10], int estatus) //en esta funcion se llena la estructura que contiene los datos del alumno
{
    Alimento *aux = (Alimento *)malloc(sizeof(Alimento));
    strcpy(aux->TipoAlimento, TipoAlimento);
    strcpy(aux->nameAlimento, NAME);
    aux->precio = Precio;
    strcpy(aux->FechaCompra, Fechacompra);
    strcpy(aux->FechaCad, FechaCad);
    aux->Estatus = estatus;
    return (aux); //retorna un apuntador de tipo Alumno
}

Nodo *crear_Nodo(Alimento *alimento) // se crea el nodo que contendrá la estructura Alumno
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo)); // crea un auxiliar de tipo nodo con memoria dinamica
    aux->datos = alimento;                    // el apuntador datos apunta a donde apunta el apuntador alumno
    aux->sig = NULL;                          // hacemos que el apuntador sig apunte a NULL
    return (aux);
}

Nodo *copiar(Nodo *cop){     //esta funció  recibe el apuntador al nodo que se va a copira
    Alimento *aux = crear_Alimento(cop->datos->TipoAlimento, cop->datos->nameAlimento, cop->datos->precio, cop->datos->FechaCompra, cop->datos->FechaCad, cop->datos->Estatus);
    Nodo *aux1 = crear_Nodo(aux);     //aux apuntará a los datos del a alimento copia, con datos sacados del nodo recibido
    return aux1;                    //se crea el nodo con los datos de aux y se retorna aux1
}

ListaS *crear_ListaS(char nombreLista[15])
{
    ListaS *aux = (ListaS *)malloc(sizeof(ListaS)); //reserva memoria de forma dinamica para una lista
    strcpy(aux->nombreLista, nombreLista);
    aux->cabeza = NULL;
    return (aux); //regresa un apuntador de tipo null
}

ListaP *crear_ListaP()
{
    ListaP *aux = (ListaP *)malloc(sizeof(ListaP)); //reserva memoria de forma dinamica para una lista
    aux->cabezaLista = NULL;
    return (aux);
}

void insertar_cabezaLista(ListaP *listap, ListaS *aux)
{
    if (isEmptyListaP(*listap) == 1) //si está vacía, entonces el apuntador cabeza, apunta a aux. sig seguiría apuntando a NULL
    {
        listap->cabezaLista = aux;
    }
    else
    {
        aux->sigLisa = listap->cabezaLista; // sig apunta al nodo al que apunta la cabeza
        listap->cabezaLista = aux;          // el apuntador cabeza, ahora apunta a aux
    }
}

int isEmptyListaP(ListaP lista)
{
    if (lista.cabezaLista == NULL)
    {
        //printf("\n Lista Vacia funcion isEmpty\n");  si la cabeza apunta a null, entonces significa que la lista está vacía
        return (1);
    }
    else
    {
        //printf("\n La Lista No Esta Vacia funcion isEmpty \n"); si no, entonces quiere decir que no está vacía
        return (0);
    }
}

int isEmpty(ListaS lista)
{
    if (lista.cabeza == NULL)
    {
        //printf("\n Lista Vacia funcion isEmpty\n");  si la cabeza apunta a null, entonces significa que la lista está vacía
        return (1);
    }
    else
    {
        //printf("\n La Lista No Esta Vacia funcion isEmpty \n"); si no, entonces quiere decir que no está vacía
        return (0);
    }
}

void insertar_cabeza(ListaS *lista, Nodo *aux)
{
    if (isEmpty(*lista) == 1) //si está vacía, entonces el apuntador cabeza, apunta a aux. sig seguiría apuntando a NULL
    {
        lista->cabeza = aux;
    }
    else
    {
        aux->sig = lista->cabeza; // sig apunta al nodo al que apunta la cabeza
        lista->cabeza = aux;      // el apuntador cabeza, ahora apunta a aux
    }
}

void insertar_cola(ListaS *lista, Nodo *aux)
{
    Nodo *cola;
    cola = lista->cabeza;     // cola apunta a cabeza
    if (isEmpty(*lista) == 1) //si la lista está vacía, entonces se inserta el nodo en la cabeza
    {
        insertar_cabeza(lista, aux);
    }
    else
    {
        while (cola->sig != NULL)
        {
            cola = cola->sig; //el ciclo recorre todos los nodos hasta que que sig sea NULL
        }
        cola->sig = aux; //sig ahora apunta a aux
        cola = aux;      //cola ahora apunta  aux
    }
}

void insertar_enmedio(ListaS *lista, Nodo *anterior, Nodo *elemento)
{
    if (isEmpty(*lista) == 1) //si la lista está vacía, entonces la cabeza apunta al elemento a insertar
    {
        lista->cabeza = elemento;
    }
    else
    { // si no, entonces el apuntador sig apuntará al nodo siguiente del nodo que estará ante de el
        elemento->sig = anterior->sig;
        anterior->sig = elemento; //al apuntador sig del nodo anterior apuntará al nodo que se va a insertar
    }
}

void quitar_cabeza(ListaS *lista)
{
    Nodo *aux = NULL;
    Nodo *aux1;
    if (!isEmpty(*lista))
    {
        aux = lista->cabeza; //si la lista no está vacía, entonces la cabeza apuntará al nodo sig de la actual cabeza
        lista->cabeza = lista->cabeza->sig;
        aux1 = aux;
        free(aux);
    }
    else
    {
        //printf("\n La lista esta vacia  estoy dentro del procedimiento quitar cabeza  \n");
    }
    //return (aux1); //en este caso, se retorna aux1 utilizar el nodo eliminado
}

void quitar_cola(ListaS *lista)
{
    Nodo *cola;
    Nodo *anterior;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar cola \n");
    }
    else
    {
        if (lista->cabeza->sig == NULL) // si la lista solo contiene a un elemento, entonces el apuntador cabeza apuntará NULL y la lista estaría vacía
        {
            lista->cabeza = NULL;
            //printf("\n  Memoria liberada estoy dentro del procedimiento quitar cola\n");
        }
        else
        {
            cola = lista->cabeza; //cola apunta a la cabeza. el ciclo hace que cola pase por todos los nodos hasta llegar al ultimo
            while (cola->sig != NULL)
            {
                anterior = cola;
                cola = cola->sig;
            }
            anterior->sig = NULL; //el apuntador sig del penultimo nodo apunta ahora a NULL
            free(cola);           //libera el apuntador que apuntaba a la cola
            //cola=NULL;
        }
    }
}

/*Nodo *quitar_enmedio1(ListaS *lista, int ent)
{
    Nodo *anterior;
    Nodo *borrar;
    Nodo *aux;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");
    }
    else
    {
        borrar = buscaElemento1(lista, ent); //el apuntador borrar apunta a donde apunta el apuntador retornado por buscaElemento1
        if (lista->cabeza == borrar)
        {
            aux = quitar_cabeza(lista); //si el elemento a borra es la cabeza, entonces se llama a la función quitar_cabeza
        }
        else
        {
            anterior = lista->cabeza;
            while (anterior->sig != borrar) //el ciclo funciona hasta que sig apunte a donde apunta borrar
            {
                anterior = anterior->sig;
            }
            anterior->sig = borrar->sig; //el apuntador sig de anterior apunta al nodo sig del nodo a eliminar de la lista
            aux = borrar;
            //free(borrar);  no se libera memoria porque aux apunta al nodo que se quitó de la lista
            //printf("\nid=%d",anterior->datos->id);
        }
    }
    return (aux);
}
*/

//esta función recine un apuntador a la lista en la que se va a buscar, apunatdores al nodo inferior y superior (depende del llamado) y el elemento (precio que se va a buscar)
void quitar_enmedio2(ListaS *lista, int ent, Nodo *inferior, Nodo *superior)
{
    Nodo *anterior;
    Nodo *borrar;
    Nodo *aux;
    if (isEmpty(*lista) == 1)
    {
        //printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");
    }
    else
    {
        borrar = busqueda_binaria_recursiva(lista, inferior, superior, ent); //el apuntador borrar apunta a donde apunta el apuntador retornado por buscaElemento1
        if (lista->cabeza == borrar)
        {
            quitar_cabeza(lista); //si el elemento a borra es la cabeza, entonces se llama a la función quitar_cabeza
        }
        else if(borrar == NULL){
            printf("\n\t El elemento que buscas eliminar ya no existe :/");
        }
        else
        {
            anterior = lista->cabeza;
            while (anterior->sig != borrar) //el ciclo funciona hasta que sig apunte a donde apunta borrar
            {
                anterior = anterior->sig;
            }
            anterior->sig = borrar->sig; //el apuntador sig de anterior apunta al nodo sig del nodo a eliminar de la lista
            //aux = borrar;
            free(borrar);  
            printf("\n\t Se ha borrado el producto correctamente :D");
        }
    }
}

Nodo *buscaElemento1(ListaS *lista, int ent)
{
    Nodo *aux = lista->cabeza;
    //Alumno *alu;
    if (!isEmpty(*lista))
    {
        while (aux->datos->precio != ent) //si la lista no está vacía, aux pasará cada uno de los nodos y  hasta que la matricula de un nodo sea igual al numero ent
        {
            if (aux->sig != NULL)
            {
                aux = aux->sig; //si es diferente de null, entonces se puede actualizar aux
            }
            else
            {
                printf("\n El precio = %d no se encuentra en la lista", ent); //cunado es null significa que no hubo ninguna coincidencia, por lo tanto, no existe ese nodo
                aux = NULL;
                return (aux); //retorna un apauntador a NULL
                //break;
            }
        }
        if (aux->datos->precio == ent)
        {
            printf("\n El precio = %d si esta en la lista", ent);
            return (aux); //retorna un apuntador al nodo que se estaba buscando
        }
    }
    else
    {
        printf("\n  LA LISTA NO TIENE NADA");
        return (NULL);
    }
}

void vaciarLista(ListaS *lista)
{
    Nodo *aux = lista->cabeza;
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
            aux = aux->sig; //el ciclo quita la cabeza hasta que aux apunte a null, lo que indicaría que la lista quedó vacía
            quitar_cabeza(lista);
        }
    }
    else
    {
        printf("\n LISTA SIN NADA PROCEDIMIENTO VACIAR LISTA \n");
    }
    free(aux);
}

void printLista(ListaS *lista)    //esta función recibe un apuntador de tipo lista
{
    Nodo *aux = lista->cabeza;  //el auxiliar de tipo lista apunta a la cabeza
    Alimento *ali;               // apuntaor de tipo Alimento
    printf("\n\t%s\n", lista->nombreLista);   
    //printf(" siguiente lista: %s\n", lista->sigLisa->nombreLista);
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
 
            ali = aux->datos;       //ali apunta a los datos de cada nodo durante el ciclo
            printf("\n Tipo del alimento: %s", ali->TipoAlimento); //se imprimen los datos de todos los nodos
            printf("\n Nombre del alimento: %s", ali->nameAlimento);
            printf("\n Precio: %d ", ali->precio);
            printf("\n Fecha de compra: %s", ali->FechaCompra);
            printf("\n Fecha de cadusidad: %s", ali->FechaCad);
            printf("\n Estatus: %d\n", ali->Estatus);
            aux = aux->sig;   //aux se actualiza para apuntar al siguiente nodo
        }
    }
    else
    {
        printf("\n LISTA SIN NADA \n");
    }
}

void printListaP(ListaP *lista)
{
    ListaS *aux = lista->cabezaLista;
    ListaS *aux1 = aux->sigLisa;
    //printf("\t%s\n", lista->cabezaLista->nombreLista);
    if (isEmptyListaP(*lista) != 1)
    {
        while (aux->sigLisa->sigLisa != NULL)
        {

            printf("\n Nombre lista: %s", aux->nombreLista);
            printf("\n Nombre lista siguiente: %s\n", aux->sigLisa->nombreLista);
            aux = aux->sigLisa;
            //aux1 = aux1->sigLisa;
        }
        printf("\n sali del ciclo");
    }
    else
    {
        printf("\n LISTA SIN NADA \n");
    }
}

void printListaPrecios(ListaS *lista)
{
    Nodo *aux = lista->cabeza;     //Similar a printLista, pero esta no utiliza un apuntador de tipo Alimento para apuntar a los datos de cada nodo
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)   //durante el ciclo, solo imprime los precios de los productos
        {

            printf("\n Precio de %s: %d", aux->datos->nameAlimento, aux->datos->precio);
            aux = aux->sig;
        }
    }
    else
    {
        printf("\n LISTA SIN NADA \n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MergeSort recibe dos apuntadores de tipo ListaS. "lista" apunta a la lista que se va a ordenar.
//temp apunta a una lista auxiliar que se va a utilizar en la funcion mezcla. También recibe dos apuntadores que
// apuntan al primer y ultimo nodo de la lista a ordenar (dependiendo de en qué llamada se encuentra)
void MergeSort(ListaS *lista, ListaS *temp, Nodo *primero, Nodo *ultimo)
{
    Nodo *central;            // se crea un apuntador de tipo Nodo llamado central
    if (primero != ultimo)    // si el apuntador primero apunta a donde apunta ultimo, entonces se acaba la función
    {
        central = getcentral(primero, ultimo);      //en caso contrario, se llama a la función getcentral y central adquiere el retorno de esta
        MergeSort(lista, temp, primero, central);   //primera llamada recursiva, esta opaera desde el primer nodo hasta el central
        MergeSort(lista, temp, central->sig, ultimo); //segunda llamda recursiva, opera desde el nodo siguiente  a central, hasta el ultmo nodo que se le haya pasado
        mezcla(lista, temp, primero, central, ultimo); //llamado a fución mezcla (se explica proximamente)
    }
}


//getcentral recibe a dos apunatdores tipo Nodo. n es el "primer" nodo y s es el "ultimo"
Nodo *getcentral(Nodo *n, Nodo *s)
{
    Nodo *aux = n->sig;    //aux apunta al nodo siguiente de n
    Nodo *aux1 = n;        //aux apunta a n
    while (aux != s && aux != NULL && aux != s->sig)
    {
        aux = aux->sig->sig;                 //aux se va actualizando de 2 en 2 hasta que este pase a s
        aux1 = aux1->sig;                  //aux1 se va actualizando de 1 en 1. Cunado el ciclo termina, aux1 apuntará al nodo "central" entre n y s
    }
    Alimento *ali = aux1->datos;
    if (aux1->sig == s || aux1->sig == s->sig)  //en caso de que solo haya dos nodos, entonces se retorna aux1 apuntando a n
    {
        aux1 = n;
        return aux1;
    }
    else
    {
        return aux1;    //se retorna el aux1 que devolvió el ciclo
    }
    printf("\n\t El nodo central es %s con precio: %d", ali->nameAlimento, ali->precio);
}

//mezcla recibe dos apuntadores tipo ListaS. lista es la lista a ordenar, temp es la lista auxiliar. Tambien recibe dos apunadores
// de tipo nodo que apunatn al nodo de la izquierda, derecha y el central entre estos dos
void mezcla(ListaS *lista, ListaS *temp, Nodo *izquierda, Nodo *central, Nodo *derecha)
{
    Nodo *aux;           //aux ayudará a crear los nodos para la lista temp
    Nodo *x;           
    Nodo *y;
    Nodo *z;
    x = izquierda;        //x apunta al nodo de la izquierda
    z = izquierda;        //z también apunta al nodo de la izquierda
    y = central->sig;       //y apunta al nodo siguiente de central
    Alimento *ali, *ali1;
    ali = x->datos;   
    ali1 = y->datos;
    while (x != central->sig && y != derecha->sig) //este ciclo seguirá mientra que x sea diferente qie el siguiente de central
    {                                              // y "y" sea diferente al siguiente de derecha
        if (ali->precio <= ali1->precio) 
        {
            aux = crear_Nodo(crear_Alimento(ali->TipoAlimento, ali->nameAlimento, ali->precio, ali->FechaCompra, ali->FechaCad, ali->Estatus));
            insertar_cola(temp, aux);      //se crea el nodo con los datos de x y se inserta en temp 
            x = x->sig;         
            ali = x->datos;       //x y ali se actualizan al siguiente nodo
        }
        else
        {
            aux = crear_Nodo(crear_Alimento(ali1->TipoAlimento, ali1->nameAlimento, ali1->precio, ali1->FechaCompra, ali1->FechaCad, ali1->Estatus));
            insertar_cola(temp, aux);     // se crea el nodo con los datos de y y se inserta en temp
            y = y->sig; 
            if (y == NULL)    //si y apunta a NULL se rompe el ciclo
            {
                break;
            }
            ali1 = y->datos;   //se actualia "y" y ali1
        }
    }
    while (x != central->sig)  //los siguientes dos ciclos sirven para insertar nodo que hayan sobrado después del ciclo anterior
    {
        aux = crear_Nodo(crear_Alimento(ali->TipoAlimento, ali->nameAlimento, ali->precio, ali->FechaCompra, ali->FechaCad, ali->Estatus));
        insertar_cola(temp, aux);
        x = x->sig;
        ali = x->datos;
    }
    while (y != derecha->sig)
    {
        aux = crear_Nodo(crear_Alimento(ali1->TipoAlimento, ali1->nameAlimento, ali1->precio, ali1->FechaCompra, ali1->FechaCad, ali1->Estatus));
        insertar_cola(temp, aux);
        y = y->sig;
        if (y == NULL)   //si y apunta a NULL, entonces se rompe el ciclo
        {
            break;
        }
        ali1 = y->datos;
    }
    for (z = izquierda, aux = temp->cabeza; z != derecha->sig; z = z->sig, aux = aux->sig)
    {
        strcpy(z->datos->TipoAlimento, aux->datos->TipoAlimento);  //en este ciclo, los nodos de la lista toman los datos de los nodos de la lista temp
        strcpy(z->datos->nameAlimento, aux->datos->nameAlimento);
        z->datos->precio = aux->datos->precio;
        strcpy(z->datos->FechaCompra, aux->datos->FechaCompra);
        strcpy(z->datos->FechaCad, aux->datos->FechaCad);
        z->datos->Estatus = aux->datos->Estatus;
    }
    vaciarLista(temp);  //se vacía la lista temp
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ordenamiento_burbuja2 recibe un apuntaor tipo ListaS que apunta a la lista a ordenar y un apuntador de tipo nodo que apunta al ultimo (derecha).
void ordenamiento_burbuja2(ListaS *lista, Nodo *derecha)
{ 
    Nodo *i;   //i apuntará a derecha 
    Nodo *j;   //j apuntará a la cabeza de la lista a ordenar (se observa en el inicio del for)
    Nodo *indiceIntercambio;   //indice de intercambio indicará si se deben seguir haciendo intercambios despues de recorrer toda la lista
    i = derecha;        //para poder iniciar el bucle, i apunta a derecha
    while (i != NULL)    //el ciclo funciona mientras que i sea diferente de NULL
    { 
        indiceIntercambio = NULL;    //indiceIntercambio apunta a NULL (pude cambiar más adelante)
        for (j = lista->cabeza; j->sig !=NULL; j = j->sig)  //el ciclo va a recorrer cada nodo de la lista hasya llegar al ultimo (el penultimo nodo es el ultimo con el que el ciclo va a operar)
        {
            if (j->sig->datos->precio < j->datos->precio)  //si el precio del nodo siguiente de j es menor que el de j, entonces se intercambian sus datos
            {
                Alimento *aux = j->datos;                  //aux y aux apuntan a los datos de j y j->sig respecctivamente
                Alimento *aux1 = j->sig->datos;
                int respaldo = aux->precio;
                char respaldoName[15];
                strcpy(respaldoName, aux->nameAlimento);
                char respaldoCom[15];
                strcpy(respaldoCom, aux->FechaCompra);
                char respaldoCad[15];
                strcpy(respaldoCad, aux->FechaCad);
                int respaldoEst = aux->Estatus;
                strcpy(aux->nameAlimento, aux1->nameAlimento);
                strcpy(aux1->nameAlimento, respaldoName);
                aux->precio = aux1->precio;                           
                aux1->precio = respaldo;                 
                strcpy(aux->FechaCompra, aux1->FechaCompra);
                strcpy(aux1->FechaCompra, respaldoCom);
                strcpy(aux->FechaCad, aux1->FechaCad);
                strcpy(aux1->FechaCad, respaldoCad);    
                aux->Estatus = aux1->Estatus;
                aux1->Estatus = respaldoEst;                                                     
                indiceIntercambio = derecha;          //si la condición fue verdadera, indiceIntercambio apuunta a derecha                            
            }
        }
        i = indiceIntercambio;  //i apunta a indiceIntercambio, y dependiendo de si este es NULL o no, entonces el ciclo seguirá o se detendrá
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//esta función recine un apuntador a la lista en la que se va a buscar, apunatdores al nodo inferior y superior (depende del llamado) y el elemento (precio que se va a buscar)
Nodo *busqueda_binaria_recursiva(ListaS *lista, Nodo *inferior, Nodo *superior, int elemento)
{
    Nodo *central;        
    //printf("\n entre al if");                            //nodo central que ayudará más adelante para encontra el nodo centrale ntre inferior y superior
    if(inferior == superior->sig){
        //printf("\n Error el precio %d ya no se encuentra en ninguna posición de la lista, regreso al menu princupal...",elemento);          //si el inferior apunta al siguiente del superior, eso quiere decir que nunca se encontró el nodo que se buscaba
        return(NULL);   //retorna un null
    }
    else{
        central = getcentral(inferior, superior);  //se llama a getcentral y central obtiene su retornado
        if(central->datos->precio == elemento){   //si el precio del nodo central es igual al que se busca, entonces envía mensajes de que sí encontró un nodo 
            printf("\n\t El precio %d se encuentra relacionado al producto %s", elemento, central->datos->nameAlimento);

            if(central->datos->Estatus == 1){ //si el estatus es 1, indica que el producto su está disponible, si no, no lo está.
                printf("\n\t El producto %s SI esta disponible en tu refrigerador :D\n", central->datos->nameAlimento);
            }
            else{
                printf("\n\t El producto %s NO esta disponible en tu refrigerador :/", central->datos->nameAlimento);
            }
            return(central);  //se retorna central
        }
        else if(central->datos->precio < elemento){   //si el precio de central es menor al que se busca, entonces se llama a la función recursivamente y operará desde el siguiente de cenetral, hasta el "superior"
            return busqueda_binaria_recursiva(lista, central->sig, superior, elemento);  // se retona el apuntador que la función decida retornar
        }
        else{            
            Nodo *aux = lista->cabeza; 
            while(aux->sig != central){
                aux = aux->sig;     //este ciclo ayuda a que aux apunte al nodo anterior de central
            }
            return busqueda_binaria_recursiva(lista, inferior, aux, elemento);  // se llamam recursivamente a la función, operando desde el "inferior" hasta aux
        }
    }
}

