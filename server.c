#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT (in_port_t)50000
#define BUF_LEN 512

int main(void){
    struct sockaddr_in me;
    int soc_wainting; //listenするソケット接続を待つソケット
    int soc;            //送受信ソケット
    char buf[BUF_LEN];

    //自分のアドレスを格納
    memset((char *) &me, 0, sizeof(me));
    me.sin_family = AF_INET;
    me.sin_addr.s_addr = htonl(INADDR_ANY);
    me.sin_port = htons(PORT);

    //ipv4のソケット作成
    if((soc_wainting = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket\n");
        exit(1);
    }

    //ソケットに自分のアドレスを設定
    if(bind(soc_wainting, (struct sockaddr *) &me, sizeof(me)) == -1){
        perror("bind\n");
        exit(1);
    }


    //ソケットで待ち受ける
    listen(soc_wainting, 1);

    //接続要求が来るまでブロック
    soc = accept(soc_wainting, NULL, NULL);

    //ソケットを閉じる
    close(soc_wainting);

    //こちらから書き込む
    write(1, "Go ahead!\n", 10);

    //通信ループ
    do{
        int n;
        n = read(0, buf, BUF_LEN);
        write(soc, buf, n);
        n = read(soc, buf, BUF_LEN);
        write(1, buf, n);
    }while(strncmp(buf,"quit",4) != 0);

    //ソケットを閉じる
    close(soc);
}