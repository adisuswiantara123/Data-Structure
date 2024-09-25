#include "admin.h"

void Admin::ubahAkun(User users[], int userCount) {
    std::string username;
    std::string password;

    std::cout << "Masukkan username yang ingin diubah: ";
    std::cin >> username;
    std::cout << "Masukkan password yang ingin diubah: ";
    std::cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            std::string newUsername;
            std::string newPassword;

            std::cout << "Masukkan username baru: ";
            std::cin >> newUsername;
            std::cout << "Masukkan password baru: ";
            std::cin >> newPassword;

            // Update username dan password
            users[i].username = newUsername;
            users[i].password = newPassword;
            std::cout << "Username dan password berhasil diperbarui.\n";

            SaveUsersToFile(users, userCount); // Simpan perubahan ke file
            return;
        }
    }

    std::cout << "Username atau password yang ingin diubah salah. Gagal mengubah akun.\n";
}
