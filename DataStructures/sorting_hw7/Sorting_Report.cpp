#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

void sorting(vector<pair<string, string>> &v, int column, int direction);
bool continueSorting(int sortingColumn, vector<pair<string, string>>& v, pair<string, string> curVal, int sortIndex, int direction);

int main() {
ifstream fin;
ofstream fout;
fin.open("Officeoursout_HW7.txt");
if(fin.fail()) {
    cout<<"File opening failed!"<<endl;
}
  vector<pair<string, string>> v;
  while(!fin.eof()) {
      pair<string, string> nameTopic;
      string studentName;
      string topic;
      fin>>studentName>>topic;
      nameTopic.first = studentName;
      nameTopic.second = topic;
      v.push_back(nameTopic);
  }
    fout.open("nameAscend.txt");
    sorting(v, 0, 0); //Column 0 is sorting by name, direction 0 is ascending.
    for (auto d: v) {
        fout << d.first << " " << d.second << endl;
    }
    fout.close();
    fout.open("nameDescend.txt");
    sorting(v, 0, 1); //Column 0 is sorting by name, direction 1 is descending.
    for (auto d: v) {
        fout << d.first << " " << d.second << endl;
    }
    fout.close();
    fout.open("topicAscend.txt");
    sorting(v, 1, 0); //Column 1 is sorting by topic, direction 0 is ascending.
    for (auto d: v) {
        fout << d.first << " " << d.second << endl;
    }
    fout.close();
    fout.open("topicDescend.txt");
    sorting(v, 1, 1); //Column 1 is sorting by name, direction 1 is descending.
    for (auto d: v) {
        fout << d.first << " " << d.second << endl;
    }


}
void sorting(vector<pair<string, string>> &v, int column, int direction) {
    for (int i = 1; i < v.size(); i++) {
        pair<string, string> curVal = v[i];
        int sortIndex = i - 1;
        while (continueSorting(column, v, curVal, sortIndex, direction)) {
            v[sortIndex + 1] = v[sortIndex];
            sortIndex--;
        }
        v[sortIndex + 1] = curVal;
    }

}
bool continueSorting(int sortingColumn, vector<pair<string, string>>& v, pair<string, string> curVal, int sortIndex, int direction) {
    if(sortingColumn == 1) {
        if(direction == 0) {
            return (sortIndex > -1 && v[sortIndex].second > curVal.second);
        }
        return (sortIndex > -1 && v[sortIndex].second < curVal.second);
    } else {
        if(direction == 0) {
            return (sortIndex > -1 && v[sortIndex].first > curVal.first);
        }
        return (sortIndex > -1 && v[sortIndex].first < curVal.first);
    }
}





