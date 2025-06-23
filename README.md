# Aplicație pentru achiziționarea și gestionarea biletelor la cinema

Acest proiect este o aplicație simplă, dezvoltată în cadrul materiei **Programare Orientată pe Obiect (POO)**, care permite achiziționarea biletelor la film și gestionarea rezervărilor.

## Funcționalități și structură

- **Clase principale:**  
  - `Persoana`  
  - `Film`  
  - `Cinema`  
  Toate variabilele au fost declarate ca private pentru a asigura încapsularea datelor.

- **Meniu de interacțiune:**  
  O funcție `introducere` afișează un mesaj și meniul principal.

- **Selectarea tipului de cinema:**  
  Funcții pentru alegerea și afișarea tipului de cinema folosind operatorii supraincarcați `>>` și `<<`.  
  A fost implementat și un constructor de copiere pentru obiectul `Cinema`.

- **Gestionarea biletelor:**  
  Operatorii `-` și `<` au fost supraincarcați pentru a verifica dacă numărul de bilete selectate este mai mic decât capacitatea maximă a sălii (50 bilete), afișând biletele rămase disponibile.  
  Biletele selectate sunt stocate într-un vector `sala`, unde fiecare bilet rezervat este marcat cu valoarea 1.

- **Afișarea detaliilor rezervării:**  
  Prin utilizarea mai multor metode și a unei funcții `friend`, se afișează un meniu final cu detaliile rezervării curente.

- **Extensibilitate:**  
  În final, este oferită opțiunea de a citi un număr `n` de obiecte (rezervări), permițând efectuarea mai multor rezervări consecutive prin modificarea codului în `main`.

## Cum se folosește

Pentru a testa aplicația:  
- Se poate utiliza meniul interactiv pentru o singură rezervare.  
- Pentru multiple rezervări, se poate activa citirea mai multor obiecte în funcția `main`, folosind variabilele `n` și `display_menu`.
