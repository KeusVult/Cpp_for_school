#include <iostream>
#include <string>

using namespace std;

bool isValidPesel(const string &pesel){
    if(pesel.length() != 11) return false;
    
    int wagi[] = {1,3,7,9,1,3,7,9,1,3};
    int s = 0;

    for(int i = 0; i < 10; i++){
        s += (pesel[i] - '0') * wagi[i];
    }

    int r = (10 - (s%10)%10);
    return r == (pesel[10] - '0');
}
string getGender(const string &pesel){
    int genderDigit = pesel[9] - '0';
    return (genderDigit % 2 == 0) ? "Kobieta" : "Mężczyzna";
}
int main(){
    
    string pesel;
    
    cout << "Podaj numer pesel: ";
    cin >> pesel;

    if(isValidPesel(pesel)){
        cout << "Numer pesel jest poprawny." << endl;
        cout << "Płeć: " << getGender(pesel) << endl;
    } else {
        cout << "Numer PESEL jest niepoprawny" << endl;
    }

    return 0;
}
