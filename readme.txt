Kompilowanie:
make - obie implementacje
lub
make philosophers1 - pierwsza implementacja
lub 
make philosophers2 - druga implementacja

make clean - usunięcie wszystkich plików powstałych przy kompilacji

Użycie: philosophers1 [-et min_eating_time max_eating_time] [-tt min_thinking_time max_thinking_time]
(analogicznie dla philosophers2)
Jeśli nie ustawimy czasów przy uruchamianiu programu, oba czasy minimalne zostaną ustawione na 1 sekundę,
a maksymalne - na 2 sekundy.

Różnice w implementacji:
philosophers1 - wszyscy filozofowie najpierw próbują wziąć lewy widelec, a następnie prawy. Aby
                wystąpiło zjawisko blokady należy wybrać
philosophers2 - filozofowie 0-3 najpierw próbują wziąc lewy widelec, a następnie prawy. Filozof 4
                (outsider) najpierw próbuje wziąć prawy widelec, a dopiero potem lewy. Zapobiega
                to zjawisku blokady.

Przykładowy widok stanu - aktualizowany co sekundę:
                   ____
                  /    \
                 /     V\
                |   WL | |
                 \     |/
                  \____/           
                                 
   ____                             ____
  /    \                           /    \
 /V     \                         /      \
| | WR   |                       |   T    |
 \|     /                         \      /
  \____/                           \____/
                                _|
                                  \
             ____         ____     \
            /    \       /    \
           /V    V\     /      \
          | | E  | |   |   T    |
           \|    |/     \      /
            \____/       \____/

LEGEND:
E - eating
T - thinking
WL - waiting for left fork
WR - waiting for right fork
