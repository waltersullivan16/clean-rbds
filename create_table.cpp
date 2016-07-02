#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<int> otoczka;
vector<vector<int> > podzbiory_otoczki_blue;
vector<vector<int> > podzbiory_otoczki_red;
vector<vector<int> > choices;

struct wynik {
	int w;
	int o;
	int min;
  int red;
};

void wypiszGraf(vector<vector<int> > &graf){
	for(int i = 0;i<graf.size();i++){
		for(int j=0; j<graf[i].size();j++){
			cout<<graf[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void wczytajGraf(vector<vector<int> > &graf){
	int size;
	cin >> size;
 // cerr<<"size "<<size<<"\n";
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

set<int> kolorujOtoczke(vector<vector<int> > &graf, vector<int> wybrane){
	set<int> res;
//	cerr<<"size "<<wybrane.size()<<"\n";
	for(int i = 0; i<wybrane.size();i++)
	{
//		cerr<<"graf "<<graf[wybrane[i]].size()<<" wybrane[i] "<<wybrane[i]<<"\n";
		for (int j = 0; j<graf[wybrane[i]-1].size();j++){
			//cerr<<graf[wybrane[i]-1][j]<<" ";
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
			cout<<(*it)[i].w<<" "<<(*it)[i].o<<" "<<(*it)[i].min<<" "<<(*it)[i].red<<"\n";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int najmniejszeKolorowanie(vector<vector<int> > & graf, set<int> &pokolorowane, int red){
	if (pokolorowane.size() == red) return 0;
	int res = -1;
  //cerr<<"pokolorowane "<<pokolorowane.size()<<" "<<red<<"\n";
	for(int i = 0; i<choices.size();i++){
		set<int> pok = pokolorowane;
//				cout<<"red "<<red<< " pokolorowane "<<pokolorowane.size()<<" "<<graf.size()<<"\n";
		for(int j = 0; j<choices[i].size();j++){
			//	cout<<"ile "<<ile<<" i "<<i<<" j "<<j<<" pod "<<podzbiory2[ile][i][j]-1<<"\n";
			for (int z = 0; z <graf[choices[i][j]-1].size();z++) {
				pok.insert(graf[choices[i][j]-1][z]);
				//cerr<<"c "<<i<<" j "<<j<<" "<<graf[choices[i][j]-1][z]<<" ";
			}
		}
		//	cout<<"koniec\n";
		if (pok.size()==red) return choices[i].size();
	}
	//cout<<"koniec\n";
	return res;

}

bool szukaj(vector<vector<int> >& graf, wynik r, int w, int o, int min, int red, vector<int>& v,
    vector<int>& red_v){
	if ((r.min==min) && (r.red==red)) {
    return true;
    wypiszGraf(graf);
    cout<<"blue\n";
    for (int i = 0; i< v.size(); i++) cout<<v[i]<<" ";
    cout<<"\nred\n";
    for (int i = 0; i< red_v.size(); i++) cout<<red_v[i]<<" ";
    cout<<"\notoczka\n";
    wypiszSet(otoczka);
    cout<<podzbiory_otoczki_red[4][0];
    cout<<"\n";
		return true;
	}
	return false;
}

int countOtoczka(set<int> &s){
	int res = 0;
	for(set<int>::iterator iter=s.begin(); iter!=s.end();++iter) {

		if (otoczka.find(*iter)!=otoczka.end()) res++;
	}
	return res;
}

void addPodOt(set<int> &s, int h){
	for(int i =0; i<podzbiory_otoczki_red[h].size();i++) {
 //   cout<<"specjalne"<<podzbiory_otoczki_red[h][i]<<"\n";

		s.insert(podzbiory_otoczki_red[h][i]);
	}
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

struct otoczka_struct{
      int w1;
      int w2;
      int w3;
      int w4;
};

void wczytaj_otoczke_blue(int blue, otoczka current_otoczka){
	podzbiory_otoczki_blue =  {({},{}), ({1},{c}), {2},{blue-1},{blue}, {2, blue-1}};
 //choices for 9 blue verticles*1
 /*	choices = {
		{3},{4},{5},{6},{7},{3,4},{3,5},{3,6},{3,7},{4,5},{4,6},{4,7},{5,6},{5,7},{6,7},{3,4,5},{3,4,6},{3,4,7},{3,5,6},{3,5,7},{3,6,7},{4,5,6},{4,5,7},{4,6,7},{5,6,7},{3,4,5,6},{3,4,5,7},{3,4,6,7},{3,5,6,7},{4,5,6,7},{3,4,5,6,7}};
*/
  ///choices for 8 vertices
//choices = {
//		{3},{4},{5},{6},{3,4},{3,5},{3,6},{4,5},{4,6},{5,6},{3,4,5},{3,4,6},{3,5,6},{4,5,6},{3,4,5,6}};

choices = {
		{3},{4},{5},{3,4},{3,5},{4,5},{3,4,5}};

}

bool if_blue_in_red(set<int>& blue_set, set<int>& red_set, blue, otoczka& current_otoczka){
  vector<set<int> > red_sasiedzi = [{}, {currcsharpent_otoczka.w1, current_otoczka.w2}, {current_otoczka.w1, current_otoczka.w3}, {current_otoczka.w2, current_otoczka.w4}, {current_otoczka.w3, current_otoczka.w4}, {current_otoczka.w1, current_otoczka.w2, current_otoczka.w3, current_otoczka.w4}];
  for (set<int>::iterator it = blue_set.begin(); it != blue_set.end(); it++) {
    if{
  }
}
}

//TODO napisać wywalanie otoczki red jeżeli zawiera się w sąsiadach blue

otoczka wczytaj_otoczke_red(){
  struct otoczka_struct current_otoczka;
  cin >> current_otoczka.w1 >> current_otoczka.w2 >> current_otoczka.w3 >> current_otoczka.w4;
  //cerr<<current_otoczka.w1<< current_otoczka.w2 << current_otoczka.w3 << current_otoczka.w4<<"\n";
  otoczka = {current_otoczka.w1, current_otoczka.w2, current_otoczka.w3, current_otoczka.w4};
	podzbiory_otoczki_red =  {{}, {current_otoczka.w1},{current_otoczka.w2},{current_otoczka.w3},{current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2},{current_otoczka.w1,current_otoczka.w3},{current_otoczka.w1,current_otoczka.w4},{current_otoczka.w2,current_otoczka.w3},{current_otoczka.w2,current_otoczka.w4},{current_otoczka.w3,current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w3},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w4},{current_otoczka.w2,current_otoczka.w3,current_otoczka.w4},{current_otoczka.w1,current_otoczka.w2,current_otoczka.w3,current_otoczka.w4}};
  return current_otoczka;
}
int EDGES = 5;
int main(){
	int n, blue, red;
	set<vector<wynik> > wynikSet;
	cin >> n >> blue >> red;
	cerr<<"all graphs "<<n<<"\n";
  wczytaj_otoczke_blue(blue);
	for (int i = 0;i<n;i++){
    cerr <<i<<"\n";
		vector<int> wybrane_do_otoczki;
		vector<vector<int> > graf;
    otoczka current_otoczka = wczytaj_otoczke_red();
		wczytajGraf(graf);
		//wypiszGraf(graf);
		  vector<wynik> v;
      int szukaj_w = 0;
		for (int h2 = 0; h2 < podzbiory_otoczki_red.size(); h2++){
		  for (int h = 0; h < podzbiory_otoczki_blue.size(); h++){
				//cerr<<"beginning of the loop\n";
				set<int> s = kolorujOtoczke(graf,podzbiory_otoczki_blue[h]);
				addPodOt(s,h2);
				//cerr<<"koloruj\n";
				int wybrane = podzbiory_otoczki_blue[h].size();
				//cerr<<"ilosc wybranyc wierzcholkow "<<wybrane<<"\n";
				int ot = countOtoczka(s);
				//cerr<<"ilosc wierzcholkow na otoczce "<<ot<<"\n";

				int naj = najmniejszeKolorowanie(graf,s,red);
        if ((wybrane+naj)>2 && h!=EDGES) naj = -2; //EDGES to wierzchołki 2 i 4 - nie chcemy ich uwzględniać w wykluczeniu, ponieważ kolorują inne rzeczy z otoczki
				//cerr<<"najmniejsze kolorowanie dla tego wyboru "<<naj<<"\n";
				wynik r;
				r.w = wybrane;
				r.o=ot;
				r.min = naj;
        r.red = h2;
       // cerr<<"h2"<<h2<<"\n";
				v.push_back(r);
			}
		}
		  wynikSet.insert(v);

		}
		wypiszVectorWynik(wynikSet);
	}
