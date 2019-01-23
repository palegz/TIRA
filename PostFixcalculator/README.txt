
-----------------------------------
-----Pauli Mänty POSTFIX LAsKIN----
-----------------------------------
------25.10.2018-------------------
-----------------------------------
pauli.manty@eng.tamk.fi
040 5877367

OHJEET:


OHJELMA AJETAAN käynnistämällä .exe /Debug/PostFixcalculator.exe

Tavoittelen tällä työllä yhtä(1) pistettä.


 Käytetyt työtunnit :

		   19.10.2018  30 minuuttia työn aloittamista ja postfix laskimeen tutustumista. 	
		   20.10.2018 1.5h aikaa työntekoa, ohjelmakoodin kirjoittamista. Yhden pisteen työ tässä vaiheessa melkein valmis.
 Ohjelma kaatuilee väärästä syötteestä, ja muutenkin.		
		   25.10.2018 2h töitä harkkatyö valmis. Kaatuu vääärästä syötteestä, älä laita väärää syötettä.


Ohjelman periaate on stackin avulla postfix laskimen tekeminen. 
Laskimen toiminta perustuu siihen, että ensin annetaan 2 termia jotka halutaan laskea, ja sitten vasta operaattori.

ohjelma koostuu neljästä aliohjelmasta ja yhdestä Main pääohjelmasta. 	
		   

int arvioiSyote(string syote);

	arvioiSyoto katsoo käyttäjän syötteestä numerot, ja valitun operaattorin bool Operaattori(); ja Termit(); aliohjelmien avulla, ja laittaa stackkeihin. 
Lasku lasketaan teeLaskutoimitus() aliohjelmalla ja tulos pushataan stackkiin ja tulostetaan näytölle.


int teeLaskutoimitus(char operaattori, int termi1, int termi2);
Tämä aliohjelma laskee termit operaattorin avulla. Muutama if else joka operaattorille jotta ohjelma tietää mitä lasketaan.


bool Operaattori(char C);
Tällä aliohjelmalla käyttäjän syötteestä valitaan operaattori laskutoimitukseen

bool Termit(char C);
Tällä aliohjelmalla muutetaan termit string syötteestä int muotoon laskettavaksi. ¨

Esimerkkisyöte 
Postfix laskin:
Anna ensin laskettavat kokonaisluvut ja sitten operaattori +, -, /, tai *.
Esimerkiksi 2 4 - /n
1 5 *
1 5 * = 5
Press any key to continue . . . 



