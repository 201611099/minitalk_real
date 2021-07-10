# Minitalk
정리 노션: https://www.notion.so/minitalk-e5203e8c2622434f8176d983ad656f0c
## subject
> 실행파일 이름은 client와 server
> ### mandatory part
> > 두 프로그램 사이에서 통신은 반드시 UNIX **signal만**을 이용해야함 **(SIGUSR1, SIGUSR2만 사용 가능)**
> > #### server
> > <pre>
> > <code>
> > * 실행 시 pid를 출력해야함
> > * 클라이언트로부터 문자열을 받으면 반드시 화면에 출력해야함 
> > * 문자열을 나타낼 때 빠르게 나타내야함 (100개 1초 안에, 1000개 2초 안에)
> > * 서버는 재시작하지 않고 다양한 클라이언트로부터 메시지를 받을 수 있어야함
> > * 허용 함수: write, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit
> > </code>
> > </pre>
> > #### client
> > <pre>
> > <code>
> > * ./client server_PID message
> > </code>
> > </pre>
> ### bonus part
> > * 작은 수신 시스템(reception acknowledgement 추가하기
> > * 유니코드 문자열 지원 (https://namu.wiki/w/UTF-8)
