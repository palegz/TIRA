
-----------------------------------
-----Pauli M�nty POSTFIX LAsKIN----
-----------------------------------
------25.10.2018-------------------
-----------------------------------
pauli.manty@eng.tamk.fi
040 5877367

OHJEET:


OHJELMA AJETAAN k�ynnist�m�ll� .exe /Debug/PostFixcalculator.exe

Tavoittelen t�ll� ty�ll� yht�(1) pistett�.


 K�ytetyt ty�tunnit :

		   19.10.2018  30 minuuttia ty�n aloittamista ja postfix laskimeen tutustumista. 	
		   20.10.2018 1.5h aikaa ty�ntekoa, ohjelmakoodin kirjoittamista. Yhden pisteen ty� t�ss� vaiheessa melkein valmis.
 Ohjelma kaatuilee v��r�st� sy�tteest�, ja muutenkin.		
		   25.10.2018 2h t�it� harkkaty� valmis. Kaatuu v���r�st� sy�tteest�, �l� laita v��r�� sy�tett�.


Ohjelman periaate on stackin avulla postfix laskimen tekeminen. 
Laskimen toiminta perustuu siihen, ett� ensin annetaan 2 termia jotka halutaan laskea, ja sitten vasta operaattori.

ohjelma koostuu nelj�st� aliohjelmasta ja yhdest� Main p��ohjelmasta. 	
		   

int arvioiSyote(string syote);

	arvioiSyoto katsoo k�ytt�j�n sy�tteest� numerot, ja valitun operaattorin bool Operaattori(); ja Termit(); aliohjelmien avulla, ja laittaa stackkeihin. 
Lasku lasketaan teeLaskutoimitus() aliohjelmalla ja tulos pushataan stackkiin ja tulostetaan n�yt�lle.


int teeLaskutoimitus(char operaattori, int termi1, int termi2);
T�m� aliohjelma laskee termit operaattorin avulla. Muutama if else joka operaattorille jotta ohjelma tiet�� mit� lasketaan.


bool Operaattori(char C);
T�ll� aliohjelmalla k�ytt�j�n sy�tteest� valitaan operaattori laskutoimitukseen

bool Termit(char C);
T�ll� aliohjelmalla muutetaan termit string sy�tteest� int muotoon laskettavaksi. �

Esimerkkisy�te 
Postfix laskin:
Anna ensin laskettavat kokonaisluvut ja sitten operaattori +, -, /, tai *.
Esimerkiksi 2 4 - /n
1 5 *
1 5 * = 5
Press any key to continue . . . 



