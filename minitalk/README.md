# MiniTalk 

Server ile Client'in arasında ki iletişimi sağlamak için kullanılan program 

`gcc server.c minitalk_utulis.c minitalk_utulis2.c -I. -o server`

`gcc client.c minitalk_utulis.c minitalk_utulis2.c -I. -o client`

yeni bir terminal ekranında 

`./server` 

yazarak serverın PID numarasına ulaşıyoruz 

ulaşmış olduğumuz PID numarasını kullanarak istekte bulanacağız 

`./client 545454 merhaba`

