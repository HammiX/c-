#include <iostream>
#include <fstream>
//#include <stdlib.h>
//#include <time.h>
#include <cmath>

using namespace std;
template <typename T>

class Excam{
public:
    T* Spisok;
    int Kolvo;
    int* ArrIMin;
    int* ArrIndex;
    Excam(char *file);
    void Out();
    void Output();
    //1
    int* SearchMinElement();
    //3
    int* MoreLeft();
    //4
    int CountElementAfterLastMin();

};

template <typename T>
Excam<T>::Excam(char *file){
    ifstream In(file);
    In>>Kolvo;
    Spisok=new T[Kolvo];
    for(int i=0;i<Kolvo;i++){
        In>>Spisok[i];
    }
}
template <typename T>
void Excam<T>::Output(){
    cout<<endl;
    for(int i=0;i<Kolvo;i++){
        cout<<Spisok[i]<<" ";
    }
    cout<<endl;
}
template <typename T>
void Excam<T>::Out(){
    ofstream Out("out+put.txt",ios::trunc);
    Out<<Kolvo<<"\n";
    for(int i=0;i<Kolvo;i++){
        Out<<Spisok[i]<<" ";
        cout<<Spisok[i]<<" ";
    }
    Out.close();
}
//1
template <typename T>
int* Excam<T>::SearchMinElement(){
    int Kmin=0;
    int iMin=0;
    for(int i=0;i<Kolvo;i++){
        if(Spisok[iMin]>Spisok[i] && Spisok[i]>0){//мэ
            iMin=i;
        }
    }
    for(int i=0;i<Kolvo;i++){
        if(Spisok[iMin]==Spisok[i]){
            Kmin++;
            ArrIMin=new int[Kmin];
            ArrIMin[Kmin]=i;
            //cout<<ArrIMin[Kmin]<<" ";
        }
    }
    cout<<"Минимальный элемент: "<<Spisok[iMin]<<" Его индекс: "<<iMin<<" Количество таких элементов: "<<Kmin;
    return ArrIMin;
}
//3
template <typename T>
int* Excam<T>::MoreLeft(){
    int k=0;
    cout<<"Список индексов элементов больших левого соседа: ";
    for(int i=Kolvo;i>0;i--){
        if(Spisok[i-1]<Spisok[i]){
            k++;
            ArrIndex=new int[k];
            ArrIndex[k]=i;
            cout<<ArrIndex[k]<<" ";
        }
    }
    return ArrIndex;
}
//4
template <typename T>
int Excam<T>::CountElementAfterLastMin(){
    int iMin=0;
    for(int i=0;i<Kolvo;i++){
        if((Spisok[iMin]>Spisok[i] && Spisok[i]>0)||Spisok[iMin]==Spisok[i]){
            iMin=i;
        }
    }
    return Kolvo-iMin-1;
}



int main()
{
    setlocale(LC_ALL,"Russian");
    //srand(time(0));
    Excam<double> *X=new Excam<double>("input.txt");
    X->Output();
    cout<<"1)\n ";
    X->SearchMinElement();
    cout<<"\n3)\n ";
    X->MoreLeft();
    cout<<"\n4)\n ";
    cout<<X->CountElementAfterLastMin();

    return 0;
}
