Можно ли "перемешать" инициализацию между разными TU?
Ответ: да, потому что вообще бывает deferred dynamic initialization.

А ещё бывает, что не вызываются конструкторы из неиспользуемой статической библиотеки: https://stackoverflow.com/questions/1300778/how-to-prevent-the-linker-from-optimizing-away-startup-code?noredirect=1&lq=1
