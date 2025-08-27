#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string paragraph;
    cout << "Enter a paragraph:\n";

    // TODO: Use appropriate function to get the paragraph input
    getline(cin, paragraph);

    // TODO: Open 'sentences.txt' file to write to

    ofstream out("sentences.txt");
    
    string sentence = "";
    // TODO: Write logic to separate the sentences from the paragraph and save them to sentences.txt file as separate lines
    // and then close the file

    cout << "Sentences stored successfully in sentences.txt\n";

    for(int i=0;i<paragraph.size();i++)
    {

        sentence=sentence+ paragraph[i];;

        if(paragraph[i]=='.')
        {
            out<<sentence<<endl;
            sentence="";
        }
    }


    // ------------------ READ BACK -------------------
    // TODO: Open the 'sentences.txt' file to read contents from it

    ifstream in("sentences.txt");
    
    string line;
    string store;
    int countline=0;
    int countword=0;

    // TODO: Read all sentences from the file and combine them back into a single paragraph 
    // and also count words and total lines
    // (Note that it is necessary to add spaces between lines to restore the original paragraph format).

    // Start writing your code from here


    while(getline(in,line))
    {
        store=store+line+" ";
        countline++;

        for(int i=0;i<line.size();i++)
        {
            if(line[i]==' ')countword++;
        }
        countword++;
    }
    
    in.close();
 
    // Do not write anything below this line
    cout << "\nRestored paragraph:\n" << store << endl;
    
    cout << "Total lines: " << countline << endl;
    cout << "Total words: " << countword << endl;


    return 0;
}
