#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159265358979323846

void basica_calculadora(float *resultado, char *deno_0, char *salir);
void juego(int *intentos, int *numazar);
float Calcu_Areas();


int main(){

    //Declaración de variable para el menú
    int opcion = 0;

    //Despliegue del menú para elegir a qué actividad quiere entrar
    while (opcion != 4) {
        printf("Ingrese la operacion a realizar (numero entero)\n");
        printf("1.- Calculadora\n");
        printf("2.- Juego\n");
        printf("3.- Calculadora de areas\n");
        printf("4.- Cerrar programa\n");
        scanf("%d",&opcion);

        //Elección del problema
        switch(opcion){

            case 1: //Calculadora 

                    float resultado;
                    char deno_0; 
                    char salir;
                    char continuar1;
                    deno_0 = 0;
                    salir = 'n';
                    continuar1 = 'y';
                    deno_0 = 0; //Inicializando en 0

                    while (continuar1 == 'y'){ //Bucle para hacer las veces que ocupe usar la calculadora
                        basica_calculadora(&resultado, &deno_0, &salir);
                        if (salir){
                            break; //En la función, obtienes el valor de salir, este te saca en caso de que no sea una división y ya no hace comparación
                        } else {

                                if (deno_0) { //En caso de que sí sea una división, hace una comparación de que si es 0, no se podrá hacer, en caso de que no sea 0, entonces sí se imprimirá.
                                    printf("El denominador no puede ser 0\n");
                                } else {
                                    printf("El resultado es: %.2f\n", resultado);
                                }

                            printf("Quieres continuar haciendo operaciones? (y/n): "); //Pregunta si quieres continuar o no
                            scanf("%s",&continuar1);

                            while (continuar1 != 'y' && continuar1 != 'n') { //En caso de introducir algo incorrecto, te meterá a este bucle hasta que metas a una opción correcta.
                                printf("Opcion incorrecta, intenta de nuevo: ");
                                scanf(" %c", &continuar1); 
                            } 
                        }   
                    }
                    break; 

            case 2: // Juego
                char continuar2;
                int intentos, numazar;
                continuar2 = 'y';

                while (continuar2 == 'y') { //Este bucle sirve para hacer la iteración las veces que necesites

                    juego(&intentos, &numazar);
                    printf("Has adivinado el numero. Es: %d con %d intentos\n", numazar, intentos); //Impresión de si adivinaste el número

                    printf("Quieres continuar jugando? (y/n): ");
                    scanf(" %c", &continuar2); //Preguntando si desea continuar jugando

                    while (continuar2 != 'y' && continuar2 != 'n') {  //En caso de ingresar una opción incorrecta, este bucle te hará elegir una opción correcta.
                        printf("Opcion incorrecta, intentalo de nuevo: ");
                        scanf(" %c", &continuar2);
                    }
                }
                break;
                
            case 3:
                char continuar3;
                float resultado_area;
                continuar3 = 'y';

                while (continuar3 == 'y'){ //Bucle para realizar la operación las veces que se necesite

                    resultado_area = Calcu_Areas(); //Llamar a la función y guardarla en resultado_area

                    printf("El resultado es: %f", resultado_area); //Impresión del resultado

                    printf("\nDeseas continuar haciendo operaciones? (y/n): ");
                    scanf(" %c",&continuar3); //Preguntar si desea continuar haciendo operaciones

                    while (continuar3 != 'y' && continuar3 != 'n'){ //En caso de que ingrese un valor incorrecto, este bucle hará que introduzca un valor correcto.
                        printf("Opcion incorrecta, por favor selecciona la correcta (y/n): ");
                        scanf(" %c",&continuar3);
                    }
                }

                break;
            case 4:
                    //Finalizar el programa
                printf("Se ha finalizado el programa con exito");
                exit(0); 
            default:
                    //En caso de ingresar un valor incorrecto, saldrá el default diciendo que la opción fue incorrecta.
                printf("Opcion incorrecta, seleccione una correcta\n");
            }
    }
}
    

void basica_calculadora(float *resultado, char *deno_0, char *salir){ 

    //Declaración de variables
    float num1, num2;
    char operador;

    //Despliegue de menú y obtención de la operacion a realizar.
    printf("Introduce el operador de la accion a hacer\n");
    printf("1.- Suma (+)\n");
    printf("2.- Resta(-)\n");
    printf("3.- Multiplicacion (*)\n");
    printf("4.- Division (/)\n");
    printf("5.- Salir (s)\n");
    scanf("%s",&operador);

    //En caso de introducir un valor diferente al del menú, este bucle se ejecutará hasta introducir uno válido.
    while (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != 's') {
        printf("Operador incorrecto, por favor intentalo de nuevo\n");
        scanf(" %c", &operador);
    }

    if (operador == 's'){
        *salir = 1; //En caso de que coloquen salir, este nos servirá para sacarnos de la iteración.
    } else {
        *salir = 0;
         //Entrada de valores num1 y num2
        printf("Introduce el primer valor\n");
        scanf("%f",&num1);
        printf("Introduce el segundo valor\n");
        scanf("%f",&num2);
        //Elección del problema
        switch(operador){
            case '+':
                //Suma de los valores de entrada (num1 y num2)
                *resultado = num1+num2;
                break;
            case '-':
                //Resta de los valores de entrada (num1 y num2)
                *resultado = num1-num2;
                break;
            case '*':
                //Multiplicación de los de entrada (num1 y num2)
                *resultado = num1*num2;
                break;
            case '/':
                //División.
                //En caso de que el denominador sea 0, no hará la operación.
                if (num2 == 0) {
                    *deno_0 = 1;
                    *resultado = 0;
                    return;
                } else {
                    *deno_0 = 0;
                    *resultado = num1 / num2;
                    return;
                }
            default:
            //Impresión en caso de introduccir un operador incorrecto.
                printf("El valor del operador es incorrecto, intentalo de nuevo\n");
            }
        }
}

void juego(int *intentos, int *numazar) {
    int numdiv;
    numdiv = 0;

    srand(time(NULL)); // Semilla para el generador de número random
    *numazar = rand() % 100; // Obtención del número rand

    printf("Juego para adivinar el numero\n");

    *intentos = 0; // Inicializar del contador de intentos
    
    //Un bucle que compara si el número adivinado (numdiv) es igual al número azar generado
    while (numdiv != *numazar) {
        printf("Introduce un valor: ");
        scanf("%d", &numdiv);
        
        //Se utiliza el if para saber si el número introducido es más grande o pequeño del número azar
        if (*numazar < numdiv) {
            printf("Introduce un valor mas bajo.\n");
        } else if (*numazar > numdiv) {
            printf("Introduce un valor mas alto.\n");
        }

        (*intentos)++; //Contador de intentos
        
    }
}
float Calcu_Areas(){
    int selected_area;
    float base, altura, resultado1, radio, lado;

    lado = 0;   //Incialización en 0 de las variables
    radio = 0;
    resultado1 = 0;
    base = 0;
    altura = 0;
    selected_area = 0;

    //Despligue del menú        
    printf("Que area deseas determinar?\n");
    printf("1.- Triangulo\n");
    printf("2.- Circulo\n");
    printf("3.- Rectangulo\n");
    printf("4.- Cubo\n");
    printf("5.- Cilindro\n");
    printf("6.- Salir\n");
    scanf("%d", &selected_area);
    //Bucle en caso de que el numero sea incorrecto
    while (selected_area != 1 && selected_area != 2 && selected_area != 3 && selected_area != 4 && selected_area != 5 && selected_area != 6) {
        printf("Numero incorrecto, por favor intentalo de nuevo\n");
        scanf(" %d", &selected_area);
    }
    switch(selected_area){
        case 1:  
                //Triangulo
            printf("Determinar area del triangulo\n");
            printf("Ingresa la altura en cm: ");
            scanf("%f",&altura);
            printf("Ingresa la base en cm: ");
            scanf("%f",&base);
            resultado1 = (base * altura)/2;
            break;
        case 2:
                //Área del circulo
            printf("Deteminar el area de un circulo\n");
            printf("Introduce el radio del circulo en cm: ");
            scanf("%f",&radio);
            resultado1 = PI * (radio*radio);
            break;
        case 3:
                //Area del rectángulo
            printf("Determinar el area de un rectangulo\n");
            printf("Introduce la base del rectangulo en cm: ");
            scanf("%f",&base);
            printf("Introduce la altura del rectangulo en cm: ");
            scanf("%f", &altura);
            resultado1 = base * altura;
            break;
        case 4:
                //Área de un cubo
            printf("Determinar el area de un cubo\n");
            printf("Introducel valor de un lado en c: ");
            scanf("%f",&lado);
            resultado1 = lado * lado;
            break;
        case 5:
                //Area de un cilindro
            printf("Determinar el area de un cilindro");
            printf("Introduce el radio del cilindro");
            scanf("%f",&radio);
            printf("Introduce la altura del cilindro");
            scanf("%f",&altura);
            resultado1 = 2 * PI * radio * (radio + altura);
            break;
        case 6:
            printf("Has salido del programa\n");
            break;
        default:
            printf("Valor incorrecto");
    }

    return resultado1; //Retonar el valor obtenido de cualquier problema en el switch.
}