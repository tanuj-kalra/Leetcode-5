#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

typedef unordered_map<int, unordered_set<int> > Graph;

vector<int> topologicalSort(Graph &gr) { // destructive
    vector<int> sorted;
    queue<int> degree_zero;
    while(!gr.empty()) {
        for(Graph::iterator i = gr.begin(), j = i; i != gr.end(); i = j) {
            j++;
            if(i->second.empty()) {
                degree_zero.push(i->first);
                gr.erase(i);
            }
        }
        while(!degree_zero.empty()) {
            int node = degree_zero.front();
            degree_zero.pop();
            sorted.push_back(node);
            for(Graph::iterator i = gr.begin(); i != gr.end(); i++)
                i->second.erase(node);
        }
    }
    return sorted;
}

int main() {
    Graph G;
    G[0].insert(1);
    G[0].insert(2);
    G[1].insert(2);
    G[2].empty();
    G[5].insert(4);
    G[1].insert(5);
    G[4].empty();
    
    vector<int> sorted = topologicalSort(G);
    for(int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << endl;

    return 0;
}
