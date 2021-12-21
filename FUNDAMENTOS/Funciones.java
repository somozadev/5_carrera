import java.io.*;
import java.util.Scanner;

public class Funciones {

    /**
     * @throws IOException
     *Lee por consola el tamano deseado para luego recorrer un array con dicho tamano rellenando el array.
     */
    public static int[] Read() {
        try (Scanner reader = new Scanner(System.in)) {
            System.out.println("Introduzca el tamano del array: ");
            int tam = reader.nextInt();
            int[] arr = new int[tam];
            for (int i = 0; i < arr.length; i++) {
                System.out.println("Introduzca el elemento " + (i + 1 ) + " : ");
                arr[i] = reader.nextInt();
            }
            return arr;
        }
    }
  /**
     * @param arr
     * @throws IOException
     * Recorre el array de enteros pasado por parametro y muestra su contenido.
     */
    public static void Show(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.println(i + 1 + "." + arr[i]);
        }
    }
    /**
     * @param arr
     * @throws IOException
     * Crea una copia auxiliar del array pasado por parametros (usando un for para pasar los valores, no se desea una copia sino un nuevo array).
     * Recorre el array original donde va guardando desde su final el principio del array auxiliar. 
     * Devuelve el array original ordenado al reves. 
     */
    public static int[] Reverse(int[] arr) {
        int j = arr.length;

        int[] auxarr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            auxarr[i] = arr[i];
        }

        for (int i = 0; i < arr.length; i++) {
            arr[j - 1] = auxarr[i];
            j -= 1;
        }
        return arr;
    }
  /**
     * @param arr
     * @throws IOException
     * Ordena por el metodo burbuja el array pasado por referencia. No devuelve nada pues el cambio lo almacena en el mismo int []arr.
     */
    public static void Sort(int[] arr) {
        int aux;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j + 1] < arr[j]) {
                    aux = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = aux;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {


        int[] array = Funciones.Read();
        Funciones.Show(array);

        Funciones.Sort(array);
        Funciones.Show(array);

        Funciones.Show(Funciones.Reverse(array));
    }
}