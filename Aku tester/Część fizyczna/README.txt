Tester ogniw v1.1
_________________
[Yjek] nie, 7 kwi 2013, 19:51:43 
Dodać rezystory do PCB R6 i R5.
Zmienić cewkę L1 filtrującą zasilanie dla µC z obudowy dużej IND-10-V na mały osiowy natomiast L3 filtrujący zasilanie dla całej części analogowej z małego osiowego na IND-10-V.
Poprawić bibliotekę obudowy K1 (D-SUB 9pin); otwory padów mocujących są za małe.


[Yjek] śro, 13 mar 2013, 22:51:06 
Zamieniłem etykietę [AGND] na [No_DAC] w złączu sterującym modułem mocy.
Przy pojawieniu się stanu wysokiego na [No_DAC] nietylko MOSFET-y będą bezpośrednio sterowane z portu (PWM) ale przekaźniki w module mocy zewrą rezystory mocy, które przy sterowaniu impulsowym poważnie komplikowałyby sprawę ze względu na swoją indukcyjność.
Celowość rezystorów w module mocy jest opisana w v1.0

[Yjek] śro, 9 sty 2013, 22:56:33
Poprzednia wersja na obecną chwilę (patrz wstawiony czas i data)
jest niedokończona. Zdecydowaliśmy się na modułowość.
Projektów jest tyle co schematów i płytek ponieważ wspólny projekt komplikował otwieranie plików.
Schematy są trzy tak jak projekty:
"Tester ogniw - Moduł mocy.sch"
"Tester ogniw - Sterownik.sch"
"Tester ogniw - Interfejs.sch
Schematy zostawiłem do ponumerowania elementów dla [STI]
ponieważ chce wykorzystać pracę nad PCB z wersji 1.0.

_________________

Tester ogniw v1.0
_________________

środa, 26 grudnia 2012
[STI] żródła zasilania (symbole zasilania) w projekcie miały inne wartości lecz nie nazwy, z tąd też np +18V POW było połączone z praktycznie wszystkimi innymi symbolami (wszystkie miały nazwę VAA !!!!!!!!) dodałem elementy z biblioteki standardowej
[STI] Dodano flagi PWR_FLAG, wyeleimnowało to błędy przy DRC (przy okazazji poprawiono elementy z biblioteki analogowe)
sob, 15 gru 2012, 20:42:28 
[Yjek] Usunięcie osieroconych elementów.
Dodano rezystory w źródłach MOSFET-ów wykonawczych. Wymusi to na WO pracę w szerszym zakresie napięć i poprawi stosunek sygnału do szumu.
Dodano kondensatory filtrujące zasilanie przy wszystkich układach.
Odwrócono MOSFET-a ładującego (dobito względem osi X).
Odbito względem osi Y WO błędu prądu ładowania.
Odbito względem osi X WO błędu prądu rozładowania.
Usunąłem wpis STI o dzielnikach (które wyrzuciliśmy z projektu bo są niepotrzebne).
Usunięto rezystory w sprzężeniu zwrotnym obu wzmacniaczy błędu prądów ładowania i rozładowania.
Zwiększenie pojemności w sprzężeniu zwrotnym wzmacniaczy pomiaru błędów prądu ładowania i rozładowania
do 1µF.
Zmieniono topologię prostownika linearyzowanego.
Dodano dzielniki PWM → DAC przed wejściami odwracającymi wzmacniaczy błędu pomiaru prądów.
Dodano "reakcyjniaki" przy powyższych dzielnikach.

pią, 23 lis 2012, 08:58:28 
[Yjek] Trzeba rozważyć złącze dla wentylatora radiatora MOSFET'ów.
Dodałem nomenklature MOSFET'ów wykonawczych.

piątek, 16 listopada 2012
[STI] Trzeba zmienić Atmege 8 na 16 bo brakuje pinów, chyba że rezygnujemy z LCD i "guzików" na rzecz osobnej atmegi z klawiaturą i LCD z którą ta pierwsza by się komunikowała (to nie do końca jest bez sensu ;) )
[STI] Za "16" stoi jeszcze JTAG który do tego projektu mógłby się bardzo przydać! 

czw, 25 paź 2012, 09:19:27 
[Yjek] Wstawiłem do głównego / bibllioteki / [ Biblioteka KiCAD ]



