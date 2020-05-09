Please use the following steps to reproduce:

1. install nim-lang
2. run `nim -d:useLibzipSrc c tests/reproduce.nim`, use `useLibzipSrc` because we want to compile it with `zip/private/libzip_all.c`.
3. run `cd tests; ./reproduce`, then run `cat /tmp/evil.txt`, and you shall see "this is an evil one". 
