#include <stdio.h>

// Fonction pour chiffrer un caract�re avec la cl�
int chiffrement(int caractere, int cle) {
    return (caractere ^ cle) + 1; // Effectue un XOR entre le caract�re et la cl�, ajoute 1 et renvoie le r�sultat
}

// Fonction pour d�chiffrer un caract�re avec la cl�
int dechiffrement(int chiffre, int cle) {
    return (chiffre - 1) ^ cle; // Soustrait 1 au chiffre, effectue un XOR entre le r�sultat et la cl� et renvoie le r�sultat
}

// Fonction pour convertir un caract�re en chiffre
int caractere_vers_chiffre(char caractere) {
    return (int) caractere; // Retourne le code ASCII du caract�re
}

// Fonction pour convertir un chiffre en caract�re
char chiffre_vers_caractere(int chiffre) {
    return (char) chiffre; // Retourne le caract�re correspondant au code ASCII
}

int main() {
    char phrase[1000], phrase_dechiffree[1000]; // Tableaux pour stocker la phrase � chiffrer et la phrase d�chiffr�e
    int cle = 43690; // Cl� de chiffrement
    int chiffres[1000], n, i; // Tableau pour stocker les chiffres repr�sentant chaque caract�re de la phrase

    // Lecture de la phrase � chiffrer
    printf("Entrez une phrase : ");
    fgets(phrase, 1000, stdin);

    // Suppression du caract�re de retour � la ligne de la fin de la cha�ne
    if (phrase[strlen(phrase) - 1] == '\n') {
        phrase[strlen(phrase) - 1] = '\0';
    }

    // Conversion des caract�res en chiffres
    n = strlen(phrase); // D�termine la longueur de la cha�ne de caract�res
    for (i = 0; i < n; i++) {
        chiffres[i] = chiffrement(caractere_vers_chiffre(phrase[i]), cle); // Convertit chaque caract�re en chiffre et chiffre le chiffre avec la cl�
    }

    // Affichage de la phrase chiffr�e
    printf("Phrase chiffree : ");
    for (i = 0; i < n; i++) {
        printf("%d ", chiffres[i]); // Affiche chaque chiffre
    }
    printf("\n");

    // D�chiffrement
    for (i = 0; i < n; i++) {
        chiffres[i] = dechiffrement(chiffres[i], cle); // D�chiffre chaque chiffre avec la cl�
    }

    // Conversion des chiffres en caract�res
    for (i = 0; i < n; i++) {
        phrase_dechiffree[i] = chiffre_vers_caractere(chiffres[i]); // Convertit chaque chiffre en caract�re
    }

    phrase_dechiffree[n] = '\0'; // Ajout du caract�re de fin de cha�ne

    // Affichage de la phrase d�chiffr�e
    printf("Phrase  apres dechiffrement : %s\n", phrase_dechiffree);

    return 0; // Indique que le programme s'est termin�
}
