#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de d�but de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";


  int fin;
  cin >> fin;


  /****************************************************
   * Compl�ter le code � partir d'ici
   ****************************************************/


  if (debut < 0 or debut > 24 or fin <0 or fin > 24 )
  {
    cout << "Les heures doivent �tre comprises entre 0 et 24 !" << endl;
  }
  else if (debut == fin)
  {
      cout << "Bizarre, vous n'avez pas lou� votre v�lo bien longtemps !" << endl;
  }

  else if (debut > fin)
  {
      cout << "Bizarre, le d�but de la location est apr�s la fin ..." << endl;

  }

  else
  {
      int unf(0);
      int deuxf(0);
      if(debut<= 7 and fin>= 17)
      {
          unf = (7-debut) + (fin - 17);
          deuxf = 10;
      }

      if(debut<= 7 and fin< 17)
      {
          unf = (7-debut) ;
          deuxf =  (fin - 17);
      }

      if(debut> 7 and fin>= 17)
      {
          unf = (fin - 17);
          deuxf = (17 - debut) ;
      }

      if(debut> 7 and fin>= 17)
      {
          unf = 0;
          deuxf = (fin - debut) ;
      }


    cout << "Vous avez lou� votre v�lo pendant" << endl;

    cout <<unf << " heure(s) au tarif horaire de "
          <<1 << " franc(s)" << endl;

    cout <<deuxf<< " heure(s) au tarif horaire de "
      <<2 << " franc(s)" << endl;

    cout << "Le montant total � payer est de " << unf + (deuxf)* 2
         << " franc(s)." << endl;
}
  /*******************************************
   * Ne rien modifier apr�s cette ligne.
   *******************************************/
  return 0;
}