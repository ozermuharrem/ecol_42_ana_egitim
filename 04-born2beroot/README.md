<div align="center">

  <img src="https://raw.githubusercontent.com/ozermuharrem/ecol_42_ana_egitim/main/42_Logo.png" alt="logo" width="200" height="auto" />
  <h1>Born2beRoot</h1>
  
  <p>
      Sistem yönetimi için bir alıştırma
  </p>
</div>

<br />

<!-- Table of Contents -->

## Table of Content

- [ Proje Hakkında ](#star2-Proje-Hakkinda)
- [ Gereksinimler ](#space_invader-Gereksinimler)
- [ Kurulum ](#wrench-Kurulum)
- [Soru Cevap ](#question-Evaluation-Soru-Cevap)

#

## :star2: Proje Hakkinda

Linux sistem yönetimi ssh, sudo, ufw Crontab ve Monitoring.sh toolları ve yapıları kullanarak yeni bir server inşa ettiğimiz bir projedir. 

<!-- ## :running: Başlangıç

Okunmasını istediğiniz .txt dosyasını main.c veye dosyanın başka bir kısmında `get_next_line()` fonksiyonuna .txt dosyasının fd sini vererek okumasını sağlayabilirsiniz. -->

## :space_invader: Gereksinimler

Linux işletim sistemi Debian veya CentOS Dağıtımlarında bir tanesi. 

## :wrench: Kurulum

Tüm işlemleri 'su -' komutu içerisinde yapın. su dan çıkmak için 'exit' yazın.

> su -

Sudo Kurulum
> apt install sudo

### Sudo grubuna kullanıcıyı ekleme
Kullanıcı ekle
> adduser kullanıcıAdınız sudo

Doğrulama
> getent group sudo
yada
> groups kullanıcıAdınız

Sudoers dosyasına kullanıcıyı ekleme
> visudo

Bu satırları ekleme
> kullanıcıAdınız	ALL=(ALL) ALL


Wget'i yükleme (Web depolarından dosya indirmek için wget kuruyoruz)
> apt-get install wget


### SSH Kurulum | Uzak bağlantıları şifreleyerek güvenli şekilde bağlantı yapmamızı sağlayan servis.
> apt-get update

> apt install openssh-server

SSH server durumu kontrol
> service ssh status

Port ayarlama
> nano /etc/ssh/sshd_config

'#Port 22' kısmını 'Port 4242' olarak değişin
'PermitRootLogin' kısmında yorum satırı kaldırıp karşısına no yazın;
> PermitRootLogin no
4242 Portuna doğrudan root olarak erişim yapmanızı engeller

Portu Kontrol Et
> grep Port /etc/ssh/sshd_config

Servisi Yeniden Başlat
> service ssh restart


### UFW Kurulum | Ağ Güvenlik Duvarı
> apt-get install ufw

UFW Durum Kontrol
> ufw status
yada
> service ufw status

Açık portları numaralı listele
> ufw status numbered

> ufw allow ssh

4242 Portunu ekle
> ufw allow 4242

Portları tekrar listele
> ufw status numbered

Port sil | 'ufw status numbered' ile gelen portların başındaki numara yazılacak
> ufw delete 3

### SSH Bağlantısı yapmak için VirtualBox'dan port açmak
VirtualBox panelinden:
Ayarlar > Ağ > Gelişmiş > B.Noktası Yönlendirme
Anamakine ve misafir makine portuna 4242 yazın.

### Mac iTerm'den Debian sunucusuna SSH bağlantısı yap
> ssh kullanıcıAdın@localhost -p 4242


### sudoers grubunu yapılandırma
> nano /etc/sudoers
<pre>
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults	badpass_message="Hata Olustu"
Defaults	passwd_tries=3
Defaults	logfile="/var/log/sudo/sudo.log"
Defaults	log_input,log_output
Defaults	requiretty
</pre>
### Sudoers Tanımlar
- sudoers		=	sudoers dosyası, Linux ve Unix yöneticilerinin sistem haklarını sistem kullanıcılarına tahsis etmek için kullandıkları bir dosyadır.
- mail_badpass	=	sudo girişi yapmak isteyen kullanıcı doğru parolayı girmezse, yöneticiye posta/bildirim gönderir.
- loglar          =       sudo komutu ile yapılan tüm işlemler sudo/sudo.log dosyasına kayıt edilir. sudo.log dosya bulunamadı hatası veriyorsa /var/log/ dizininde 'mkdir sudo' klasörünü oluşturun.
- requiretty      =       pdf de tty modu aktif edilmelidir yazıyor. sudo girişlerini doğrudan klavye girdisi ile yapılmasını istiyoruz. Yani uzaktan, script yönetimi ile şifre girilmesini istemiyoruz.


### Ana bilgisayarın adını değişme
Mevcut ana bilgisayar adını kontrol etme
> hostnamectl

Ana bilgisayarın adını değiştirme
> hostnamectl set-hostname yeni_isim

/etc/host dosyasını değişme
> nano /etc/hosts

Eski pc adını değişme
> 127.0.0.1       localhost

> 127.0.0.1       yeni_isim
'reboot' yazarak sistemi yeniden başlat

### Şifre Politikaları
> apt-get install libpam-pwquality

> nano /etc/pam.d/common-password

> password        requisite                       pam_pwquality.so retry=3 minlen=10 lcredit =-1 ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7 enforce_for_root

### Şifre Politikaları Tanımlar
<pre>
lcredit         =       Küçük Harf
ucredit         =       Büyük Harf
dcredit         =       Rakam
maxrepeat       =       Ardışık karakter olmasın
usercheck       =       Kullanıcı adı içermesin
minlen          =       Minimum 10 karakter
difok           =       Eski şifreden kaç karakter farklı olacağını belirliyor
enforce_for_root=       Bu kurallar root içinde geçerli olmalı
-1 değeri       =       En az 1 karakter olmasını istiyoruz. Pozitif değer olursa en fazla karakteri belirlemiş oluruz.
</pre>

### Şifre Kullanım Süreleri
> nano /etc/login.defs
Bu satırları bulup değerleri değiştirin.
<pre>
PASS_MAX_DAYS 30      =       30 günde bir şifre değiştirilmesi gerekiyor
PASS_MIN_DAYS 2       =       Şifre değiştirildiği 2 gün içinde tekrar değişiklik yapılmasın
PASS_WARN_AGE 7       =       Değişikliğe son 7 gün kala uyarı ver
</pre>
'reboot' yazarak sistemi yeniden başlat


### Crontab ve Monitoring.sh
> apt-get update -y

> apt-get install -y net-tools

/usr/local/bin/ yolunda monitoring.sh dosyası oluştur

> nano monitoring.sh

<pre>
ARCH=$(uname -a)
PCPU=$(cat /proc/cpuinfo | grep cpu\ cores | uniq | wc -l)
VCPU=$(cat /proc/cpuinfo | grep processor | wc -l)
CPUUSG=$(top -b -n1 | grep "Cpu(s)" | awk '{print $2 + $4"%"}')
LASTBOOT=$(who -b | awk '{print $3,$4}')
lvmrtn=$(lsblk | grep "lvm" | wc -l)
LVMGET=$(if [ $lvmrtn -eq 0 ]; then echo no; else echo yes; fi)
TCPCNT=$(netstat | grep ESTABLISHED | wc -l)
TCPEST=$(netstat | grep ESTABLISHED | awk '{print($6)}')
USRCNT=$(who | wc -l)
NTWRKMAC=$(ip link show | grep link/ether | awk '{print($2)}')
NTWRKIP=$(hostname -I)
SUDOCNT=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
MEMUSG=$(free -m | grep Mem: | awk '{print($3)}')
MEMUSGTTL=$(free -m | grep Mem: | awk '{print($2)}')
MEMUSGPRCNT=$(free -m | grep Mem: | awk '{printf("%.2f"),($3/$2*100)}')
DSKUSGMB=$(df -BM --total | grep total | awk '{print($2)}' | tr -d M)
DSKUSGGB=$(df -BG --total | grep total | awk '{print($3)}' | tr -d G)
DSKUSGPRCNT=$(df --total | grep total | awk '{print($5)}')
wall "
        #Architecture: $ARCH
        #CPU physical : $PCPU
        #vCPU : $VCPU
        #Memory Usage: $MEMUSG/$MEMUSGTTL"MB" ($MEMUSGPRCNT"%")
        #Disk Usage: $DSKUSGMB/$DSKUSGGB"Gb" ($DSKUSGPRCNT)
        #CPU load: $CPUUSG
        #Last boot: $LASTBOOT
        #LVM use: $LVMGET
        #Connexions TCP : $TCPCNT $TCPEST
        #User log: $USRCNT
        #Network: "IP" $NTWRKIP ($NTWRKMAC)
        #Sudo : $SUDOCNT cmd
"
</pre>

Sudoers dosyasına, sudo parolası istemeden uygulayacağı kuralı ekliyoruz

> visudo

> username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh

Crontab
> crontab -u root -e

> */10 * * * * /usr/local/bin/monitoring.sh

___

### BONUS
#### Kullanacağımız servisleri kuralım
> apt install lighttpd -y

> apt install mariadb -y

> mysql_secure_installation

#### Mariadb ile mysql veritabanı oluşturma
Burada yazılacak username ve şifreler intra bilgisini gerektirmiyor, yani özgürsünüz. 
> mariadb

> CREATE DATABASE dbname;

> GRANT ALL ON bonus. * TO 'username'@'localhost' IDENTIFIED BY 'sifre' WITH GRANT OPTION;

> exit

Db oluşturulduğunu doğrulamak için giriş yapıyoruz.
> mariadb -u username -p

> şifreniz

> show databases;

> exit

#### PHP ve Wordpress Kurulum
> apt install php-cgi php-mysql -y

> cd /var/www/html

> wget http://wordpress.org/latest.tar.gz -P /var/www/html

> tar -xzvf /var/www/html/latest.tar.gz

> rm /var/www/html/latest.tar.gz

> cp -r /var/www/html/wordpress/* /var/www/html

> cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

nano /var/www/html/wp-config.php
> Şu satırları düzenleyin
<pre>
define( 'DB_NAME', 'veritabanı_adı');
define( 'DB_USER', 'veritabanı_kullanıcısı');
define( 'DB_PASSWORD', 'veritabanı_kullanıcısı_şifresi');
</pre>

> lighty-enable-mod fastcgi

> lighty-enable-mod fastcgi-php

> service lighttpd force-reload

> apt install vsftpd

> vim /etc/vsftpd.conf
Bu satırlardaki # işaretini kaldırın.
> write_enable=YES
En alt satıra şunları ekleyin;
<pre>
user_sub_token=$USER
local_root=/home/$USER/ftp
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
</pre>

> mkdir /home/username/ftp

> mkdir /home/username/ftp/files

> chown nobody:nogroup /home/username/ftp

> chmod a-w /home/username/ftp

vsftpd.userlist dosyasını oluştur
> nano /etc/vsftpd.userlist
kullanıcı adını içine yaz.

Tarayıcınıza localhost:8080 yada 127.0.0.1:8080 yazarak wordpress kurulumunu tamamlayın ve projenizi bitirin.


## :question: Evaluation Soru Cevap

Born2Beroot Projesi Evaluation Soruları ve Kısa Cevapları

##### 1. Seçtiğin işletim sistemi nedir?
<pre>Yüklediğiniz işletim sistemi</pre>

##### 2. Debian ile CentOS arasındaki basit farklar
<pre>İki sistem arasında büyük bir fark yoktur. Debian sık güncellemeler alır ve CentOS'a göre kullanımı daha basittir.</pre>

##### 3. Sanal makinelerin amacı nedir?
<pre>Bir sistem üzerinde birden fazla farklı işletim sistemi kurabilir ve her açıdan tasarruf sağlar.</pre>

##### 4. CentOS'u seçtiysen SElinux ve DNF nedir?
<pre>SElinux: Linux çekirdeğine eklenmiş ek bir güvenlik protokolü modülüdür.
DNF: Paket yöneticisidir.
</pre>

##### 5. Debianı seçtiysen aptitude ve apt arasındaki farklar nedir?
<pre>İkiside paket indirme yöneticisidir. Aptitude apt ye göre daha gelişmiştir ve bir arayüze sahiptir.</pre>

##### 6. Debianı seçtiysen APParmor nedir?
<pre>Linux çekirdeğine eklenmiş bir güvenlik protokolüdür. Sistemin güvenliğini sağlar.</pre>

##### 7. UFW Nedir? APParmor ile arasındki fark nedir?
<pre>UFW port yönetimini sağlayan ağ güvenlik duvarıdır. AppArmor sistem güvenliğini sağlar.</pre>

##### 8. SSH Nedir?
<pre>Uzak sistemlere şifreli şekilde güvenli bağlantı sağlar.</pre>

#### Fiziksel Sorular
##### 1. UFW service başlatılmış mı diye kontrol et
<pre>ufw status
yada
service ufw status</pre>

##### 2. SSH service başlatılmış mı diye kontrol et
<pre>service ssh status</pre>

##### 3. Sistemin Debian mı CentOS'mu olup olmadığını kontrol et
<pre>hostnamectl
yada
uname -a</pre>

#### Kullanıcı İşlemleri
##### 1. Kullanıcı sudo grubuna ekli mi diye kontrol et.
<pre>groups KullanıcıAdın</pre>

##### 2. Yeni bir kullanıcı oluştur, şifreyi kurallara uygun olarak koy, bu kuralları nasıl oluşturduğunu açıkla.
<pre>'adduser username' yazarak kullanıcı oluşturulur ve şifre koyulur.
Şifre kuralları için şu dosyayı aç; nano /etc/pam.d/common-passwd
</pre>

##### 3. evaluating adında bir grup oluştur, bu gruba oluşturduğun yeni kullanıcı ata ve kontrol et.
<pre>addgroup evaluating
adduser evaluating username
groups username
</pre>

##### 4. son olarak şifre kurallarının avantajlarını ve dezavantajlarını açıkla.
<pre>Avantajı: Brute force gibi saldırılara karşı güvenlidir, tahmin edilmesi zordur.
Dezavantajı: Şifrenin uzun olması, her ay farklı şifre istemesi unutulabilir oluyor.</pre>

#### Hostname ve Partiton
##### 1. hostname'in <ogrenci ismi>42  formatına uygun olup olmadığını kontrol et
<pre>hostnamectl</pre>
  
##### 2. hostnameyi değiştir 
<pre>hostnamectl set-hostname username42</pre>
  
##### 3. hostnameyi eski haline geri döndürebilirsin.
  
##### 4. partitonları listele
<pre>lsblk</pre>

#### SUDO
##### 1. /var/log/sudo klasörünün olup olmadığına bak ve içinde en azında bir dosyanın olduğunu teyit et
##### 2. sudo ile bir komut gerçekleştir ve /var/log/sudo'da ki dosyada değişim olup olmadığını teyit et

#### UFW
##### 1. UFW'nin aktif kurallarını listele, 4242 portu listede olmalı
<pre>ufw status</pre>

##### 2. 5353 portu için yeni bir kural ekle, kontrol et.
<pre>ufw allow 5353</pre>
  
##### 3. yeni eklenen kuralı sil
<pre>'ufw status numbered' ile 5353 portunun sıra numarasını alabilirsiniz.
'ufw delete sıraNo' yazarak silebilirsiniz.</pre>
  
#### SSH
##### 1. SSH servisinin sadece 4242 portunu kullandığından emin ol
  <pre>nano /etc/ssh/sshd_config</pre>
##### 2. Yeni oluşturulan kullanıcı ile SSH kullanarak bağlantı kurunuz.

#### Monitoring
##### 1. Script nasıl çalışıyor kodları anlat
##### 2. cron nedir
  <pre>Zamanlı görev dosyası</pre>
##### 3. bu scripti 1dk'da çalışmaya ayarla
  
#### BONUS
##### 1. Kurulum aşamalarını anlat. Lighttpd ve mariadb nedir?
##### 2. 127.0.0.1:8080 adresine gir, açık olup olmadığını kontrol et.

---

*Kurulum ve Soru Cevap Kısımlarını Enes Hazır Hazırlamıştır*