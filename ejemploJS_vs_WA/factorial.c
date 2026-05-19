// factorial.c
/*
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
double slowFactorial(int n) {
    if (n <= 1) return 1.0;
    
    // Hacemos esto súper lento usando recursión ineficiente
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
        // Añadimos operaciones innecesarias para hacerlo más lento
        for (int j = 0; j < 1000000; j++) {
            result = result * 1.0000001 / 1.0000001;
        }
    }
    return result;
}
*/
// factorial.c
#include <emscripten/emscripten.h>
#include <stdlib.h>
#include <math.h>

EMSCRIPTEN_KEEPALIVE
double slowBubbleSort(int size) {
    // Crear array con números en orden inverso (peor caso)
    double* arr = (double*)malloc(size * sizeof(double));
    
    // Llenar con valores en orden descendente
    for (int i = 0; i < size; i++) {
        arr[i] = (double)(size - i);
    }
    
    // Bubble Sort ineficiente con operaciones extra
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            // Comparación con operaciones costosas
            double a = arr[j];
            double b = arr[j + 1];
            
            // Operaciones innecesarias para hacerlo más lento
            for (int k = 0; k < 1000; k++) {
                a = sin(a * 0.001) * cos(b * 0.001);
                b = sqrt(fabs(a * b)) + 1.0;
            }
            
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    double result = arr[0];
    free(arr);
    return result;
}