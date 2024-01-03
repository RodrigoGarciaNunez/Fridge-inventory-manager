#include "FuncionesPY.h"      // Alan Yair Cortes Lopez y Rodrigo Gracía Núñez
#include <stdio.h>
#include <stdlib.h>            //NOTA: Por favor, utilice este programa con numeros de 1 solo dígito
#include <string.h>

void menuSec(Nodo *aux1, Nodo *aux2, Nodo *aux3, Nodo *aux4, ListaS *lista, ListaS *listaTemp, ListaS *encontrados, char tipo[20]);

int main()
{
    ListaP *LPrincipal;                        // Aquí se crea un apuntador que apuntará a la lista de  listas
    LPrincipal = crear_ListaP();               // se llama a la función para crear la lista principal
    ListaS *bebidas;                
    bebidas = crear_ListaS("Bebidas");            //creacion de apuntadores para cada lista y se agregan a la lista principal para tener la lista de listas
    insertar_cabezaLista(LPrincipal, bebidas);    // desde la linea 13 a linea 29
    ListaS *embutidos;
    embutidos = crear_ListaS("Embutidos");
    insertar_cabezaLista(LPrincipal, embutidos);
    ListaS *frutas;
    frutas = crear_ListaS("Frutas");
    insertar_cabezaLista(LPrincipal, frutas);
    ListaS *lacteos;
    lacteos = crear_ListaS("Lacteos");
    insertar_cabezaLista(LPrincipal, lacteos);
    ListaS *proteinas;
    proteinas = crear_ListaS("Proteinas");
    insertar_cabezaLista(LPrincipal, proteinas);
    ListaS *verduras;
    verduras = crear_ListaS("Verduras");
    insertar_cabezaLista(LPrincipal, verduras);

   Nodo *aux = crear_Nodo(crear_Alimento("Bebida", "Coca-cola", 9, "01/02/19", "01/03/22", 1));
    insertar_cola(bebidas, aux);
    aux = crear_Nodo(crear_Alimento("Bebida", "Red-cola", 5, "01/03/18", "01/05/21", 1));
    insertar_cola(bebidas, aux);
    aux = crear_Nodo(crear_Alimento("Bebida", "Pepsi", 7, "02/04/20", "04/07/22", 1));
    insertar_cola(bebidas, aux);

    aux = crear_Nodo(crear_Alimento("Embutido", "Chorizo", 2, "22/01/22", "03/09/21", 1));
    insertar_cola(embutidos, aux);
    aux = crear_Nodo(crear_Alimento("Embutido", "Salchicha", 2, "00/00/00", "00/00/00", 0));
    insertar_cola(embutidos, aux);
    aux = crear_Nodo(crear_Alimento("Embutido", "Fuet", 1, "01/03/18", "01/05/21", 1));
    insertar_cola(embutidos, aux);
   
    aux = crear_Nodo(crear_Alimento("Fruta", "Manzana", 2, "P", "P", 1));
    insertar_cola(frutas, aux);
    aux = crear_Nodo(crear_Alimento("Fruta", "Mango", 7, "P", "P", 1));
    insertar_cola(frutas, aux);
    aux = crear_Nodo(crear_Alimento("Fruta", "Pera", 8, "P", "P", 1));
    insertar_cola(frutas, aux);
    
    aux = crear_Nodo(crear_Alimento("Lacteo", "Leche", 3, "P", "P", 1));
    insertar_cola(lacteos, aux);
    aux = crear_Nodo(crear_Alimento("Lacteo", "Queso crema", 2, "P", "P", 1));
    insertar_cola(lacteos, aux);
    aux = crear_Nodo(crear_Alimento("Lacteo", "Queso manchego", 2, "P", "P", 1));
    insertar_cola(lacteos, aux);
    
    aux = crear_Nodo(crear_Alimento("Proteina", "Nuez", 5, "P", "P", 1));
    insertar_cola(proteinas, aux);
    aux = crear_Nodo(crear_Alimento("Proteina", "Pasta", 1, "P", "P", 1));
    insertar_cola(proteinas, aux);
    aux = crear_Nodo(crear_Alimento("Proteina", "Almendra", 3, "P", "P", 1));
    insertar_cola(proteinas, aux);
   
    aux = crear_Nodo(crear_Alimento("Verdura", "Cilantro", 9, "P", "P", 1));
    insertar_cola(verduras, aux);
    aux = crear_Nodo(crear_Alimento("Verdura", "Cebolla", 2, "P", "P", 1));
    insertar_cola(verduras, aux);
    aux = crear_Nodo(crear_Alimento("Verdura", "Zanahoria", 3, "P", "P", 1));
    insertar_cola(verduras, aux);

    ListaS *listaTemp;             // se crea una lista enlazada simple llamada "Temp" que se utilizará para la función mergeSort
    listaTemp = crear_ListaS("Temp");
    ListaS *encontrados;
    encontrados = crear_ListaS("Encontrados");  // La lista "Encontrados" se utilizará para guardar a los nodos que sean buscados y tengan el mismo precio
    Nodo *aux1;
    Nodo *aux2;   // Nodos auxiliares para proximos usos
    Nodo *aux3;
    Nodo *aux4;
    int elecprincipal; // "elecprincipal" guarda la opcion que el usuario elija del menú principal
    /*char TipoAlimento[20];
    char NAME[30];
    int precio;
    char FechaCompra[15];
    char FechaCad[15];
    int estatus;

    
    int elecsec;
    int busc;
    int rept;
    int elecins;
    int elec3;*/
    do
    {
        printf("\n\t\tBienvenido a las listas del contenido de tu refrigerador\n");    // menú principal
        printf("\tEstas son las categorias de los alimentos que podemos enlistar:\n");
        printf("\t\t\t\t1.- Bebidas\n");
        printf("\t\t\t\t2.- Embutidos\n");
        printf("\t\t\t\t3.- Frutas\n");
        printf("\t\t\t\t4.- Lacteos\n");
        printf("\t\t\t\t5.- Proteinas\n");
        printf("\t\t\t\t6.- Verduras\n");
        printf("\t\t\t\t7.- Salir\n");
        printf("\t\tDime el numero de la categoria a la que quieres ingresar:\n");
        scanf("%d", &elecprincipal);  //se guarda la opcion que el usuario elija en "elecprincipal"

        switch (elecprincipal) // sentencia switch que corresponde a "elecprincipal"
        {
        case 1:   //el caso 1 corresponde a la lista bebidas
        {
            menuSec(aux1, aux2, aux3, aux4, bebidas, listaTemp, encontrados, "Bebida"); //la función menuSec se explica hasta abajo
            break;
        }
        case 2:   //el caso 2 corresponde a la lista embutidos
        {
            menuSec(aux1, aux2, aux3, aux4, embutidos, listaTemp, encontrados, "Embutido");
            break;
        }
        case 3: //el caso 1 corresponde a la lista frutas
        {
            menuSec(aux1, aux2, aux3, aux4, frutas, listaTemp, encontrados, "Fruta");
            break;
        }
        case 4:   //el caso 1 corresponde a la lista lacteos
        {
            menuSec(aux1, aux2, aux3, aux4, lacteos, listaTemp, encontrados, "Lacteo");
            break;
        }
        case 5:    //el caso 1 corresponde a la lista proteinas
        {
            menuSec(aux1, aux2, aux3, aux4, proteinas, listaTemp, encontrados, "Proteina");
            break;
        }
        case 6:    //el caso 1 corresponde a la lista verduras
        {
            menuSec(aux1, aux2, aux3, aux4, verduras, listaTemp, encontrados, "Verdura");
            break;
        }
        default:
        {
            break;
        }
        }
    } while (elecprincipal < 7);
    free(LPrincipal);
    free(bebidas);      //se libera la memoria de cada lista creada
    free(embutidos);
    free(verduras);
    free(frutas);
    free(lacteos);
    free(proteinas);
    free(listaTemp);
    free(encontrados);
    //free(aux);
    //free(aux1);
    //free(aux2);
    //free(aux3);
    printf("\n\t\tHasta luego! :)");
    return (0);
}

//menSec es una función tipo Void que recibe a los cuatro apuntadores auxiliares de tipo Nodo expuestos anteriormenet, a los 3 apuntadores tipo ListaS y una cadena de 20 caracteres 

void menuSec(Nodo *aux1, Nodo *aux2, Nodo *aux3, Nodo *aux4, ListaS *lista, ListaS *listaTemp, ListaS *encontrados, char tipo[20])
{
    char TipoAlimento[20];    //variables que guardarán datos si es que se ingresa un nuevo alimento
    char NAME[20];
    int precio;
    char FechaCompra[15];
    char FechaCad[15];
    int estatus;

    int elecprincipal;
    int elecsec;
    int busc;
    int rept;
    int elecins;
    int elec3;
    do
    {
        printf("\n\n\t\tEstas en la seccion de %s\n", lista->nombreLista);   // menú secundario
        printf("\t\t\tQue deseas hacer?:\n\n");
        printf("\t\t\t1.- Ingresar %s\n", lista->nombreLista);
        printf("\t\t\t2.- Quitar %s\n", lista->nombreLista);
        printf("\t\t\t3.- Mostrar la lista de %s\n", lista->nombreLista);
        printf("\t\t\t4.- Buscar %s\n", lista->nombreLista);
        printf("\t\t\t5.- Ordenar %s por precio\n", lista->nombreLista);
        printf("\t\t\t6.- Vaciar lista de %s\n", lista->nombreLista);
        printf("\t\t\t7.- Salir\n");
        printf("\t\tDime el numero de lo que quieres hacer:\n");
        printf("\n\tNOTA: las opciones quitar y buscar utilizan busquedas binarias recursivas:\n");
        printf("\tSi vas a usar alguna de estas, asegurate de siempre usar la opcion ordenar antes:\n");
        scanf("%d", &elecsec);   // se guarda la opción que elija el usuario en elecsec
        fflush(stdin);

        switch (elecsec)
        {
        case 1:
        {
            //Nodo *aux1;
            //int rept;
            do
            {
                printf("\n Ingresa los datos de la/el %s: ", tipo);    // se pide al usuario que ingresen los datos del alimento que van a ingresar
                fflush(stdin);
                printf("\n Nombre de la/el %s: ", tipo);
                scanf("%[^\n]", NAME);
                printf(" Precio: ");
                scanf("%d", &precio);
                fflush(stdin);
                printf(" Fecha de compra (siga el formato dd/mm/aa): ");
                scanf("%[^\n]", FechaCompra);
                fflush(stdin);
                printf(" Fecha de caducidad (siga el formato dd/mm/aa): ");
                scanf("%[^\n]", FechaCad);
                fflush(stdin);
                printf(" Estatus: ");
                scanf("%d", &estatus);
                fflush(stdin);
                aux1 = crear_Nodo(crear_Alimento(tipo, NAME, precio, FechaCompra, FechaCad, estatus));  //se crea un nodo con los datos que el usuario ingresó 
                
                if (isEmpty(*lista) == 1)    //si la lista está vacía, se ingresa el nodo en la cabeza
                {
                    insertar_cabeza(lista, aux1);
                }
                else     // en caso contrario, se le pregunta al usuario en dónde quiere ingresar el nuevo nodo
                {

                    printf(" \n En donde la/o quieres insertar?");
                    printf("\n 1.- Al inicio de la lista");
                    printf("\n 2.- En medio de la lista");
                    printf("\n 3.- Al final de la lista");
                    scanf("%d", &elecins);      //elcins guarda la opción que haya esogido el usuario
                    fflush(stdin);                                             
                    if (elecins == 1)
                    {
                        insertar_cabeza(lista, aux1);  //si eligió 1, el nodo se ingresa en la cabeza
                    }
                    else if (elecins == 2)
                    {                         //si esoge 2, entonces se le muestra al usuario la lista de precios de los productos actuales en la lista
                        printf("\n\tLista de precios\n");
                        printListaPrecios(lista);  // se imprime la lista de solo los precios de los productos
                        printf(" \nDespues de que precio desea insertar?");
                        scanf("%d", &elec3);
                        fflush(stdin);
                        aux2 = buscaElemento1(lista, elec3);   // se busca al elemento con la función buscaElemento1
                        if (aux2 == NULL)
                        {
                            insertar_cabeza(lista, aux1);    //si la función regresa NULL, significa que el nodo que se buscaba no existe, así que se inserta el nodo en la cabeza
                        }
                        else
                        {
                            insertar_enmedio(lista, aux2, aux1);  //en caso contrario, se llama a la funció insertar_enmedio
                        }
                    }
                    else
                    {
                        insertar_cola(lista, aux1);  // si el usuario elige 3, entonces el nodo se ingresa en la cola
                    }
                }
                printf("\n Deseas ingresar otra/o %s (1=si, 0=no)", tipo);  //se pregunta al usario si quiere ingresar otro alumno
                scanf("%d", &rept);
                fflush(stdin); //se limpia el buffer

            } while (rept == 1);
            printLista(lista);
            break;
        }
        case 2:
        {
            if(isEmpty(*lista)==1){ //si la lista está vacía, se rompe el caso
                printf("\n\t No hay nada en la lista %s :/", lista->nombreLista);
                break;
            } 

            printf("\n Que precio tiene el producto que vas a eliminar?");
            scanf("%d", &busc);       //el usuario ingresa el precio que tiene el producto que va a eliminar
            fflush(stdin);
            aux2 = lista->cabeza;  //aux2 apunta a la cabeza de la lista actual
            aux3 = aux2;    //aux3 apunta a donde apunta aux2
            while (aux2->sig != NULL)
            {
                aux2 = aux2->sig;          //este ciclo ayuda a que aux2 apunte al ultimo nodo
            }
            quitar_enmedio2(lista, busc, aux3, aux2); //se llama a la función quitar_enmedio2
            printLista(lista);
            break;
        }
        case 3:
        {
            printLista(lista);  // se imprime toda la lista
            break;
        }
        case 4:
        {
            if(isEmpty(*lista)==1){ //si la lista está vacía, se rompe el caso
                printf("\n\t No hay nada en la lista %s :/", lista->nombreLista);
                break;
            } 

            printf("\n Que precio tiene el producto que estas buscando? ");
            scanf("%d", &busc);       //se pregunta al usuario sobre el precio que está buscando
            fflush(stdin);
            aux2 = lista->cabeza;     //aux2 apunta a la cabeza
            aux3 = aux2;               //aux3 apunta a donde apunta aux2
            while (aux2->sig != NULL)
            {
                aux2 = aux2->sig;      // con el ciclo, aux2 apuntará al ultimo nodo
            }

            while (aux3 != NULL)
            {
                aux3 = busqueda_binaria_recursiva(lista, aux3, aux2, busc);  //se manda a llamar a la busqueda binaria recursiva
                if (aux3 == NULL)
                {
                    break;     //si la función devuelve un NULL, entoces se rompe el ciclo
                }
                else
                {
                    aux4 = copiar(aux3);                   // en caso contraro, aux3 se copiará en aux4 con la función copiar
                    insertar_cabeza(encontrados, aux4);    //se inserta en la cabeza el nod copia en la lista encontrados
                    aux3 = aux3->sig;   //aux3 apunta al siguiente nodo para reiniciar la busqueda de otros nodos que compartan el mismo precio
                }
            }
            if(encontrados->cabeza == NULL){
                printf("\n Lo siento, pero no encontré %s con el precio que buscas :/", lista->nombreLista);
            }
            else{
                printLista(encontrados);   // se imprime la lista "encontrados"
                vaciarLista(encontrados);    // se vacía la lista "encontrados"
            }
            break;
        }
        case 5:
        {
            if(isEmpty(*lista)==1){ //si la lista está vacía, se rompe el caso
                printf("\n\t No hay nada en la lista %s :/", lista->nombreLista);
                break;
            } 

            aux2 = lista->cabeza;  //aux2 apunta a la cabeza 
            aux3 = aux2;            //aux3 apunta a donde apunta aux2
            while (aux2->sig != NULL)
            {
                aux2 = aux2->sig;     //con este ciclo aux2 apuntará al ultimo nodo de la lista actual
            }
            if (strcmp(tipo, "Bebida") == 0 || strcmp(tipo, "Fruta") == 0 || strcmp(tipo, "Proteina") == 0)   //aquí el código decide si usar MergeSort u ordenamiento_burbuja2 
            {            //strcmp compara la cadena tipo con "Bebida", "fruta" y Proteina. Si solo una se cumple, entonces se usa Mergesort
                MergeSort(lista, listaTemp, aux3, aux2);
                printf("\n Listo! Use MergeSort\n");
            }
            else   // en caso contrario, se usa  ordenamiento_burbuja2
            {
                ordenamiento_burbuja2(lista, aux2);
                printf("\n Listo! Use ordenamiento Burbuja2\n");
            }
            printLista(lista);
            break;
        }
        case 6:
        {
            vaciarLista(lista); //se vacía la lista
            break;
        }
        default:
        {
            break;
        }
        }
    } while (elecsec < 7);
}
