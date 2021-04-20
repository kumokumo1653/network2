#include "mylib.h"

int setup_server(in_port_t port){
    struct sockaddr_in me;
    int soc_waiting;
    int soc;

    memset((char *) &me, 0, sizeof(me));
    me.sin_family = AF_INET;
    me.sin_addr.s_addr = htonl(INADDR_ANY);
    me.sin_port = htons(port);

    //ipv4のソケット作成
    if((soc_waiting = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket\n");
        return -1;
    }

    //ソケットに自分のアドレスを設定
    if(bind(soc_waiting, (struct sockaddr *) &me, sizeof(me)) == -1){
        perror("bind\n");
        return -1;
    }

    //ソケットで待ち受ける
    listen(soc_waiting, 1);
    fprintf(stderr, "successfully bound, now waintg.\n");

    //接続要求が来るまでブロック
    soc = accept(soc_waiting, NULL, NULL);

    //ソケットを閉じる
    close(soc_waiting);

    //通信に使うソケットを返す
    return soc;
}