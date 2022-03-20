class Solution {
public:
   
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       vector<int> v(7,0);
		 int i=0,j=0;
		 
		 while(i<tops.size()){
			 if(tops[i]!=bottoms[i]){
			 v[tops[i]]++;
			 v[bottoms[i]]++;
			 }
			 else v[tops[i]]++;
			 i++;
		 }
		int value=-1;
		for(int k=1;k<=6;k++){
			if(v[k]>=tops.size()){
				value=k;
				break;
			}
		}

		if(value==-1) return -1;
		int c1=0,c2=0;
	
		for(auto it: tops){
			if(it==value) c1++;
		}
		for(auto it: bottoms){
			if(it==value) c2++;
		}
		return min((tops.size()-c1),(bottoms.size()-c2));
    }
};