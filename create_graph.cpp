#include<iostream>
#include<vector>
#include "ciagi.h"
using namespace std;

typedef vector<vector<int> > graf;
typedef vector<vector<int> > layer;

layer red_layer;
layer blue_layer;

void make_layer(int blue, int red_l, int red_r){
	red_layer.clear();
	blue_layer.clear();
	vector<int> first_b = {1};
	blue_layer.push_back(first_b);
	vector<int> second_b;
	for (int i = 2; i <= blue-1; i++){
		second_b.push_back(i);
	}
	blue_layer.push_back(second_b);
	vector<int> third_b = {blue};
	blue_layer.push_back(third_b);
	vector<int> first_r;
	for (int i = 1; i <= red_l; i++){
		first_r.push_back(i);
	}
	red_layer.push_back(first_r);
	vector<int> second_r;
	for (int i = red_l+1; i <= red_r+red_l; i++){
		second_r.push_back(i);
	}
	red_layer.push_back(second_r);
}
void wypiszGraf(graf *g){
  cout<<g->size()-1<<"\n";
  for(int i = 1;i<g->size();i++){
    cout<<(*g)[i].size()<<"\n";
    for(int j=0; j<(*g)[i].size();j++){
      cout<<(*g)[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void init(graf *g, int blue){
	int r_l = red_layer[0].size();
	int r_p = red_layer[1].size();
	int b_mid = blue_layer[1].size();
	for(int i = 0; i<r_l;i++){
		(*g)[1].push_back(red_layer[0][i]);
	}
	for(int i = 0; i<r_p;i++){
		(*g)[blue].push_back(red_layer[1][i]);
	}
}
int ile = 0;

//void createL(int ile){

//}
vector<vector<int> > *changeGraf(vector<vector<int> > *graf,int blue, int red){
  vector<vector<int> > *res = new vector<vector<int> >();
  for(int i = 1;i<graf->size();i++){
    vector<int> tmp;
    for(int j=0; j<(*graf)[i].size();j++){
      tmp.push_back((*graf)[i][j]+blue);
    }
    res->push_back(tmp);
  }
  for (int i = 0; i<red; i++){
    vector<int> tmp;
    res->push_back(tmp);
  }
  for (int j = 0;j<graf->size();j++){
    for(int z =0; z<(*graf)[j].size();z++){
      (*res)[blue+(*graf)[j][z]-1].push_back(j);
    }
  }
//wypiszGraf(res);
  return res;
}
bool podzbior(vector<int> &v1, vector<int>&v2){
  int j = 0;
  for(int i = 0; i<v1.size();i++){
    if (j>=v2.size()) return false;
    while (v2[j]<v1[i]) j++;
    if (j>=v2.size()) return false;
    if (v2[j]==v1[i]) j++;
    else {

      return false;}

  }
/*cout<<"wektory\n";
for (int i =0;i<v1.size();i++){
cout<<v1[i]<<" ";
}
cout<<"\n";
for (int i =0;i<v2.size();i++){
cout<<v2[i]<<" ";
}*/
  return true;
}
bool rule1(vector<vector<int> > *graf, int blue, int red) {

  for(int i = 1; i < graf->size();i++){
    for(int j = i+1; j<graf->size();j++){
      if (podzbior((*graf)[i],(*graf)[j])||podzbior((*graf)[j],(*graf)[i]))  {
//cerr<<"not rule1\n";
        return false;
      }
    }
  }
  return true;
}
bool rule12(vector<vector<int> > *graf, int blue, int red) {
  vector<vector<int> > *g2 = changeGraf(graf,blue,red);

  for(int i = 1; i < g2->size();i++){
    for(int j = i+1; j<g2->size();j++){
      if (podzbior((*g2)[i],(*g2)[j])||podzbior((*g2)[j],(*g2)[i]))  {
        delete g2;
//cout<<"i "<<i<<" j "<<j<<"\n";
//cerr<<"not rule12\n";
        return false;
      }
    }
  }
  delete g2;
  return true;
}


bool check(vector<vector<int> > *graf, int blue, int red) {
  if (rule12(graf,blue,red))

    return true;
  else return false;
}

void endGraf(graf *g, int i, int j,int blue, int r_l, int r_p){
int z = 0;
//string a1 = "112222334444";
//string b="111122223344";
string s1=ciagi[r_l][blue-2][i];
string s2=ciagi[r_p][blue-2][j];
//cout<<"a to jest "<<ciagi[r_p][blue-2][i]<<"\n";
	for (int q=2;q<=blue_layer[1].size()+1;q++){
			for (int a = (s1[z]-'0');a<=(s1[z+1]-'0');a++){
//cout<<"q "<<q<<" a "<<a<<"\n";
				(*g)[q].push_back(a);
	}
z+=2;
}
z = 0;
//cout<<"a to jest "<<ciagi[r_p][blue-2][j]<<"\n";
	for (int q=2;q<=blue_layer[1].size()+1;q++){
			for (int a = (s2[z]-'0');a<=(s2[z+1]-'0');a++){
				(*g)[q].push_back(a+r_l);
	}
z+=2;
}
}
void createLeft(int blue, int beg, long long res){
	if (blue<=0) {
cout<<"\""<<1<<res<<red_layer[0].size()<<"\""<<", ";
ile++;
		return;
	}
	for (int i = beg;i<=red_layer[0].size(); i++) {
		createLeft(blue-1,i,(res*10+i));
	}
}

void makeGraph(int r_l, int r_r, int blue){
  int z=0;
  int razem=0;
  int all = ciagi[r_l][blue-2].size();
  for (int i =0; i<ciagi[r_l][blue-2].size();i++){
      for (int j =0; j<ciagi[r_r][blue-2].size();j++){
	graf *g = new graf();
	for (int i= 0; i <blue+1;i++){
		vector<int> v;
		g->push_back(v);
	}
	init(g,blue);
		z++;
if (z%1000==0) cerr<<z<<"/"<<all*all<<"\n";
	endGraf(g,i,j,blue,r_l,r_r);
			if (check(g,blue,r_l+r_r)) {

				wypiszGraf(g);
razem++;
			}
delete g;
		}
}
cout<<razem<<"\n";
//createLeft(2*6-2,1,0);
}



int main(){
int blue,r_l,r_p,r;
cin>>blue>>r;
//wypiszGraf(&red_layer);
//cout<<"\n";
//wypiszGraf(&blue_layer);
//cout<<"\n";
r_l=0;
r_p=r;
while (r_p>0){
cout<<1<<" "<<r_l<<" "<<r_l+1<<" "<<r_l+r_p<<"\n";
make_layer(blue,r_l,r_p);
makeGraph(r_l,r_p,blue);
r_l++;
r_p--;
}
}