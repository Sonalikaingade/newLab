#include<bits/stdc++.h>
using namespace std;

void luDecomposition(vector<vector<int>> arr, vector<int> &voters){

    int row = arr.size();
   
    vector<vector<int>> lower(row, vector<int> (row, 0));
    vector<vector<int>> upper(row, vector<int> (row, 0));

    // Decomposition of matrix into lower and upper triangular matrix.
    for(int i=0;i<row;i++){

        // Upper Triangular.
        for(int k=i;k<row;k++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum += (lower[i][j]*upper[j][k]);
            }
            upper[i][k] = arr[i][k] - sum;
        }
        // Lower Triangular.
        for(int k=i;k<row;k++){
            // Diagonal will be 1.
            if(i == k){
                lower[i][k] = 1;
            }
            else{
                int sum=0;
                for(int j=0;j<i;j++){
                    sum += (lower[k][j]*upper[j][i]);
                }
                lower[k][i] = (arr[k][i]-sum)/upper[i][i];
            }
        }
    }
    cout<<"Lower Matrix"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++)
            cout<<lower[i][j]<<" ";

        cout<<endl;    
    }

    cout<<"Upper Matrix"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++)
            cout<<upper[i][j]<<" ";

        cout<<endl;    
    }


}


    int main(){
    vector<vector<int>> arr = {
        {-2, 5, 3, 6}, {8, 2, -5, -2}, {1, 3, 10, 4}, {10, 6, -2, 5}
    };

    vector<int> voters(arr.size());
    for(int i=0;i<arr.size();i++){
        cin>>voters[i];
    }

    luDecomposition(arr, voters);
    return 0;
}
