import java.util.Scanner;

/*Realiza el algoritmo y programa en Java que lea un número entero por pantalla e indique si es par y múltiplo de 5. */

public class ParYMulCin {
    int input;

    ParYMulCin(int input) {
        this.input = input;
    }

    private boolean isPair() {
        boolean returner = false;
        if (input % 2 == 0)
            returner = true;
        return returner;
    }

    private boolean isMulCin() {
        boolean returner = false;
        if (input % 5 == 0)
            returner = true;
        return returner;
    }

    public void PrettyPrint() {
        if (isPair() && isMulCin())
            System.out.println("El " + input + " es un número par y múltiplo de 5.");
        else if (isPair())
            System.out.println("El " + input + " es un número par pero no es múltiplo de 5.");
        else if (isMulCin())
            System.out.println("El " + input + " es múltiplo de 5 pero no es par.");
        else
            System.out.println("El " + input + " no es par ni múltiplo de 5.");
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("Introduzca un número entero: ");
        int input = reader.nextInt();

        ParYMulCin parymul = new ParYMulCin(input);
        parymul.PrettyPrint();
        reader.close();
    }

}