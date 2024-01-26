# Communication_Project
# Kısım 1

**Projenin Açıklaması:** Bu proje, basit bir TCP server uygulamasını içerir. Server, belirli bir portu dinler, gelen bağlantıları kabul eder ve bağlantıda bulunan istemci ile iletişim kurar.

## Gereksinimler

- C++ derleyicisi
- Linux işletim sistemi (veya uyumlu bir işletim sistemi)

## Kullanım

1. Proje klasörünü yerel bilgisayarınıza kopyalayın.
2. Derlemek için terminalde şu komutu kullanın:

   ```bash
   g++ server.cpp -o server
   ```

3. Oluşturulan yürütülebilir dosyayı çalıştırın:

   ```bash
   ./server
   ```

4. Server, belirtilen portu dinleyerek bağlantıları kabul edecek ve gelen mesajları ekrana yazdıracaktır.

## Proje Detayları

- **server.cpp:** Bu dosya, server tarafındaki uygulamayı içerir.
- **serverAddress:** Server'ın IP adresi ve dinleyeceği portu bu bölümde tanımlanır. Gerekirse, bu değerleri değiştirebilirsiniz.
- **Bağlantı Bekleme ve Mesaj Alma:** Server, bağlantı bekler ve bir istemciden gelen mesajları ekrana yazdırır.
- **Teyit Mesajı Gönderme:** Server, alınan mesajı teyit etmek için istemciye "Mesaj alındı" mesajını gönderir.

## Örnek Kullanım

1. İstemci, server'a başarılı bir şekilde bağlandığında:

   ```bash
   Server başlatıldı
   Yeni bir bağlantı
   Client: Merhaba, nasılsın?
   ```

2. İstemci, server'a bağlanamadığında:

   ```bash
   Socket oluşturulamadı
   ```


# Kısım 2

**Projenin Açıklaması:** Bu proje, basit bir istemci tarafından belirli bir sunucuya TCP soket üzerinden bağlanmak için bir örnek içerir.

## Gereksinimler

- C++ derleyicisi
- Linux işletim sistemi (veya uyumlu bir işletim sistemi)

## Kullanım

1. Proje klasörünü yerel bilgisayarınıza kopyalayın.
2. Derlemek için terminalde şu komutu kullanın:

   ```bash
   g++ client.cpp -o client
   ```

3. Oluşturulan yürütülebilir dosyayı çalıştırın:

   ```bash
   ./client
   ```

4. Program, server ile bağlantı kuracak ve kullanıcıdan alınan mesajları server'a iletecek.

## Proje Detayları

- **client.cpp:** Bu dosya, istemci tarafındaki uygulamayı içerir.
- **serverAddress:** Server'ın IP adresi ve portu bu bölümde tanımlanır. Gerekirse, bu değerleri değiştirebilirsiniz.
- **Mesaj Gönderme ve Alma:** Kullanıcıdan alınan mesajlar, server'a gönderilir ve gelen teyit mesajları ekrana yazdırılır.

## Örnek Kullanım

1. İstemci, server'a başarılı bir şekilde bağlandığında:

   ```bash
   Server'a bağlandı
   Mesaj: Merhaba, nasılsın?
   Server: Mesaj alındı
   ```

2. İstemci, server'a bağlanamadığında:

   ```bash
   Socket oluşturulamadı
   ```
