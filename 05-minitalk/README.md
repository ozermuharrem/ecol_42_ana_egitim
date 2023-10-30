<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>MiniTalk</h1>
  
  <p>
       putnbr ve putstr yeterli değil
  </p>
</div>

<br />

<!-- Table of Contents -->
  ## Table of Content
  * [ Proje Hakkında ](#star2-Proje-Hakkinda)
  <!-- * [ Başlangıç ](#running-Başlangıç) -->
  * [ Gereksinimler ](#space_invader-Gereksinimler)

  * [ Kullanım ](#Kullanım)
  * [ Ek Bilgi ](#Ek-Bilgi)
  <!-- * [ User Story ](#User-Story)
  * [ Technologies ](#Technologies)
  * [ Installation ](#Installation)
  * [ Usage ](#Usage)
  * [ Credits and Reference ](#Credits-and-Reference)
  * [ Tests ](#Tests)
  * [ Author Contact ](#Author-Contact)
  * [ License ](#Baglantilar) -->
  #

  


## :star2: Proje Hakkinda

Bu projenin amacı, UNIX sinyallerini kullanarakküçük bir veri değişim programı kodlamaktır. 

<!-- ## :running: Başlangıç

Okunmasını istediğiniz .txt dosyasını main.c veye dosyanın başka bir kısmında `get_next_line()` fonksiyonuna .txt dosyasının fd sini vererek okumasını sağlayabilirsiniz. -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

##  🛠️  Kullanım

```shell
make
```

make komutu aşağıda ki komutları çalıştırır

`gcc server.c minitalk_utulis.c minitalk_utulis2.c -I. -o server`

`gcc client.c minitalk_utulis.c minitalk_utulis2.c -I. -o client`

make komutu ile kodlar derlendikten sonra 

```shell
./server
```

komutu işe serveri başlatılmalı. 

Server çalıştıktan sonra konsolda PID bilgisi dönecek. 

Yeni bir terminalde 

```shell
./client <PID> "<Mesaj>"
```

komutunu çalıştırarak servere mesaja iletiriz. 

---
