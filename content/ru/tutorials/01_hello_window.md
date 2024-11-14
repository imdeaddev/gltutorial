# Hello window

## OpenGL

Об OpenGL обычно говорят, как о графическом API, но это не совсем так, сама OpenGL - это спецификация API, разработанная [Khronos Group](http://www.khronos.org/), а конкретная реализация предоставляется графическим драйвером.
При этом OpenGL имеет кучу разных версий и расширений, которые могут поддерживаться драйвером устройства/видеокартой как таковой, поэтому все функции OpenGL загружаются динамически ([подробнее](https://en.wikipedia.org/wiki/Dynamic_linker)). Это можно сделать вручную, но для удобствва и чтобы не изобретать велосипед, можно использовать готовую библиотеку-загрузчик. Мы будем использовать [glad](gen.glad.sh), хотя на самом деле это не так уж и важно для нас.
Так же OpenGL тесно связан с оконной системой. Создание контекста OpenGL обычно происходит при создании окна, так что нам нужна библиотека, которая позволила бы создать окно с контекстом OpenGL. Обычно для этих целей используют [SDL2](https://libsdl.org) или [glfw](https://www.glfw.org). Первая очень популярна, имеет огромное количество крутых функций и используется даже крупными игровыми студиями, однако на мой взгляд glfw будет более простым в освоении и прекрасно подходит для наших задач.

## GLFW

GLFW - кросс-платформенная библиотека, которая предназначения для создания оконных приложений. Если быть точнее, то с помощью нее мы можем создать окно и контекст OpenGL, а так же обрабатывать ввод.

## Написание кода

### Инициализация

Перед использованием библиотеку нужно инициализировать, а после очистить все используемые ей ресурсы, для этого существуют функции `glfwInit` и `glfwTerminate`

```cpp
#include <GLFW/glfw3.h> // GLFW

// Настройки окна
constexpr int         g_nWindowWidth  = 640;
constexpr int         g_nWindowHeight = 480;
constexpr const char *g_szWindowTitle = "OpenGL tutorial";

int main( int argc, const char *argv[] )
{
    if ( !glfwInit() ) // инициализируем библиотеку перед использыванием и проверяем успех
    {
        std::cerr << "Failed to init GLFW" << std::endl;
        return -1;
    }
    ... // Создаем окно
    glfwTerminate(); // деинициализируем
    return 0; // выходим
}
```

### Создание окна

Далее нам нужно создать окно, для этого используется функция `glfwCreateWindow`, а в конце удалить его при помощи `glfwDestroyWindow`.

```cpp
    GLFWwindow* pWindow = nullptr;
    pWindow = glfwCreateWindow( g_nWindowWidth, g_nWindowHeight, g_szWindowTitle, nullptr, nullptr ); // передаем ширину, высоту и заголовок окна, два последних параметра - monitor (используется для создания полноэкранного окна) и share ()
    if ( !pWindow ) // Проверяем, что окно было успешно создано, иначе выводим сообщение об ошибку, деинициализируем glfw и закрываем приложение
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    ... // главный цикл будет здесь
    glfwDestroyWindoww(pWindow);
```

### Главный цикл

Теперь главный цикл. Тут все просто - пока окно не должно закрыться (`glfwWindowShouldClose`), обрабатываем события, произошедшие с окном (`glfwPollEvents`), например, ввод с клавиатуры, движение мышью, закрытие окна или изменение его размера.

```cpp
    while ( !glfwWindowShouldClose( pWindow ) ) // Пока pWindow не закрыто
    {
        glfwPollEvents(); // Обрабатываем события (event'ы)
    }
```

## Итоговый код

При запуске данного кода, если Вы все сделали правильно, у Вас должно появится окно 640 на 480 с заголовком OpenGL tutorial.

```cpp
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int         g_nWindowWidth  = 640;
constexpr int         g_nWindowHeight = 480;
constexpr const char *g_szWindowTitle = "OpenGL tutorial";

int main( int argc, const char *argv[] )
{
    GLFWwindow *pWindow = nullptr;
    if ( !glfwInit() )
    {
        std::cerr << "Failed to init GLFW" << std::endl;
        return -1;
    }

    pWindow = glfwCreateWindow( g_nWindowWidth, g_nWindowHeight, g_szWindowTitle, nullptr, nullptr );
    if ( !pWindow )
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    while ( !glfwWindowShouldClose( pWindow ) )
    {
        glfwPollEvents();
    }

    glfwDestroyWindow( pWindow );
    glfwTerminate();
    return 0;
}
```
