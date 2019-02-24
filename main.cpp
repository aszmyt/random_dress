#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

string sukienki[100];
int ile_sukienek=0;

void print()
{
    system("cls");
    for(int i=0;i<ile_sukienek;i++)
    {
        cout<<sukienki[i]<<endl;
    }
    cout<<endl<<"Aby wrocic do menu nacisnij enter"<<endl;
    getchar();
}

int load()
{
    ile_sukienek=0;
    string linia;
    fstream plik;
    plik.open("sukienki.txt", ios::in);
    if(!(plik.good()))
       {
           cout<<"nie ma sukienek do wyboru, wprowadz jakas"<<endl;
           return 0;
       }
    while(getline(plik,linia))
    {
        sukienki[ile_sukienek]=linia;
        ile_sukienek++;
    }
    plik.close();
    return 0;
}

void add()
{
    system("cls");
    string sukienka;
    fstream plik;
    plik.open("sukienki.txt", ios::out | ios::app);
    cout<<"jaka masz sukienke: ";
    while(getline(cin,sukienka))
    {
        break;
    }
    plik<<sukienka<<endl;
    plik.close();
    load();
    cout<<"Sukienka: "<<sukienka<<" zostala dodana"<<endl;
    Sleep(3000);
}

void suffle()
{
    system("cls");
    if(ile_sukienek!=0)
    {
        int tmp;
        srand(time(NULL));
        tmp=rand()%ile_sukienek;
        cout<<"wybor na dzis to: "<<sukienki[tmp];
        getchar();
        exit(0);
    }
    else
    {
        cout<<"nie masz zadnych, musisz dodac!"<<endl;
        getchar();
    }

}

int cut()
{
        while(true)
        {


        int wybor=0;
        system("cls");
        load();
        string tmp[ile_sukienek];
        for(int i=0;i<ile_sukienek;i++)
        {
            cout<<i+1<<". "<<sukienki[i]<<endl;
        }
        cout<<"Wybierz numer sukienki ktora chcesz usunac (aby wyjsc wpisz 0) \nWpisz numer: ";
        cin>>wybor;
        if(wybor>0)
        {
            wybor--;
            if(wybor >ile_sukienek) cout<<"Tego numeru nie ma" <<endl;
            else
            {
                for(int i=0;i<ile_sukienek-1;i++)
                {
                    if(i<wybor)
                    {
                        tmp[i]=sukienki[i];
                    }
                    else
                    {
                        tmp[i]=sukienki[i+1];
                    }
                }
                fstream plik;
                plik.open("sukienki.txt", ios::out);
                for(int i=0;i<ile_sukienek-1;i++)
                {
                    plik<<tmp[i]<<endl;
                }
                plik.close();
            }
        }
        else
        {
            return 0;
        }
    }
}

void menu()
{
    while(true){
        load();
        system("cls");
        char wybor;
        cout<<"Witam w menu"<<endl;
        cout<<"============"<<endl;
        cout<<"Wybierz opcje: "<<endl;
        cout<<"1. Sprawdz zbior sukienek"<<endl;
        cout<<"2. Dodaj nowa sukienke"<<endl;
        cout<<"3. Usun sukienke"<<endl;
        cout<<"4. Wylosuj sukienke na dzis"<<endl;
        cout<<"0. Wyjdz"<<endl;
        wybor=getch();
        switch(wybor)
        {
            case '1': print();        break;
            case '2': add();          break;
            case '3': cut();          break;
            case '4': suffle();       break;
            case '0': exit(0);        break;
            default: cout<< "wybierz inna opcje"<<endl;
        }
    }
}


int main()
{
    load();
    menu();
    getchar();
    return 0;
}
