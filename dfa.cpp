#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;

int l[10000][27];
list<int> l_reverse[10000];
pair<int, int> matrix[22001][5001];
int can_arr_to_fin[5002];
int final[100];

int nr, n, sigma, m, k;
int st_init;
bool find_sol = false;
int nr_can_arr, check;

void read(){
    ifstream fin("input.txt");
    fin >> nr >> n >> sigma >> m >> k >> st_init;
    for(int i = 0; i < m; i++){
        fin >> final[i];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < sigma; j++){
            fin >> l[i][j];
            l_reverse[l[i][j]].push_back(i);
        }
    fin.close();
}

// gasim nodurile care pot ajunge în starea finală
// dacă între nod și destinație nu există drum, atunci
// îl putem considera o stare de FAIL

void parse(int final){
    stack<int> stack;
    stack.push(final);
    while (!stack.empty())
    {
        int s = stack.top();
        stack.pop();
        for(auto i : l_reverse[s])
            if(can_arr_to_fin[i] == 0){
                can_arr_to_fin[i] = 1;
                nr_can_arr++;
                stack.push(i);
            }
    }
}

int main(){
    bool will_be_sol = true;
    int i = 1;
    ofstream fout("output.txt");
    read();

    for(int j = 0; j < m; j++){
        parse(final[j]);
    }
 
    for(int i = 0; i < sigma; i++){   
        matrix[1][l[st_init][i]] = make_pair(st_init, i);
    }
    
    while(will_be_sol){
        will_be_sol = false;
        for(int j = 1; j <= n; j++)

            // verificam daca s-a ajuns in starea respectiva si
            // daca nu este stare de FAIL
            if(matrix[i][j].first != 0 && can_arr_to_fin[j] == 1){
                will_be_sol = true;
                for(int eps = 0; eps < sigma; eps++)
                    matrix[i + 1][l[j][eps]] = make_pair(j, eps);
            }

        if(i >= k && will_be_sol){
            // in acest pas orice stare finala accesata
            // este valida

            for(int j = 0; j < m; j++)
                if(matrix[i][final[j]].first != 0){
                    string sol;
                    int dist = i, dest = final[j];
                    while(dist > 0){ 
                        sol.push_back(matrix[dist][dest].second + 'a');
                        dest = matrix[dist][dest].first;
                        dist--;
                    }

                    // dupa ce construim traseul parcurs îl inversăm
                    // deoarece vrem să începem cu sursa
                    
                    int l = sol.length();
                    for (int eps = 0; eps < l / 2; eps++)
                        swap(sol[eps], sol[l - eps - 1]);
                    fout << i << " " << sol;
                    fout.close();
                    return 0;
                }
        }
        i++;
        
    }
    fout << "-1";
    fout.close();
    return 0;
    
}