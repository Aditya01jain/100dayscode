class Solution {
public:
    bool compare(string dictionary,string v){
        for(int i=0;i<dictionary.size();i++){
            if(dictionary[i]!=v[i]){
                return false;
            }
        }
        return true;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> v;
        string st="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                v.push_back(st);
                st="";
            }else{
                st+=sentence[i];
            }
        }
        v.push_back(st);
        for(int i=0;i<dictionary.size();i++){
            for(int j=0;j<v.size();j++){
                if(dictionary[i].size()<=v[j].size() && compare(dictionary[i],v[j])){
                    v[j]=dictionary[i];
                }
            }
        }
        st="";
        for(int i=0;i<v.size()-1;i++){
            st+=v[i];
            st+=" ";
        }
        st+=v[v.size()-1];
        return st;
    }
};