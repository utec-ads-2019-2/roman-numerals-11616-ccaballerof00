#include <iostream>
#include <map>

using namespace std;

map<char,int> letras;

void convertir_romano(string &numero)
{
    int num = stoi(numero);
    numero.clear();
    int parte = num/1000;
    switch(parte)
    {
        case 0:
            break;
        case 1:
            numero+='M';
            break;
        case 2:
            numero = numero+'M'+'M';
            break;
        case 3:
            numero = numero + 'M' + 'M' + 'M';
            break;
    }
    parte = num%1000 / 100;
    switch(parte)
    {
        case 0:
            break;
        case 1:
            numero += 'C';
            break;
        case 2:
            numero = numero + 'C' + 'C';
            break;
        case 3:
            numero = numero + 'C' + 'C' + 'C';
            break;
        case 4:
            numero = numero + 'C' + 'D';
            break;
        case 5:
            numero +='D';
            break;
        case 6:
            numero = numero + 'D' + 'C';
            break;
        case 7:
            numero = numero + 'D' + 'C' + 'C';
            break;
        case 8:
            numero = numero + 'D' + 'C' + 'C' + 'C';
            break;
        case 9:
            numero = numero + 'C' + 'M';
            break;
    }
    parte = num%100 / 10;
    switch(parte)
    {
        case 0:
            break;
        case 1:
            numero += 'X';
            break;
        case 2:
            numero = numero + 'X' + 'X';
            break;
        case 3:
            numero = numero + 'X' + 'X' + 'X';
            break;
        case 4:
            numero = numero + 'X' + 'L';
            break;
        case 5:
            numero +='L';
            break;
        case 6:
            numero = numero + 'L' + 'X';
            break;
        case 7:
            numero = numero + 'L' + 'X' + 'X';
            break;
        case 8:
            numero = numero + 'L' + 'X' + 'X' + 'X';
            break;
        case 9:
            numero = numero + 'X' + 'C';
            break;
    }
    parte = num%10;
    switch(parte)
    {
        case 0:
            break;
        case 1:
            numero += 'I';
            break;
        case 2:
            numero = numero + 'I' + 'I';
            break;
        case 3:
            numero = numero + 'I' + 'I' + 'I';
            break;
        case 4:
            numero = numero + 'I' + 'V';
            break;
        case 5:
            numero +='V';
            break;
        case 6:
            numero = numero + 'V' + 'I';
            break;
        case 7:
            numero = numero + 'V' + 'I' + 'I';
            break;
        case 8:
            numero = numero + 'V' + 'I' + 'I' + 'I';
            break;
        case 9:
            numero = numero + 'I' + 'X';
            break;
    }
}

void convertir_arabigo(string &numero)
{
    int num = 0;
        for(int i = 0; i < numero.length();i++)
        {
            if(i == numero.length()-1)
            {
                num += letras[numero[i]];
                break;
            }
            if(letras[numero[i]]>=letras[numero[i+1]])
            {
                num += letras[numero[i]];
            }
            else
            {
                num-=letras[numero[i]];
            }
        }
        numero = to_string(num);
}

int main()
{
    letras['I']=1;
    letras['V']=5;
    letras['X']=10;
    letras['L']=50;
    letras['C']=100;
    letras['D']=500;
    letras['M']=1000;
    string inp;
    while(cin>>inp)
    {
        if(isdigit(inp[0]))
        {
            convertir_romano(inp);
        }
        else
        {
            convertir_arabigo(inp);
        }
        cout<<inp;
        cout<<endl;
    }
}

