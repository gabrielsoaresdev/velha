#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

//Prototipos
void print_table();
void mudar_vez();
char verificar_vencedor();
void input();
bool marcar(int n);


//Globais
int _numero_jogadas;
char _table[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char _vez = '0';

int main (void) {
	setlocale(LC_ALL, "portuguese");
    _vez = 'X';
    while(verificar_vencedor() == '0') {
        system("clear");
        print_table();
        input();
        mudar_vez();
    }

    system("clear");
    print_table();

    switch (verificar_vencedor()) {
        case 'V':
            cout << "Deu velha!" << endl;
            break;
        case 'X':
            cout << "VENCEU o X" << endl;
            break;
        case 'O':
            cout << "VENCEU O Y" << endl;
            break;
        default:
            break;
    }

    cout << "Pressione qualquer tecla para sair..." << endl;
    getchar();
    return 0;
}

void print_table () {
    int i;
    for(i = 0; i < 3; i++) {
        cout << "  " << _table[i][0] << " | " << _table[i][1] << " | " << _table[i][2] << endl;
        if(i < 2)
            cout << "-------------\n";
    }
}

void mudar_vez() {
    if(_vez == 'X')
        _vez = 'O';
    else
        _vez = 'X';
    _numero_jogadas++;
}

char verificar_vencedor() {
    int i;
    for(i = 0; i < 3; i++) {
        if(_table[i][0] == _table[i][1] and _table[i][1] == _table[i][2] ) {
            return _table[i][0];
        }
        if(_table[0][i] == _table[1][i] and _table[1][i] == _table[2][i]) {
            return _table[0][i];
        }
    }

    if((_table[0][0] == _table[1][1] and _table[1][1] == _table[2][2])
    || (_table[0][2] == _table[1][1] and _table[1][1] == _table[2][0]))
        return _table[1][1];

    if(_numero_jogadas == 9)
        return 'V';

    return '0';
}

bool marcar(int n) {
    int x, y;
    if(n > 0 and n <= 3)
        x = 0;
    else if(n > 3 and n <= 6)
        x = 1;
    else if(n > 6 and n <= 9)
        x = 2;
    else {
        cout << "Posição não encontrada!\n";
        return false;
    }
    
    if(n == 1 or n == 4 or n == 7)
        y = 0;
    else if(n == 2 or n == 5 or n == 8)
        y = 1;
    else
        y = 2;
    
    if(_table[x][y] != 'X' and _table[x][y] != 'Y') {
        _table[x][y] = _vez;
    }
    else
        return false;
    return true;
        
}

void input() {
    cout << _vez << "-> Digite o número: ";
    int n;
    cin >> n;

    if(!marcar(n)) {
        cout << "A Posição informada não está disponível!\n";
        input();
    }
}
