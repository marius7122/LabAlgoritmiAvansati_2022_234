# Problema Comisului Voiajor

Se dau n puncte in spatiu. Problema cere sa se gaseasca ordinea in care trebuie sa parcurgem orasele astfel incat sa trecem prin toate si distanta parcursa sa fie minima. Distanta dintre doua orase este distanta euclidiana dintre doua puncte

## Input
Pe prima linie se afla n, numarul de orase, iar pe urmatoarele n linii se afla cate doua numere reprezentand coordonatele unui oras.

## Output
Pe prima linie se va avisa distanta minima circuitului hamiltonian, iar pe a doua linie se va afisa ordinea in care vom parcurge orasele.

## Observatii
- Problema este NP-hard; solutiile sunt generate folosind backtracking

## Exemplu
| Input         | Output        | 
| ---          | ---          |
| 4 <br> 0 0 <br> -1 1 <br> 0 2 <br> 1 1 | 5.65 <br> 1 2 3 4 1
