## Lowlevel IO vs Standard IO  

One of the differences between the lowlevel IO read and write and the standard library IO fread and fwrite, is that fwrite doesn't dive down into the kernel every time you call it.  
It accumulate the output into a buffer and only travels the kernel when it's got a worthwhile amount of data to write.  
And under some circumstances, this acn make abig difference to the performance.   


```
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$ time ./rawio 1 10000000

real	0m10.782s
user	0m1.221s
sys	0m9.417s
ryan01@ryan01:~/linux_system_programming/02$ time ./bufio 1 10000000

real	0m0.381s
user	0m0.373s
sys	0m0.000s
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$ time ./rawio 100 10000

real	0m0.013s
user	0m0.000s
sys	0m0.013s
ryan01@ryan01:~/linux_system_programming/02$ time ./bufio 100 10000

real	0m0.003s
user	0m0.003s
sys	0m0.000s
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$
ryan01@ryan01:~/linux_system_programming/02$ don't do the io in tiny little pieces

```
