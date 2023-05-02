#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe qui représente un employé
class Employe {
public:
    Employe(string nom, string prenom, int nbConges) {
        this->nom = nom;
        this->prenom = prenom;
        this->nbConges = nbConges;
    }

    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    int getNbConges() { return nbConges; }
    void setNbConges(int nb) { nbConges = nb; }

private:
    string nom;
    string prenom;
    int nbConges;
};

// Classe qui représente une entreprise avec une liste d'employés
class Entreprise {
public:
    Entreprise() {}

    // Méthode pour ajouter un employé
    void ajouterEmploye(Employe emp) {
        employes.push_back(emp);
    }

    // Méthode pour afficher les employés de l'entreprise avec leur nombre de congés
    void afficherEmployes() {
        for (int i = 0; i < employes.size(); i++) {
            cout << employes[i].getNom() << " " << employes[i].getPrenom() << " : " << employes[i].getNbConges() << " jours de congé" << endl;
        }
    }

    // Méthode pour chercher un employé par son nom et prénom
    Employe* chercherEmploye(string nom, string prenom) {
        for (int i = 0; i < employes.size(); i++) {
            if (employes[i].getNom() == nom && employes[i].getPrenom() == prenom) {
                return &employes[i];
            }
        }
        return NULL;
    }

private:
    vector<Employe> employes;
};

int main() {
    Entreprise entreprise;

    // Demander à l'utilisateur les noms et prénoms des employés et leur nombre de congés
    int nbEmployes;
    cout << "Combien d'employes voulez-vous ajouter ? ";
    cin >> nbEmployes;
    for (int i = 0; i < nbEmployes; i++) {
        string nom, prenom;
        int nbConges;
        cout << "Nom de l'employe " << i + 1 << " : ";
        cin >> nom;
        cout << "Prénom de l'employe " << i + 1 << " : ";
        cin >> prenom;
        cout << "Nombre de congés de l'employe " << i + 1 << " : ";
        cin >> nbConges;
        entreprise.ajouterEmploye(Employe(nom, prenom, nbConges));
    }

    // Afficher les employés
    entreprise.afficherEmployes();


    return 0;
}