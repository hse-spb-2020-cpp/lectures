# Обработка ошибок [00:15]
http://joeduffyblog.com/2016/02/07/the-error-model/

## Два вида ошибок [00:05]
1. Ошибки программирования: любой UB, нарушение инварианта (двоичный поиск, состояние класса),
  нарушения контракта.
  ```
  void foo(const char *s) {
      printf("%s\n", s);  // Некорректный s.
  }
  ```
  * Лучше выявлять на стадии тестирования.
  * Обычно видны не сразу, а через какое-то время.
  * Можно пробовать проверять и детектировать (например, `vector::at` вместо `vector::operator[]`),
    но не задетектирует всё (потому что баги) и неясно, что делать после обнаружения
    (мало в чём можно быть уверенным).
  * Если случилось, то никаких гарантий, all bets are off.
    Баг в программе точно есть, причём неизвестный, могло упасть где угодно.
1. "Ошибки окружения": некорректный ввод пользователя, файл не найден,
   оборвалось сетевое соединение...
  * Могут произойти независимо от программы.
  * Лучше обрабатывать.
  * Например, клиент Telegram должен быстро работать, даже если
    сервер внезапно отвалился.
    Переподключиться? Держать ещё одно соединение в запасе? Надо думать.
  * Не хватило прав доступа — может, наоборот, не сообщать пользователю,
    зато сообщить администратору.

## Надо думать [00:05]
Бывают пограничные ситуации в разных контекстах.

* На хороших контестах гарантируется, что ввод корректен.
* А что если кончился стэк/память/место на диске?
  * Место на диске: можно забить, можно почистить свой собственный кэш.
  * Память: а если при обработке потребуется ещё память?
  * Не удалась запись в файл: могут быть разные требования к чат-клиенту (который
    может всё скачать с сервера) и самому серверу (которому надо как-то
    восстанавливаться и централизованно сообщать "жёсткий диск сломался").
* Нарушен инвариант структуры — проблема.
  А вот если мы её перед этим считывали по сети, то, может, это попытка взлома
  и надо залогировать и пропустить запрос.

Про каждую ошибку в программе надо думать:

1. Что случится, когда произойдёт? (не "если")
1. Можно ли с ней сделать что-то разумное?

## Обработка ошибок [00:05]
Почти всегда можно залогировать ошибку _для разработчика_.

1. Уронить процесс целиком.
   Самое безопасное при ошибках программирования.
   Хотя тоже может нарушить инварианты (например, файл не до конца записали).
   Можно ещё перед этим позвонить домой и отправить багрепорт.
   А потом немедленно упасть, даже если кажется, что всё хорошо.
1. Уронить кусок процесса.
   Только если не ошибка программирования (хотя в Java/Python с изоляцией получше).
   Например, мы сервер и порвалось соединение с клиентом.
1. Как-то обработать: например, попробовать другой адрес для подключения к серверу.
1. Сообщить пользователю и попросить что-нибудь сделать: "файл не найден, выберите другой".
   * Важно понимать, что пользователь далеко не всегда что-то может сделать.
     О каких ошибках и как сообщать пользователю — отдельный вопрос.

Проще и надёжнее всего уронить программу целиком.

Нет серебрянной пули для обработки ошибок: это такая же часть спецификации
программы, над которой надо хорошо думать заранее и отдельно реализовывать.

Например, `On Error Resume Next` писать не надо никогда.
