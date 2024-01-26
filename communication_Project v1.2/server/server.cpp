#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Socket oluştur
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Socket oluşturulamadı" << std::endl;
        return -1;
    }

    // Server adres ve port tanımlamaları
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);  //port numarısı default olarak 12345 olarak belirtilmiştir || boş bir port atadığınza emin olun
    serverAddress.sin_addr.s_addr = INADDR_ANY; //adres belirlemek için bu kısma local bir ipv4 adresi atayınız

    // server ile client parçacıklarını ilişkilendir
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "İlişkilendirme hatası" << std::endl;
        close(serverSocket);
        return -1;
    }

    // Socket'ı dinle
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Dinleme hatası" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Server başlatıldı" << std::endl;

    // Client'ın bağlantı yapmasını bekleyin
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        std::cerr << "Bağlantı kabul hatası" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Yeni bir bağlantı" << std::endl;

    // Mesaj al ve yaz
    char buffer[1024];
    while (true) {
        // Client'dan mesaj al
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Bağlantı kesildi veya hata oluştu" << std::endl;
            break;
        }

        // Gelen mesajı ekrana yaz
        buffer[bytesRead] = '\0';
        std::cout << "Client: " << buffer << std::endl;

        // Mesajı teyit et
        send(clientSocket, "Mesaj alındı", 12, 0);
    }

    // Socket'ları kapat
    close(clientSocket);
    close(serverSocket);

    return 0;
}
