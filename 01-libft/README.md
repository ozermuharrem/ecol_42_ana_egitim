<!--
Hey, thanks for using the awesome-readme-template template.  
If you have any enhancements, then fork this project and create a pull request 
or just open an issue with the label "enhancement".

Don't forget to give this project a star for additional support ;)
Maybe you can mention me or this repo in the acknowledgements too
-->
<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>Libft</h1>
  
  <p>
    Kendi Yazdığımız İlk Kütüphane
  </p>
</div>

<br />

<!-- Table of Contents -->
  ## Table of Content
  * [ Proje Hakkında ](#star2-Proje-Hakkinda)
  * [ Gereksinimler ](#space_invader-Gereksinimler)
  * [ Kullanım ](#Kullanım)
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

Bu projenin amacı bir sonra ki projelerimizde de kullanabileceğimiz bir C kütüphanesi yazmaktır. 

<!-- ## :running: Başlangıç

Projenin yerel makinenize veya sunucunuza nasıl kurulacağınızı anlatan adım adım talimatlar burada yer almalıdır. -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

##  🛠️  Kullanım

  + Libft klasötünü kendi projenize ekledikten sonra 
  ```c
  #include "libft.h" 
  ```
  kütüphanesini projenize dahil ettikten sonra kütüphane içerisinde ki fonksiyonlara erişebilirsiniz.

  main.c dosyası içerisinde test yapmak istiyorsanız

  ```shell
  touch main.c
  ```

  `touch` komutu ile yeni bir `main.c` dosyası açın

  Dosyanın içerisine aşağıdaki kod bloğunu yazın

  ```c
  #include "libft.h" 
  #include <stdio.h>

  int main(){
    // fonskiyonu ve rekeli parametreleri vererek buraya yazın
    // örneğin ft_strlen() fonksiyonunu test çağıralım

    char *str = "Bu cümledeki katerter sayisini doner";

    printf("Karekter sayisi : %d ", ft_strlen(str));

    return 0;
  }
  ```

  Derlemek için

  ```shell
  gcc -Wall -Wextra -Werror *.c -o Libft && ./Libft
  ```
  Sonuç
  ```shell 
  $>37
  ```



<table class="table">
  <thead>
    <tr>
      <th scope="col">Fonksiyon İsmi</th>
      <th scope="col">Açıklaması</th>
    </tr>
  </thead>
  <tbody>
      <tr><td>ft_isalpha </td><td> Alfabetik karekter testi </td></tr>
    <tr><td>ft_isdigit </td><td> Sayısal karekter testi</td></tr>
    <tr><td>ft_isalnum </td><td> Alfanumerik karekter testi</td></tr>
    <tr><td>ft_isascii </td><td> Ascii değeri olan karekterlerin testi</td></tr>
    <tr><td>ft_isprint </td><td> Yazılabilir karekterlerin testi Not: Arapça, Japonca Gibi Yazı Karekterleri 1 Döndürür</td></tr>
    <tr><td>ft_strlen </td><td> s paremetresi ile gönderilen karekter dizisinin uzunluğunu sayar fonksiyon</td></tr>
    <tr><td>ft_memset </td><td> str paremetresi ile gönderilen karekter dizisini len paremetresi kadar c paremetresi ile gönderilen karekter ile değiştiren fonksiyon</td></tr>
    <tr><td>ft_bzero </td><td> Bellekte n kadar s bytında ki değeri silen fonksiyon</td></tr>
    <tr><td>ft_memcpy </td><td> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon</td></tr>
    <tr><td>ft_memmove </td><td> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon ft_memcpy den farkı over-lop kopya her zaman tahribatsız bir şekilde yapılır. Sondan başlayarak kopyalar.  </td></tr>
    <tr><td>ft_strlcpy </td><td> Dst ye her zaman tek bir NULL bayt yazar(boyut sıfır değilse). NULL ile sonlandırılacak src dizisinden dstye -1 karekter kadar kopyalar ve sonuna NULL atayarak sonlandırır.</td></tr>
    <tr><td> ft_strlcat </td><td> Ara belleğin tam boyutunu alır (yalnızca uzunluğunu değil) ve sonuna NULL ile sonlandırmayı garanti eder</td></tr>
    <tr><td> ft_tolower </td><td> Büyük karekterleri küçülten fonksiyon </td></tr>
    <tr><td> ft_toupper </td><td> Küçük karekterleri büyüten fonsiyon </td></tr>
    <tr><td> ft_strchr </td><td> str paremetresi ile gösterilen karekter dizisinde ki c paremetresi ile gösterilen değerin (unsigned char olarak değerlendirilir) ilk geçtiği yeri arar ve bellek adresini gösteren bir işaretci ile geri döndürür. Özetle bir karekter dizisi içerisinde c paremetresi ile gösterilen karekteri ara bulduğu yerden sonrasını silen fonksiyon </td></tr>
    <tr><td>ft_strrchr </td><td> strchr dan farkı sondan başlayarak silmesi dir. </td></tr>
    <tr><td> ft_strncmp </td><td> iki tane karekter dizisini n paremetresi kadar karşılaştırır eşit olmadığı kısmında ki karekterlerin ascii kadunu döndüren fonksiyon </td></tr>
    <tr><td> ft_memchr </td><td> * s ile gösterilen karekter dizisinde ki c parmetresi ile gösterilen karekteri arar. Bulursa karekterin bellek adresini döndüren fonksiyon</td></tr>
    <tr><td> ft_memcmp </td><td> iki bellek bloğunu karşılaştırır n paremetre değeri kadar elde ettiği değeri döndüren fonksiyon</td></tr>
    <tr><td> ft_strnstr </td><td> samanlıkta iğne arayan fonksiyon</td></tr>
    <tr><td> ft_atoi </td><td> str paremetresi ile gösterilen değeri int degere dönüştüren fonksiyon</td></tr>
    <tr><td> ft_calloc </td><td> Size paremetre değeri kadar olan bellekte count paremetre değeri kadar sayıda bellek blogu tahsis eden ve açılan belleği sıfır değeri ile dolduran fonksiyon</td></tr>
    <tr><td> ft_strdup </td><td> * s1 paremeteresi ile gösterilen karekter dizisinin aynısını geri döndüren fonksiyon</td></tr>
    <tr><td>ft_substr </td><td> * s ile gösterilen karekter dizisinin start paremetre değerinden sonrasını len paremetre değeri kadar döndüren fonksiyondur</td></tr>
    <tr><td> ft_strjoin </td><td> * s1 paremetresi ile * s2 paremetresini birleştirir</td></tr>
    <tr><td> ft_strtrim </td><td> * s1 paremetresi ile gösterilen karekter dizisinde ki * s2 paremetresinde ki karekterleri karşılaştırıp kırpan fonksiyon </td></tr>
    <tr><td> ft_split </td><td> * s1 paremetresi ile gönderilen dizinin içerisinde bulunan c paremetresi ile gösterilen karekterlerden böler</td></tr>
    <tr><td> ft_itoa </td><td> n paremetresi ile gönderilen int değeri sitringe çevirir.</td></tr>
    <tr><td> ft_strmapi </td><td> dışarıdan gönderilen sitring değeri f fonksiyonundan dönen değeri malloc ile ayrılan bellek alanına atan fonksiyondur</td></tr>
    <tr><td> ft_striteri </td><td> dışarıdan gönderilen sitring değeri f fonksiyonundan dönen değeri malloc ile yer ayırmadan ara bellekte döndüren fonksiyon</td></tr>
    <tr><td> ft_putchar_fd </td><td> char c parametresi le gönderilen fd parametresinin id sine yazan fonksiyon</td></tr>
    <tr><td> ft_putstr_fd </td><td> gönderilen stringi ekrana yazan fonksiyon</td></tr>
    <tr><td> ft_putendl_fd </td><td> gönderilen stringi ekrana yazan (döngü ile yazan) fonksiyon</td></tr>
    <tr><td> ft_putnbt_fd </td><td> gönderilen int değeri ekran basan fonksiyondur</td></tr>
    <tr><td>ft_lsrnew </td><td> yeni liste oluşturan fonksiyon</td></tr>
    <tr><td>ft_lstadd_front </td><td> yeni eleman atama ve atanan elemanı listenin başına atayan fonksiyondur</td></tr> 
    <tr><td>ft_lstsize </td><td> liste içerisinde ki elemanları sayan fonksiyondur</td></tr>
    <tr><td>ft_lstlas </td><td> liste içerisinde ki son elemana ulaşan fonksiyon</td></tr>
    <tr><td>ft_lstadd_back </td><td> liste içerisinde son elemana ulaşıp en sona atama</td></tr>
    <tr><td>ft_lstdelone </td><td> liste içerisinde ki bir elemanı silme işlemi </td></tr>
    <tr><td>ft_lstclear </td><td> tüm listeyi silen fonksiyon</td></tr>
    <tr><td>ft_lstiter </td><td> listenin contentini dışarıdan gönderinlen farklı bir fonksiyona gönderilen fonksiyondur</td></tr>
    <tr><td>ft_lstmap </td><td> listenin contentindeki elemanları dışarıdan gönderdiğimiz farklı bir fonksiyon ile çalıştırıp yeni çıktıyı listeye atar</td></tr>
  </tbody>
</table>

---
