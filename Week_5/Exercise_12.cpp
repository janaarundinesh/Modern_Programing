#include <iostream>
#include <string>

using namespace std;

class Song {
private:
    string title;
    string artist;
    int releaseYear;
    string recordLabel;

public:
    // Public constructor to initialize the private members
    Song(string Title, string Artist, int ReleaseYear, string RecordLabel)
        : title(Title), artist(Artist), releaseYear(ReleaseYear), recordLabel(RecordLabel) {
    }

    // Public member function to print song details
    void print();
};

void Song::print() {
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Release Year: " << releaseYear << endl;
        cout << "Record Label: " << recordLabel << endl;
    };

int main() {
    Song song1("Shape of You", "Ed Sheeran", 2017, "Asylum Atlantic");
    Song song2("One Kiss", "Calvin Harris and Dua Lipa", 2018, "Columbia Records");

    // Calling the print function to display song details
    song1.print();
    cout << endl;
    song2.print();

    return 0;
}
