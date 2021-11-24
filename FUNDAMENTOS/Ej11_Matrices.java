import java.util.Scanner;



class Ej11_Matrices {

    public int[][] mat;
    public void setN(int n) {
        mat = new int[n][n];        
    }
    public  boolean isCuadrada() {
        boolean iscuad = false;
        if(mat.length == mat[0].length)
        iscuad = true;
        return iscuad; 
    }

    public  void FillMatrix(Scanner scanner) {
        for(int i=0; i < mat.length; i++){
            for(int j=0; j < mat[i].length; j++){
                mat[i][j] = scanner.nextInt();
            }
        }
    }

    public boolean isSymetric() {
        boolean isSym = true;
        for(int i=0; (i < (mat.length-1)) && isSym; i++){
            for(int j=i+1; (j<= mat[i].length-1) && isSym; j++){
                if(mat[i][j]!= mat[j][i])
                    isSym=false;
            }
        }
        return isSym;
    }

    public  void PrintMatrix() {
        for(int i=0; i < mat.length; i++){
            for(int j=0; j < mat[i].length; j++){
                System.out.print(mat[i][j] + ", ");
            }
            System.out.println("");
        }
        
    }

    public  void PrintInfo() {
        this.PrintMatrix();
        System.out.println("Es cuadrada: "+this.isCuadrada());
        System.out.println("Es simetrica: "+this.isSymetric());
    }

    public static void main(String[] args) {
        Ej11_Matrices ej = new Ej11_Matrices();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Dime la dimension n: ");
        ej.setN(scanner.nextInt());
        ej.FillMatrix(scanner);
       ej.PrintInfo();
    }
}
