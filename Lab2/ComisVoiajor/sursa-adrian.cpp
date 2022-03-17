#include <iostream>
#include <cmath>
using namespace std;
int n,height=1;
bool is_valid, did_stuff, first_path_found=0;
double Max, Min;
int shortest_path[1001];
int x[1001], y[1001], st[1001];
double matrix[1001][1001];
void create_matrix(int x[1001], int y[1001]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                matrix[i][j]=0;
            }
            else{
                matrix[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            }
        }
    }
}
void succesor(int height, bool &did_stuff){
    //ce elem punem
    if(st[height]<n){
        st[height]++;
        did_stuff=1;
    }
    else
    did_stuff=0;
}
void valid(int height, bool &is_valid){
    is_valid=1;
    for(int i=1;i<height;i++){
        if(st[height]==st[i]){
            is_valid=0;
            //adica l-am mai pus inainte in stiva
        }
    }
}
void get_all_paths_backtracking(){
    st[1]=0;
    while(height>0){
        do{
            succesor(height, did_stuff);
            if(did_stuff==1){
                valid(height, is_valid);
            }
        }while(did_stuff==1 && is_valid==0);
        if(did_stuff==1){
            if(height==n){
                if(first_path_found==0){
                    Min=matrix[n][1];
                    for(int i=1;i<n;i++){
                        Min += matrix[st[i]][st[i+1]];
                        shortest_path[i]=st[i];
                    }
                    shortest_path[n]=st[n];
                    first_path_found = 1;
                }
                else{
                    double Sum=matrix[st[n]][st[1]];
                    for(int i=1;i<n;i++){
                        Sum += matrix[st[i]][st[i+1]];
                    }
                    if(Sum < Min){
                        for(int i=1;i<=n;i++){
                            shortest_path[i]=st[i];
                        }
                        Min = Sum;
                    }
                }
            }
            else{
                height++;
                st[height]=0;
            }
        }
        else{
            height--;
            //there was no possible number we could have placed there
        }
    }
}
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    create_matrix(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    get_all_paths_backtracking();
    cout<<"The shortest road is: "<<Min<<'\n';
    cout<<"And the order of the nodes is: ";
    for(int i=1;i<=n;i++){
        cout<<shortest_path[i]<<" ";
    }
    cout<<shortest_path[1];
    return 0;
}
