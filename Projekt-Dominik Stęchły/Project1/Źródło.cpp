#include<iostream>
#include<cctype>
#include <windows.h>
#include<random>
#include<string>
#include<cstring>
#include<iomanip>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
using namespace std;


bool czydobraklasa(string wejscie)
{
	if (wejscie.length() > 1) return true;
	else
	{
		if (wejscie.compare("1") == 0) return false;
		else if (wejscie.compare("2") == 0) return false;
		else if (wejscie.compare("3") == 0) return false;
		else return true;
	}
}

int klasaatak(int klasa)
{
	if (klasa == 1) return 2;
	if (klasa == 2) return 4;
	else return 1;
}

int klasaszczescie(int klasa)
{
	if (klasa == 1) return 2;
	if (klasa == 2) return 1;
	else return 4;
}

void wybranaklasa(int klasa)
{
	cout << "Wybrales klase : ";
	if (klasa == 1) cout << "Wojownik (+1 do ataku i +1 do szczescia)" << endl;
	if (klasa == 2) cout << "Barbarzynca(+3 do ataku ale -1 do szczescia" << endl;
	if (klasa == 3) cout << "Goblin, -1 do ataku ale +3 do szczescia" << endl;
	cout << "\n\n Rozdaj punkty umiejetnosci(10 dostepnych) i pamietaj ze nie mozna ich odjac" << endl;
}

void punkty(int obrazenia, int szczescie, int celnosc, int kryt,int zycie)
{
	cout << "  " << obrazenia << " -Atak(zwieksza mnoznik zadawanych obrazen)" << endl;
	cout << "  " << szczescie << " -Szczescie(zwieksza szanse na zadanie obrazen krytycznych i szanse na blok ataku przeciwnika)" << endl;
	cout << "  " << celnosc << " -Celnosc(Zmniejsza szanse na zablokowanie ataku przez przeciwnika)" << endl;
	cout << "  " << kryt << " -Trafienie krytyczne(zwieksza obrazenia trafienia krytycznego)" << endl;
	cout << "  " << zycie << "-Zycie(zwieksza liczbe punktow zdrowia)" << endl;
}

bool czywolnepunkty(int wolnepunkty)
{
	if (wolnepunkty != 0)
	{
		return true;
	}
	else return false;
}

bool czydobrestaty(string wejsciestatystyka)
{
	if (wejsciestatystyka.length() > 1) return true;
	else
	{
		if (wejsciestatystyka.compare("1") == 0) return false;
		else if (wejsciestatystyka.compare("2") == 0) return false;
		else if (wejsciestatystyka.compare("3") == 0) return false;
		else if (wejsciestatystyka.compare("4") == 0) return false;
		else if (wejsciestatystyka.compare("5") == 0) return false;
		else return true;
	}
}
bool czydobrepkt(string wejsciedodanepkt)
{
	if (wejsciedodanepkt.length() > 3) return true;
	else
	{
		if (wejsciedodanepkt.compare("1") == 0) return false;
		else if (wejsciedodanepkt.compare("2") == 0) return false;
		else if (wejsciedodanepkt.compare("3") == 0) return false;
		else if (wejsciedodanepkt.compare("4") == 0) return false;
		else if (wejsciedodanepkt.compare("5") == 0) return false;
		else if (wejsciedodanepkt.compare("6") == 0) return false;
		else if (wejsciedodanepkt.compare("7") == 0) return false;
		else if (wejsciedodanepkt.compare("8") == 0) return false;
		else if (wejsciedodanepkt.compare("9") == 0) return false;
		else if (wejsciedodanepkt.compare("10") == 0) return false;
		else return true;
	}
}
bool(czykontynuuj(string kontynuuj))
{
	if (kontynuuj.length() > 1) return true;
	else if (kontynuuj.compare("1") == 0) return false;
	else if (kontynuuj.compare("2") == 0) return false;
	else return true;
}



int main()
{
	int klasa, k = 10, wolnepunkty = 10, dodanepkt, statystyka;
	int atak = 1, szczescie = 1, kryt = 1, celnosc = 1,zycie=1;
	int atakp = 1, szczesciep = 1, celnoscp = 1, krytp = 1, zyciep = 1, punktyprzeciwnik = 10, dodatek, pluspkt, rodzajataku,pdmg,trafienie;
	string wejscie,wejsciestatystyka,wejsciedodanepkt,kontynuuj;
	random_device random;
	mt19937 generator(random());


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
	cout << "Dostepne klasy: \n 1.Wojownik(bazowe statystyki) \n 2.Barbarzynca(zwiekszone obrazenia ale mniejsze szczescie) \n 3.Goblin (mniejsze obrazenia ale wieksze szczescie)\n Wybierz klase postaci(1-3):" << endl;
	cin>>wejscie;		//przyjmuje klase

	//KLASA
	while (czydobraklasa(wejscie))
	{
		if (czydobraklasa(wejscie))
		{
			cin.clear();
			cout << "Podales zla liczbe! Sprobuj jeszcze raz(1-3) : " << endl;
			cin >> wejscie;
		}
	}
	klasa = stoi(wejscie);
	if (system("CLS")) system("clear");

	atak = klasaatak(klasa);
	szczescie = klasaszczescie(klasa);
	wybranaklasa(klasa); //wyswietla wybrana klasa
	/*punkty(atak, szczescie, blok, celnosc, kryt);*/

	//ROZDAWANIE PUNKTOW
	while (czywolnepunkty(wolnepunkty))
	{
		punkty(atak, szczescie, celnosc, kryt,zycie);
		cout << "Masz " << wolnepunkty << " wolnych punktow. Co chcesz ulepszyc?\n 1.Atak   2.Szczescie   3.Celnosc   4.Trafienie krytyczne  5.Zycie" << endl;
		cin >> wejsciestatystyka;
		while (czydobrestaty(wejsciestatystyka))
		{
			if (czydobrestaty)
			{
				cin.clear();
				cout << "Podales zla cyfre! Sprobuj podac jeszcze raz : ";
				cin >> wejsciestatystyka;
			}
		}
		statystyka = stoi(wejsciestatystyka);
		cout << "Ile punktow ";
		if (statystyka == 1) cout << "ataku";
		if (statystyka == 2) cout << "szczescia";
		if (statystyka == 3) cout << "celnosci";
		if (statystyka == 4) cout << "trafienia krytycznego";
		if (statystyka == 5) cout << "zycia";
		cout << " chcesz dodac : ";
		cin >> wejsciedodanepkt;
		while (czydobrepkt(wejsciedodanepkt))
		{
			if (czydobrepkt(wejsciedodanepkt))
			{
				cin.clear();
				cout << "Podales zla cyfre! Sprobuj ponownie!";
				cin >> wejsciedodanepkt;
			}
		}
		dodanepkt = stoi(wejsciedodanepkt);

		/*while (dodanepkt > wolnepunkty || dodanepkt <= 0)
		{
			if (dodanepkt > wolnepunkty)
			{
				cout << "Podales zbyt duza liczbe punktow! Sprobuj jeszcze raz: ";
				cin >> wejsciedodanepkt;
				dodanepkt = (int)wejsciedodanepkt - 48;
			}
			else if (dodanepkt <= 0)
			{
				cout << "Podales niewlasciwa ilosc punktow! Sprobuj jeszcze raz: ";
				cin >> wejsciedodanepkt;
				dodanepkt = (int)wejsciedodanepkt - 48;
			}
		}*/
		if (statystyka == 1) atak = atak + dodanepkt;
		if (statystyka == 2) szczescie = szczescie + dodanepkt;
		if (statystyka == 3) celnosc = celnosc + dodanepkt;
		if (statystyka == 4) kryt = kryt + dodanepkt;
		if (statystyka == 5) zycie = zycie + dodanepkt;
		wolnepunkty = wolnepunkty - dodanepkt;
		if (system("CLS")) system("clear");
	}
	if (system("CLS")) system("clear");
	cout << "Aktualne statystyki: " << endl;
	punkty(atak, szczescie, celnosc, kryt,zycie);

	//PRZECIWNIK
	while (punktyprzeciwnik > 0)
	{
		uniform_int_distribution <int> distribution(1, 1);
		uniform_int_distribution <int> rodzaj(1, 5);
		dodatek = rodzaj(generator);
		pluspkt = distribution(generator);
		if (dodatek == 1)atakp = atakp + pluspkt;
			if (dodatek == 2)szczesciep = szczesciep + pluspkt;
				if (dodatek == 3)celnoscp = celnoscp + pluspkt;
					if (dodatek == 4)krytp = krytp + pluspkt;
						if (dodatek == 5)zyciep = zyciep + pluspkt;
		punktyprzeciwnik = punktyprzeciwnik - pluspkt;
	}

	int kontynuujliczba, mindmg, maxdmg, dmg, traf, przeciwnikmindmg, przeciwnikmaxdmg, przeciwnikdmg, przeciwniktraf, przeciwniktrafienie, przecrodzaj, atakkryt, krytgracz, krytprzeciwnik, hp, hpprzeciwnik, runda = 1, potrzebne;
	bool hit, przeciwnikhit, celkryt, celkrytprzec,czygramydalej=true;
	uniform_int_distribution <int> ataklos(1, 3);
	uniform_int_distribution <int> czytrafione(1, 100);
	hp = zycie * 20;
	hpprzeciwnik = zyciep * 20;

	while (czygramydalej)
	{
		traf = czytrafione(generator);
		przeciwniktraf = czytrafione(generator);
		przecrodzaj = ataklos(generator);
	if (system("CLS")) system("clear");
	cout << endl << setw(32) << right << "RUNDA " << runda;
	std::cout << std::setw(18) << std::left << "\nTwoj atak: " << atak << "\t" << atakp << "  -Atak przeciwnika";
	std::cout << std::setw(18) << std::left << "\nTwoj szczescie: " << szczescie << "\t" << szczesciep << "  -Szzescie przeciwnika ";
	std::cout << std::setw(18) << std::left << "\nTwoj celnosc: " << celnosc<< "\t" << celnoscp << "  -Celnosc przeciwnika " ;
	std::cout << std::setw(18) << std::left << "\nTwoj kryt: " << kryt << "\t" << krytp << "  -Kryt przeciwnika " ;
	std::cout << std::setw(18) << std::left << "\nTwoje pkt zycia: "<<hp <<"\t" << hpprzeciwnik << "  -Zycie przeciwnika ";


	cout <<endl<< "Jaki rodzaj ataku chcesz wykonac?" << endl;
	std::cout<<"\n\n" <<std::setw(62)<<std::left<< "1.Silny(Duze obrazenia ale mala szansa na tafienie)"<<"Obrazenia("<<std::setw(3)<<std::left<<6+atak*2<<" - "<<std::setw(3)<<std::right<<9+atak*3<<")"<<"  Szansa trafienia: "<<std::setw(4)<<std::left<<15+celnosc*2<<"%" <<"\n"<< std::setw(62) <<std::left<<"2.Normalny(Srednie obrazenia i srednia szansa na trafienie)"<<"Obrazenia(" << std::setw(3) << std::left << 3+atak * 1 << " - " << std::setw(3) << std::right << 6+atak * 2 << ")" << "  Szansa trafienia: " << std::setw(4) << std::left << 43 + celnosc * 2 << "%"<<"\n"<< std::setw(62) <<std::left<<"3.Slaby(Niskie obrazenia ale wysoka szansa na trafienie)"<< "Obrazenia(" << std::setw(3) << std::left<<(int)(1+0.5*atak)  <<" - " << std::setw(3) << std::right <<3+atak*1<<")"<<"  Szansa trafienia: "<<std::setw(4) << std::left<<80+celnosc*2<<"%" << endl;
	cin >> rodzajataku;


	switch(rodzajataku)//atak gracza
	{
	case 1:
		{
			mindmg = 6 + 2 * atak;
			maxdmg = 9 + 3 * atak;
			trafienie=15+2*celnosc;
			uniform_int_distribution<int> iloscdmg(mindmg, maxdmg);
			dmg = iloscdmg(generator);
			if (traf >= trafienie) hit = false;
			else hit = true;
			break;
		}
	case 2:
		{
			mindmg = 3 + 1 * atak;
			maxdmg = 6 + 2 * atak;
			trafienie = 43 + 2 * celnosc;
			uniform_int_distribution<int> iloscdmg(mindmg, maxdmg);
			dmg = iloscdmg(generator);
			if (traf >= trafienie) hit = false;
			else hit = true;
			break;
		}
	case 3:
		{
			mindmg = 1 + 0 * atak;
			maxdmg = 3 + 1 * atak;
			trafienie = 80 + 2 * celnosc;
			uniform_int_distribution<int> iloscdmg(mindmg, maxdmg);
			dmg = iloscdmg(generator);
			if (traf >= trafienie) hit = false;
			else hit = true;
			break;
		}
	}
	switch (przecrodzaj)//atak przeciwnika
	{
	case 1:
	{
		przeciwnikmindmg = 6 + 2 * atakp;
		przeciwnikmaxdmg = 9 + 3 * atakp;
		przeciwniktrafienie = 15 + 2 * celnoscp;
		uniform_int_distribution<int> iloscdmg(przeciwnikmindmg, przeciwnikmaxdmg);
		przeciwnikdmg = iloscdmg(generator);
		if (przeciwniktraf >= przeciwniktrafienie) przeciwnikhit = false;
		else przeciwnikhit = true;
		break;
	}
	case 2:
	{
		przeciwnikmindmg = 3 + 1 * atakp;
		przeciwnikmaxdmg = 6 + 2 * atakp;
		przeciwniktrafienie = 43 + 2 * celnoscp;
		uniform_int_distribution<int> iloscdmg(mindmg, maxdmg);
		przeciwnikdmg = iloscdmg(generator);
		if (przeciwniktraf >= przeciwniktrafienie) przeciwnikhit = false;
		else przeciwnikhit = true;
		break;
	}
	case 3:
	{
		przeciwnikmindmg = 1 + 0 * atakp;
		przeciwnikmaxdmg = 3 + 1 * atakp;
		przeciwniktrafienie = 80 + 2 * celnoscp;
		uniform_int_distribution<int> iloscdmg(przeciwnikmindmg, przeciwnikmaxdmg);
		przeciwnikdmg = iloscdmg(generator);
		if (przeciwniktraf >= przeciwniktrafienie) przeciwnikhit = false;
		else przeciwnikhit = true;
		break;
	}
	}
		//krytyk
		uniform_int_distribution <int> czykryt(1, 100);
		atakkryt = czykryt(generator);
		krytgracz = 10+szczescie * 5;
		krytprzeciwnik = 10+szczesciep * 5;
		if (atakkryt <= krytgracz)
		{
			celkryt = true;
		}
		else celkryt = false;
		atakkryt = czykryt(generator);
		if (atakkryt <= krytprzeciwnik)
		{
			celkrytprzec = true;
		}
		else celkrytprzec = false;
		if (hit)
		{
			dmg = dmg * 2;
			hpprzeciwnik = hpprzeciwnik - dmg;
		}
		if (przeciwnikhit)
		{
			przeciwnikdmg = przeciwnikdmg * 2;
			hp = hp - przeciwnikdmg;
		}
		if (system("CLS")) system("clear");
		//chyba runda
				cout <<endl<< setw(32) << right << "RUNDA " << runda;
				std::cout << std::setw(20) << std::left << "\nTwoj atak: " << setw(3) << atak << "\t" << setw(10) << right << atakp << "  -Atak przeciwnika";
				std::cout << std::setw(20) << std::left << "\nTwoj szczescie: " << setw(3) << szczescie << "\t" << setw(10) << right << szczesciep << "  -Szzescie przeciwnika ";
				std::cout << std::setw(20) << std::left << "\nTwoj celnosc: " << setw(3) << celnosc << "\t" << setw(10) << right << celnoscp << "  -Celnosc przeciwnika ";
				std::cout << std::setw(20) << std::left << "\nTwoj kryt: " << setw(3) << kryt << "\t" << setw(10) << right << krytp << "  -Kryt przeciwnika ";
				std::cout << std::setw(20) << std::left << "\nTwoje pkt zycia: " << setw(3) << hp << "\t" << setw(10) << right << hpprzeciwnik << "  -Zycie przeciwnika " << endl << endl;
				if (rodzajataku == 1) cout << setw(37) << left << "Uzywa silnego ataku";
				else if (rodzajataku == 2) cout << setw(37) << left << "Uzywa normalnego ataku";
				else if (rodzajataku == 3)cout << setw(37) << left << "Uzywa slabego ataku";
				if (przecrodzaj == 1) cout << setw(23) << left << "Uzywa silnego ataku";
				else if (przecrodzaj == 2) cout << setw(23) << left << "Uzywa normalnego ataku";
				else if (przecrodzaj == 3)cout << setw(23) << left << "Uzywa slabego ataku";
			//	if (celkryt) { dmg = dmg * 2; }
			//	if (celkrytprzec) { przeciwnikdmg = przeciwnikdmg * 2; }
				if (hit) {
					cout << "\nTrafil ";
					if (celkryt) cout << setw(30) << left << " krytycznie";
					else cout << setw(30) << left << " bez trafienia krytycznego";
				}
				else cout << setw(38) << left << "\nNie trafil";
				if (przeciwnikhit) {
					cout << "Trafil ";
					if (celkrytprzec) cout << "krytycznie";
					else cout << "Bez trafienia krytycznego";
				}
				else cout << "Nie trafil";
				if (hit) cout << endl << setw(6) << "Zadal" << setw(3) << dmg << setw(24) << left << " obrazen";
				else cout << endl << setw(33) << left << "Nie zadal obrazen";
				if (przeciwnikhit) cout << setw(10) << right << "Zadal " << setw(3) << przeciwnikdmg << setw(14) << left << " obrazen";
				else cout << "    Nie zadal obrazen" << endl;
				runda++;
				if (hp > 0)
				{
					if (hpprzeciwnik > 0)
					{
						cout << "Czy chcesz grac dalej?\n1.Tak!\n2.Nie!" << endl;
						cin >> kontynuuj;
						while (czykontynuuj(kontynuuj))
						{
							if (czykontynuuj(kontynuuj))
							{
								cin.clear();
								cout << "Podales zla cyfre(1-2)";
								cin >> kontynuuj;
							}
						}
						kontynuujliczba = stoi(kontynuuj);
						if (kontynuujliczba == 1)
						{
							czygramydalej = true;
						}
						else czygramydalej = false;
					}
					else czygramydalej = false;
				}
				else czygramydalej = false;
				if (system("CLS")) system("clear");
		}
		if (hpprzeciwnik < 0)
		{
			if (system("CLS")) system("clear");
			cout << "ZADALES "<<dmg<<" PUNKTOW OBRAZEN DZIEKI CZEMU WYMIERZYLES SMIERTELNY CIOS SWOJEMU PRZECIWNIKOWI!\nWYGRALES!GRATULACJE"<<endl;
		}
		else if (hp < 0)
		{
			if (system("CLS")) system("clear");
			cout << "PRZECIWNIK ZADAL"<<przeciwnikdmg<<" PUNKTOW OBRAZEN DZIEKI CZEMU WYMIERDZYL SMIERTELNY CIOS TWOJEMU BOHATEROWI!\nNIESTETY PRZEGRALES!"<<endl;
		}
		else cout << "PODDALES SIE W WALCE!\nPRZECIWNIK ZWYCIEZYL!"<<endl;
		//cout <<endl<< setw(6) << "Zadal " << setw(3) << dmg << setw(24) <<left<< " obrazen" << setw(6) << "Zadal " << setw(3) << przeciwnikdmg << setw(14) <<left<< " obrazen" << endl;
	system("pause");
}