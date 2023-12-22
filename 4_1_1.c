/* 4.1.1 Statisk länkning - teori - 1p
Förklara utförligt hur statisk länkning påverkar programmet m a p:
- Filstorlek
- Prestanda
- Kompatibilitet/Portabilitet


Filstorlek
Svar: 
Då alla funktioner som kommer från stdbibliotek och egna bibliotek( med " .h" filer) och som behövs i koden 
kopieras in permanent i exekveringsfilen (binär) så ökar storleken på densamma.
Detta gör att den tar mer plats i disken och i huvudminnet (main memory).
Anropen till funktionern i dessa bibliotek utförs under själva länkningen ligger kvar hela tiden och 
minnet frigörs därmed inte under exekveringen. Det krävs ett större minne helt enkelt.
I dynamisk länkning är det bara adressen som finns med.


Prestanda
Svar: 
Anropen till funktionerna i dessa bibliotek (det är bara det funktioner som krävs som kopieras med) utförs 
under själva länkningen (sista steget i kompileringen)  ligger kvar hela tiden och minnet frigörs därmed inte under exekveringen. 
Det krävs ett större minne helt enkelt. (I dynamisk länkning är det bara adressen som finns med.)
Kan inte uppdateras efter länkningen utan hela kompileringen måste göras om.
Inga beroenden av biblioteket efer länkningen, så en ändring av någon kommer inte med. (Ibland bra, ibland dåligt.)
Statisk länkning kräver ordentligt med minne. Om Windows system verktyg var statiskt länkat 
skulle det krävas ett tiotal MB RAM minne och datorn skulle saktas ner pga frekvent paging. 
(Paging = is a memory management scheme that eliminates the need for contiguous allocation of physical memory)
Inga beroende av bibliotekens run time och får därmed inte run time loading cost.
Kunden behöver inte ha rätt bibliotek i sins system för det är redan inkluderat i exekveringsfilen.
En stor fördel som fortsatt idag gör att statisk länkning används är hastigheten.  because a set of commonly used object files is put into a single library executable file.


Kompbilitet/Portabilitet
Svar: 
- Inga beroenden av biblioteket efter länkningen, så en ändring av någon kommer inte med. (Ibland bra, ibland dåligt.)
- Kunden behöver inte ha rätt bibliotek i sins system för det är redan inkluderat i exekveringsfilen.
- Statisk länkning gör att om kompilering görs på tex på en Ubuntu dator och sen flytta över filerna och köra den på en Debian eller windows dator är ok. 
- Är därmed lätt att flytta mellan datorer.
- Saknar oftast kompabilitets problem då allt ingår i en modul.
*/





/*
Minnesanteckningar
STATISK LÄNKNING
- källkoden måste kompileras, länkas till olika bibliotek för en exekverbar fil (.exe). 
- till exempel vara standardbibliotek <bibl.h> eller egna bibliotek ”bibl.h”. 
- innehålla förkompilerade funktioner (precompiled functions) anropas från programmet för att utföra olika uppgifter.
- När funktioner länkas till en applikation kopieras de och blir en permanent del av applikationens exekverbara fil. 
- Samtliga anrop till funktioner i länkade biblioteken översätts eller utförs bara en gång, nämligen under själva länkningen. 
- Detta kallas statisk länkning och följaktligen statiska bibliotek. 
- Detta är praktiskt om man vill låta andra använda funktionerna utan att vilja/behöva avslöja.

DYNAMISK LÄNKNING
- möjligt att länka en applikation till bibliotek under själva programkörningen. 
- dynamiska bibliotek kopieras aldrig in i en applikations exekverbara fil. 
- Ett dynamiskt bibliotek kallas vanligen ett DLL (Dynamic Link Library) – en .DLL-fil.
- Vid programkörning laddar operativsystemet in DLL-filen i minnet och länkar 
  alla referenser till funktioner I DLL-filen, så de kan anropas av applikationen.
- Sedan exekverar de delarna av applikationen som använder DLL-funktionerna.
- minnet frigörs när DLLfunktionerna ej längre behövs.

What is a static library good for?
programs needed are nicely packaged for use in other systems (portability) 
but: source code is available to everybody…

Static linking:
- all parts are copied permanently into the executable (… size)
- all necessary code is in located in the executable
- calls are translated/executed only once – during linking
*/