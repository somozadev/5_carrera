import java.io.*;






public class Funciones {
    public static void main(String[] args) throws IOException{

        String line = "";
        final String file = "file.txt";
        double age_m = 0.0;
        int students_n = 0;
        
        String fields[] = new String[4];
        BufferedReader reader = new BufferedReader(new FileReader(file)); 
        
        line = reader.readLine();
        while(line!=null)
        {
            students_n++;
            fields = line.split("\t");
            age_m+= Integer.parseInt(fields[1]);
            
        }
    }
}