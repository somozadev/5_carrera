import java.util.Scanner;

class numeroComplejo {
    int num_real;
    int num_imag;

    numeroComplejo(int num_real, int num_imag) {
        this.num_real = num_real;
        this.num_imag = num_imag;
    }
}

public class NumComplCalculator {
    numeroComplejo z;
    numeroComplejo w;

    NumComplCalculator(numeroComplejo z, numeroComplejo w) {
        this.z = z;
        this.w = w;
    }
    public numeroComplejo Sum() {
        numeroComplejo res = new numeroComplejo(z.num_real + w.num_real, z.num_imag + w.num_imag);
        return res;
    }

    public numeroComplejo Res() {
        numeroComplejo res = new numeroComplejo(z.num_real - w.num_real, z.num_imag - w.num_imag);
        return res;
    }

    public numeroComplejo Mult() {
        numeroComplejo res = new numeroComplejo((z.num_real * w.num_real) - (z.num_imag * w.num_imag),
                (z.num_real * w.num_imag) + (z.num_imag * w.num_real));
        return res;
    }
    public void Prettify(numeroComplejo res)
    {
        System.out.println("El resultado es : "+ res.num_real + "+" + res.num_imag + " i");
    }



    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        System.out.println("[1 num_real] Introduzca el número real del primer número complejo: ");
        int real = reader.nextInt();
        System.out.println("[1 num_imag] Introduzca el número imaginario del primer número complejo: ");
        int imag = reader.nextInt();
        numeroComplejo n1 = new numeroComplejo(real, imag);

        
        System.out.println("[2 num_real] Introduzca el número real del segundo número complejo: ");
        int real2 = reader.nextInt();
        System.out.println("[2 num_imag] Introduzca el número imaginario del segundo número complejo: ");
        int imag2 = reader.nextInt();
        numeroComplejo n2 = new numeroComplejo(real2, imag2);

        NumComplCalculator calculator = new NumComplCalculator(n1,n2);
        System.out.println("La suma: ");
        calculator.Prettify(calculator.Sum());
        System.out.println("La resta: ");
        calculator.Prettify(calculator.Res());
        System.out.println("La multiplicación: ");
        calculator.Prettify(calculator.Mult());
        reader.close();
    }
}
