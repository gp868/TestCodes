


void get(vcetor<string> strs){
    int count = 0, maxCount = 0;
    int time = 0;
    for(string str : strs){
        count = 0;
        for(char ch : str){
            if(ch == '>'){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
        }
        time = maxCount + 1;
    }







}

