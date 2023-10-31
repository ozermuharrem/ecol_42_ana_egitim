<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>Push_Swap</h1>
  
  <p>
       swap_push o kadar doğal değil.
  </p>
</div>

<br />

<!-- Table of Contents -->
  ## Table of Content
  * [ Proje Hakkında ](#star2-Proje-Hakkinda)
  <!-- * [ Başlangıç ](#running-Başlangıç) -->
  * [ Gereksinimler ](#space_invader-Gereksinimler)

  * [ Kullanım ](#wrench-Kullanım)
  * [ Push_Swap Kuralları ve Derecelendirme ](#Push_Swap-Kuralları-ve-Derecelendirme)
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

Bu proje bize mümkün olan endüşük sayıda hamleyi yaparak ve sınırlı bir talimat seti kullanarak bir yığındaki verileri sıralatacak.Başarabilmek için çeşitli tiplerdeki  algoritmaları manipüle edip optimal bir veri sıralaması için en uygun olanını (birçoğu arasından) seçmemiz gerek.

<!-- ## :running: Başlangıç

Okunmasını istediğiniz .txt dosyasını main.c veye dosyanın başka bir kısmında `get_next_line()` fonksiyonuna .txt dosyasının fd sini vererek okumasını sağlayabilirsiniz. -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

## :wrench: Kullanım

Depoyu klonlayın ve içine gidin. Ardından derlemek için make kullanın.

Daha sonra şu şekilde çalıştırın:

```shell
./push_swap <sayılar>
```

Sağlanan sayılar pozitif veya negatif tamsayılar olabilir. Tekrarlayan sayılar olmamalıdır. 

```shell
./push_swap 9 0 -217 2147483647 -2147483648

```

Argümanlar geçerli ise, program listeği sıralamak için en verimli işlem listesini çıkaracaktır.

Program, verilen kontrolcü ile kontrol edilebilir, şu şekilde:

Linux işletim sistemi için `checker_linux` Mac için `chacker_Mac` ile derleyin.

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker_<...> $ARG
```

## Push_Swap Kuralları ve Derecelendirme

Program sadece iki yığınla çalışmak için izin verilen yığın A ve yığın B'yi kullanabilir. Tüm sayılar başlangıçta yığın A'ya eklenir ve B boştur.

Mümkün olan işlemler şunlardır:

- pa (A'ya it): B'nin üstündeki ilk öğeyi alın ve A'nın üstüne koyun. B boşsa hiçbir şey yapmayın.
- pb (B'ye it): A'nın üstündeki ilk öğeyi alın ve B'nin üstüne koyun. A boşsa hiçbir şey yapmayın.
- sa (A'yı değiştir): A yığınının üstündeki ilk 2 öğeyi değiştirin. Yalnızca bir veya hiç öğe yoksa hiçbir şey yapmayın.
- sb (B'yi değiştir): B yığınının üstündeki ilk 2 öğeyi değiştirin. Yalnızca bir veya hiç öğe yoksa hiçbir şey yapmayın.
- ss: sa ve sb aynı anda.
- ra (A'yı döndür): A yığınının tüm öğelerini 1 ile yukarı kaydırın. İlk öğe sonuncu olur.
- rb (B'yi döndür): B yığınının tüm öğelerini 1 ile yukarı kaydırın. İlk öğe sonuncu olur.
- rr: ra ve rb aynı anda.
- rra (A'yı ters döndür): A yığınının tüm öğelerini 1 ile aşağı kaydırın. Son öğe ilk olur.
- rrb (B'yi ters döndür): B yığınının tüm öğelerini 1 ile aşağı kaydırın. Son öğe ilk olur.
- rrr: rra ve rrb aynı anda.

Not: Derece, programın sıralama sürecinin ne kadar verimli olduğuna bağlıdır.

<br>

+ 3 değeri sıralama: en fazla 3 işlem.
+ 5 değeri sıralama: en fazla 12 işlem.
+ 100 değeri sıralama: işlem sayısına bağlı olarak 1 ile 5 puan arasında değerlendirme yapılır:
+ 700 işlemden az ise 5 puan
+ 900 işlemden az ise 4 puan
+ 1100 işlemden az ise 3 puan
+ 1300 işlemden az ise 2 puan
+ 1500 işlemden az ise 1 puan
+ 500 değeri sıralama: işlem sayısına bağlı olarak 1 ile 5 puan arasında değerlendirme yapılır:
+ 5500 işlemden az ise 5 puan
+ 7000 işlemden az ise 4 puan
+ 8500 işlemden az ise 3 puan
+ 10000 işlemden az ise 2 puan
+ 11500 işlemden az ise 1 puan

---
