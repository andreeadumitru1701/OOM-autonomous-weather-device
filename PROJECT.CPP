#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

class utilizator
{
	private: char*id;
		static int nr;
	public: utilizator();
		utilizator(char*);
		~utilizator();
		static int get_nr();
};

	int utilizator::nr=0;

utilizator::utilizator()
{
	id=0;
	++nr;
}

utilizator::utilizator(char*a)
{
	id=new char[strlen(a)+1];
	strcpy(id,a);
	++nr;
}

utilizator::~utilizator()
{
	delete id;
	--nr;
}

int utilizator::get_nr()
{
	cout<<"\n Numarul utilizatorilor activi:";
	return nr;
}

class panou_control
{
	public: panou_control();
		~panou_control();
		inline void oprire_panou()
		{
			cout<<"\n Panou de control dezactivat.";
		}
		inline void masuratoare_noua()
		{
			cout<<"\n Se initiaza o noua masuratoare...";
		}
		inline void email()
		{
			cout<<"\n Se trimite email cu datele inregistrate...";
		}
};

panou_control::panou_control()
{
	cout<<"\n Panou de control activat";
}

panou_control::~panou_control()
{
}

class aparat
{
	public: aparat();
		inline void oprire_aparat()
		{
			cout<<"\n Aparat oprit.";
		}
		~aparat();
};

aparat::aparat()
{
	cout<<"\n Pornire aparat...";
}

aparat::~aparat()
{
}

class senzor
{
	public: senzor();
		virtual void analiza_date();
		virtual float calibrare();
};

senzor::senzor()
{
}

void senzor::analiza_date()
{
	cout<<"\n Se analizeaza datele...";
}

float senzor::calibrare()
{
	cout<<"\n Aparatul se calibreaza...";
	return 0.0;
}

class senzor_presiune:public senzor
{
	private: char*tip_senzor;
		float presiune;
	public: senzor_presiune();
		senzor_presiune(char*, float);
		~senzor_presiune();
		void selectare();
		void masoara();
		void transmite_date();
		void analiza_date();
		void afisare_date();
		float calibrare();
};

senzor_presiune::senzor_presiune()
{
	tip_senzor="Senzor presiune";
	presiune=0.0;
}

senzor_presiune::senzor_presiune(char*c, float d)
{
	tip_senzor=new char[strlen(c)+1];
	strcpy(tip_senzor,c);
	presiune=d;
}

senzor_presiune::~senzor_presiune()
{
	delete tip_senzor;
}

void senzor_presiune::selectare()
{
	cout<<"\n Senzor presiune selectat";
}

void senzor_presiune::masoara()
{
	cout<<"\n Se masoara presiunea...";
}

void senzor_presiune::analiza_date()
{
	if (presiune<695)
		cout<<"\n ALERTA - Va aflati in zona depresionara!";
	else if (presiune>803)
		cout<<"\n ALERTA - Anticiclon!";
}

void senzor_presiune::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_presiune::afisare_date()
{
	cout<<"\n Presiune inregistrata:"<<presiune<<"mmHg";
}

float senzor_presiune::calibrare()
{
	presiune=0.0;
	cout<<"\n Presiune:";
	return presiune;
}

class senzor_temperatura:public senzor
{
	private: char*tip_senzor;
		float temperatura;
	public: senzor_temperatura();
		senzor_temperatura(char*, float);
		~senzor_temperatura();
		void selectare();
		void masoara();
		void transmite_date();
		void analiza_date();
		void afisare_date();
		float calibrare();
};

senzor_temperatura::senzor_temperatura()
{
	tip_senzor="Senzor temperatura";
	temperatura=0.0;
}

senzor_temperatura::senzor_temperatura(char*e, float f)
{
	tip_senzor=new char[strlen(e)+1];
	strcpy(tip_senzor,e);
	temperatura=f;
}

senzor_temperatura::~senzor_temperatura()
{
	delete tip_senzor;
}

void senzor_temperatura::selectare()
{
	cout<<"\n Senzor temperatura selectat";
}

void senzor_temperatura::masoara()
{
	cout<<"\n Se masoara temperatura...";
}

void senzor_temperatura::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_temperatura::analiza_date()
{
	if (temperatura>30)
		cout<<"\n ALERTA - Canicula!";
	else if (temperatura<0)
		cout<<"\n ALERTA - Inghet!";
}

void senzor_temperatura::afisare_date()
{
	cout<<"\n Temperatura inregistrata:"<<temperatura<<"grade Celsius";
}

float senzor_temperatura::calibrare()
{
	temperatura=0.0;
	cout<<"\n Temperatura:";
	return temperatura;
}

class senzor_precipitatii:public senzor
{
	private: char*tip_senzor;
		float precipitatii;
	public: senzor_precipitatii();
		senzor_precipitatii(char*g, float h);
		~senzor_precipitatii();
		void selectare();
		void masoara();
		void transmite_date();
		void analiza_date();
		void afisare_date();
		float calibrare();
};

senzor_precipitatii::senzor_precipitatii()
{
	tip_senzor="Senzor precipitatii";
	precipitatii=0.0;
}

senzor_precipitatii::senzor_precipitatii(char*i, float j)
{
	tip_senzor=new char[strlen(i)+1];
	strcpy(tip_senzor,i);
	precipitatii=j;
}

senzor_precipitatii::~senzor_precipitatii()
{
	delete tip_senzor;
}

void senzor_precipitatii::selectare()
{
	cout<<"\n Senzor precipitatii selectat";
}

void senzor_precipitatii::masoara()
{
	cout<<"\n Se masoara nivelul de precipitatii...";
}

void senzor_precipitatii::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_precipitatii::analiza_date()
{
	if (precipitatii>=10.0)
		cout<<"\n ALERTA - Inundatie!";
	else if (precipitatii>1.0)
		cout<<"\n ALERTA - Ploaie!";
}

void senzor_precipitatii::afisare_date()
{
	cout<<"\n Precipitatii inregistrate:"<<precipitatii<<"mm";
}

float senzor_precipitatii::calibrare()
{
	precipitatii=0.0;
	cout<<"\n Precipitatii:";
	return precipitatii;
}

class senzor_lumina:public senzor
{
	private: char*tip_senzor;
		float lumina;
	public: senzor_lumina();
		senzor_lumina(char*, float);
		~senzor_lumina();
		void selectare();
		void masoara();
		void transmite_date();
		void afisare_date();
		float calibrare();
};

senzor_lumina::senzor_lumina()
{
	tip_senzor="Senzor lumina";
	lumina=0.0;
}

senzor_lumina::senzor_lumina(char*k, float l)
{
	tip_senzor=new char[strlen(k)+1];
	strcpy(tip_senzor,k);
	lumina=l;
}

senzor_lumina::~senzor_lumina()
{
	delete tip_senzor;
}

void senzor_lumina::selectare()
{
	cout<<"\n Senzor lumina selectat";
}

void senzor_lumina::masoara()
{
	cout<<"\n Se masoara intensitatea luminoasa...";
}

void senzor_lumina::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_lumina::afisare_date()
{
	cout<<"\n Grad luminos inregistrat:"<<lumina<<"lumeni";
}

float senzor_lumina::calibrare()
{
	lumina=0.0;
	cout<<"\n Lumina:";
	return lumina;
}

class senzor_ceata:public senzor
{
	private: char*tip_senzor;
		float ceata;
	public: senzor_ceata();
		senzor_ceata(char*, float);
		~senzor_ceata();
		void selectare();
		void masoara();
		void transmite_date();
		void analiza_date();
		void afisare_date();
		float calibrare();
};

senzor_ceata::senzor_ceata()
{
	tip_senzor="Senzor ceata";
	ceata=0.0;
}

senzor_ceata::senzor_ceata(char*m, float n)
{
	tip_senzor=new char[strlen(m)+1];
	strcpy(tip_senzor,m);
	ceata=n;
}

senzor_ceata::~senzor_ceata()
{
	delete tip_senzor;
}

void senzor_ceata::selectare()
{
	cout<<"\n Senzor ceata selectat";
}

void senzor_ceata::masoara()
{
	cout<<"\n Se masoara nivelul de ceata...";
}

void senzor_ceata::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_ceata::analiza_date()
{
	if (ceata>=20.0)
		cout<<"\n ALERTA - Ceata!";
}

void senzor_ceata::afisare_date()
{
	cout<<"\n Grad de ceata inregistrat:"<<ceata<<"%";
}

float senzor_ceata::calibrare()
{
	ceata=0.0;
	cout<<"\n Ceata:";
	return ceata;
}

class senzor_umiditate:public senzor
{
	private: char*tip_senzor;
		float umiditate;
	public: senzor_umiditate();
		senzor_umiditate(char*, float);
		~senzor_umiditate();
		void selectare();
		void masoara();
		void transmite_date();
		void analiza_date();
		void afisare_date();
		float calibrare();
};

senzor_umiditate::senzor_umiditate()
{
	tip_senzor="Senzor umiditate";
	umiditate=0.0;
}

senzor_umiditate::senzor_umiditate(char*o, float p)
{
	tip_senzor=new char[strlen(o)+1];
	strcpy(tip_senzor,o);
	umiditate=p;
}

senzor_umiditate::~senzor_umiditate()
{
	delete tip_senzor;
}

void senzor_umiditate::selectare()
{
	cout<<"\n Senzor umiditate selectat";
}

void senzor_umiditate::masoara()
{
	cout<<"\n Se masoara umiditatea...";
}

void senzor_umiditate::transmite_date()
{
	cout<<"\n Se transmit date catre panoul de control...";
}

void senzor_umiditate::analiza_date()
{
	if (umiditate>=50.0)
		cout<<"\n ALERTA - Umezeala!";
}

void senzor_umiditate::afisare_date()
{
	cout<<"\n Grad umiditate inregistrat:"<<umiditate<<"%";
}

float senzor_umiditate::calibrare()
{
	umiditate=0.0;
	cout<<"\n Umiditate:";
	return umiditate;
}

class monitorizare
{
	public: monitorizare();
		~monitorizare();
		virtual void afisare_date();
};

monitorizare::monitorizare()
{
	cout<<"\n Monitorizare date";
}

monitorizare::~monitorizare()
{
	cout<<"\n Monitorizare incheiata.";
}

void monitorizare::afisare_date()
{
	cout<<"\n Datele inregistrate sunt:";
}

void main()
{
	clrscr();
	int x;
	aparat a0;
	panou_control pc0;
	cout<<"\n Selectati una dintre optiunile aparatului meteo:";
	cout<<"\n 1 - Calibrare aparat";
	cout<<"\n 2 - Inregistreaza date";
	cout<<"\n 3 - Monitorizare date";
	cout<<"\n 4 - Utilizatori activi";
	cout<<"\n 5 - Oprire aparat";
	cin>>x;

	utilizator u1("admin");
	senzor_presiune sp0, sp1("Senzor presiune", 780);
	senzor_presiune sp2("Senzor presiune", 660);
	senzor_presiune sp3("Senzor presiune", 810);
	senzor_temperatura st0, st1("Senzor temperatura", 40);
	senzor_temperatura st2("Senzor temperatura", 13);
	senzor_temperatura st3("Senzor temperatura", -10);
	senzor_precipitatii spr0, spr1("Senzor precipitatii", 1.4);
	senzor_precipitatii spr2("Senzor precipitatii", 11);
	senzor_precipitatii spr3("Senzor precipitatii", 6);
	senzor_lumina sl0, sl1("Senzor lumina", 70);
	senzor_lumina sl2("Senzor lumina", 100);
	senzor_lumina sl3("Senzor lumina", 150);
	senzor_ceata sc0, sc1("Senzor ceata", 25);
	senzor_ceata sc2("Senzor ceata", 14);
	senzor_ceata sc3("Senzor ceata", 50);
	senzor_umiditate su0, su1("Senzor umiditate", 15);
	senzor_umiditate su2("Senzor umiditate", 12);
	senzor_umiditate su3("Senzor umiditate", 52);
	senzor s0;

	switch(x)
	{
		case 1: senzor*ptr;
			ptr=&s0;
			cout<<ptr->calibrare();
			ptr=&sp0;
			cout<<ptr->calibrare();
			ptr=&st0;
			cout<<ptr->calibrare();
			ptr=&spr0;
			cout<<ptr->calibrare();
			ptr=&sl0;
			cout<<ptr->calibrare();
			ptr=&sc0;
			cout<<ptr->calibrare();
			ptr=&su0;
			cout<<ptr->calibrare();
			break;
		case 2: pc0.masuratoare_noua();
			sp1.masoara();
			sp1.transmite_date();
			sp1.afisare_date();
			st3.masoara();
			st3.afisare_date();
			spr1.masoara();
			spr1.afisare_date();
			sl1.masoara();
			sl1.afisare_date();
			sc2.masoara();
			sc2.afisare_date();
			su1.masoara();
			su1.afisare_date();
			senzor*ptrx;
			ptrx=&s0;
			ptrx->analiza_date();
			ptrx=&sp1; ptrx->analiza_date();
			ptrx=&st3; ptrx->analiza_date();
			ptrx=&spr1; ptrx->analiza_date();
			ptrx=&sl1; ptrx->analiza_date();
			ptrx=&sc2; ptrx->analiza_date();
			ptrx=&su1; ptrx->analiza_date();
			break;
		case 3:	cout<<"\n Ultimele date inregistrate:";
			sp2.afisare_date();
			st2.afisare_date();
			spr3.afisare_date();
			sl2.afisare_date();
			sc3.afisare_date();
			su3.afisare_date();
			senzor*ptrz;
			ptrz=&s0;
			ptrz->analiza_date();
			ptrz=&sp2; ptrz->analiza_date();
			ptrz=&st2; ptrz->analiza_date();
			ptrz=&spr3; ptrz->analiza_date();
			ptrz=&sl2; ptrz->analiza_date();
			ptrz=&sc3; ptrz->analiza_date();
			ptrz=&su3; ptrz->analiza_date();
			pc0.email();
			break;
		case 4: cout<<utilizator::get_nr();
			break;
		case 5: pc0.oprire_panou();
			a0.oprire_aparat();
			break;


		default: cout<<"\n Selectati o alta optiune";
	}

	cout<<"\n Press ENTER key to continue...";
	getchar();

}