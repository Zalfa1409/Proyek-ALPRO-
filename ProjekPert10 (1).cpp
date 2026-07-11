#include <iostream>
#include <iomanip>
using namespace std;

// Rekursif + Pointer
int hitungTotal(int *harga, int *jumlah, int index, int n)
{
    if (index == n)
        return 0;

    return (*(harga + index) * *(jumlah + index)) +
           hitungTotal(harga, jumlah, index + 1, n);
}

// Sorting
void sortingBuku(string buku[], int harga[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (harga[j] > harga[j + 1])
            {
                swap(harga[j], harga[j + 1]);
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

// Searching + Pointer
int cariBuku(string *buku, int n, string cari)
{
    for (int i = 0; i < n; i++)
    {
        if (*(buku + i) == cari)
            return i;
    }
    return -1;
}

int main()
{
    char ulang;

    do
    {
        string namaPembeli, alamat;

        // Array 1 Dimensi
        string daftarBuku[4] =
        {
            "Matematika",
            "Fisika",
            "Kimia",
            "Biologi"
        };

        int daftarHarga[4] =
        {
            50000,
            60000,
            55000,
            52000
        };

        // Array 2 Dimensi
        string dataBuku[4][3] =
        {
            {"Matematika", "50000", "20"},
            {"Fisika", "60000", "15"},
            {"Kimia", "55000", "18"},
            {"Biologi", "52000", "25"}
        };

        cout << "======================================" << endl;
        cout << "         TOKO BUKU CERDAS             " << endl;
        cout << "======================================" << endl;

        cout << "Nama Pembeli : ";
        getline(cin, namaPembeli);

        cout << "Alamat       : ";
        getline(cin, alamat);

        // Tampil Array 2D
        cout << "\n=== DATA BUKU (ARRAY 2 DIMENSI) ===" << endl;
        cout << "==============================================" << endl;

        cout << left
             << setw(5) << "No"
             << setw(15) << "Nama Buku"
             << setw(10) << "Harga"
             << setw(10) << "Stok"
             << endl;

        cout << "==============================================" << endl;

        for (int i = 0; i < 4; i++)
        {
            cout << left
                 << setw(5) << i + 1
                 << setw(15) << dataBuku[i][0]
                 << setw(10) << dataBuku[i][1]
                 << setw(10) << dataBuku[i][2]
                 << endl;
        }

        cout << "==============================================" << endl;

        // Pointer
        string *ptrBuku = daftarBuku;
        int *ptrHarga = daftarHarga;

        cout << "\n=== DATA BUKU MENGGUNAKAN POINTER ===" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << *(ptrBuku + i)
                 << " - Rp "
                 << *(ptrHarga + i)
                 << endl;
        }

        // Sebelum Sorting
        cout << "\n=== SEBELUM SORTING ===" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << daftarBuku[i]
                 << " - Rp "
                 << daftarHarga[i]
                 << endl;
        }

        // Sorting
        sortingBuku(daftarBuku, daftarHarga, 4);

        cout << "\n=== SETELAH SORTING ===" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << daftarBuku[i]
                 << " - Rp "
                 << daftarHarga[i]
                 << endl;
        }

        // Searching
        string cari;

        cout << "\nMasukkan Nama Buku Yang Dicari : ";
        getline(cin >> ws, cari);

        int posisi = cariBuku(daftarBuku, 4, cari);

        if (posisi != -1)
        {
            cout << "\nBuku Ditemukan!" << endl;
            cout << "Nama Buku : "
                 << daftarBuku[posisi] << endl;

            cout << "Harga     : Rp "
                 << daftarHarga[posisi] << endl;
        }
        else
        {
            cout << "\nBuku Tidak Ditemukan!" << endl;
        }

        string bukuDipilih[3];
        int harga[3] = {0};
        int jumlah[3] = {0};
        int subtotal[3] = {0};

        int pilihan;
        int banyakBuku = 0;

        cout << "\n=== DAFTAR BUKU ===" << endl;
        cout << "1. Matematika - Rp 50000" << endl;
        cout << "2. Fisika     - Rp 60000" << endl;
        cout << "3. Kimia      - Rp 55000" << endl;
        cout << "4. Biologi    - Rp 52000" << endl;

        for (int i = 0; i < 3; i++)
        {
            if (i > 0)
            {
                char lanjut;

                cout << "\nTambah Buku Lagi? (y/n) : ";
                cin >> lanjut;

                if (lanjut != 'y' && lanjut != 'Y')
                    break;
            }

            cout << "\nPilih Buku (1-4) : ";
            cin >> pilihan;

            while (pilihan < 1 || pilihan > 4)
            {
                cout << "Pilihan Tidak Valid! Masukkan Lagi : ";
                cin >> pilihan;
            }

            switch (pilihan)
            {
                case 1:
                    bukuDipilih[i] = "Matematika";
                    harga[i] = 50000;
                    break;

                case 2:
                    bukuDipilih[i] = "Fisika";
                    harga[i] = 60000;
                    break;

                case 3:
                    bukuDipilih[i] = "Kimia";
                    harga[i] = 55000;
                    break;

                case 4:
                    bukuDipilih[i] = "Biologi";
                    harga[i] = 52000;
                    break;
            }

            cout << "Jumlah Beli : ";
            cin >> jumlah[i];

            subtotal[i] = harga[i] * jumlah[i];
            banyakBuku++;
        }

        // Rekursif
        int totalSemua =
            hitungTotal(harga, jumlah, 0, banyakBuku);

        cout << "\nTotal Bayar : Rp "
             << totalSemua << endl;

        int bayar;

        cout << "Uang Bayar : Rp ";
        cin >> bayar;

        if (bayar < totalSemua)
        {
            cout << "\nMaaf, Uang Anda Kurang!" << endl;
            cout << "Transaksi Dibatalkan." << endl;
        }
        else
        {
            int kembalian = bayar - totalSemua;

            cout << "\n=========== STRUK PEMBELIAN ===========" << endl;
            cout << "Nama   : " << namaPembeli << endl;
            cout << "Alamat : " << alamat << endl;

            for (int i = 0; i < banyakBuku; i++)
            {
                cout << bukuDipilih[i]
                     << " x" << jumlah[i]
                     << " = Rp "
                     << subtotal[i]
                     << endl;
            }

            cout << "---------------------------------------" << endl;
            cout << "TOTAL      : Rp " << totalSemua << endl;
            cout << "BAYAR      : Rp " << bayar << endl;
            cout << "KEMBALIAN  : Rp " << kembalian << endl;
            cout << "=======================================" << endl;
        }

        cout << "\nIngin Bertransaksi Lagi? (y/n) : ";
        cin >> ulang;
        cin.ignore();

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram Selesai." << endl;

    return 0;
}
