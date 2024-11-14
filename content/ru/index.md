# Уроки OpenGL

- [Уроки OpenGL](#уроки-opengl)
  - [Для чего они созданы?](#для-чего-они-созданы)
  - [Что нужно для того, чтобы начать изучать OpenGL по этим урокам?](#что-нужно-для-того-чтобы-начать-изучать-opengl-по-этим-урокам)
    - [Для Windows](#для-windows)
    - [Для Linux](#для-linux)
    - [Для Mac OS](#для-mac-os)
  - [Visual Studio Code](#visual-studio-code)
  - [Сборка](#сборка)

## Для чего они созданы?

Не смотря на то, что в интернете уже есть куча ресурсов по OpenGL и графике в целом, ресурсов на русском языке не так уж и много... Да ладно, мне просто интересно, почему бы и нет :) Пусть это будет Yet another OpenGL tutorial
Да и мне самому будет полезно написать такое, чтобы повторить и лучше изучить данный материал.

## Что нужно для того, чтобы начать изучать OpenGL по этим урокам?

### Для Windows

- [git](https://git-scm.com/downloads/win) (или `winget install Git.Git`)
- Компилятор
- - [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) (рекомендовано)
- - или используйте [MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
- - так же можно использовать clang, легче всего это сделать с Visual Studio - в установщике ищите "LVVM toolchain" и ставьте галочку
- [CMake](https://cmake.org/download/) (или `winget install Kitware.CMake`)
- (опционально) [Visual Studio Code](https://code.visualstudio.com/download) (или `winget install Microsoft.VisualStudioCode`)
- OpenGL 4.5-совместимая видеокарта (большинство современных видеокарт поддерживают OpenGL 4.5)

### Для Linux

Скорее всего, у Вас уже есть все нужное, но на всякий случай

- [git](https://git-scm.com/downloads/linux)
- - Debian/Ubuntu (apt) `apt-get install git`
- - Arch Linux (pacman) `pacman -S git`
- - Fedora 22+ (dnf) `dnf install git`
- - Fedora (yum) `yum install git`
- - и т.д.
- [CMake](https://cmake.org/download/)
- [gcc](https://gcc.gnu.org/install/)

### Для Mac OS

К сожалению, OpenGL 4.5 не поддерживается системами Apple, ищите уроки по OpenGL ES/Metal/Vulkan

## Visual Studio Code

Для Visual Studio Code Вам понадобятся некоторые расширения, их я указал в `.vscode/extensions.json`, так что редактор сам предложит их установить.

Для запуска понадобится `launch.json`, где в качестве программы для запуска прописываем `${command:cmake.launchTargetPath}`, пример для Windows (Visual Studio debugger):

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(Windows) Launch",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${command:cmake.launchTargetPath}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "console": "integratedTerminal"
        }
    ]
}
```

## Сборка

Попробуйте собрать исходный код уроков или переходите сразу к созданию собственного проекта.
Это можно сделать разными способами, например, создать проект в Visual Studio, но для простоты рекомендую скопировать папку `deps`  в папку своего проекта и добавить файлы `main.cpp` и `CMakeLists.txt` с следующим содержимым:

```cmake
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project("My OpenGL project")

add_subdirectory(deps)
add_subdirectory(source)

# add_executable(ИМЯ_ИСПОЛНЯЕМОГО_ФАЙЛА ВАШИ_ИСХОДНЫЕ_ФАЙЛЫ), например:
add_executable(game main.cpp)
target_link_libraries(game PRIVATE glad glfw glm::glm-header-only) # подключаем библиотеки
```

После можете приступить к [уроку 1](tutorials/01_hello_window.md)
