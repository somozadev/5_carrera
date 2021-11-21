/** EJERCICIO 3
 * Implementar una calculadora de matrices en C++.
 * El programa debe permitir, dadas 2 matrices de n elementos realizar las 
 * operaciones de suma, resta y multiplicación. Las matrices deben alojarse 
 * en el free store, tanto las dadas para operar como la matriz resultante.
 * 
 * Punto extra: Adicionalmente y de manera opcional, puede generarse funciones 
 * que permitan calcular la matriz traspuesta a la dada, y, en caso de ser una 
 * matriz cuadrática, obtener su determinante.
**/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

bool esEntero(string);
void menu();
void opcion01_SumadeMatrices();
void opcion02_RestadeMatrices();
void opcion03_MultiplicaciondeMatrices();
void opcion04_Matriztraspuesta();
void opcion05_DeterminantedeunaMatriz();

bool esEntero(string linea)
{
	bool esEntero = true;
	int longitud = linea.size();
	
	if (longitud == 0)
	{
		esEntero = false;
	}
	else if (longitud == 1 && !isdigit(linea[0]))
	{
		esEntero = false;
	}
	
	return esEntero;	
}

void menu()
{
	cout << "" <<endl;
	cout << "" <<endl;
	cout << "\t\tCALCULADORA DE MATRICES" <<endl;
	cout << "\t======================================" <<endl;
    cout << "\t Elige una opcion:" <<endl;
    cout << "\t\t1. Suma de matrices" <<endl;
    cout << "\t\t2. Resta de matrices" <<endl;
    cout << "\t\t3. Multiplicacion de matrices" <<endl;
    cout << "\t\t4. Matriz traspuesta" <<endl;
    cout << "\t\t5. Determinante de una matriz" <<endl;
    cout << "\t\t6. Salir" <<endl;
    cout << "\t======================================" <<endl;
    cout << "" <<endl;
    cout << "\tOPCION:  ";
}

void opcion01_SumadeMatrices()
{
	int valorfila;
	int valorcolumna;
	
	cout << "\t* LAS MATRICES DEBEN TENER LA MISMA " <<endl;
	cout << "\t\t     DIMENSION *" <<endl;
	cout << "" <<endl;
	cout << "\tEscribe las dimensiones de las matrices:" <<endl;
	cout << "\tNumero de filas: ";
	cin >> valorfila;
	cout << "\tNumero de columnas: ";
	cin >> valorcolumna;
	cout << "" <<endl;
	
	cout << "\tDatos de la matriz A: " <<endl;
	int matriz_A[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz A[" << i << "][" << j << "]: ";
	    	cin >> matriz_A[i][j];
		}
	}
	
	cout << "" <<endl;
	cout << "\tDatos de la matriz B: " <<endl;
	int matriz_B[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz B[" << i << "][" << j << "]: ";
	    	cin >> matriz_B[i][j];
		}
	}
	
	int Resultado[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	Resultado[i][j] = matriz_A[i][j] + matriz_B[i][j];
		}
	}
    
    cout << "\n\tMatriz A: ";
    
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << matriz_A[i][j] << " ";
		}
		
		cout << "|";
	}
	
	cout << "\n" <<endl;
    cout << "\tMatriz B: ";
    
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << matriz_B[i][j] << " ";
		}
		
		cout << "|";
	}
	
	cout << "\n" <<endl;
	cout << "\tResultado de la suma: ";
	
	for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << Resultado[i][j] << " ";
		}
		
		cout << "|";
	}
}

void opcion02_RestadeMatrices()
{
	int valorfila;
	int valorcolumna;
	
	cout << "\t* LAS MATRICES DEBEN TENER LA MISMA " <<endl;
	cout << "\t\t     DIMENSION *" <<endl;
	cout << "" <<endl;
	cout << "\tEscribe las dimensiones de las matrices:" <<endl;
	cout << "\tNumero de filas: ";
	cin >> valorfila;
	cout << "\tNumero de columnas: ";
	cin >> valorcolumna;
	cout << "" <<endl;
	
	cout << "\tDatos de la matriz A: " <<endl;
	int matriz_A[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz A[" << i << "][" << j << "]: ";
	    	cin >> matriz_A[i][j];
		}
	}
	
	cout << "" <<endl;
	cout << "\tDatos de la matriz B: " <<endl;
	int matriz_B[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz B[" << i << "][" << j << "]: ";
	    	cin >> matriz_B[i][j];
		}
	}
	
	int Resultado[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	Resultado[i][j] = matriz_A[i][j] - matriz_B[i][j];
		}
	}
    
    cout << "\n\tMatriz A: ";
    
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << matriz_A[i][j] << " ";
		}
		
		cout << "|";
	}
	
	cout << "\n" <<endl;
    cout << "\tMatriz B: ";
    
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << matriz_B[i][j] << " ";
		}
		
		cout << "|";
	}
	
	cout << "\n" <<endl;
	cout << "\tResultado de la resta: ";
	
	for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << Resultado[i][j] << " ";
		}
		
		cout << "|";
	}
}

void opcion03_MultiplicaciondeMatrices()
{
	int valorfilaA;
	int valorcolumnaA;
	int valorfilaB;
	int valorcolumnaB;
	
	cout << "\t* DEBES CUMPLIR EL SIGUIENTE REQUISITO " <<endl;
	cout << "\t     filas de B = columnas de A " <<endl;
	//cout << "\t      filas de B = columnas de A *" <<endl;
	cout << "" <<endl;
	
	cout << "\tDatos de la matriz A: " <<endl;
	cout << "\tNumero de filas: ";
	cin >> valorfilaA;
	cout << "\tNumero de columnas: ";
	cin >> valorcolumnaA;
	cout << "" <<endl;
	int matriz_A[valorfilaA][valorcolumnaA];
    for(int i = 0; i < valorfilaA; i = i + 1)
    {
    	for(int j = 0; j < valorcolumnaA; j = j + 1)
	    {
	    	cout << "\t\tMatriz A[" << i << "][" << j << "]: ";
	    	cin >> matriz_A[i][j];
		}
	}
	
	cout << "" <<endl;
	cout << "\tDatos de la matriz B: " <<endl;
	cout << "\tNumero de filas: ";
	cin >> valorfilaB;
	cout << "\tNumero de columnas: ";
	cin >> valorcolumnaB;
	cout << "" <<endl;
	int matriz_B[valorfilaB][valorcolumnaB];
    for(int i = 0; i < valorfilaB; i = i + 1)
    {
    	for(int j = 0; j < valorcolumnaB; j = j + 1)
	    {
	    	cout << "\t\tMatriz B[" << i << "][" << j << "]: ";
	    	cin >> matriz_B[i][j];
		}
	}
	
	int Resultado[valorfilaA][valorcolumnaB];
	for(int i = 0; i < valorfilaA; i = i + 1)
    {
    	for(int j = 0; j < valorcolumnaB; j = j + 1)
	    {
	    	Resultado[i][j] = 0;
		}
	}
	
	if(valorfilaB == valorcolumnaA)
	{
		cout << "\n\tMatriz A: ";
	    
	    for(int i = 0; i < valorfilaA; i = i + 1)
	    {
	    	cout << "\n\t\t| ";
	    	
	    	for(int j = 0; j < valorcolumnaA; j = j + 1)
		    {
		    	cout << matriz_A[i][j] << " ";
			}
			
			cout << "|";
		}
		
		cout << "\n" <<endl;
	    cout << "\tMatriz B: ";
	    
	    for(int i = 0; i < valorfilaB; i = i + 1)
	    {
	    	cout << "\n\t\t| ";
	    	
	    	for(int j = 0; j < valorcolumnaB; j = j + 1)
		    {
		    	cout << matriz_B[i][j] << " ";
			}
			
			cout << "|";
		}
		
		
	    for(int i = 0; i < valorfilaA; i = i + 1)
	    {
	    	for(int j = 0; j < valorcolumnaB; j = j + 1)
		    {
                for( int z = 0; z < valorcolumnaA; z = z + 1)
                {
                    Resultado[i][j] += matriz_A[i][z] * matriz_B[z][j];
				}
			}
		}
		
		cout << "\n" <<endl;
		cout << "\tResultado de la multiplicacion: ";
		
		for(int i = 0; i < valorfilaA; i = i + 1)
	    {
	    	cout << "\n\t\t| ";
	    	
	    	for(int j = 0; j < valorcolumnaB; j = j + 1)
		    {
		    	cout << Resultado[i][j] << " ";
			}
			
			cout << "|";
		}
	}
	else
	{
		cout << "\t* NO CUMPLES CON EL REQUISITO " <<endl;
	}
}

void opcion04_Matriztraspuesta()
{
	int valorfila;
	int valorcolumna;
	
	cout << "\tEscribe las dimensiones de la matriz:" <<endl;
	cout << "\tNumero de filas: ";
	cin >> valorfila;
	cout << "\tNumero de columnas: ";
	cin >> valorcolumna;
	cout << "" <<endl;
	
	cout << "\tDatos de la matriz: " <<endl;
	int matriz_A[valorfila][valorcolumna];
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz[" << i << "][" << j << "]: ";
	    	cin >> matriz_A[i][j];
		}
	}
	
	int Matriz_Traspuesta[valorcolumna][valorfila];
    for(int i = 0; i < valorcolumna; i = i + 1)
    {
    	for(int j = 0; j < valorfila; j = j + 1)
	    {
	    	Matriz_Traspuesta[i][j] = matriz_A[j][i];
		}
	}
	
	cout << "\n\tMatriz: ";
    
    for(int i = 0; i < valorfila; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorcolumna; j = j + 1)
	    {
	    	cout << matriz_A[i][j] << " ";
		}
		
		cout << "|";
	}
	
	cout << "\n" <<endl;
	cout << "\tMatriz traspuesta: ";
	
	for(int i = 0; i < valorcolumna; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(int j = 0; j < valorfila; j = j + 1)
	    {
	    	cout << Matriz_Traspuesta[i][j] << " ";
		}
		
		cout << "|";
	}
}

void opcion05_DeterminantedeunaMatriz()
{
	int filaycolumna;
	float determinante;
	int i;
	int j;
	int k;
	int l;
	int m;
	
	cout << "\tEscribe las dimensiones de la matriz:" <<endl;
	cout << "\tNumero de filas y columnas: ";
	cin >> filaycolumna;
	m = filaycolumna - 1;
	
	cout << "\tDatos de la matriz: " <<endl;
	float matriz[100][100];
    for(i = 0; i < filaycolumna; i = i + 1)
    {
    	for(j = 0; j < filaycolumna; j = j + 1)
	    {
	    	cout << "\t\tMatriz[" << i << "][" << j << "]: ";
	    	cin >> matriz[i][j];
		}
	}
	
	cout << "\n\tMatriz: ";
    
    for(i = 0; i < filaycolumna; i = i + 1)
    {
    	cout << "\n\t\t| ";
    	
    	for(j = 0; j < filaycolumna; j = j + 1)
	    {
	    	cout << matriz[i][j] << " ";
		}
		
		cout << "|";
	}
	
	determinante = matriz[1][1];
	for(k = 1; k <= m; k = k + 1)
	{
		l = k + 1;
		
		for(i = l; i <= filaycolumna; i = i + 1)
		{
			for(j = l; j <= filaycolumna; j = j + 1)
			{
				matriz[i][j] = (matriz[k][k] * matriz[i][j] - matriz[k][j] * matriz[i][k] ) / matriz[k][k];
			}
		}
		determinante = determinante * matriz[k+1][k+1];
	}
	cout << endl;
	cout << "\n\tDETERMINANTE = " << determinante << endl;
}

int main()
{
	string linea;
	int opcion;
	bool repite = true;
	
	do
	{
		do
		{
			menu();
			getline(cin, linea);
			opcion = atoi(linea.c_str());
			
			switch( opcion )
			{
	            case 1:
	            {
    				cout << "" <<endl;
					cout << "\t------------  OPCION 01  ------------" <<endl;
    				cout << "" <<endl;
    				
	            	opcion01_SumadeMatrices();
	            	
					break;
				}
				
				case 2:
				{
    				cout << "" <<endl;
					cout << "\t------------  OPCION 02  ------------" <<endl;
    				cout << "" <<endl;
    				
					opcion02_RestadeMatrices();
					
					break;
				}
				
				case 3:
				{
    				cout << "" <<endl;
					cout << "\t------------  OPCION 03  ------------" <<endl;
    				cout << "" <<endl;
    				
					opcion03_MultiplicaciondeMatrices();
					
					break;
				}
				
				case 4:
				{
    				cout << "" <<endl;
					cout << "\t------------  OPCION 04  ------------" <<endl;
    				cout << "" <<endl;
    				
					opcion04_Matriztraspuesta();
					
					break;
				}
				
				case 5:
				{
    				cout << "" <<endl;
					cout << "\t------------  OPCION 05  ------------" <<endl;
    				cout << "" <<endl;
    				
					opcion05_DeterminantedeunaMatriz();
					
					break;
				}
				
	            case 6:
	            {
	            	cout << "" <<endl;
	            	cout << "\t--------  FIN DEL PROGRAMA  ---------" <<endl;
	            	break;
				}
				
				default:
				{
					cout << "" <<endl;
	            	cout << "\t--------  OPCION NO VALIDA  ---------" <<endl;
	            	break;
				}
	        }
			
		}while(linea != "6");
		
		if (esEntero(linea))
		{
			repite = false;
		}
		else
		{
			cout << "" <<endl;
			cout << "\tNo has ingresado un valor entero." <<endl;
			cout << "\tIntentalo nuevamente" <<endl;
		}
		
	} while(repite);
	
	return 0;
}