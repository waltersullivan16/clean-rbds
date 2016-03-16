#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> otoczka;
vector<vector<vector<int> > > podzbiory_otoczki_blue;
vector<vector<vector<int> > > podzbiory_otoczk_red;
vector<vector<vector<int> > > choices;

struct wynik {
	int w;
	int o;
	int min;
};

void wypiszGraf(vector<vector<int> > &graf){
	for(int i = 0;i<graf.size();i++){
		for(int j=0; j<graf[i].size();j++){
			cerr<<graf[i][j]<<" ";
		}
		cerr<<"\n";
	}
}

void wczytajGraf(vector<vector<int> > &graf){
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int m;
		cin >> m;
		vector<int> edges;
		for (int j = 0; j<m;j++) {
			int e;
			cin >>e;
			edges.push_back(e);
		}
		graf.push_back(edges);
	}
}

set<int> kolorujOtoczke(vector<vector<int> > &graf, vector<int> wybrane, int otoczka){
	set<int> res;
	cerr<<"size "<<wybrane.size()<<"\n";
	for(int i = 0; i<wybrane.size();i++)
	{
		cerr<<"graf "<<graf[wybrane[i]].size()<<" wybrane[i] "<<wybrane[i]<<"\n";
		for (int j = 0; j<graf[wybrane[i]-1].size();j++){
			cerr<<graf[wybrane[i]-1][j]<<" ";
			res.insert(graf[wybrane[i]-1][j]);
		}
	}
	return res;
}

void wypiszSet(set<int> &s){
	for(set<int>::iterator iter=s.begin(); iter!=s.end();++iter) {
		cout<<*iter<<" ";
	}
	cout<<"\n";
}
void wypiszVectorWynik(set<vector<wynik> > &s){
	cout<<s.size()<<"\n";
	for(set<vector<wynik> >::iterator it = s.begin(); it!=s.end();it++){
		for(int i = 0; i<(*it).size();i++){
			cout<<(*it)[i].w<<" "<<(*it)[i].o<<" "<<(*it)[i].min<<"\n";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int najmniejszeKolorowanie(vector<vector<int> > & graf, set<int> &pokolorowane, int red, int otoczka){
	if (pokolorowane.size() == red) return 0;
	int res = -1;
	int ile = graf.size()-otoczka;
	for(int i = 0; i<podzbiory2[ile].size();i++){
		set<int> pok = pokolorowane;
		//		cout<<"red "<<red<<" ile "<<ile<<" otoczka "<<otoczka<<" pokolorowane "<<pokolorowane.size()<<" "<<graf.size()<<" "<<otoczka<<"\n";
		for(int j = 0; j<podzbiory2[ile][i].size();j++){
			//	cout<<"ile "<<ile<<" i "<<i<<" j "<<j<<" pod "<<podzbiory2[ile][i][j]-1<<"\n";
			for (int z = 0; z <graf[podzbiory2[ile][i][j]-1].size();z++) {
				pok.insert(graf[podzbiory2[ile][i][j]-1][z]);
				//cout<<graf[podzbiory2[ile][i][j]-1][z]<<" ";
			}
		}
		//	cout<<"koniec\n";
		if (pok.size()==red) return podzbiory2[ile][i].size();
	}
	//cout<<"koniec\n";
	return res;

}

bool szukaj(vector<vector<int> >& graf, wynik r, int w, int o, int min, vector<int>& v){
	if ((r.w==w)&&(r.o==o)&&(r.min==min)) {wypiszGraf(graf);
		cout<<"\n\nwzieta\n";
		for (int i =0;i<v.size();i++) cout<<v[i]<<" "<<"\n";
		cout<<"\n";
		return true;
	}
	return false;
}

int countOtoczka(set<int> &s, int otoczka){
	int res = 0;
	for(set<int>::iterator iter=s.begin(); iter!=s.end();++iter) {

		if (oto.find(*iter)!=oto.end()) res++;
	}
	return res;
}

void addPodOt(set<int> &s, int h){
	for(int i =0; i<podOt[h].size();i++) {

		s.insert(podOt[h][i]);
	}
	//if (res==0) {wypiszSet(s);
	//cout<<"\n\n";}
}
inline bool operator<(const wynik& lhs, const wynik& rhs)
{
	if (lhs.w==rhs.w) {
		if (lhs.o==rhs.o) {
			return lhs.min < rhs.min;
		}
		return lhs.o<rhs.o;
	}
	return lhs.w<rhs.w;
}

struct otoczka{
      int w1;
      int w2;
      int w3;
      int w4;
};

void wczytaj_otoczke_blue(){
	podzbiory_otoczki_blue =  {{{0}},{{1}},{{1},{2},{1,2}},{{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}},{{1},{2},{blue-1},{blue},{1,2},{1,blue-1},{1,blue},{2,blue-1},{2,blue},{blue-1,blue},{1,2,blue-1},{1,2,blue},{2,blue-1,blue},{1,2,blue-1,blue}}};
	choices = {
		{{0}},
		{{5}},
		{{5},{6},{5,6}},
		{{5},{6},{7},{5,6},{5,7},{6,7},{5,6,7}},
		{{3},{4},{5},{6},{3,4},{3,5},{3,6},{4,5},{4,6},{5,6},{3,4,5},{3,4,6},{3,5,6},{4,5,6},{3,4,5,6}},
		{{3},{4},{5},{6},{7},{3,4},{3,5},{3,6},{3,7},{4,5},{4,6},{4,7},{5,6},{5,7},{6,7},{3,4,5},{3,4,6},{3,4,7},{3,5,6},{3,5,7},{3,6,7},{4,5,6},{4,5,7},{4,6,7},{5,6,7},{3,4,5,6},{3,4,5,7},{3,4,6,7},{3,5,6,7},{4,5,6,7},{3,4,5,6,7}},
		{{3},{4},{5},{6},{7},{8},{3,4},{3,5},{3,6},{3,7},{3,8},{4,5},{4,6},{4,7},{4,8},{5,6},{5,7},{5,8},{6,7},{6,8},{3,4,5},{3,4,6},{3,4,7},{3,4,8},{3,5,6},{3,5,7},{3,5,8},{3,6,7},{3,6,8},{3,7,8},{4,5,6},{4,5,7},{4,5,8},{4,6,7},{4,6,8},{4,7,8},{5,6,7},{5,6,8},{5,7,8},{3,4,5,6},{3,4,5,7},{3,4,5,8},{3,4,6,7},{3,4,6,8},{3,4,7,8},{3,5,6,7},{3,5,6,8},{3,5,7,8},{4,5,6,7},{4,5,6,8},{4,5,7,8},{4,6,7,8},{5,6,7,8},{3,4,5,6,7},{3,4,5,6,8},{4,5,6,7,8},{3,4,5,6,7,8}},};
}

void wczytaj_otoczke_red(){
  struct otoczka current_otoczka;
  cin >> current_otoczka.w1 >> current_otoczka.w2 >> current_otoczka.w3 >> current_otoczka.w4;
  otoczka = {current_otoczka.w1, current_otoczka.w2, current_otoczka.w3, current_otoczka.w4};
	podzbiory_otoczki_red =  {{current_otoczka.w1},{current_otoczka.w2},{current_otoczka.w3},{current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2},{current_otoczka.w1,current_otoczka.w3},{current_otoczka.w1,current_otoczka.w4},{current_otoczka.w2,current_otoczka.w3},{current_otoczka.w2,current_otoczka.w4},{current_otoczka.w3,current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w3},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w4},{current_otoczka.w2,current_otoczka.w3,current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w3,current_otoczka.w4}};
}
int main(){
	int n, blue, red;
	set<vector<wynik> > wynikSet;
	cin >> n >> blue >> red;
	cerr<<"all graphs "<<n<<"\n";
  wczytaj_otoczke_blue();
  //ONLY FOR TESTS TODO Change that!
  n = 1;
	for (int i = 0;i<n;i++){
		vector<int> wybrane_do_otoczki;
		vector<vector<int> > graf;
		wczytajGraf(graf);
		wypiszGraf(graf);
    wczytaj_otoczke_red();
		vector<wynik> v;
		for (int h = 0; h < podzbiory_otoczki_blue[otoczka].size(); h++){
			for (int h2 = 0; h2 < choices.size(); h2++){
				cerr<<"beginning of the loop\n";
				set<int> s = kolorujOtoczke(graf, podzbiory_otoczki_blue[otoczka][h], otoczka);
				addPodOt(s,h2);
				//	wypiszSet(s);
				cerr<<"koloruj\n";
				int wybrane = podzbiory_otoczki_blue[otoczka][h].size();
				cerr<<"ilosc wybranyc wierzcholkow "<<wybrane<<"\n";
				int ot = countOtoczka(s, otoczka);
				cerr<<"ilosc wierzcholkow na otoczce "<<ot<<"\n";

				int naj = najmniejszeKolorowanie(graf,s,red,otoczka);
				cerr<<"najmniejsze kolorowanie dla tego wyboru "<<naj<<"\n";
				wynik r;
				r.w = wybrane;
				r.o=ot;
				r.min = naj;
				//				if (szukaj(graf,r,2,4,3, podzbiory[otoczka][h])) return 1;
				v.push_back(r);
			}
		}

		wynikSet.insert(v);
		}
		wypiszVectorWynik(wynikSet);
	}
