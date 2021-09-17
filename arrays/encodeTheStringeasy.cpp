string encode(string str)
{     
        char curr = str[0];
          
        int cnt = 0;
          
        string ans;
          
        for(int i = 0; i < str.length(); i++){
              
            if(str[i] == curr){
            
                cnt++;
            }
            else{
                
                ans += curr; ans += to_string(cnt);
                
                curr = str[i];
                
                cnt = 1;
            }
        }
          
        ans += curr, ans += to_string(cnt);
          
        return ans;
}