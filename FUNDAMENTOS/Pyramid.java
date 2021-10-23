import java.util.Scanner;

public class Pyramid {
    float l;
    float number_of_l;
    float h;
    float area;
    float volumen;

    Pyramid(float l, float h) {
        this.l = l;
        this.h = h;
        this.number_of_l = 4;
        this.area = Area();
        this.volumen = Volumen();
    }

    void ShowData() {
        System.out.println("lado:" + this.l);
        System.out.println("altura:" + this.h);
        System.out.println("*****************");
        System.out.println("area:" + this.area + " m^2");
        System.out.println("volumen:" + this.volumen + " m^3");
    }

    float Area() {
        float a_base = this.l * this.l;
        float a_lat = this.l * this.h * this.number_of_l / 2;
        float a_tot = a_base+a_lat;
        return a_tot;
    }

    float Volumen() {

        float a_base = this.l * this.l;
        float v_pyramid = (a_base * this.h) / 3;
        return v_pyramid;
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println("Escriba el valor del lado: ");
        int l = reader.nextInt();
        System.out.println("Escriba el valor de la altura: ");
        int h = reader.nextInt();
        Pyramid piramide = new Pyramid(l, h);
        piramide.ShowData();
        reader.close();

    }
}