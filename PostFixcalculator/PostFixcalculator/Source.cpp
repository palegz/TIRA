/*
Tietorakenteet ja algoritmit kurssin PostFix laskin.
A: Pauli Mänty
20/10/2018 
 
 Tällä hetkeellä harjoitustyöllä tavoitellaan yhtäpistettä.

+ - * ja / käyvät operaattoreista.

*/
#include<iostream>
#include<stack>
#include<string>

using std::cout; using std::string; using std::cin; using std::getline; using std::endl; using std::stack;

//laskimen aliohjelmien esittely.
int arvioiSyote(string syote);
int teeLaskutoimitus(char operaattori, int termi1, int termi2);
bool Operaattori(char C);
bool Termit(char C);

int main()
{
    string laskutoimitus;			
	cout << "Postfix laskin: " << endl;
	cout << "Anna ensin laskettavat kokonaisluvut ja sitten operaattori +, -, /, tai *. " << endl;
	cout << "Esimerkiksi 2 4 - /n" << endl;
	getline(cin, laskutoimitus);
	int tulos = arvioiSyote(laskutoimitus);
	cout << laskutoimitus << " = " << tulos << endl;

	system("pause");
	return 0;
}

int arvioiSyote(string syote) //aliohjelma joka etsii kayttajan syotteesta termit ja 
								//operaattorin Operaattori ja Termit aliohjelmien avulla. 
					
{
	stack<int> s;
		//for loop joka lukee syotteen ja  etsii sielta termit ja operaattorin, suorittaa vaadittavat toimenpitee
		//kun koko syöte on luettu tehdaan laskutoimitus ja pushataan toimituksen tulos stackkiin ja stackkiin jää tulos arvoksi.
	for (unsigned int i = 0; i <= syote.length(); i++) {
		if (syote[i] == ' ' || syote[i] == ',') continue;
		else if (Operaattori(syote[i])) {
			int termi1 = s.top(); s.pop();
			int termi2 = s.top(); s.pop();
			int tulos = teeLaskutoimitus(syote[i], termi1, termi2);
			s.push(tulos);
		}
		else if (Termit(syote[i])) {			int termi = 0;
			while (i <= syote.length() && Termit(syote[i])) {
				//jos syotetyssa luvussa on enemman kuin 1 numero otetaan edellinen syöte ja kerrotaan se kymmenella 
				//ja lisataan sueraava luku siihen 
				termi = (termi * 10) + (syote[i] - '0');
				i++;
			}
			i--;
			s.push(termi);
		}
	}
	// If expression is in correct format, Stack will finally have one element. This will be the output. 
	return s.top();
}

bool Termit(char C) //aliohjelma joka määrittää mikä syötteeessä on hyväksyttävää termistöä laskutoimitukselle
{
	if (C >= '0' && C <= '9') return true;
	return false;
}

bool Operaattori(char C) //aliohjelma joka määrittää mitkä operaattorit ovat sallittuja
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}

int teeLaskutoimitus(char laskutoimitus, int termi1, int termi2)
{
	if (laskutoimitus == '+') return termi1 + termi2;
	else if (laskutoimitus == '-') return termi1 - termi2;
	else if (laskutoimitus == '*') return termi1 * termi2;
	else if (laskutoimitus == '/') return termi1 / termi2;
	return -1;
}