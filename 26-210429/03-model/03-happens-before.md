#
Мотивация: есть оптимизации компилятора/процесора и кэши.
Есть слабые модели памяти: https://habr.com/ru/company/JetBrains-education/blog/523298/

1. Внутри потока: A; B и ещё некоторые "sequenced-before": https://en.cppreference.com/w/cpp/language/eval_order
2. Между потоками: отпустили мьютекс; взяли мьютекс
3. У atomic'ов: технически есть разница между acquire/release: 

#
```c++
// Thread 1
started = true;
m.lock();
finished = true;
m.unlock();

// Thread 2
m.lock();
if (finished) {
    assert(started);    // Верно
}
m.unlock();
```

#
```c++
// Thread 1
started = true;
m.lock(); data++; m.unlock();
finished1 = true;
finished2 = true;

// Thread 2
m.lock(); m.unlock();
if (finished2) { // UB
    assert(finished1);  // Непонятно, UB/reordering
    assert(data > 0);   // Непонятно, UB
    assert(started);    // Непонятно, UB
}
```

#
Не помогает даже sleep!

Бывает много читателей, но не больше одного писателя. Как в Rust.
`shared_mutex`, будет в бонусе.

Рекомендация: поменьше общих ресурсов.

Пройтись по предыдущей лекции и найти race condition.
