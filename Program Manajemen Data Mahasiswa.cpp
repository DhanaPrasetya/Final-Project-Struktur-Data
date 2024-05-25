#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct treeMahasiswaTI {
    int64_t nimMahasiswaTI;
    string namaMahasiswaTI;
    int umurMahasiswaTI;
    string alamatMahasiswaTI;
    float ipMahasiswaTI;
    treeMahasiswaTI* next;
};

struct treeMahasiswaSI {
    int64_t nimMahasiswaSI;
    string namaMahasiswaSI;
    int umurMahasiswaSI;
    string alamatMahasiswaSI;
    float ipMahasiswaSI;
    treeMahasiswaSI* next;
};

struct treeMahasiswaPTI {
    int64_t nimMahasiswaPTI;
    string namaMahasiswaPTI;
    int umurMahasiswaPTI;
    string alamatMahasiswaPTI;
    float ipMahasiswaPTI;
    treeMahasiswaPTI* next;
};

class DataMahasiswa {
private:
    treeMahasiswaTI* headTI;
    treeMahasiswaSI* headSI;
    treeMahasiswaPTI* headPTI;
    unordered_map<int64_t, treeMahasiswaTI*> hashTableTI;
    unordered_map<int64_t, treeMahasiswaSI*> hashTableSI;
    unordered_map<int64_t, treeMahasiswaPTI*> hashTablePTI;
    queue<treeMahasiswaTI*> queueTI;
    queue<treeMahasiswaSI*> queueSI;
    queue<treeMahasiswaPTI*> queuePTI;
    stack<treeMahasiswaTI*> stackTI;
    stack<treeMahasiswaSI*> stackSI;
    stack<treeMahasiswaPTI*> stackPTI;
    int totaldataTI;
    int totaldataSI;
    int totaldataPTI;

public:
    DataMahasiswa() {
        headTI = nullptr;
        headSI = nullptr;
        headPTI = nullptr;
        totaldataTI = 0;
        totaldataSI = 0;
        totaldataPTI = 0;
    }

    void tambahDataEligible() {
        int pilihan;
        cout << "\nTambah data untuk:\n";
        cout << "1. Mahasiswa TI\n";
        cout << "2. Mahasiswa SI\n";
        cout << "3. Mahasiswa PTI\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataTI();
                break;
            case 2:
                tambahDataSI();
                break;
            case 3:
                tambahDataPTI();
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void tambahDataTI() {
        auto* newMahasiswa = new treeMahasiswaTI();
        cout << "\nMasukkan NIM: ";
        cin >> newMahasiswa->nimMahasiswaTI;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, newMahasiswa->namaMahasiswaTI);
        cout << "Masukkan Umur: ";
        cin >> newMahasiswa->umurMahasiswaTI;
        cout << "Masukkan Alamat: ";
        cin.ignore();
        getline(cin, newMahasiswa->alamatMahasiswaTI);
        cout << "Masukkan IP: ";
        cin >> newMahasiswa->ipMahasiswaTI;

        newMahasiswa->next = headTI;
        headTI = newMahasiswa;

        hashTableTI[newMahasiswa->nimMahasiswaTI] = newMahasiswa;

        if (newMahasiswa->ipMahasiswaTI >= 3.5) {
            queueTI.push(newMahasiswa);
            stackTI.push(newMahasiswa);
        }

        totaldataTI++;
    }

    void tambahDataSI() {
        auto* newMahasiswa = new treeMahasiswaSI();
        cout << "\nMasukkan NIM: ";
        cin >> newMahasiswa->nimMahasiswaSI;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, newMahasiswa->namaMahasiswaSI);
        cout << "Masukkan Umur: ";
        cin >> newMahasiswa->umurMahasiswaSI;
        cout << "Masukkan Alamat: ";
        cin.ignore();
        getline(cin, newMahasiswa->alamatMahasiswaSI);
        cout << "Masukkan IP: ";
        cin >> newMahasiswa->ipMahasiswaSI;

        newMahasiswa->next = headSI;
        headSI = newMahasiswa;

        hashTableSI[newMahasiswa->nimMahasiswaSI] = newMahasiswa;

        if (newMahasiswa->ipMahasiswaSI >= 3.5) {
            queueSI.push(newMahasiswa);
            stackSI.push(newMahasiswa);
        }

        totaldataSI++;
    }

    void tambahDataPTI() {
        auto* newMahasiswa = new treeMahasiswaPTI();
        cout << "\nMasukkan NIM: ";
        cin >> newMahasiswa->nimMahasiswaPTI;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, newMahasiswa->namaMahasiswaPTI);
        cout << "Masukkan Umur: ";
        cin >> newMahasiswa->umurMahasiswaPTI;
        cout << "Masukkan Alamat: ";
        cin.ignore();
        getline(cin, newMahasiswa->alamatMahasiswaPTI);
        cout << "Masukkan IP: ";
        cin >> newMahasiswa->ipMahasiswaPTI;

        newMahasiswa->next = headPTI;
        headPTI = newMahasiswa;

        hashTablePTI[newMahasiswa->nimMahasiswaPTI] = newMahasiswa;

        if (newMahasiswa->ipMahasiswaPTI >= 3.5) {
            queuePTI.push(newMahasiswa);
            stackPTI.push(newMahasiswa);
        }

        totaldataPTI++;
    }

    void tampilData() {
        cout << "\nTampilkan data untuk:\n";
        cout << "1. Mahasiswa TI\n";
        cout << "2. Mahasiswa SI\n";
        cout << "3. Mahasiswa PTI\n";
        cout << "Masukkan pilihan: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilDataTI();
                break;
            case 2:
                tampilDataSI();
                break;
            case 3:
                tampilDataPTI();
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void tampilDataTI() {
        treeMahasiswaTI* currTI = headTI;
        cout << "\nData Mahasiswa TI:\n";
        while (currTI) {
            cout << "\nNIM: " << currTI->nimMahasiswaTI << "\n";
            cout << "Nama: " << currTI->namaMahasiswaTI << "\n";
            cout << "Umur: " << currTI->umurMahasiswaTI << "\n";
            cout << "Alamat: " << currTI->alamatMahasiswaTI << "\n";
            cout << "IP: " << currTI->ipMahasiswaTI << "\n";
            currTI = currTI->next;
        }
    }

    void tampilDataSI() {
        treeMahasiswaSI* currSI = headSI;
        cout << "\nData Mahasiswa SI:\n";
        while (currSI) {
            cout << "\nNIM: " << currSI->nimMahasiswaSI << "\n";
            cout << "Nama: " << currSI->namaMahasiswaSI << "\n";
            cout << "Umur: " << currSI->umurMahasiswaSI << "\n";
            cout << "Alamat: " << currSI->alamatMahasiswaSI << "\n";
            cout << "IP: " << currSI->ipMahasiswaSI << "\n";
            currSI = currSI->next;
        }
    }

    void tampilDataPTI() {
        treeMahasiswaPTI* currPTI = headPTI;
        cout << "\nData Mahasiswa PTI:\n";
        while (currPTI) {
            cout << "\nNIM: " << currPTI->nimMahasiswaPTI << "\n";
            cout << "Nama: " << currPTI->namaMahasiswaPTI << "\n";
            cout << "Umur: " << currPTI->umurMahasiswaPTI << "\n";
            cout << "Alamat: " << currPTI->alamatMahasiswaPTI << "\n";
            cout << "IP: " << currPTI->ipMahasiswaPTI << "\n";
            currPTI = currPTI->next;
        }
    }

    void hapusData() {
        cout << "\nHapus data untuk:\n";
        cout << "1. Mahasiswa TI\n";
        cout << "2. Mahasiswa SI\n";
        cout << "3. Mahasiswa PTI\n";
        cout << "Masukkan pilihan: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                hapusDataTI();
                break;
            case 2:
                hapusDataSI();
                break;
            case 3:
                hapusDataPTI();
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void hapusDataTI() {
        int64_t nim;
        cout << "\nMasukkan NIM mahasiswa yang ingin dihapus: ";
        cin >> nim;

        if (!headTI) {
            cout << "\nTidak ada data mahasiswa TI.\n";
            return;
        }

        if (headTI->nimMahasiswaTI == nim) {
            treeMahasiswaTI* temp = headTI;
            headTI = headTI->next;
            hashTableTI.erase(temp->nimMahasiswaTI);
            delete temp;
            cout << "\nData mahasiswa TI berhasil dihapus.\n";
            totaldataTI--;
            return;
        }

        treeMahasiswaTI* prev = headTI;
        treeMahasiswaTI* curr = headTI->next;
        while (curr) {
            if (curr->nimMahasiswaTI == nim) {
                prev->next = curr->next;
                hashTableTI.erase(curr->nimMahasiswaTI);
                delete curr;
                cout << "\nData mahasiswa TI berhasil dihapus.\n";
                totaldataTI--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "\nData mahasiswa TI tidak ditemukan.\n";
    }

    void hapusDataSI() {
        int64_t nim;
        cout << "\nMasukkan NIM mahasiswa yang ingin dihapus: ";
        cin >> nim;

        if (!headSI) {
            cout << "\nTidak ada data mahasiswa SI.\n";
            return;
        }

        if (headSI->nimMahasiswaSI == nim) {
            treeMahasiswaSI* temp = headSI;
            headSI = headSI->next;
            hashTableSI.erase(temp->nimMahasiswaSI);
            delete temp;
            cout << "\nData mahasiswa SI berhasil dihapus.\n";
            totaldataSI--;
            return;
        }

        treeMahasiswaSI* prev = headSI;
        treeMahasiswaSI* curr = headSI->next;
        while (curr) {
            if (curr->nimMahasiswaSI == nim) {
                prev->next = curr->next;
                hashTableSI.erase(curr->nimMahasiswaSI);
                delete curr;
                cout << "\nData mahasiswa SI berhasil dihapus.\n";
                totaldataSI--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "\nData mahasiswa SI tidak ditemukan.\n";
    }

    void hapusDataPTI() {
        int64_t nim;
        cout << "\nMasukkan NIM mahasiswa yang ingin dihapus: ";
        cin >> nim;

        if (!headPTI) {
            cout << "\nTidak ada data mahasiswa PTI.\n";
            return;
        }

        if (headPTI->nimMahasiswaPTI == nim) {
            treeMahasiswaPTI* temp = headPTI;
            headPTI = headPTI->next;
            hashTablePTI.erase(temp->nimMahasiswaPTI);
            delete temp;
            cout << "\nData mahasiswa PTI berhasil dihapus.\n";
            totaldataPTI--;
            return;
        }

        treeMahasiswaPTI* prev = headPTI;
        treeMahasiswaPTI* curr = headPTI->next;
        while (curr) {
            if (curr->nimMahasiswaPTI == nim) {
                prev->next = curr->next;
                hashTablePTI.erase(curr->nimMahasiswaPTI);
                delete curr;
                cout << "\nData mahasiswa PTI berhasil dihapus.\n";
                totaldataPTI--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "\nData mahasiswa PTI tidak ditemukan.\n";
    }

    void tampilDataEligibleQueue() {
        cout << "\nMasukkan pilihan 1 untuk mahasiswa TI\n";
        cout << "Masukkan pilihan 2 untuk mahasiswa SI\n";
        cout << "Masukkan pilihan 3 untuk mahasiswa PTI\n";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                while (!queueTI.empty()) {
                    treeMahasiswaTI* mahasiswa = queueTI.front();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaTI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaTI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaTI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaTI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaTI << "\n";
                    queueTI.pop();
                }
                break;
            case 2:
                while (!queueSI.empty()) {
                    treeMahasiswaSI* mahasiswa = queueSI.front();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaSI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaSI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaSI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaSI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaSI << "\n";
                    queueSI.pop();
                }
                break;
            case 3:
                while (!queuePTI.empty()) {
                    treeMahasiswaPTI* mahasiswa = queuePTI.front();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaPTI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaPTI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaPTI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaPTI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaPTI << "\n";
                    queuePTI.pop();
                }
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void tampilDataEligibleStack() {
        cout << "\nMasukkan pilihan 1 untuk mahasiswa TI\n";
        cout << "Masukkan pilihan 2 untuk mahasiswa SI\n";
        cout << "Masukkan pilihan 3 untuk mahasiswa PTI\n";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                while (!stackTI.empty()) {
                    treeMahasiswaTI* mahasiswa = stackTI.top();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaTI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaTI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaTI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaTI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaTI << "\n";
                    stackTI.pop();
                }
                break;
            case 2:
                while (!stackSI.empty()) {
                    treeMahasiswaSI* mahasiswa = stackSI.top();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaSI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaSI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaSI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaSI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaSI << "\n";
                    stackSI.pop();
                }
                break;
            case 3:
                while (!stackPTI.empty()) {
                    treeMahasiswaPTI* mahasiswa = stackPTI.top();
                    cout << "\nNIM: " << mahasiswa->nimMahasiswaPTI << "\n";
                    cout << "Nama: " << mahasiswa->namaMahasiswaPTI << "\n";
                    cout << "Umur: " << mahasiswa->umurMahasiswaPTI << "\n";
                    cout << "Alamat: " << mahasiswa->alamatMahasiswaPTI << "\n";
                    cout << "IP: " << mahasiswa->ipMahasiswaPTI << "\n";
                    stackPTI.pop();
                }
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void cariData() {
        cout << "\nMasukkan pilihan 1 untuk mencari mahasiswa TI\n";
        cout << "Masukkan pilihan 2 untuk mencari mahasiswa SI\n";
        cout << "Masukkan pilihan 3 untuk mencari mahasiswa PTI\n";
        int pilihan;
        int64_t nim;
        cin >> pilihan;

        cout << "\nMasukkan NIM mahasiswa: ";
        cin >> nim;

        switch (pilihan) {
            case 1:
                cariDataTI(nim);
                break;
            case 2:
                cariDataSI(nim);
                break;
            case 3:
                cariDataPTI(nim);
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }

    void cariDataTI(int64_t nim) {
        if (hashTableTI.find(nim) != hashTableTI.end()) {
            treeMahasiswaTI* mahasiswa = hashTableTI[nim];
            cout << "\nNIM: " << mahasiswa->nimMahasiswaTI << "\n";
            cout << "Nama: " << mahasiswa->namaMahasiswaTI << "\n";
            cout << "Umur: " << mahasiswa->umurMahasiswaTI << "\n";
            cout << "Alamat: " << mahasiswa->alamatMahasiswaTI << "\n";
            cout << "IP: " << mahasiswa->ipMahasiswaTI << "\n";
        } else {
            cout << "\nMahasiswa TI dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    void cariDataSI(int64_t nim) {
        if (hashTableSI.find(nim) != hashTableSI.end()) {
            treeMahasiswaSI* mahasiswa = hashTableSI[nim];
            cout << "\nNIM: " << mahasiswa->nimMahasiswaSI << "\n";
            cout << "Nama: " << mahasiswa->namaMahasiswaSI << "\n";
            cout << "Umur: " << mahasiswa->umurMahasiswaSI << "\n";
            cout << "Alamat: " << mahasiswa->alamatMahasiswaSI << "\n";
            cout << "IP: " << mahasiswa->ipMahasiswaSI << "\n";
        } else {
            cout << "\nMahasiswa SI dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    void cariDataPTI(int64_t nim) {
        if (hashTablePTI.find(nim) != hashTablePTI.end()) {
            treeMahasiswaPTI* mahasiswa = hashTablePTI[nim];
            cout << "\nNIM: " << mahasiswa->nimMahasiswaPTI << "\n";
            cout << "Nama: " << mahasiswa->namaMahasiswaPTI << "\n";
            cout << "Umur: " << mahasiswa->umurMahasiswaPTI << "\n";
            cout << "Alamat: " << mahasiswa->alamatMahasiswaPTI << "\n";
            cout << "IP: " << mahasiswa->ipMahasiswaPTI << "\n";
        } else {
            cout << "\nMahasiswa PTI dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }
};

int main() {
    DataMahasiswa dataMahasiswa;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampil Data Mahasiswa\n";
        cout << "3. Hapus Data Mahasiswa\n";
        cout << "4. Tampil Data Eligible (Queue)\n";
        cout << "5. Tampil Data Eligible (Stack)\n";
        cout << "6. Cari Data Mahasiswa\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                dataMahasiswa.tambahDataEligible();
                break;
            case 2:
                dataMahasiswa.tampilData();
                break;
            case 3:
                dataMahasiswa.hapusData();
                break;
            case 4:
                dataMahasiswa.tampilDataEligibleQueue();
                break;
            case 5:
                dataMahasiswa.tampilDataEligibleStack();
                break;
            case 6:
                dataMahasiswa.cariData();
                break;
            case 7:
                cout << "\nKeluar program.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    return 0;
}
