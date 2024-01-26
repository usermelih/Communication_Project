#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Socket oluştur
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Socket oluşturulamadı" << std::endl;
        return -1;
    }

    // Server adres ve port tanımlamaları
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);  // Server'ın kullandığı port
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    // Server'a bağlan
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Server'a bağlanılamadı" << std::endl;
        close(clientSocket);
        return -1;
    }

    std::cout << "Server'a bağlandı" << std::endl;

    // Mesaj gönder ve al
    char message[1024];
    while (true) {
        // Kullanıcıdan mesaj al
        std::cout << "Mesaj : ";
        std::cin.getline(message, sizeof(message));

        // Mesajı server'a gönder
        send(clientSocket, message, strlen(message), 0);

        // Server'dan teyit mesajını al
        char buffer[1024];                                  // bu kısım sadece mesajın gönderildiğinin veya gönderilmediğinin kontrolu içndir
        recv(clientSocket, buffer, sizeof(buffer), 0);      //isteğer bağlı kod parçacığı çıkartılabilir
        std::cout << "Server: " << buffer << std::endl;
    }

    // Socket'ı kapat
    close(clientSocket);

    return 0;
}
