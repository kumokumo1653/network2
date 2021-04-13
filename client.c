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
    struct hostent *server_ent;
    struct sockaddr_in server;
    int soc;
    char hostname[] = "localhost";
    char buf[BUF_LEN];

    //サーバーのホスト名からアドレスを得る
    if((server_ent = gethostbyname(hostname)) == NULL){
        perror("gethostmyname\n");
        exit(1);
    }


    //サーバーの情報を構造体に格納
    memset((char *)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char *)&server.sin_addr, server_ent->h_addr, server_ent->h_length);
    
    //ipv4でソケット作成
    if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket\n");
        exit(1);
    }
    //サーバーに接続
    if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
        perror("connect\n");
        exit(1);
    }

    //相手から
    write(1, "Wait\n", 5);

    //通信ループ
    do{
        int n;
        n = read(soc, buf, BUF_LEN);
        write(1, buf, n);
        n = read(0, buf, BUF_LEN);
        write(soc, buf, n);
    }while(strncmp(buf,"quit",4) != 0);

    close(soc);
    return 0;
}