#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct wynik {
	int w;
	int o;
	int min;
  int red;
bool operator<(const wynik& rhs) const
    {
        if (w < rhs.w)
        {
           return true;
        }
        else if (w == rhs.w)
        {
            if (o < rhs.o)
            {
                return true;
            }
            else if (o == rhs.o)
            {
                return min < rhs.min;
            }
        }
}
};


int main(){
int n1, n2;
cin>>n1;
set<vector<wynik> > s1;
set<vector<wynik> > s2;
for (int i =0; i<n1;i++){
	vector<wynik> v;
	for (int j = 0; j<75; j++){
		wynik w;
		cin>>w.w;
		cin>>w.o;
		cin>>w.min;
		cin>>w.red;
		v.push_back(w);
	}
	s1.insert(v);
}
cin>>n2;
for (int i =0; i<n2;i++){
	vector<wynik> v;
	for (int j = 0; j<75; j++){
		wynik w;
		cin>>w.w;
		cin>>w.o;
		cin>>w.min;
		cin>>w.red;
		v.push_back(w);
	}
	s2.insert(v);
}
int all=0;
	for(set<vector<wynik > >::iterator iter=s1.begin(); iter!=s1.end();++iter) {
		if (s2.find(*iter)==s2.end()) {
all++;
			for (int i =0; i<(*iter).size();i++){
				cout<<(*iter)[i].w<<" "<<(*iter)[i].o<<" "<<(*iter)[i].min<<" "<<(*iter)[i].red<<"\n";
			}
			cout<<"\n\n";
		}
	}
cout<<all<<"\n";
}
