#include <bits/stdc++.h>

using namespace std;

using SeedPair = pair<int, int>;
using Sorter = function<bool(const SeedPair&, const SeedPair&)>;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime, Sorter sorter){
	vector <pair <int, int>> ps;
	int totalPlantTime = 0, res = 0;

	for (int i = 0; i < plantTime.size(); i++)
		ps.push_back({plantTime[i], growTime[i]});

	sort(ps.begin(), ps.end(), sorter);

	for (auto p : ps) {
		totalPlantTime += p.first;
		res = max(res, totalPlantTime + p.second);
	}
	
	return res;
}

int main(){
	int n, k, in;

	vector <vector<int>> solucoes;

	while(cin >> n){
		k = n;
		vector <int> plantTime, growTime;
		vector <int> testeAtual;
		
		while (k--){
			cin >> in;
			plantTime.push_back(in);
		}

		k = n;

		while (k--){
			cin >> in;
			growTime.push_back(in);
		}

		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return l.first < r.first;
    		}));

    		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return l.first > r.first;
       		}));

		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return l.second < r.second;
    		}));

    		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return l.second > r.second;
    		}));

		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return (l.first + l.second) < (r.first + r.second);
    		}));

    		testeAtual.push_back(earliestFullBloom(plantTime, growTime, [](const SeedPair &l, const SeedPair &r) {
        	    return (l.first + l.second) > (r.first + r.second);
    		}));

		solucoes.push_back(testeAtual);
	}

	for (int i = 0; i < solucoes.size(); ++i){
		const vector<int>& sol = solucoes[i];
 
		cout << "--- Caso de Teste " << i + 1 << " ---\n";
       		cout << "PlantTime crescente:    " << sol[0] << '\n';
       		cout << "PlantTime decrescente:  " << sol[1] << '\n';
       		cout << "GrowTime crescente:     " << sol[2] << '\n';
       		cout << "Full bloom crescente:   " << sol[4] << '\n';
       		cout << "Full bloom decrescente: " << sol[5] << "\n\n";
       		cout << "GrowTime decrescente:   " << sol[3] << '\n';
       		cout << "\n";
	}

	return 0;
}
