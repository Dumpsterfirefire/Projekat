#include <bits/stdc++.h>
#include <windows.h> // za Sleep() i system("cls")

using namespace std;

const int WIDTH = 10;   // širina table
const int HEIGHT = 10;  // visina table

int aiX = 8, aiY = 8;   // početna pozicija AI zmije
int foodX, foodY;       // pozicija hrane
int aiScore = 0;        // rezultat AI

// Funkcija za generisanje nove hrane na nasumičnoj lokaciji
void spawnFood() 
{
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

// Funkcija za crtanje table u konzoli
void drawGrid() 
{
    system("cls");  // čisti ekran (Windows)

    for (int y = 0; y < HEIGHT; y++) 
    {
        for (int x = 0; x < WIDTH; x++) 
        {
            if (x == aiX && y == aiY) cout << 'A';      // AI zmija
            else if (x == foodX && y == foodY) cout << 'F'; // Hrana
            else cout << '.';                            // Prazno polje
        }
        cout << '\n';
    }
    cout << "\nRezultat AI: " << aiScore << "\n";
}

// Funkcija kojom AI pomera zmiju prema hrani
void updateAI() 
{
    if (aiX < foodX) aiX++;            // ako je AI levo od hrane, pomeri desno
    else if (aiX > foodX) aiX--;       // ako je AI desno od hrane, pomeri levo
    else if (aiY < foodY) aiY++;       // ako je AI iznad hrane, pomeri dole
    else if (aiY > foodY) aiY--;       // ako je AI ispod hrane, pomeri gore
}

// Provera da li je AI stigao do hrane
bool checkWin() 
{
    if (aiX == foodX && aiY == foodY) {
        aiScore++;    // AI je pojeo hranu - uvećaj rezultat
        return true;
    }
    return false;
}

int main() 
{
    srand(time(0));  // inicijalizacija generatora nasumičnih brojeva
    spawnFood();     // postavi prvu hranu

    while (true) 
    {
        drawGrid();   // iscrtaj tablu

        updateAI();   // pomeri AI prema hrani

        if (checkWin()) 
        {  // ako AI dođe do hrane
            spawnFood();   // postavi novu hranu
        }

        Sleep(150);   // pauza od 150 milisekundi (usporava petlju)
    }

    return 0;
}
