#include <iostream>
#include <string>

using namespace std;

class estado{
  int state;

  public:
    estado(int state): state(state){};
    bool next(string &word, int counter){
        if(state == 5 && counter == word.length())return true;
        if(counter ==  word.length() && counter > 0 && state == 4){
            return 1;
        }

        if(counter == word.length()){
            return 0;
        }
        cout << "\n" << state << " " << word[counter] << word[counter+1] << "\n";
        switch(state){
                
            case 0:
                if (word[counter] == 'b' and word[counter+1] == 'l')return next(word, counter+2);
                else if (word[counter] == 'b' and word[counter+1] == 'r'){ state = 1; return next(word, counter+2);}
                else if (word[counter] == 'h' and word[counter+1] == 's'){ state = 2; return next(word, counter+2);}
                break;
            case 1:
                if (word[counter] == 'b' and (word[counter+1] == 'r' or word[counter+1] == 'l'))return next(word, counter+2);
                else if (word[counter] == 'h' and word[counter+1] == 's'){ state = 2; return next(word, counter+2);}
                else if (word[counter] == 'f' and word[counter+1] == 'e'){ state = 2; return next(word, counter+2);}
                else if (word[counter] == 't' and word[counter+1] == 'u'){ state = 2; return next(word, counter+2);}
                else if (word[counter] == 'f' and word[counter+1] == 's'){ state = 3; return next(word, counter+2);}
                break;
            case 2:
                if (word[counter] == 'f' and word[counter+1] == 'e')return next(word, counter+2);
                else if (word[counter] == 't' and word[counter+1] == 'u')return next(word, counter+2);
                else if (word[counter] == 'f' and word[counter+1] == 's'){ state = 3; return next(word, counter+2);}
                break;
            case 3:
                if (word[counter] == 'b' and word[counter+1] == 'l')return next(word, counter+2);
                else if (word[counter] == 'b' and word[counter+1] == 'r'){state = 4; return next(word, counter+2);}
                break;
            case 4:
                if (word[counter] == 'b' and (word[counter+1] == 'r' or word[counter+1] == 'l'))return next(word, counter+2);
                else if (word[counter] == 's' and word[counter+1] == 'p'){ state = 5; return next(word, counter+2);}
                break;
        }
        return 0;
    }
};

bool compile(string word){
    estado estadito(0);
    return estadito.next(word, 0);
}

int main(){
    string input;
    cin >> input;
    cout << compile(input);


    return 0;
}
