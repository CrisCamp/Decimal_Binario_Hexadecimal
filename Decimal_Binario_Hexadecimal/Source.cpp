#include <iostream>
#include <sstream>

using namespace std;

class Conversor
{
private:
	int n, op1;
	string nh, nd;
public:
	Conversor(int n, int op1, string nh, string nd)
	{
		this->n = n;
		this->nh = nh;
		this->nd = nd;
		this->op1 = op1;
	}
	double potRec(double numero, long potencia)
	{
		if (potencia <= 0)
		{
			return 1;
		}
		else
		{
			return numero * potRec(numero, potencia - 1);
		}
	}

	void IntToBin()
	{
		string r;
		while (n != 0) {
			r += (n % 2 == 0 ? "0" : "1");
			n /= 2;
		}	
		cout << r;
	}

//http://programacionparacoccidio.blogspot.com/2012/12/convertir-numeros-decimales.html

	void convertir(string& hex, stringstream& stream, int numero) {
		int residuo;
		if (numero == 0 || numero == 1 || numero == 2 || numero == 3 ||
			numero == 4 || numero == 5 || numero == 6 || numero == 7 ||
			numero == 8	|| numero == 9) {
			stream << numero;
		}
		else {
			residuo = numero % 16;
			numero = numero / 16;
			convertir(hex, stream, numero);
			stream << residuo;
		}
		hex = stream.str();
	}

	void IntToHex(string nd)
	{
		int i = 0;
		string hex = "";
		int numero;
		numero = atoi(nd.c_str());//converir de String a Int
		stringstream stream;
		convertir(hex, stream, numero);
		nd = hex;
		hex = "";
		if (nd[i] == '1' && (nd[i + 1] == '0' || nd[i + 1] == '1' || nd[i + 1] == '2' || nd[i + 1] == '3' || nd[i + 1] == '4' || nd[i + 1] == '5'))
		{
			i++;
			cout << "1";
		}
		else if (nd[i] == '0')
		{
			i++;
		}
		do {
			if (nd[i] == '1' && nd[i + 1] == '0') {
				i += 2;
				hex += 'A';
			}
			else if (nd[i] == '1' && nd[i + 1] == '1') {
				i += 2;
				hex += 'B';
			}
			else if (nd[i] == '1' && nd[i + 1] == '2') {
				i += 2;
				hex += 'C';
			}
			else if (nd[i] == '1' && nd[i + 1] == '3') {
				i += 2;
				hex += 'D';
			}
			else if (nd[i] == '1' && nd[i + 1] == '4') {
				i += 2;
				hex += 'E';
			}
			else if (nd[i] == '1' && nd[i + 1] == '5') {
				i += 2;
				hex += 'F';						 
			}									 
			// ejemplo
			// el numero 257 al ser dividido entre 16 da como resultado 16 y un residuo 1,									 
			// por cada residuo abtenido el valor sera enviado a "stream" o tambien cuando 
			// la condicion sea verdadera en la funcion se dara el valor a stream y stream 
			// dara el valor a "hex" a su vez "hex" sede su valor a "nd" que es la variable que  
			// será evaluada conteniendo todos los residuos del valor original (257)
			// 
			//	número decimal		 2    5    7 
			//	residuos			 1    0    1  --> if (i++) = 1 --> switch [i++] = 2
			//	posicion -> [i]		[0]  [1]  [2]
			//	el uno de la posicion 0 se imprime en pantalla de una manera crakeada en la sentencia if
			// 
			// cuando entra al swicth ahora la posicion que se evaluara es la posision "2"
			// tambien se puede poner un if - else justo donde esta este comentario para evitar el <cout << "1">
			else
			{
				switch (nd[i++]) // se evalua el valor de la posicion --> residuos
				{
					case '0': hex += '0'; break;
					case '1': hex += '1'; break;
					case '2': hex += '2'; break;
					case '3': hex += '3'; break;
					case '4': hex += '4'; break;
					case '5': hex += '5'; break;
					case '6': hex += '6'; break;
					case '7': hex += '7'; break;
					case '8': hex += '8'; break;
					case '9': hex += '9'; break;
				}
			}
		} while (nd[i] != '\0');
		cout << hex;
	}

	void HexToBin()
	{
		int i = 0, x0 = 0;
		string x;
		while (nh[i]) 
		{
			switch (nh[i])
			{
				case '0':
					x += "0000";
					//cout << "0000";
					break;
				case '1':
					x += "0001";
					//cout << "0001";
					break;
				case '2':
					x += "0010";
					//cout << "0010";
					break;
				case '3':
					x += "0011";
					//cout << "0011";
					break;
				case '4':
					x += "0100";
					//cout << "0100";
					break;
				case '5':
					x += "0101";
					//cout << "0101";
					break;
				case '6':
					x += "0110";
					//cout << "0110";
					break;
				case '7':
					x += "0111";
					//cout << "0111";
					break;
				case '8':
					x += "1000";
					//cout << "1000";
					break;
				case '9':
					x += "1001";
					//cout << "1001";
					break;
				case 'A':
				case 'a':
					x += "1010";
					//cout << "1010";
					break;
				case 'B':
				case 'b':
					x += "1011";
					//cout << "1011";
					break;
				case 'C':
				case 'c':
					x += "1100";
					//cout << "1100";
					break;
				case 'D':
				case 'd':
					x += "1101";
					//cout << "1101";
					break;
				case 'E':
				case 'e':
					x += "1110";
					//cout << "1110";
					break;
				case 'F':
				case 'f':
					x += "1111";
					//cout << "1111";
					break;
				default:
					cout << "\nInvalid hexadecimal digit "
						<< nh[i];
			}
			i++;
		}
		if (op1 == 5)
		{
			x0 = stoi(x);
			BinToInt(x0);
		}
		else
		{
			cout << "\n" << x << "\n";
		}
	}

	void BinToInt(int n)
	{
		ostringstream a;
		string x0;
		int exp, digito;
		double decimal;
		exp = 0;
		decimal = 0;
		while (((int)(n / 10)) != 0)
		{
			digito = (int)n % 10;
			decimal = decimal + digito * potRec(2.0, exp);
			exp++;
			n = (int)(n / 10);
		}
		decimal = decimal + n * potRec(2.0, exp);
		if (op1 == 4)
		{
			a << decimal;
			x0 = a.str();
			IntToHex(x0);
		}
		else
		{
			cout << endl << "Decimal: " << decimal << endl;
		}
	}
};
class Inicio
{
private:
	int n, op1, op2;
	string nh, nd; //la variable nh y nd sirve para convertir numeros binarios y decimales a hexadecimales
public:
	Inicio()
	{
		n = 0;
		op1 = 0;
		op2 = 0;
		nh = "";
		nd = "";
	}
	void run()
	{
		do {
			cout << "Bienvenido introduzca la opcion que desea seleccionar"
				"\n1. Decimales a binarios"
				"\n2. Decimales a hexagecimales"
				"\n3. Binarios a decimales"
				"\n4. Binarios a hexagecimales"
				"\n5. Hexagecimales a decimales"
				"\n6. Hexagecimales a binarios" << endl;
			cin >> op1;
			system("cls");

			Conversor* dato;

			switch (op1)
			{
			case 1:
				cout << "Introduzca un numero Decimal: " << endl;
				cin >> n;

				dato = new Conversor(n, op1, nh, nd);
				dato->IntToBin();

				break;

			case 2:
				cout << "Introduzca un numero Decimal: " << endl;
				cin >> nd;

				dato = new Conversor(n, op1, nh, nd);
				dato->IntToHex(nd);

				break;

			case 3:
				cout << "Introduzca un numero Binario: " << endl;
				cin >> n;

				dato = new Conversor(n, op1, nh, nd);
				dato->BinToInt(n);

				break;

			case 4:
				cout << "Introduzca un numero Binario: " << endl;
				cin >> n;

				dato = new Conversor(n, op1, nh, nd);
				dato->BinToInt(n);
				break;

			case 5:
				cout << "Introduzca un numero Hexagesimal: " << endl;
				cin >> nh;

				dato = new Conversor(n, op1, nh, nd);
				dato->HexToBin();

				break;

			case 6:
				cout << "Introduzca un numero Hexagesimal: " << endl;
				cin >> nh;

				dato = new Conversor(n, op1, nh, nd);
				dato->HexToBin();

				break;
			}
			cout << "\n\nIntroduzca la opcion\n1. Seguir en el programa\n2. Salir del programa" << endl;
			cin >> op2;
			system("cls");
		} while (op2 != 2);
	}
};
int main()//llama a todas las funciones
{
	Inicio menu;
	menu.run();
}