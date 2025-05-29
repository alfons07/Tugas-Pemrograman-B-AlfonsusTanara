
# Estimasi Jarak Tempuh Menggunakan Aturan Trapesium Komposit

Nama : Alfonsus Tanara Gultom  
NPM : 2306267126


## Deskripsi Program
Program ini adalah implementasi metode numerik Aturan Trapesium Komposit dalam bahasa C++. Program ini bertujuan untuk mengestimasi total jarak yang ditempuh oleh suatu objek berdasarkan serangkaian data kecepatan yang tercatat pada interval waktu tertentu.

Data waktu dan kecepatan dimasukkan sebagai vektor dalam kode sumber (`main` function). Fungsi `trapezoidal_composite` menerima vektor waktu (`t`) dan kecepatan (`v`) sebagai input, lalu menghitung integral numerik dari kecepatan terhadap waktu untuk mendapatkan estimasi jarak tempuh. Program ini juga menyertakan penanganan error dasar untuk memastikan input data valid (ukuran vektor sama, waktu terurut menaik, minimal dua data poin).

Kode sumber (`trapezoidal_rule.cpp`) dilengkapi dengan komentar untuk menjelaskan setiap bagian penting dari logika program.
