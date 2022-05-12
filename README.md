Как запустить проект:

Предварительно надо установить SFML через sudo apt-get install libsfml-dev.

В папке с CMakeLists.txt создается папка build.

В ней делаются команды:

	1) cmake ..
	2) make
	3) cmake install ..

Затем исполняется файл MainBuild в папке build путем ./MainBuild.
