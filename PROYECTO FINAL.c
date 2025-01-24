#include <stdio.h>
#include <string.h>

#define MAX_FAMILIAS 100

// Estructura para almacenar información de la familia
struct Familia {
    char nombre[50];
    char cedula[20];
    int num_hijos;
    int regalos_recibidos;
    int regalos_necesitados;
};

// Arreglo para almacenar datos de las familias
struct Familia familias[MAX_FAMILIAS];

// Variable para rastrear el número de familias en el sistema
int num_familias = 0;

void mostrarMenu() {
    printf("\nSistema de Distribución de Regalos Navideños\n");
    printf("----------------------------------\n");
    printf("1. Registrar una Familia\n");
    printf("2. Registrar Entrega de Regalos\n");
    printf("3. Reporte de Regalos Faltantes por Familia\n");
    printf("4. Reporte de Regalos Entregados por Familia\n");
    printf("5. Salir\n");
    printf("Ingrese su opción: ");
}

void registrarFamilia() {
    if (num_familias < MAX_FAMILIAS) {
        printf("Ingrese los detalles de la familia:\n");
        printf("Nombre: ");
        scanf("%s", familias[num_familias].nombre);
        printf("Cédula: ");
        scanf("%s", familias[num_familias].cedula);
        printf("Número de hijos: ");
        scanf("%d", &familias[num_familias].num_hijos);
        familias[num_familias].regalos_recibidos = 0;
        familias[num_familias].regalos_necesitados = familias[num_familias].num_hijos;
        num_familias++;
        printf("¡Familia registrada exitosamente!\n");
    } else {
        printf("Se ha alcanzado el número máximo de familias.\n");
    }
}

void registrarEntregaRegalo() {
    char cedula[20];
    int regalos;

    printf("Ingrese la Cédula de la familia: ");
    scanf("%s", cedula);

    for (int i = 0; i < num_familias; i++) {
        if (strcmp(familias[i].cedula, cedula) == 0) {
            printf("Ingrese el número de regalos entregados: ");
            scanf("%d", &regalos);
            familias[i].regalos_recibidos += regalos;
            printf("¡Entrega de regalos registrada exitosamente!\n");
            return;
        }
    }
    printf("No se encontró la familia con Cédula %s.\n", cedula);
}

void reporteRegalosFaltantes() {
    printf("\nReporte de Regalos Faltantes:\n");
    printf("-----------------------\n");
    for (int i = 0; i < num_familias; i++) {
        printf("Familia: %s, Regalos Faltantes: %d\n", familias[i].nombre, familias[i].regalos_necesitados - familias[i].regalos_recibidos);
    }
}

void reporteRegalosEntregados() {
    printf("\nReporte de Regalos Entregados:\n");
    printf("------------------------\n");
    for (int i = 0; i < num_familias; i++) {
        printf("Familia: %s, Regalos Recibidos: %d\n", familias[i].nombre, familias[i].regalos_recibidos);
    }
}

int main() {
    int opcion;

    while (1) {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarFamilia();
                break;
            case 2:
                registrarEntregaRegalo();
                break;
            case 3:
                reporteRegalosFaltantes();
                break;
            case 4:
                reporteRegalosEntregados();
                break;
            case 5:
                return 0;
            default:
                printf("Opción inválida. Por favor, intente de nuevo.\n");
        }
    }

    return 0;
}
