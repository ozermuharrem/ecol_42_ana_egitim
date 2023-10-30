<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>ft_printf</h1>
  
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

`printf()` fonksiyonunu yeniden yazmak. Temelde değişken argümanların nasıl kullanılacağını öğrenmek

<!-- ## :running: Başlangıç

Okunmasını istediğiniz .txt dosyasını main.c veye dosyanın başka bir kısmında `get_next_line()` fonksiyonuna .txt dosyasının fd sini vererek okumasını sağlayabilirsiniz. -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

##  🛠️  Kullanım

  ```c
  #include "ft_printf.h" 
  ```

  main.c dosyası içerisinde veya başa bir fonksiyonun içerisinde `ft_printf()` fonksiyonuna aşağıdaki değerleri vererek çalıştırabilirsiniz.
  + %s: Karşılığı bir karakter dizisini (char*) yazdırmak için kullanılır.
  + %d: Karşılığı bir ondalık (int) sayıyı yazdırmak için kullanılır.
  + %x: Karşılığı onaltılı (hexadecimal) bir sayıyı küçük harfle yazdırmak için kullanılır.
  + %X: Karşılığı onaltılı bir sayıyı büyük harfle yazdırmak için kullanılır.
  + %p: Karşılığı bir işaretçiyi (pointer) yazdırmak için kullanılır. İşaretçi adresini onaltılı olarak gösterir.
  + %u: Karşılığı işaretlenmemiş (unsigned) bir ondalık sayıyı yazdırmak için kullanılır.
  + %%: Karşılığı bir yüzde işareti (%) yazdırmak için kullanılır. İki yüzde işareti yan yana yazılmalıdır.

  ```c
  #include "ft_printf.h" 

int main()
{
    char* metin = "Merhaba, dünya!";
    int sayi = 42;
    unsigned int usayi = 123;
    int* pointer = &sayi;

    ft_printf("%s\n", metin);   // Metin dizisini yazdırır
    ft_printf("%d\n", sayi);    // Ondalık sayıyı yazdırır
    ft_printf("%x\n", sayi);    // Sayıyı onaltılı (küçük harfle) yazdırır
    ft_printf("%X\n", sayi);    // Sayıyı onaltılı (büyük harfle) yazdırır
    ft_printf("%p\n", pointer); // İşaretçiyi yazdırır (işaretçi adresi)
   ft_printf("%u\n", usayi);   // İşaretlenmemiş ondalık sayıyı yazdırır
    ft_printf("Yüzde işareti: %%\n"); // Yüzde işaretini yazdırır
}
  ```

  Derlemek için

  ```shell
  gcc -Wall -Wextra -Werror *.c  && ./a.out
  ```

  **Sonuc** 
  ```shell
  $>Merhaba, dünya!
  $>42
  $>2a
  $>2A
  $>0x7ffd1ef7a7b0
  $>123
  $>Yüzde işareti: %
  ```

  ## Ek Bilgi

  `ft_printf(const char *, ...);` 

Yukarıda ki şekilde modellenecetir. <br>

Modelde yer alan "..." kısımı sonsuz argüman alabilen fonksyon anlamına gelmektedir. 

**strarg.h** kütüphanesindedir. 

<table>
  <tr>
    <th>va_list </th>
    <th>va_start, va_arg, va_end ve va_copy typedef tarafından ihtiyaç duyan bilgileri tutar</th>
  </tr>
  <tr>
    <th>va_start</th>
    <th>ilk argümana erişim sağlar argümanın nerden başladığını gösterir</th>
  </tr>
  <tr>
    <th>va_arg</th>
    <th>Sonraki argümana erişir</th>
  </tr>
  <tr>
    <th>va_end</th>
    <th>Argümanların geçişini sona erdirir</th>
  </tr>
  <tr>
    <th>va_copy</th>
    <th>Argümanların kopyasını oluşturur</th>
  </tr>
 </table>

  <h2>Hexadecimal</h2>
 
 Hexadecimal (İngilizce kısaltmasıyla hex), matematik ve bilişim alanlarında kullanılan 16 tabanlı sayı sistemidir. <br>
 Hexadecimal sayı sisteminde sayılar 16 farklı sembolle temsil edilir. <br>
 0-9 arasında semboller 0 ile 9 arasında sayıları, A-F arasındaki harfler ise 10 ile 15 arasındaki sayıları temsil eder. 
<br><br> 
<h3>Ondalık sayıların on altılık sayıya çevrilişi</h3>

Ondalık sayı, bölüm sıfır olana kadar 16'ya bölünür. <br>
Bölme işlemi bittikten sonra, sırayla bölüm hanesindekiler ve en son olarak da kalan sayı soldan sağa yazılır.

**Örnek;**

100/16 = 4(kalan):6(bölüm) 6/16 = 6(kalan) = 64

**Örnek**


![277](https://user-images.githubusercontent.com/86782430/158175639-ccc746fb-95a9-4bb8-a540-bcacd4b43ac6.png) 

**Hexadecimal** 101 çıkıt sağdan sola doğru yazılır .

**Örnek**

![3412](https://user-images.githubusercontent.com/86782430/158179297-b5afc093-c3a7-4036-b7ff-c545b621b7ed.png)

**Hexadecimal** d54 çıktı 

---
