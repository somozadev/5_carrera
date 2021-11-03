import java.util.Scanner;

class Fraction {
    public int num, den;

    public Fraction() {
        Scanner reader = new Scanner(System.in);
        System.out.println("Introduzca el numerador: ");
        this.num = reader.nextInt();
        System.out.println("Introduzca el denominador: ");
        this.den = reader.nextInt();
    }

    public Fraction(int num, int den) {
        this.num = num;
        this.den = den;
    }

    @Override
    public String toString() {
        return this.num + "/" + this.den;
    }
}

class Simpl {

    public Fraction f;
    private Fraction f_base;
    private boolean canSimpl;

    public Simpl(Fraction f) {
        this.f = f;
        this.f_base = new Fraction(f.num, f.den);
        this.canSimpl = true;
    }

    private void Simplify() {
        int mcd = Mcd();
        if (mcd == 1)
            canSimpl = false;
        f.num /= mcd;
        f.den /= mcd;
    }

    private int Mcd() {
        int num = Math.abs(this.f.num);
        int den = Math.abs(this.f.den);

        if (den == 0) {
            canSimpl = false;
            return num;
        }
        int aux;
        while (den != 0) {
            aux = num % den;
            num = den;
            den = aux;
        }
        return num;
    }

    public void Print() {
        Simplify();
        if (canSimpl)
            System.out.println("La simplificación de " + f_base.toString() + " es: " + this.f.num + "/" + this.f.den);
        else
            System.out.println(f_base.toString() + " no se puede simplificar");
    }

    public static void main(String[] args) {


        Fraction fraccion = new Fraction();
        Simpl simplificador = new Simpl(fraccion);
        simplificador.Print();
        Fraction fraccion2 = new Fraction();
        simplificador = new Simpl(fraccion2);
        simplificador.Print();
    }
}
