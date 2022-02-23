<h1 aling="center">Libft 42 Cursus</h1>
<ul>
<li>'ft_isalpha' -> Alfabetik karekter testi </li>
<li>'ft_isdigit' -> Sayısal karekter testi</li>
<li>'ft_isalnum' -> Alfanumerik karekter testi</li>
<li>'ft_isascii' -> Ascii değeri olan karekterlerin testi</li>
<li>'ft_isprint' -> Yazılabilir karekterlerin testi Not: Arapça, Japonca Gibi Yazı Karekterleri 1 Döndürür</li>
<li>'ft_strlen' -> s paremetresi ile gönderilen karekter dizisinin uzunluğunu sayar fonksiyon</li>
<li>'ft_memset' -> str paremetresi ile gönderilen karekter dizisini len paremetresi kadar c paremetresi ile gönderilen karekter ile değiştiren fonksiyon</li>
<li>'ft_bzero' -> Bellekte n kadar s bytında ki değeri silen fonksiyon</li>
<li>'ft_memcpy' -> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon</li>
<li>'ft_memmove' -> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon ft_memcpy den farkı over-lop kopya her zaman tahribatsız bir şekilde yapılır. Sondan başlayarak kopyalar. </li>
<li>`ft_strlcpy` -> Dst ye her zaman tek bir NULL bayt yazar(boyut sıfır değilse). NULL ile sonlandırılacak src dizisinden dst'ye -1 karekter kadar kopyalar ve sonuna NULL atayarak sonlandırır.</li>
<li> 'ft_strlcat' -> Ara belleğin tam boyutunu alır (yalnızca uzunluğunu değil) ve sonuna NULL ile sonlandırmayı garanti eder</li>
<li> 'ft_tolower' -> Büyük karekterleri küçülten fonksiyon </li>
<li> 'ft_toupper' -> Küçük karekterleri büyüten fonsiyon </li>
<li> 'ft_strchr' -> str paremetresi ile gösterilen karekter dizisinde ki c paremetresi ile gösterilen değerin (unsigned char olarak değerlendirilir) ilk geçtiği yeri arar ve bellek adresini gösteren bir işaretci ile geri döndürür. Özetle bir karekter dizisi içerisinde c paremetresi ile gösterilen karekteri ara bulduğu yerden sonrasını silen fonksiyon </li>
<li>'ft_strrchr' -> strchr dan farkı sondan başlayarak silmesi dir. </li>
<li> 'ft_strncmp' -> iki tane karekter dizisini n paremetresi kadar karşılaştırır eşit olmadığı kısmında ki karekterlerin ascii kadunu döndüren fonksiyon </li>
<li> 'ft_memchr' -> * s ile gösterilen karekter dizisinde ki c parmetresi ile gösterilen karekteri arar. Bulursa karekterin bellek adresini döndüren fonksiyon</li>
<li> 'ft_memcmp' -> iki bellek bloğunu karşılaştırır n paremetre değeri kadar elde ettiği değeri döndüren fonksiyon</li>
<li> 'ft_strnstr' -> samanlıkta iğne arayan fonksiyon</li>
<li> 'ft_atoi' -> str paremetresi ile gösterilen değeri int degere dönüştüren fonksiyon</li>
<li> 'ft_calloc' -> Size paremetre değeri kadar olan bellekte count paremetre değeri kadar sayıda bellek blogu tahsis eden ve açılan belleği sıfır değeri ile dolduran fonksiyon</li>
<li> 'ft_strdup' -> * s1 paremeteresi ile gösterilen karekter dizisinin aynısını geri döndüren fonksiyon</li>
</ul>
<br><br>

<h2>Part 2</h2> 
<ul>
<li>'ft_substr' -> * s ile gösterilen karekter dizisinin start paremetre değerinden sonrasını len paremetre değeri kadar döndüren fonksiyondur</li>
<li> 'ft_strjoin' -> * s1 paremetresi ile * s2 paremetresini birleştirir</li>
<li> 'ft_strtrim' -> * s1 paremetresi ile gösterilen karekter dizisinde ki * s2 paremetresinde ki karekterleri karşılaştırıp kırpan fonksiyon </li>
<li> 'ft_split' -> * s1 paremetresi ile gönderilen dizinin içerisinde bulunan c paremetresi ile gösterilen karekterlerden böler</li>
<li> 'ft_itoa' -> n paremetresi ile gönderilen int değeri sitringe çevirir.</li>
<li> 'ft_strmapi' -> dışarıdan gönderilen sitring değeri f fonksiyonundan dönen değeri malloc ile ayrılan bellek alanına atan fonksiyondur</li>
<li> 'ft_striteri' -> dışarıdan gönderilen sitring değeri f fonksiyonundan dönen değeri malloc ile yer ayırmadan ara bellekte döndüren fonksiyon</li>
<li> 'ft_putchar_fd' -> char c parametresi le gönderilen fd parametresinin id sine yazan fonksiyon</li>
<li> 'ft_putstr_fd' -> gönderilen stringi ekrana yazan fonksiyon</li>
<li> 'ft_putendl_fd' -> gönderilen stringi ekrana yazan (döngü ile yazan) fonksiyon</li>
<li> 'ft_putnbt_fd' -> gönderilen int değeri ekran basan fonksiyondur</li>
</ul>  
<br><br>
  
<h2>Bonus Part<h2>  
<ul>
<li>'ft_lsrnew' -> yeni liste oluşturan fonksiyon</li>
<li>'ft_lstadd_front' -> yeni eleman atama ve atanan elemanı listenin başına atayan fonksiyondur</li> 
<li> 'ft_lstsize' -> liste içerisinde ki elemanları sayan fonksiyondur</li>
<li> 'ft_lstlas' -> liste içerisinde ki son elemana ulaşan fonksiyon</li>
<li> 'ft_lstadd_back' -> liste içerisinde son elemana ulaşıp en sona atama</li>
<li> 'ft_lstdelone' -> liste içerisinde ki bir elemanı silme işlemi </li>
<li> 'ft_lstclear' -> tüm listeyi silen fonksiyon</li>
<li>'ft_lstiter' -> listenin contentini dışarıdan gönderinlen farklı bir fonksiyona gönderilen fonksiyondur</li>
<li>'ft_lstmap' -> listenin contentindeki elemanları dışarıdan gönderdiğimiz farklı bir fonksiyon ile çalıştırıp yeni çıktıyı listeye atar</li>
</ul> 
  
  <hr>
  
  <h2>Makefile</h2>
  
  <p> eşittir ile gösterilenler değişkendir </p>
  <p>iki nokta kural atam işlemi </p>
  arşiv bir dosyası na tek tek derlememek için ihtiyaç duyarız 
  -c arşiv oluşturmak için -o dosyalarına ihtiyacımız var 
  -o dosyası olmadan arşiv dosyası olmaz 
  
  <h2>Libft.h</h2>
  
 <p> #ifndef ="if not defined" anlamındadır. Bir sabitin tanımlanmamış olması halinde ne yapılacağını bildirmeye yarar. #include Başka bir kütükten kaynak program ya da text çağırmak için kullanılır. #if Bir önişlemci sabitinin ya da ifadenin DOĞRU olup olmadığını denetler. </p>
<p>  #define = önişlemci direktifi, programlarımızın herhangi bir işlem satırında kullanılmak üzere, istediğimiz ifadelerin kısa bir isim altında tanımlamamızı sağlar. </p>

<p>size_t = bir nesnenin boyutunu tutan herhangi bir değişken yada argüman bildiriminde önerilen yoldur. 
GNU Sisteminde size_t ya unsigned int yada unsigned long int türüne eşdeğerdir. </p>
