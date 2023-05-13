#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Функция принимает строку, затем находит и выводит на экран все слова, начинающиеся с определённой буквы.
 * Функция реализована с учётом того, что между словами может быть как одинарный, так и двойной, тройной и тп промежуток.
 * В список слов, которые выводятся на экран, включаются как слова с большой, так и с маленькой буквы */

/* Function takes a string then finds and gives as a result all words that begin from specific letter.
 * It's possible to have multiple spaces between words in the original string (1,2,3..).
 * List of words includes words starting with upper and lowercase letter.
 */


vector<string>WordsStartingSameLetter(string text, char letter){
    vector<string>vec_words;
    string word = "";

    for (int i=0; i < text.length(); i++){
        if (text[i]!=' '){
            word +=text[i];
        }else{
            if (!word.empty()) {
                if(word[0]==toupper(letter) || word[0]==tolower(letter)) {
                vec_words.push_back(word);
                }
            }
            word = "";
        }
        if (i == (text.length()-1) && (word[0]==toupper(letter) || word[0]==tolower(letter) )){
            vec_words.push_back(word);
        }
    }

    return vec_words;
}

int main() {
    string text;
    char letter;
    vector <string>words;

    cout<< "Enter text"<< endl;
    getline(cin,text);

    cout <<"Enter the letter"<<endl;
    cin >>letter;

    words = WordsStartingSameLetter(text, letter);

    for (auto w:words){
        cout <<w<< " ";
    }

    return 0;
}
