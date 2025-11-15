goal:-writeln('Введите список'),read(L),writeln('Введите N'),
read(N),copy(L,N,L1),write('Результат:'),write(L1).
copy(L,N,L1):-copy(L,N,N,L1).
copy([],_,_,[]):-!.
copy([_|Tail],0,N,L1):-!,copy(Tail,N,N,L1).
copy([Head|Tail],N,K,[Head|L1]):-!,N1 is N-1,
copy([Head|Tail],N1,K,L1).
