<!--
Hey, thanks for using the awesome-readme-template template.  
If you have any enhancements, then fork this project and create a pull request 
or just open an issue with the label "enhancement".

Don't forget to give this project a star for additional support ;)
Maybe you can mention me or this repo in the acknowledgements too
-->
<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>Get_Next_Line</h1>
  
  <p>
       Fd de bir satır okumak çok sıkıcı
  </p>
</div>

<br />

<!-- Table of Contents -->
  ## Table of Content
  * [ Proje Hakkında ](#star2-Proje-Hakkinda)
  * [ Başlangıç ](#running-Başlangıç)
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

Bu projenin amacı bir sonra ki projelerimizde de Bu projenin amacı file descriptordan okunan bir satırı dönen fonksiyonu yazmamızı sağlamak.

## :running: Başlangıç

Okunmasını istediğiniz .txt dosyasını main.c veye dosyanın başka bir kısmında `get_next_line()` fonksiyonuna .txt dosyasının fd sini vererek okumasını sağlayabilirsiniz.

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

##  🛠️  Kullanım

  + get_next_line klasötünü kendi projenize dehil etmek için. 
  ```c
  #include "<path>/get_next_line.h" 
  ```

  main.c dosyası içerisinde veya başa bir fonksiyonun içerisinde `get_next_line()` fonksiyonuna `open()` ile açılmış ve okuma izini verilmiş dosyayı okur. Kullanım şekli main.c de aşağıda ki gibidir. 

  ```c
  #include "get_next_line.h" 
  #include <stdio.h>

  int main(){
   int fd;
		int fd;
    	fd = open("test.txt", 'r');
    	printf("%s", get_next_line(fd));

    return 0;
  }
  ```

  Derlemek için

  ```shell
  gcc -Wall -Wextra -Werror *.c  && ./a.out
  ```
  herhangi bir hata ile karşılaşmazsa `test.txt` içerisinde `\n` yeni satır görene kadar okur okuduğunu döner.

---
