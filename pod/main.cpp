#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

void z10nadowolny(vector <int> &tab, int pods, int wartosc)
{
    int i=0;
    cout << "liczba" << wartosc << endl;
    while(wartosc>0) {
        tab.push_back(wartosc % pods);
        cout << wartosc % pods;
        wartosc /= pods;
        i++;

    }
    cout << endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    int podstawa, i_zapytan;
    cin >> podstawa >> i_zapytan;
    int * liczby = new int[podstawa];
    int suma=0;
    for (int i = 0; i < podstawa; i++) {
        cin >> liczby[i];
        suma += liczby[i];
    }
    vector < int > zapytania;
    for (int i = 0; i < i_zapytan; i++) {
        int get;
        cin >> get;
        zapytania.push_back(get);
    }
    vector <int> tablica;
    cout << "suma: " << suma << endl;
    long long double pom= pow(podstawa, suma)-1;
    cout << "suma max: " <<  pom << endl;
    for (unsigned long i = pow(podstawa, suma)-1; i > 0 ; i--) {
        tablica.clear();
        bool znaleziono=0;
        if(i%(podstawa-1)==0){
            z10nadowolny(tablica, podstawa, i);
            cout << "rozmiar tablicy:" <<  tablica.size() << endl;
            int * kopia = new int[podstawa];
            for (int j = 0; j < i_zapytan; j++) {
                kopia[j]=liczby[j];
            }
            for (int j = 0; j < tablica.size(); j++){
                kopia[tablica[j]]--;
            }
            znaleziono=1;
            for (int j = 0;  j < i_zapytan; j++) {
                if(kopia[j]<0){
                    znaleziono=0;
                    break;
                }
            }
            delete [] kopia;
        }
        if(znaleziono)break;
    }
    for (int i = 0; i < i_zapytan; i++) {
        if(tablica.size()<=zapytania[i]) cout << "-1" << endl;
        else cout << tablica[zapytania[i]] << endl;
    }

}