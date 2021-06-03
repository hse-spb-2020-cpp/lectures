# Статическая инициализация
12-201208/04-global-vars-init/TODO.md

# Почему бывает чтение невыровренной памяти?
21-210316/00-questions/01.cpp

# Self-move
```
vector operator=(vector &&other) {
}

v = std::move(v);  // self-move.
```

Self-move на самом деле допускается (как минимум с C++23): оставляет объект в valid, but unspecified state: https://stackoverflow.com/a/66952566/767632

У меня требования чуть строже, но на самом деле это необязательно: для swap хватает unspecified state.

# `23-*`
23-210408\01-language\TODO.md
