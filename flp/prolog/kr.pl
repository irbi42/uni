

initialize_database :-
    (   exists_file('/home/irbi/prolog/metals.db')
    ->  consult('/home/irbi/prolog/metals.db'),
        write('База данных загружена из файла metals.db'), nl
    ;   write('Файл metals.db не найден. Создана пустая база данных.'), nl
    ).


save_database :-
    tell('/home/irbi/prolog/metals.db'),
    listing(metal),
    told,
    write('База данных сохранена в файл metals.db'), nl.

view_all_metals :-
    listing(metal),
    write('=== Конец базы данных ==='), nl.


add_metal :-
    write('Введите название металла: '), nl,
    read_line_to_string(user_input, NameStr),
    string_to_atom(NameStr, Name),
    
    write('Введите удельную проводимость: '), nl,
    read_line_to_string(user_input, CondStr),
    number_string(Conductivity, CondStr),
    
    assertz(metal(Name, Conductivity)),
    format('Добавлен металл: ~w с проводимостью ~w~n', [Name, Conductivity]),
    
    write('Добавить еще один металл? (y/n): '), nl,
    read_line_to_string(user_input, Answer),
    (   Answer = "y"
    ->  add_metal
    ;   true
    ).


delete_metal :-
    write('Введите название металла для удаления: '), nl,
    read_line_to_string(user_input, NameStr),
    string_to_atom(NameStr, Name),
    
    (   retract(metal(Name, Conductivity))
    ->  format('Удален металл: ~w с проводимостью ~w~n', [Name, Conductivity])
    ;   write('Металл с таким названием не найден.'), nl
    ),
    
    write('Удалить еще один металл? (y/n): '),
    read_line_to_string(user_input, Answer),
    (   Answer = "y"
    ->  delete_metal
    ;   true
    ).


find_max_conductivity_metals :-
    write('=== Металлы с максимальной проводимостью ==='), nl,
    
    findall(Conductivity, metal(_, Conductivity), Conductivities),
    (   Conductivities = []
    ->  write('База данных пуста.'), nl
    ;   max_list(Conductivities, MaxConductivity),
        
        findall(Name, metal(Name, MaxConductivity), MaxMetals),
        
        format('Максимальная проводимость: ~w~n', [MaxConductivity]),
        write('Металлы с максимальной проводимостью:'), nl,
        print_list(MaxMetals)
    ).


print_list([]).
print_list([H|T]) :-
    format('  - ~w~n', [H]),
    print_list(T).

show_menu :-
    nl,
    write('=== БАЗА ДАНЫХ МЕТАЛЛОВ ==='), nl,
    write('1. Просмотр всех металлов'), nl,
    write('2. Добавление металла'), nl,
    write('3. Удаление металла'), nl,
    write('4. Найти металлы с максимальной проводимостью'), nl,
    write('5. Выход и сохранение'), nl,
    write('Выберите пункт меню (1-5): '), nl.

process_choice(1) :-
    view_all_metals, !.
process_choice(2) :-
    add_metal,!.
process_choice(3) :-
    delete_metal,!.
process_choice(4) :-
    find_max_conductivity_metals, !.
process_choice(5) :-
    save_database,
    write('Выход из программы.'), nl, !.
process_choice(_) :-
    write('Неверный выбор. Попробуйте снова.'), nl,!.


goal :-
    initialize_database,
    repeat,
    show_menu,
    read_line_to_string(user_input, ChoiceStr),
    number_string(Choice, ChoiceStr),
    process_choice(Choice),
    Choice = 5,!.


