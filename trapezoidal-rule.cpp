// Nama File: trapezoidal_rule.cpp
// Deskripsi: Program C++ untuk mengestimasi jarak tempuh berdasarkan data kecepatan
//            menggunakan metode Aturan Trapesium Komposit.

#include <iostream>
#include <vector>
#include <numeric> // Untuk std::accumulate (opsional, bisa dihitung manual)
#include <stdexcept> // Untuk penanganan error

// Fungsi untuk menghitung integral menggunakan Aturan Trapesium Komposit
// Input: 
//   t: Vektor waktu (harus terurut menaik dan interval tidak harus sama)
//   v: Vektor kecepatan (harus memiliki ukuran yang sama dengan t)
// Output:
//   Estimasi jarak tempuh (integral dari v terhadap t)
double trapezoidal_composite(const std::vector<double>& t, const std::vector<double>& v) {
    // Periksa apakah ukuran vektor sama
    if (t.size() != v.size()) {
        throw std::invalid_argument("Ukuran vektor waktu dan kecepatan harus sama.");
    }

    // Periksa apakah ada cukup data poin (minimal 2)
    size_t n = t.size();
    if (n < 2) {
        throw std::invalid_argument("Membutuhkan setidaknya dua data poin untuk integrasi.");
    }

    double integral = 0.0;

    // Iterasi melalui setiap interval (trapesium)
    for (size_t i = 0; i < n - 1; ++i) {
        // Periksa apakah waktu terurut menaik
        if (t[i+1] <= t[i]) {
             throw std::invalid_argument("Vektor waktu harus terurut menaik.");
        }
        // Hitung lebar interval (delta t)
        double h = t[i+1] - t[i];
        // Hitung luas trapesium untuk interval ini
        double segment_area = (v[i] + v[i+1]) / 2.0 * h;
        // Tambahkan ke total integral
        integral += segment_area;
    }

    return integral;
}

int main() {
    // --- Contoh Data Input ---
    // Data waktu (detik)
    std::vector<double> time = {0.0, 1.0, 2.5, 3.0, 4.8, 5.0, 6.2};
    // Data kecepatan (meter/detik)
    std::vector<double> velocity = {0.0, 5.0, 7.0, 6.5, 8.0, 8.5, 9.0};

    // --- Perhitungan ---
    try {
        double distance = trapezoidal_composite(time, velocity);
        // --- Output Hasil ---
        std::cout << "Data Waktu (detik): ";
        for (double val : time) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        std::cout << "Data Kecepatan (m/s): ";
        for (double val : velocity) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        std::cout << "\nEstimasi Jarak Tempuh: " << distance << " meter" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Keluar dengan kode error
    }

    return 0; // Sukses
}

