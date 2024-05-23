#include <iostream>
#include <limits> // for 'numeric_limits'

using namespace std;

void errorInput(int &input) { // Failsafe kalo input gagal baca integer

    while (true) {

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // If input not integer, repeat
            cout << "\n>> Input bukan huruf\n\n";
            cout << "> ";
            cin >> input;

        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

struct treeMahasiswaTI { // Define tree mahasiswa prodi TI

    int valueMahasiswaTI;
    string namaMahasiswaTI;
    string umurMahasiswaTI;
    string alamatMahasiswaTI;
    string ipMahasiswaTI;
    string nimMahasiswaTI = "23051204";

    treeMahasiswaTI* left;
    treeMahasiswaTI* right;

    treeMahasiswaTI(int value, string name, string age, string ip, string nim) : valueMahasiswaTI(value), // Initialize
    namaMahasiswaTI(name), umurMahasiswaTI(age), ipMahasiswaTI(ip), nimMahasiswaTI(nim),  left(nullptr), right(nullptr) {}
};

struct treeMahasiswaSI { // Define tree mahasiswa prodi SI

};

struct treeMahasiswaPTI { // Define tree mahasiswa prodi PTI

};



int main () {

    cout << "\n----------Program manajemen data mahasiswa TI----------\n";

    do {

        int homePath;

        cout << "\n1. Tambahkan data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Tampilkan data seluruh mahasiswa\n";
        cout << "4. Tampilkan data mahasiswa eligible\n";
        cout << "5. Cari data mahasiswa berdasarkan NIM\n";
        cout << "0. Keluar dari program\n";
        cout << "\n";
        cout << "> ";

        cin >> homePath;
        errorInput(homePath); // Handling error input


        if (homePath == 1) {

            do {

                int prodiPath;

                cout << "\n1. Pilih prodi mahasiswa\n";
                cout << "\n1) Teknik Informatika\n";
                cout << "2) Sistem Informasi\n";
                cout << "3) Pendidikan Teknologi Informasi\n";
                cout << "0) Kembali ke menu utama\n";
                cout << "> ";

                cin >> prodiPath;
                errorInput(prodiPath); // Handling error input

                if (prodiPath == 1) {

                } else if (prodiPath == 2) {

                } else if (prodiPath == 3) {
                
                } else if (prodiPath == 0) {
                    cout << "\n>> Kembali ke menu utama\n";
                    break; // Exit loop
                
                } else if (homePath > 4) {
                    cout << "\n>> Input terlalu besar\n";

                } else {
                    cout << "\n>> Input bukan bilangan negatif\n";
                }


            } while(true);

        } else if (homePath == 2) {
            
        } else if (homePath == 3) {
            
        } else if (homePath == 4) {
            
        } else if (homePath == 5) {
            
        } else if (homePath == 0) {
            cout << "\n>> Keluar dari program\n";
            break; // Exit loop

        } else if (homePath > 4) {
            cout << "\n>> Input terlalu besar\n";

        } else {
            cout << "\n>> Input bukan bilangan negatif\n";
        }

    } while(true);

}
