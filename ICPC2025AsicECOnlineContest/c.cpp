#include <bits/stdc++.h>
#define int long long

using namespace std;

signed find_max(vector<int> & F){
    int _max = 0;
    signed index = 1;
    for (signed i = 1; i <= 7; i++){
        if (F[i] > _max){
            _max = F[i];
            index = i;
        }
    }
    return index;
}

signed find_min(vector<int> & F){
    int _min = 0;
    signed index = 1;
    for (signed i = 1; i <= 3; i++){
        if (F[i] < _min){
            _min = F[i];
            index = i;
        }
    }
    return index;
}

vector<int> ff(const vector<int> & F){
    vector<int> a(4, 0);
    a[1] += F[3] + F[5];
    a[2] += F[3] + F[6];
    a[3] += F[5] + F[6];
    return a;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        vector<int> F(8, 0);
        vector<int> stu(4, 0);
        int S;
        cin >> S;
        for (signed j = 1; j <= 7; j++){
            cin >> F[j];
        }

        stu[1] = F[1];
        stu[2] = F[2];
        stu[3] = F[4];
        F[1] = 0;
        F[2] = 0;
        F[4] = 0;

        while (F[3] != 0 || F[5] != 0 || F[6] != 0 || F[7] != 0){
g:          signed index = find_max(F);
            switch (index){
                case 3:
                    while (F[3] != 0){
                        if (stu[1] > stu[2]){
                            stu[2]++;
                        }
                        else if (stu[2] > stu[1]){
                            stu[1]++;
                        }
                        else{
                            vector<int>a = ff(F);
                            if (a[1] > a[2]){
                                stu[2]++;
                            }
                            else{
                                stu[1]++;
                            }
                        }
                        F[3]--;
                        signed ot = find_max(F);
                        if (ot != index){
                            goto g;
                        }
                    }
                    break;
                case 5:
                    while (F[5] != 0){
                        if (stu[1] > stu[3]){
                            stu[3]++; 
                        }
                        else if (stu[3] > stu[1]){
                            stu[1]++;
                        }
                        else{
                            vector<int> a = ff(F);
                            if (a[1] > a[3]){
                                stu[3]++;
                            }
                            else{
                                stu[1]++;
                            }
                        }
                        F[5]--;
                        signed ot = find_max(F);
                        if (ot != index){
                            goto g;
                        }
                    }
                    break;
                case 6:
                    while (F[6] != 0){
                        if (stu[2] > stu[3]){
                            stu[3]++;
                        }
                        else if (stu[3] > stu[2]){
                            stu[2]++;
                        }
                        else{
                        vector<int> a = ff(F);
                            if (a[1] > a[3]){
                                stu[3]++;
                            }
                            else{
                                stu[1]++;
                            }
                        }
                        F[6]--;
                        signed ot = find_max(F);
                        if (ot != index){
                            goto g;
                        }
                    }
                    break;
                case 7:
                    while (F[7] != 0){
                        if (stu[1] > stu[3] && stu[2] > stu[3]){
                            stu[3]++;
                        }
                        else if (stu[1] > stu[2] && stu[3] > stu[2]){
                            stu[2]++;
                        }
                        else if (stu[2] > stu[1] && stu[3] > stu[1]){
                            stu[1]++;
                        }
                        else{
                            vector<int> a = ff(F);
                            if (stu[1] > stu[2] && stu[1] > stu[3]){
                                if (a[2] > a[3]){
                                    stu[3]++;
                                }
                                else{
                                    stu[2]++;
                                }
                            }
                            else if (stu[2] > stu[1] && stu[2] > stu[3]){
                                if (a[1] > a[3]){
                                    stu[3]++;
                                }
                                else{
                                    stu[1]++;
                                }
                            }
                            else if (a[3] > a[2] && a[3] > a[1]){
                                if (a[1] > a[2]){
                                    stu[2]++;
                                }
                                else{
                                    stu[1]++;
                                }
                            }
                            else{
                                signed o = find_min(a);
                                stu[o]++;
                            }
                        }
                        F[7]--;
                        signed ot = find_max(F);
                        if (ot != index){
                            goto g;
                        }
                    }
                    break;
            }
        }
        cout << min(stu[1], min(stu[2], stu[3])) << '\n';

    }

    return 0;
}