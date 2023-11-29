#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void process(const string &key, const string &in, const string &out, bool encrypt) {
    stringstream ss;
    int k = 0;

    ss << key;
    ss >> k;

    ifstream fin(in, ios::binary);
    ofstream fout(out, ios::binary);

    char ch;  // Change the type to char

    while (fin.get(ch)) {
        if (encrypt) {
            ch = (ch + k) % 256;
        } else {
            ch = (ch - k + 256) % 256;
        }
        fout.put(ch);
    }

    fin.close();
    fout.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " key in out" << endl;
        return 1;
    }

    string key = argv[1];
    string in = argv[2];
    string out = argv[3];

    bool encrypt = (string(argv[0]).find("decrypter") == string::npos);

    process(key, in, out, encrypt);

    return 0;
}
