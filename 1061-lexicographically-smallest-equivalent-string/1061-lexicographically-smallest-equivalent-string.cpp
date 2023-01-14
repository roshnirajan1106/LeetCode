class Solution {
public:
    char find(char src, map<char,char>&parent)
    {
        if(parent[src] == src)
            return src;
        return parent[src] = find(parent[src],parent);
    }
    void unionset(char s1, char s2, map<char,char>&rank,map<char,char>&parent){
        char s11 = find(s1,parent);
        char s22 = find(s2,parent);
        if(s11 == s22)
        {
            return ;
        }
        cout<<s11<<" "<<s22<<endl;
        if(s11 < s22){
            parent[s22] = s11;
            rank[s2] = s1;
        }else{
            parent[s11] = s22;
            rank[s1] = s2;
        }
        cout<<parent[s11] <<"---> "<<parent[s22]<<endl;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,char>parent;
        map<char,char>rank;
        for(int i = 0;i<s1.length();i++)
        {
            int a= s1[i];
            int b = s2[i];
            parent[a] = a;
            parent[b] = b;
            rank[a] = a;
            rank[b] = b;
        }
        for(int i = 0;i<s1.length();i++)
        {
            int a = s1[i];
            int b = s2[i];
            unionset(a,b,rank,parent);
            
        }
        string s = "";
        for(auto p : baseStr){
            if(parent.find(p) != parent.end())
            s += find(p,parent);
            else
                s += p;
        }
        return s;
    }
};