# Отчёт по лабораторной работе №2

## Тема
Изучение систем контроля версий на примере Git.

## Выполнение

### Part I
- Создан репозиторий Home2 на GitHub с лицензией MIT
- Настроен git (user.name, user.email)
- Создана структура папок: sources, include, examples
- Написан файл hello_world.cpp с плохим стилем (using namespace std)
- Выполнен первый коммит: "added sources"
- Файл обновлён: добавлен ввод имени пользователя
- Выполнен коммит без повторного git add, так как файл уже отслеживается

### Part II
- Создана ветка patch1
- Исправлен код: убран using namespace std, добавлены std::
- Добавлены комментарии к коду
- Выполнены коммиты и push в удалённый репозиторий
- Создан pull-request patch1 -> main
- PR смержен, ветка patch1 удалена

### Part III
- Создана ветка patch2
- Применён clang-format со стилем Mozilla
- Выполнены commit, push, создан pull-request patch2 -> main
- Выполнен rebase с веткой main
- Выполнен force push
- PR смержен, ветка patch2 удалена

## Вывод
В ходе работы изучены основные команды Git: init, add, commit, push, pull,
branch, checkout, merge, rebase. Получен практический опыт работы с
- PR смержен, ветка patch2 удалена

## Вывод
В ходе работы изучены основные команды Git: init, add, commit, push, pull,
branch, checkout, merge, rebase. Получен практический опыт работы с
ветками и pull-request на GitHub.
