#include <stdio.h>

// Fonction pour chiffrer un caractère avec la clé
int chiffrement(int caractere, int cle) {
    return (caractere ^ cle) + 1; // Effectue un XOR entre le caractère et la clé, ajoute 1 et renvoie le résultat
}

// Fonction pour déchiffrer un caractère avec la clé
int dechiffrement(int chiffre, int cle) {
    return (chiffre - 1) ^ cle; // Soustrait 1 au chiffre, effectue un XOR entre le résultat et la clé et renvoie le résultat
}

// Fonction pour convertir un caractère en chiffre
int caractere_vers_chiffre(char caractere) {
    return (int) caractere; // Retourne le code ASCII du caractère
}

// Fonction pour convertir un chiffre en caractère
char chiffre_vers_caractere(int chiffre) {
    return (char) chiffre; // Retourne le caractère correspondant au code ASCII
}

int main() {
    char phrase[1000], phrase_dechiffree[1000]; // Tableaux pour stocker la phrase à chiffrer et la phrase déchiffrée
    int cle = 43690; // Clé de chiffrement
    int chiffres[1000], n, i; // Tableau pour stocker les chiffres représentant chaque caractère de la phrase

    // Lecture de la phrase à chiffrer
    printf("Entrez une phrase : ");
    fgets(phrase, 1000, stdin);

    // Suppression du caractère de retour à la ligne de la fin de la chaîne
    if (phrase[strlen(phrase) - 1] == '\n') {
        phrase[strlen(phrase) - 1] = '\0';
    }

    // Conversion des caractères en chiffres
    n = strlen(phrase); // Détermine la longueur de la chaîne de caractères
    for (i = 0; i < n; i++) {
        chiffres[i] = chiffrement(caractere_vers_chiffre(phrase[i]), cle); // Convertit chaque caractère en chiffre et chiffre le chiffre avec la clé
    }

    // Affichage de la phrase chiffrée
    printf("Phrase chiffree : ");
    for (i = 0; i < n; i++) {
        printf("%d ", chiffres[i]); // Affiche chaque chiffre
    }
    printf("\n");

    // Déchiffrement
    for (i = 0; i < n; i++) {
        chiffres[i] = dechiffrement(chiffres[i], cle); // Déchiffre chaque chiffre avec la clé
    }

    // Conversion des chiffres en caractères
    for (i = 0; i < n; i++) {
        phrase_dechiffree[i] = chiffre_vers_caractere(chiffres[i]); // Convertit chaque chiffre en caractère
    }

    phrase_dechiffree[n] = '\0'; // Ajout du caractère de fin de chaîne

    // Affichage de la phrase déchiffrée
    printf("Phrase  apres dechiffrement : %s\n", phrase_dechiffree);

    return 0; // Indique que le programme s'est terminé
}
