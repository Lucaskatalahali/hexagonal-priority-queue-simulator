Not 1: Bu proje, ağaçların çıkarılacağı Data.txt dosyasının en az 50.000 satıra sahip olmasını gerektirir. 
Ancak, cmd terminali bu kadar çok satırı yazdırmakta zorlanabilir ve tampon bellek sınırı nedeniyle ilk satırları silebilir. 
Bu nedenle, terminaldeki son satırların her zaman tam olacağını, ancak ilk satırların kesilebileceğini göz önünde bulundurmanızı rica ederim. 
Programı VS Code terminali yerine doğrudan cmd üzerinden çalıştırırsanız bu sorun ortadan kalkabilir. 
Tur sayısını çıktının başında gösterseydim, programın nerede çalıştırıldığına bağlı olarak bu bilgi kesilebilirdi.
Bu yüzden, her zaman görünür olması için bu bilgiyi çıktının sonuna ekledim.

Not 2: Data.txt dosyası projenin kök dizininde bulunmaktadır. 
Eğer program doğrudan cmd üzerinden çalıştırılırsa (VS Code üzerinden değil), Data.txt dosyasını çalıştırılabilir dosyanın (.exe) bulunduğu bin 
klasörüne taşımanız gerekebilir.

Not 3: Altıgen listesindeki düğümlerin (kenarların) kalıcı olduğunu varsaydım. Yani, kenarlardan birindeki veriyi sildiğimizde, 
ağaç kaldırılır ancak o alan var olmaya devam eder. Başka bir deyişle, verisi silinse bile kenar fiziksel olarak mevcuttur.
Böylece o pozisyon yeni ağaçlar alabilir.

Not 4: Proje metni, altıgenlerin 6'şarlı gruplar halinde basılması gerektiğini belirtiyor.
Ancak, proje dokümanındaki örnek görselde çift numaralı satırlardaki altıgenlerin ters sırada basıldığı görülmektedir; 
çünkü altıncı altıgenden çıkan çizgi on ikinci altıgene gitmektedir (zig-zag yapısı). 
Arka planda listedeki bağlantının 6. altıgenden 7. ye doğru olduğu bilinse de, ekrana yazdırma işleminde, 
proje dokümanındaki görsele sadık kalmak için çift satırlardaki altıgenleri sondan başa doğru (ters sırada) yazdırdım.