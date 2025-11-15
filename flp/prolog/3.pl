reverse_file :-
%    OutputFile = '/output.txt',
%    write('Введите имя файла: '), nl,
%    read(InputFile),
%    exists_file(InputFile),
    open('/home/irbi/prolog/input.txt', read, Input),
    open('/home/irbi/prolog/output.txt', write, Output),
    process_file_lines(Input, Output),
    close(Input),
    close(Output),
    write('Обработка завершена.'), nl.

process_file_lines(Input, Output) :-
    read_line_to_string(Input, Line),
    (   Line == end_of_file
    ->  true
    ;   reverse_words(Line, ReversedLine),
        writeln(Output, ReversedLine),
        process_file_lines(Input, Output)
    ).


reverse_words(Line, ReversedLine) :-
    split_string(Line, " ", "", Words),
    reverse_all_words(Words, ReversedWords),
    atomic_list_concat(ReversedWords, " ", ReversedLine).


reverse_all_words([], []).
reverse_all_words([Word|Rest], [Reversed|ReversedRest]) :-
    string_chars(Word, Chars),
    reverse(Chars, ReversedChars),
    string_chars(Reversed, ReversedChars),
    reverse_all_words(Rest, ReversedRest).
