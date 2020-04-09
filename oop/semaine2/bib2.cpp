#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Auteur
{
public:
     Auteur(string n, bool p = false) : nom(n), prime(p) {}
     Auteur(Auteur &a) = delete;

     string getNom() const
     {
          return nom;
     }
     bool getPrime() const
     {
          if (prime)
          {
               return true;
          }
     }

private:
     string nom;
     bool prime;
};

class Oeuvre
{
public:
     ~Oeuvre()
     {
          cout << "L’oeuvre " << getTitre() << ", " << getAuteur().getNom() << ", en " << getLangue() << " n’est plus disponible." << endl;
     }

     Oeuvre(Oeuvre &o) = delete;

     Oeuvre(string tit, Auteur &a, string lan) : titre(tit), auteur(a), langue(lan) {}

     string getTitre() const
     {
          return titre;
     }
     const Auteur &getAuteur() const
     {
          return auteur;
     }
     void affiche() const
     {
          cout << getTitre() << ", " << getAuteur().getNom() << ", en " << getLangue(); //<< endl;
     }

     string getLangue() const
     {
          return langue;
     }

private:
     string titre;
     const Auteur &auteur;
     string langue;
};

class Book
{
public:
     Book(Book &o) = delete;

     Book(string title) : title(title) {}

     string getTitre()
     {
          return title;
     }

private:
     string title;
};

class Exemplaire
{
public:
     Exemplaire(Oeuvre &o) : oeuvre(o) { cout << "new copy from a book" << endl; }
     Exemplaire(Exemplaire &e) : oeuvre(e.oeuvre) { cout << "Copy from another copy" << endl; }

     void affiche() const
     {
          cout << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
     }
     const Oeuvre &getOeuvre()
     {
          return oeuvre;
     }

private:
     Oeuvre &oeuvre;
};

class Bibliotheque
{
public:
     ~Bibliotheque()
     {
          cout << "La bibliothèque " << getNom() << " ferme ses portes et détruit ses livres." << endl;
     }

     Bibliotheque(string s) : nom(s) { cout << "La bibliothèque " << getNom() << " est ouverte !" << endl; }

     string getNom()
     {
          return nom;
     }

     void stocker(Oeuvre &o, int nombre = 1)
     {
          for (int i(0); i < nombre; i++)
          {
               v.push_back(Exemplaire(o));
          }

          return;
     }
     void lister_exemplaires(string langue1 = "")
     {

          if (langue1 == "")
          {
               for (int i(0); i < v.size(); i++)
               {
                    v[i].affiche();
                    cout << endl;
               }
          }
          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getLangue() == langue1)
               {
                    v[i].affiche();
                    cout << endl;
               }
          }
     }

     int compter_exemplaires(Oeuvre &o)
     {
          int count(0);
          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getTitre() == o.getTitre())
               {
                    ++count;
               }
          }
          return count;
     }
     void afficher_auteurs(bool b = false) 
     {

          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getAuteur().getPrime() == b)
               {
                    cout << v[i].getOeuvre().getAuteur().getNom() << endl;
               }
          }
     }

private:
     string nom;
     vector<Exemplaire> v;
};