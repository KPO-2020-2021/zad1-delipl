#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
  Trzeba zmienić funkcję void ZamienNaPodkreslenie(char* Temp) na char* ZamienNaPodkreslenie(char* Temp) [75]
  ponieważ nie można zmienić litery pod wskaźnikiem. Trzeba zamienić cały ciąg i wywołać funkcję w przypisaniu. [151]
  Zwolnienie pamięci pod wskaźnikiem [161]
*/


/*
 *  Liczy ilosc wystapien znaku "spacja"
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) tekstem. 
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            ilosc spacji.
 */
int PoliczSpacje(char* Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (*Tekst == ' ') ++Ilosc;
  return Ilosc;
}


/*
 * Wyznacza dlugosc najdluzszego slowa w tekscie.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) tekstem. 
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 */
int RozmiarNajdluzszegoSlowa(char* Tekst)
{
  int DlugoscMaks = 0, DlugoscRob;
  char *Slowo = NULL;

  for (; *Tekst; ++Tekst) {
    if (isspace(*Tekst)) {
      if (!Slowo) continue;
      DlugoscRob = Tekst - Slowo;
      if (DlugoscMaks < DlugoscRob) DlugoscMaks = DlugoscRob;
      Slowo = 0L;
      continue;
    }
    if (!Slowo) Slowo = Tekst;
  }
  return DlugoscMaks;
}



/*
 * Zamienia wszystkie spacje znajdujace sie w tekscie na znak podkreslenia.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 */
char* ZamienNaPodkreslenie(char* Temp)
{
  int size = strlen(Temp)+1;
  char * Tekst = (char*) malloc(size*sizeof(char));
  for(int i = 0; i < size; i++){
    if(Temp[i] == ' ') Tekst[i] = '_';
    else Tekst[i] = Temp[i];
  }
  return Tekst;
}



/*
 * Oblicza ilosc wystapien malych liter.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 *
 *  Wartosc zwracana:
 *    Ilosc malych liter.
 */
int IloscMalychLiter(char *Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (islower(*Tekst)) ++Ilosc;
  return Ilosc;
}


/*
 * Oblicza ilosc wystapien wielkich liter.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 *
 *  Wartosc zwracana:
 *    Ilosc wielkich liter.
 */
int IloscWielkichLiter(char *Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (isupper(*Tekst)) ++Ilosc;
  return Ilosc;
}



int main()
{
  char *Napis = "Jak dobrze jest wstac skoro swit. Jutrzenki blask ...";
  int IloscSpacji;
  int DlugoscSlowaXXX;
  int IloscMaLiter = 0;
  int IloscWiLiter = 0;

  printf("\n------------------------------\n");
  printf(" Statystyka dla tekstu: '%s'\n\n",Napis);


  IloscSpacji = PoliczSpacje(Napis);
  DlugoscSlowaXXX = RozmiarNajdluzszegoSlowa(Napis);
  Napis = ZamienNaPodkreslenie(Napis);
  IloscMaLiter = IloscMalychLiter(Napis);
  IloscWiLiter = IloscWielkichLiter(Napis);

  printf("               Ilosc spacji: %i\n",IloscSpacji);
  printf("         Ilosc malych liter: %i\n",IloscMaLiter);
  printf("       Ilosc wielkich liter: %i\n",IloscWiLiter);
  printf(" Rozmiar najdluzszego slowa: %i\n",DlugoscSlowaXXX);
  printf(" Tekst z podkresleniami: '%s'\n",Napis);
  printf("\n");
  free(Napis);
  return 0;
}
