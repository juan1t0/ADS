#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;
void printVector(vector<string>&a) {
	size_t len = a.size();
	for (size_t i = 0; i < len; i++) {
		cout << a[i] << "|";
	}
	cout << endl;
}
vector<string> convertir(vector<string> &stop_words, string &line) {
	string palabra="";
	vector<string> temporal;
	size_t ll = line.size() -1;
	size_t csw = stop_words.size();
	for (size_t i = 0; i < ll; i++) {
		switch (line[i])
		{
		case ' ':
			if(palabra != "")
				temporal.push_back(palabra);
			palabra = "";
			break;
		case ',':
			break;
		case '.':
			break;
		case '\'':
			palabra += line[i];
			break;
		default:
			if ((line[i] > 122) || (line[i] < 97))
				if ((line[i] > 64) && (line[i] < 91)){
					line[i] += 32;
					palabra += line[i];
				}
				else
					break;
			else
				palabra += line[i];
			break;
		}
	}
	temporal.push_back(palabra);
	//printVector(temporal);
	size_t &ct = ll;
	ct = temporal.size();
	///////////////////////////////
	for (size_t i = 0; i < csw; i++) {
		for (size_t j = 0; j < ct; j++) {
			if (temporal[j] == stop_words[i]) {
				temporal.erase(temporal.begin()+j);
				j--;
			}
		}
	}
	return temporal;
}
void limpiarVW (vector<string> &a){
//	size_t sizeA = a.size()-1;
	sort(a.begin(), a.end());
	size_t i = 0;
	while ( i < a.size() - 1) {
		if (a[i] == a[i + 1]) {
			a.erase(a.begin() + i);
		}
		else
			i++;
	}
}
vector<string> makeSetWords(vector<vector<string>> &A) {
	size_t Vcnt, vcnt;
	vector<string> words;
	Vcnt = A.size();
	short ind = 0;
	for (size_t i = 0; i < Vcnt; i++) {
		vcnt = A[i].size();
		for (size_t j = 0; j < vcnt; j++) {
			words.push_back(A[i][j]);
		}
		//printVector(words);
		limpiarVW(words);
	}
	return words;
}
vector<vector<int>> foo_uno(vector<string> &SetWords, vector<vector<string>> &setWords) {
	size_t sizeSW = setWords.size(), tot = SetWords.size(),sis;
	vector<vector<int>> matriz(sizeSW);
	for (size_t i = 0; i < sizeSW; i++) {
		matriz[i].assign(tot-1, 0);
		sis = setWords[i].size();
		for (size_t j = 0; j < sis; j++) {
			for (size_t k = 0; k < tot; k++) {
				if (setWords[i][j] == SetWords[k]) {
					matriz[i][k] += 1;
					//cout << SetWords[k] << endl;
				}
			}
		}
	}
	return matriz;
}
int main() {
	vector<string> stop_words;
	{
		std::ifstream ifs("NewStopWord.txt");
		//std::ifstream ifs("StopWord.txt");
		boost::archive::text_iarchive ia(ifs);
		ia & stop_words;
	}
	//printVector(stop_words);
	vector<vector<string>> setWords;
	string line="",nameNew,aux;
	int x;
	cin >> x;
	ifstream niu;
	for (int i = 1; i <= x; i++) {
		nameNew = "Noticias\\NOTICIA (" + to_string(i) + ").txt";
		//cout << nameNew << endl;
		niu.open(nameNew);
		while (getline(niu, aux)) {
			line += aux + " ";
		}
		//cout << line << endl;
		vector<string> FeatureVector = convertir(stop_words, line);
		//printVector(FeatureVector);
		niu.close();
		line = "";
		setWords.push_back(FeatureVector);
//		cout << i << " ";
	}
	//cout << setWords[x / 2].size() << endl;
	//system("PAUSE");
	vector<string> SetWords = makeSetWords(setWords);
	//system("PAUSE");
	//printVector(SetWords);
	vector<vector<int>> M_data = foo_uno(SetWords, setWords);
	/*
	for (int i = 0; i < M_data.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < M_data[i].size(); j++) {
			cout << M_data[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << M_data.size() << " " << M_data[0].size() << endl;
	/**
	std::vector<string> words;
	string p;
	ifstream w("NewStopW.txt");
	while (getline(w, p)) {
		words.push_back(p);
	}
	printVector(words);
	// serialize vector
	{
		ofstream ofs("NewStopWord.txt");
		boost::archive::text_oarchive oa(ofs);
		oa & words;
	}

	//system("PAUSE");*/

	return 0;
}