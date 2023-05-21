#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

void alta();
void listas();
void archivo();
void baja();
void modificar();

int na, * numero;
float* precio, timp, * total;
string* nombre, * descripcion, * clasificacion, * genero, * consola, * status;

int main()
{
    int opcion;
    printf("\t ***MENU DE OPCIONES***\n");
    printf("1.- Alta de Articulos\n");
    printf("2.- Baja de Articulos\n");
    printf("3.- Modificacion de Articulo\n");
    printf("4.- Lista de Articulos\n");
    printf("5.- Limpiar Pantalla\n");
    printf("6.- Salir\n");
    printf("\nSeleccion:");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        alta();
        return main();
        break;
    case 2:
        baja();
        return main();
        break;
    case 3:
        modificar();
        return main();
        break;
    case 4:
        listas();
        return main();
        break;
    case 5:
        system("cls");
        return main();
        break;
    case 6:
        archivo();
        break;
    }

    return 0;
}

void alta()
{
    printf("Digite el numero de articulos que desea registrar:\n");
    scanf("%d", &na);
    numero = new int[na];
    precio = new float[na];
    nombre = new string[na];
    descripcion = new string[na];
    clasificacion = new string[na];
    genero = new string[na];
    consola = new string[na];
    status = new string[na];
    total = new float[na];

    for (int i = 0; i < na; i++)
    {
        printf("Numero de Articulo:\n");
        scanf("%d", &numero[i]);
        getchar();
        printf("Nombre de Articulo:\n");
        getline(cin, nombre[i]);
        printf("Precio Unitario:\n");
        scanf("%f", &precio[i]);
        getchar();
        printf("Descripcion:\n");
        getline(cin, descripcion[i]);
        printf("Clasificacion:\n");
        getline(cin, clasificacion[i]);
        printf("Genero:\n");
        getline(cin, genero[i]);
        printf("Consola:\n");
        getline(cin, consola[i]);
        total[i] = precio[i] * 1.16;
        status[i] = "ACTIVO";
    }
}

void listas()
{
    for (int i = 0; i < na; i++)
    {
        if (status[i] == "ELIMINADO")
        {
            printf("REGISTRO ELIMINADO %d\n", i + 1);
        }
        else
        {
            printf("registro %d\n", i + 1);
            printf("Numero de articulo: %d\n", numero[i]);
            printf("Nombre: %s\n", nombre[i].c_str());
            printf("Precio unitario: %.2f\n", precio[i]);
            printf("Descripcion: %s\n", descripcion[i].c_str());
            printf("Clasificacion: %s\n", clasificacion[i].c_str());
            printf("Genero: %s\n", genero[i].c_str());
            printf("Consola: %s\n", consola[i].c_str());
            printf("Precio con iva: %.2f\n", total[i]);
        }
    }
}

void archivo()
{
    ofstream archivo;
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "La cueva del gamer.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        printf("ERROR NO SE PUDO CREAR EL ARCHIVO\n");
        exit(1);
    }

    archivo << "NUMERO DE ARTICULO\t";
    archivo << "NOMBRE\t";
    archivo << "PRECIO UNITARIO\t";
    archivo << "DESCRIPCION\t";
    archivo << "CLASIFICACION\t";
    archivo << "GENERO\t";
    archivo << "CONSOLA\t";
    archivo << "PRECIO CON IVA\t";
    archivo << "STATUS\n";

    for (int i = 0; i < na; i++)
    {
        if (status[i] == "ELIMINADO")
        {
            texto2 = "REGISTRO ELIMINADO ";
            texto = i;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto = numero[i];
            archivo << texto << "\t" << "\t";
            texto2 = nombre[i];
            archivo << texto2 << "\t" << "\t";
            texto = precio[i];
            archivo << texto << "\t" << "\t";
            texto2 = descripcion[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = clasificacion[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = genero[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = consola[i];
            archivo << texto2 << "\t" << "\t";
            texto = total[i];
            archivo << texto << "\t" << "\t";
            archivo << status[i] << "\n";
        }
    }

    archivo.close();
}

void baja()
{
    int j;
    printf("Ingrese el numero de registro a eliminar: ");
    scanf("%d", &j);
    j = j - 1;

    if (j >= 0 && j < na)
    {
        printf("Eliminando registro %d\n", j + 1);
        status[j] = "ELIMINADO";
    }
    else
    {
        printf("Registro no valido\n");
    }
}

void modificar()
{
    int j, opcion, op2;
    do
    {
        printf("Ingrese el numero de registro a modificar: ");
        scanf("%d", &j);
        j = j - 1;

        if (j >= 0 && j < na)
        {
            if (status[j] == "ELIMINADO")
            {
                printf("Eliminando registro %d\n", j + 1);
                printf("Ingrese un registro válido\n");
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
        else
        {
            printf("Registro no valido\n");
            op2 = 1;
        }
    } while (op2 == 1);

    printf("Ingrese que desea modificar:\n");
    printf("1.- Numero de Articulo\n");
    printf("2.- Nombre de Articulo\n");
    printf("3.- Precio Unitario\n");
    printf("4.- Descripcion\n");
    printf("5.- Clasificacion\n");
    printf("6.- Genero\n");
    printf("7.- Consola\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("Ingrese numero de articulo: ");
        scanf("%d", &numero[j]);
        break;
    case 2:
        printf("Ingrese nombre de articulo: ");
        while (getchar() != '\n');
        getline(cin, nombre[j]);
        break;
    case 3:
        printf("Ingrese precio unitario: ");
        scanf("%f", &precio[j]);
        break;
    case 4:
        printf("Ingrese descripcion: ");
        while (getchar() != '\n');
        getline(cin, descripcion[j]);
        break;
    case 5:
        printf("Ingrese clasificacion: ");
        while (getchar() != '\n');
        getline(cin, clasificacion[j]);
        break;
    case 6:
        printf("Ingrese genero: ");
        while (getchar() != '\n');
        getline(cin, genero[j]);
        break;
    case 7:
        printf("Ingrese consola: ");
        while (getchar() != '\n');
        getline(cin, consola[j]);
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
}