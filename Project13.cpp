
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
//clasa abstracta
class detalii_rochii {
public:
	virtual void detaliiImbracaminte() = 0;
	virtual float stocvandut() = 0;
};

//clasa has a


//clasa de baza
class Rochie : public detalii_rochii
{
private:
	char* culoare;
	string material;
	int nr_bucati;
	int* marime_bucati;
	const int nr_rochie;
	static int nr;
	
public:
	//constructori
	Rochie() :nr_rochie(++nr)
	{

		this->culoare = new char[strlen("nonculoare") + 1];
		strcpy(this->culoare, "nonculoare");
		this->material = "neidentificat";
		this->nr_bucati = 0;
		this->marime_bucati = nullptr;

	}

	Rochie(const char* culoare, string material, int nr_bucati, int* marime_bucati) :nr_rochie(++nr)
	{
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		this->material = material;
		this->nr_bucati = nr_bucati;
		this->marime_bucati = new int[nr_bucati];
		for (int i = 0; i < nr_bucati; i++)
		{
			this->marime_bucati[i] = marime_bucati[i];
		}
	}


	Rochie(const char* culoare) :nr_rochie(++nr)
	{
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		this->material = "neidentificat";
		this->nr_bucati = 0;
		this->marime_bucati = nullptr;
	}

	Rochie(Rochie& r) :nr_rochie(++nr)
	{
		if (r.culoare != nullptr)
		{
			this->culoare = new char[strlen(r.culoare) + 1];
			strcpy(this->culoare, r.culoare);


		}
		else
		{
			this->culoare = nullptr;
		}
		this->material = r.material;
		this->nr_bucati = r.nr_bucati;
		if (r.marime_bucati != nullptr)
		{
			this->marime_bucati = new int[nr_bucati];
			for (int i = 0;i < r.nr_bucati;i++)
			{
				this->marime_bucati[i] = r.marime_bucati[i];
			}
		}
		else
		{
			this->marime_bucati = nullptr;
		}
	}


	//getteri si setteri 

	char* getCuloare()
	{
		if (culoare != nullptr)
		{
			return culoare;
		}
		else
		{
			return 0;
		}
	}


	void setCuloare(const char* culoare)
	{
		if (culoare == nullptr)
		{
			cout << " !eroare: culoare nu poate fi null" << endl;
			return;
		}


		if (this->culoare != nullptr && strcmp(this->culoare, culoare) == 0)
		{
			cout << " !eroare: este aceeasi culoare" << endl;
			return;
		}


		if (this->culoare != nullptr)
		{
			delete[] this->culoare;
		}


		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
	}

	string getmaterial()
	{
		return material;
	}

	void setmaterial(string materialNou)
	{
		if (material != materialNou)
		{
			material = materialNou;
		}
		else
		{
			cout << " !eroare, sunt la fel!";
		}

	}


	int get_nr_buc()
	{
		return nr_bucati;
	}


	void set_nr_buc(int nr_nou)
	{
		if (nr_nou == 0)
		{
			cout << " Stocul este zero";

		}
		if (nr_nou < 0)
		{
			cout << "!eroare, nr de buc nu poate fi negativ";
		}
		if (nr_nou > 0)
		{
			nr_bucati = nr_nou;
		}
	}



	int getmarimi(int index)
	{
		if (index >= 0 && index < nr_bucati)
		{
			return marime_bucati[index];
		}

	}

	void setmarimi(const int* vector, int lungime)
	{
		if (marime_bucati != nullptr)
		{
			delete[] marime_bucati;

		}
		if (lungime > nr_bucati)
		{
			cout << "nu se poate";
		}
		marime_bucati = new int[lungime];
		for (int i = 0;i < lungime;i++)
		{
			marime_bucati[i] = vector[i];

		}
	}


	//op egal

	Rochie& operator=(Rochie& r)
	{
		if (r.culoare != nullptr)
		{
			if (culoare != nullptr)
			{
				delete[] culoare;
			}

			this->culoare = new char[strlen(r.culoare) + 1];
			strcpy(culoare, r.culoare);
		}

		material = r.material;
		nr_bucati = r.nr_bucati;

		if (r.marime_bucati != nullptr)
		{
			if (marime_bucati != nullptr)
			{
				delete[] marime_bucati;
			}

			this->marime_bucati = new int[r.nr_bucati];
			for (int i = 0;i < r.nr_bucati;i++)
			{
				marime_bucati[i] = r.marime_bucati[i];
			}
		}
		return *this;
	}

	//
	void detaliiImbracaminte() override
	{
		cout << endl;
		cout << endl << "nr identificare rochie: " << nr_rochie;
		cout << endl << "culoare: " << culoare;
		cout << endl << "materila: " << material;
		cout << endl << "nr buc disponibile: " << nr_bucati;
		cout << endl << "marimi disponibile: ";
		for (int i = 0;i < nr_bucati;i++)
		{
			cout << marime_bucati[i] << ", ";
		}
	}

	float stocvandut() override
	{
		cout << endl << "din 1000 de buc s-au vandut: ";
		if (marime_bucati == nullptr) // Verificăm pointerul corect
		{
			cout << "1000 " << endl;
			return 1000;
		}
		else
		{
			float stoc = 1000 - nr_bucati;
			cout << stoc << endl;
			return stoc;
		}
	}

	//afisare si scriere

	friend ostream& operator<<(ostream& out, Rochie r)
	{
		out << endl;
		out << endl << "nr identificare rochie: " << r.nr_rochie;
		out << endl << "culoare: " << r.culoare;
		out << endl << "material: " << r.material;
		out << endl << "nr buc disponibile: " << r.nr_bucati;
		out << endl << "marimi disponibile: ";
		for (int i = 0;i < r.nr_bucati;i++)
		{
			out << r.marime_bucati[i] << ", ";
		}
		return out;
	}

	friend istream& operator>>(istream& in, Rochie& r)
	{

		if (r.culoare != nullptr)
		{
			delete[] r.culoare;
			r.culoare = nullptr;
		}


		cout << "culoare: ";
		char temp[256];
		in >> temp;
		r.culoare = new char[strlen(temp) + 1];
		strcpy(r.culoare, temp);

		cout << "material: ";
		in >> r.material;


		cout << "nr buc: ";
		in >> r.nr_bucati;

		r.marime_bucati = new int[r.nr_bucati];
		for (int i = 0; i < r.nr_bucati; i++)
		{
			cout << "introduceti marimea pt bucata " << i + 1 << ": ";
			in >> r.marime_bucati[i];
		}

		return in;
	}
	//alti operatori
   //1. 
	Rochie& operator+(Rochie& r)
	{
		material = material + " & " + r.material;
		return *this;
	}

	//2.
	Rochie& operator++(int)
	{
		Rochie temp = *this;
		nr_bucati++;
		return temp;
	}


	Rochie& operator++()
	{
		++nr_bucati;
		return *this;
	}
	//3
	Rochie& operator--(int)
	{
		Rochie temp = *this;
		nr_bucati--;
		return temp;
	}


	Rochie& operator--()
	{
		--nr_bucati;
		return *this;
	}

	//4.
	int operator[](int index)
	{
		if (index >= 0 && index <= nr_bucati)
		{
			return marime_bucati[index];
		}
		else
		{

			return -1;
		}
	}
	//5.

	bool operator==(Rochie& r)
	{
		if (nr_bucati == r.nr_bucati)
		{
			return true;
		}
		else
			return false;
	}


	//scriere si citire din fisier

	friend ofstream& operator<<(ofstream& fout, Rochie& r)
	{
		fout << r.culoare;
		fout << endl << r.material;
		fout << endl << r.nr_bucati;
		for (int i = 0;i < r.nr_bucati;i++)
		{
			fout << endl << r.marime_bucati[i];
		}

		return fout;

	}


	friend ifstream& operator>>(ifstream& fin, Rochie& r)
	{
		char temp[30];
		fin >> temp;
		if (r.culoare != nullptr)
		{
			delete[] r.culoare;
		}
		r.culoare = new char[strlen(temp) + 1];
		strcpy(r.culoare, temp);
		fin >> r.material;
		fin >> r.nr_bucati;
		if (r.marime_bucati != nullptr)
		{
			delete[]  r.marime_bucati;
		}
		r.marime_bucati = new int[r.nr_bucati];
		for (int i = 0;i < r.nr_bucati;i++)
		{
			fin >> r.marime_bucati[i];
		}

		return fin;
	}

	//destructor
	~Rochie()
	{
		delete[] culoare;
		delete[] marime_bucati;
	}
};

int Rochie::nr = 0;

//clasa has a

class magazin {
private:
	Rochie* rochii;
	int nr_rochii;
	string nume;
	string adresa;
	int nr_angajati;
	int* varsta_angajati;	
public:		
	magazin()
	{
		this->rochii = nullptr;
		this->nr_rochii = 0;
		this->nume = "neidentificat";
		this->adresa = "neidentificat";
		this->nr_angajati = 0;
		this->varsta_angajati = nullptr;
	}

	magazin(Rochie* rochii, int nr_rochii, string nume, string adresa, int nr_angajati, int* varsta_angajati)
	{
		this->rochii = new Rochie[nr_rochii];
		for (int i = 0; i < nr_rochii; i++)
		{
			this->rochii[i] = rochii[i];
		}
		this->nr_rochii = nr_rochii;
		this->nume = nume;
		this->adresa = adresa;
		this->nr_angajati = nr_angajati;
		this->varsta_angajati = new int[nr_angajati];
		for (int i = 0; i < nr_angajati; i++)
		{
			this->varsta_angajati[i] = varsta_angajati[i];
		}

	}

	magazin(Rochie* rochii, int nr_rochii, string nume, string adresa) 
	{
		this->rochii = new Rochie[nr_rochii];
		for (int i = 0; i < nr_rochii; i++)
		{
			this->rochii[i] = rochii[i];
		}
		this->nr_rochii = nr_rochii;
		this->nume = nume;
		this->adresa = adresa;
		this->nr_angajati = 0;
		this->varsta_angajati = nullptr;


	}

	magazin(const magazin& m)
	{
		if (m.rochii != nullptr)
		{
			this->rochii = new Rochie[m.nr_rochii];
			for (int i = 0; i < m.nr_rochii; i++)
			{
				this->rochii[i] = m.rochii[i];
			}
		}
		else
		{
			this->rochii = nullptr;
		}
		this->nr_rochii = m.nr_rochii;
		this->nume = m.nume;
		this->adresa = m.adresa;
		this->nr_angajati = m.nr_angajati;
		if (m.varsta_angajati != nullptr)
		{
			this->varsta_angajati = new int[m.nr_angajati];
			for (int i = 0; i < m.nr_angajati; i++)
			{
				this->varsta_angajati[i] = m.varsta_angajati[i];
			}
		}
		else
		{
			this->varsta_angajati = nullptr;
		}

	}


	//op egal

	magazin& operator=(magazin& m)
	{
		if (m.rochii != nullptr)
		{
			if (rochii != nullptr)
			{
				delete[] rochii;
			}
			this->rochii = new Rochie[m.nr_rochii];
			for (int i = 0; i < m.nr_rochii; i++)
			{
				this->rochii[i] = m.rochii[i];
			}
		}
		else
		{
			this->rochii = nullptr;
		}
		this->nr_rochii = m.nr_rochii;
		this->nume = m.nume;
		this->adresa = m.adresa;
		this->nr_angajati = m.nr_angajati;
		if (m.varsta_angajati != nullptr)
		{
			if (varsta_angajati != nullptr)
			{
				delete[] varsta_angajati;
			}
			this->varsta_angajati = new int[m.nr_angajati];
			for (int i = 0; i < m.nr_angajati; i++)
			{
				this->varsta_angajati[i] = m.varsta_angajati[i];
			}
		}
		else
		{
			this->varsta_angajati = nullptr;
		}
		return *this;

	}

	//afisare si citire	

	friend ostream& operator<<(ostream& out, magazin& m)
	{
		out << endl;
		out << endl << "nume magazin: " << m.nume;
		out << endl << "adresa: " << m.adresa;
		out << endl << "nr rochii: " << m.nr_rochii;
		out << endl << "nr angajati: " << m.nr_angajati;
		out << endl << "varsta angajati: ";
		for (int i = 0; i < m.nr_angajati; i++)
		{
			out << m.varsta_angajati[i] << ", ";
		}
		out << endl << "rochii: ";
		for (int i = 0; i < m.nr_rochii; i++)
		{
			out << m.rochii[i] << endl;
		}
		return out;
	}


	friend istream& operator>>(istream& in, magazin& m)
	{
		if (m.rochii != nullptr)
		{
			delete[] m.rochii;
			m.rochii = nullptr;
		}
		if (m.varsta_angajati != nullptr)
		{
			delete[] m.varsta_angajati;
			m.varsta_angajati = nullptr;
		}
		cout << "nume magazin: ";
		in >> m.nume;
		cout << "adresa: ";
		in >> m.adresa;
		cout << "nr rochii: ";
		in >> m.nr_rochii;
		cout << "nr angajati: ";
		in >> m.nr_angajati;
		m.rochii = new Rochie[m.nr_rochii];
		for (int i = 0; i < m.nr_rochii; i++)
		{
			cout << "introduceti rochia " << i + 1 << ": ";
			in >> m.rochii[i];
		}
		m.varsta_angajati = new int[m.nr_angajati];
		for (int i = 0; i < m.nr_angajati; i++)
		{
			cout << "introduceti varsta angajatului " << i + 1 << ": ";
			in >> m.varsta_angajati[i];
		}
		return in;
	}

	//alti operatori
	 
	// 1.
	magazin& operator+(magazin& m)
	{
		magazin temp = *this;
		temp.nr_rochii = nr_rochii + m.nr_rochii;
		temp.rochii = new Rochie[temp.nr_rochii];
		for (int i = 0; i < nr_rochii; i++)
		{
			temp.rochii[i] = rochii[i];
		}
		for (int i = 0; i < m.nr_rochii; i++)
		{
			temp.rochii[i + nr_rochii] = m.rochii[i];
		}
		return temp;
	}
	//getteri si setteri 
	
	string getnume()
	{
		return nume;
	}

	void setnume(string numeNou)
	{
		if (nume != numeNou)
		{
			nume = numeNou;
		}
		else
		{
			cout << " !eroare, numele este acelasi!";
		}
	}

	string getadresa()
	{
		return adresa;
	}

	void setadresa(string adresaNoua)
	{
		if (adresa != adresaNoua)
		{
			adresa = adresaNoua;
		}
		else
		{
			cout << " !eroare, adresa este aceeasi!";
		}
	}

	int getnr_angajati()
	{
		return nr_angajati;
	}

	void setnr_angajati(int nr_angajatiNou)
	{
		if (nr_angajati != nr_angajatiNou)
		{
			nr_angajati = nr_angajatiNou;
		}
		else
		{
			cout << " !eroare, nr angajati este acelasi!";
		}
	}

	int getvarsta_angajati(int index)
	{
		if (index >= 0 && index < nr_angajati)
		{
			return varsta_angajati[index];
		}
		else
		{
			return -1;
		}
	}

	void setvarsta_angajati(int* vector, int lungime)
	{
		if (varsta_angajati != nullptr)
		{
			delete[] varsta_angajati;
		}
		if (lungime > nr_angajati)
		{
			cout << " !eroare, nu se poate!";
		}
		varsta_angajati = new int[lungime];
		for (int i = 0; i < lungime; i++)
		{
			varsta_angajati[i] = vector[i];
		}
	}

	


	//2.
	magazin& operator++(int)
	{
		magazin temp = *this;
		nr_angajati++;
		return temp;
	}

	magazin& operator++()
	{
		++nr_angajati;
		return *this;
	}

	//3.
	magazin& operator--(int)
	{
		magazin temp = *this;
		nr_angajati--;
		return temp;
	}

	magazin& operator--()
	{
		--nr_angajati;
		return *this;
	}
	//destructor		
	~magazin()
	{
		delete[] rochii;
		delete[] varsta_angajati;
	}


	};

//IS A
class rochiecocktail : public Rochie
{
private:
	static string lungime;
	char* ocazie;
	int temperatura_spalare;

public:
	//constructori
	rochiecocktail()
	{
		this->ocazie = new char[strlen("neidentificata") + 1];
		strcpy(this->ocazie, "neidentificata");
		this->temperatura_spalare = 10;
	}

	rochiecocktail(const char* ocazie, int temperatura_spalare, const char* culoare, string material, int nr_bucati, int* marime_bucati) :Rochie(culoare, material, nr_bucati, marime_bucati)
	{
		if (ocazie != nullptr)
		{
			this->ocazie = new char[strlen(ocazie) + 1];
			strcpy(this->ocazie, ocazie);

		}
		else
		{
			this->ocazie = nullptr;
		}
		this->temperatura_spalare = temperatura_spalare;

	}

	rochiecocktail(const char* ocazie, const char* culoare) :Rochie(culoare)
	{
		if (ocazie != nullptr)
		{
			this->ocazie = new char[strlen(ocazie) + 1];
			strcpy(this->ocazie, ocazie);
		}
		else
		{
			this->ocazie = nullptr;
		}
		this->temperatura_spalare = 10;
	}

	//const de copiere


	rochiecocktail(rochiecocktail& rc) :Rochie(rc)
	{
		if (rc.ocazie != nullptr)
		{
			this->ocazie = new char[strlen(rc.ocazie) + 1];
			strcpy(this->ocazie, rc.ocazie);
		}
		else
		{
			this->ocazie = nullptr;
		}
	}

	//operator egal

	rochiecocktail& operator=(rochiecocktail& rc)
	{
		Rochie::operator=(rc);
		if (rc.ocazie != nullptr)
		{
			if (ocazie != nullptr)
			{
				delete[] ocazie;
			}

			ocazie = new char[strlen(rc.ocazie) + 1];
			strcpy(ocazie, rc.ocazie);
		}
		return *this;
	}

	//citire+afisare

	friend ostream& operator<<(ostream& out, rochiecocktail& rc) {
		out << (Rochie&)rc;
		out << endl << "Ocazie: " << rc.ocazie;
		out << endl << "Lungime: " << lungime;
		out << endl << "Temperatura spalare: " << rc.temperatura_spalare;
		return out;
	}

	friend istream& operator>>(istream& in, rochiecocktail& rc) {
		cout << endl;
		in >> (Rochie&)rc;
		if (rc.ocazie != nullptr) {
			delete[] rc.ocazie;
		}
		char temp[30];
		cout << endl << "tipul ocaziei: ";
		in >> temp;
		rc.ocazie = new char[strlen(temp) + 1];
		strcpy(rc.ocazie, temp);
		cout << endl << "temperatura spalare: ";
		in >> rc.temperatura_spalare;

		return in;
	}

	//getteri si setteri

	char* getocazie()
	{
		return ocazie;
	}

	void setocazie(const char* ocazieNoua)
	{
		if (ocazie != nullptr)
		{
			delete[] ocazie;
		}
		if (strcmp(ocazie, ocazieNoua) != 0)
		{
			ocazie = new char[strlen(ocazieNoua) + 1];
			strcpy(ocazie, ocazieNoua);
		}
		else
		{
			cout << " !Eroare! Nu reprezinta o modificare";
			return;
		}
	}


	string getlungime()
	{
		return lungime;
	}

	void setlungime(string lungimemodf)
	{
		if (lungimemodf != "scurta")
		{
			lungime = lungimemodf;
		}
		else
		{
			cout << endl << "!eroare!lungimea este deja scurta!";
		}
	}

	int gettemp()
	{
		return temperatura_spalare;
	}

	void settemp(int temperatura_spalareN)
	{
		if (temperatura_spalareN < 0)
		{
			cout << "!eroare, hainele se degradeaza!";
		}
		else
			temperatura_spalare = temperatura_spalareN;
	}
	//operatori
	//1.
	rochiecocktail& operator+(string detaliu)
	{
		lungime = lungime + " de exact " + detaliu + " cm ";
		return *this;
	}

	//2.
	bool operator==(rochiecocktail& rc)
	{
		if (temperatura_spalare == rc.temperatura_spalare)
		{
			return true;
		}
		else
			return false;
	}
	//3.
	bool operator!()
	{
		if (temperatura_spalare == 0)
		{
			return true;
		}
		else
			return false;
	}

	//destructor
	~rochiecocktail()
	{
		delete[] ocazie;
	}
};

string rochiecocktail::lungime = "scurta";

void main() {
	//constructori, operatori =, <<, >>, functii virtuale
	Rochie r1;
	r1.detaliiImbracaminte();



	Rochie r2("roz", "bumbac", 3, new int [3] {29, 32, 40});
	r2.detaliiImbracaminte();
	r1 = r2;


	Rochie r3 = r2;

	r3.detaliiImbracaminte();



	r3 = r1;
	cout << r3;
	cout << endl;
	r3.stocvandut();


	Rochie r4;
	cin >> r4;
	cout << r4;
	cout << endl << "culoare veche: " << r4.getCuloare();
	r4.setCuloare(NULL);

	//getteri si setteri

	cout << endl << "culoare veche: " << r3.getCuloare();
	r3.setCuloare("maro");
	cout << ", culoare noua: " << r3.getCuloare();

	cout << endl << "material vechi: " << r3.getmaterial();
	r3.setmaterial("tulle");
	cout << ", material nou: " << r3.getmaterial();

	cout << endl << " nr buc vechi: " << r3.get_nr_buc();
	int n = r3.get_nr_buc();
	r3.set_nr_buc(5);
	cout << ", nr buc nou: " << r3.get_nr_buc();

	cout << endl << "marimi vechi: ";

	for (int i = 0;i < n;i++)
	{
		cout << r3.getmarimi(i) << ", ";
	}
	cout << endl << "marimi noi: ";
	int vector[5] = { 30,32,34,36,38 };

	r3.setmarimi(vector, r3.get_nr_buc());
	for (int i = 0;i < r3.get_nr_buc();i++)
	{
		cout << r3.getmarimi(i) << ", ";
	}
	//operatori
	r3 + r2;
	cout << endl << "r3+r2 " << r3.getmaterial();

	r3++;
	++r3;
	cout << endl << "nr buc dupa pre si post incrementare: " << r3.get_nr_buc();
	r3--;
	--r3;
	cout << endl << "nr buc dupa pre si post decrementare: " << r3.get_nr_buc();
	cout << endl << "marimea a 2 a disponibila din r2: " << r2[1];

	if (r1 == r2)
	{
		cout << endl << " r1 si r2 au acelasi nr de buc";
	}

	if (r1 == r3)
	{
		cout << endl << "r1 si r3 au acelasi nr de buc";
	}
	else
	{
		if (r1.get_nr_buc() < r3.get_nr_buc())
		{
			cout << endl << "r3 are mai multe buc";
		}
		else
		{
			cout << endl << "r1 are mai multe buc";

		}
	}
	//citire fisier+scriere fisier
	ofstream fileOut("fisier.txt", ios::out);
	fileOut << r2;
	fileOut.close();
	cout << endl << "sccriere reusita!";

	ifstream fileIn("fisier.txt", ios::in);
	Rochie r7;
	fileIn >> r7;
	fileIn.close();
	cout << r7 << endl;
	//CLASA DERIVATA IS A
	cout << endl << "CLASA DERIVATA- IS A" << endl;

	rochiecocktail rc1;
	cout << rc1;

	rochiecocktail rc2("seara", 20, "rosie", "bumbac", 1, new int[1] {36});
	cout << rc2;

	rochiecocktail rc3(rc2);
	cout << rc3;

	rc3 = rc1;
	cout << rc3;

	rochiecocktail rc4;
	cout << endl << "inainte de scriere: " << rc4;
	cin >> rc4;
	cout << endl << "dupa scriere: " << rc4;
	//getteri+setteri
	rc4.setocazie("seara");
	cout << endl << "dupa setter ocazie: " << rc4;

	cout << endl << "lungime veche: " << rc3.getlungime();
	rc3.setlungime("midi");
	cout << endl << "lungime noua: " << rc3.getlungime();

	cout << endl << "temperatura veche: " << rc3.gettemp();
	cout << endl << "temperatura noua: ";
	rc3.settemp(-2);

	//operatori
	rc3 + "20";
	cout << endl << "lungime: " << rc3.getlungime();

	if (rc2 == rc3)
	{
		cout << endl << "rochiile se spala la aceeasi temperatura!";
	}
	else
	{
		cout << endl << "rochiile se spala la temperaturi diferite!";
	}

	rc4.settemp(rc2.gettemp());
	if (rc2 == rc4)
	{
		cout << endl << "rochiile se spala la aceeasi temperatura!";
	}
	else
	{
		cout << endl << "rochiile se spala la temperaturi diferite!";
	}

	rochiecocktail rc5;
	rc5.settemp(0);
	if (!rc5)
	{
		cout << endl << "ATENTIE! Temperatura de spalare este de 0 grade!";
	}
    else
	{
		cout << endl << "Temperatura de spalare este diferita de 0 grade!";
	}
	//clasa has a
	//constructori
	magazin m1;
	cout << m1;

	magazin m2(&r2, 1, "Zara", "Iasi", 4, new int[4] {20, 25,45,35});
	cout << m2;

	magazin m4(&r3, 1, "H&M", "Bucuresti");
	cout << m4;

	magazin m3(m2);
	cout << m3;

	
	
	//op egal
	m1 = m2;
	cout << m1;
	


	//oper
	m1 + m2;
	cout << m1;

	m1++;
	cout << m1;

	++m1;
	cout << m1;

	m1--;
	cout << m1;

	--m1;
	cout << m1;

	//citire+afisare
	cout << "inainte de scriere: " << m4;
	cin >> m4;
	cout << "dupa scriere: " << m4;

	//getteri si sett
	cout << "nume veche: " << m4.getnume();
	m4.setnume("Zara");
	cout << ", nume nou: " << m4.getnume();

	cout << "adresa veche: " << m4.getadresa();
	m4.setadresa("Ploiesti");
	cout << ", adresa noua: " << m4.getadresa();

	cout << "nr angajati vechi: " << m4.getnr_angajati();
	m4.setnr_angajati(3);
    cout << ", nr angajati nou: " << m4.getnr_angajati();
	
	cout << "varsta angajati veche: ";
	for (int i = 0; i < m2.getnr_angajati(); i++)
	{
		cout << m2.getvarsta_angajati(i) << ", ";
	}
	cout << endl << "varsta angajati noua: ";
	int vec[3] = { 20, 25, 30 };
	m2.setnr_angajati(3);
	m2.setvarsta_angajati(vec, m2.getnr_angajati());
	for (int i = 0; i < m2.getnr_angajati(); i++)
	{
		cout << m2.getvarsta_angajati(i) << ", ";
	}

		



}