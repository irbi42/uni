count_occurrences(_, [], 0).
count_occurrences(Elem, [Elem|Tail], Count) :-
    count_occurrences(Elem, Tail, TailCount),
    Count is TailCount + 1.
count_occurrences(Elem, [Head|Tail], Count) :-
    Elem \= Head,
    count_occurrences(Elem, Tail, Count).

remove_duplicates([], []).
remove_duplicates([Head|Tail], Result) :-
    member(Head, Tail),
    remove_duplicates(Tail, Result), !.
remove_duplicates([Head|Tail], [Head|Result]) :-
    \+ member(Head, Tail),
    remove_duplicates(Tail, Result), !.

create_count_list(_,[],[]).
create_count_list(Original, [Head|UniqueTail], [[Head, Count]|Result]) :-
    count_occurrences(Head, Original, Count),
    create_count_list(Original, UniqueTail, Result).

goal :-
    write('Введите список: '),nl,
    read(OriginalList),

    remove_duplicates(OriginalList, UniqueList),
    create_count_list(OriginalList, UniqueList, Result),

    write('Результат: '), nl,
    write(Result), nl.
