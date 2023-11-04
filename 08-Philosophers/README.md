<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>Philosophers</h1>
  
  <p>
       Felsefenin bu kadar ölümcül olacağını hiç düşünmemiştim.
  </p>
</div>

<br />

<!-- Table of Contents -->
  ## Table of Content
  * [ Proje Hakkında ](#star2-Proje-Hakkinda)
  * [ Başlangıç ](#running-Başlangıç)
  * [ Gereksinimler ](#space_invader-Gereksinimler)

  * [ Kullanım ](#wrench-Kullanım)
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


Bu projede ile, bir süreci iş parçacığına ayırmanın temellerini, iş parçacıklarının nasıl oluşturulacağını ve muteksleri keşfettik.

<!-- ## :running: Başlangıç -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

## :wrench: Kullanım

Depoyu klonlayın ve içine gidin. Ardından derlemek için make kullanın.

```shell
make
cd philo
```

Daha sonra şu şekilde çalıştırın:

```shell
./philo 4 500 500 500
```

Argüman olarak 4 tane filozofun 500 ms ölme süresi 500 ms yeme 500 ms uyuma süresi tanımlamış olduk. 

İlk olarak id si tek tek olanlar uyur id si çift olanlar çatalları kullanır idsi çifft olanlar uyur idsi tek olanlar çatalları alıp yemek yerler. 

Ana kısımda `pthread` kütüphanesi kullanılırken bonus kısmında `semaphore` kütüphanesi ile yazılmıştır.  

---
