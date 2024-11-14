# Hello OpenGL

- [Hello OpenGL](#hello-opengl)
  - [Цель урока](#цель-урока)
  - [Параметры создания окна](#параметры-создания-окна)
  - [Используя созданный контекст, загружаем функции OpenGL](#используя-созданный-контекст-загружаем-функции-opengl)
  - [Render loop](#render-loop)
  - [Итог](#итог)

## Цель урока

В этом уроке мы с помощью GLFW создадим современный контекст OpenGL и загрузим OpenGL с помощью glad, а так же закрасим окно цветом.

## Параметры создания окна

В GLFW можно задать параметры для создания окна, например, сделать его фиксированного размера или убрать рамку, для этого используется функция `glfwWindoHint`.
В нашем случае, мы должны запросить создания контекста OpenGL, задав параметры `GLFW_CLIENT_API` (`GLFW_OPENGL_API` - используем OpenGL), `GLFW_OPENGL_PROFILE` (`GLFW_OPENGL_CORE_PROFILE` - используем основной профиль API, без обратной совместимости), `GLFW_CONTEXT_VERSION_MAJOR` и `GLFW_CONTEXT_VERSION_MINOR` - указываем версию OpenGL (4 и 5 соответственно).

```cpp
    ...
    glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_API );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 5 );
    pWindow = glfwCreateWindow(...);
    ...
```

## Используя созданный контекст, загружаем функции OpenGL

Созданный контекст нужно сделать текущим используя функцию `glfwMakeContextCurrent`, иначе мы не сможем загрузить OpenGL с помощью `glfwGetProcAddress`, а значит и с помощью glad, который является оберткой над предоставленной пользователем функции для получения адреса функции. Код ниже нужен для того, чтобы мы могли использовать функции OpenGL.

```cpp
    ...
    glfwMakeContextCurrent( pWindow ); // Делаем контекст текущим
    // Передаем в glad функцию-загрузчик glfwGetProcAddress. 
    // glfwGetProcAddress используется для получения указателя на функцию по ее имени в виде передаваемой строки
    // glad сразу загружает все нужные функции
    int nLoadedOpenGLVersion = gladLoadGL( glfwGetProcAddress );
    if ( ( GLAD_VERSION_MAJOR( nLoadedOpenGLVersion ) < 4 ) || GLAD_VERSION_MINOR( nLoadedOpenGLVersion ) < 5 )
    { // Проверяем, что загруженный API OpenGL имеет версию не ниже 4.5
        std::cerr << "Failed to load OpenGL 4.5 functions" << std::endl;
        glfwDestroyWindow( pWindow );
        glfwTerminate();
        return -1;
    }
    ...
```

## Render loop

Современный OpenGL использует двойной буфер по умолчанию. Это значит что для отрисовки используется два изображения-буфера - пока в один ведется запись, изображение со второго отображается на экране. После окончания отрисовки можно поменять буферы местами используя `glfwSwapBuffer`.
Код, непосредственно относящийся к OpenGL здесь всего в двух строчках, но они довольно важны - `glClearColor` задает цвет для очистки экрана, а `glClear` очищает указанные буферы, в данном случае мы очищаем только буфер цвета `GL_COLOR_BUFFER_BIT`, тем самым заливая экран цветом, указанным при помощи `glClearColor`

```cpp
    ...
    glClearColor( 0.1, 0.2, 0.7, 1.0 ); // Задаем цвет, которым будем заливать в формате r, g, b, a

    while ( !glfwWindowShouldClose( pWindow ) )
    {
        glfwPollEvents();
        glClear( GL_COLOR_BUFFER_BIT );
        glfwSwapBuffers( pWindow );
    }
    ...
```

## Итог

В результате Вы должны увидеть окно, которое окрашено в указанный цвет (в моем случае, синий #1a33b3ff)

Исходный код - [02_hello_opengl](../../../source/02_hello_opengl/)

Далее - to be continued
