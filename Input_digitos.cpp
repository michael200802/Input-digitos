/*El error consiste en que la funcion input no funciona*/

#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

//Funcion gotoxy
//Con esta funcion podemos ubicarnos en una parte de la consola
void gotoxy(int x,int y);

//La funcion input, la mas importante.
void input(string&num,int&x,int&y,int&cf);

int main(){
	//Declaramos las variables
    string num;
    int x = 17, y = 0, cf = 0;
    //Imprimimos el texto
    cout<<"Ingrese su edad: ";
    //Se llama la funion input
    input(num,x,y,cf);
    //Borramos el texto
    system("cls");
    if(atoi(num.c_str()) < 18){
    	cout<<"Eres menor de edad.";
	} 
	else
	{
		cout<<"Eres mayor de edad.";
	}
	getch();
    return 0;
}

void gotoxy(int x,int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwpos;

    dwpos.X = x;
    dwpos.Y = y;

    SetConsoleCursorPosition(hcon,dwpos);
}

//num es el string que sera modificado y guardara el valor
//x es la posicion en la consola (columna)
//y es la posicion en la consola (fila)
/*cf indica con que tecla se termina el input
  0 es para ' ' y '\n
  1 es para ' '
  2 es para '\n'*/

void input(string&num,int&x,int&y,int&cf)
{
    //c guarda la posicion de i
    int c = 0;
    //p guarda la extencion de la string y en que posicion se guarda cada numero
    int p = 0;

    //Ciclo infinito, usado para repetir el for cuantas veces sea nesesario
    while (true)
    {
        //Aumenta el valor de i en busca de la tecla pulsada
        for (unsigned char i = 0; i < 255; i++)
        {
            //Se comprueba si se ha encontrado la tecla pulsada
            if(GetAsyncKeyState(i) == -32767)
            {
                switch (c)
                {
                    //En este switch se comprueba cual es la tecla pulsada
                    //En el caso de que no se haya tocado la tecla de un numero se lo guardara en num
                    //y aumentara el valor de p en 1
                case 48:
                    cout<<"0";
                    
                    num[p] = '0';
                    
                    p = p + 1;
                    break;
                case 49:
                    cout<<"1";
                    
                    num[p] = '1';
                    
                    p = p + 1;
                    break;
                case 50:
                    cout<<"2";
                    
                    num[p] = '2';
                    
                    p = p + 1;
                    break;
                case 51:
                    cout<<"3";
                    
                    num[p] = '3';
                    
                    p = p + 1;
                    break;
                case 52:
                    cout<<"4";
                    
                    num[p] = '4';
                    
                    p = p + 1;
                    break;
                case 53:
                    cout<<"5";
    
                    num[p] = '5';
                    
                    p = p + 1;
                    break;
                case 54:
                    cout<<"6";
                    
                    num[p] = '6';
                    
                    p = p + 1;
                    break;
                case 55:
                    cout<<"7";
                    
                    num[p] = '7';
                    
                    p = p + 1;
                    break;
                case 56:
                    cout<<"8";
                    
                    num[p] = '8';
                    
                    p = p + 1;
                    break;
                case 57:
                    cout<<"9";
                    
                    num[p] = '9';

                    p = p + 1;
                    break;
                //Si c es igual a 8, se ha tocado la tecla back
                case 8:
                    //Primero se comprobara si p es diferente de cero, 
                    //para saber si hay almenos un digito que borrar
                    if(p != 0)
                    {
                        //Se restara a p en 1
                        p = p - 1;
                        //Se usa a gotoxy para volver un espacio hacia atras
                        gotoxy(x+p,y);
                        //Se pone un espacio para borra el caracter en especifico
                        cout<<" ";
                        //Se usa a gotoxy para volver un espacio hacia atras
                        gotoxy(x+p,y);
                    }
                    break;
                }


                //Si cf == 1
                //Y se ha ingresado almenos un digito (p != 0)
				if(cf == 1 && p != 0)
                {
                    //Si c == 32
                    //El usuario ha pulsado la tecla space
                    if (c == 32)
                    {
                        //x aumenta en uno, pues, nos hemos dezplazado en una columna
                        x = x + 1;
                        //Se imprime un espacio
                        cout<<" ";
                    }
                    else
                        {
                        //El usuario no ha pulsado space asi que c se iguala a cero
                        c = 0;
                    }
                    
                }
                //Si cf == 2
                //Y se ha digitado almenos un digito (p != 0)
                if (cf == 2 && p != 0)
                {
                    //Si c == 10
                    //El usuario pulsado la tecla enter
                    if (c == 10)
                    {
                        //y aumenta en uno, pes, nos hemos dezplazado en una fila
                        y = y + 1;
                        //x es cero pues, ahora estamos en la columna 0
                        x = 0;
                        //Imprimimos el endl
                        cout<<endl;
                    }
                    else
                    {
                        c = 0;
                    }
                    
                }
                if (cf == 0 && p != 0)
                {
                    if (c == 32)
                    {
                        //x aumenta en uno, pues, nos hemos desplazado un espacio
                        x = x + 1;
                        //se imprime el espacio
                        cout<<" ";
                    }
                    else
                        {
                        c = 0;
                    }

                    if (c == 10)
                    {
                        //y aumenta en uno, pues, nos hemos dezplazado una fila mas
                        y = y + 1;
                        //x es igual a 0, pues, ahora estamos en la columna 0
                        x = 0;
                        //se imprime el endl
                        cout<<endl;
                    }
                    else
                    {
                        //No se toco la tecla enter
                        //c se iguala a cero, para prepararlo para el siguiente ciclo for
                        c = 0;
                    }                    
                }
                //Hemos encontrado la tecla que pulsamos, por lo tanto se termina el ciclo for
                break;
            }
            //Aumentamos el valor de c
            c = c + 1;
        }
        
        //Si cf == 1
        //Y se ha digitado como minimo un digito (p != 0)
        if (cf == 1 && p != 0)
        {
            //Y c == 32
            //Eso quiere decir que hemos pulsado la tecla space
            if (c == 32)
            {
                //Rompemos el ciclo while
                break;
            }
            
        }
        //Si cf == 2
        //Y se ha digitado como minimo un digito (p != 0)
        if (cf == 2 && p != 0)
        {
            //Y c == 10
            //Eso quiere decir que hemos pulsado la tecla enter
            if (c == 10)
            {
                //Rompemos el ciclo while
                break;
            }
            
        }
        //Si cf == 0
        //Y se ha digitado como minimo un digito (p != 0)
        if (cf == 0 && p != 0)
        {
            //Si c == 32 o c == 10
            if(c == 32 || c == 10)
            {
                //Rompemos el ciclo while
                break;
            }
        }

    }

    //A x se le suma la longitud del array
    x = x + p;
    //Declaramos un array de caracteres
    char aux[num.length()];

    //Guardamos los valores que necesitamos en aux
    for (int i = 0; i < p; i++)
    {
        aux[i] = num[i];
    }
    //Reiniciamos num
    num = "";
    //num es igual a aux
    num = aux;
}
