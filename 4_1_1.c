/* 4.1.1 Statisk l�nkning - teori - 1p
F�rklara utf�rligt hur statisk l�nkning p�verkar programmet m a p:
- Filstorlek
- Prestanda
- Kompatibilitet/Portabilitet


Filstorlek
Svar: 
D� alla funktioner som kommer fr�n stdbibliotek och egna bibliotek( med " .h" filer) och som beh�vs i koden 
kopieras in permanent i exekveringsfilen (bin�r) s� �kar storleken p� densamma.
Detta g�r att den tar mer plats i disken och i huvudminnet (main memory).
Anropen till funktionern i dessa bibliotek utf�rs under sj�lva l�nkningen ligger kvar hela tiden och 
minnet frig�rs d�rmed inte under exekveringen. Det kr�vs ett st�rre minne helt enkelt.
I dynamisk l�nkning �r det bara adressen som finns med.


Prestanda
Svar: 
Anropen till funktionerna i dessa bibliotek (det �r bara det funktioner som kr�vs som kopieras med) utf�rs 
under sj�lva l�nkningen (sista steget i kompileringen)  ligger kvar hela tiden och minnet frig�rs d�rmed inte under exekveringen. 
Det kr�vs ett st�rre minne helt enkelt. (I dynamisk l�nkning �r det bara adressen som finns med.)
Kan inte uppdateras efter l�nkningen utan hela kompileringen m�ste g�ras om.
Inga beroenden av biblioteket efer l�nkningen, s� en �ndring av n�gon kommer inte med. (Ibland bra, ibland d�ligt.)
Statisk l�nkning kr�ver ordentligt med minne. Om Windows system verktyg var statiskt l�nkat 
skulle det kr�vas ett tiotal MB RAM minne och datorn skulle saktas ner pga frekvent paging. 
(Paging = is a memory management scheme that eliminates the need for contiguous allocation of physical memory)
Inga beroende av bibliotekens run time och f�r d�rmed inte run time loading cost.
Kunden beh�ver inte ha r�tt bibliotek i sins system f�r det �r redan inkluderat i exekveringsfilen.
En stor f�rdel som fortsatt idag g�r att statisk l�nkning anv�nds �r hastigheten.  because a set of commonly used object files is put into a single library executable file.


Kompbilitet/Portabilitet
Svar: 
- Inga beroenden av biblioteket efter l�nkningen, s� en �ndring av n�gon kommer inte med. (Ibland bra, ibland d�ligt.)
- Kunden beh�ver inte ha r�tt bibliotek i sins system f�r det �r redan inkluderat i exekveringsfilen.
- Statisk l�nkning g�r att om kompilering g�rs p� tex p� en Ubuntu dator och sen flytta �ver filerna och k�ra den p� en Debian eller windows dator �r ok. 
- �r d�rmed l�tt att flytta mellan datorer.
- Saknar oftast kompabilitets problem d� allt ing�r i en modul.
*/





/*
Minnesanteckningar
STATISK L�NKNING
- k�llkoden m�ste kompileras, l�nkas till olika bibliotek f�r en exekverbar fil (.exe). 
- till exempel vara standardbibliotek <bibl.h> eller egna bibliotek �bibl.h�. 
- inneh�lla f�rkompilerade funktioner (precompiled functions) anropas fr�n programmet f�r att utf�ra olika uppgifter.
- N�r funktioner l�nkas till en applikation kopieras de och blir en permanent del av applikationens exekverbara fil. 
- Samtliga anrop till funktioner i l�nkade biblioteken �vers�tts eller utf�rs bara en g�ng, n�mligen under sj�lva l�nkningen. 
- Detta kallas statisk l�nkning och f�ljaktligen statiska bibliotek. 
- Detta �r praktiskt om man vill l�ta andra anv�nda funktionerna utan att vilja/beh�va avsl�ja.

DYNAMISK L�NKNING
- m�jligt att l�nka en applikation till bibliotek under sj�lva programk�rningen. 
- dynamiska bibliotek kopieras aldrig in i en applikations exekverbara fil. 
- Ett dynamiskt bibliotek kallas vanligen ett DLL (Dynamic Link Library) � en .DLL-fil.
- Vid programk�rning laddar operativsystemet in DLL-filen i minnet och l�nkar 
  alla referenser till funktioner I DLL-filen, s� de kan anropas av applikationen.
- Sedan exekverar de delarna av applikationen som anv�nder DLL-funktionerna.
- minnet frig�rs n�r DLLfunktionerna ej l�ngre beh�vs.

What is a static library good for?
programs needed are nicely packaged for use in other systems (portability) 
but: source code is available to everybody�

Static linking:
- all parts are copied permanently into the executable (� size)
- all necessary code is in located in the executable
- calls are translated/executed only once � during linking
*/