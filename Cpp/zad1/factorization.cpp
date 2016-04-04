/*
    @OPIS

    Ten program znajduje czynniki pierwsze i wypisuje je,
    jeden pod drugim, rodzielone znakiem *.
    Parametramy sluza do ustalenia, jakich liczby chcemy
    znalezc czynniki.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

void print_vector(vector<long long>f_numbers) {
    for (auto value : f_numbers) {
        cout << value << endl;

        if (f_numbers.back()) {
            if (value != f_numbers.end()) {
                cout << "*" << endl;
            }
        }
    }
}

vector<long long> factors(long long number) {
    /* Znajduje czynniki pierwsze liczby */
    vector<long long> f_numbers;

    if ((abs(number) <= 1) && number != LLONG_MIN) { 
        f_numbers.push_back(number);
        return f_numbers;
    }

    if (number < 0) { 
        f_numbers.push_back(-1);

        if (number == LLONG_MIN) { 
            if (number % 2 == 0) {
                number = number/2;
                f_numbers.push_back(2);
            }
        }
        
        number = abs(number);
    }

    while (number % 2 == 0) { // Eliminuje dwojki
        number = number/2;
        f_numbers.push_back(2); 
    }

    long long x = 3;
    while (x <= sqrt(number)+1) { // Glowna petla
        if (number % x == 0) {
            f_numbers.push_back(x);
            number = number/x;
        } else {
            x += 2;
        }
    }
    
    if (x > sqrt(number)+1) { // Jesli liczba/czynnik okaze sie liczba pierwsza
        f_numbers.push_back(number);
    }

    return(f_numbers);
}

long long char_to_number(const char* ch_number) {
    /* Zamiana (argumentu) char na liczbe */
    try {
        long long number = stoll(ch_number);
        return number;
    } catch (std::invalid_argument) {
        throw invalid_argument("Argumentem musi byc liczba.");
    } catch (std::out_of_range) {
        throw invalid_argument("Liczba przekracza zakres.");
    }
}

int main(int argc, const char* argv[]) {
    /* 
    Program sprawdza czy wszystkie argumenty sa prawidlowe,
    dopiero wtedy zaczyna szukac czynniki 
    */

    vector<long long> numbers;

    if (argc < 2) { // Brak parametrow
        cerr << "Program znajduje czynniki pierwsze liczb z zarkesu" << endl;
        cerr << "<" << LLONG_MIN << ", " << LLONG_MAX << ">" << endl << endl;
        cerr << "Aby uzyc programu, w argumentach podaj liczby." << endl << endl;
        cerr << "./a.out <liczba1> <liczba2> <liczba3> <liczba4>" << endl;
    } else {
        
        for (int i = 1; i < argc; i++) { // Zamienia argumenty na long long
            numbers.push_back(char_to_number(argv[i]));
        }

    }

    for (long long number : numbers) { // Szuka czynnikow dla elementow vektora
        cout << number << endl;
        cout << "=" << endl;
        print_vector(factors(number));
        
        if (number != numbers.back()) {
            cout << endl;
        }
    }

    return 0;
}
