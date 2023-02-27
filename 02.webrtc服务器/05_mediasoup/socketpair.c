#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>


int main() {
	int sv[2];    //一对无名的套接字描述符
	if (socketpair(PF_LOCAL, SOCK_STREAM, 0, sv) < 0)   //成功返回零 失败返回-1
	{
		perror("socketpair");
		return 0;
	}

	pid_t id = fork();        //fork出子进程
	if (id == 0)               //孩子
	{

		const char* msg = "I'm children!\n";
		char buf[1024];

		close(sv[1]);

		while (1) {
			write(sv[0], msg, strlen(msg));
			sleep(1);

			ssize_t _s = read(sv[0], buf, sizeof(buf) - 1);
			if (_s > 0) {
				buf[_s] = '\0';
				printf("parent say to children : %s\n", buf);
			}
		}
	} else { // parent

		const char* msg = "I'm father!\n";
		char buf[1024];

		close(sv[0]);//关闭写端口

		while (1) {
			ssize_t _s = read(sv[1], buf, sizeof(buf) - 1);
			if (_s > 0) {
				buf[_s] = '\0';
				printf("Children say to parent : %s\n", buf);
				usleep(1);
			}
			write(sv[1], msg, strlen(msg));
		}
	}
	return 0;
}
