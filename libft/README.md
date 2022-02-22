<h1 aling="center">Libft 42 Cursus</h1>

<p>'ft_isalpha' -> Alfabetik karekter testi </p>
<p>'ft_isdigit' -> Sayısal karekter testi</p>
<p>'ft_isalnum' -> Alfanumerik karekter testi</p>
<p>'ft_isascii' -> Ascii değeri olan karekterlerin testi</p>
<p>'ft_isprint' -> Yazılabilir karekterlerin testi Not: Arapça, Japonca Gibi Yazı Karekterleri 1 Döndürür</p>
<p>'ft_strlen' -> s paremetresi ile gönderilen karekter dizisinin uzunluğunu sayar fonksiyon</p>
<p>'ft_memset' -> str paremetresi ile gönderilen karekter dizisini len paremetresi kadar c paremetresi ile gönderilen karekter ile değiştiren fonksiyon</p>
<p>'ft_bzero' -> Bellekte n kadar s bytında ki değeri silen fonksiyon</p>
<p>'ft_memcpy' -> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon</p>
<p>'ft_memmove' -> * src paremetresi ile gösterilen bellek bölgesinde ki karekterleri n paremetresi değeri kadar uzunlukta dst paremetresinde ki bellek bölgesine kopyalayan fonksiyon ft_memcpy den farkı over-lop kopya her zaman tahribatsız bir şekilde yapılır. Sondan başlayarak kopyalar. </p>
<p>`ft_strlcpy` -> Dst ye her zaman tek bir NULL bayt yazar(boyut sıfır değilse). NULL ile sonlandırılacak src dizisinden dst'ye -1 karekter kadar kopyalar ve sonuna NULL atayarak sonlandırır.
<p> 'ft_strlcat' -> Ara belleğin tam boyutunu alır (yalnızca uzunluğunu değil) ve sonuna NULL ile sonlandırmayı garanti eder</p>
<p> 'ft_tolower' -> Büyük karekterleri küçülten fonksiyon </p>
<p> 'ft_toupper' -> Küçük karekterleri büyüten fonsiyon </p>
<p> 'ft_strchr' -> str paremetresi ile gösterilen karekter dizisinde ki c paremetresi ile gösterilen değerin (unsigned char olarak değerlendirilir) ilk geçtiği yeri arar ve bellek adresini gösteren bir işaretci ile geri döndürür. Özetle bir karekter dizisi içerisinde c paremetresi ile gösterilen karekteri ara bulduğu yerden sonrasını silen fonksiyon </p>
<p>'ft_strrchr' -> strchr dan farkı sondan başlayarak silmesi dir. </p>
<p> 'ft_strncmp' -> iki tane karekter dizisini n paremetresi kadar karşılaştırır eşit olmadığı kısmında ki karekterlerin ascii kadunu döndüren fonksiyon </p>
<p> 'ft_memchr' -> * s ile gösterilen karekter dizisinde ki c parmetresi ile gösterilen karekteri arar. Bulursa karekterin bellek adresini döndüren fonksiyon</p>
<p> 'ft_memcmp' -> iki bellek bloğunu karşılaştırır n paremetre değeri kadar elde ettiği değeri döndüren fonksiyon</p>
<p> 'ft_strnstr' -> samanlıkta iğne arayan fonksiyon</p>
<p> 'ft_atoi' -> str paremetresi ile gösterilen değeri int degere dönüştüren fonksiyon</p>
<p> 'ft_calloc' -> Size paremetre değeri kadar olan bellekte count paremetre değeri kadar sayıda bellek blogu tahsis eden ve açılan belleği sıfır değeri ile dolduran fonksiyon</p>
<p> 'ft_strdup' -> * s1 paremeteresi ile gösterilen karekter dizisinin aynısını geri döndüren fonksiyon</p>

<br><br>

<h2>Part 2</h2> 

<p>'ft_substr' -> * s ile gösterilen karekter dizisinin start paremetre değerinden sonrasını len paremetre değeri kadar döndüren fonksiyondur</p>
<p> 'ft_strjoin' -> * s1 paremetresi ile * s2 paremetresini birleştirir</p>
<p> 'ft_strtrim' -> * s1 paremetresi ile gösterilen karekter dizisinde ki * s2 paremetresinde ki karekterleri karşılaştırıp kırpan fonksiyon </p>




