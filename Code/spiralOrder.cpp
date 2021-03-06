class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        int first_i=0,last_j=0;
        int first_j=matrix[0].size()-1,last_i=matrix.size()-1;
        while(true){
            for(int j=last_j;j<=first_j;j++){
                result.push_back(matrix[first_i][j]);
            }
            if(++first_i>last_i) break;
            for(int i = first_i;i<=last_i;i++){
                result.push_back(matrix[i][first_j]);
            }
            if(--first_j<last_j) break;
            for(int j = first_j;j>=last_j;j--){
                result.push_back(matrix[last_i][j]);
            }
            if(--last_i<first_i) break;
            for(int i = last_i;i>=first_i;i--){
                result.push_back(matrix[i][last_j]);
            }
            if(++last_j>first_j) break;
        }
        return result;
    }
};

//more details
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        int first_i=0,last_j=0;
        int first_j=matrix[0].size()-1,last_i=matrix.size()-1;
        while(first_i<last_i&&first_j>last_j){
            for(int j=last_j;j<first_j;j++){
                result.push_back(matrix[first_i][j]);
            }
            for(int i = first_i;i<last_i;i++){
                result.push_back(matrix[i][first_j]);
            }
            for(int j = first_j;j>last_j;j--){
                result.push_back(matrix[last_i][j]);
            }
            for(int i = last_i;i>first_i;i--){
                result.push_back(matrix[i][last_j]);
            }
            first_i++;last_j++;
            last_i--;first_j--;
        }
        if(first_i==last_i) copy(matrix[first_i].begin()+last_j,matrix[first_i].begin()+first_j+1,back_inserter(result));
        else if(first_j == last_j)
        	for(int i = first_i;i<=last_i;i++)
        		result.push_back(matrix[i][first_j]);
        return result;
    }
};
