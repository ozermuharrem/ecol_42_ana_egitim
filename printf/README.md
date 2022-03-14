<h1>FT_PRINTF</h1>

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
 
 <h2>Heksadesimal</h2>
 
 Heksadesimal (İngilizce kısaltmasıyla hex), matematik ve bilişim alanlarında kullanılan 16 tabanlı sayı sistemidir. <br>
 Heksadesimal sayı sisteminde sayılar 16 farklı sembolle temsil edilir. <br>
 0-9 arasında semboller 0 ile 9 arasında sayıları, A-F arasındaki harfler ise 10 ile 15 arasındaki sayıları temsil eder. 
<br><br> 
<h3>Ondalık sayıların on altılık sayıya çevrilişi</h3>

Ondalık sayı, bölüm sıfır olana kadar 16'ya bölünür. <br>
Bölme işlemi bittikten sonra, sırayla bölüm hanesindekiler ve en son olarak da kalan sayı soldan sağa yazılır. <br><br>
Örnek;<br>
<br>
100/16 = 4(kalan):6(bölüm) 6/16 = 6(kalan) = 64
<br><br>
Örnek;<br>
<br>

![277](https://user-images.githubusercontent.com/86782430/158175639-ccc746fb-95a9-4bb8-a540-bcacd4b43ac6.png) 

**heksadesimal** 101 çıkıt sağdan sola doğru yazılır .

<br><br>
Örnek;<br>
<br> 

![3412](https://user-images.githubusercontent.com/86782430/158179297-b5afc093-c3a7-4036-b7ff-c545b621b7ed.png)

**heksadesimal** d54 çıktı 
