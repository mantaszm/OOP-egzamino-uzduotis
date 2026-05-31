# OOP egzamino užduotis — `std::string` ir asociatyvūs konteineriai

Papildoma objektinio programavimo užduotis, skirta panagrinėti, kodėl **asociatyvūs
konteineriai** (`std::map`, `std::set`) tam tikroms užduotims yra patogesni ir
efektyvesni už sekos konteinerius: elementai į juos įrašymo metu iškart „surūšiuojami“,
todėl paieška, skaičiavimas ir unikalumo užtikrinimas tampa paprasti.

Programa apdoroja tekstinį failą ir atlieka tris uždavinius, kurių rezultatus įrašo į
atskirus išvesties failus.

## Naudojami konteineriai

| Konteineris | Kur naudojamas |
|-------------|----------------|
| `std::map<std::string,int>` | žodžių skaičiavimas |
| `std::map<std::string,std::set<int>>` | cross-reference | kiekvienam žodžiui — unikalių, surūšiuotų eilučių numerių aibė |
| `std::set<std::string>` | URL sąrašas |
| `std::string` | viso teksto apdorojimas |

## Failų struktūra

```
.
├── main.cpp        # meniu ir funkcijų iškvietimas
├── funkcijos.h     # visa apdorojimo logika
├── README.md
└── .gitignore
```

## Kompiliavimas

Projektui reikalingas **C++17** standartas (naudojamas `<filesystem>`).

> projektas pritaikytas **Windows** aplinkai.

Windows (MinGW / g++):

```bash
g++ -std=c++17 main.cpp -o programa.exe
```

## Paleidimas

Paleidus programą rodomas meniu:

```
Pasirinti funkcija:
1 - Suskaiciuoti pasikartojima
2 - Cross-reference lentele
3 - URL suradimas
4 - Visos funkcijos
```

Pasirinkus skaičių, programa paprašo įvesties failo pavadinimo (pvz. `tekstas.txt`),
kuris turi būti tame pačiame kataloge kaip vykdomasis failas.

## Išvesties failai

Išvesties failų pavadinimai sudaromi iš įvesties failo vardo:

| Funkcija | Išvesties failas | Turinys |
|----------|------------------|---------|
| 1 | `<vardas>_zodziu_skaicius.txt` | `žodis: skaičius` (tik > 1) |
| 2 | `<vardas>_cross_ref.txt` | `žodis -> eilutė eilutė ...` |
| 3 | `<vardas>_urls.txt` | rasti URL adresai (po vieną eilutėje) |
