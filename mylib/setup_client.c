#include "mylib.h"

int setup_client(char* hostname, in_port_t port){
    struct hostent *server_ent;
    struct sockaddr_in server;
    int soc;

    //ホスト名からアドレスを得る
    if((server_ent = gethostbyname(hostname)) == NULL){
        perror("gethostmyname\n");
        return -1;
    }

    //サーバーの情報を構造体に格納
    memset((char *)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    memcpy((char *)&server.sin_addr, server_ent->h_addr, server_ent->h_length);
    
    //ipv4でソケット作成
    if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket\n");
        return -1;
    }
    //サーバーに接続
    if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
        perror("connect\n");
        return -1;
    }
    fprintf(stderr, "connexted.\n");


    //ソケットを返す
    return soc;
}