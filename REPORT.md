# Отчёт по лабораторной работе №2

## Тема
Изучение систем контроля версий на примере Git.

## Предварительная подготовка

```bash
$ sudo apt update && sudo apt install git -y
```

```
Чтение списков пакетов…
...
git уже установлен (1:2.43.0-1ubuntu7.3).
```

```bash
$ git config --global user.name "dast548"
$ git config --global user.email "orlovsasha2007@gmail.com"
$ git config -e --global
```

```
[user]
    name = dast548
    email = orlovsasha2007@gmail.com
[hub]
    protocol = https
```

## Ход работы

### Part I

#### 1. Создан публичный репозиторий Home2 с лицензией MIT на сервисе github.com

Репозиторий создан по адресу: https://github.com/dast548/Home2

#### 2. Клонирование репозитория

```bash
$ git clone https://github.com/dast548/Home2.git
$ cd Home2
```

```
Cloning into 'Home2'...
warning: You appear to have cloned an empty repository.
```

#### 3. Создание файла hello_world.cpp с плохим стилем кода

```bash
$ cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  cout << "Hello world" << endl;
  return 0;
}
EOF
```

#### 4. Создание структуры папок и файлов

```bash
$ mkdir sources include examples
```

```bash
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```

```bash
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```

```bash
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF
```

```bash
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>
#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```

#### 5. Добавление файлов и первый коммит

```bash
$ git add .
$ git status
```

```
On branch main
No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   examples/example1.cpp
        new file:   examples/example2.cpp
        new file:   hello_world.cpp
        new file:   include/print.hpp
        new file:   sources/print.cpp
```

```bash
$ git commit -m "added sources"
```

```
[main (root-commit) 7f76b4c] added sources
 5 files changed, 39 insertions(+)
 create mode 100644 examples/example1.cpp
 create mode 100644 examples/example2.cpp
 create mode 100644 hello_world.cpp
 create mode 100644 include/print.hpp
 create mode 100644 sources/print.cpp
```

#### 6. Изменение hello_world.cpp — добавлен ввод имени пользователя

```bash
$ cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  string name;
  cout << "Enter your name: ";
  cin >> name;
  cout << "Hello world from @" << name << endl;
  return 0;
}
EOF
```

#### 7. Коммит новой версии

```bash
$ git commit -am "updated hello_world.cpp: added user input"
```

```
[main 9621555] updated hello_world.cpp: added user input
 1 file changed, 4 insertions(+), 1 deletion(-)
```

> Файл не нужно добавлять повторно через `git add`, потому что он уже отслеживается Git после первого `git add`. Флаг `-a` в команде `git commit -am` автоматически добавляет все изменённые отслеживаемые файлы.

#### 8. Пуш изменений в удалённый репозиторий

```bash
$ git push origin main
```

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 415 bytes | 415.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
To https://github.com/dast548/Home2.git
   7f76b4c..9621555  main -> main
```

#### 9. История коммитов доступна в удалённом репозитории

Проверено на странице https://github.com/dast548/Home2/commits/main

---

### Part II

#### 1. Создание локальной ветки patch1

```bash
$ git checkout -b patch1
```

```
Switched to a new branch 'patch1'
```

#### 2. Исправление кода — удалён using namespace std

```bash
$ cat > hello_world.cpp <<EOF
#include <iostream>

int main(int argc, char** argv)
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
EOF
```

#### 3. Коммит и пуш ветки patch1

```bash
$ git commit -am "fixed code style: removed using namespace std"
$ git push origin patch1
```

```
[patch1 e00e164] fixed code style: removed using namespace std
 1 file changed, 4 insertions(+), 5 deletions(-)
Enumerating objects: 5, done.
...
To https://github.com/dast548/Home2.git
 * [new branch]      patch1 -> patch1
```

#### 4. Ветка patch1 доступна в удалённом репозитории

Проверено на странице https://github.com/dast548/Home2/tree/patch1

#### 5. Создан pull-request patch1 -> main

Pull-request создан на странице https://github.com/dast548/Home2/pull/1

#### 6. Добавление комментариев в ветке patch1

```bash
$ cat > hello_world.cpp <<EOF
#include <iostream>

int main(int argc, char** argv)
{
  std::string name;
  // запрашиваем имя пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;
  // выводим приветствие
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
EOF
```

#### 7. Коммит и пуш

```bash
$ git commit -am "added comments to hello_world.cpp"
$ git push origin patch1
```

```
[patch1 c330052] added comments to hello_world.cpp
 1 file changed, 2 insertions(+)
...
To https://github.com/dast548/Home2.git
   e00e164..c330052  patch1 -> patch1
```

#### 8. Новые изменения появились в pull-request

Проверено — в PR #1 видны оба коммита: "fixed code style" и "added comments".

#### 9. Слияние PR patch1 -> main и удаление ветки

Выполнено через интерфейс GitHub: Merge pull request -> Confirm merge -> Delete branch.

```
Pull request successfully merged and closed.
```

#### 10. Локальный pull

```bash
$ git checkout main
$ git pull origin main
```

```
remote: Enumerating objects: 4, done.
...
Updating 9621555..368cd7d
Fast-forward
 hello_world.cpp | 7 ++++---
```

#### 11. Просмотр истории коммитов

```bash
$ git log
```

```
commit 368cd7d9f70631f72c547ba2e84d68a8ca7607ef (HEAD -> main, origin/main)
Merge: 9621555 c330052
Author: dast548 <orlovsasha2007@gmail.com>
Date:   Fri Jun 5 22:45:53 2026 +0300

    Merge pull request #1 from dast548/patch1

commit c330052b657ff01d7d5c1c9625120c1e50c204e7
Author: dast548 <orlovsasha2007@gmail.com>
    added comments to hello_world.cpp

commit e00e164d0c3f48dc2f3a554d1ef37dea45e62107
Author: dast548 <orlovsasha2007@gmail.com>
    fixed code style: removed using namespace std

commit 9621555...
    updated hello_world.cpp: added user input

commit 7f76b4c...
    added sources
```

#### 12. Удаление локальной ветки patch1

```bash
$ git branch -d patch1
```

```
Deleted branch patch1 (was c330052).
```

---

### Part III

#### 1. Создание ветки patch2

```bash
$ git checkout -b patch2
```

```
Switched to a new branch 'patch2'
```

#### 2. Применение clang-format со стилем Mozilla

```bash
$ sudo apt install clang-format -y
$ clang-format -style=Mozilla -i hello_world.cpp
$ git diff hello_world.cpp
```

```
diff --git a/hello_world.cpp b/hello_world.cpp
index c9894eb..e701a44 100644
--- a/hello_world.cpp
+++ b/hello_world.cpp
@@ -1,6 +1,7 @@
 #include <iostream>
-int main(int argc, char** argv)
+int
+main(int argc, char** argv)
 {
```

#### 3. Коммит, пуш, создание pull-request patch2 -> main

```bash
$ git commit -am "applied clang-format Mozilla style"
$ git push origin patch2
```

```
[patch2 93decad] applied clang-format Mozilla style
 1 file changed, 2 insertions(+), 1 deletion(-)
...
To https://github.com/dast548/Home2.git
 * [new branch]      patch2 -> patch2
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:   https://github.com/dast548/Home2/pull/new/patch2
```

Pull-request создан на странице https://github.com/dast548/Home2/pull/2

#### 4. Изменение комментария в ветке main на GitHub

Через интерфейс GitHub отредактирован файл hello_world.cpp в ветке main:
комментарий `// запрашиваем имя пользователя` изменён на `// ask for user name.`

#### 5. В pull-request появился конфликт

Проверено — GitHub показывал "Can't automatically merge" после изменения в main.

#### 6. Локальный pull + rebase

```bash
$ git checkout patch2
$ git pull origin main --rebase
```

```
remote: Enumerating objects: 5, done.
...
Successfully rebased and updated refs/heads/patch2.
```

#### 7. Force push в ветку patch2

```bash
$ git push --force origin patch2
```

```
Enumerating objects: 5, done.
...
To https://github.com/dast548/Home2.git
 + 93decad...08dceb4 patch2 -> patch2 (forced update)
```

#### 8. Конфликты в pull-request исчезли

Проверено — GitHub показал "No conflicts with base branch".

#### 9. Слияние pull-request patch2 -> main

Выполнено через интерфейс GitHub: Merge pull request -> Confirm merge -> Delete branch.

```
Pull request successfully merged and closed.
```

## Вывод

В ходе лабораторной работы были изучены основные команды Git:
`init`, `add`, `commit`, `push`, `pull`, `branch`, `checkout`, `merge`, `rebase`.
Получен практический опыт работы с ветками и pull-request на GitHub.
Изучена работа с конфликтами и их разрешение через rebase.
