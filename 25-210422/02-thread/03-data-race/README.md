Не пытаться использовать atomic, там жесть как только больше одной переменной (то есть почти всегда).

std::cout потокобезопасен (посимвольно): https://eel.is/c++draft/input.output#iostream.objects.overview-7
