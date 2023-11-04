<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>MiniShell</h1>
  
  <p>
       Bir deniz kabuğu kadar güzel
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


Bu proje basit bir shell oluşturmakla ilgilidir. Evet, kendi küçük bash'ımız. Süreçler ve dosya tanımlayıcıları hakkında çok şey göreceğiz.

<!-- ## :running: Başlangıç -->

## :space_invader: Gereksinimler

Fonksiyon C dilinde yazılmıştır ve bu nedenle çalışması için `gcc` derleyicisine ve bazı standart C kütüphanelerine ihtiyaç duyar.

## :wrench: Kullanım

Depoyu klonlayın ve içine gidin. Ardından derlemek için make kullanın.

```shell
make
```

Daha sonra şu şekilde çalıştırın:

```shell
./minishell
```

## Denemek İçin Bazı Komutlar

Bu proje, bash'ı taklit etmek için yapıldığından, normalde bash'ta denediğiniz herhangi bir komutu deneyebilirsiniz.

Eğer gerçekten bir şey düşünemiyorsanız, aşağıdaki bazı komutları deneyebilirsiniz. Her satırı ayrı ayrı girmeniz gerektiğini unutmayın, çünkü program yeni satırları işlemiyor. 

```shell
ls -la | grep a | tr 'a-z' 'A-Z'
```

```shell
cat << EOF > file
cat file
rm file
```

```shell
ls | rev > file
cat file
rev file | cat
rm file
``` 
Programdan çıkmak için

```shell
exit
``` 



---
