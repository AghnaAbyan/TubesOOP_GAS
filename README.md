# Tugas Besar 1 Pemrograman Berorientasi Objek (OOP): Kompetisi Kartu ala Kerajaan Permen
Program ini dibuat untuk memenuhi capaian kurikulum Tugas Besar 1 IF2210 Pemrograman Berorientasi Objek 2022/2023, yaitu membuat program C++ dengan implementasi OOP.

## Informasi Umum
Program merupakan implementasi sebuah permainan kartu yang menerapkan konsep-konsep OOP, seperti:
- Inheritance dan Polymorphism
- Exception dan Exception Handling
- Function Overloading dan Operator Overloading
- Abstract Class dan Virtual Function
- Generic Function
- STL (Standard Template Library)

## Command
Beberapa perintah (command) yang dapat dilakukan pada program adalah sebagai berikut:
| Perintah        | Aksi |
| --------------- | ---- |
| Next            | Pemain tidak melakukan apa-apa, giliran diteruskan ke pemain selanjutnya |
| Re-roll         | Pemain membuang 2 kartu *main deck* ditangannya dan mengambil 2 kartu baru dari tumpukan kartu |
| Double/Quadruple| Pemain menaikkan total hadiah permain menjadi 2x lipat/4x lipat |
| Half/Quarter    | Pemain menurunkan total hadiah permain menjadi setengah/seperempatnya |
| Reverse         | Pemain memutar arah giliran eksekusi perintah, pemain yang sudah melakukan aksi pada giliran tersebut dilewati |
| Swap Card       | Pemain dapat menukar salah satu kartu pemain lain dengan satu kartu pemain lainnya |
| Switch          | Pemain menukar kartu *main deck* miliknya dengan kartu *main deck* pemain lain |
| Abilityless     | Pemain dapat mematikan kemampuan kartu lawan |

## How to run
Run perintah berikut di terminal:
```shell
g++ -o m main.cpp Game.cpp src/Kartu/Kartu.cpp src/Kombo/Kombo.cpp InventoryHolder.cpp Player.cpp TableCard.cpp
```

Selanjutnya jalankan:
```shell
./m
```

## Ucapan Terimakasih
Kami mengucapkan terimakasih kepada dosen yang telah mengajari kami tentang materi-materi pemrograman berorientasi objek C++ yang sangat penting untuk dipahami dan diimplementasikan pada tugas besar ini. Kami juga mengucapkan terimakasih kepada asisten yang telah membimbing kami selama pengerjaan tugas besar ini.

## Asisten
> Aditya Bimawan - 13519064

## Anggota Kelompok
| NIM       | Nama                        | Username      |
| --------- | --------------------------- | ------------- |
| 13521051  | Manuella Ivana Uli Sianipar | manuellaiv    |
| 13521053  | Athif Nirwasito             | Onyxcodeotto  |
| 13521076  | Moh. Aghna Maysan Abyan     | AghnaAbyan    |
| 13521115  | Shelma Salsabila            | shelmasalsa17 |
| 13521165  | Reza Pahlevi Ubaidillah     | obediqbal     |
